/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: Buzz.C
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

#define  BUZZ_GLOBALS
#include "includes.h"
  
#if BUZZ_EN>0

#if BUZZ_POSITIVE_EN==0

#define OpenBuzz()           		  CSP_GPIO_BitSet(BSP_GPIO_BUZZ_OUT_PORT,BSP_GPI0_BUZZ_OUT);
#define CloseBuzz()          		  CSP_GPIO_BitClr(BSP_GPIO_BUZZ_OUT_PORT,BSP_GPI0_BUZZ_OUT);

#else

#define OpenBuzz()           		  CSP_GPIO_BitClr(BSP_GPIO_BUZZ_OUT_PORT,BSP_GPI0_BUZZ_OUT);
#define CloseBuzz()          		  CSP_GPIO_BitSet(BSP_GPIO_BUZZ_OUT_PORT,BSP_GPI0_BUZZ_OUT);

#endif


/*******************************************************************************************************
** 函数名称: BuzzInit
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
void BuzzInit(void)
{
  CSP_GPIO_Cfg(BSP_GPIO_BUZZ_OUT_PORT,
               BSP_GPI0_BUZZ_OUT,
               CSP_GPIO_DIR_OUT,
               CSP_GPIO_FLAG_MODE_NONE,
               DEF_NO,
               0u,
               CSP_GPIO_FNCT_00);
  CloseBuzz();  
  g_usrBuzz.ucPrior=0;
  BuzzSet(1,3,3,0);
}

/*******************************************************************************************************
** 函数名称: BuzzSet
** 功能描述:
** 输 　 入: ucTimes=0为常响
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
void BuzzSet(INT8U ucTimes,INT8U ucKFrequence,INT8U ucGFrequence,INT8U ucPrior)
{
  if(g_usrBuzz.ucPrior<=ucPrior){
    g_usrBuzz.ucTimes=ucTimes;
    g_usrBuzz.ucKFrequence=ucKFrequence;
    g_usrBuzz.ucGFrequence=ucGFrequence;
    g_usrBuzz.ucKCurrent=ucKFrequence;
    g_usrBuzz.ucGCurrent=ucGFrequence;
    g_usrBuzz.ucPrior=ucPrior;
  }
}

/*******************************************************************************************************
** 函数名称: Buzz_Process
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
void Buzz_Process(void)
{
  if(g_usrBuzz.ucKCurrent!=0){
    g_usrBuzz.ucKCurrent--;
    OpenBuzz();
  }else if(g_usrBuzz.ucGCurrent!=0){
    g_usrBuzz.ucGCurrent--;
    CloseBuzz();
  }else{
    if(g_usrBuzz.ucTimes>=2){
      g_usrBuzz.ucTimes--;
      g_usrBuzz.ucGCurrent=g_usrBuzz.ucGFrequence;
      g_usrBuzz.ucKCurrent=g_usrBuzz.ucKFrequence;
    }else if(g_usrBuzz.ucTimes==1){
      g_usrBuzz.ucPrior=0;      
      CloseBuzz();
    }else{
      g_usrBuzz.ucGCurrent=g_usrBuzz.ucGFrequence;
      g_usrBuzz.ucKCurrent=g_usrBuzz.ucKFrequence;
    }
   }
}


#endif

/*********************************************************************************************************
**                            End Of File
********************************************************************************************************/
