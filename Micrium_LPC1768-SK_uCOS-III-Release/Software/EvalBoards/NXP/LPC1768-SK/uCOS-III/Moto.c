/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------???tD??￠---------------------------------------------------------------------------------
*??   ?t   ??: Moto.c
*′′   ?¨   è?: John Tonny
*×?oóDT??è??ú: 2009?ê11??01è?
*?è        ê?:
*
*--------------àúê·°?±?D??￠-----------------------------------------------------------------------------
* ′′?¨è?: John Tonny
* °?  ±?: V1.0
* è????ú: 2009?ê11??01è?
* ?è??ê?: ?-ê?°?±?
*
*-------------------------------------------------------------------------------------------------------
* DT??è?:
* °?  ±?:
* è????ú:
* ?è??ê?:
*
*--------------μ±?°°?±?DT??-----------------------------------------------------------------------------
* DT??è?:
* è????ú:
* ?è??ê?:
*
*-------------------------------------------------------------------------------------------------------
*******************************************************************************************************/

#define MOTO_GLOBALS
#include "includes.h"

INT8U BUZZ_SK_MODE[4]={5,10,20,40};

#define OpenScan()           		  CSP_GPIO_BitClr(BSP_GPIO_SCAN_PORT,BSP_GPIO_SCAN_OUT);
#define CloseScan()           		  CSP_GPIO_BitSet(BSP_GPIO_SCAN_PORT,BSP_GPIO_SCAN_OUT);


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
void MotoInit(void)
{
  //DMoto1
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO1_EN1_PORT,
               BSP_GPIO_DMOTO1_EN1,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO1_EN2_PORT,
               BSP_GPIO_DMOTO1_EN2,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN1_PORT,
                  BSP_GPIO_DMOTO1_EN1);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN2_PORT,
                  BSP_GPIO_DMOTO1_EN2);
  
  //DMoto2
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO2_EN1_PORT,
               BSP_GPIO_DMOTO2_EN1,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO2_EN2_PORT,
               BSP_GPIO_DMOTO2_EN2,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN1_PORT,
                  BSP_GPIO_DMOTO2_EN1);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN2_PORT,
                  BSP_GPIO_DMOTO2_EN2);

  //DMoto3f
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO3_EN1_PORT,
               BSP_GPIO_DMOTO3_EN1,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO3_EN2_PORT,
               BSP_GPIO_DMOTO3_EN2,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN1_PORT,
                  BSP_GPIO_DMOTO3_EN1);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN2_PORT,
                  BSP_GPIO_DMOTO3_EN2);

  //DMoto4
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO4_EN1_PORT,
               BSP_GPIO_DMOTO4_EN1,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO4_EN2_PORT,
               BSP_GPIO_DMOTO4_EN2,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN1_PORT,
                  BSP_GPIO_DMOTO4_EN1);
  CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN2_PORT,
                  BSP_GPIO_DMOTO4_EN2);


  //SMoto1
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO1_CC_PORT,
               BSP_GPIO_SMOTO1_CC,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO1_CLK_PORT,
               BSP_GPIO_SMOTO1_CLK,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO1_EN_PORT,
               BSP_GPIO_SMOTO1_EN,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO1_RST_PORT,
               BSP_GPIO_SMOTO1_RST,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);

  CSP_GPIO_BitSet(BSP_GPIO_SMOTO1_CC_PORT,
                  BSP_GPIO_SMOTO1_CC);
  CSP_GPIO_BitSet(BSP_GPIO_SMOTO1_CLK_PORT,
                  BSP_GPIO_SMOTO1_CLK);
  CSP_GPIO_BitSet(BSP_GPIO_SMOTO1_EN_PORT,
                  BSP_GPIO_SMOTO1_EN);
  CSP_GPIO_BitSet(BSP_GPIO_SMOTO1_RST_PORT,
                  BSP_GPIO_SMOTO1_RST);
  
  //SMoto2
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO2_CC_PORT,
               BSP_GPIO_SMOTO2_CC,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO2_CLK_PORT,
               BSP_GPIO_SMOTO2_CLK,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO2_EN_PORT,
               BSP_GPIO_SMOTO2_EN,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_SMOTO2_RST_PORT,
               BSP_GPIO_SMOTO2_RST,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_BitSet(BSP_GPIO_SMOTO2_CC_PORT,
                  BSP_GPIO_SMOTO2_CC);
  CSP_GPIO_BitSet(BSP_GPIO_SMOTO2_CLK_PORT,
                  BSP_GPIO_SMOTO2_CLK);
  CSP_GPIO_BitSet(BSP_GPIO_SMOTO2_EN_PORT,
                  BSP_GPIO_SMOTO2_EN);
  CSP_GPIO_BitSet(BSP_GPIO_SMOTO2_RST_PORT,
                  BSP_GPIO_SMOTO2_RST);

  //Pos1
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO1_POSA_PORT,
               BSP_GPIO_DMOTO1_POSA,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO1_POSB_PORT,
               BSP_GPIO_DMOTO1_POSB,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSE1_PORT,
               BSP_GPIO_CARD_POSE1,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOXLOAD1_PORT,
               BSP_GPIO_BOXLOAD1,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX1_REV1_PORT,
               BSP_GPIO_BOX1_REV1,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX1_REV2_PORT,
               BSP_GPIO_BOX1_REV2,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX1_POS_PORT,
               BSP_GPIO_BOX1_POS,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);

  //Pos2
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO2_POSA_PORT,
               BSP_GPIO_DMOTO2_POSA,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO2_POSB_PORT,
               BSP_GPIO_DMOTO2_POSB,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSE2_PORT,
               BSP_GPIO_CARD_POSE2,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOXLOAD2_PORT,
               BSP_GPIO_BOXLOAD2,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX2_REV1_PORT,
               BSP_GPIO_BOX2_REV1,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX2_REV2_PORT,
               BSP_GPIO_BOX2_REV2,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX2_POS_PORT,
               BSP_GPIO_BOX2_POS,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  
  //Pos3
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO3_POSA_PORT,
               BSP_GPIO_DMOTO3_POSA,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DMOTO3_POSB_PORT,
               BSP_GPIO_DMOTO3_POSB,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSE3_PORT,
               BSP_GPIO_CARD_POSE3,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOXLOAD3_PORT,
               BSP_GPIO_BOXLOAD3,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX3_REV1_PORT,
               BSP_GPIO_BOX3_REV1,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX3_REV2_PORT,
               BSP_GPIO_BOX3_REV2,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX3_POS_PORT,
               BSP_GPIO_BOX3_POS,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);

  //Pos4
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSA_PORT,
               BSP_GPIO_CARD_POSA,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSB_PORT,
               BSP_GPIO_CARD_POSB,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSC_PORT,
               BSP_GPIO_CARD_POSC,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSD_PORT,
               BSP_GPIO_CARD_POSD,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSE_PORT,
               BSP_GPIO_CARD_POSE,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_CARD_POSF_PORT,
               BSP_GPIO_CARD_POSF,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  
  //AutoCard
  CSP_GPIO_Cfg(BSP_GPIO_AUTOCARD_PORT,
               BSP_GPIO_AUTOCARD,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);

  //DEV TYPE
  CSP_GPIO_Cfg(BSP_GPIO_DEV_TYPE_PORT,
               BSP_GPIO_DEV1_TYPE,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
#if BOARD_OLD_EN==0  
  CSP_GPIO_Cfg(BSP_GPIO_DEV_TYPE_PORT,
               BSP_GPIO_DEV2_TYPE,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DEV_TYPE_PORT,
               BSP_GPIO_DEV3_TYPE,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
#else
  CSP_GPIO_Cfg(BSP_GPIO_DEV2_TYPE_PORT,
               BSP_GPIO_DEV2_TYPE,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_DEV3_TYPE_PORT,
               BSP_GPIO_DEV3_TYPE,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);  
  CSP_GPIO_BitClr(BSP_GPIO_DEV3_TYPE_PORT,
                  BSP_GPIO_DEV3_TYPE);
#endif  

  CSP_GPIO_Cfg(BSP_GPIO_BOX1_SELECT_PORT,
               BSP_GPIO_BOX1_SELECT,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX2_SELECT_PORT,
               BSP_GPIO_BOX2_SELECT,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CSP_GPIO_Cfg(BSP_GPIO_BOX3_SELECT_PORT,
               BSP_GPIO_BOX3_SELECT,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);

  CSP_GPIO_BitClr(BSP_GPIO_BOX1_SELECT_PORT,
                  BSP_GPIO_BOX1_SELECT);
  CSP_GPIO_BitClr(BSP_GPIO_BOX2_SELECT_PORT,
                  BSP_GPIO_BOX2_SELECT);
  CSP_GPIO_BitClr(BSP_GPIO_BOX3_SELECT_PORT,
                  BSP_GPIO_BOX3_SELECT);
  

  CSP_GPIO_Cfg(BSP_GPIO_SELFTEST_KEY_PORT,
               BSP_GPIO_SELFTEST_KEY,
               CSP_GPIO_DIR_IN,
               CSP_GPIO_FLAG_MODE_PULLUP,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
    
}

/********************************************************************************************************
** 函数名称: SMotoHook
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
void SMotoHook(void)
{
  INT8U i;

  for(i=0;i<CARDMACHINE_SMOTO_NUMS;i++){
    if(g_usrSMoto[i].ucEnabled){
      if(g_usrSMoto[i].uiCounts>0){
        MOTO_STEP_CLK(i);
        g_usrSMoto[i].uiCounts--;
      }else{
        MOTO_STEP_DISABLED(i,INTERRUPT_MODE); 
      }      
    }else{
      MOTO_STEP_DISABLED(i,INTERRUPT_MODE); 
    }
  }
}

/********************************************************************************************************
** 函数名称: DMotoHook
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
void DMotoHook(void)
{
  INT8U i;
  for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
    if(g_usrDMoto[i].ucEnabled){
      if(g_usrDMoto[i].uiFreq!=g_usrDMoto[i].uiPwm){
        MOTO_DC_CLK(i);
      }
    }
  }
}

/********************************************************************************************************
** 函数名称: MOTO_DC_FORWARD
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
void MOTO_DC_FORWARD(INT8U ucSelected)
{
  switch(ucSelected){
    case 0:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN1_PORT,BSP_GPIO_DMOTO1_EN1);
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO1_EN2_PORT,BSP_GPIO_DMOTO1_EN2);
      break;
    case 1:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN1_PORT,BSP_GPIO_DMOTO2_EN1);
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO2_EN2_PORT,BSP_GPIO_DMOTO2_EN2);
      break;
    case 2:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN1_PORT,BSP_GPIO_DMOTO3_EN1);
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO3_EN2_PORT,BSP_GPIO_DMOTO3_EN2);
      break;
    case 3:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN1_PORT,BSP_GPIO_DMOTO4_EN1);
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO4_EN2_PORT,BSP_GPIO_DMOTO4_EN2);
      break;
  }
}

/********************************************************************************************************
** 函数名称: MOTO_DC_BACKWARD
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
void MOTO_DC_BACKWARD(INT8U ucSelected)
{
  switch(ucSelected){
    case 0:
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO1_EN1_PORT,BSP_GPIO_DMOTO1_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN2_PORT,BSP_GPIO_DMOTO1_EN2);
      break;
    case 1:
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO2_EN1_PORT,BSP_GPIO_DMOTO2_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN2_PORT,BSP_GPIO_DMOTO2_EN2);
      break;
    case 2:
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO3_EN1_PORT,BSP_GPIO_DMOTO3_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN2_PORT,BSP_GPIO_DMOTO3_EN2);
      break;
    case 3:
      CSP_GPIO_BitClr(BSP_GPIO_DMOTO4_EN1_PORT,BSP_GPIO_DMOTO4_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN2_PORT,BSP_GPIO_DMOTO4_EN2);
      break;
  }
}

/********************************************************************************************************
** 函数名称: MOTO_DC_DISABLED
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
void MOTO_DC_DISABLED(INT8U ucSelected,INT8U ucMode)
{
  INT8U i;
  INT8U ucEnabled;

  CPU_SR_ALLOC();

  if(ucSelected>=CARDMACHINE_DMOTO_NUMS){
    return;
  }

  if(ucMode){
    g_usrDMoto[ucSelected].ucEnabled=0;
    ucEnabled=0;
    for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
      if(g_usrDMoto[i].ucEnabled){
        ucEnabled=1;
        break;
      }
    }
    if(!ucEnabled){
      DMOTO_DISABLED();
    }
  }else{
    OS_ENTER_CRITICAL();
    g_usrDMoto[ucSelected].ucEnabled=0;
    ucEnabled=0;
    for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
      if(g_usrDMoto[i].ucEnabled){
        ucEnabled=1;
        break;
      }
    }
    if(!ucEnabled){
      DMOTO_DISABLED();
    }
    OS_EXIT_CRITICAL();
  }


  switch(ucSelected){
    case 0:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN1_PORT,BSP_GPIO_DMOTO1_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN2_PORT,BSP_GPIO_DMOTO1_EN2);
      break;
    case 1:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN1_PORT,BSP_GPIO_DMOTO2_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN2_PORT,BSP_GPIO_DMOTO2_EN2);
      break;
    case 2:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN1_PORT,BSP_GPIO_DMOTO3_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN2_PORT,BSP_GPIO_DMOTO3_EN2);
      break;
    case 3:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN1_PORT,BSP_GPIO_DMOTO4_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN2_PORT,BSP_GPIO_DMOTO4_EN2);
      break;
    default:
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN1_PORT,BSP_GPIO_DMOTO1_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO1_EN2_PORT,BSP_GPIO_DMOTO1_EN2);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN1_PORT,BSP_GPIO_DMOTO2_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO2_EN2_PORT,BSP_GPIO_DMOTO2_EN2);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN1_PORT,BSP_GPIO_DMOTO3_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO3_EN2_PORT,BSP_GPIO_DMOTO3_EN2);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN1_PORT,BSP_GPIO_DMOTO4_EN1);
      CSP_GPIO_BitSet(BSP_GPIO_DMOTO4_EN2_PORT,BSP_GPIO_DMOTO4_EN2);
      break;
  }
}

/********************************************************************************************************
** 函数名称: MOTO_DC_CLK
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
void MOTO_DC_CLK(INT8U ucSelected)
{
  switch(ucSelected){
    case 0:
      CSP_GPIO_BitToggle(BSP_GPIO_DMOTO1_EN1_PORT,BSP_GPIO_DMOTO1_EN1);
      break;
    case 1:
      CSP_GPIO_BitToggle(BSP_GPIO_DMOTO2_EN1_PORT,BSP_GPIO_DMOTO2_EN1);
      break;
    case 2:
      CSP_GPIO_BitToggle(BSP_GPIO_DMOTO3_EN1_PORT,BSP_GPIO_DMOTO3_EN1);
      break;
    case 3:
      CSP_GPIO_BitToggle(BSP_GPIO_DMOTO4_EN1_PORT,BSP_GPIO_DMOTO4_EN1);
      break;
  }
}

/********************************************************************************************************
** 函数名称: MOTO_STEP_FORWARD
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
void MOTO_STEP_FORWARD(INT8U ucSelected)
{
  switch(ucSelected){
    case 0:
      CSP_GPIO_BitSet(BSP_GPIO_SMOTO1_CC_PORT,BSP_GPIO_SMOTO1_CC);
      break;
    case 1:
      CSP_GPIO_BitSet(BSP_GPIO_SMOTO2_CC_PORT,BSP_GPIO_SMOTO2_CC);
      break;
  }
}

/********************************************************************************************************
** 函数名称: MOTO_STEP_BACKWARD
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
void MOTO_STEP_BACKWARD(INT8U ucSelected)
{
  switch(ucSelected){
    case 0:
      CSP_GPIO_BitClr(BSP_GPIO_SMOTO1_CC_PORT,BSP_GPIO_SMOTO1_CC);
      break;
    case 1:
      CSP_GPIO_BitClr(BSP_GPIO_SMOTO2_CC_PORT,BSP_GPIO_SMOTO2_CC);
      break;
  }
}

/********************************************************************************************************
** 函数名称: MOTO_STEP_ENABLED
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
void MOTO_STEP_ENABLED(INT8U ucSelected)
{
  switch(ucSelected){
    case 0:
      CSP_GPIO_BitClr(BSP_GPIO_SMOTO1_EN_PORT,BSP_GPIO_SMOTO1_EN);
      break;
    case 1:
      CSP_GPIO_BitClr(BSP_GPIO_SMOTO2_EN_PORT,BSP_GPIO_SMOTO2_EN);
      break;
  }
  SMOTO_ENABLED();
}

/********************************************************************************************************
** 函数名称: MOTO_STEP_DISABLED
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
void MOTO_STEP_DISABLED(INT8U ucSelected,INT8U ucMode)
{
  INT8U i;
  INT8U ucEnabled;

  CPU_SR_ALLOC();
  if(ucSelected>=CARDMACHINE_SMOTO_NUMS){
    return;
  }

  if(ucMode){
    g_usrSMoto[ucSelected].ucEnabled=0;
    ucEnabled=0;
    for(i=0;i<CARDMACHINE_SMOTO_NUMS;i++){
      if(g_usrSMoto[i].ucEnabled){
        ucEnabled=1;
        break;
      }
    }
    if(!ucEnabled){
      SMOTO_DISABLED();
    }		
  }else{
    OS_ENTER_CRITICAL();
    g_usrSMoto[ucSelected].ucEnabled=0;
    ucEnabled=0;
    for(i=0;i<CARDMACHINE_SMOTO_NUMS;i++){
      if(g_usrSMoto[i].ucEnabled){
        ucEnabled=1;
        break;
      }
    }
    if(!ucEnabled){
      SMOTO_DISABLED();
    }		
    OS_EXIT_CRITICAL();
  }
  switch(ucSelected){
  case 0:
    CSP_GPIO_BitSet(BSP_GPIO_SMOTO1_EN_PORT,BSP_GPIO_SMOTO1_EN);
    break;
  case 1:
    CSP_GPIO_BitSet(BSP_GPIO_SMOTO2_EN_PORT,BSP_GPIO_SMOTO2_EN);
    break;
  default:
    CSP_GPIO_BitSet(BSP_GPIO_SMOTO1_EN_PORT,BSP_GPIO_SMOTO1_EN);
    CSP_GPIO_BitSet(BSP_GPIO_SMOTO2_EN_PORT,BSP_GPIO_SMOTO2_EN);
    break;
  }
}

/********************************************************************************************************
** 函数名称: MOTO_STEP_CLK
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
void MOTO_STEP_CLK(INT8U ucSelected)
{
  switch(ucSelected){
    case 0:
      CSP_GPIO_BitToggle(BSP_GPIO_SMOTO1_CLK_PORT,BSP_GPIO_SMOTO1_CLK);
      break;
    case 1:
      CSP_GPIO_BitToggle(BSP_GPIO_SMOTO2_CLK_PORT,BSP_GPIO_SMOTO2_CLK);
      break;
  }
}

/********************************************************************************************************
** 函数名称: SMotoStart
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
void SMotoStart(INT8U ucFreq,INT16U uiCounts,INT8U ucDirection,INT8U ucSelected)
{
  CPU_SR_ALLOC();
    
  if(ucSelected>=CARDMACHINE_SMOTO_NUMS){
    return;
  }
  
  if(ucFreq<SMOTO_FREQ_600US){
    ucFreq=SMOTO_FREQ_600US;
  }

  MOTO_STEP_DISABLED(ucSelected,NORMAL_MODE);  
  OS_ENTER_CRITICAL();  
  g_usrSMoto[ucSelected].ucFreq=ucFreq;
  g_usrSMoto[ucSelected].uiCounts=uiCounts;
  g_usrSMoto[ucSelected].uiBakCounts=uiCounts;
  g_usrSMoto[ucSelected].ucDirection=ucDirection;
  g_usrSMoto[ucSelected].ucEnabled=1;
  g_usrSMoto[ucSelected].uiTime=(((INT32U)uiCounts)*ucFreq)/1000+2;

  if(!ucDirection){
    MOTO_STEP_FORWARD(ucSelected);      
  }else{
    MOTO_STEP_BACKWARD(ucSelected);
  }
  SMOTO_SET_TIME(ucFreq);
  MOTO_STEP_ENABLED(ucSelected);  	
  OS_EXIT_CRITICAL();      
}
			
/********************************************************************************************************
** 函数名称: DMotoStart
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
void DMotoStart(INT16U uiFreq,INT16U uiPwm,INT8U ucDirection,INT16U uiMotoTime,INT8U ucSelected)
{
  OS_ERR err;
  INT8U ucDirectionBak;
  CPU_SR_ALLOC();

  if(ucSelected>=CARDMACHINE_DMOTO_NUMS){
    return;
  }
  
  if(uiFreq<DMOTO_FREQ_DEFAULT){
    uiFreq=DMOTO_FREQ_DEFAULT;
  }
  
  if(uiPwm<DMOTO_PWM_700){
    uiPwm=DMOTO_PWM_700;
  }

  
  MOTO_DC_DISABLED(ucSelected,NORMAL_MODE);

  OS_ENTER_CRITICAL();  
  ucDirectionBak=g_usrDMoto[ucSelected].ucDirection;
  OS_EXIT_CRITICAL();  
  if(ucDirectionBak!=ucDirection){
   OSTimeDly(30,OS_OPT_TIME_DLY, &err) ;         
  }

  OS_ENTER_CRITICAL();  

  g_usrDMoto[ucSelected].uiFreq=uiFreq;
  g_usrDMoto[ucSelected].uiPwm=uiPwm;
  g_usrDMoto[ucSelected].ucDirection=ucDirection;
  g_usrDMoto[ucSelected].uiTime=uiMotoTime;

  PWM1TC=0;
  DMOTO_SET_TIME(uiFreq,uiPwm);	
  if(uiFreq!=uiPwm){
    DMOTO_ENABLED();
  }
  if(!ucDirection){
    MOTO_DC_FORWARD(ucSelected);
  }else{
    MOTO_DC_BACKWARD(ucSelected);
  }
  g_usrDMoto[ucSelected].ucEnabled=1;

  OS_EXIT_CRITICAL();
}

/********************************************************************************************************
** 函数名称: MotoTime
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
void MotoTime(void)
{
  INT8U i;
  
  for(i=0;i<CARDMACHINE_DMOTO_NUMS;i++){
    if(g_usrDMoto[i].uiTime>0){
      g_usrDMoto[i].uiTime--;
    }else{
      MOTO_DC_DISABLED(i,INTERRUPT_MODE);
    }
  }
  for(i=0;i<CARDMACHINE_SMOTO_NUMS;i++){
    if(g_usrSMoto[i].uiTime>0){
      g_usrSMoto[i].uiTime--;
    }else{
      MOTO_STEP_DISABLED(i,INTERRUPT_MODE);
    }
  }
}
               
               
/********************************************************************************************************
** 函数名称: Action_Process
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
void Action_Process(void)
{
  LIB_ERR               lib_err;
  OS_ERR                os_err;
  CPU_TS                ts;
  OS_MSG_SIZE           msgSize;
  
  CardMachineRxData     *pcommData;
  INT8U                 *pMsg;
  
  INT8U                 ucType;
  INT8U                 ucCmd;

  PowerOnSelftest();
    
  while(DEF_TRUE){
    ucType=DEV_TYPE();
    if(CARD_AUTO_MODE()){
      if(!m_usrGlobalFlag.usrBit.bKeyTest){
        if(ucType==LARGE_THICK_OUT_TYPE){
          LOutAutoEvent();
        }else if(ucType==SMALL_THICK_OUT_TYPE){
          SOutAutoEvent();
        }else if(ucType==SMALL_THICK_IN_TYPE){
          SInAutoEvent();
        }else if(ucType==SMALL_THICK_ZIN_TYPE){
          ZInAutoEvent();
        }else if(ucType==SMALL_THICK_GIN_TYPE){
          SGInAutoEvent();
        }
      }
      OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
    }else{
      BSP_OS_SemPost(g_pActionSem);
      pMsg = (INT8U *)OSTaskQPend(0, OS_OPT_PEND_BLOCKING, &msgSize, &ts, &os_err);
      if(pMsg){
        if(msgSize==1){
          ucCmd=*pMsg;
          if(ucCmd==POWER_ON_SELFTEST_MSG){
            ucCmd=DISPLAY_SELFTEST_MSG;
            Box_TaskLcdQPost(&App_TaskLcdTCB,&ucCmd,1);  
            PowerOnSelftest();
          }else if(ucCmd==MOTO_IN_TO_ANT_MSG){
            if(ucType==SMALL_THICK_IN_TYPE){
              InToAntProcess(NULL);
            }else{
              if(ZInToAntProcess(NULL)){
              #if PRINT_MOTO_EN==1                
                ZPrintOpenProcess(NULL,DOOR_CLOSE_MODE);
              #endif
              }
            }
          }
        }else if(msgSize==sizeof(CardMachineRxData)){
          ucType=DEV_TYPE();
          pcommData=(CardMachineRxData *)pMsg;
          switch(pcommData->ucCmd){
          case MOTO_IN_TO_ANT_MSG:
            if(ucType==SMALL_THICK_GIN_TYPE){
              GCardToAntProcess(pcommData);		
            }else if(ucType==SMALL_THICK_IN_TYPE){
              InToAntProcess(pcommData);
            }else if(ucType==SMALL_THICK_ZIN_TYPE){
              if(ZInToAntProcess(pcommData)){
              #if PRINT_MOTO_EN==1                
                ZPrintOpenProcess(pcommData,DOOR_CLOSE_MODE);
              #endif                
              }
            }
            break;
            
          case MOTO_ANT_TO_BOX_MSG:
            if(ucType==SMALL_THICK_GIN_TYPE){
              GAntToBoxProcess(pcommData);		
            }else if(ucType==SMALL_THICK_IN_TYPE){
              AntToBoxProcess(pcommData);
            }else if(ucType==SMALL_THICK_ZIN_TYPE){
              ZAntToBoxProcess(pcommData);
            }
            break;
            
          case MOTO_BOX_TO_ANT_MSG:
          case MOTO_BOX_TO_ANT_B_MSG:
            if(ucType==LARGE_THICK_OUT_TYPE){
              LBoxToAntProcess(pcommData,pcommData->ucData[0]-0x30);
            }else if(DEV_TYPE()==SMALL_THICK_IN_TYPE || DEV_TYPE()==SMALL_THICK_OUT_TYPE){
              BoxToAntProcess(pcommData);
            }
            break;
            
          case MOTO_ANT_TO_OUT_MSG:
            m_ucMachineAddr=m_usrComm1RxData.ucAddr;
          case MOTO_ANT_TO_OUT_B_MSG:
            if(ucType==LARGE_THICK_OUT_TYPE){
              LAntToOutProcess(pcommData);
            }else if(ucType==SMALL_THICK_GIN_TYPE){
              GAntToOutProcess(pcommData);
            }else if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_OUT_TYPE){
              AntToOutProcess(pcommData);
            }else if(ucType==SMALL_THICK_ZIN_TYPE){
              ZAntToOutProcess(pcommData);
            }
            break;
            
          case MOTO_ANT_TO_REV_MSG:
            if(ucType==LARGE_THICK_OUT_TYPE){
              LAntToRevProcess(pcommData);
            }
            break;
            
          case MOTO_DOOR_OPEN_MSG:
            if(ucType==SMALL_THICK_ZIN_TYPE){
              ZDoorOpenProcess(pcommData,DOOR_CLOSE_MODE);
            }
            break;
            
          case MOTO_PRINT_OPEN_MSG:
            if(ucType==SMALL_THICK_ZIN_TYPE){
              ZPrintOpenProcess(pcommData,DOOR_CLOSE_MODE);
            }
            break;
            
          /*case SCAN_OPEN_MSG:
            if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
              CloseScan();
              BSP_OS_TimeDlyMs(30);    
              OpenScan();
              Uart0Pack(INFTYPE_CMD_FINISHED,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
            }
            break;
            */
            
          }
        }
        Mem_PoolBlkFree(&m_BoxPool, pMsg, &lib_err);
        if (lib_err != LIB_MEM_ERR_NONE)  {
          //error
        }
      }
    }
  }
}

