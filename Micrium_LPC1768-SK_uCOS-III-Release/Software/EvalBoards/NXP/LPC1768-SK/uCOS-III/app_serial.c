/*
*********************************************************************************************************
*                                              EXAMPLE CODE
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
*                                           uC/Serial
*                                        Application Code
*
* Filename      : app_serial.c
* Version       : V1.00
* Programmer(s) : FT
*********************************************************************************************************
*/

/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/


#define  APP_SERIAL_MODULE
#include <app_serial.h>
#include <Global.h>
#include <Hpi.h>
#include <key.h>
#include <Moto.h>
#include <I2c.h>
#include <I2C24C02.H>
#include <bsp_os.h>
#include <csp.h>


//#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)
#include <stdio.h>
//#endif

#define OpenScan()           		  CSP_GPIO_BitClr(BSP_GPIO_SCAN_PORT,BSP_GPIO_SCAN_OUT);
#define CloseScan()           		  CSP_GPIO_BitSet(BSP_GPIO_SCAN_PORT,BSP_GPIO_SCAN_OUT);

/*
*********************************************************************************************************
*                                                 ENABLE
*********************************************************************************************************
*/

#if (APP_CFG_SERIAL_EN == DEF_ENABLED)

#define UART0_MODE      0

#define ULTRASOUND_EN   1

/*
*********************************************************************************************************
*                                       LOCAL GLOBAL VARIABLES
*********************************************************************************************************
*/

#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)
static  SERIAL_IF_NBR    App_SerTraceIF_Nbr;
#endif

static SERIAL_IF_NBR     Uart_SerTraceIF_Nbr[4];

extern BSP_OS_SEM                *g_pActionSem;

static INT8U m_ucBoxToUart[3]={2,1,3};
static INT8U m_ucUartToBox[3]={1,0,2};

/*
*********************************************************************************************************
*                                          FUNCTION PROTOTYPES
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                    LOCAL CONFIGURATION ERRORS
*********************************************************************************************************
*/


/*
*********************************************************************************************************
*                                         App_SerialInit()
*
* Description : Initialize Serial module
*
* Argument(s) : none.
*
* Caller(s)   : Application
*
* Return(s)   : none.
*
* Note(s)     : none.
*********************************************************************************************************
*/

CPU_BOOLEAN  App_SerialInit (void)
{
    SERIAL_ERR     err;
#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)  
    SERIAL_IF_CFG  uart_cfg;
#endif

    CPU_SIZE_T      octets_reqd;
    LIB_ERR         lib_err;
    
    INT8U ucType=DEV_TYPE();
    
    CPU_SR_ALLOC();
    
    CPU_CRITICAL_ENTER();
    Mem_PoolCreate((MEM_POOL   *)&m_UartBufPool,
                   (void       *) 0,
                   (CPU_SIZE_T  ) 0,
                   (CPU_SIZE_T  ) 20,
                   (CPU_SIZE_T  ) 64,
                   (CPU_SIZE_T  ) 1,
                   (CPU_SIZE_T *)&octets_reqd,
                   (LIB_ERR    *)&lib_err);
    
    if (lib_err != LIB_MEM_ERR_NONE) {
        CPU_CRITICAL_EXIT();
        return (DEF_FAIL);    
    }
    CPU_CRITICAL_EXIT();
        
    Serial_Init();                                              /* Initial Serial module                                */

    Serial_DevDrvAdd(                  "UART0",                 /* Add serial interface/device.                         */
                     (SERIAL_DEV_CFG *)&SerialDev_LPCxxxx_UART0,
                                        128u,
                                        128u,
                                       &err);
    
    if (err != SERIAL_ERR_NONE) {
        return (DEF_FAIL);    
    }
    
    if(ucType!=SMALL_THICK_ZIN_TYPE && ucType!=SMALL_THIN_ZIN_TYPE){
      Serial_DevDrvAdd(                  "UART1",                 /* Add serial interface/device.                         */
                       (SERIAL_DEV_CFG *)&SerialDev_LPCxxxx_UART1_Alt,
                                          128u,
                                          128u,
                                         &err);
      
      if (err != SERIAL_ERR_NONE) {
          return (DEF_FAIL);    
      }
    }
     
    Serial_DevDrvAdd(                  "UART2",                 /* Add serial interface/device.                         */
                     (SERIAL_DEV_CFG *)&SerialDev_LPCxxxx_UART2,
                                        128u,
                                        128u,
                                       &err);
    
    if (err != SERIAL_ERR_NONE) {
        return (DEF_FAIL);    
    }

    Serial_DevDrvAdd(                  "UART3",                 /* Add serial interface/device.                         */
                     (SERIAL_DEV_CFG *)&SerialDev_LPCxxxx_UART3_Alt1,
                                        128u,
                                        128u,
                                       &err);
    
    if (err != SERIAL_ERR_NONE) {
        return (DEF_FAIL);    
    }
    
#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)    
    uart_cfg.Baudrate = SERIAL_BAUDRATE_115200;
    uart_cfg.DataBits = SERIAL_DATABITS_8;
    uart_cfg.StopBits = SERIAL_STOPBITS_1;
    uart_cfg.Parity   = SERIAL_PARITY_NONE;
    uart_cfg.FlowCtrl = SERIAL_FLOW_CTRL_NONE;

    App_SerTraceIF_Nbr = Serial_Open((CPU_CHAR      *)APP_SERIAL_CFG_TRACE_PORT_NAME,
                                     (SERIAL_IF_CFG *)&uart_cfg,
                                     (SERIAL_ERR    *)&err);
    if (err != SERIAL_ERR_NONE) {
        return (DEF_FAIL);
    }
    
    Serial_SetLineDrv((SERIAL_IF_NBR        ) App_SerTraceIF_Nbr,
                      (SERIAL_LINE_DRV_API *)&SerialLine_TTY ,
                      (SERIAL_ERR          *)&err);  
    if (err != SERIAL_ERR_NONE) {
        return (DEF_FAIL);
    }
#endif    

    return (DEF_OK);    
}

