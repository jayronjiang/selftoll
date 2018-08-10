/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: I2c.C
*创   建   人: John Tonny
*最后修改日期: 2005年05月01日
*描        述:
*
*--------------历史版本信息-----------------------------------------------------------------------------
* 创建人: John Tonny
* 版  本: V1.0
* 日　期: 2005年05月01日
* 描　述: 原始版本
*
*-------------------------------------------------------------------------------------------------------
* 修改人:
* 版  本:
* 日　期:
* 描　述:
*
*--------------当前版本修订-----------------------------------------------------------------------------
* 修改人:
* 日　期:
* 描　述:
*
*-------------------------------------------------------------------------------------------------------
*******************************************************************************************************/

#define  I2C_GLOBALS
#include "includes.h"
  

#define I2C_CON_FLAGS (I2CONSET_AA | I2CONSET_SI | I2CONSET_STO | I2CONSET_STA)

static I2C_XFER_T g_usrI2c;
static BSP_OS_SEM *g_pI2cSem;

/*******************************************************************************************************
** 函数名称: LPC17xx_I2C0_IntHandler
** 功能描述:
** 输 　 入:
**
** 输　  出:
**
** 全局变量:
** 调用模块:
**
** 作　  者: John Tonny
** 日　  期: 2005年05月01日
**------------------------------------------------------------------------------------------------------
** 修 改 人:
** 日　  期:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
static void LPC17xx_I2C0_IntHandler(void  *p_arg) 
{
  // this handler deals with master read and master write only 
  uint8_t StatValue;
  uint32_t cclr = I2C_CON_FLAGS;

  g_usrI2c.timeOut=0;
	
  StatValue = I2C0STAT;
  switch ( StatValue ){
    case 0x08:		// Start condition on bus 
    case 0x10:		// Repeated start condition 
      I2C0DAT= (g_usrI2c.slaveAddr) | (g_usrI2c.txSz == 0);
      break;

    // Tx handling 
    case 0x18:		// SLA+W sent and ACK received 
    case 0x28:		// DATA sent and ACK received 
      if (!g_usrI2c.txSz) {
        cclr &= ~(g_usrI2c.rxSz ? I2CONSET_STA : I2CONSET_STO);
        if(!g_usrI2c.rxSz){
          BSP_OS_SemPost(g_pI2cSem);
        }
      } else {
        I2C0DAT= *g_usrI2c.txBuff++;
        g_usrI2c.txSz--;
      }
      break;

    // Rx handling 
    case 0x58:		// Data Received and NACK sent 
      cclr &= ~I2CONSET_STO;

    case 0x50:		// Data Received and ACK sent 
      *g_usrI2c.rxBuff++ = I2C0DAT;
      g_usrI2c.rxSz--;

    case 0x40:		// SLA+R sent and ACK received 
      if (g_usrI2c.rxSz > 1) {
        cclr &= ~I2CONSET_AA;
      }else if(!g_usrI2c.rxSz){
        BSP_OS_SemPost(g_pI2cSem);
      }
      break;

    // NAK Handling 
    case 0x20:		// SLA+W sent NAK received 
    case 0x30:		// DATA sent NAK received 
    case 0x48:		// SLA+R sent NAK received 
      g_usrI2c.status = I2C_STATUS_NAK;
      cclr &= ~I2CONSET_STO;
      BSP_OS_SemPost(g_pI2cSem);
      break;

    case 0x38:		// Arbitration lost 
      g_usrI2c.status = I2C_STATUS_ARBLOST;
      break;

    // Bus Error 
    case 0x00:
      g_usrI2c.status = I2C_STATUS_BUSERR;
      cclr &= ~I2CONSET_STO;
      break;  
    }

  // Set clear control flags 
  I2C0CONSET = cclr ^ I2C_CON_FLAGS;
  I2C0CONCLR = cclr;
}

/*******************************************************************************************************
** 函数名称: I2cStart
** 功能描述:
** 输 　 入:
**
** 输　  出:
**
** 全局变量:
** 调用模块:
**
** 作　  者: John Tonny
** 日　  期: 2005年05月01日
**------------------------------------------------------------------------------------------------------
** 修 改 人:
** 日　  期:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
uint32_t I2c0Start(void)
{
  uint32_t retVal = FALSE;
 
  /*I2CTimeout = 0;
  //--- Issue a start condition ---
  I2C0CONSET = I2CONSET_STA;	// Set Start flag 
    
  //--- Wait until START transmitted ---
  while( 1 ){
    if ( I2CMasterState == I2C_STARTED ){
      retVal = TRUE;
      break;	
    }
    if ( I2CTimeout >= MAX_TIMEOUT ){
      retVal = FALSE;
      break;
    }
    I2CTimeout++;
  }*/
  return( retVal );
}

