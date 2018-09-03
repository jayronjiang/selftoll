/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: Global.C
*创   建   人: John Tonny
*最后修改日期: 2009年11月01日
*描        述:
*
*--------------历史版本信息-----------------------------------------------------------------------------
* 创建人: John Tonny
* 版  本: V1.0
* 日　期: 2009年11月01日
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

#define GLOBAL_GLOBALS
#include "includes.h"


INT8U  m_ucKey_GROUP_SMALL_ZIN_TYPE[]={ 4, 5,26, 3,24,25, 8, 7, 6, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,23, 0, 1, 2,27,28,29,30,31,
                                       
                                       12,13, 2,11, 4, 5,26, 7,14,24,25, 3, 0, 1, 8,15,16,17,18,19,20,21,22,23, 8, 9,10,27,28,29,30,31,
                                       
                                       20,21, 2,19, 4, 5, 6, 7,22, 9,10,11,12,13,14,15,24,25,26, 3, 0, 1, 8,23,16,17,18,27,28,29,30,31};


/********************************************************************************************************
** 函数名称: LPC17xx_TIMER0_IntHandler
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
static  void  LPC17xx_TIMER0_IntHandler (void  *p_arg)
{
  T0IR = T0IR | 0x01;					                                    // ??3y?D??±ê??	                	 

  DMotoSwitchStop();

}

/********************************************************************************************************
** 函数名称: LPC17xx_TIMER0_IntHandler
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
static  void  LPC17xx_TIMER1_IntHandler (void  *p_arg)
{
  T1IR = T1IR | 0x01;					                                    // ??3y?D??±ê??	                	 
  
  SMotoHook();    
}

/********************************************************************************************************
** 函数名称: LPC17xx_TIMER2_IntHandler
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
static  void  LPC17xx_TIMER2_IntHandler (void  *p_arg)
{
  /*if(T2IR & 0x01){
    T2IR = T2IR | 0x01;					                                    // MR0中断	                	 
    BSP_LED_On(4);
  }else if( T2IR & 0x02){
    T2IR = T2IR | 0x01;					                                    // MR1中断
    BSP_LED_Off(4);
  }else{
    T2IR = T2IR | 0x0FF;					                            //	                	 
    //BSP_LED_Off(4);
  }
  T2IR = T2IR | 0x0FF;					                            //	                	 
  */
  
  T2IR = T2IR | 0x01;					                                    // ??3y?D??±ê??	                	 
  BSP_LED_Toggle(4);  
}

/********************************************************************************************************
** 函数名称: LPC17xx_TIMER3_IntHandler
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
static  void  LPC17xx_TIMER3_IntHandler (void  *p_arg)
{
  T3IR = T3IR | 0x01;					                                    // ??3y?D??±ê??	                	 
  MotoTime();  
}

/********************************************************************************************************
** 函数名称: LPC17xx_PWM1_IntHandler
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
static  void  LPC17xx_PWM1_IntHandler (void  *p_arg)
{
  if(PWM1IR & (0x1<<0)){	//for step moto clk and timeout test
    PWM1IR  = PWM1IR | (0x1<<0);		/* clear interrupt flag */
    DMotoHook();
  }else if(PWM1IR & (0x1<<1)){	//for step moto clk and timeout test
    PWM1IR  = PWM1IR | (0x1<<1);		/* clear interrupt flag */
    DMotoHook();
  }		  
}