/********************************************************************************************************
** 函数名称: PowerOnSelftest
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
void PowerOnSelftest(void)
{
  INT32U ulTmp;
  INT8U ucTmp;
  
  INT16U uiDMotoPwm;	
  INT16U uiDMotoTime;
  INT8U ucDSelected;
  
  INT8U ucSwitchErr=0;
  INT8U ucDMotoErr=0;
  INT8U ucDMotoErr1=0;
  
  INT8U ucRet;
  
  ucTmp=DISPLAY_SELFTEST_MSG;
  Box_TaskLcdQPost(&App_TaskLcdTCB,&ucTmp,1);    
  
  INT8U ucType=DEV_TYPE();
  if(ucType==SMALL_THICK_IN_TYPE){
  }else if(ucType==SMALL_THICK_OUT_TYPE){
  }else if(ucType==SMALL_THICK_GIN_TYPE){
    SMotoMoveWait(1500,MOTO_BACKWARD_MODE,SMOTO_FIRST);									
    ulTmp=GetKey();    
    ucTmp=((ulTmp>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01) | (((ulTmp>>m_ucKeyBit[CARD_POSC_BIT]) & 0x03)<<1);
    if(ucTmp){
      ucSwitchErr=1;
    }
    DMotoMoveWait(35,MOTO_BACKWARD_MODE,DMOTO_FIRST);	
    DMotoMoveWait(35,MOTO_FORWARD_MODE,DMOTO_FIRST);	
    
    uiDMotoPwm=m_uiDMotoPwm[DMOTO_SECOND];	
    uiDMotoTime=((INT32U)DMOTO_FREQ_DEFAULT)*DMOTO_TIME_SK_DEFAULT/uiDMotoPwm;
    ucDSelected=m_ucDMotoBit[DMOTO_SECOND];
    
    if(!DMotoPosAValid(DMOTO_SECOND)){
      if(!MotoReset(WAIT_MODE,DMOTO_SECOND)){
        ucDMotoErr=1;
      }
    }
    if(!ucDMotoErr){
      DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_FORWARD_MODE,uiDMotoTime,ucDSelected);
      ucRet=DMotoPosBWaitEnter(uiDMotoTime+5,DMOTO_SECOND);			
      MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
      if(ucRet){
        if(!MotoReset(WAIT_MODE,DMOTO_SECOND)){
          ucDMotoErr=1;
        }				
      }else{
        ucDMotoErr=1;
      }
    }
    if(ucSwitchErr && ucDMotoErr){
      m_usrErrorFlags.usrBit.bSelfTest=3;
    }else if(ucSwitchErr){
      m_usrErrorFlags.usrBit.bSelfTest=1;			
    }else if(ucDMotoErr){
      m_usrErrorFlags.usrBit.bSelfTest=2;			
    }
  }else if(ucType==SMALL_THICK_ZIN_TYPE){
    SMotoMoveWait(1500,MOTO_BACKWARD_MODE,SMOTO_FIRST);									
    ulTmp=GetKey();    
    ucTmp=((ulTmp>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01) | (((ulTmp>>m_ucKeyBit[CARD_POSC_BIT]) & 0x03)<<1);
    if(ucTmp){
      ucSwitchErr=1;
    }
    
#if DOOR_OPEN_EN==1
    uiDMotoPwm=m_uiDMotoPwm[DMOTO_SECOND];	                                                //掉卡
    uiDMotoTime=((INT32U)DMOTO_FREQ_DEFAULT)*DMOTO_TIME_SK_DEFAULT/uiDMotoPwm;
    ucDSelected=m_ucDMotoBit[DMOTO_SECOND];
    
    if(DMotoPosBValid(DMOTO_SECOND) && !DMotoPosAValid(DMOTO_SECOND)){
      if(!MotoReset(WAIT_MODE,DMOTO_SECOND)){
        ucDMotoErr=1;
      }
    }
    if(!ucDMotoErr){
      DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_FORWARD_MODE,uiDMotoTime,ucDSelected);
      ucRet=DMotoPosBWaitEnter(uiDMotoTime+5,DMOTO_SECOND);			
      MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
      
      BSP_OS_TimeDlyMs(1000);    
      if(ucRet){
        if(!MotoReset(WAIT_MODE,DMOTO_SECOND)){
          ucDMotoErr=1;
        }				
      }else{
        ucDMotoErr=1;
      }
    }
#endif

#if PAPER_RECYCLE_EN==1
    SMotoReset(WAIT_MODE,SMOTO_SECOND);
#else    
    uiDMotoPwm=m_uiDMotoPwm[DMOTO_FIRST];	                                                //打印机
    uiDMotoTime=((INT32U)DMOTO_FREQ_DEFAULT)*DMOTO_TIME_SK_DEFAULT/uiDMotoPwm;
    ucDSelected=m_ucDMotoBit[DMOTO_FIRST];
    
    if(DMotoPosAValid(DMOTO_FIRST)){
      DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_FORWARD_MODE,uiDMotoTime,ucDSelected);
      ucRet=DMotoPosAWaitEnter(uiDMotoTime+5,DMOTO_SECOND);			
      MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
    }else{
      if(!MotoReset(WAIT_MODE,DMOTO_FIRST)){
        ucDMotoErr1=1;
      }
    }
#endif    
    
    if(ucSwitchErr && ucDMotoErr && ucDMotoErr1){
      m_usrErrorFlags.usrBit.bSelfTest=3;
    }else if(ucSwitchErr){
      m_usrErrorFlags.usrBit.bSelfTest=1;			
    }else if(ucDMotoErr){
      m_usrErrorFlags.usrBit.bSelfTest=2;			
    }
    g_ucLedMode=LEDOUT_ON_MODE;
    
  }else if(DEV_TYPE()==LARGE_THICK_OUT_TYPE){
  }	
  ucTmp=DISPLAY_MAIN_MSG;
  Box_TaskLcdQPost(&App_TaskLcdTCB,&ucTmp,1);  
}
               

/********************************************************************************************************
** 函数名称: SMotoMoveWait
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
INT8U SMotoMoveWait(INT16U uiCounts,INT8U ucDirection,INT8U ucSelected)
{  
  OS_ERR os_err;
  
  INT8U ucRet;
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSelected];
  INT8U ucSSelected=m_ucSMotoBit[ucSelected];
  INT16U uiTimes;
  
  CPU_SR_ALLOC();
  
  SMotoStart(ucSMotoFreq,uiCounts,ucDirection,ucSSelected);
  OS_ENTER_CRITICAL();
  uiTimes=g_usrSMoto[ucSSelected].uiTime;
  OS_EXIT_CRITICAL();
  
  ucRet=0;
  while(!ucRet){
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
    OS_ENTER_CRITICAL();
    if(!g_usrSMoto[ucSSelected].uiCounts){
      ucRet=1;
    }
    OS_EXIT_CRITICAL();
    if(uiTimes>0){
      uiTimes--;
    }else{
      ucRet=2;                                                                      //系统故障
    }
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  if(ucRet==1){
    return TRUE;
  }
  return FALSE;
}

/********************************************************************************************************
** 函数名称: DMotoMoveWait
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
void DMotoMoveWait(INT16U uiTime,INT8U ucDirection,INT8U ucSelected)
{
  OS_ERR os_err;
  INT8U ucDSelected=m_ucDMotoBit[ucSelected];

  DMotoStart(DMOTO_FREQ_DEFAULT,m_uiDMotoPwm[ucDSelected],ucDirection,uiTime,ucDSelected);
  OSTimeDly(uiTime*10,OS_OPT_TIME_DLY, &os_err) ;         
  MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);	
}


/********************************************************************************************************
** 函数名称: DMotoPosAValid
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
INT8U DMotoPosAValid(INT8U ucSelected)
{
  INT8U ucTmp;
  INT8U ucPos;
  INT32U ulTmp;

  
  if(ucSelected>=CARDMACHINE_DMOTO_NUMS){
    return FALSE;
  }

  ucPos=DMotoPosBySelected(ucSelected);	
  ucPos=DMotoByPos(ucPos);
  ucTmp=m_ucKeyBit[DMOTO1_POSA_BIT+ucPos*8];
  ulTmp=GetKeyOutput();  
  
  if(CheckBit(ulTmp,ucTmp)){
    return TRUE;
  }else{
    return FALSE;
  }
}

/********************************************************************************************************
** 函数名称: DMotoPosBValid
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
INT8U DMotoPosBValid(INT8U ucSelected)
{
  INT8U ucTmp;
  INT8U ucPos;
  INT32U ulTmp;

  
  if(ucSelected>=CARDMACHINE_DMOTO_NUMS){
    return FALSE;
  }

  ucPos=DMotoPosBySelected(ucSelected);	
  ucPos=DMotoByPos(ucPos);
  ucTmp=m_ucKeyBit[DMOTO1_POSB_BIT+ucPos*8];
  ulTmp=GetKeyOutput();  
  
  if(CheckBit(ulTmp,ucTmp)){
    return TRUE;
  }else{
    return FALSE;
  }
}

/********************************************************************************************************
** 函数名称: DMotoPosAWaitEnter
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
INT8U DMotoPosAWaitEnter(INT16U uiWaitTime,INT8U ucSelected)
{
  OS_ERR os_err;
  INT16U uiTimes=uiWaitTime;
  
  while(!DMotoPosAValid(ucSelected)){
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err);
    if(uiTimes>0){
      uiTimes--;
    }else{
      return FALSE;
    }
  }
  return TRUE;
}

/********************************************************************************************************
** 函数名称: DMotoPosBWaitEnter
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
INT8U DMotoPosBWaitEnter(INT16U uiWaitTime,INT8U ucSelected)
{
  OS_ERR os_err;
  INT16U uiTimes=uiWaitTime;
  
  while(!DMotoPosBValid(ucSelected)){
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err);
    if(uiTimes>0){
      uiTimes--;
    }else{
      return FALSE;
    }
  }
  return TRUE;
}

/********************************************************************************************************
** 函数名称: SMotoReset
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
INT8U SMotoReset(INT8U ucMode,INT8U ucSelected)
{
  INT8U ucRet;
  INT8U ucSSelected=m_ucSMotoBit[ucSelected];
  INT8U ucRetrys=0;

  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];

  if(DMotoPosAValid(ucSelected)){
    return TRUE;
  }
  
  /*
  if(!ucMode){
    SMotoStart(ucSMotoFreq,SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT,MOTO_BACKWARD_MODE,ucSSelected);    
    return TRUE;
  }*/
  
  while(ucRetrys++<MOTO_RETRYS){
    SMotoStart(ucSMotoFreq,SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT,MOTO_BACKWARD_MODE,ucSSelected);    
    ucRet=DMotoPosAWaitEnter(SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT-10,0);//ucSelected);
    MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
    if(ucRet){
      return TRUE;
    }
  }
  return FALSE;
}