/*******************************************************************************************************
** 函数名称: I2cStop
** 功能描述:
** 输 　 入:
**
** 输　  出:
**
** 全局变量:
** 调用模块:
**
** 作　  者: John Tonny
** 日　  期: 2005年05月01日
**------------------------------------------------------------------------------------------------------
** 修 改 人:
** 日　  期:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
uint32_t I2c0Stop(void)
{
  I2C0CONSET = I2CONSET_STO;            // Set Stop flag 
  I2C0CONCLR = I2CONCLR_SIC;  		// Clear SI flag  
            
  //--- Wait for STOP detected ---
  while( I2C0CONSET & I2CONSET_STO );
  return TRUE;
}

/*******************************************************************************************************
** 函数名称: I2c0Init
** 功能描述:
** 输 　 入:
**
** 输　  出:
**
** 全局变量:
** 调用模块:
**
** 作　  者: John Tonny
** 日　  期: 2005年05月01日
**------------------------------------------------------------------------------------------------------
** 修 改 人:
** 日　  期:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void I2c0Init( void ) 
{
  LIB_ERR lib_err;
  
  PCONP |= (1 << 7);

  // set PIO0.27 and PIO0.28 to I2C0 SDA and SCL 
  // function to 01 on both SDA and SCL. 
  PINSEL1 &= ~((0x03<<22)|(0x03<<24));
  PINSEL1 |= ((0x01<<22)|(0x01<<24));	
 
  //--- Clear flags ---
  I2C0CONCLR = I2CONCLR_AAC | I2CONCLR_SIC | I2CONCLR_STAC | I2CONCLR_I2ENC;    

  //--- Reset registers ---
#if FAST_MODE_PLUS
  I2CPADCFG |= ((0x1<<0)|(0x1<<2));
  I2C0SCLL   = I2SCLL_HS_SCLL;
  I2C0SCLH   = I2SCLH_HS_SCLH;
#else
  I2CPADCFG &= ~((0x1<<0)|(0x1<<2));
  I2C0SCLL   = I2SCLL_SCLL;
  I2C0SCLH   = I2SCLH_SCLH;
#endif

  // Install interrupt handler 
  CSP_IntVectReg(CSP_INT_CTRL_NBR_MAIN,CSP_INT_SRC_NBR_I2C_00,LPC17xx_I2C0_IntHandler,0);
  CSP_IntEn(CSP_INT_CTRL_NBR_MAIN, CSP_INT_SRC_NBR_I2C_00);  

  I2C0CONSET = I2CONSET_I2EN;
  
  g_pI2cSem = (OS_SEM *)Mem_PoolBlkGet((MEM_POOL    *)&m_BoxPool,
                                  (CPU_SIZE_T   ) sizeof(OS_SEM),
                                  (LIB_ERR     *)&lib_err);
  if(!g_pI2cSem){
    return;
  }
  
  if(BSP_OS_SemCreate((BSP_OS_SEM *)g_pI2cSem,
                            (BSP_OS_SEM_VAL)1,
                            (CPU_CHAR *)0)==DEF_FAIL){  
  }
  return;
}

/*******************************************************************************************************
** 函数名称: I2cSend
** 功能描述:
** 输 　 入:
**
** 输　  出:
**
** 全局变量:
** 调用模块:
**
** 作　  者: John Tonny
** 日　  期: 2005年05月01日
**------------------------------------------------------------------------------------------------------
** 修 改 人:
** 日　  期:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
uint8_t I2cSend(uint8_t slaveAddr, uint8_t *txBuf,uint8_t txLen,uint8_t *rxBuf, uint8_t rxLen)
{
  CPU_BOOLEAN ucRet;
  
  CPU_SR_ALLOC();
  
  if(!g_pI2cSem){
    return FALSE;
  }
  
  if(BSP_OS_SemWait(g_pI2cSem,25)==DEF_FAIL){
    return FALSE;
  }
  
  OS_ENTER_CRITICAL();
  g_usrI2c.slaveAddr=slaveAddr;
  g_usrI2c.txBuff=txBuf;
  g_usrI2c.txSz=txLen;
  g_usrI2c.rxBuff=rxBuf;
  g_usrI2c.rxSz=rxLen;
  g_usrI2c.status=I2C_STATUS_BUSY;
  OS_EXIT_CRITICAL();
	
  I2C0CONSET = I2CONSET_STA;														 
  ucRet=BSP_OS_SemWait(g_pI2cSem,25);
  I2C0CONCLR = I2CONCLR_STAC;
  BSP_OS_SemPost(g_pI2cSem);
  if(ucRet==DEF_FAIL){
    return FALSE;
  }
  if(g_usrI2c.txSz || g_usrI2c.rxSz){
    return FALSE;
  }
  return TRUE;
}


/******************************************************************************
**                            End Of File
******************************************************************************/

