/*
*********************************************************************************************************
*                                              EXAMPLE CODE
*
*                          (c) Copyright 2003-2012; Micrium, Inc.; Weston, FL
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
*                                            EXAMPLE CODE
*
*                                             NXP LPC1768
*                                                on the
*                                     IAR LPC1768-SK Kickstart Kit
*
* Filename      : app.c
* Version       : V1.00
* Programmer(s) : FT
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include <includes.h>

/*
*********************************************************************************************************
*                                            LOCAL DEFINES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

static  OS_TCB           App_TaskStartTCB;
static  CPU_STK_SIZE     App_TaskStartStk[APP_CFG_TASK_START_STK_SIZE];

static  CPU_INT08U       m_ucUart[4]={0,1,2,3};

/*
*********************************************************************************************************
*                                      LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/

static  void  App_ObjCreate          (void);
static  void  App_TaskCreate         (void);
static  void  App_TaskStart          (void       *p_arg);


extern  CSP_INT_VECT  CSP_MainVectTbl[CSP_INT_SRC_NBR_MAX]; 

static void  App_TaskUartReceive    (void      *p_arg);
static void  App_TaskUartProcess    (void      *p_arg);
static void  App_TaskBox            (void      *p_arg);
static void  App_TaskLcd            (void      *p_arg);
static void  App_TaskBuzz           (void      *p_arg);
static void  App_TaskAction         (void      *p_arg);

#define OpenScan()           		  CSP_GPIO_BitClr(BSP_GPIO_SCAN_PORT,BSP_GPIO_SCAN_OUT);
#define CloseScan()           		  CSP_GPIO_BitSet(BSP_GPIO_SCAN_PORT,BSP_GPIO_SCAN_OUT);

/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will call
*               main() once you have performed all necessary initialization.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : This the main standard entry point.
*
* Note(s)     : none.
*********************************************************************************************************
*/

