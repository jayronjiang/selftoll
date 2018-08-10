/*
*********************************************************************************************************
*                                               uC/PROBE
*
*                          (c) Copyright 2003-2009; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*               Knowledge of the source code may NOT be used to develop a similar product.
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                               uC/Serial
*                                           Application Code
*
* Filename      : app_serial.h
* Version       : V1.00
* Programmer(s) : FT
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                                 MODULE
*
* Note(s) : (1) This header file is protected from multiple pre-processor inclusion through use of the
*               APP_SERIAL_MODULE_PRESENT present pre-processor macro definition.
*********************************************************************************************************
*/

#ifndef  APP_SERIAL_MODULE_PRESENT                              /* See Note #1.                                         */
#define  APP_SERIAL_MODULE_PRESENT


/*
*********************************************************************************************************
*                                              INCLUDE FILES
*********************************************************************************************************
*/

#include <os.h>

#include  <lib_def.h>

#include  <cpu.h>

#include  <app_cfg.h>


/*
*********************************************************************************************************
*                                                 EXTERNS
*********************************************************************************************************
*/

#ifdef   APP_SERIAL_MODULE
#define  APP_SERIAL_MODULE_EXT
#else
#define  APP_SERIAL_MODULE_EXT  extern
#endif

/*
*********************************************************************************************************
*                                        DEFAULT CONFIGURATION
*********************************************************************************************************
*/

#ifndef  APP_CFG_SERIAL_EN                   
#define  APP_CFG_SERIAL_EN                   DEF_DISABLED  
#endif

#ifndef  APP_SERIAL_CFG_TRACE_EN
#define  APP_SERIAL_CFG_TRACE_EN             DEF_DISABLED
#endif


/*
*********************************************************************************************************
*                                      CONDITIONAL INCLUDE FILES
*********************************************************************************************************
*/


#if (APP_CFG_SERIAL_EN == DEF_ENABLED)
#include  <serial.h>
#include  <serial_bsp_lpc17xx.h>
#endif

#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)
#include  <stdarg.h>
#include  <lib_str.h>
#include  <serial_line_tty.h>
#endif


/*
*********************************************************************************************************
*                                                 DEFINES
*********************************************************************************************************
*/




/*
*********************************************************************************************************
*                                               DATA TYPES
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                            GLOBAL VARIABLES
*********************************************************************************************************
*/

#if (APP_CFG_SERIAL_EN == DEF_ENABLED)

APP_SERIAL_MODULE_EXT MEM_POOL                  m_UartBufPool;