/********************************************************************************************************
** 函数名称: MotoReset
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
INT8U MotoReset(INT8U ucMode,INT8U ucSelected)
{
  INT8U ucRet;
  INT16U uiDMotoPwm;
  INT8U ucDSelected=m_ucDMotoBit[ucSelected];
  INT8U ucRetrys=0;

  uiDMotoPwm=m_uiDMotoPwm[ucDSelected];

  if(DMotoPosAValid(ucSelected)){
    return TRUE;
  }

  if(!ucMode){
    DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_BACKWARD_MODE,DMOTO_TIME_SK_DEFAULT,ucDSelected);
    return TRUE;
  }
  
  while(ucRetrys++<MOTO_RETRYS){
    DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_BACKWARD_MODE,DMOTO_TIME_SK_DEFAULT,ucDSelected);
    ucRet=DMotoPosAWaitEnter(DMOTO_TIME_SK_DEFAULT-10,ucSelected);
    MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
    if(ucRet){
      return TRUE;
    }
  }
  return FALSE;
}


/********************************************************************************************************
** 函数名称: DMotoSwitchStop
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
void DMotoSwitchStop(void)
{
  INT8U i;
  
  INT8U ucDMotoPosABit;
  INT8U ucDMotoPosBBit;
  INT8U ucCardPosBit;
  
  INT8U ucSelected;
  
  INT8U ucABit[3];
  INT8U ucBBit[3];
  
  static INT32U ulKeyOutput1=0; 
  
  INT8U ucType=DEV_TYPE();
  
  g_usrGetKey1.ulKeyInput=GetKey();
  KeyDeBounce1();

  if(ulKeyOutput1==g_usrGetKey1.ulKeyOutput){
    return;
  }
  
  ucABit[0]=m_ucKeyBit[DMOTO1_POSA_BIT];
  ucABit[1]=m_ucKeyBit[DMOTO2_POSA_BIT];
  ucABit[2]=m_ucKeyBit[DMOTO3_POSA_BIT];
  
  ucBBit[0]=m_ucKeyBit[DMOTO1_POSB_BIT];
  ucBBit[1]=m_ucKeyBit[DMOTO2_POSB_BIT];
  ucBBit[2]=m_ucKeyBit[DMOTO3_POSB_BIT];

  for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
    ucDMotoPosABit=ucABit[i];
    if(CheckBit(g_usrGetKey1.ulKeyOutput,ucDMotoPosABit) && !CheckBit(ulKeyOutput1,ucDMotoPosABit)){
      ucSelected=DMotoByPos(i);
      MOTO_DC_DISABLED(ucSelected,INTERRUPT_MODE);
    }
    ucDMotoPosBBit=ucBBit[i];
    if(CheckBit(g_usrGetKey1.ulKeyOutput,ucDMotoPosBBit) && !CheckBit(ulKeyOutput1,ucDMotoPosBBit)){
      ucSelected=DMotoByPos(i);
      MOTO_DC_DISABLED(ucSelected,INTERRUPT_MODE);
    }
    
    ucCardPosBit=m_ucKeyBit[CARDBOX1_POS_BIT+i*8];
    if(!CheckBit(g_usrGetKey1.ulKeyOutput,ucCardPosBit)){
      m_usrBoxInfo[i].usrFlag.usrBit.bSelftest=0;													//?è?úμ20,è?oó?′?úμ21,×??ì1y3ìíê3é
    }
  }
  ulKeyOutput1=g_usrGetKey1.ulKeyOutput;
}

/*******************************************************************************************************
** oˉêy??3?: GCardToAnt
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?: 
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U GCardToAnt(INT8U ucRetrys)
{
  OS_ERR os_err;
  
  INT16U uiTimes;
  INT16U uiDelays;
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucTmp;
  INT8U ucDSelected=m_ucDMotoBit[DMOTO_FIRST];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
          
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
  INT16U uiDMotoPwm=m_uiDMotoPwm[ucDSelected];
  
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  
  CPU_SR_ALLOC();
  if(ucRetrys==1){        
    ulTmp=GetKeyOutput();    
    ucTmp=((ulTmp>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01) | (((ulTmp>>m_ucKeyBit[CARD_POSC_BIT]) & 0x03)<<1) ;
    if(ucTmp){
      if(SMotoMoveWait(SMOTO_COUNT_GK_CLEAR_DEFAULT,MOTO_BACKWARD_MODE,SMOTO_FIRST)){
        ucRet=3;
      }else{
        ucRet=4;
      }
      if(ValidBit(ulTmp,ucCardPosDBit) && NoValidBit(ulTmp,ucCardPosCBit)){
        ucRet=5;
      }
      return ucRet;
    }
  }

  uiDelays=MOTO_INTERFER_TIME_DEFAULT/ACTION_DELAY_TIME_DEFAULT;
  uiTimes=(((INT32U)SMOTO_COUNT_GK_INTOANT_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+20/ACTION_DELAY_TIME_DEFAULT;
  
  DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_BACKWARD_MODE,DMOTO_TIME_GK_DEFAULT,ucDSelected);
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_GK_INTOANT_DEFAULT,MOTO_FORWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    OSTimeDly(ACTION_DELAY_TIME_DEFAULT,OS_OPT_TIME_DLY, &os_err);         
    if(uiDelays>0){
      uiDelays--;
    }else{
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucCardPosABit)){
        ucRet=1;
      }
      /*if(CheckBit(ulTmp,ucCardPosCBit)){
        ucRet=2;
      }*/

      OS_ENTER_CRITICAL();
      if(!g_usrSMoto[ucSSelected].uiCounts){
        ucRet=3;
      }
      OS_EXIT_CRITICAL();
      if(uiTimes>0){
        uiTimes--;
      }else{
        ucRet=4;                                                                      //系统故障
      }
    }
  }
  MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);

#if MOTO_INTERFER_TIME_EN==1
  OSTimeDly(MOTO_INTERFER_TIME_DEFAULT,OS_OPT_TIME_DLY, &os_err) ;         
#endif	
  ulTmp=GetKey();    
  if(CheckBit(ulTmp,m_ucKeyBit[CARD_POSA_BIT])){
    ucRet=1;
  }    
  
  DMotoMoveWait(400,MOTO_FORWARD_MODE,DMOTO_FIRST);
  
  return ucRet;
}