int  main (void)
{
    OS_ERR  err;

    CPU_Init();

    BSP_Init();                                                 /* Initialize BSP functions                             */
    
    GlobalInit();
    
    Mem_Init();

    OSInit(&err);                                               /* Initialize "uC/OS-III, The Real-Time Kernel"         */

    OSTaskCreate((OS_TCB     *)&App_TaskStartTCB,               /* Create the start task                                */
                 (CPU_CHAR   *)"App Task Start",
                 (OS_TASK_PTR ) App_TaskStart,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_START_PRIO,
                 (CPU_STK    *)&App_TaskStartStk[0],
                 (CPU_STK     )(APP_CFG_TASK_START_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_START_STK_SIZE,
                 (OS_MSG_QTY  ) 0,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
#if (OS_TASK_NAME_EN > 0u)
    OSTaskNameSet(APP_CFG_TASK_START_PRIO, "Start", &err);
#endif
    
    OSStart(&err);                                              /* Start multitasking (i.e. give control to uC/OS-III). */

    while(DEF_ON){				                /* Should Never Get Here							    */
    };
}

/*
*********************************************************************************************************
*                                          App_TaskStart()
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static  void  App_TaskStart (void *p_arg)
{

    (void)p_arg;                                                /* See Note #1                                          */

    
    BSP_Start();                                                /* Start BSP and tick initialization                    */

#if (OS_TASK_STAT_EN > 0)
    OSStatInit();                                               /* Determine CPU capacity                               */
#endif

#if (APP_CFG_SERIAL_EN == DEF_ENABLED)
    App_SerialInit();
#endif
    
    Box_Init();    
    
    App_ObjCreate();                                            /* Create Applicaiton kernel objects                    */

    App_TaskCreate();                                           /* Create Application tasks                             */

    BSP_LED_Off(1);
    BSP_LED_On(2);
    
    Key_Process();
}


/*
*********************************************************************************************************
*                                      App_ObjCreate()
*
* Description:  Creates the application kernel objects.
*
* Argument(s) :  none.
*
* Return(s)   :  none.
*
* Caller(s)   :  App_TaskStart().
*
* Note(s)     :  none.
*********************************************************************************************************
*/

static  void  App_ObjCreate (void)
{
}


/*
*********************************************************************************************************
*                                      App_TaskCreate()
*
* Description :  This function creates the application tasks.
*
* Argument(s) :  none.
*
* Return(s)   :  none.
*
* Caller(s)   :  App_TaskStart().
*
* Note(s)     :  none.
*********************************************************************************************************
*/

static  void  App_TaskCreate (void)
{
    OS_ERR  err;
    INT8U ucType=DEV_TYPE();
    
#if (APP_CFG_SERIAL_EN == DEF_ENABLED)
    OSTaskCreate((OS_TCB     *)&App_TaskUart0ReceiveTCB,              
               (CPU_CHAR   *)"Uart0 Rx",
               (OS_TASK_PTR ) App_TaskUartReceive,
               (void       *) &m_ucUart[0],
               (OS_PRIO     ) APP_CFG_TASK_UART0_RECEIVE_PRIO,
               (CPU_STK    *)&App_TaskUart0ReceiveStk[0],
               (CPU_STK     )(APP_CFG_TASK_UART0_RECEIVE_STK_SIZE / 10u),
               (CPU_STK_SIZE) APP_CFG_TASK_UART0_RECEIVE_STK_SIZE,
               (OS_MSG_QTY  ) 10,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
               (OS_ERR     *)&err);
     
    if(ucType!=SMALL_THICK_ZIN_TYPE && ucType!=SMALL_THIN_ZIN_TYPE){
      OSTaskCreate((OS_TCB     *)&App_TaskUart1ReceiveTCB,              
                 (CPU_CHAR   *)"Uart1 Receive",
                 (OS_TASK_PTR ) App_TaskUartReceive,
                 (void       *) &m_ucUart[1],
                 (OS_PRIO     ) APP_CFG_TASK_UART_RECEIVE_PRIO,
                 (CPU_STK    *)&App_TaskUart1ReceiveStk[0],
                 (CPU_STK     )(APP_CFG_TASK_UART_RECEIVE_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_UART_RECEIVE_STK_SIZE,
                 (OS_MSG_QTY  ) 10,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
    }else{
      ScanInit();
      CardBoxSetSelected(BOX_THIRD,BOX_POWER_ON_MODE);    
    }
      
    OSTaskCreate((OS_TCB     *)&App_TaskUart2ReceiveTCB,              
               (CPU_CHAR   *)"Uart2 Receive",
               (OS_TASK_PTR ) App_TaskUartReceive,
               (void       *) &m_ucUart[2],
               (OS_PRIO     ) APP_CFG_TASK_UART_RECEIVE_PRIO,
               (CPU_STK    *)&App_TaskUart2ReceiveStk[0],
               (CPU_STK     )(APP_CFG_TASK_UART_RECEIVE_STK_SIZE / 10u),
               (CPU_STK_SIZE) APP_CFG_TASK_UART_RECEIVE_STK_SIZE,
               (OS_MSG_QTY  ) 10,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
               (OS_ERR     *)&err);
      
    OSTaskCreate((OS_TCB     *)&App_TaskUart3ReceiveTCB,              
               (CPU_CHAR   *)"Uart3 Receive",
               (OS_TASK_PTR ) App_TaskUartReceive,
               (void       *) &m_ucUart[3],
               (OS_PRIO     ) APP_CFG_TASK_UART_RECEIVE_PRIO,
               (CPU_STK    *)&App_TaskUart3ReceiveStk[0],
               (CPU_STK     )(APP_CFG_TASK_UART_RECEIVE_STK_SIZE / 10u),
               (CPU_STK_SIZE) APP_CFG_TASK_UART_RECEIVE_STK_SIZE,
               (OS_MSG_QTY  ) 10,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
               (OS_ERR     *)&err);
    
    OSTaskCreate((OS_TCB     *)&App_TaskUartProcessTCB,              
               (CPU_CHAR   *)"Uart3 Process",
               (OS_TASK_PTR ) App_TaskUartProcess,
               (void       *) 0,
               (OS_PRIO     ) APP_CFG_TASK_UART_PROCESS_PRIO,
               (CPU_STK    *)&App_TaskUartProcessStk[0],
               (CPU_STK     )(APP_CFG_TASK_UART_PROCESS_STK_SIZE / 10u),
               (CPU_STK_SIZE) APP_CFG_TASK_UART_PROCESS_STK_SIZE,
               (OS_MSG_QTY  ) 10,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
               (OS_ERR     *)&err);
#endif    
    
    //BOX
    if(ucType!=SMALL_THICK_ZIN_TYPE && ucType!=SMALL_THIN_ZIN_TYPE){
      OSTaskCreate((OS_TCB     *)&App_TaskBoxTCB,              
                 (CPU_CHAR   *)"Box",
                 (OS_TASK_PTR ) App_TaskBox,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_BOX_PRIO,
                 (CPU_STK    *)&App_TaskBoxStk[0],
                 (CPU_STK     )(APP_CFG_TASK_BOX_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_BOX_STK_SIZE,
                 (OS_MSG_QTY  ) 10,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
    }
    
    //LCD
    if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_OUT_TYPE || ucType==SMALL_THICK_GIN_TYPE || ucType==SMALL_THIN_IN_TYPE || ucType==SMALL_THIN_OUT_TYPE || ucType==SMALL_THIN_GIN_TYPE){
      OSTaskCreate((OS_TCB     *)&App_TaskLcdTCB,              
                 (CPU_CHAR   *)"Lcd",
                 (OS_TASK_PTR ) App_TaskLcd,
                 (void       *) 0,
                 (OS_PRIO     ) APP_CFG_TASK_LCD_PRIO,
                 (CPU_STK    *)&App_TaskLcdStk[0],
                 (CPU_STK     )(APP_CFG_TASK_LCD_STK_SIZE / 10u),
                 (CPU_STK_SIZE) APP_CFG_TASK_LCD_STK_SIZE,
                 (OS_MSG_QTY  ) 10,
                 (OS_TICK     ) 0,
                 (void       *) 0,
                 (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
                 (OS_ERR     *)&err);
    }

    //BUZZ
    OSTaskCreate((OS_TCB     *)&App_TaskBuzzTCB,              
               (CPU_CHAR   *)"Buzz",
               (OS_TASK_PTR ) App_TaskBuzz,
               (void       *) 0,
               (OS_PRIO     ) APP_CFG_TASK_BUZZ_PRIO,
               (CPU_STK    *)&App_TaskBuzzStk[0],
               (CPU_STK     )(APP_CFG_TASK_BUZZ_STK_SIZE / 10u),
               (CPU_STK_SIZE) APP_CFG_TASK_BUZZ_STK_SIZE,
               (OS_MSG_QTY  ) 10,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
               (OS_ERR     *)&err);
    

    //ACTION
    OSTaskCreate((OS_TCB     *)&App_TaskActionTCB,              
               (CPU_CHAR   *)"Action",
               (OS_TASK_PTR ) App_TaskAction,
               (void       *) 0,
               (OS_PRIO     ) APP_CFG_TASK_ACTION_PRIO,
               (CPU_STK    *)&App_TaskActionStk[0],
               (CPU_STK     )(APP_CFG_TASK_ACTION_STK_SIZE / 10u),
               (CPU_STK_SIZE) APP_CFG_TASK_ACTION_STK_SIZE,
               (OS_MSG_QTY  ) 1,
               (OS_TICK     ) 0,
               (void       *) 0,
               (OS_OPT      )(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
               (OS_ERR     *)&err);
    
}

/*
*********************************************************************************************************
*                                          Uart_TaskStart()
*
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/

static void  App_TaskUartReceive (void *p_arg)
{
  Uart_Receive(p_arg);
}

/*
*********************************************************************************************************
*                                          App_TaskUartProcess()
*v
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/
static  void  App_TaskUartProcess (void *p_arg)
{
  while(DEF_TRUE){
    Uart_Process();
  }
}

/*
*********************************************************************************************************
*                                          App_TaskBoxProcess()
*v
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/
static  void  App_TaskBox (void *p_arg)
{
  Box_Process();
}

/*
*********************************************************************************************************
*                                          App_TaskLcdProcess()
*v
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/
static  void  App_TaskLcd (void *p_arg)
{
  Lcd_Process();
}

/*
*********************************************************************************************************
*                                          App_TaskBuzzProcess()
*v
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/
static  void  App_TaskBuzz (void *p_arg)
{
  static INT8U ucLedErrTimes=0;
  static INT8U ucLedTimes=0;
  static INT8U ucTimes=0;
    
  while(DEF_TRUE){
    if(++ucTimes>100){
      ucTimes=0;
      BSP_LED_Toggle(1);
    }
    
    if(++ucLedTimes>50){
      ucLedTimes=0;
      if(g_ucLedMode==LEDOUT_ON_MODE){
        BSP_LED_On(3);
      }else if(g_ucLedMode==LEDOUT_TOGGLE_MODE){
        BSP_LED_Toggle(3);
      }else{
        BSP_LED_Off(3);
      }
    }
    
    if(++ucLedErrTimes>20){
      ucLedErrTimes=0;
      if(g_ucLedErrMode==LEDOUT_ON_MODE){
        BSP_LED_On(2);
      }else if(g_ucLedErrMode==LEDOUT_TOGGLE_MODE){
        BSP_LED_Toggle(2);
      }else{
        BSP_LED_Off(2);
      }
    }

  #if SCAN_EN==1
    if(g_usrScan.bEnabled){
      if(g_usrScan.b14Times>0){
        g_usrScan.b14Times--;
      }else{
        if(g_usrScan.bMode==SCAN_OPEN_MODE){
          //开模式
          CloseScan();
          g_usrScan.bMode=SCAN_CLOSE_MODE;
          g_usrScan.b14Times=g_ucScanCloseTime;
        }else{
          //关模式
          OpenScan();
          g_usrScan.bMode=SCAN_OPEN_MODE;
          g_usrScan.b14Times=g_ucScanOpenTime;
        }
      }
    }
  #endif    
    
    BSP_OS_TimeDlyMs(10);    
    Buzz_Process();
    
  }
}

/*
*********************************************************************************************************
*                                          App_TaskActionProcess()
*v
* Description : This is an example of a startup task.  As mentioned in the book's text, you MUST
*               initialize the ticker only once multitasking has started.
*
* Argument(s) : p_arg   is the argument passed to 'App_TaskStart()' by 'OSTaskCreate()'.
*
* Return(s)   : none.
*
* Caller(s)   : This is a task.
*
* Notes       : (1) The first line of code is used to prevent a compiler warning because 'p_arg' is not
*                   used.  The compiler should not generate any code for this statement.
*********************************************************************************************************
*/
static  void  App_TaskAction (void *p_arg)
{
  Action_Process();
}

