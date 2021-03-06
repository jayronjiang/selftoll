/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: Buzz.h
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

#ifdef   BUZZ_GLOBALS
#define  BUZZ_EXT
#else
#define  BUZZ_EXT  extern
#endif


/*******************************************************************************************************
*                                         Config Definition
*******************************************************************************************************/


#define BUZZ_POSITIVE_EN                      0

/*******************************************************************************************************
*                                         Register Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Hardware Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Constant Definition
*******************************************************************************************************/


//超时取卡
#define TAKEOUT_OVER_TIMES_DEFAULT              0x0A
#define TAKEOUT_OVER_KFREQ_DEFAULT              0x10
#define TAKEOUT_OVER_GFREQ_DEFAULT              0x10
#define TAKEOUT_OVER_PRIOR_DEFAULT              0x03

//收发卡状态错误
#define CARDSTATE_ERROR_TIMES_DEFAULT           0x14
#define CARDSTATE_ERROR_KFREQ_DEFAULT           0x10
#define CARDSTATE_ERROR_GFREQ_DEFAULT           0x10
#define CARDSTATE_ERROR_PRIOR_DEFAULT           0x09

//系统错误
#define SYSTEM_ERROR_TIMES_DEFAULT              0x05
#define SYSTEM_ERROR_KFREQ_DEFAULT              0x10
#define SYSTEM_ERROR_GFREQ_DEFAULT              0x10
#define SYSTEM_ERROR_PRIOR_DEFAULT              0x0A


#define BUZZ_FK_MIN_PRIOR			9
#define BUZZ_FK_ZERO_PRIOR			10
#define BUZZ_SK_MAX_PRIOR			9
#define BUZZ_SK_FULL_PRIOR			10
#define BUZZ_SK_FINISH_PRIOR			1

#define BUZZ_DMOTO_ERROR_PRIOR			18
#define BUZZ_SFK_ERROR_PRIOR			19
#define BUZZ_COUNT_WRITE_ERR_PRIOR		20


/*******************************************************************************************************
*                                         Type Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Data Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Macro Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Function Prototypes
*******************************************************************************************************/

#if BUZZ_EN>0

BUZZ_EXT void BuzzInit(void);

BUZZ_EXT void BuzzSet(INT8U ucTimes,INT8U ucKFrequence,INT8U ucGFrequence,INT8U ucPrior);

BUZZ_EXT void Buzz_Process(void);

#endif

/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/