/*******************************************************************************************************
** oˉêy??3?: GCardToAntProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U GCardToAntProcess(CardMachineRxData *pcommRx1Data)
{
  INT8U ucRetrys=0;
  INT8U ucData[32];
  INT8U ucMode;
  INT8U ucRet;
	
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
	
  ucRetrys=0;
  while(++ucRetrys<=MOTO_RETRYS){
    ucRet=GCardToAnt(ucRetrys);
    if(ucRet==1){
      break;
    }else if(ucRet==4 || ucRet==5){
      ucRetrys=100;
      break;
    }
  }
  
  if(ucRetrys>MOTO_RETRYS){
    ucData[0]=SUBTYPE_ERR_BOX2ANT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }else{
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
  }
  return TRUE;
}
               
/*******************************************************************************************************
** oˉêy??3?: GAntToBox
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U GAntToBox(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucEnterC=0;
  INT8U ucLeaveC=0;	
  INT8U ucDSelected=m_ucDMotoBit[DMOTO_SECOND];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
  
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
  INT16U uiDMotoPwm=m_uiDMotoPwm[ucDSelected];	
  INT16U uiDMotoTime=((INT32U)DMOTO_FREQ_DEFAULT)*DMOTO_TIME_SK_DEFAULT/uiDMotoPwm;
          
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucDMoto1PosBBit=m_ucKeyBit[DMOTO1_POSB_BIT];

  INT16U uiTimes;
  INT8U uiDelays;
  
  CPU_SR_ALLOC();
	
  uiTimes=(((INT32U)SMOTO_COUNT_GK_ANTTOBOX_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+20/ACTION_DELAY_TIME_DEFAULT;
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_GK_ANTTOBOX_DEFAULT,MOTO_FORWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosCBit) && !ucEnterC){
      //??è??ú2??a1?????
      ucEnterC=1;
    }    
		
    if(!CheckBit(ulTmp,ucCardPosCBit) && ucEnterC){
      //à??a?ú2??a1?????
      //MOTO_STEP_DISABLED();
      ucLeaveC=1;
    }    
		
    OS_ENTER_CRITICAL();
    if(!g_usrSMoto[ucSSelected].uiCounts){
      if(ucLeaveC){
        ucRet=1;
      }else{
        ucRet=2;
      }
    }
    OS_EXIT_CRITICAL();
    
    if(uiTimes>0){
      uiTimes--;
    }else{
      ucRet=4;                                                                  //系统故障
    }	
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
	
  ulTmp=GetKey();
  if(CheckBit(ulTmp,ucCardPosCBit) || CheckBit(ulTmp,ucCardPosABit)){								//óD?¨￡?′ò??￡?·μ????ê?
    return 0;
  }
  
  uiDelays=MOTO_INTERFER_TIME_DEFAULT/ACTION_DELAY_TIME_DEFAULT;
  uiTimes=uiDMotoTime*(10/ACTION_DELAY_TIME_DEFAULT)+20/ACTION_DELAY_TIME_DEFAULT;
  DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_FORWARD_MODE,uiDMotoTime,ucDSelected);
  ucRet=0;
  while(!ucRet){
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err);
    if(uiTimes>0){
      uiTimes--;
    }
    if(uiDelays>0){
      uiDelays--;
    }else{
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucDMoto1PosBBit)){
        OSTimeDly(20,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
        ucRet=1;
      }
      if(!uiTimes){
        ucRet=2;
      }
    }
  }
  MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
#if MOTO_INTERFER_TIME_EN==1
  OSTimeDly(MOTO_INTERFER_TIME_DEFAULT/10,OS_OPT_TIME_DLY, &os_err) ;         
#endif
  
  ucRet=0;
  ulTmp=GetKeyOutput();    	
  DebugInfoA(0x66,(INT8U *)&ulTmp,4);
  if(!(CheckBit(ulTmp,ucCardPosCBit) || CheckBit(ulTmp,ucCardPosDBit))){//?T?¨
    DebugInfoA(0x77,(INT8U *)&ulTmp,4);
    ucRet=1;
            
    if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited){
      m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited=1;
      
      //???ó?¨êy
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ulMachineId=m_usrBoxInfo[BOX_FIRST].ulMachineId;
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucCurrentCount=m_usrBoxInfo[BOX_FIRST].ucCounts;
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucNewCount=m_usrBoxInfo[BOX_FIRST].ucCounts+1;
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucRetrys=8;
      CardCountUpdateSend(0,BOX_FIRST);
    #if MOTO_INTERFER_TIME_EN==1
      OSTimeDly(BOX_COUNT_WRITE_TIME/10,OS_OPT_TIME_DLY, &os_err) ;         
    #endif			
    }
  }
  
  MotoReset(WAIT_MODE,DMOTO_SECOND);
  
  return ucRet; 	
}

/*******************************************************************************************************
** oˉêy??3?: GAntToBoxProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U GAntToBoxProcess(CardMachineRxData *pcommRx1Data)
{
  OS_ERR os_err;
  
  INT8U ucRetrys=0;
  INT8U ucData[32];
  INT8U ucMode;
  INT32U ulTmp;
  INT8U ucTmp;

  INT8U ucBoxLoad1Bit=m_ucKeyBit[BOXLOAD1_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
  INT8U ucSMotoFreq=m_ucSMotoFreq[SMOTO_FIRST];
  
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }

  if(!MotoReset(WAIT_MODE,DMOTO_SECOND)){
    ucData[0]=SUBTYPE_ERR_HEAD1STATUSERR;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return 1;
  }

  ulTmp=GetKeyOutput();
  if(!CheckBit(ulTmp,ucBoxLoad1Bit)){
    ucData[0]=SUBTYPE_ERR_CARDBOX_UNLOAD;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return 1;
  }

  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
    ucData[0]=SUBTYPE_ERR_BOX_NOCONNECT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return 1;
  }

  if(m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucEnabled){
    ucData[0]=SUBTYPE_ERR_DEVICE_BUSY;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return 2;
  }

  if(m_usrBoxInfo[BOX_FIRST].ucCounts>=m_usrBoxInfo[BOX_FIRST].ucMaxCounts){
    ucData[0]=SUBTYPE_ERR_CARDCOUNT_OVER;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return 1;
  }

  ucTmp=((ulTmp>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01) | (((ulTmp>>m_ucKeyBit[CARD_POSC_BIT]) & 0x03)<<1) ;
  if(ucTmp==0){
    ucData[0]=SUBTYPE_ERR_NOCARD_ONANT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return 2;
  /*}else if(ucTmp!=1){
    ucData[0]=SUBTYPE_ERR_CARD_POSITION;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
  return 1;*/
  }

  m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited=0;
  ucRetrys=0;
  while(++ucRetrys<=MOTO_RETRYS){
    if(GAntToBox()){
      ulTmp=GetKeyOutput();    
      DebugInfoA(0x88,(INT8U *)&ulTmp,4);
      if((CheckBit(ulTmp,ucCardPosCBit) || CheckBit(ulTmp,ucCardPosDBit))){
        DebugInfoA(0x99,(INT8U *)&ulTmp,4);
        while(1){
          BSP_LED_Toggle(2);
          OSTimeDly(100,OS_OPT_TIME_DLY, &os_err) ;         
          ulTmp=GetKeyOutput();    
          DebugInfoA(0xAA,(INT8U *)&ulTmp,4);
        }
      }else{
        break;
      }
    }
    
    BoxMotoMoveDown(BOXMOTO_FREQUENCE_PER_CARD*5,BOX_FIRST);		
    SMotoStart(ucSMotoFreq,20,MOTO_BACKWARD_MODE,ucSSelected);
    OSTimeDly(200,OS_OPT_TIME_DLY, &os_err) ;         
    MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  }
    
  if(ucRetrys<=MOTO_RETRYS){
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCardPos=0;
    if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bBuzzEn){
      if(m_usrBoxInfo[BOX_FIRST].ucBuzzMode>3){
        m_usrBoxInfo[BOX_FIRST].ucBuzzMode=0;
      }
      BuzzSet(2,BUZZ_SK_MODE[m_usrBoxInfo[BOX_FIRST].ucBuzzMode],BUZZ_SK_MODE[m_usrBoxInfo[BOX_FIRST].ucBuzzMode],0);
    }
    return 0;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2BOX_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
  }
  return 1;
}