/********************************************************************************************************
** 函数名称: GlobalInit
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
void GlobalInit(void)
{
    
  BuzzInit();
    
  MotoInit();
    
}

/********************************************************************************************************
** 函数名称: Timer0Init
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
void Timer0Init (void)
{
  CPU_INT32U clk_freq = CSP_PM_PerClkFreqGet(CSP_PM_PER_CLK_NBR_TMR_00);

  PCONP |= (0x1<<1);
  T0TCR  = 0x02;
  T0IR   = 0xFF;
  T0CTCR = 0;
  T0TC   = 0;
  T0PR   = clk_freq/100000-1;								// 10us
  T0MR0  = 25-1;                                                 			// 25*10us            
  T0MCR  = 0x03;                                                                        // ?￥??oó2úéú?D???￠?′??             
  T0TCR  = 0x01;
  
  CSP_IntVectReg(CSP_INT_CTRL_NBR_MAIN,CSP_INT_SRC_NBR_TMR_00,LPC17xx_TIMER0_IntHandler,0);
  CSP_IntEn(CSP_INT_CTRL_NBR_MAIN, CSP_INT_SRC_NBR_TMR_00);
  
} 

/********************************************************************************************************
** 函数名称: Timer1Init
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
void Timer1Init (void)
{
    CPU_INT32U clk_freq = CSP_PM_PerClkFreqGet(CSP_PM_PER_CLK_NBR_TMR_00);
  
    PCONP |= (0x1<<2);
    T1TCR  = 0x02;
    T1IR   = 0xFF;
    T1CTCR = 0;
    T1TC   = 0;
    T1PR   = clk_freq/100000-1;                                         //10us		
    T1MR0  = SMOTO_FREQ_700US-1;                                        // 70*10us            
    T1MCR  = 0x03;                                                      // ?￥??oó2úéú?D???￠?′??              
    
    CSP_IntVectReg(CSP_INT_CTRL_NBR_MAIN,CSP_INT_SRC_NBR_TMR_01,LPC17xx_TIMER1_IntHandler,0);
    CSP_IntEn(CSP_INT_CTRL_NBR_MAIN, CSP_INT_SRC_NBR_TMR_01);
} 

/********************************************************************************************************
** 函数名称: Timer2Init
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
void Timer2Init (void)
{
  CPU_INT32U clk_freq = CSP_PM_PerClkFreqGet(CSP_PM_PER_CLK_NBR_TMR_00);

  PCONP |= (0x1<<22);
  T2TCR  = 0x02;
  T2IR   = 0xFF;
  T2CTCR = 0;
  T2TC   = 0;
  
  /*
  T2PR   = 0;					                        // 1us
  T2MR0  = 250-1;                                               	// (494/25)us            
  T2MR1  = 750-1;                                               	// 658/25(us)            
  T2MCR  = 0x01 | 0x18;                                                 //MR0产生中断，MR1复位TC     
  */
  
  T2PR   = clk_freq/1000000-1;                                         //1us										
  T2MR0  = 3000-1;                                                     //3000*1us             
  T2MCR  = 0x03;                                                      //MR0产生中断，MR0复位TC              
  
  T2TCR  = 0x00;
  
  CSP_IntVectReg(CSP_INT_CTRL_NBR_MAIN,CSP_INT_SRC_NBR_TMR_02,LPC17xx_TIMER2_IntHandler,0);
  CSP_IntEn(CSP_INT_CTRL_NBR_MAIN, CSP_INT_SRC_NBR_TMR_02);
  
} 