/**********************************************************************************************************
*                                           Uart_Receive()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void Uart_Receive(void *p_arg)
{
  CPU_INT08U ucMode=*((CPU_INT08U *)p_arg);
    
  if(ucMode==0){
    Uart0Receive(ucMode);
  }else if(ucMode>=1 && ucMode<=3){
    UartReceive(ucMode);
  }      
}

/**********************************************************************************************************
*                                           Uart0Receive()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void  Uart0Receive  (CPU_INT08U ucMode)
{
  SERIAL_ERR     err;
  SERIAL_IF_CFG  uart_cfg;
  
  uart_cfg.Baudrate = SERIAL_BAUDRATE_9600;
  uart_cfg.DataBits = SERIAL_DATABITS_8;
  uart_cfg.StopBits = SERIAL_STOPBITS_1;
  uart_cfg.Parity   = SERIAL_PARITY_NONE;
  uart_cfg.FlowCtrl = SERIAL_FLOW_CTRL_NONE;
  Uart_SerTraceIF_Nbr[0] = Serial_Open((CPU_CHAR      *)"UART0",
                                   (SERIAL_IF_CFG *)&uart_cfg,
                                   (SERIAL_ERR    *)&err);
  if (err != SERIAL_ERR_NONE) {
    return ;
  }
      
#if UART0_MODE==0
  Uart0UnPack(ucMode);
#else
  UartUnPack(ucMode);
#endif    
}

/**********************************************************************************************************
*                                           UartReceive()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void  UartReceive  (CPU_INT08U ucMode)
{ 
  SERIAL_ERR     err;
  SERIAL_IF_CFG  uart_cfg;
  
  CPU_CHAR       ucName[3][8]={"UART1","UART2","UART3"};
  
  m_ucMachineAddr=0x40;

  uart_cfg.Baudrate = SERIAL_BAUDRATE_9600;
  uart_cfg.DataBits = SERIAL_DATABITS_8;
  uart_cfg.StopBits = SERIAL_STOPBITS_1;
  uart_cfg.Parity   = SERIAL_PARITY_NONE;
  uart_cfg.FlowCtrl = SERIAL_FLOW_CTRL_NONE;
  if(ucMode==0 && ucMode>3){
    return;
  }
  Uart_SerTraceIF_Nbr[ucMode] = Serial_Open((CPU_CHAR      *)&ucName[ucMode-1],
                                 (SERIAL_IF_CFG *)&uart_cfg,
                                 (SERIAL_ERR    *)&err);
  if (err != SERIAL_ERR_NONE) {
    return ;
  }

  if(ucMode==1){
    Uart1UnPack(ucMode);
  }else if(ucMode==2){
    Uart1UnPack(ucMode);
  }else if(ucMode==3){
#if BOARD_OLD_EN==0     

#if ULTRASOUND_EN==0
    Uart1UnPack(ucMode);
#else
    Uart3UnPack(ucMode);
#endif

#else
    Uart1UnPack(ucMode);    
#endif
  }
}
        
/**********************************************************************************************************
*                                           Uart_Process()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void  Uart_Process  (void)
{
  LIB_ERR       lib_err;
  OS_ERR        os_err;
  CPU_TS        ts;
  CPU_CHAR      *pMsg; 
  OS_MSG_SIZE   msgSize;
  
  pMsg = (CPU_CHAR *)OSTaskQPend(0, OS_OPT_PEND_BLOCKING, &msgSize, &ts, &os_err);
  if(pMsg!= 0){
    if(*(pMsg+1)==UART0_SOF){
      Uart0Process(pMsg,msgSize);
    }else if(*(pMsg+1)==UART_SOF){
      UartProcess(pMsg,msgSize);
    }
    Mem_PoolBlkFree(&m_UartBufPool, pMsg, &lib_err);
    if (lib_err != LIB_MEM_ERR_NONE)  {
      //error
    }        
  }
}

/*
*********************************************************************************************************
*                                           App_SerPrintf()
*
* Description : Output  'printf()' statements 
*
* Argument(s) : p_fmt       Pointer to format string.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)  
void  App_SerPrintf (CPU_CHAR  *p_fmt, 
                     ...)
{
    CPU_CHAR    str[80u + 1u];
    CPU_SIZE_T  len;
    SERIAL_ERR  err;
    va_list     vArgs;


    va_start(vArgs, p_fmt);
    
    vsprintf((char       *)str, 
             (char const *)p_fmt, 
                           vArgs);
    
    va_end(vArgs);

    len = Str_Len(str);

    Serial_Wr((SERIAL_IF_NBR   )App_SerTraceIF_Nbr,
              (void           *)&str[0],
              (CPU_SIZE_T      )len,
              (CPU_INT32U      )0,
              (SERIAL_ERR     *)&err);

}
#endif


/*
*********************************************************************************************************
*                                           App_SerPrintf()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

#if (APP_SERIAL_CFG_TRACE_EN == DEF_ENABLED)  
void  App_SerStrRd  (CPU_CHAR   *p_str,
                     CPU_SIZE_T  len)
{
    SERIAL_ERR  err;

    Serial_Rd((SERIAL_IF_NBR   )App_SerTraceIF_Nbr,
              (void           *)p_str,
              (CPU_SIZE_T      )len,
              (CPU_INT32U      )0,
              (SERIAL_ERR     *)&err);
}
#endif


/*
*********************************************************************************************************
*                                           Uart_SerStrRd()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  Uart_SerStrRd  (SERIAL_IF_NBR  if_nbr,
                      CPU_CHAR   *p_str,
                     CPU_SIZE_T  len,
                     CPU_INT32U      timeout_ms,
                     SERIAL_ERR *perr)
{
    /*Serial_RdAsync((SERIAL_IF_NBR   )App_SerTraceIF_Nbr,
              (void           *)p_str,
              (CPU_SIZE_T      )len,
              (SERIAL_CALLBACK_FNCT *)0,
              (CPU_INT32U      )0,
              (SERIAL_ERR     *)perr);*/

    
    
    Serial_Rd((SERIAL_IF_NBR   )if_nbr,
              (void           *)p_str,
              (CPU_SIZE_T      )len,
              (CPU_INT32U      )timeout_ms,
              (SERIAL_ERR     *)perr);
    
    
    /*Serial_WaitFor((SERIAL_IF_NBR   )App_SerTraceIF_Nbr,
              (void           *)p_str,
              (CPU_SIZE_T      )len,
              (CPU_INT32U      )10,
              (SERIAL_ERR     *)perr);*/
}