/*******************************************************************************************************
** oˉêy??3?: GAntToOut
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U GAntToOut(void)
{
  OS_ERR os_err;
	
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucLeaveA=0;	
  INT8U ucSSelected=SMOTO_FIRST;
  
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
  
  INT8U ucTimes=100;
  
  CPU_SR_ALLOC();
  
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_GK_ANTTOOUT_DEFAULT,MOTO_BACKWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(!CheckBit(ulTmp,ucCardPosABit)){
      //à??a?ú2??a1?????
      ucLeaveA=1;
    }    
		
    OS_ENTER_CRITICAL();
    if(!g_usrSMoto[ucSSelected].uiCounts){
      if(ucLeaveA){
        ucRet=1;
      }else{      
        ucRet=2;
      }
    }
    OS_EXIT_CRITICAL();
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;                                                                  //系统故障
    }
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
	
  if(ucRet>=2){
    ulTmp=GetKey();    
    if(!CheckBit(ulTmp,ucCardPosABit)){
      return TRUE;
    }
      return FALSE;
    }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: GAntToOutProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U GAntToOutProcess(CardMachineRxData *pcommRx1Data)
{
  INT8U ucRetrys=0;
  INT8U ucData[16];
	INT8U ucMode;
	
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(AntToOut()){
      break;
    }
  }
  
  KeyChange();
  if(ucRetrys<=MOTO_RETRYS){
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2EXIT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }  
}

/*******************************************************************************************************
** oˉêy??3?: BoxToAnt
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U BoxToAnt(void)
{
  OS_ERR os_err;
  
  INT8U ucDMotoPosA;
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucEnterA=0;
  INT8U ucEnterC=0;
  INT8U ucLeaveC=0;
  INT8U ucDSelected=m_ucDMotoBit[DMOTO_FIRST];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
          
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
  INT16U uiDMotoPwm=m_uiDMotoPwm[ucDSelected];
  
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  
  INT8U ucTimes;
  INT8U ucDelays;
  INT8U ucDelay1s;
  
  ucDelays=MOTO_INTERFER_TIME_DEFAULT/10;
  ucDelay1s=MOTO_INTERFER_TIME_DEFAULT/10;
  ucTimes=(((INT32U)SMOTO_COUNT_GK_ANTTOBOX_DEFAULT)*ucSMotoFreq)/1000+10;
  
  CPU_SR_ALLOC();
  
  DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_BACKWARD_MODE,DMOTO_TIME_DEFAULT,ucDSelected);
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_DEFAULT,MOTO_BACKWARD_MODE,ucSSelected);
  
  ucDMotoPosA=0;
  ucRet=0;
  while(!ucRet){
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
    if(ucTimes>0){
      ucTimes--;
    }
    if(ucDelays>0){
      ucDelays--;
    }else{
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucCardPosABit)){
        MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
        if(!ucDMotoPosA){
          ucDMotoPosA=1;
        }
      }
      
      if(!ucDelay1s){
        if(CheckBit(ulTmp,ucCardPosCBit)){
          //ò?μ??ú2??a1?????
          ucEnterC=1;
        }        
        
        if(CheckBit(ulTmp,ucCardPosABit)){
          //ò?μ?ía2??a1?????
          MOTO_STEP_DISABLED(SMOTO_FIRST,NORMAL_MODE);
          ucEnterA=1;
        }    
        
        //ía2??a1?1ê??ê±,ó??ú2??a1?DT?y
        if(!CheckBit(ulTmp,ucCardPosCBit) && ucEnterC){
          //à??a?ú2??a1?????
          MOTO_STEP_DISABLED(SMOTO_FIRST,NORMAL_MODE);
          ucLeaveC=1;
        }  
      }else{
        ucDelay1s--;
      }

      OS_ENTER_CRITICAL();
      if(ucEnterA  || ucLeaveC){
        ucRet=1;			
      }else if(!g_usrSMoto[ucSSelected].uiCounts){
        ucRet=2;
      }
      OS_EXIT_CRITICAL();
    }
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
                                  
  if(!ucDMotoPosA){
    ucDMotoPosA=DMotoPosAWaitEnter(100,ucDSelected);
  }
  MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
  OSTimeDly(MOTO_INTERFER_TIME_DEFAULT/10,OS_OPT_TIME_DLY, &os_err) ;         

  if(ucRet>=2){
    //ulTmp=GetKeyOutput();    
    //if(!CheckBit(ulTmp,ucCardPosABit) && !CheckBit(ulTmp,ucCardCBit)){
    return FALSE;
    //}    
  }  

  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited){
    m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited=1;
    //μ??ú???μ
    CardBoxBasicInfoSend(0x80,BOX_FIRST);
    
    //??éù?¨êy
    m_usrBoxInfo[BOX_FIRST].usrCountResponse.ulMachineId=m_usrBoxInfo[BOX_FIRST].ulMachineId;
    m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucCurrentCount=m_usrBoxInfo[BOX_FIRST].ucCounts;
    m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucNewCount=m_usrBoxInfo[BOX_FIRST].ucCounts-1;
    m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucRetrys=8;
    CardCountUpdateSend(0,BOX_FIRST);
    OSTimeDly(BOX_COUNT_WRITE_TIME/10,OS_OPT_TIME_DLY, &os_err) ;         
  }

  /*if(ucEnterA){
  MotoStepCounts(20,MOTO_FORWARD_MODE);
  }else if(ucLeaveC){
  MotoStepCounts(60,MOTO_FORWARD_MODE);
  }*/

  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: BoxToAntProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U BoxToAntProcess(CardMachineRxData *pcommRx1Data)
{
  OS_ERR os_err;
  INT8U ucRetrys=0;
  INT8U ucData[32];
  INT8U ucMode;
  INT32U ulTmp;
  INT8U ucRet;
  
  INT8U ucBoxLoad1Bit=m_ucKeyBit[BOXLOAD1_BIT];
  
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  ucRetrys=0;
  ucRet=0;
  while(++ucRetrys<=MOTO_RETRYS){
    ucRet=BoxToAntPreProcess();
    if(!ucRet){
      OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
      break;
    }else if(ucRet==1){
      ucData[0]=SUBTYPE_ERR_CARD_ONANT;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
      ucData[0]=DISPLAY_INFO_MSG;
      ucData[1]=DISPLAY_INFO_ONANT_HAVING_CARD_CMD;
      Box_TaskLcdQPost(&App_TaskLcdTCB,ucData,2);  
      return FALSE;
    }else if(ucRet==3){
      ucData[0]=SUBTYPE_ERR_CARD_ONEXIT;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
      ucData[0]=DISPLAY_INFO_MSG;
      ucData[1]=DISPLAY_INFO_ONEXIT_HAVING_CARD_CMD;
      Box_TaskLcdQPost(&App_TaskLcdTCB,ucData,2);  
      return FALSE;
    }else if(ucRet==4){
      ucData[0]=SUBTYPE_ERR_BOX2ANT_FAIL;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
      ucData[0]=DISPLAY_INFO_MSG;
      ucData[1]=DISPLAY_INFO_ONANTEXIT_HAVING_CARD_CMD;
      Box_TaskLcdQPost(&App_TaskLcdTCB,ucData,2);  
      return FALSE;
    }
  }	
  if(ucRetrys>MOTO_RETRYS){
    ucData[0]=SUBTYPE_ERR_BOX2ANT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }		
  
  ulTmp=GetKeyOutput();
  if(!CheckBit(ulTmp,ucBoxLoad1Bit)){
    ucData[0]=SUBTYPE_ERR_CARDBOX_UNLOAD;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
          
  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
    ucData[0]=SUBTYPE_ERR_BOX_NOCONNECT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  if(m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucEnabled){
    ucData[0]=SUBTYPE_ERR_DEVICE_BUSY;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  if(!m_usrBoxInfo[BOX_FIRST].ucCounts){
    ucData[0]=SUBTYPE_ERR_CARDCOUNT_ZERO;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited=0;
  ucRetrys=0;
  while(++ucRetrys<=MOTO_RETRYS){
    ulTmp=GetKeyOutput();
    if(!CheckBit(ulTmp,ucBoxLoad1Bit)){
      ucData[0]=SUBTYPE_ERR_CARDBOX_UNLOAD;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
      return FALSE;
    }
    if(BoxToAnt()){
      break;
    }
  }
  
  if(ucRetrys>MOTO_RETRYS){
    ucData[0]=SUBTYPE_ERR_BOX2ANT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }else{
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: AntToOut
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U AntToOut(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucTmp;
  INT8U ucLeaveC=0;	
  INT16U uiSteps=160;
  INT8U ucSSelected=SMOTO_FIRST;
  
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
  INT8U ucTimes;
  
  CPU_SR_ALLOC();
  
  if(EepromReadVerifyBytes(AUTOOUT_MODE_ADDR,&ucTmp,1)){
    if(!ucTmp){
      uiSteps=500;
    }
  }
  
  ucTimes=(((INT32U)uiSteps)*ucSMotoFreq)/1000+2;
  SMotoStart(ucSMotoFreq,uiSteps,MOTO_BACKWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(!CheckBit(ulTmp,ucCardPosCBit)){
      //à??a?ú2??a1?????
      ucLeaveC=1;
    }    
    OS_ENTER_CRITICAL();
    if(!g_usrSMoto[ucSSelected].uiCounts){
      if(ucLeaveC){
        ucRet=1;
      }else{      
        ucRet=2;
      }
    }
    OS_EXIT_CRITICAL();
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;
    }
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
	
  if(ucRet>=2){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosABit) && !CheckBit(ulTmp,ucCardPosCBit)){
      return TRUE;
    }
    return FALSE;
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: AntToOutProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U AntToOutProcess(CardMachineRxData *pcommRx1Data)
{
  INT8U ucRetrys=0;
  INT8U ucData[16];
  INT8U ucMode;
  INT32U ulTmp;
  
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  ulTmp=GetKeyOutput();
  if(!AntToOutPreProcess(ulTmp)){
    ucData[0]=SUBTYPE_ERR_NOCARD_ONANT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(AntToOut()){
      break;
    }
  }
  
  if(ucRetrys<=MOTO_RETRYS){
    //???ˉ?¨ê±?′°?3?±¨?ˉ  
    //TakeoutOvertimeRead();    
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2EXIT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }  
}

/*******************************************************************************************************
** oˉêy??3?: InToAnt
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U InToAnt(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucLeaveC=0;
  INT8U ucEnterC=0;
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
          
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  
  INT8U ucTimes;
  
  CPU_SR_ALLOC();
  
  ulTmp=GetKeyOutput();    
  if(CheckBit(ulTmp,ucCardPosCBit)){
    //反转
    ucTimes=(((INT32U)SMOTO_COUNT_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+10/ACTION_DELAY_TIME_DEFAULT;
    SMotoStart(ucSMotoFreq,SMOTO_COUNT_DEFAULT,MOTO_FORWARD_MODE,ucSSelected);
    ucRet=0;
    while(!ucRet){
      ulTmp=GetKeyOutput();    
      if(!CheckBit(ulTmp,ucCardPosCBit)){
        //离开
        OSTimeDly(20,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
        ucLeaveC=1;
      }
      
      
      OS_ENTER_CRITICAL();
      if(ucLeaveC){
        ucRet=1;
      }else if(!g_usrSMoto[ucSSelected].uiCounts){
        ucRet=2;
      }
      OS_EXIT_CRITICAL();
      
      if(ucTimes>0){
        ucTimes--;
      }else{
        ucRet=4;
      }
      OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
    }
    MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  }
  
  if(ucRet>=2){
    return FALSE;
  }
  
  ucTimes=(((INT32U)SMOTO_COUNT_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+10/ACTION_DELAY_TIME_DEFAULT;
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_DEFAULT,MOTO_BACKWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosCBit)){
      //
      //OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucEnterC=1;
    }
    
    OS_ENTER_CRITICAL();
    if(ucEnterC){
      ucRet=1;
    }else if(!g_usrSMoto[ucSSelected].uiCounts){
      ucRet=2;
    }
    OS_EXIT_CRITICAL();
    
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;
    }
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  	
  if(ucRet>=2){
    return FALSE;
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: InToAntProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U InToAntProcess(CardMachineRxData *pcommRx1Data)
{
  INT8U ucRetrys=0;
  INT8U ucData[8+8];
  INT8U ucMode;
  INT32U ulTmp;
  
  INT8U ucType=DEV_TYPE();

  CPU_SR_ALLOC();
  
  MotoReset(NOWAIT_MODE,DMOTO_SECOND);
  
  if(ucType==SMALL_THICK_IN_TYPE){
    ulTmp=GetKeyOutput();
    if(InToAntPreProcess(ulTmp)){
      return 2;
    }
  }
  
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  OS_ENTER_CRITICAL();
  g_usrMotoFlags.uiFlag=0;
  OS_EXIT_CRITICAL();
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(InToAnt()){
      break;
    }
  }
  
  KeyChange();
  if(ucRetrys<=MOTO_RETRYS){
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_EXIT2ANT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    //BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }
}

/*******************************************************************************************************
** oˉêy??3?: AntToBox
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U AntToBox(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucEnterD=0;
  INT8U ucLeaveC=0;
  INT8U ucCardPos=0;
  INT8U ucDSelected=m_ucDMotoBit[DMOTO_FIRST];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
  
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
  INT16U uiDMotoPwm=m_uiDMotoPwm[ucDSelected];
  INT16U uiDMotoTime=((INT32U)DMOTO_FREQ_DEFAULT)*DMOTO_TIME_SK_DEFAULT/uiDMotoPwm;
  
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  INT8U ucDMoto1PosBBit=m_ucKeyBit[DMOTO1_POSB_BIT];
  INT8U ucCardBox1PosBit=m_ucKeyBit[CARDBOX1_POS_BIT];

  INT8U ucTimes;
  INT8U ucDelays;
  
  CPU_SR_ALLOC();
  
  ucTimes=(((INT32U)SMOTO_COUNT_ANTTOBOX_DEFAULT)*ucSMotoFreq)/1000+2;
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_ANTTOBOX_DEFAULT,MOTO_FORWARD_MODE,ucSSelected);
  
  ucRet=0;
  while(!ucRet){    
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosDBit)){
      //μ?′??¨?ú?a1?????
      ucEnterD=1;
    }
    
    if(!CheckBit(ulTmp,ucCardPosCBit)){
      //à??a?ú2??a1?????
      ucLeaveC=1;
    }   
    
    if(AntToBoxPreProcess(ulTmp)>1){
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);	
      if(PlugInClear(150)){
        break;
      }else{
        SMotoStart(ucSMotoFreq,SMOTO_COUNT_ANTTOBOX_DEFAULT+150,MOTO_FORWARD_MODE,ucSSelected);
        ucTimes=(((INT32U)SMOTO_COUNT_ANTTOBOX_DEFAULT+150)*ucSMotoFreq)/1000+2;
      }
    }
    
    if(!(CheckBit(ulTmp,ucCardPosCBit) || CheckBit(ulTmp,ucCardPosDBit))){//?T?¨
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);	
      ucRet=3;
    }
    
    OS_ENTER_CRITICAL();
    if(!g_usrSMoto[ucSSelected].uiCounts){
      if(ucLeaveC){
        ucRet=1;
      }else{      
        ucRet=2;
      }
    }
    OS_EXIT_CRITICAL();
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;
    }
    
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);	
  
  if(CheckBit(ulTmp,ucCardPosCBit) /*|| CheckBit(ulTmp,ucCardPosDBit)*/){								//óD?¨￡?′ò??￡?·μ????ê?
    return 0;
  }
          
  ucDelays=MOTO_INTERFER_TIME_DEFAULT/10;
  ucTimes=uiDMotoTime;
  DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_FORWARD_MODE,uiDMotoTime,ucDSelected);
  ucRet=0;
  while(!ucRet){
    if(ucDelays>0){
      ucDelays--;
    }else{
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucDMoto1PosBBit)){
        OSTimeDly(20,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
        ucRet=1;
      }

      if(CheckBit(ulTmp,ucCardBox1PosBit)){
        ucCardPos=1;																																		//?¨??μ????a1??′μ???
      }
      
      if(ucTimes>0){
        ucTimes--;
      }else{
        ucRet=2;
      }
    }
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
  OSTimeDly(MOTO_INTERFER_TIME_DEFAULT/10,OS_OPT_TIME_DLY, &os_err) ;         

  ucRet=0;
  ulTmp=GetKey();    	
  DebugInfoA(0x66,(INT8U *)&ulTmp,4);
  if(!(CheckBit(ulTmp,ucCardPosCBit) || CheckBit(ulTmp,ucCardPosDBit))){//?T?¨
    DebugInfoA(0x77,(INT8U *)&ulTmp,4);
    ucRet=1;
            
    if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited){
      m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited=1;
      
      //μ??ú???μ
      if(ucCardPos){																																									//???°°ù???¨ê??¨ê±??290??
        if(m_usrBoxInfo[BOX_FIRST].ucCounts<=95){
          BoxMotoMoveDown(BOXMOTO_FREQUENCE_PER_CARD*5,BOX_FIRST);																		//×°?¨1y3ì?D,è?1?3???μ????a1?2?μ???,?ò?μ5???¨??
        }else{
          CardBoxBasicInfoSend(0x80,BOX_FIRST);																												//?-à′·?ê?Dèòa315??
        }
      }else{
        BoxMotoMoveDown(BOXMOTO_FREQUENCE_PER_CARD,BOX_FIRST);																			
      }
      
      //???ó?¨êy
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ulMachineId=m_usrBoxInfo[BOX_FIRST].ulMachineId;
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucCurrentCount=m_usrBoxInfo[BOX_FIRST].ucCounts;
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucNewCount=m_usrBoxInfo[BOX_FIRST].ucCounts+1;
      m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucRetrys=8;
      CardCountUpdateSend(0,BOX_FIRST);
    #if MOTO_INTERFER_TIME_EN==1
      OSTimeDly(BOX_COUNT_WRITE_TIME/10,OS_OPT_TIME_DLY, &os_err) ;         
    #endif
    }
  }
  
  MotoReset(WAIT_MODE,DMOTO_SECOND);
  
  return ucRet; 
}

/*******************************************************************************************************
** oˉêy??3?: AntToBoxProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U AntToBoxProcess(CardMachineRxData *pcommRx1Data)
{
  OS_ERR os_err;
  
  INT8U ucRetrys=0;
  INT8U ucData[8+8];
  INT8U ucMode;
  INT32U ulTmp;

  INT8U ucBoxLoad1Bit=m_ucKeyBit[BOXLOAD1_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];

  INT8U ucSMotoFreq=m_ucSMotoFreq[SMOTO_FIRST];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];

  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }

  if(!MotoReset(WAIT_MODE,DMOTO_SECOND)){
    ucData[0]=SUBTYPE_ERR_HEAD1STATUSERR;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  ulTmp=GetKeyOutput();
  if(!CheckBit(ulTmp,ucBoxLoad1Bit)){
    ucData[0]=SUBTYPE_ERR_CARDBOX_UNLOAD;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
    ucData[0]=SUBTYPE_ERR_BOX_NOCONNECT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  if(m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucEnabled){
    ucData[0]=SUBTYPE_ERR_DEVICE_BUSY;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  if(m_usrBoxInfo[BOX_FIRST].ucCounts>=m_usrBoxInfo[BOX_FIRST].ucMaxCounts){
    ucData[0]=SUBTYPE_ERR_CARDCOUNT_OVER;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  if(!AntToBoxPreProcess(ulTmp)){
    ucData[0]=SUBTYPE_ERR_NOCARD_ONANT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  ucRetrys=0;
  m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCountWrited=0;
  while(++ucRetrys<=MOTO_RETRYS){
    if(AntToBox()){
      ulTmp=GetKeyOutput();    
      DebugInfoA(0x88,(INT8U *)&ulTmp,4);
      if((CheckBit(ulTmp,ucCardPosCBit) || CheckBit(ulTmp,ucCardPosDBit))){
        DebugInfoA(0x99,(INT8U *)&ulTmp,4);
        while(1){
          BSP_LED_Toggle(1);
          OSTimeDly(1000,OS_OPT_TIME_DLY, &os_err) ;         
          ulTmp=GetKeyOutput();    
          DebugInfoA(0xAA,(INT8U *)&ulTmp,4);
        }
      }else{
        break;
      }
    }

    BoxMotoMoveDown(BOXMOTO_FREQUENCE_PER_CARD*5,BOX_FIRST);		
    SMotoStart(ucSMotoFreq,20,MOTO_BACKWARD_MODE,ucSSelected);
    OSTimeDly(2000,OS_OPT_TIME_DLY, &os_err) ;         
  }

  if(ucRetrys<=MOTO_RETRYS){
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCardPos=0;
    if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bBuzzEn){
      if(m_usrBoxInfo[BOX_FIRST].ucBuzzMode>3){
        m_usrBoxInfo[BOX_FIRST].ucBuzzMode=0;
      }
      BuzzSet(2,BUZZ_SK_MODE[m_usrBoxInfo[BOX_FIRST].ucBuzzMode],BUZZ_SK_MODE[m_usrBoxInfo[BOX_FIRST].ucBuzzMode],0);
    }
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2BOX_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
  }
  return FALSE; 
}

/*******************************************************************************************************
** oˉêy??3?: ZInToAnt
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZInToAnt(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucLeaveC=0;
  INT8U ucEnterC=0;
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
          
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  
  INT8U ucFDir=MOTO_FORWARD_MODE;
  INT8U ucBDir=MOTO_BACKWARD_MODE;
  
  INT8U ucTimes;
  
  CPU_SR_ALLOC();
  
  ulTmp=GetKeyOutput();    
  if(CheckBit(ulTmp,ucCardPosCBit)){
    //反转
    ucTimes=(((INT32U)SMOTO_COUNT_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+10/ACTION_DELAY_TIME_DEFAULT;
    SMotoStart(ucSMotoFreq,SMOTO_COUNT_DEFAULT,ucBDir,ucSSelected);
    ucRet=0;
    while(!ucRet){
      ulTmp=GetKeyOutput();    
      if(!CheckBit(ulTmp,ucCardPosCBit)){
        //离开
        OSTimeDly(20,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
        ucLeaveC=1;
      }
      
      
      OS_ENTER_CRITICAL();
      if(ucLeaveC){
        ucRet=1;
      }else if(!g_usrSMoto[ucSSelected].uiCounts){
        ucRet=2;
      }
      OS_EXIT_CRITICAL();
      
      if(ucTimes>0){
        ucTimes--;
      }else{
        ucRet=4;
      }
      OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
    }
    MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  }
  
  if(ucRet>=2){
    return FALSE;
  }
  
  ucTimes=(((INT32U)SMOTO_COUNT_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+10/ACTION_DELAY_TIME_DEFAULT;
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_DEFAULT,ucFDir,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    //if(CheckBit(ulTmp,ucCardPosCBit)){
    if(!CheckBit(ulTmp,ucCardPosABit)){
      //
      //OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucEnterC=1;
    }
    
    OS_ENTER_CRITICAL();
    if(ucEnterC){
      ucRet=1;
    }else if(!g_usrSMoto[ucSSelected].uiCounts){
      ucRet=2;
    }
    OS_EXIT_CRITICAL();
    
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;
    }
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  	
  if(ucRet>=2){
    return FALSE;
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: ZInToAntProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZInToAntProcess(CardMachineRxData *pcommRx1Data)
{
  OS_ERR os_err;
  
  INT8U ucRetrys=0;
  INT8U ucData[8+8];
  INT8U ucMode;
  
  INT8U ucType=DEV_TYPE();

  CPU_SR_ALLOC();

#if SCAN_EN==1 && SCAN_AUTO_EN==1
  CloseScan();
  
  OS_ENTER_CRITICAL();
  g_usrScan.bEnabled=1;
  g_usrScan.bMode=SCAN_CLOSE_MODE;
  g_usrScan.b14Times=g_ucScanCloseTime;
  OS_EXIT_CRITICAL();
#endif
  
#if DOOR_OPEN_EN==1
  //关门
  MotoReset(WAIT_MODE,DMOTO_SECOND);
#endif
    
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  OS_ENTER_CRITICAL();
  g_usrMotoFlags.uiFlag=0;
  OS_EXIT_CRITICAL();
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(ZInToAnt()){
      break;
    }
  }
  
  KeyChange();
  if(ucRetrys<=MOTO_RETRYS){
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    g_ucLedMode=LEDOUT_OFF_MODE;
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_EXIT2ANT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }
}

/*******************************************************************************************************
** oˉêy??3?: ZAntToBox
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZAntToBox(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucEnterD=0;
  INT8U ucLeaveC=0;
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];  
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
    
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  //INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];

  INT8U ucFDir=MOTO_FORWARD_MODE;
  INT8U ucBDir=MOTO_BACKWARD_MODE;
  
  INT8U ucTimes;
  INT8U ucDelays;
  
  CPU_SR_ALLOC();
  
  ucTimes=(((INT32U)SMOTO_COUNT_ANTTOBOX_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+10/ACTION_DELAY_TIME_DEFAULT;
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_ANTTOBOX_DEFAULT,ucFDir,ucSSelected);
  ucRet=0;
  while(!ucRet){    
    ulTmp=GetKeyOutput();    
    /*if(CheckBit(ulTmp,ucCardPosDBit)){
      //μ?′??¨?ú?a1?????
      ucEnterD=1;
    }*/
    
    if(!CheckBit(ulTmp,ucCardPosCBit)){
      //à??a?ú2??a1?????
      ucLeaveC=1;
    }   
    
    /*if(AntToBoxPreProcess(ulTmp)>1){
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);	
      if(PlugInClear(150)){
        break;
      }else{
        SMotoStart(ucSMotoFreq,SMOTO_COUNT_ANTTOBOX_DEFAULT+150,MOTO_FORWARD_MODE,ucSSelected);
        ucTimes=(((INT32U)SMOTO_COUNT_ANTTOBOX_DEFAULT+150)*ucSMotoFreq)/1000+2;
      }
    }*/
    
    OS_ENTER_CRITICAL();
    if(!g_usrSMoto[ucSSelected].uiCounts){
      if(ucLeaveC){
        ucRet=1;
      }else{      
        ucRet=2;
      }
    }
    OS_EXIT_CRITICAL();
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;
    }
    
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);	
  
  if(CheckBit(ulTmp,ucCardPosCBit) /*|| CheckBit(ulTmp,ucCardPosDBit)*/){								//óD?¨￡?′ò??￡?·μ????ê?
    return 0;
  }
          
  return ucRet; 
}

