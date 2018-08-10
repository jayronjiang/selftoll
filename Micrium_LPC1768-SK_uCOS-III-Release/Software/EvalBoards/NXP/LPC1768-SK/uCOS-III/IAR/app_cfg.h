/*
*********************************************************************************************************
*                                              uC/OS-III
*                                        The Real-Time Kernel
*
*                          (c) Copyright 2004-2012; Micrium, Inc.; Weston, FL
*
*               All rights reserved.  Protected by international copyright laws.
*
*               uC/OS-III is provided in source form for FREE evaluation, for educational
*               use or peaceful research.  If you plan on using uC/OS-III in a commercial
*               product you need to contact Micrium to properly license its use in your
*               product.  We provide ALL the source code for your convenience and to
*               help you experience uC/OS-III.  The fact that the source code is provided
*               does NOT mean that you can use it without paying a licensing fee.
*
*               Knowledge of the source code may NOT be used to develop a similar product.
*
*               Please help us continue to provide the Embedded community with the finest
*               software available.  Your honesty is greatly appreciated.
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*
*                                       APPLICATION CONFIGURATION
*
*                                             NXP LPC1768
*                                                on the
*                                     IAR LPC1768-SK Kickstart Kit
*
*
* Filename      : app_cfg.h
* Version       : V1.00
* Programmer(s) : FT
*                 DC
*********************************************************************************************************
*/

#ifndef  APP_CFG_MODULE_PRESENT
#define  APP_CFG_MODULE_PRESENT


/*
*********************************************************************************************************
*                                       ADDITIONAL uC/MODULE ENABLES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                            TASK PRIORITIES
*********************************************************************************************************
*/

#define  APP_CFG_TASK_UART0_RECEIVE_PRIO                 10u
#define  APP_CFG_TASK_UART_RECEIVE_PRIO                  11u
#define  APP_CFG_TASK_UART0_PROCESS_PRIO                 12u
#define  APP_CFG_TASK_UART_PROCESS_PRIO                  13u
#define  APP_CFG_TASK_BOX_PRIO                           14u
#define  APP_CFG_TASK_LCD_PRIO                           15u
#define  APP_CFG_TASK_BUZZ_PRIO                          16u
#define  APP_CFG_TASK_ACTION_PRIO                        9u


#define  APP_CFG_TASK_START_PRIO                         2u
#define  APP_CFG_TASK_JOY_PRIO                           11u


#define  OS_TASK_TMR_PRIO                                (OS_LOWEST_PRIO - 2)


/*
*********************************************************************************************************
*                                            TASK STACK SIZES
*********************************************************************************************************
*/

#define  APP_CFG_TASK_START_STK_SIZE                     192u

#define  APP_CFG_TASK_UART0_RECEIVE_STK_SIZE             128u
#define  APP_CFG_TASK_UART_RECEIVE_STK_SIZE              128u
#define  APP_CFG_TASK_UART_PROCESS_STK_SIZE              128u

#define  APP_CFG_TASK_BOX_STK_SIZE                       128u
#define  APP_CFG_TASK_LCD_STK_SIZE                       128u
#define  APP_CFG_TASK_BUZZ_STK_SIZE                      128u
#define  APP_CFG_TASK_ACTION_STK_SIZE                    128u


/*
*********************************************************************************************************
*                                             uC/LIB CONFIGURATION
*********************************************************************************************************
*/

#define  LIB_MEM_CFG_OPTIMIZE_ASM_EN                    DEF_ENABLED
#define  LIB_MEM_CFG_ARG_CHK_EXT_EN                     DEF_ENABLED
#define  LIB_MEM_CFG_ALLOC_EN                           DEF_ENABLED
#define  LIB_MEM_CFG_HEAP_SIZE                          8*1024u


/*
*********************************************************************************************************
*                                               SERIAL
*
* Note(s) : (1) Configure SERIAL_CFG_MAX_NBR_IF to the number of interfaces (i.e., UARTs) that will be
*               present.
*
*           (2) Configure SERIAL_CFG_RD_BUF_EN to enable/disable read buffer functionality.  The serial
*               core stores received data in the read buffer until the user requests it, providing a
*               reliable guarantee against receive overrun.
*
*           (3) Configure SERIAL_CFG_WR_BUF_EN to enable/disable write buffer functionality.  The serial
*               core stores line driver transmit data in the write buffer while the serial interface is
*               transmitting application data.
*
*           (4) Configure SERIAL_CFG_ARG_CHK_EXT_EN to enable/disable extended argument checking
*               functionality.
*
*           (5) Configure SERIAL_CFG_TX_DESC_NBR to allow multiple transmit operations (i.e., Serial_Wr,
*               Serial_WrAsync) to be queued.
*********************************************************************************************************
*/


#define  SERIAL_CFG_MAX_NBR_IF                             4    /* See Note #1.                                         */

#define SERIAL_CFG_RD_BUF_EN                    DEF_ENABLED
//#define  SERIAL_CFG_RD_BUF_EN                    DEF_DISABLED   /* See Note #2.                                         */

#define  SERIAL_CFG_WR_BUF_EN                    DEF_ENABLED   /* See Note #3.                                         */
//#define  SERIAL_CFG_WR_BUF_EN                    DEF_DISABLED   /* See Note #3.                                         */

#define  SERIAL_CFG_ARG_CHK_EXT_EN               DEF_DISABLED   /* See Note #4.                                         */

#define  SERIAL_CFG_TX_DESC_NBR                            10    /* See Note #5.                                         */


/*
*********************************************************************************************************
*                                    uC/SERIAL APPLICATION CONFIGURATION
*********************************************************************************************************
*/

#define  APP_CFG_SERIAL_EN                      DEF_ENABLED
#define  APP_SERIAL_CFG_TRACE_EN                DEF_DISABLED
#define  APP_SERIAL_CFG_TRACE_PORT_NAME         "UART0"

/*
*********************************************************************************************************
*                                     TRACE / DEBUG CONFIGURATION
*********************************************************************************************************
*/

#define  TRACE_LEVEL_OFF                                  0u
#define  TRACE_LEVEL_INFO                                 1u
#define  TRACE_LEVEL_DBG                                  2u

#define  APP_CFG_TRACE_LEVEL                    TRACE_LEVEL_DBG
#define  APP_CFG_TRACE                          printf

#define  APP_TRACE_INFO(x)                     ((APP_CFG_TRACE_LEVEL >= TRACE_LEVEL_INFO)  ? (void)(APP_CFG_TRACE x) : (void)0)
#define  APP_TRACE_DBG(x)                      ((APP_CFG_TRACE_LEVEL >= TRACE_LEVEL_DBG)   ? (void)(APP_CFG_TRACE x) : (void)0)



#endif