/*
*********************************************************************************************************
*                                           Uart_SerStrWr()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
*********************************************************************************************************
*/

void  Uart_SerStrWr  (SERIAL_IF_NBR  if_nbr,
                      CPU_CHAR   *p_str,
                     CPU_SIZE_T  len,
                     SERIAL_ERR *perr)
{
  
    Serial_WrAsync((SERIAL_IF_NBR   )if_nbr,
              (void           *)p_str,
              (CPU_SIZE_T      )len,
              (SERIAL_CALLBACK_FNCT *)0,
              (CPU_INT32U      )0,
              (SERIAL_ERR     *)perr);    
}

/**********************************************************************************************************
*                                           Uart0Pack()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void  Uart0Pack  (CPU_INT08U ucCmd,
                     CPU_INT08U ucAddr,
                     CPU_INT08U ucSeq,
                     CPU_INT08U *pucData,
                     CPU_INT08U ucLen,
                     CPU_INT08U ucMode)
{
    LIB_ERR lib_err;
    SERIAL_ERR err;

    static CPU_INT08U ucTxSeq=0x0F;		//0x10~0x7F
    CPU_INT08U *pucTx;
    CPU_INT08U ucBcc=0;
    CPU_INT08U i;
    
    pucTx= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                     (CPU_SIZE_T)64,
                                     (LIB_ERR  *)&lib_err);
    if(!pucTx){
      return;
    }
  
    pucTx[0]=UART0_SOF;
    if(ucMode){
      pucTx[1]=m_ucMachineAddr;
      if(ucTxSeq==0x80){
        ucTxSeq=0x0F;
      }
      ucTxSeq++;
      pucTx[2]=ucTxSeq;
    }else{
      pucTx[1]=ucAddr;
      pucTx[2]=ucSeq;
    }
    pucTx[3]=ucCmd;
    ucBcc^=pucTx[1];
    ucBcc^=pucTx[2];
    ucBcc^=pucTx[3];
    for(i=0;i<ucLen;i++){
        pucTx[4+i]=*(pucData+i);
        ucBcc^=pucTx[4+i];
    }
    pucTx[4+ucLen]=UART0_EOF;
    pucTx[5+ucLen]=ucBcc;
    Serial_WrAsync((SERIAL_IF_NBR   )Uart_SerTraceIF_Nbr[0],
              (void           *)pucTx,
              (CPU_SIZE_T      )ucLen+6,
              (SERIAL_CALLBACK_FNCT *)UartTxFinish,
              (CPU_INT32U      )0,
              (SERIAL_ERR     *)&err);        
    
}
          
/********************************************************************************************************
** oˉêy??3?: UartPack
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
void UartPack(INT8U ucCmd,INT8U ucResponse,INT8U ucLen,INT8U *pucData,INT8U ucSelected)
{
  LIB_ERR lib_err;
  OS_ERR os_err;
  CommTxData *pcommTxData=NULL;
  INT16U intCrc16;
  INT8U ucSelectedA;
  
  pcommTxData= (CommTxData *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                   (CPU_SIZE_T)sizeof(CommTxData),
                                   (LIB_ERR  *)&lib_err);
  if(!pcommTxData){
    return;
  }
  
  if(m_ucUartBit[ucSelected]>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  pcommTxData->ucHead=UART_SOF;
  pcommTxData->ucLen=ucLen+5;
  pcommTxData->uiCluster=0x0301 | ucResponse;
  pcommTxData->ucCmd=ucCmd;
  Mem_Copy(pcommTxData->ucData,pucData,ucLen);
  
  intCrc16=RevCrc16Bytes(&pcommTxData->ucLen,ucLen+4,0xA001);
  pcommTxData->ucData[ucLen]=(INT8U)(intCrc16&0xFF);
  pcommTxData->ucData[ucLen+1]=(INT8U)(intCrc16>>8);
  
#if BOARD_OLD_EN==0  
  ucSelectedA=m_ucBoxToUart[m_ucUartBit[ucSelected]];
#else
  ucSelectedA=3;
#endif  
  Serial_WrAsync((SERIAL_IF_NBR   )ucSelectedA,
            (void           *)&pcommTxData->ucHead,
            (CPU_SIZE_T      )ucLen+7,
            (SERIAL_CALLBACK_FNCT *)UartTxFinish,
            (CPU_INT32U)0,
            (SERIAL_ERR     *)&os_err);        

}

/********************************************************************************************************
** oˉêy??3?: UartTxFinish
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
void UartTxFinish(SERIAL_IF_NBR if_nbr,void *p_arg,void *p_buf,CPU_SIZE_T wr_len,SERIAL_ERR err)
{
//                           err == SERIAL_ERR_UNDERFLOW ? SERIAL_ERR_NONE : err);
  LIB_ERR lib_err;
  
  Mem_PoolBlkFree(&m_UartBufPool, p_buf, &lib_err);
  if (lib_err != LIB_MEM_ERR_NONE)  {
    //error
  }
}

/********************************************************************************************************
** oˉêy??3?: Uart0UnPack
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
void Uart0UnPack(CPU_INT08U ucMode)
{
  LIB_ERR        lib_err;
  OS_ERR         os_err;
  SERIAL_ERR     err;
  
  CPU_INT08U     ucStart;
  CPU_INT08U     ucStop;
  CPU_INT08U     ucCounts;    
  CPU_INT08U     ucErr;
  CPU_CHAR       scBcc;
  CPU_CHAR       scData;
  
  CPU_INT08U     *pucRx=NULL;
  CPU_INT08U     *pucBuf;
  
  m_ucMachineAddr=0x40;
      
  Uart0Pack(INFTYPE_POWER_ON,0,0,NULL,0,1);				//上电
  Uart0Pack(INFTYPE_BELTCLEAR,0,0,NULL,0,1);				//清除故障
  
  ucStart=0;
  ucCounts=0;
  while (DEF_TRUE) {                
    Uart_SerStrRd(Uart_SerTraceIF_Nbr[0],&scData,1,0,&err);
    if(err==SERIAL_ERR_NONE){
        if(ucCounts>=64){
          ucErr=0xC1;
          Uart0Pack(ucErr,0,0,0,0,1);
          if(pucRx!=0){
            Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
            if (lib_err != LIB_MEM_ERR_NONE)  {
              //error
            }
            pucRx=0;
          }
          ucStart=0;
          ucCounts=0;
        }else{
          if(scData==UART0_SOF && ucStart==0){
            pucRx= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                             (CPU_SIZE_T) 64,
                                             (LIB_ERR  *)&lib_err);
            if(pucRx!=0){
              ucCounts=0;
              pucBuf=pucRx;
              *pucBuf=0x00;
              pucBuf++;
              ucCounts++;
              ucStart=1;
              ucStop=0;
              scBcc=0;
              ucErr=0;
              *pucBuf=scData;
              pucBuf++;
              ucCounts++;
            }
          }else if(ucStart==1){
            *pucBuf=scData;
            pucBuf++;
            ucCounts++;
            if(scData==UART0_EOF && ucStop==0){
              ucStop=1;
            }else if(ucStart==1 && ucStop==1){
              if(scBcc!=scData){
                ucErr=0xC4;
                Uart0Pack(ucErr,0,0,0,0,1);
                if(pucRx!=0){
                  Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
                  if (lib_err != LIB_MEM_ERR_NONE)  {
                    //error
                  }
                  pucRx=NULL;
                }
              }else{
                OSTaskQPost(&App_TaskUartProcessTCB, pucRx, ucCounts, OS_OPT_POST_FIFO, &os_err);
                if(os_err!=OS_ERR_NONE){
                  //error
                  ucStart=1;
                }
                pucRx=NULL;
              }
              ucStart=0;
              ucCounts=0;
            }else{
              scBcc^=scData;
            }
          }else{
            //error
            //ucErr=0xC3;
            //Uart0Pack(ucErr,0,0,0,0,1);
            if(pucRx!=0){
              Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
              if (lib_err != LIB_MEM_ERR_NONE)  {
                //error
              }
              pucRx=NULL;
            }
            ucStart=0;
            ucCounts=0;
          }
        }
   }else{
      if(pucRx!=0){
        Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
        if (lib_err != LIB_MEM_ERR_NONE)  {
          //error
        }
        pucRx=NULL;
      }
      ucStart=0;
      ucCounts=0;
    }
  }    
}

/********************************************************************************************************
** oˉêy??3?: UartUnPack
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
void UartUnPack(CPU_INT08U ucMode)
{
  LIB_ERR        lib_err;
  OS_ERR         os_err;
  SERIAL_ERR     err;
  
  CPU_INT08U     ucState=0;
  CPU_INT08U      ucLen;
  CPU_INT08U     ucCounts;    
  CPU_INT08U     ucErr;
  CPU_INT16U     uiCrc16;
  CPU_CHAR       scData;
  
  CPU_INT08U     *pucRx=NULL;
  CPU_INT08U     *pucBuf;
  
  ucState=0;
  ucCounts=0;
  while (DEF_TRUE) {                
    Uart_SerStrRd(Uart_SerTraceIF_Nbr[0],&scData,1,0,&err);
    if(err==SERIAL_ERR_NONE){
      if(ucCounts>=64){
        ucErr=0xC1;
        Uart0Pack(ucErr,0,0,0,0,1);
        if(pucRx!=0){
          Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
          if (lib_err != LIB_MEM_ERR_NONE)  {
            //error
          }
          pucRx=0;
        }
        ucState=0;
      }else{
        if(scData==UART_SOF && ucState==0){
          pucRx= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                           (CPU_SIZE_T) 64,
                                           (LIB_ERR  *)&lib_err);
          if(pucRx!=0){
            pucBuf=pucRx;
            ucState=1;
            ucCounts=0;
            ucErr=0;
            *pucBuf=ucMode;
            pucBuf++;
            ucCounts++;
            *pucBuf=scData;
            pucBuf++;
            ucCounts++;
          }
        }else if(ucState==1){
          *pucBuf=scData;
          ucLen=scData;
          pucBuf++;
          ucCounts++;
          ucState=2;
        }else{
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
          if(ucCounts==ucLen+3){
            uiCrc16=RevCrc16Bytes(pucRx+2,ucLen+1,0xA001);
            if(!uiCrc16){
              OSTaskQPost(&App_TaskUartProcessTCB, pucRx, ucCounts, OS_OPT_POST_FIFO, &os_err);
              if(os_err!=OS_ERR_NONE){
                //error
                ucState=1;
              }
            }else{
              Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
              if (lib_err != LIB_MEM_ERR_NONE){
                //error
                ucState=1;
              }
              pucRx=NULL;
            }
            ucState=0;
            ucCounts=0;
          }
        }
      }
   }else{
      if(pucRx!=0){
        Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
        if (lib_err != LIB_MEM_ERR_NONE)  {
          //error
        }
        pucRx=NULL;
      }
      ucState=0;
      ucCounts=0;
    }
  }    
}

/********************************************************************************************************
** oˉêy??3?: Uart1UnPack
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
void Uart1UnPack(CPU_INT08U ucMode)
{ 
  LIB_ERR        lib_err;
  OS_ERR         os_err;
  SERIAL_ERR     err;
  
  CPU_INT08U     ucState=0;
  CPU_INT08U     ucLen;
  CPU_INT08U     ucCounts;    
  CPU_INT08U     ucErr;
  CPU_INT16U     uiCrc16;
  CPU_CHAR       scData;
  
  CPU_INT08U     *pucRx=NULL;
  CPU_INT08U     *pucBuf;
  
#if BOARD_OLD_EN==1
  CPU_INT08U     ucSelected;
#endif
  
  ucState=0;
  ucCounts=0;
  while (DEF_TRUE) {                
    Uart_SerStrRd(Uart_SerTraceIF_Nbr[ucMode],&scData,1,0,&err);
    if(err==SERIAL_ERR_NONE){
      if(ucCounts>=64){
        ucErr=0xC1;
        Uart0Pack(ucErr,0,0,0,0,1);
        if(pucRx!=0){
          Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
          if (lib_err != LIB_MEM_ERR_NONE)  {
            //error
          }
          pucRx=0;
        }
        ucState=0;
      }else{
        if(scData==UART_SOF && ucState==0){
          pucRx= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                           (CPU_SIZE_T) 64,
                                           (LIB_ERR  *)&lib_err);
          if(pucRx!=0){
            pucBuf=pucRx;
            ucState=1;
            ucCounts=0;
            ucErr=0;
          #if BOARD_OLD_EN==0
            *pucBuf=ucMode;
          #else
            ucSelected=CardBoxGetSelectedA()+1;
            *pucBuf=ucSelected;
          #endif
            pucBuf++;
            ucCounts++;
            *pucBuf=scData;
            pucBuf++;
            ucCounts++;
          }
        }else if(ucState==1){
        #if BOARD_OLD_EN==1
          if(ucSelected!=(CardBoxGetSelectedA()+1)){
            Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
            if (lib_err != LIB_MEM_ERR_NONE)  {
              //error
            }
            pucRx=NULL;
            ucState=0;
            ucCounts=0;
            continue;
          }
        #endif
          *pucBuf=scData;
          ucLen=scData;
          pucBuf++;
          ucCounts++;
          ucState=2;
        }else{
        #if BOARD_OLD_EN==1
          if(ucSelected!=(CardBoxGetSelectedA()+1)){
            Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
            if (lib_err != LIB_MEM_ERR_NONE)  {
              //error
            }
            pucRx=NULL;
            ucState=0;
            ucCounts=0;
            continue;
          }
        #endif
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
          if(ucCounts==ucLen+3){
            uiCrc16=RevCrc16Bytes(pucRx+2,ucLen+1,0xA001);
            if(!uiCrc16){
              OSTaskQPost(&App_TaskUartProcessTCB, pucRx, ucCounts, OS_OPT_POST_FIFO, &os_err);
              if(os_err!=OS_ERR_NONE){
                //error
                ucState=1;
              }
            }else{
              Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
              if (lib_err != LIB_MEM_ERR_NONE){
                //error
                ucState=1;
              }
              pucRx=NULL;
            }
            ucState=0;
            ucCounts=0;
          }
        }
      }
   }else{
      if(pucRx!=0){
        Mem_PoolBlkFree(&m_UartBufPool, pucRx, &lib_err);
        if (lib_err != LIB_MEM_ERR_NONE)  {
          //error
        }
        pucRx=NULL;
      }
      ucState=0;
      ucCounts=0;
    }
  }    
}


/********************************************************************************************************
** oˉêy??3?: Uart3UnPack
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
void Uart3UnPack(CPU_INT08U ucMode)
{
  SERIAL_ERR     err;
  
  CPU_INT08U     ucStart;
  CPU_INT08U     ucCounts;    
  CPU_CHAR       scData;
  
  CPU_INT08U     ucRx[10];
  CPU_INT08U     *pucBuf;
  
  CPU_INT08U     ucTimes;
  CPU_INT08U     ucNoTimes;
  CPU_INT08U     ucMaxTimes;
  CPU_INT08U     ucMaxDistance;
  CPU_INT08U     ucHaved;
  
  CPU_INT08U     ucRecvLen;
#if ULTRASOUND_LEN_7_EN==1
  ucRecvLen=7;
#else
  ucRecvLen=8;
#endif
 
  if(!EepromReadVerifyBytes(ULTRASOUND_PARAMS_ADDR,ucRx,2)){
    ucMaxTimes=ULTRASOUND_TIMES_DEFAULT;
    ucMaxDistance=ULTRASOUND_DISTANCE_DEFAULT;
  }else{
    ucMaxDistance=ucRx[0];
    ucMaxTimes=ucRx[1];
  }
    
  m_ucMachineAddr=0x40;
      
  ucHaved=0;
  ucTimes=0;
  ucNoTimes=0;
  ucStart=0;
  ucCounts=0;
  while (DEF_TRUE) {                
    Uart_SerStrRd(Uart_SerTraceIF_Nbr[3],&scData,1,0,&err);
    if(err==SERIAL_ERR_NONE){
    #if ULTRASOUND_NEW_EN==0
      if(ucCounts>ucRecvLen){
        ucStart=0;
        ucCounts=0;
      }else{
        if(scData==UART3_SOF && ucStart==0){
          ucCounts=0;
          ucStart=1;
          pucBuf=ucRx;
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
        }else if(ucStart==1){
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
        #if ULTRASOUND_LEN_7_EN==0
          if(ucCounts==8 && scData==UART3_EOF){
        #else            
          if(ucCounts==7){
        #endif
            if(ucRx[3]<=ucMaxDistance && ucRx[4]<=ucMaxDistance){
              ucNoTimes=0;
              if(ucTimes<ucMaxTimes){                
                ucTimes++;
                if(ucTimes>=ucMaxTimes && ucHaved==0){
                  ucHaved=1;
                  UltraSoundSend(1);
                  Uart0Pack(INFTYPE_ULTRASOUND_STATUS,0,0,&ucRx[3],4,1);
                }
              }else{
                Uart0Pack(INFTYPE_ULTRASOUND_STATUS,0,0,&ucRx[3],4,1);
              }
            }else{
              if(ucNoTimes<ucMaxTimes){                
                ucNoTimes++;
                if(ucNoTimes>=ucMaxTimes){
                  ucHaved=0;
                  UltraSoundSend(0);
                  Uart0Pack(INFTYPE_ULTRASOUND_STATUS,0,0,&ucRx[3],4,1);
                }
              }
              ucTimes=0;
            }
            ucStart=0;
          }
        }else{
          ucStart=0;
        }
      }
  #else
      if(ucCounts>ucRecvLen){
        ucStart=0;
        ucCounts=0;
      }else{
        if(scData==UART3_SOF && ucStart==0){
          ucCounts=0;
          ucStart=1;
          pucBuf=ucRx;
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
        }else if(scData==UART3_CMD && ucStart==1){
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
          ucStart=2;
        }else if(scData==UART3_LEN && ucStart==2){
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
          ucStart=3;
        }else if(ucStart==3){
          *pucBuf=scData;
          pucBuf++;
          ucCounts++;
        #if ULTRASOUND_LEN_7_EN==0
          if(ucCounts==8 && scData==UART3_EOF){
        #else            
          if(ucCounts==7){
        #endif
            if(ucRx[3]<=ucMaxDistance && ucRx[4]<=ucMaxDistance){
              ucNoTimes=0;
              if(ucTimes<ucMaxTimes){                
                ucTimes++;
                if(ucTimes>=ucMaxTimes && ucHaved==0){
                  ucHaved=1;
                  UltraSoundSend(1);
                  Uart0Pack(INFTYPE_ULTRASOUND_STATUS,0,0,&ucRx[3],4,1);
                }
              }else{
                Uart0Pack(INFTYPE_ULTRASOUND_STATUS,0,0,&ucRx[3],4,1);
              }
            }else{
              if(ucNoTimes<ucMaxTimes){                
                ucNoTimes++;
                if(ucNoTimes>=ucMaxTimes){
                  ucHaved=0;
                  UltraSoundSend(0);
                  Uart0Pack(INFTYPE_ULTRASOUND_STATUS,0,0,&ucRx[3],4,1);
                }
              }
              ucTimes=0;
            }
            ucStart=0;
          }
        }else{
          ucStart=0;
        }
      }          
  #endif        
   }else{
      ucStart=0;
    }
  }    
}

/**********************************************************************************************************
*                                           Uart0Process()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void Uart0Process(CPU_CHAR *pMsg,OS_MSG_SIZE msgSize)
{
  INT8U ucBuf[8];
  CPU_SR_ALLOC();
  
  CardMachineRxData *pcommData=(CardMachineRxData *)&pMsg[1];
  
  pcommData->ucLen=msgSize-7;
  m_ucMachineAddr=pcommData->ucAddr;
  switch(pcommData->ucCmd){
    case SMOTO_WRITE_PARAMS_CMD:
      SMotoWriteParams(pcommData);
      break;
    case SMOTO_READ_PARAMS_CMD:
      SMotoReadParams(pcommData);
      break;

    case DMOTO_WRITE_PARAMS_CMD:
      DMotoWriteParams(pcommData);
      break;
    case DMOTO_READ_PARAMS_CMD:
      DMotoReadParams(pcommData);

    case AUTOOUT_MODE_WRITE_CMD:
      //ParamsFlagWrite(pcommData,AUTOOUT_MODE_ADDR);
      AutoOutModeWrite(pcommData);
      break;
    case AUTOOUT_MODE_READ_CMD:
      //ParamsFlagRead(pcommData,AUTOOUT_MODE_ADDR);
      AutoOutModeRead(pcommData);
      break;

    case BUZZ_EN_WRITE_CMD:
      //ParamsFlagWrite(pcommData,BUZZ_EN_ADDR);
      BuzzEnWrite(pcommData);
      break;
    case BUZZ_EN_READ_CMD:
      //ParamsFlagRead(pcommData,BUZZ_EN_ADDR);
      BuzzEnRead(pcommData);
      break;

    case DMOTO_SELECT_WRITE_CMD:
      DMotoSelectWrite(pcommData);
      break;
    case DMOTO_SELECT_READ_CMD:
      DMotoSelectRead(pcommData);
      break;

    case SMOTO_SELECT_WRITE_CMD:
      SMotoSelectWrite(pcommData);
      break;
    case SMOTO_SELECT_READ_CMD:
      SMotoSelectRead(pcommData);
      break;

    case BOX_SELECT_WRITE_CMD:
      BoxSelectWrite(pcommData);
      break;
    case BOX_SELECT_READ_CMD:
      BoxSelectRead(pcommData);
      break;

    case KEY_SELECT_WRITE_CMD:
      KeySelectWrite(pcommData);
      break;
    case KEY_SELECT_READ_CMD:
      KeySelectRead(pcommData);
      break;

    case ULTRASOUND_WRITE_CMD:
      UltraSoundWrite(pcommData);
      break;
    case ULTRASOUND_READ_CMD:
      UltraSoundRead(pcommData);
      break;

    case GROUP_SELECT_WRITE_CMD:
      GroupSelectWrite(pcommData);
      break;
    case GROUP_SELECT_READ_CMD:
      GroupSelectRead(pcommData);
      break;

    case SCAN_PARAMS_WRITE_CMD:
      ScanParamsWrite(pcommData);
      break;
    case SCAN_PARAMS_READ_CMD:
      ScanParamsRead(pcommData);
      break;

      
    case 0x10: 					//?¨?ú3??¨￡????¨′ó?¨?D×°3?μ??á?¨ìì???????￡
    case 0x13:
    case 0x11: 					//?¨?úí??¨￡????¨′ó?¨?ú?úμ??á?¨????·￠3?è￥?￡
    case 0x20: 					//?¨?úê??¨￡????¨′ó?¨?ú×°è?μ??á?¨ìì???????￡//D?ê??¨?úê1ó?
    case 0x21: 					//?¨?ú???¨￡????¨′ó?¨?ú?úμ??á?¨????×°???¨?D?￡//ê??¨?úê1ó?
    case 0x22: 					//?¨?úí??¨￡????¨í?3?￡?D?ê??¨?ú?¨???áD′?TD§ê±???¨í?3?
    case 0x23:					//?μ?¨??ê?		
    case 0x38:                                  //掉卡开门3
    case 0x39:                                  //打印机门
      if(BSP_OS_SemWait(g_pActionSem,20)==DEF_FAIL){
        ucBuf[0]=SUBTYPE_ERR_DEVICE_BUSY;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucBuf,1,0);
      }else{
        Box_TaskQPost(&App_TaskActionTCB,&pcommData->ucHead,sizeof(CardMachineRxData));  
      }
      break;
      
    case 0x15:					//?D??1¤??
      if(pcommData->ucData[0]==0x30){
        OS_ENTER_CRITICAL();
        g_usrGlobalFlag.usrBit.bLedOutMode=3;		
        OS_EXIT_CRITICAL();
      }else{
        OS_ENTER_CRITICAL();
        g_usrGlobalFlag.usrBit.bLedOutMode=0;		
        OS_EXIT_CRITICAL();
      }
      break;
      
    case 0x30:					//?á?¨?ú?μáDo? I2C
      CardMachineIdRead(pcommData);
      break;
    case 0x41:					//éè???¨?ú?μáDo? I2C
      CardMachineIdWrite(pcommData);
      break;

    case 0x31:					//?á?¨?D?μáDo? UART3
      CardBoxIdRead(pcommData);
      break;
    case 0x42:					//éè???¨?D?μáDo? UART3
      CardBoxIdWrite(pcommData);
      break;

    case 0x32:					//?áè??¨?D?¨êy I2C ?òUART3
      CardBoxCountRead(pcommData);
      break;		
    case 0x34: 					//éè???¨?Dμ±?°′?′￠?¨êy UART3
      CardBoxCountWrite(pcommData);
      break;

    case 0x35:					//?áè??¨?úμ??·
      CardMachineAddrRead(pcommData);
      break;
    case 0x36:					//éè???¨?úμ??·
      CardMachineAddrWrite(pcommData);
      break;
      
    case 0x3A:			//内部天线	
      CardBoxSetSelected(BOX_FIRST,BOX_POWER_OFF_MODE);
      Uart0Pack(INFTYPE_CMD_FINISHED,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      break;
      
    case 0x3B:			// 外部天线
      CardBoxSetSelected(BOX_FIRST,BOX_POWER_ON_MODE);
      Uart0Pack(INFTYPE_CMD_FINISHED,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      break;

    case 0x3C:			//开扫描枪
      CloseScan();
      OS_ENTER_CRITICAL();
      g_usrScan.bEnabled=1;
      g_usrScan.bMode=SCAN_CLOSE_MODE;
      g_usrScan.b14Times=g_ucScanCloseTime;
      OS_EXIT_CRITICAL();
      
      Uart0Pack(INFTYPE_CMD_FINISHED,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      break;
    
    case 0x3D:			// 关扫描枪
      CloseScan();
      OS_ENTER_CRITICAL();
      g_usrScan.bEnabled=0;
      OS_EXIT_CRITICAL();
      Uart0Pack(INFTYPE_CMD_FINISHED,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      break;

    case 0x43:				//éè???¨?úμ±?°ê1ó?±¨?ˉò? I2C í¨??D-òé?T′???			
      break;
    case 0x45:				//éè???¨?ú?ì?úμ?áù???¨êy I2C
      CardMachineAlarmMaxWrite(pcommData);
      break;
    case 0x46:				//éè???¨?ú?ì??μ?áù???¨êy I2C
      CardMachineAlarmMinWrite(pcommData);
      break;

    case 0x48:					//?á?¨?D×?′ó?¨êy
      CardBoxMaxCountRead(pcommData);
      break;
    case 0x49:					//éè?¨?D×?′ó?¨êy I2C
      CardBoxMaxCountWrite(pcommData);
      break;

    case 0x50:					//?áè??¨?ú×′ì?D??￠ GPIO		
      CardMachineStateRead(pcommData);
      break;
    case 0x51:					//?áè??¨?úààDí
      CardMachineTypeRead(pcommData);
      break;
    case 0x52:				//??3y?¨?DD??￠
      CardBoxRecordInit(pcommData);
      break;
      
    case 0x6B:					//?á?¨?ú?ì?úáù???¨êyI2C
      CardMachineAlarmMaxRead(pcommData);
      break;
    case 0x6C:					//?á?¨?ú?ì??áù???¨êyI2C
      CardMachineAlarmMinRead(pcommData);
      break;
    case 0x6D:					//3?ê??ˉ?¨?ú????
      break;
    case 0x6F:					//?á?¨?ú1ì?t°?±?D??￠/??DT/μ÷ê? I2C
      CardMachineVersionRead(pcommData);
      break;		
    case 0x80:			//?á?¨?úêy?Y?éID
    case 0x81:
    case 0x82:
    case 0x83:
      CardMachineDataRead(pcommData);
    break;
    case 0x90:			//D′?¨?úêy?Y?éID
    case 0x91:
    case 0x92:
    case 0x93:           
      CardMachineDataWrite(pcommData);
    break;
    case 0x9A:	//?á?¨?D°?±?D??￠
      CardBoxVersionRead(pcommData);
      break;

      //A0??μ÷ê?ê1ó??üá?×?	
    case 0xA0://μ÷ê?ê±ê1ó?￡?éy?μ??ì¨
      CardBoxMotoMove(pcommData);
      break;

    case 0xA1:  //μ÷ê?ê±ê1ó?￡??ó???¨êy
      CardBoxCountAddSub(pcommData);;
      break;

    case 0xA2:		//μ??ú2aê?
      break;

    case 0xA3:		//??????ê??¨éè?¨￡¨μ÷ê?ê±ê1ó?￡??¨??μ?′??¨?úê±￡?×??ˉ??ê??á??ê?oD￡?
    case 0xA4:		//μ??ú?-?·2aê?￡?ê?μ?′???á???oó￡???è??-?·2aê?
      break;
    case 0xA5: //?±á÷μ??ú?-?·2aê?
      break;

    case 0xA6:
      DMotoMove(pcommData);
      break;
    case 0xA7:
      SMotoMove(pcommData);
      break;
    case 0xAA:
      if(DEV_TYPE()==SMALL_THICK_GIN_TYPE){
        CardToBox(pcommData);
      }
      break;
    case 0xAB:
      if(DEV_TYPE()==SMALL_THICK_GIN_TYPE){
        CardToOut(pcommData);
      }
      break;		
    case 0xAC:		//debug
      KeyTest(pcommData);
      break;		
  }
}


/**********************************************************************************************************
*                                           UartProcess()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void UartProcess(CPU_CHAR *pMsg,OS_MSG_SIZE msgSize)
{
  CommRxData *pcommData=(CommRxData *)&pMsg[1];
  CPU_INT08U ucSelected;
#if BOARD_OLD_EN==0  
  ucSelected=m_ucUartToBox[(*pMsg)-1];
#else
  ucSelected=(*pMsg)-1;  
#endif  
  
  if((pcommData->uiCluster & 0x0381)==0x0381 && !pcommData->ucStatus){
    switch(pcommData->ucCmd){
      case CARDMACHINE_RECORD_INIT_CMD:
        CardBoxRecordInitResponse(pcommData,ucSelected);
        return;
              
      case CARDMACHINE_READ_MACHINE_ID_CMD:
      case CARDMACHINE_WRITE_MACHINE_ID_CMD:
        CardBoxMachineIdResponse(pcommData,ucSelected);
        return;
      
      case CARDMACHINE_READ_BASIC_INFO_CMD:
        CardBoxBasicInfoResponse(pcommData,ucSelected);
        return;
              
      case UART_COUNT_ADD_CMD:
      case UART_COUNT_SUB_CMD:
        CardBoxCountAddSubResponse(pcommData,ucSelected);
        return;
      
      case UART_COUNT_SET_WRITE:
      case UART_COUNT_READ_CMD:
        CardBoxCountResponse(pcommData,ucSelected);
        return;
      
              
      case CARDMACHINE_READ_COUNT_MAX_CMD:
      case CARDMACHINE_WRITE_COUNT_MAX_CMD:
        CardBoxMaxCountResponse(pcommData,ucSelected);
        return;
                                                      
      case CARDMACHINE_READ_VERSION_CMD:
        CardBoxVersionResponse(pcommData,ucSelected);
      
      default:
        break;					
    }
  }
}

/**********************************************************************************************************
*                                           UltraSoundSend()
*
* Description : Read a string from the serial terminal. 
*
* Argument(s) : p_str       Pointer to string.
*
*               len         String length.
*
* Return(s)   : The number of octets written.
*
* Caller(s)   : Application.
*
* Note(s)     : none.
**********************************************************************************************************/
void UltraSoundSend(INT8U ucStatus)
{
  INT32U ulKeyOutputNew;
  INT32U ulTmp;
  
  ulKeyOutputNew=g_usrGetKey.ulKeyOutput;
  ulTmp=KeyConvert(ulKeyOutputNew);
  if(ucStatus){
    ulTmp&=(~(1<<6));
  }else{
    ulTmp|=(1<<6);
  }
  Uart0Pack(INFTYPE_DEVICE_STATUS,0,0,(INT8U *)&ulTmp,4,1);
}

#endif