/*******************************************************************************************************
** oˉêy??3?: ZAntToBoxProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZAntToBoxProcess(CardMachineRxData *pcommRx1Data)
{
  OS_ERR os_err;
  
  INT8U ucRetrys=0;
  INT8U ucData[8+8];
  INT8U ucMode;
  INT32U ulTmp;

  INT8U ucBoxLoad1Bit=m_ucKeyBit[BOXLOAD1_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];

  INT8U ucSMotoFreq=m_ucSMotoFreq[SMOTO_FIRST];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];

  static INT8U ucTest=0;
  
  CPU_SR_ALLOC();
  
#if SCAN_EN==1  
  CloseScan();
  
  OS_ENTER_CRITICAL();
  g_usrScan.bEnabled=0;
  OS_EXIT_CRITICAL();
#endif

  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }

  ulTmp=GetKeyOutput();
  if(!CheckBit(ulTmp,ucBoxLoad1Bit)){
    ucData[0]=SUBTYPE_ERR_CARDBOX_UNLOAD;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  if(!AntToBoxPreProcess(ulTmp)){
    ucData[0]=SUBTYPE_ERR_NOCARD_ONANT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  ucRetrys=0;
  while(++ucRetrys<=MOTO_RETRYS){
    if(ZAntToBox()==1){
      break;
    }else{
      ucTest=1;
    }
  }

  if(ucRetrys<=MOTO_RETRYS){
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bBuzzEn){
      if(m_usrBoxInfo[BOX_FIRST].ucBuzzMode>3){
        m_usrBoxInfo[BOX_FIRST].ucBuzzMode=0;
      }
      BuzzSet(2,BUZZ_SK_MODE[m_usrBoxInfo[BOX_FIRST].ucBuzzMode],BUZZ_SK_MODE[m_usrBoxInfo[BOX_FIRST].ucBuzzMode],0);
    }
    g_ucLedMode=LEDOUT_ON_MODE;
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2BOX_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
  }
  return FALSE; 
}


/*******************************************************************************************************
** oˉêy??3?: ZAntToOut
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZAntToOut(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucTmp;
  INT8U ucLeaveB=0;	
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];
  
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosBBit=m_ucKeyBit[CARD_POSB_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
  INT8U ucTimes;
  
  INT8U ucFDir=MOTO_FORWARD_MODE;
  INT8U ucBDir=MOTO_BACKWARD_MODE;
  
  CPU_SR_ALLOC();
  
  ucTimes=(((INT32U)SMOTO_COUNT_ZIN_ANTTOOUT_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+10/ACTION_DELAY_TIME_DEFAULT;
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_ZIN_ANTTOOUT_DEFAULT,ucBDir,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(!CheckBit(ulTmp,ucCardPosBBit)){
      //à??a?ú2??a1?????
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucLeaveB=1;
    }    
    OS_ENTER_CRITICAL();
    if(ucLeaveB){
      ucRet=1;
    }else if(!g_usrSMoto[ucSSelected].uiCounts){
      ucRet=2;
    }
    OS_EXIT_CRITICAL();
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;
    }
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
	
  if(ucRet>=2){
    return FALSE;
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: ZAntToOutProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZAntToOutProcess(CardMachineRxData *pcommRx1Data)
{
  INT8U ucRetrys=0;
  INT8U ucData[16];
  INT8U ucMode;
  INT32U ulTmp;
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosBBit=m_ucKeyBit[CARD_POSB_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  
  CPU_SR_ALLOC();
  
#if SCAN_EN==1 
  CloseScan();

  OS_ENTER_CRITICAL();
  g_usrScan.bEnabled=0;
  OS_EXIT_CRITICAL();
#endif

  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  ulTmp=GetKeyOutput();
  if(!(CheckBit(ulTmp,ucCardPosCBit) ||  CheckBit(ulTmp,ucCardPosBBit))){
    ucData[0]=SUBTYPE_ERR_NOCARD_ONANT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(ZAntToOut()){
      break;
    }
  }
  
  if(ucRetrys<=MOTO_RETRYS){
    //???ˉ?¨ê±?′°?3?±¨?ˉ  
    //TakeoutOvertimeRead();    
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    g_ucLedMode=LEDOUT_TOGGLE_MODE;
    m_usrGlobalFlag.usrBit.bWaitTakeOut=1;
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2EXIT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }  
}

/*******************************************************************************************************
** oˉêy??3?: ZDoorOpen
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZDoorOpen(INT8U ucState)
{
#if DOOR_OPEN_EN==1  
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucTmp;
  INT8U ucDSelected=m_ucDMotoBit[DMOTO_SECOND];
  INT16U uiDMotoPwm=m_uiDMotoPwm[ucDSelected];	                                                        
  INT16U uiDMotoTime=((INT32U)DMOTO_FREQ_DEFAULT)*DMOTO_TIME_SK_DEFAULT/uiDMotoPwm;
      
  INT8U ucDMoto1PosABit=m_ucKeyBit[DMOTO1_POSA_BIT];
  INT8U ucDMoto1PosBBit=m_ucKeyBit[DMOTO1_POSB_BIT];
  
  
  INT8U ucDelays;
  INT8U ucTimes;
  
  INT8U ucFDir=MOTO_FORWARD_MODE;
  INT8U ucBDir=MOTO_BACKWARD_MODE;
  
  CPU_SR_ALLOC();
  
  
  ulTmp=GetKeyOutput();    
  if(CheckBit(ulTmp,ucDMoto1PosBBit) && !CheckBit(ulTmp,ucDMoto1PosABit)){
    //开门
    OSTimeDly(1000,OS_OPT_TIME_DLY, &os_err) ;  
    
    //关门
    if(MotoReset(WAIT_MODE,DMOTO_SECOND)){
      return TRUE;
    }else{
      return FALSE;
    }
  }
       
  ucDelays=MOTO_INTERFER_TIME_DEFAULT/10;
  ucTimes=uiDMotoTime;
  DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,ucFDir,uiDMotoTime,ucDSelected);
  ucRet=0;
  while(!ucRet){
    if(ucDelays>0){
      ucDelays--;
    }else{
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucDMoto1PosBBit)){
        OSTimeDly(20,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
        ucRet=1;
      }

      if(ucTimes>0){
        ucTimes--;
      }else{
        ucRet=2;
      }
    }
    OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
  OSTimeDly(MOTO_INTERFER_TIME_DEFAULT/10,OS_OPT_TIME_DLY, &os_err) ;         
	    
  if(ucRet>=2){
    return FALSE;
  }
  
  if(ucState==DOOR_CLOSE_MODE){
    OSTimeDly(300,OS_OPT_TIME_DLY, &os_err) ;         
    if(MotoReset(WAIT_MODE,DMOTO_SECOND)){
      return TRUE;
    }else{
      return FALSE;
    }
  }
#endif
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: ZDoorOpenProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZDoorOpenProcess(CardMachineRxData *pcommRx1Data,INT8U ucState)
{
  INT8U ucRetrys=0;
  INT8U ucData[16];
  INT8U ucMode;
    
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(ZDoorOpen(ucState)){
      break;
    }
  }
  
  if(ucRetrys<=MOTO_RETRYS){
    //???ˉ?¨ê±?′°?3?±¨?ˉ  
    //TakeoutOvertimeRead();    
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_DOOROPEN_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }  
}


/*******************************************************************************************************
** oˉêy??3?: ZPrintOpen
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZPrintOpen(INT8U ucState)
{
#if PAPER_RECYCLE_EN==0    
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucTmp;
  INT8U ucDSelected=m_ucDMotoBit[DMOTO_FIRST];
  INT16U uiDMotoPwm=m_uiDMotoPwm[ucDSelected];	                                                        
  INT16U uiDMotoTime=((INT32U)DMOTO_FREQ_DEFAULT)*DMOTO_TIME_SK_DEFAULT/uiDMotoPwm;
      
  INT8U ucDMoto2PosABit=m_ucKeyBit[DMOTO2_POSA_BIT];
  
  
  INT8U ucDelays;
  INT8U ucTimes;
  
  INT8U ucFDir=MOTO_FORWARD_MODE;
  INT8U ucBDir=MOTO_BACKWARD_MODE;
  
  CPU_SR_ALLOC();
  
  
  ulTmp=GetKeyOutput();    
       
  ucDelays=MOTO_INTERFER_TIME_DEFAULT*2/5;
  ucTimes=uiDMotoTime;
  DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_BACKWARD_MODE,uiDMotoTime,ucDSelected);
  /*if(!CheckBit(ulTmp,ucDMoto2PosABit)){
    OSTimeDly(200,OS_OPT_TIME_DLY, &os_err) ;  
  }*/
  ucRet=0;
  while(!ucRet){
    if(ucDelays>0){
      ucDelays--;
    }else{
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucDMoto2PosABit)){
        //OSTimeDly(20,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
        ucRet=1;
      }

      if(ucTimes>0){
        ucTimes--;
      }else{
        ucRet=2;
      }
    }
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_DC_DISABLED(ucDSelected,NORMAL_MODE);
  OSTimeDly(MOTO_INTERFER_TIME_DEFAULT/10,OS_OPT_TIME_DLY, &os_err) ;         
	    
  if(ucRet>=2){
    return FALSE;
  }
  return TRUE;
#else  
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_SECOND];
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];
          
  INT8U ucDMoto1PosABit=m_ucKeyBit[DMOTO1_POSA_BIT];
  INT8U ucDMoto1PosBBit=m_ucKeyBit[DMOTO1_POSB_BIT];
 
  INT8U ucEnterB=0;
  
  INT8U ucTimes;
  
  CPU_SR_ALLOC();
    
  ulTmp=GetKeyOutput();    
  if(!CheckBit(ulTmp,ucDMoto1PosBBit) && !CheckBit(ulTmp,ucDMoto1PosABit)){
    //中间位置
    SMotoStart(ucSMotoFreq,SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT,MOTO_FORWARD_MODE,ucSSelected);    
    ucRet=DMotoPosBWaitEnter(SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT-10,0);//ucSSelected);
    MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
    //
    SMotoReset(WAIT_MODE,SMOTO_SECOND);
  }
       
  ucTimes=(((INT32U)SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT)*ucSMotoFreq)/(100*ACTION_DELAY_TIME_DEFAULT)+10/ACTION_DELAY_TIME_DEFAULT;
  SMotoStart(ucSMotoFreq,SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT,MOTO_FORWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucDMoto1PosBBit)){
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucEnterB=1;
    }
    
    OS_ENTER_CRITICAL();
    if(ucEnterB){
      ucRet=1;
    }else if(!g_usrSMoto[ucSSelected].uiCounts){
      ucRet=2;
    }
    OS_EXIT_CRITICAL();
    
    if(ucTimes>0){
      ucTimes--;
    }else{
      ucRet=4;
    }
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  	
  if(ucRet>=2){
    return FALSE;
  }
  
  if(ucState==DOOR_CLOSE_MODE){
    if(SMotoReset(WAIT_MODE,SMOTO_SECOND)){
      return TRUE;
    }else{
      return FALSE;
    }
  }
  return TRUE;