/********************************************************************************************************
** 函数名称: Timer3Init
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
void Timer3Init (void)
{
  CPU_INT32U clk_freq = CSP_PM_PerClkFreqGet(CSP_PM_PER_CLK_NBR_TMR_00);
  
  PCONP |= (0x1<<23);
  T3TCR  = 0x02;
  T3IR   = 0xFF;
  T3CTCR = 0;
  T3TC   = 0;
  T3PR   = clk_freq/1000-1;						// 10us
  T3MR0  = 10-1;                                                         // 100*10us            
  T3MCR  = 0x03;                                                      // ?￥??oó2úéú?D???￠?′??            
  T3TCR  = 0x01;
  
  CSP_IntVectReg(CSP_INT_CTRL_NBR_MAIN,CSP_INT_SRC_NBR_TMR_03,LPC17xx_TIMER3_IntHandler,0);
  CSP_IntEn(CSP_INT_CTRL_NBR_MAIN, CSP_INT_SRC_NBR_TMR_03);  
} 

/********************************************************************************************************
** 函数名称: PWM1Init
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
void PWM1Init (void)
{
  CPU_INT32U clk_freq = CSP_PM_PerClkFreqGet(CSP_PM_PER_CLK_NBR_TMR_00);

  PWM1TCR  = 0x02;
  PWM1IR   = 0xFF;
  PWM1CTCR = 0;
  PWM1TC   = 0;
  PWM1PR   = clk_freq/1000000-1;																		// 1us
  PWM1MR0  = 2000-1;                                               	// 2000us            
  PWM1MR1  = 1000-1;                                               	// 1000us            
  PWM1MCR  = 0x0B;                                            	// ?￥??oó2úéú?D???￠?′??	

  CSP_IntVectReg(CSP_INT_CTRL_NBR_MAIN,CSP_INT_SRC_NBR_PWM_01,LPC17xx_PWM1_IntHandler,0);  
  CSP_IntEn(CSP_INT_CTRL_NBR_MAIN, CSP_INT_SRC_NBR_PWM_01);  
} 

/********************************************************************************************************
** 函数名称: ScanInit
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
void ScanInit (void)
{
  CSP_GPIO_Cfg(BSP_GPIO_SCAN_PORT,
               BSP_GPIO_SCAN_OUT,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_BitSet(BSP_GPIO_SCAN_PORT,BSP_GPIO_SCAN_OUT);
} 

/********************************************************************************************************
** 函数名称: RevCrc16Bytes
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
int16u RevCrc16Bytes(int8u *pucData,int8u usrLength,int16u uiPolynomial)
{
  int8u i=8;
  int16u uiCrc;

#if CRC_INIT_VALUE>0
  uiCrc=0xFFFF;
#else
  uiCrc=0x0000;
#endif
  
  do{
    uiCrc^=*pucData++;
    i=8;
    do{
      if((uiCrc & 0x01) != 0){
        uiCrc>>=1;
        uiCrc^=uiPolynomial;
      }else{
        uiCrc>>=1;
      }
    }while(--i);
  }while(--usrLength);
  return uiCrc;
}

/********************************************************************************************************
** 函数名称: BytesToAscs
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
void BytesToAscs(INT8U *pucSource,INT8U ucLen,INT8U *pucDest)
{
  INT8U i;
  
  for(i=0;i<ucLen;i++){
    *pucDest++=ByteToAsc((*pucSource)>>4);
    *pucDest++=ByteToAsc((*pucSource++)&0x0F);
  }
}

/********************************************************************************************************
** 函数名称: AscToByte
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
INT8S AscToByte(INT8U ucData)
{
  if(ucData>=0x30 && ucData<=0x39){
    return ucData-0x30;
  }else if(ucData>=0x41 && ucData<=0x46){
    return ucData-0x37;
  }else{
    return -1;
  }
}

/********************************************************************************************************
** 函数名称: ByteToAsc
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
INT8S ByteToAsc(INT8U ucData)
{
  if(ucData<=9){
    return ucData+0x30;
  }else if(ucData>=10 && ucData<=15){
    return ucData+0x37;
  }else{
    return -1;
  }
}

/********************************************************************************************************
** 函数名称: SprintF
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
void SprintF(INT8U *pucData,INT8U ucLen,INT32U ulData)
{
  INT8U i;
  INT8U ucData[10];
  INT32U ulTmp;

  for(i=0;i<10;i++){
    ulTmp=ulData%10;
    ucData[i]=(INT8U)ulTmp;
    ulData=ulData/10;
  }

  for(i=0;i<ucLen;i++){
    pucData[i]=ByteToAsc(ucData[ucLen-1-i]);
  }	
}

/********************************************************************************************************
** oˉêy??3?: CardBoxGetSelected
** 1|?ü?èê?:
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2005?ê05??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U CardBoxGetSelected(void)
{
  return (((CSP_GPIO_Rd(BSP_GPIO_BOX1_SELECT_PORT)&BSP_GPIO_BOX1_SELECT)>>BSP_GPIO_BOX1_SELECT_BIT)|((CSP_GPIO_Rd(BSP_GPIO_BOX2_SELECT_PORT)&BSP_GPIO_BOX2_SELECT)>>(BSP_GPIO_BOX2_SELECT_BIT-1))|((CSP_GPIO_Rd(BSP_GPIO_BOX3_SELECT_PORT)&BSP_GPIO_BOX3_SELECT)>>(BSP_GPIO_BOX3_SELECT_BIT-2)))&0x07;
}

/********************************************************************************************************
** oˉêy??3?: CardBoxGetSelectedA
** 1|?ü?èê?:
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2005?ê05??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U CardBoxGetSelectedA(void)
{
  return (((CSP_GPIO_Rd(BSP_GPIO_BOX1_SELECT_PORT)&BSP_GPIO_BOX1_SELECT)>>BSP_GPIO_BOX1_SELECT_BIT<<1)|((CSP_GPIO_Rd(BSP_GPIO_BOX2_SELECT_PORT)&BSP_GPIO_BOX2_SELECT)>>(BSP_GPIO_BOX2_SELECT_BIT)))&0x03;
}

/********************************************************************************************************
** 函数名称: CardBoxSetSelected
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
INT8U CardBoxSetSelected(INT8U ucSelected,INT8U ucMode)
{
  INT8U i;
#if BOARD_OLD_EN==0
  ucSelected=m_ucUartBit[ucSelected];
  for(i=0;i<4;i++){
    switch(ucSelected){
      case 0:
        if((CardBoxGetSelected()&0x01)==ucMode){
          return TRUE;
        }
        if(ucMode){
          CSP_GPIO_BitSet(BSP_GPIO_BOX1_SELECT_PORT,
                          BSP_GPIO_BOX1_SELECT);
        }else{
          CSP_GPIO_BitClr(BSP_GPIO_BOX1_SELECT_PORT,
                          BSP_GPIO_BOX1_SELECT);
        }
        break;
      case 1:
        if(((CardBoxGetSelected()>>1)&0x01)==ucMode){
          return TRUE;
        }
        if(ucMode){
          CSP_GPIO_BitSet(BSP_GPIO_BOX2_SELECT_PORT,
                          BSP_GPIO_BOX2_SELECT);
          
        }else{
          CSP_GPIO_BitClr(BSP_GPIO_BOX2_SELECT_PORT,
                          BSP_GPIO_BOX2_SELECT);
        }
        break;
      case 2:
        if(((CardBoxGetSelected()>>2)&0x01)==ucMode){
          return TRUE;
        }
        if(ucMode){
          CSP_GPIO_BitSet(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
          
        }else{
          CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
        }
        break;
      default:
        if(CardBoxGetSelected()==0){
          return TRUE;
        }
        CSP_GPIO_BitClr(BSP_GPIO_BOX1_SELECT_PORT,
                        BSP_GPIO_BOX1_SELECT);
        CSP_GPIO_BitClr(BSP_GPIO_BOX2_SELECT_PORT,
                        BSP_GPIO_BOX2_SELECT);
        CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                        BSP_GPIO_BOX3_SELECT);
        break;
    }
    m_usrBoxInfo[ucSelected].ucTimes=1;
  }
  return FALSE;
#else
  INT8U ucTmp;
  for(i=0;i<4;i++){
    switch(ucSelected){
      case 0:
        if(ucMode){
          ucTmp=0x04;
        }else{
          ucTmp=0x00;
        }
        if(CardBoxGetSelected()==ucTmp){
          return TRUE;
        }
        CSP_GPIO_BitClr(BSP_GPIO_BOX1_SELECT_PORT,
                        BSP_GPIO_BOX1_SELECT);
        CSP_GPIO_BitClr(BSP_GPIO_BOX2_SELECT_PORT,
                        BSP_GPIO_BOX2_SELECT);
        if(ucMode){
          CSP_GPIO_BitSet(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
        }else{
          CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
        }
        break;
      case 1:
        if(ucMode){
          ucTmp=0x06;
        }else{
          ucTmp=0x02;
        }
        if(CardBoxGetSelected()==ucTmp){
          return TRUE;
        }
        CSP_GPIO_BitClr(BSP_GPIO_BOX1_SELECT_PORT,
                        BSP_GPIO_BOX1_SELECT);
        CSP_GPIO_BitSet(BSP_GPIO_BOX2_SELECT_PORT,
                        BSP_GPIO_BOX2_SELECT);
        if(ucMode){
          CSP_GPIO_BitSet(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
        }else{
          CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
        }
        break;
      case 2:
        if(ucMode){
          ucTmp=0x05;
        }else{
          ucTmp=0x01;
        }
        if(CardBoxGetSelected()==ucTmp){
          return TRUE;
        }
        CSP_GPIO_BitSet(BSP_GPIO_BOX1_SELECT_PORT,
                        BSP_GPIO_BOX1_SELECT);
        CSP_GPIO_BitClr(BSP_GPIO_BOX2_SELECT_PORT,
                        BSP_GPIO_BOX2_SELECT);
        if(ucMode){
          CSP_GPIO_BitSet(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
        }else{
          CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                          BSP_GPIO_BOX3_SELECT);
        }
        break;
      default:
        ucTmp=0;
        if(CardBoxGetSelected()==ucTmp){
          return TRUE;
        }
        CSP_GPIO_BitClr(BSP_GPIO_BOX1_SELECT_PORT,
                        BSP_GPIO_BOX1_SELECT);
        CSP_GPIO_BitClr(BSP_GPIO_BOX2_SELECT_PORT,
                        BSP_GPIO_BOX2_SELECT);
        CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                        BSP_GPIO_BOX3_SELECT);
        break;
    } 
  }
  return FALSE;
#endif
}

/********************************************************************************************************
** 函数名称: CardBoxPower
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
INT8U CardBoxPower(INT8U ucMode)
{
  INT8U i;
  INT8U ucTmp;
  INT8U ucType=DEV_TYPE();
  
  for(i=0;i<4;i++){
    if(ucMode){
      ucTmp=0x04;
    }else{
      ucTmp=0x00;
    }
    
    if((CardBoxGetSelected()&0x04)==ucTmp){
      return TRUE;
    }
    if(ucMode){
      CSP_GPIO_BitSet(BSP_GPIO_BOX3_SELECT_PORT,
                      BSP_GPIO_BOX3_SELECT);
    }else{
      CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                      BSP_GPIO_BOX3_SELECT);
    }
    if(ucType==LARGE_THICK_OUT_TYPE){
      m_usrBoxInfo[BOX_FIRST].ucTimes=1;    
    }else{
      m_usrBoxInfo[BOX_FIRST].ucTimes=2000/BOX_CONNECT_TIME_DEFAULT+1;    
    }
  }
  return FALSE;
}

/********************************************************************************************************
** 函数名称: DMotoSelectGet
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
void DMotoSelectGet(INT8U ucMode)
{
  INT8U i;
  INT8U j;
  INT8U ucData[8];
  INT8U ucMoto[8];
  INT8U ucErr;

  ucErr=1;
  if(EepromReadVerifyBytes(DMOTO_SELECT_ADDR,ucMoto,4)){
    ucData[0]=ucMoto[0] & 0x0F;
    ucData[1]=(ucMoto[0]>>4) & 0x0F;
    ucData[2]=ucMoto[1] & 0x0F;
    ucData[3]=(ucMoto[1]>>4) & 0x0F;
    ucData[4]=ucMoto[2] & 0x0F;
    ucData[5]=(ucMoto[2]>>4) & 0x0F;
    ucData[6]=ucMoto[3] & 0x0F;
    ucData[7]=(ucMoto[3]>>4) & 0x0F;
    
    ucErr=0;
    for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
      if(ucData[i]>=CARDMACHINE_DMOTO_NUMS){
        ucErr=1;
        break;
      }
    }
    for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
      for(j=i+1;j<CARDMACHINE_DMOTO_NUMS;j++){
        if(ucData[i]==ucData[j]){
          ucErr=1;
          break;
        }
      }
      if(ucErr){
        break;
      }
    }
  }
  if(ucErr){
    m_ucDMotoBit[0]=DMOTO_FIRST;
    m_ucDMotoBit[1]=DMOTO_SECOND;
    m_ucDMotoBit[2]=DMOTO_THIRD;
    m_ucDMotoBit[3]=DMOTO_FOURTH;
    m_ucDMotoBit[4]=DMOTO_FIRST;
    m_ucDMotoBit[5]=DMOTO_SECOND;
    m_ucDMotoBit[6]=DMOTO_THIRD;
    
    ucData[0]=(m_ucDMotoBit[0] & 0x0F) | ((m_ucDMotoBit[1]<<4) & 0xF0);
    ucData[1]=(m_ucDMotoBit[2] & 0x0F) | ((m_ucDMotoBit[3]<<4) & 0xF0);
    ucData[2]=(m_ucDMotoBit[4] & 0x0F) | ((m_ucDMotoBit[5]<<4) & 0xF0);
    ucData[3]=(m_ucDMotoBit[6] & 0x0F);
    EepromWriteVerifyBytes(DMOTO_SELECT_ADDR,ucData,4);
  }else{
    for(i=0;i<CARDMACHINE_DMOTO_NUMS+3;i++){
      m_ucDMotoBit[i]=ucData[i];
    }
  }
}

/********************************************************************************************************
** 函数名称: SMotoSelectGet
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
void SMotoSelectGet(INT8U ucMode)
{
  INT8U ucData[8];
  INT8U ucErr;
  
  ucErr=1;
  if(EepromReadVerifyBytes(SMOTO_SELECT_ADDR,ucData,2)){
    ucErr=0;
    if(ucData[0]==ucData[1] || ucData[0]>1 || ucData[1]>1){
      ucErr=1;
    }
  }
  if(ucErr){
    m_ucSMotoBit[0]=SMOTO_FIRST;
    m_ucSMotoBit[1]=SMOTO_SECOND;
    ucData[0]=m_ucSMotoBit[0];
    ucData[1]=m_ucSMotoBit[1];
    EepromWriteVerifyBytes(SMOTO_SELECT_ADDR,ucData,2);
  }else{
    m_ucSMotoBit[0]=ucData[0];
    m_ucSMotoBit[1]=ucData[1];
  }
}

/********************************************************************************************************
** 函数名称: BoxSelectGet
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
void BoxSelectGet(INT8U ucMode)
{
  INT8U i;
  INT8U j;
  INT8U ucData[8];
  INT8U ucBox[2];
  INT8U ucErr;
  
  ucErr=1;
  if(EepromReadVerifyBytes(BOX_SELECT_ADDR,ucBox,2)){
    ucData[0]=ucBox[0] & 0x0F;
    ucData[1]=(ucBox[0]>>4) & 0x0F;
    ucData[2]=ucBox[1] & 0x0F;
    ucErr=0;
    for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
      if(ucData[i]>=CARDMACHINE_CARDBOX_NUMS){
        ucErr=1;
        break;
      }
    }
    if(!ucErr){
      for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
        for(j=i+1;j<CARDMACHINE_CARDBOX_NUMS;j++){
          if(ucData[i]==ucData[j]){
            ucErr=1;
            break;
          }
        }
        if(ucErr==1){
          break;
        }
      }
    }
  }
  if(ucErr){
    m_ucUartBit[0]=1;
    m_ucUartBit[1]=0;
    m_ucUartBit[2]=2;
    ucData[0]=(m_ucUartBit[0] & 0x0F) | ((m_ucUartBit[1]<<4) & 0xF0);
    ucData[1]=(m_ucUartBit[2] & 0x0F);
    EepromWriteVerifyBytes(BOX_SELECT_ADDR,ucData,2);
  }else{
    m_ucUartBit[0]=ucData[0];
    m_ucUartBit[1]=ucData[1];
    m_ucUartBit[2]=ucData[2];
  }
}

/********************************************************************************************************
** 函数名称: KeySelectGet
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
void KeySelectGet(INT8U ucMode)
{
  INT8U ucType=DEV_TYPE();
  
#if BOARD_OLD_EN==0  
  INT8U i;
  INT8U j;
  INT8U ucData[32];
  INT8U ucErr;
  INT8U ucErr1;
  
  INT8U ucGroup=GroupSelectGet();
  
  for(i=0;i<4;i++){
    ucErr1=1;
    if(EepromReadVerifyBytes(KEY0_SELECT_ADDR+i*8,&ucData[i*6],6)){
      ucErr1=0;
    }else{
      break;
    }
  }
  if(!ucErr1){
    KeyBitDecode(ucData);
    ucErr=0;
    for(i=0;i<32;i++){
      if(ucData[i]<32){
        for(j=i+1;j<32;j++){
          if(ucData[i]==ucData[j]){
            ucErr=1;
            break;
          }
        }
        if(ucErr){
          break;
        }
      }else{
        ucErr=1;
        break;
      }
    }
  }
  if(ucErr1 || ucErr){
    if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
      Mem_Copy(ucData,&m_ucKey_GROUP_SMALL_ZIN_TYPE[ucGroup*32],32);
    }else{
      for(i=0;i<32;i++){
        m_ucKeyBit[i]=i;
        ucData[i]=i;
      }
    }
    KeyBitEncode(ucData);
    for(i=0;i<4;i++){
      EepromWriteVerifyBytes(KEY0_SELECT_ADDR+i*8,&ucData[i*6],6);
    }
  }else{
    for(i=0;i<32;i++){
      m_ucKeyBit[i]=ucData[i];
    }
  }
#else
  
  if(ucType==LARGE_OUT_TYPE){
    m_ucKeyBit[0]=4;
    m_ucKeyBit[1]=5;
    m_ucKeyBit[2]=25;
    m_ucKeyBit[3]=20;
    m_ucKeyBit[4]=6;
    m_ucKeyBit[5]=7;
    m_ucKeyBit[6]=16;
    m_ucKeyBit[7]=8;
    
    m_ucKeyBit[8]=27;
    m_ucKeyBit[9]=28;
    m_ucKeyBit[10]=26;
    m_ucKeyBit[11]=19;
    m_ucKeyBit[12]=9;
    m_ucKeyBit[13]=10;
    m_ucKeyBit[14]=13;
    m_ucKeyBit[15]=11;
    
    m_ucKeyBit[16]=29;
    m_ucKeyBit[17]=21;
    m_ucKeyBit[18]=1;
    m_ucKeyBit[19]=18;
    m_ucKeyBit[20]=14;
    m_ucKeyBit[21]=15;
    m_ucKeyBit[22]=12;
    m_ucKeyBit[23]=17;
    
    m_ucKeyBit[24]=0;
    m_ucKeyBit[25]=2;
    m_ucKeyBit[26]=3;
    m_ucKeyBit[27]=24;
    m_ucKeyBit[28]=22;
    m_ucKeyBit[28]=23;
    m_ucKeyBit[30]=30;
    m_ucKeyBit[31]=31;
  }else{
    m_ucKeyBit[0]=3;
    m_ucKeyBit[1]=2;
    m_ucKeyBit[2]=4;
    m_ucKeyBit[3]=5;
    m_ucKeyBit[4]=6;
    m_ucKeyBit[5]=7;
    m_ucKeyBit[6]=0;
    m_ucKeyBit[7]=8;
    
    m_ucKeyBit[8]=9;
    m_ucKeyBit[9]=10;
    m_ucKeyBit[10]=11;
    m_ucKeyBit[11]=12;
    m_ucKeyBit[12]=13;
    m_ucKeyBit[13]=14;
    m_ucKeyBit[14]=15;
    m_ucKeyBit[15]=16;
    
    m_ucKeyBit[16]=17;
    m_ucKeyBit[17]=18;
    m_ucKeyBit[18]=19;
    m_ucKeyBit[19]=20;
    m_ucKeyBit[20]=21;
    m_ucKeyBit[21]=22;
    m_ucKeyBit[22]=23;
    m_ucKeyBit[23]=26;
    
    m_ucKeyBit[24]=24;
    m_ucKeyBit[25]=27;
    m_ucKeyBit[26]=25;
    m_ucKeyBit[27]=1;
    m_ucKeyBit[28]=28;
    m_ucKeyBit[29]=29;
    m_ucKeyBit[30]=30;
    m_ucKeyBit[31]=31;
  }
#endif
}


/********************************************************************************************************
** 函数名称: KeyBitEncode
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
void KeyBitEncode(INT8U *pucData)
{
  INT8U i;
  INT8U ucData[64];
  INT8U ucStart=1;
  INT8U ucMove;
  INT8U ucIndex=0;
  INT8U ucBits=8;

  for(i=0;i<32;i++){
    ucData[i]=0;
  }
  for(i=0;i<32;i++){
    if(ucStart){
      ucStart=0;
      ucData[ucIndex]=(*(pucData+i));
      ucMove=ucBits-6;
    }else{
      if(ucMove){
        ucData[ucIndex]=ucData[ucIndex]|((*(pucData+i))<<(ucBits-ucMove));
        ucIndex++;
      }
      ucData[ucIndex]=((*(pucData+i))>>(ucMove));
      ucMove=ucBits-(6-ucMove);
      if(ucMove==8){
        ucStart=1;
      }
    }
  }
  for(i=0;i<32;i++){
    *(pucData+i)=ucData[i];
  }
}

/********************************************************************************************************
** 函数名称: KeyBitDecode
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
void KeyBitDecode(INT8U *pucData)
{
  INT8U i;
  INT8U ucData[64];
  INT8U ucStart=1;
  INT8U ucMove;
  INT8U ucIndex=0;
  INT8U ucBits=8;

  for(i=0;i<32;i++){
    ucData[i]=0;
  }

  ucStart=1;
  ucMove=0;
  ucIndex=0;
  ucBits=8;
  for(i=0;i<32;i++){
    if(ucStart){
      ucStart=0;
      ucData[ucIndex]=(*(pucData+i))&0x3F;
      ucIndex++;
      ucMove=ucBits-6;
    }else{
      if(ucMove){
        ucData[ucIndex]=((*(pucData+i-1))>>(8-ucMove));
      }
      ucData[ucIndex]=(ucData[ucIndex] | ((*(pucData+i))<<ucMove))&0x3F;
      ucIndex++;
      ucMove=ucBits-(6-ucMove);
      if(ucMove>=6){
        ucData[ucIndex]=((*(pucData+i))>>(8-ucMove))&0x3F;
        ucIndex++;
        ucStart=1;
      }
}
  }

  for(i=0;i<32;i++){
    *(pucData+i)=ucData[i];
  }
}

/********************************************************************************************************
** 函数名称: GroupSelectGet
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
INT8U GroupSelectGet(void)
{
  INT8U ucData;
  
  if(!EepromReadVerifyBytes(GROUP_SELECT_ADDR,&ucData,1)){
    ucData=0;
    EepromWriteVerifyBytes(GROUP_SELECT_ADDR,&ucData,1);
  }
  return ucData;
}
                        
/********************************************************************************************************
** 函数名称: ScanParamsGet
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
void ScanParamsGet(void)
{
  INT8U ucData[2];
  
  if(!EepromReadVerifyBytes(SCAN_PARAMS_ADDR,ucData,2)){
    ucData[0]=SCAN_OPEN_TIMES;
    ucData[1]=SCAN_CLOSE_TIMES;
    EepromWriteVerifyBytes(SCAN_PARAMS_ADDR,ucData,2);
  }
  g_ucScanOpenTime=ucData[0];
  g_ucScanCloseTime=ucData[1];
}                        

/********************************************************************************************************
** 函数名称: DMotoPosBySelected
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
INT8U DMotoPosBySelected(INT8U ucSelected) 
{	
  if(ucSelected>CARDMACHINE_DMOTO_NUMS-1){
    return 0;
  }
  return m_ucDMotoBit[CARDMACHINE_DMOTO_NUMS+ucSelected];
}

/********************************************************************************************************
** 函数名称: DMotoByPos
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
INT8U DMotoByPos(INT8U ucPos)
{
  INT8U i;
  
  for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
    if(m_ucDMotoBit[i+CARDMACHINE_DMOTO_NUMS]==ucPos){
      return i;
    }
  }
  return 0;	
}

/********************************************************************************************************
** 函数名称: DEV_TYPE
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
INT8U DEV_TYPE(void)
{
#if BOARD_OLD_EN==0
  return (~(CSP_GPIO_Rd(BSP_GPIO_DEV_TYPE_PORT)>>BSP_GPIO_DEV1_TYPE_BIT)) & 0x7;
#else
  return ((~(CSP_GPIO_Rd(BSP_GPIO_DEV_TYPE_PORT)>>BSP_GPIO_DEV1_TYPE_BIT)) & 0x01) | ((~(CSP_GPIO_Rd(BSP_GPIO_DEV2_TYPE_PORT)>>(BSP_GPIO_DEV2_TYPE_BIT-2))) & 0x4);  
#endif
}

/********************************************************************************************************
** 函数名称: CARD_AUTO_MODE
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
INT8U CARD_AUTO_MODE(void)
{  
  CSP_GPIO_MSK ulTmp=CSP_GPIO_Rd(BSP_GPIO_AUTOCARD_PORT);
#if BOARD_OLD_EN==0  
  if(!CheckBit(ulTmp,BSP_GPIO_AUTOCARD_BIT)){
#else
  if(CheckBit(ulTmp,BSP_GPIO_AUTOCARD_BIT)){
#endif
    return TRUE;
  }
  return FALSE;
}  

/********************************************************************************************************
** oˉêy??3?: SMotoFreqRead
** 1|?ü?èê?:
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2005?ê05??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void SMotoFreqGet(void)
{
  INT8U ucTmp;
  INT8U i;
  
  for(i=0;i<CARDMACHINE_SMOTO_NUMS;i++){
    if(!EepromReadVerifyBytes(SMOTO_FREQ_ADDR+i*4,(INT8U *)&ucTmp,1)){
      ucTmp=SMOTO_FREQ_DEFAULT;
      EepromWriteVerifyBytes(SMOTO_FREQ_ADDR+i*4,(INT8U *)&ucTmp,1);
    }
    if(ucTmp<SMOTO_FREQ_MIN || ucTmp>SMOTO_FREQ_2500US){
      ucTmp=SMOTO_FREQ_DEFAULT;
      EepromWriteVerifyBytes(SMOTO_FREQ_ADDR+i*4,&ucTmp,1);
    }	
    m_ucSMotoFreq[i]=ucTmp;
  }
}

/********************************************************************************************************
** oˉêy??3?: DMotoPwmGet
** 1|?ü?èê?:
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2005?ê05??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void DMotoPwmGet(void)
{
  INT16U uiPwm;
  INT8U i;
  
  for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
    if(!EepromReadVerifyBytes(DMOTO_PWM_ADDR+i*4,(INT8U *)&uiPwm,2)){
      uiPwm=DMOTO_FREQ_DEFAULT;
      EepromWriteVerifyBytes(DMOTO_PWM_ADDR+i*4,(INT8U *)&uiPwm,2);
    }
    if(uiPwm<DMOTO_PWM_700 ||uiPwm>DMOTO_FREQ_DEFAULT){
      uiPwm=DMOTO_FREQ_DEFAULT;
      EepromWriteVerifyBytes(DMOTO_PWM_ADDR+i*4,(INT8U *)&uiPwm,2);
    }
    m_uiDMotoPwm[i]=uiPwm;
  }
}

/********************************************************************************************************
** oˉêy??3?: AutoOutModeGet
** 1|?ü?èê?:
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2005?ê05??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U AutoOutModeGet(void)
{
  INT8U ucTmp;
  
  if(!EepromReadVerifyBytes(AUTOOUT_MODE_ADDR,&ucTmp,1)){
    ucTmp=0x01;
    EepromWriteVerifyBytes(AUTOOUT_MODE_ADDR,&ucTmp,1);
  }
  return ucTmp;
}

/********************************************************************************************************
** oˉêy??3?: BuzzEnGet
** 1|?ü?èê?:
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2005?ê05??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U BuzzEnGet(void)
{
  INT8U ucTmp;
  
  if(!EepromReadVerifyBytes(BUZZ_EN_ADDR,&ucTmp,1)){
    ucTmp=0x01;
    EepromWriteVerifyBytes(BUZZ_EN_ADDR,&ucTmp,1);
  }
  return ucTmp;
}



/********************************************************************************************************
** 函数名称: Box_TaskQPost
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
INT8U Box_TaskQPost(OS_TCB *p_tcb,INT8U *p_ucMsg,INT8U ucLen)
{
  OS_ERR os_err;
  LIB_ERR lib_err;
  CPU_INT08U  *pMsg; 
  
  INT8U ucType=DEV_TYPE();
  
  pMsg= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_BoxPool,
                                   (CPU_SIZE_T) ucLen,
                                   (LIB_ERR  *)&lib_err);
  if(pMsg!=0){
    Mem_Copy(pMsg,p_ucMsg,ucLen);
    OSTaskQPost(p_tcb, pMsg, ucLen, OS_OPT_POST_FIFO, &os_err);
    return TRUE;
  }
  return FALSE;
}


/********************************************************************************************************
** 函数名称: Box_PostMsg
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
INT8U Box_TaskLcdQPost(OS_TCB *p_tcb,INT8U *p_ucMsg,INT8U ucLen)
{
  OS_ERR os_err;
  LIB_ERR lib_err;
  CPU_INT08U  *pMsg; 
  
  INT8U ucType=DEV_TYPE();
  
  if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_OUT_TYPE || ucType==SMALL_THICK_GIN_TYPE || ucType==SMALL_THIN_IN_TYPE || ucType==SMALL_THIN_OUT_TYPE || ucType==SMALL_THIN_GIN_TYPE){
    pMsg= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_BoxPool,
                                     (CPU_SIZE_T) ucLen,
                                     (LIB_ERR  *)&lib_err);
    if(pMsg!=0){
      Mem_Copy(pMsg,p_ucMsg,ucLen);
      OSTaskQPost(p_tcb, pMsg, ucLen, OS_OPT_POST_FIFO, &os_err);
      return TRUE;
    }
    return FALSE;
  }else{
    return TRUE;
  }
}

/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/

