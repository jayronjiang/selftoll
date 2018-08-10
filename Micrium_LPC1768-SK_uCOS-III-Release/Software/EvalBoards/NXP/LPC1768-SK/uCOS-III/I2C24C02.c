/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: I2c24C02.C
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

#define  I2C24C02_GLOBALS
#include "includes.h"

#define EEPROM_BACKUP_ADDR 				0x80

#define ADDR_24C02 								0xA0

/*******************************************************************************************************
** 函数名称: EepromWriteBytes
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
uint8_t EepromWriteBytes(uint8_t romAddr, uint8_t *info, uint8_t infolen )
{
  uint8_t i = 0; 
          
  uint8_t ucTx[16];
  
  if( romAddr+infolen > 256){
    return FALSE;
  }
  if(infolen>8){
    return FALSE;
  }
  
  ucTx[0]=romAddr;
  for(i=0;i<infolen;i++){
    ucTx[1+i]=*info;
    info++;
  }
  
  if(!I2cSend(ADDR_24C02,ucTx,1+infolen,NULL,0)){
    return FALSE;
  }
  BSP_OS_TimeDlyMs(20);    
  return TRUE;
}

/*******************************************************************************************************
** 函数名称: EepromReadBytes
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
uint8_t EepromReadBytes( uint8_t romAddr, uint8_t *info, uint8_t infolen )
{
  uint8_t ucTx[16];
	
	// Write SLA(W), address, SLA(R), and read one byte back. 
  if( romAddr+infolen >256 ){
    return FALSE;
  }

  if(infolen>8){
    return FALSE;
  }

  ucTx[0]=romAddr;
  if(!I2cSend(ADDR_24C02,ucTx,1,info,infolen)){
    return FALSE;
  }
  return TRUE;
}

/*******************************************************************************************************
** 函数名称: EepromWriteVerifyBytes
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
uint8_t EepromWriteVerifyBytes( uint8_t romAddr, uint8_t *info, uint8_t infolen )
{
  uint8_t i;
  uint8_t ucBuf[8];
  uint8_t ucBuf1[8];
  uint8_t ucBufA[8];
  uint8_t ucBufB[8];
  uint16_t uiCrc16;
  uint8_t ucRet;
  uint8_t ucRet1;
  uint8_t ucRead;
  uint8_t ucRead1;

  if(infolen>6){
    return FALSE;
  }

  Mem_Copy(ucBuf,info,infolen);
  uiCrc16=RevCrc16Bytes(ucBuf,infolen,0xA001);
  ucBuf[infolen]=uiCrc16;
  ucBuf[infolen+1]=uiCrc16>>8;

  for(i=0;i<3;i++){
    ucRead=0;
    if(EepromReadBytes(romAddr,ucBufA,infolen+2)){
      ucRead=1;
    }
    ucRead1=0;
    if(EepromReadBytes(romAddr+EEPROM_BACKUP_ADDR,ucBufB,infolen+2)){
      ucRead1=1;
    }
    if(ucRead && ucRead1){
      break;
    }
  }


  for(i=0;i<3;i++){
    ucRet=1;
    if(!ucRead || !Mem_Cmp(ucBuf,ucBufA,infolen+2)){
      ucRet=0;
      if(EepromWriteBytes(romAddr,ucBuf,infolen+2)){
        if(EepromReadBytes(romAddr,ucBuf1,infolen+2)){
          if(Mem_Cmp(ucBuf,ucBuf1,infolen+2)){
            ucRet=1;
          }
        }
      }
    }
    
    ucRet1=1;
    if(!ucRead1 || !Mem_Cmp(ucBuf,ucBufB,infolen+2)){
      ucRet1=0;
      if(EepromWriteBytes(romAddr+EEPROM_BACKUP_ADDR,ucBuf,infolen+2)){
        if(EepromReadBytes(romAddr+EEPROM_BACKUP_ADDR,ucBuf1,infolen+2)){
          if(Mem_Cmp(ucBuf,ucBuf1,infolen+2)){
            ucRet1=1;
          }
        }
      }
    }
    if(ucRet || ucRet1){
      return TRUE;
    }
  }
  return FALSE;
}

/*******************************************************************************************************
** 函数名称: EepromReadVerifyBytes
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
uint8_t EepromReadVerifyBytes( uint8_t romAddr, uint8_t *info, uint8_t infolen )
{
  uint8_t i;
  uint8_t ucBuf[8];

  if(infolen>6){
    return FALSE;
  }

  for(i=0;i<3;i++){
    if(EepromReadBytes(romAddr,ucBuf,infolen+2)){
      if(!RevCrc16Bytes(ucBuf,infolen+2,0xA001)){
        Mem_Copy(info,ucBuf,infolen);
        EepromWriteVerifyBytes(romAddr,ucBuf,infolen);
        return TRUE;
      }
    }

    if(EepromReadBytes(romAddr+EEPROM_BACKUP_ADDR,ucBuf,infolen+2)){
      if(!RevCrc16Bytes(ucBuf,infolen+2,0xA001)){
        Mem_Copy(info,ucBuf,infolen);
        EepromWriteVerifyBytes(romAddr,ucBuf,infolen);
        return TRUE;
      }
    }
  }
  return FALSE;
}


/******************************************************************************
**                            End Of File
******************************************************************************/