#endif  
}

/*******************************************************************************************************
** oˉêy??3?: ZPrintOpenProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U ZPrintOpenProcess(CardMachineRxData *pcommRx1Data,INT8U ucState)
{
  INT8U ucRetrys=0;
  INT8U ucData[16];
  INT8U ucMode;
    
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(ZPrintOpen(ucState)){
      break;
    }
  }
  
  if(ucRetrys<=MOTO_RETRYS){
    //???ˉ?¨ê±?′°?3?±¨?ˉ  
    //TakeoutOvertimeRead();    
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_PRINTOPEN_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }  
}


/*******************************************************************************************************
** oˉêy??3?: LChannelToAnt
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LChannelToAnt(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucEnterC=0;
  INT8U ucLeaveC=0;	
  INT8U ucEnterA=0;
  INT16U uiSteps=SMOTO_COUNT_DEFAULT;
  INT8U ucSSelected=SMOTO_FIRST;
  INT8U ucSSelected1=SMOTO_SECOND;
  
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosBBit=m_ucKeyBit[CARD_POSB_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  
  
  CPU_SR_ALLOC();
  
  SMotoStart(m_ucSMotoFreq[ucSSelected],uiSteps,MOTO_FORWARD_MODE,ucSSelected);
  SMotoStart(m_ucSMotoFreq[ucSSelected1],uiSteps,MOTO_FORWARD_MODE,ucSSelected1);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosDBit)){
      //??è??a1?????
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
    }    
		
    if(CheckBit(ulTmp,ucCardPosCBit)){
      //??è??a1?????
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucEnterC=1;
    }    
    if(!CheckBit(ulTmp,ucCardPosCBit) && ucEnterC){
      //à??a?a1?????
      MOTO_STEP_DISABLED(ucSSelected1,NORMAL_MODE);
      ucLeaveC=1;
    }    
		
    if(CheckBit(ulTmp,m_ucKeyBit[CARD_POSB_BIT])){
      //??è??a1?????
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
    }    
				
    if(CheckBit(ulTmp,ucCardPosABit)){
      //??è??a1?????
      MOTO_STEP_DISABLED(ucSSelected1,NORMAL_MODE);
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucEnterA=1;
    }    
		
    if(ucLeaveC || ucEnterA){
      ucRet=1;
    }else if(!g_usrSMoto[ucSSelected].uiCounts || !g_usrSMoto[ucSSelected1].uiCounts){
      ucRet=2;
    }
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  MOTO_STEP_DISABLED(ucSSelected1,NORMAL_MODE);
	
  if(ucRet>=2){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosABit) && CheckBit(ulTmp,ucCardPosCBit)){
      return TRUE;
    }
    return FALSE;
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: LBoxToChannel
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LBoxToChannel(INT8U ucSelected)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucEnterE=0;
  INT8U ucLeaveE=0;
  INT8U ucPos=0;
  INT16U uiTmp=20;

  INT8U ucDMotoBitB=m_ucKeyBit[DMOTO1_POSB_BIT+ucSelected*8];
  INT8U ucCardEBit=m_ucKeyBit[CARD_POSE1_BIT+ucSelected*8];

  INT16U uiDMotoPwm=m_uiDMotoPwm[ucSelected];
  INT8U ucSMotoFreq=m_ucSMotoFreq[SMOTO_SECOND];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_SECOND];
  
  INT8U ucDelays;
  INT8U ucTimes;

  CPU_SR_ALLOC();
  
  if(ucSelected>=CARDMACHINE_DMOTO_NUMS){
    return FALSE;
  }
    
  ucDelays=MOTO_INTERFER_TIME_DEFAULT/5;

  ulTmp=GetKeyOutput();    
  if(CheckBit(ulTmp,ucCardEBit)){
    ucEnterE=1;
  }

  ucTimes=(((INT32U)1000)*ucSMotoFreq)/1000+2;
  ucDelays=DMOTO_TIME_DEFAULT;
  DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_FORWARD_MODE,DMOTO_TIME_DEFAULT,ucSelected);
  SMotoStart(ucSMotoFreq,1000,MOTO_FORWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    if(ucDelays>0){
      ucDelays--;
    }else{
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucDMotoBitB)){
       OSTimeDly(20,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_DC_DISABLED(ucSelected,NORMAL_MODE);
        ucPos=1;	
      }
              
      if(CheckBit(ulTmp,ucCardEBit)){
        ucEnterE=1;
      }
      
      if(!CheckBit(ulTmp,ucCardEBit) && ucEnterE){
        ucLeaveE=1;
        if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCountWrited){
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCountWrited=1;
          
          //??éù?¨êy
          m_usrBoxInfo[ucSelected].usrCountResponse.ulMachineId=m_usrBoxInfo[ucSelected].ulMachineId;
          m_usrBoxInfo[ucSelected].usrCountResponse.ucCurrentCount=m_usrBoxInfo[ucSelected].ucCounts;
          m_usrBoxInfo[ucSelected].usrCountResponse.ucNewCount=m_usrBoxInfo[ucSelected].ucCounts-1;
          m_usrBoxInfo[ucSelected].usrCountResponse.ucRetrys=8;
          CardCountUpdateSend(0,ucSelected);
        }
      }		
      
      if(ucPos){
        ucRet=1;
      }else if(!g_usrDMoto[ucSelected].uiTime){
        ucRet=2;
      }
    }
   OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
    
  }

  MOTO_DC_DISABLED(ucSelected,NORMAL_MODE);
  MOTO_STEP_DISABLED(SMOTO_FIRST,NORMAL_MODE);
  OSTimeDly(MOTO_INTERFER_TIME_DEFAULT/10,OS_OPT_TIME_DLY, &os_err) ;         

  if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCountWrited){
    OSTimeDly(BOX_COUNT_WRITE_TIME/10,OS_OPT_TIME_DLY, &os_err) ;         
  }

  if(ucRet>=2){
    return FALSE;
  }  
	
  if(!LMotoReset(ucSelected)){
    return 2;
  }
	
  //μ??úé?éy
  CardBoxBasicInfoSend(0x80,ucSelected);
  
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: LBoxToAntProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LBoxToAntProcess(CardMachineRxData *pcommRx1Data,INT8U ucSelected)
{
  INT8U ucRetrys=0;
  INT8U ucData[32];
  INT8U ucMode;
  INT32U ulTmp;
  INT8U ucRet;	
  INT8U ucReset;
  INT8U ucBoxLoadBit=m_ucKeyBit[BOXLOAD1_BIT+ucSelected*8];
  
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return FALSE;
  }
  
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }
  
  ucRetrys=0;
  ucRet=0;
  while(++ucRetrys<=MOTO_RETRYS){
    ucRet=LBoxToAntPreProcess();
    if(!ucRet){
      break;
    }else if(ucRet==1){
      ucData[0]=SUBTYPE_ERR_CARD_ONANT;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
      return FALSE;
    }
  }	
  if(ucRetrys>MOTO_RETRYS){
    ucData[0]=SUBTYPE_ERR_CARD_SLIPPED;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }
	
	
  if(m_usrErrorFlags.usrBit.bBoxToAnt){
    m_usrErrorFlags.usrBit.bBoxToAnt=0;
    if(LChannelToAnt()){
      ucData[0]=SUBTYPE_ERR_CARD_ONANT;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
      return FALSE;
    }
  }

  ulTmp=GetKeyOutput();
  if(!CheckBit(ulTmp,ucBoxLoadBit)){
    ucData[0]=SUBTYPE_ERR_CARDBOX_UNLOAD;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
    
  if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
    ucData[0]=SUBTYPE_ERR_BOX_NOCONNECT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled){
    ucData[0]=SUBTYPE_ERR_DEVICE_BUSY;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }

  if(!m_usrBoxInfo[ucSelected].ucCounts){
    ucData[0]=SUBTYPE_ERR_CARDCOUNT_ZERO;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }	
    
  m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCountWrited=0;
  ucReset=0;
  ucRet=0;
  ucRetrys=0;
  while(++ucRetrys<=MOTO_RETRYS){
    ulTmp=GetKeyOutput();
    if(!CheckBit(ulTmp,ucBoxLoadBit)){
      ucData[0]=SUBTYPE_ERR_CARDBOX_UNLOAD;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
      return FALSE;
    }
    if(!ucReset){
      if(LMotoReset(ucSelected)){
        ucRetrys=0;
        ucReset=1;
      }
    }
    if(ucReset){
      if(!ucRet){
        ucRet=LBoxToChannel(ucSelected);
      }
      if(ucRet){
        if(LChannelToAnt()){
          m_usrErrorFlags.usrBit.bBoxToAnt=0;
          break;
        }else{
          m_usrErrorFlags.usrBit.bBoxToAnt=1;
        }
      }else{
        ucReset=0;
      }
    }
  }

  KeyChange();
  if(ucRetrys>MOTO_RETRYS){
    ucData[0]=SUBTYPE_ERR_BOX2ANT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    BuzzSet(4,50,25,BUZZ_SFK_ERROR_PRIOR);
    return FALSE;
  }else{
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: LAntToOut
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LAntToOut(void)
{
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucTmp;
  INT8U ucEnterB=0;
  INT8U ucLeaveB=0;	
  INT16U uiSteps=300;
  INT8U ucExit=0;
  
  INT8U ucSMotoFreq=m_ucSMotoFreq[1];
  
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosBBit=m_ucKeyBit[CARD_POSB_BIT];
  
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_SECOND];
          
  if(EepromReadVerifyBytes(AUTOOUT_MODE_ADDR,&ucTmp,1)){
    if(!ucTmp){
      uiSteps=600;
      ucExit=1;
    }
  }
  
  SMotoStart(ucSMotoFreq,uiSteps,MOTO_FORWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosBBit)){
      //??è??a1?????
      ucEnterB=1;
    }    
		
    if(!CheckBit(ulTmp,ucCardPosBBit) && ucEnterB){
      //à??a?ú2??a1?????
      if(!ucExit){
        MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      }
      ucLeaveB=1;
    }    
		
    if(ucLeaveB){
      if(!ucExit){
        ucRet=1;
      }
    }
    if(!g_usrSMoto[ucSSelected].uiCounts){
      if(ucLeaveB){
        ucRet=1;
      }else{
        ucRet=2;
      }
    }
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  
  ulTmp=GetKeyOutput();    
  if(ucRet>=2){
    if(CheckBit(ulTmp,ucCardPosABit) && !CheckBit(ulTmp,ucCardPosBBit)){
      if(ucExit){
        if(!LAntToOutPreProcess(ulTmp)){
          m_usrGlobalFlag.usrBit.bCardTakeout=1;
        }
      }
      return TRUE;
    }
    return FALSE;
  }
  if(ucExit){
    if(!LAntToOutPreProcess(ulTmp)){
      m_usrGlobalFlag.usrBit.bCardTakeout=1;
    }
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: LAntToOutProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LAntToOutProcess(CardMachineRxData *pcommRx1Data)
{
  INT8U ucRetrys=0;
  INT8U ucData[16];
  INT8U ucMode;
  INT32U ulTmp;
  
  CPU_SR_ALLOC();
  
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }

  ulTmp=GetKeyOutput();
  if(!LAntToOutPreProcess(ulTmp)){
    ucData[0]=SUBTYPE_ERR_NOCARD_ONANT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(LAntToOut()){
      break;
    }
  }
  
  if(ucRetrys<=MOTO_RETRYS){
    //???ˉ?¨ê±?′°?3?±¨?ˉ  
    //TakeoutOvertimeRead();    
    OS_ENTER_CRITICAL();
    g_usrGlobalFlag.usrBit.bLedOutMode=0x01;		
    OS_EXIT_CRITICAL();
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2EXIT_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }  
}

/*******************************************************************************************************
** oˉêy??3?: LAntToRev
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LAntToRev(void)
{
  INT8U ucRet;
  INT32U ulTmp;
  INT8U ucEnterD=0;	
  INT8U ucLeaveD=0;	
  INT16U uiSteps=400;
  
  INT8U ucSMotoFreq=m_ucSMotoFreq[SMOTO_SECOND];
  
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_SECOND];
  
  SMotoStart(ucSMotoFreq,uiSteps,MOTO_BACKWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosDBit)){
      //??è??a1?????
      ucEnterD=1;
    }    
		
    if(!CheckBit(ulTmp,ucCardPosDBit) && ucEnterD){
      //à??a?a1?????
      ucLeaveD=1;
    }    
		
    if(!g_usrSMoto[ucSSelected].uiCounts){
      if(ucLeaveD){
        ucRet=1;
      }else{      
        ucRet=2;
      }
    }
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
	
  if(ucRet>=2){
    return FALSE;
  }
  return TRUE;
}

/*******************************************************************************************************
** oˉêy??3?: LAntToRevProcess
** 1|?ü?èê?: 
** ê? ?? è?:
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LAntToRevProcess(CardMachineRxData *pcommRx1Data)
{
  INT8U ucRetrys=0;
  INT8U ucData[16];
  INT8U ucMode;
  INT32U ulTmp;
  
  ucMode=0;
  if(!pcommRx1Data){
    ucMode=1;
  }

  ulTmp=GetKeyOutput();
  if(!LAntToOutPreProcess(ulTmp)){
    ucData[0]=SUBTYPE_ERR_NOCARD_ONEXIT;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }
  
  while(++ucRetrys<=MOTO_RETRYS){
    if(LAntToRev()){
      break;
    }
  }
  
  if(ucRetrys<=MOTO_RETRYS){
    Uart0Pack(INFTYPE_CMD_FINISHED,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,0,0,ucMode);
    return TRUE;
  }else{
    ucData[0]=SUBTYPE_ERR_ANT2REV_FAIL;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommRx1Data->ucAddr,pcommRx1Data->ucSeq,ucData,1,ucMode);
    return FALSE;
  }  
}

/*******************************************************************************************************
** oˉêy??3?: LMotoReset
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U  LMotoReset(INT8U ucSelected)
{
  INT8U ucRet;
  INT16U uiDMotoPwm;
  INT8U ucRetrys=0;
  INT32U ulTmp;
  INT8U ucBoxLoadBit=m_ucKeyBit[BOXLOAD1_BIT+ucSelected*8];

  //uiDMotoPwm=DMotoPwmGet();
  uiDMotoPwm=m_uiDMotoPwm[ucSelected];

  CPU_SR_ALLOC();

  if(DMotoPosAValid(ucSelected)){
    ClrBit(m_usrErrorFlags.ucFlag,ucSelected);
    return TRUE;
  }

  while(++ucRetrys<=4){
    DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_BACKWARD_MODE,DMOTO_TIME_DEFAULT,ucSelected);
    ucRet=DMotoPosAWaitEnter(DMOTO_TIME_DEFAULT-10,ucSelected);
    MOTO_DC_DISABLED(ucSelected,NORMAL_MODE);
    if(!ucRet){
      DMotoStart(DMOTO_FREQ_DEFAULT,uiDMotoPwm,MOTO_FORWARD_MODE,DMOTO_TIME_DEFAULT,ucSelected);
      DMotoPosBWaitEnter(DMOTO_TIME_DEFAULT-50,ucSelected);
      MOTO_DC_DISABLED(ucSelected,NORMAL_MODE);
      
      BoxMotoMoveDown(3000,ucSelected);		
      OS_ENTER_CRITICAL();
      g_ucCommTime=200;
      OS_EXIT_CRITICAL();
      while(1){
        OS_ENTER_CRITICAL();
        if(!g_ucCommTime){
          OS_EXIT_CRITICAL();
          break;
        }else{
          OS_EXIT_CRITICAL();
        }
        ulTmp=GetKeyOutput();
        if(!CheckBit(ulTmp,ucBoxLoadBit)){
          break;
        }
      }
    }else{
      ClrBit(m_usrErrorFlags.ucFlag,ucSelected);
      return TRUE;
    }			
  }

  SetBit(m_usrErrorFlags.ucFlag,ucSelected);
  return FALSE;
}
 

/********************************************************************************************************
** oˉêy??3?: PlugInClear
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
INT8U PlugInClear(INT16U uiCount)
{
  INT32U ulTmp;
  INT8U ucSMotoFreq=m_ucSMotoFreq[SMOTO_FIRST];

  INT8U ucSSelected=m_ucSMotoBit[SMOTO_FIRST];

  CPU_SR_ALLOC();

  OS_ENTER_CRITICAL();
  /*if(!CheckBit(g_usrGetKey.ulKeyOutput,CARD_POSA_BIT)){
  OS_EXIT_CRITICAL();
  return TRUE;
  }*/

  g_ucCommTime=20;
  OS_EXIT_CRITICAL();
  SMotoStart(ucSMotoFreq,uiCount,MOTO_BACKWARD_MODE,ucSSelected);
  while(1){
    ulTmp=GetKeyOutput();    
    if(!CheckBit(ulTmp,CARD_POSA_BIT)){
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);	
      return TRUE;
    }
    OS_ENTER_CRITICAL();
    if(!g_ucCommTime){
      OS_EXIT_CRITICAL();
      break;
    }else{
      OS_EXIT_CRITICAL();
    }
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);	
  if(!CheckBit(ulTmp,CARD_POSC_BIT)){
    return TRUE;
  }
  return FALSE;
}