APP_SERIAL_MODULE_EXT SERIAL_IF_NBR             Uart_SerTraceIF_Nbr[4];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskUart0ReceiveTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskUart0ReceiveStk[APP_CFG_TASK_UART0_RECEIVE_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskUart1ReceiveTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskUart1ReceiveStk[APP_CFG_TASK_UART_RECEIVE_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskUart2ReceiveTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskUart2ReceiveStk[APP_CFG_TASK_UART_RECEIVE_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskUart3ReceiveTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskUart3ReceiveStk[APP_CFG_TASK_UART_RECEIVE_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskUartProcessTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskUartProcessStk[APP_CFG_TASK_UART_PROCESS_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskBoxTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskBoxStk[APP_CFG_TASK_BOX_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskLcdTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskLcdStk[APP_CFG_TASK_LCD_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskBuzzTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskBuzzStk[APP_CFG_TASK_BUZZ_STK_SIZE];

APP_SERIAL_MODULE_EXT OS_TCB                    App_TaskActionTCB;
APP_SERIAL_MODULE_EXT CPU_STK_SIZE              App_TaskActionStk[APP_CFG_TASK_ACTION_STK_SIZE];

#endif



/*
*********************************************************************************************************
*                                                 MACRO'S
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

#if (APP_CFG_SERIAL_EN == DEF_ENABLED)
CPU_BOOLEAN  App_SerialInit (void);

#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)  
void         App_SerPrintf  (CPU_CHAR *format, ...);
void         App_SerStrRd   (CPU_CHAR   *p_str,
                             CPU_SIZE_T  len);
#endif


APP_SERIAL_MODULE_EXT void  Uart_Receive  (void *p_arg);

APP_SERIAL_MODULE_EXT void  Uart0Receive  (CPU_INT08U ucMode);
APP_SERIAL_MODULE_EXT void  UartReceive   (CPU_INT08U ucMode);

APP_SERIAL_MODULE_EXT void  Uart_Process   (void);


APP_SERIAL_MODULE_EXT void  Uart_SerStrRd  (SERIAL_IF_NBR  if_nbr,
                                            CPU_CHAR   *p_str,
                                            CPU_SIZE_T  len,
                                            CPU_INT32U  timeout_ms,
                                            SERIAL_ERR *perr);

APP_SERIAL_MODULE_EXT void  Uart_SerStrWr  (SERIAL_IF_NBR  if_nbr,
                                            CPU_CHAR   *p_str,
                                            CPU_SIZE_T  len,
                                            SERIAL_ERR *perr);

APP_SERIAL_MODULE_EXT void  Uart0Pack       (CPU_INT08U ucCmd,
                                            CPU_INT08U ucAddr,
                                            CPU_INT08U ucSeq,
                                            CPU_INT08U *pucData,
                                            CPU_INT08U ucLen,
                                            CPU_INT08U ucMode);

APP_SERIAL_MODULE_EXT void UartPack         (INT8U ucCmd,
                                            INT8U ucResponse,
                                            INT8U ucLen,
                                            INT8U *pucData,
                                            INT8U ucSelected);

APP_SERIAL_MODULE_EXT void Uart0UnPack      (CPU_INT08U ucMode);
APP_SERIAL_MODULE_EXT void UartUnPack       (CPU_INT08U ucMode);
APP_SERIAL_MODULE_EXT void Uart1UnPack       (CPU_INT08U ucMode);
APP_SERIAL_MODULE_EXT void Uart3UnPack       (CPU_INT08U ucMode);


APP_SERIAL_MODULE_EXT void  UartProcess    (CPU_CHAR *pMsg,
                              OS_MSG_SIZE msgSize);

APP_SERIAL_MODULE_EXT void  Uart0Process   (CPU_CHAR *pMsg,
                              OS_MSG_SIZE msgSize);
                      
APP_SERIAL_MODULE_EXT void UartTxFinish(SERIAL_IF_NBR if_nbr,void *p_arg,void *p_buf,CPU_SIZE_T wr_len,SERIAL_ERR err);

APP_SERIAL_MODULE_EXT void UltraSoundSend(INT8U ucStatus);

#endif

/*
*********************************************************************************************************
*                                          CONFIGURATION ERRORS
*********************************************************************************************************
*/

#ifndef  APP_CFG_SERIAL_EN
#error  "APP_CFG_SERIAL_EN                              not #define'd in 'app_cfg.h'     "
#error  "                                   [MUST be  DEF_DISABLED]                      "
#error  "                                   [     ||  DEF_ENABLED ]                      "

#elif  ((APP_CFG_SERIAL_EN != DEF_DISABLED) && \
        (APP_CFG_SERIAL_EN != DEF_ENABLED ))
#error  "APP_CFG_SERIAL_EN                        illegally #define'd in 'app_cfg.h'     "
#error  "                                   [MUST be  DEF_DISABLED]                      "
#error  "                                   [     ||  DEF_ENABLED ]                      "

#elif  (APP_CFG_SERIAL_EN == DEF_ENABLED)
#ifndef  APP_SERIAL_CFG_TRACE_EN
#error  "APP_SERIAL_CFG_TRACE_EN                        not #define'd in 'app_cfg.h'     "
#error  "                                   [MUST be  DEF_DISABLED]                      "
#error  "                                   [     ||  DEF_ENABLED ]                      "

#elif  ((APP_SERIAL_CFG_TRACE_EN != DEF_DISABLED) && \
        (APP_SERIAL_CFG_TRACE_EN != DEF_ENABLED ))
#error  "APP_SERIAL_CFG_TRACE_EN                  illegally #define'd in 'app_cfg.h'     "
#error  "                                   [MUST be  DEF_DISABLED]                      "
#error  "                                   [     ||  DEF_ENABLED ]                      "

#elif  (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)
#if    !defined(APP_SERIAL_CFG_TRACE_PORT_NAME)
#error  "APP_SERIAL_CFG_TRACE_PORT_NAME                 not #define'd in 'app_cfg.h'     "
#endif
#endif
#endif


/*
*********************************************************************************************************
*                                              MODULE END
*
* Note(s) : See 'MODULE  Note #1'.
*********************************************************************************************************
*/

#endif                                                          /* End of APP_SERIAL_MODULE_PRESENT module include ...  */
                                                                /* ... (see Note #1).                                   */
