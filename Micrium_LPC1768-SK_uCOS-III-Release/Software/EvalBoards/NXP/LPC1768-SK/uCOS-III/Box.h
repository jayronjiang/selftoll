/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------???tD??￠---------------------------------------------------------------------------------
*??   ?t   ??: Key.h
*′′   ?¨   è?: John Tonny
*×?oóDT??è??ú: 2009?ê1??01è?
*?è        ê?:
*
*--------------àúê·°?±?D??￠-----------------------------------------------------------------------------
* ′′?¨è?: John Tonny
* °?  ±?: V1.0
* è????ú: 2009?ê1??01è?
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

#ifdef   BOX_GLOBALS
#define  BOX_EXT
#else
#define  BOX_EXT  extern
#endif

/*******************************************************************************************************
*                                         Config Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Register Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Hardware Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Constant Definition
*******************************************************************************************************/

#define CARDMACHINE_SMALL_IN_TYPE		0x01
#define CARDMACHINE_SMALL_OUT_TYPE		0x02
#define CARDMACHINE_LARGE_OUT_TYPE		0x02

#define BOX_CONNECT_TIME_DEFAULT                250                             //定时连接卡夹时间

#define BOX_CONNECTING_MSG                      0x01                            //卡夹连接
#define BOX_PLUGIN_MSG                          0x02                            //插入卡片
#define BOX_TAKEOUT_MSG                         0x03                            //拔出卡片
#define BOX_UART_SEND_MSG                       0x04                            //发送数据


/*******************************************************************************************************
*                                         Type Definition
*******************************************************************************************************/



/*******************************************************************************************************
*                                         Data Definition
*******************************************************************************************************/

BOX_EXT MEM_POOL                  m_BoxPool;
BOX_EXT BSP_OS_SEM                *g_pActionSem;
BOX_EXT BSP_OS_SEM                *g_pSMotoSem;
BOX_EXT BSP_OS_SEM                *g_pDMotoSem;

/*******************************************************************************************************
*                                         Macro Definition
*******************************************************************************************************/



/*******************************************************************************************************
*                                         Function Prototypes
*******************************************************************************************************/

BOX_EXT CPU_BOOLEAN Box_Init(void);
BOX_EXT void Box_Process(void);

BOX_EXT void CardBoxConnectEvent(void);
BOX_EXT void CardBoxCountEvent(void);

BOX_EXT void CardBoxConnectCountEvent(void);

BOX_EXT void CardBoxBasicInfoSend(INT8U ucMode,INT8U ucSelected);
BOX_EXT void CardCountUpdateSend(INT8U ucMode,INT8U ucSelected);
BOX_EXT void BoxMotoMoveDown(INT16U uiCount,INT8U ucSelected);

BOX_EXT void CardBoxInfoReset(INT8U ucSelected); 
BOX_EXT void CardBoxConnectReset(INT8U ucSelected);
BOX_EXT void CardBoxCountReset(INT8U ucSelected);
BOX_EXT void CardBoxPosReset(INT8U ucSelected);

BOX_EXT void BoxConnected(INT8U ucSelected);

BOX_EXT void BoxLoadEvent(INT8U ucSelected);
BOX_EXT void BoxUnloadEvent(INT8U ucSelected);
BOX_EXT INT8U BOXLOAD_VALID(INT8U ucSelected);

BOX_EXT INT8U BoxPostMsg(INT8U *pucData,INT8U ucLen);


/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/