/*******************************************************************************************************
** oˉêy??3?: AntToOutPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U AntToOutPreProcess(INT32U ulState)
{
  INT8U ucTmp;

  ucTmp=((ulState>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01) | ((ulState>>m_ucKeyBit[CARD_POSB_BIT]) & 0x06) ;
  switch(ucTmp){
    case 0:
      return 0;															//?T?¨
    case 3:
    case 2:
    case 6:
    case 4:
      return 1;															//ò????¨
    case 7:																	
      return 2;															//á????¨￡?ò????ú???¨?ú￡?ò????úí¨μà?D
    case 5:																														
      return 3;															//á????¨￡?ò????ú???¨?ú￡?ò????ú???¨?D?ú	
    default:
      return 4;
  }
}


/*******************************************************************************************************
** oˉêy??3?: LBoxToAntPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LBoxToAntPreProcess(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT8U ucTmp;	
  INT32U ulTmp;
  INT8U ucEnterC=0;
  INT8U ucLeaveC=0;
  INT8U ucEnterA=0;
  INT8U ucLeaveA=0;
  INT16U uiSteps=400;

  INT8U ucSMotoFreq=m_ucSMotoFreq[SMOTO_SECOND];
  INT8U ucSSelected=m_ucSMotoBit[SMOTO_SECOND];

  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];

  ulTmp=GetKeyOutput();
  ucTmp=((ulTmp>>m_ucKeyBit[CARD_POSA_BIT]) & 0x07) | (((ulTmp>>m_ucKeyBit[CARD_POSD_BIT]) & 0x01)<<3);
  if(!ucTmp){
    return 0;
  }

  if(CheckBit(ulTmp,ucCardPosABit) && CheckBit(ulTmp,ucCardPosCBit)){
    return 1;
  }	

  if(ucTmp>=1 && ucTmp<=3){
    SMotoStart(ucSMotoFreq,uiSteps,MOTO_BACKWARD_MODE,ucSSelected);
    ucRet=0;
    while(!ucRet){
      ulTmp=GetKeyOutput();    
      if(CheckBit(ulTmp,ucCardPosCBit)){
        //??è??a1?????
        OSTimeDly(10,OS_OPT_TIME_DLY, &os_err) ;         
        MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
        ucRet=1;
        break;
      }    
      
      if(CheckBit(ulTmp,ucCardPosDBit)){
        //??è??a1?????
        MOTO_STEP_DISABLED(SMOTO_SECOND,NORMAL_MODE);
        ucRet=3;
        break;
      }    
      
      if(!g_usrSMoto[1].uiCounts){
        ucRet=2;
      }
    }
    MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);

    if(ucRet<3){
      return ucRet;
    }
  }

  ucLeaveC=0;
  ucEnterC=0;
  ucEnterA=0;
  if(!CheckBit(ulTmp,ucCardPosABit)){
    ucLeaveA=1;
  }

  SMotoStart(ucSMotoFreq,uiSteps,MOTO_FORWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosCBit)){
      //??è??a1?????
      ucEnterC=1;
    }    
    if(!CheckBit(ulTmp,ucCardPosCBit) && ucEnterC){
      //à??a?a1?????
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucLeaveC=1;
    }    
    if(CheckBit(ulTmp,ucCardPosABit) && ucLeaveA){
      //??è??a1?????
      MOTO_STEP_DISABLED(SMOTO_SECOND,NORMAL_MODE);
      ucEnterA=1;
    }    

    if(ucLeaveC || ucEnterA){
      ucRet=1;
    }else if(!g_usrSMoto[ucSSelected].uiCounts){
      ucRet=2;
    }
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);

  return ucRet;
}

/*******************************************************************************************************
** oˉêy??3?: AntToBoxPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U AntToBoxPreProcess(INT32U ulState)
{ 
	INT8U ucTmp;
	ucTmp=((ulState>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01) | (((ulState>>m_ucKeyBit[CARD_POSC_BIT]) & 0x03)<<1) ;
	switch(ucTmp){
		case 0:
			return 0;															//?T?¨
		case 3:
		case 2:
		case 6:
		case 4:
			return 1;															//ò????¨
		case 7:																	
			return 2;															//á????¨￡?ò????ú???¨?ú￡?ò????úí¨μà?D
		case 5:																														
			return 3;															//á????¨￡?ò????ú???¨?ú￡?ò????ú???¨?D?ú	
		default:
			return 4;
	}
}

/*******************************************************************************************************
** oˉêy??3?: BoxToAntPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U BoxToAntPreProcess(void)
{
  OS_ERR os_err;
  
  INT8U ucRet;
  INT8U ucTmp;	
  INT32U ulTmp;
  INT8U ucEnterC=0;
  INT8U ucLeaveC=0;
  INT8U ucEnterA=0;
  INT16U uiSteps=400;
  
  INT8U ucSSelected=SMOTO_FIRST;
  INT8U ucSMotoFreq=m_ucSMotoFreq[ucSSelected];

  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  
  ulTmp=GetKeyOutput();
  ucTmp=((ulTmp>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01) | (((ulTmp>>m_ucKeyBit[CARD_POSC_BIT]) & 0x03)<<1) ;
  if(!ucTmp){
    return 0;
  }
  
  if(ucTmp==1){
    return 3;
  }
  
  if(ucTmp==7){
    return 4;
  }
  
  if(CheckBit(ulTmp,ucCardPosABit) && CheckBit(ulTmp,ucCardPosCBit)){
    return 1;
  }	
  
  if(CheckBit(ulTmp,m_ucKeyBit[CARD_POSA_BIT])){
    ucEnterA=1;
  }    
  
  SMotoStart(ucSMotoFreq,uiSteps,MOTO_BACKWARD_MODE,ucSSelected);
  ucRet=0;
  while(!ucRet){
    OSTimeDly(30,OS_OPT_TIME_DLY, &os_err) ;         
    ulTmp=GetKeyOutput();    
    if(CheckBit(ulTmp,ucCardPosCBit)){
      //ò?μ??ú2??a1?????
      ucEnterC=1;
      }        

    if(CheckBit(ulTmp,ucCardPosABit) && !ucEnterA){
      //ò?μ?ía2??a1?????
      MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
      ucEnterA=1;
    }    

    //ía2??a1?1ê??ê±,ó??ú2??a1?DT?y
    if(!CheckBit(ulTmp,ucCardPosCBit) && ucEnterC){
      //à??a?ú2??a1?????
      MOTO_STEP_DISABLED(SMOTO_FIRST,NORMAL_MODE);
      ucLeaveC=1;
    }  

    if(ucEnterA  || ucLeaveC){
      ucRet=1;			
    }else if(!g_usrSMoto[ucSSelected].uiCounts){
      ucRet=2;
    }
          
  }
  MOTO_STEP_DISABLED(ucSSelected,NORMAL_MODE);
  
  return ucRet;
}

/*******************************************************************************************************
** oˉêy??3?: LAntToOutPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U LAntToOutPreProcess(INT32U ulState)
{
  INT8U ucTmp;

  ucTmp=((ulState>>m_ucKeyBit[CARD_POSA_BIT]) & 0x07) | ((ulState>>m_ucKeyBit[CARD_POSE_BIT]) & 0x08);
  return ucTmp;
}

/*******************************************************************************************************
** oˉêy??3?: InToAntPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U InToAntPreProcess(INT32U ulState)
{
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  INT8U ucCardPosBBit=m_ucKeyBit[CARD_POSB_BIT];
  INT8U ucCardPosCBit=m_ucKeyBit[CARD_POSC_BIT];
  INT8U ucCardPosDBit=m_ucKeyBit[CARD_POSD_BIT];
  
  if(CheckBit(ulState,ucCardPosCBit) || CheckBit(ulState,ucCardPosDBit) || CheckBit(ulState,ucCardPosDBit) || CheckBit(ulState,ucCardPosDBit)){
    return TRUE;
  }
  return FALSE;
}

/*******************************************************************************************************
** oˉêy??3?: InToAntPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void LOutAutoEvent(void)
{
  INT8U ucSelected;
  INT8U ucCardPosABit;
  
  
  for(ucSelected=0;ucSelected<CARDMACHINE_CARDBOX_NUMS;ucSelected++){
    if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
      return;
    }
    if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest){
      return;
    }
    if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled){
      return;
    }
    if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos){
      return;
    }

    //·￠?¨-è?×??¨??
    if(m_usrGlobalFlag.usrBit.bCardTakeout){
      m_usrGlobalFlag.usrBit.bCardTakeout=0;        
      if(LBoxToAntProcess(NULL,ucSelected)){
        if(LAntToOutProcess(NULL)){
          ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT+ucSelected*8];
          ClrBit(m_ulKeyOutput,ucCardPosABit);
        }
      }
    }
  }
}

/*******************************************************************************************************
** oˉêy??3?: InToAntPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void SOutAutoEvent(void)
{
  
  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
    return;
  }
  if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bSelftest){
    return;
  }
  if(m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucEnabled){
    return;
  }
  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCardPos){
    return;
  }
  
  //·￠?¨-è?×??¨??
  m_ucMachineAddr=0x40;
  if(m_usrGlobalFlag.usrBit.bCardTakeout){
    m_usrGlobalFlag.usrBit.bCardTakeout=0;        
    if(BoxToAntProcess(NULL)){
      if(AntToOutProcess(NULL)){
        ClrBit(m_ulKeyOutput,m_ucKeyBit[CARD_POSA_BIT]);
      }
    }
  }
  
}

/*******************************************************************************************************
** oˉêy??3?: InToAntPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void SInAutoEvent(void)
{
  INT8U ucRet;
  
  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
    return;
  }
  if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bSelftest){
    return;
  }
  if(m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucEnabled){
    return;
  }
  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCardPos){
    return;
  }

  //ê??¨-2?è??¨??
  m_ucMachineAddr=0x41;
  if(m_usrGlobalFlag.usrBit.bCardPlugIn){
    m_usrGlobalFlag.usrBit.bCardPlugIn=0;
    if((ucRet=InToAntProcess(NULL))>0){
      if(ucRet==2){
        DebugInfoA(0x55,NULL,0);
      }
      if(AntToBoxProcess(NULL)){
        ClrBit(m_ulKeyOutput,m_ucKeyBit[CARD_POSA_BIT]);
      }
    }
  }  
}

/*******************************************************************************************************
** oˉêy??3?: InToAntPreProcess
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void ZInAutoEvent(void)
{
  INT8U ucRet;
  
  //ê??¨-2?è??¨??
  m_ucMachineAddr=0x41;
  if(m_usrGlobalFlag.usrBit.bCardPlugIn){
    m_usrGlobalFlag.usrBit.bCardPlugIn=0;
    if((ucRet=ZInToAntProcess(NULL))>0){
      if(ucRet==2){
        DebugInfoA(0x55,NULL,0);
      }
      if(ZAntToBoxProcess(NULL)){
        ClrBit(m_ulKeyOutput,m_ucKeyBit[CARD_POSA_BIT]);
      }
    }
  }  
}

/*******************************************************************************************************
** oˉêy??3?: SGInAutoEvent
** 1|?ü?èê?: 
** ê? ?? è?: 
**
** ê???  3?:
**
** è???±?á?:
** μ÷ó??￡?é:
**
** ×÷??  ??: John Tonny
** è???  ?ú: 2009?ê11??01è?
**------------------------------------------------------------------------------------------------------
** DT ?? è?:
** è???  ?ú:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void SGInAutoEvent(void)
{
  INT8U ucRet;
  INT8U ucCardBoxPosBit;
  INT32U ulTmp;
  
  if(m_usrGlobalFlag.usrBit.bGCardToOut){
    if(GCardToAntProcess(&m_usrComm1RxData)){
      if(!GAntToOutProcess(NULL)){
        m_usrGlobalFlag.usrBit.bGCardToOut=0;            
      }
    }else{
      m_usrGlobalFlag.usrBit.bGCardToOut=0;            
    }
  }else{
    if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
      return;
    }
    if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bSelftest){
      return;
    }
    
    if(m_usrGlobalFlag.usrBit.bGCardToBox){
      if(g_ucGInState==GIN_CARDTOANT_STATE){
        if(!GCardToAntProcess(NULL)){
          m_usrGlobalFlag.usrBit.bGCardToBox=0;
        }
      }
      g_ucGInState=GIN_ANTTOBOX_STATE;
      if(m_usrBoxInfo[BOX_FIRST].usrCountResponse.ucEnabled){
        return;
      }
      
      ucCardBoxPosBit=m_ucKeyBit[CARDBOX1_POS_BIT];
      ulTmp=GetKeyOutput();
      if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCardPos && CheckBit(ulTmp,ucCardBoxPosBit)){
        return;
      }
            
      ucRet=GAntToBoxProcess(NULL);
      if(!ucRet){
        g_ucGInState=GIN_CARDTOANT_STATE;
      }else if(ucRet==1){
        m_usrGlobalFlag.usrBit.bGCardToBox=0;
      }
    }	
  }
}

/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/

