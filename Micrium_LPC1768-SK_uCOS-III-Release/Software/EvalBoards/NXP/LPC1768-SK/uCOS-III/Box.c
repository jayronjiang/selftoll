/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------�ļ���Ϣ---------------------------------------------------------------------------------
*��   ��   ��: Box.C
*��   ��   ��: John Tonny
*����޸�����: 2009��11��01��
*��        ��:
*
*--------------��ʷ�汾��Ϣ-----------------------------------------------------------------------------
* ������: John Tonny
* ��  ��: V1.0
* �ա���: 2009��11��01��
* �衡��: ԭʼ�汾
*
*-------------------------------------------------------------------------------------------------------
* �޸���:
* ��  ��:
* �ա���:
* �衡��:
*
*--------------��ǰ�汾�޶�-----------------------------------------------------------------------------
* �޸���:
* �ա���:
* �衡��:
*
*-------------------------------------------------------------------------------------------------------
*******************************************************************************************************/

#define BOX_GLOBALS
#include "includes.h"


/********************************************************************************************************
** ��������: Box_Init
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
CPU_BOOLEAN Box_Init(void)
{
  CPU_SIZE_T      octets_reqd;
  LIB_ERR         lib_err;

  CPU_SR_ALLOC();
  
  
  CPU_CRITICAL_ENTER();
  Mem_PoolCreate((MEM_POOL   *)&m_BoxPool,
                 (void       *) 0,
                 (CPU_SIZE_T  ) 0,
                 (CPU_SIZE_T  ) 4,
                 (CPU_SIZE_T  ) 64,
                 (CPU_SIZE_T  ) 1,
                 (CPU_SIZE_T *)&octets_reqd,
                 (LIB_ERR    *)&lib_err);
  
  if (lib_err != LIB_MEM_ERR_NONE) {
      CPU_CRITICAL_EXIT();
      return (DEF_FAIL);    
  }
  CPU_CRITICAL_EXIT();
      
  
  g_pActionSem = (OS_SEM *)Mem_PoolBlkGet((MEM_POOL    *)&m_BoxPool,
                                  (CPU_SIZE_T   ) sizeof(OS_SEM),
                                  (LIB_ERR     *)&lib_err);
  
  if(g_pActionSem){
    if(BSP_OS_SemCreate((BSP_OS_SEM *)g_pActionSem,
                              (BSP_OS_SEM_VAL)0,
                              (CPU_CHAR *)0)==DEF_FAIL){  
    }
  }
  
  
  
  I2c0Init();
  
  DMotoSelectGet(0);
  SMotoSelectGet(0);
  BoxSelectGet(0);
  KeySelectGet(0);
  
  DMotoPwmGet();	
  SMotoFreqGet();
  
  ScanParamsGet();    
  
  Timer0Init();
  Timer1Init();
  Timer2Init();
  Timer3Init();
  PWM1Init();
  
   
  return DEF_OK;
    
}

/********************************************************************************************************
** ��������: Box_Process
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void Box_Process(void)
{  
  LIB_ERR               lib_err;
  OS_ERR                os_err;
  CPU_TS                ts;
  OS_MSG_SIZE           msgSize;
  CPU_INT08U            *pMsg; 
  INT8U                 ucCmd;
  INT8U                 ucType=DEV_TYPE();
  INT8U                 ucSelected;
  
  INT32U                ulTmp;
  INT8U ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
  
  while(DEF_TRUE){
    pMsg = (CPU_INT08U *)OSTaskQPend(BOX_CONNECT_TIME_DEFAULT, OS_OPT_PEND_BLOCKING, &msgSize, &ts, &os_err);
    if(pMsg){
      ucCmd=pMsg[0];
      if(ucCmd==BOX_CONNECTING_MSG){
        if(ucType==SMALL_THICK_OUT_TYPE || ucType==LARGE_THICK_OUT_TYPE || ucType==SMALL_THIN_OUT_TYPE || ucType==LARGE_THIN_OUT_TYPE){
          //����
          if(CARD_AUTO_MODE()){																																		
            //�Զ�ģʽ
            ulTmp=GetKeyOutput();
            if(!CheckBit(ulTmp,ucCardPosABit)){
              //�޿�
              m_usrGlobalFlag.usrBit.bCardTakeout=1;
            }
          }      
        }
      }else if(ucCmd==BOX_UART_SEND_MSG){
        ucSelected=pMsg[3];
        if(CardBoxSetSelected(ucSelected,BOX_POWER_ON_MODE)){
          UartPack(pMsg[1],pMsg[2],msgSize-4,&pMsg[4],pMsg[3]);
        }
      }
      Mem_PoolBlkFree(&m_BoxPool, pMsg, &lib_err);
      if (lib_err != LIB_MEM_ERR_NONE){
        //error
      }
      continue;
    }    
  
  #if BOARD_OLD_EN==0
    CardBoxCountEvent();
    CardBoxConnectEvent();
  #else
    CardBoxConnectCountEvent();
  #endif
  }

}

/********************************************************************************************************
** o����y??3?: CardBoxConnectEvent
** 1|?��?����?:
** ��? ?? ��?:
**
** ��???  3?:
**
** ��???��?��?:
** �̡¨�??��?��:
**
** ����??  ??: John Tonny
** ��???  ?��: 2005?��05??01��?
**------------------------------------------------------------------------------------------------------
** DT ?? ��?:
** ��???  ?��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxConnectEvent(void)
{
  INT8U ucData[32];
  INT8U ucSelected;
  INT8U ucBoxNums;
  
  INT8U ucType;
  
  ucType=DEV_TYPE();
  if(ucType==LARGE_THICK_OUT_TYPE || ucType==LARGE_THIN_OUT_TYPE){
    ucBoxNums=CARDMACHINE_CARDBOX_NUMS;
  }else{
    ucBoxNums=1;
  }
	
  for(ucSelected=0;ucSelected<ucBoxNums;ucSelected++){
    if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad){
      //װ��
      if(m_usrBoxInfo[ucSelected].ucTimes){
         m_usrBoxInfo[ucSelected].ucTimes--;
      }else{
        //��������
        if(m_usrBoxInfo[ucSelected].usrConnectResponse.ucRetrys>0){
          m_usrBoxInfo[ucSelected].usrConnectResponse.ucRetrys--;
        }else{
          CardBoxInfoReset(ucSelected);
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCommErr=1;          
        }
        
        
        if(m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums>0){
          m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums--;
        }
        
        if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest=1;																							//��??��
          ucData[0]=0x40;
        }else{
          ucData[0]=0x00;
          if(!m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums){
            if(m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrRetrys){
              m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrRetrys--;
              if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest){					
                ucData[0]=0x40;
                m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums=21;
              }else{
                m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums=CARDBOX_POS_ERR_NUMS;
                ucData[0]=0x80;
              }
            }else{
              m_usrBoxInfo[ucSelected].usrFlag.usrBit.bPosErr=1;
            }
          }
        }			
        if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest && !m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos){					
          ucData[0]=0x80;
        }
        CardBoxBasicInfoSend(ucData[0],ucSelected);
      }
    }
  }
}
         
/********************************************************************************************************
** o����y??3?: CardBoxCountEvent
** 1|?��?����?: �̡�D�䨨??����y?�䨪��3����?��??��???��D�䨨?��??����???��??????������??2?��?��??��?D
** ��? ?? ��?:
**
** ��???  3?:
**
** ��???��?��?:
** �̡¨�??��?��:
**
** ����??  ??: John Tonny
** ��???  ?��: 2005?��05??01��?
**------------------------------------------------------------------------------------------------------
** DT ?? ��?:
** ��???  ?��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxCountEvent(void)
{
  INT8U ucType;
  INT8U ucBoxNums;
  INT8U ucSelected;
  
  CPU_SR_ALLOC();
  
  ucType=DEV_TYPE();
  if(ucType==LARGE_THICK_OUT_TYPE || ucType==LARGE_THIN_OUT_TYPE){
    ucBoxNums=CARDMACHINE_CARDBOX_NUMS;
  }else{
    ucBoxNums=1;
  }
  
  for(ucSelected=0;ucSelected<ucBoxNums;ucSelected++){
    if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad || !m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
      continue;
    }
    
    if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled){		
      if(m_usrBoxInfo[ucSelected].usrCountResponse.ulMachineId==m_usrBoxInfo[ucSelected].ulMachineId){		
        OS_ENTER_CRITICAL();
        if(m_usrBoxInfo[ucSelected].usrCountResponse.ucRetrys>0){
          m_usrBoxInfo[ucSelected].usrCountResponse.ucRetrys--;
        }else{
          BuzzSet(7,30,15,BUZZ_COUNT_WRITE_ERR_PRIOR);
        }
        OS_EXIT_CRITICAL();
        CardCountUpdateSend(1,ucSelected);
      }else{
        CardBoxCountReset(ucSelected);
      }
    }	
  }
}

/********************************************************************************************************
** o����y??3?: CardBoxConnectCountEvent
** 1|?��?����?: �̡�D�䨨??����y?�䨪��3����?��??��???��D�䨨?��??����???��??????������??2?��?��??��?D
** ��? ?? ��?:
**
** ��???  3?:
**
** ��???��?��?:
** �̡¨�??��?��:
**
** ����??  ??: John Tonny
** ��???  ?��: 2005?��05??01��?
**------------------------------------------------------------------------------------------------------
** DT ?? ��?:
** ��???  ?��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxConnectCountEvent(void)
{
  INT8U ucData[32];
  INT8U ucType;
  INT8U ucBoxNums;
  INT8U ucSelected;
  INT8U i;  
  
  CPU_SR_ALLOC();
  
  ucType=DEV_TYPE();
  if(ucType==LARGE_THICK_OUT_TYPE || ucType==LARGE_THIN_OUT_TYPE){
    ucBoxNums=CARDMACHINE_CARDBOX_NUMS;
  }else{
    ucBoxNums=1;
  }
    
  ucSelected=g_ucBoxCurSelected;  
  for(i=0;i<ucBoxNums;i++){
    if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad){
      if(!CardBoxSetSelected(ucSelected,BOX_POWER_ON_MODE)){
        ucSelected++;
        if(ucSelected>=ucBoxNums){
          ucSelected=0;
        }
        continue;
      }
      //װ��
      if(m_usrBoxInfo[ucSelected].ucTimes){
        m_usrBoxInfo[ucSelected].ucTimes--;
        
        ucSelected++;
        if(ucSelected>=ucBoxNums){
          ucSelected=0;
        }
      }else{
        //��������
        if(m_usrBoxInfo[ucSelected].usrConnectResponse.ucRetrys>0){
          m_usrBoxInfo[ucSelected].usrConnectResponse.ucRetrys--;
        }else{
          CardBoxInfoReset(ucSelected);
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCommErr=1;          
        }
        
        if(m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums>0){
          m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums--;
        }
        
        if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest=1;																							//��??��
          ucData[0]=0x40;
        }else{
          ucData[0]=0x00;
          if(!m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums){
            if(m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrRetrys){
              m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrRetrys--;
              if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest){					
                ucData[0]=0x40;
                m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums=21;
              }else{
                m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums=CARDBOX_POS_ERR_NUMS;
                ucData[0]=0x80;
              }
            }else{
              m_usrBoxInfo[ucSelected].usrFlag.usrBit.bPosErr=1;
            }
          }
        }			
        if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest && !m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos){					
          ucData[0]=0x80;
        }
        CardBoxBasicInfoSend(ucData[0],ucSelected);
        
        if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled){		
          if(m_usrBoxInfo[ucSelected].usrCountResponse.ulMachineId==m_usrBoxInfo[ucSelected].ulMachineId){		
            OS_ENTER_CRITICAL();
            if(m_usrBoxInfo[ucSelected].usrCountResponse.ucRetrys>0){
              m_usrBoxInfo[ucSelected].usrCountResponse.ucRetrys--;
            }else{
              BuzzSet(7,30,15,BUZZ_COUNT_WRITE_ERR_PRIOR);
            }
            OS_EXIT_CRITICAL();
            CardCountUpdateSend(1,ucSelected);
          }else{
            CardBoxCountReset(ucSelected);
          }
        }
        ucSelected++;
        if(ucSelected>=ucBoxNums){
          ucSelected=0;
        }
        break;
      }
    }else{
      ucSelected++;
      if(ucSelected>=ucBoxNums){
        ucSelected=0;
      }
    }
  }  
  g_ucBoxCurSelected=ucSelected;
}

/********************************************************************************************************
** ��������: BoxConnected
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void BoxConnected(INT8U ucSelected)
{
  INT8U ucData[32];
  INT8U ucMsg;
  
  if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected=1;
        
    ucMsg=BOX_CONNECTING_MSG;

    BoxPostMsg(&ucMsg,1);
    
    ucData[0]=ucSelected+0x30;
    SprintF(&ucData[1],4,m_usrBoxInfo[ucSelected].ucCounts);
  #if COUNT_ID_EN==0          
    Uart0Pack(INFTYPE_CARD_COUNT,m_ucMachineAddr,0,ucData,5,1);
  #else
    SprintF(&ucData[5],8,m_usrBoxInfo[ucSelected].ulMachineId);
    Uart0Pack(INFTYPE_CARD_COUNT,m_ucMachineAddr,0,ucData,13,1);
  #endif          
  }
}

         
/********************************************************************************************************
** o����y??3?: CardBoxBasicInfoSend
** 1|?��?����?:
** ��? ?? ��?:
**
** ��???  3?:
**
** ��???��?��?:
** �̡¨�??��?��:
**
** ����??  ??: John Tonny
** ��???  ?��: 2005?��05??01��?
**------------------------------------------------------------------------------------------------------
** DT ?? ��?:
** ��???  ?��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxBasicInfoSend(INT8U ucMode,INT8U ucSelected)
{
  INT8U ucData[8];
  INT8U ucType=DEV_TYPE();
  
  if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_GIN_TYPE || ucType==SMALL_THIN_IN_TYPE || ucType==SMALL_THIN_GIN_TYPE){
    ucData[0]=CARDMACHINE_SMALL_IN_TYPE;
  }else if(ucType==SMALL_THICK_OUT_TYPE || ucType==LARGE_THICK_OUT_TYPE || ucType==SMALL_THIN_OUT_TYPE || ucType==LARGE_THIN_OUT_TYPE){
    ucData[0]=CARDMACHINE_SMALL_OUT_TYPE;
  }
  ucData[0]|=ucMode;
  if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bPosErr){
    ucData[0]&=0x3F;
  }

  if(m_ucCardBoxTxSeq==0x80){
    m_ucCardBoxTxSeq=0x0F;
  }
  m_ucCardBoxTxSeq++;
  ucData[1]=m_ucCardBoxTxSeq;

  UartPack(CARDMACHINE_READ_BASIC_INFO_CMD,UART_RESPONSE_MODE,0x02,ucData,ucSelected);	
  UartPack(CARDMACHINE_READ_BASIC_INFO_CMD,UART_RESPONSE_MODE,0x02,ucData,ucSelected);	
}
         
/********************************************************************************************************
** o����y??3?: CardCountUpdateSend
** 1|?��?����?:
** ��? ?? ��?:
**
** ��???  3?:
**
** ��???��?��?:
** �̡¨�??��?��:
**
** ����??  ??: John Tonny
** ��???  ?��: 2005?��05??01��?
**------------------------------------------------------------------------------------------------------
** DT ?? ��?:
** ��???  ?��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardCountUpdateSend(INT8U ucMode,INT8U ucSelected)
{
  INT8U ucData[32];
  INT8U ucType=DEV_TYPE();
  INT8U ucCmd;
	
  ucCmd=DISPLAY_WRITING_MSG;
  Box_TaskLcdQPost(&App_TaskLcdTCB,&ucCmd,1);
    
  if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_GIN_TYPE || ucType==SMALL_THIN_IN_TYPE || ucType==SMALL_THIN_GIN_TYPE){
    //�տ�
    if(!ucMode){
      if(m_usrBoxInfo[BOX_FIRST].ucCounts>=m_usrBoxInfo[BOX_FIRST].ucMaxCounts-1){
        BuzzSet(4,50,50,BUZZ_SK_FULL_PRIOR);
      }else if(m_usrBoxInfo[BOX_FIRST].ucCounts>m_usrBoxInfo[BOX_FIRST].ucAlarmMax-1){
        BuzzSet(2,50,50,BUZZ_SK_MAX_PRIOR);
      }
    }
  }else{
    //����
    if(!ucMode){
      if(m_usrBoxInfo[BOX_FIRST].ucCounts==1){
        BuzzSet(4,50,50,BUZZ_FK_ZERO_PRIOR);
      }else if(m_usrBoxInfo[BOX_FIRST].ucCounts<=m_usrBoxInfo[BOX_FIRST].ucAlarmMin+1){
        BuzzSet(2,50,50,BUZZ_FK_MIN_PRIOR);
      }
    }
  }
          
  if(m_ucCardBoxTxSeq==0x80){
    m_ucCardBoxTxSeq=0x0F;
  }
  m_ucCardBoxTxSeq++;
  m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled=1;
#if BOARD_OLD_EN==0  
  ucData[0]=m_usrBoxInfo[ucSelected].usrCountResponse.ucNewCount;
  ucData[1]=0x00;
  ucData[2]=m_ucCardBoxTxSeq;
  UartPack(UART_COUNT_SET_WRITE,UART_RESPONSE_MODE,3,ucData,ucSelected);
  UartPack(UART_COUNT_SET_WRITE,UART_RESPONSE_MODE,3,ucData,ucSelected);
#else
  ucData[0]=BOX_UART_SEND_MSG;
  ucData[1]=UART_COUNT_SUB_CMD;
  ucData[2]=UART_RESPONSE_MODE;
  ucData[3]=ucSelected;
  
  ucData[4]=m_usrBoxInfo[ucSelected].usrCountResponse.ucNewCount;
  ucData[5]=0x00;
  ucData[6]=m_ucCardBoxTxSeq;
  BoxPostMsg(ucData,7);
#endif  
}       


/********************************************************************************************************
** o����y??3?: BoxMotoMoveDown
** 1|?��?����?:
** ��? ?? ��?:
**
** ��???  3?:
**
** ��???��?��?:
** �̡¨�??��?��:
**
** ����??  ??: John Tonny
** ��???  ?��: 2005?��05??01��?
**------------------------------------------------------------------------------------------------------
** DT ?? ��?:
** ��???  ?��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void BoxMotoMoveDown(INT16U uiCount,INT8U ucSelected)
{
  INT8U ucData[32];
  
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }	

#if BOARD_OLD_NE==0  
  ucData[0]=(INT8U)(uiCount&0xFF);
  ucData[1]=(INT8U)(uiCount>>8);
  ucData[2]=1;
  ucData[3]=m_ucCardBoxTxSeq;
  
  UartPack(CARDMACHINE_CLOSE_DOOR_CMD,UART_RESPONSE_MODE,4,ucData,ucSelected);
#else
  ucData[0]=BOX_UART_SEND_MSG;
  ucData[1]=CARDMACHINE_CLOSE_DOOR_CMD;
  ucData[2]=UART_RESPONSE_MODE;
  ucData[3]=ucSelected;
  
  ucData[4]=(INT8U)(uiCount&0xFF);
  ucData[5]=(INT8U)(uiCount>>8);
  ucData[6]=1;
  ucData[7]=m_ucCardBoxTxSeq;
  
  BoxPostMsg(ucData,8);
#endif  
}


/********************************************************************************************************
** o����y??3?: CardBoxPosReset
** 1|?��?����?:
** ��? ?? ��?:
**
** ��???  3?:
**
** ��???��?��?:
** �̡¨�??��?��:
**
** ����??  ??: John Tonny
** ��???  ?��: 2005?��05??01��?
**------------------------------------------------------------------------------------------------------
** DT ?? ��?:
** ��???  ?��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxInfoReset(INT8U ucSelected)
{		
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
    
  m_usrBoxInfo[ucSelected].ucCounts=0;
  m_usrBoxInfo[ucSelected].ucMaxCounts=0;
  m_usrBoxInfo[ucSelected].ulMachineId=0;
  m_usrBoxInfo[ucSelected].ucAlarmMax=0;	
  m_usrBoxInfo[ucSelected].ucAlarmMin=0;

  m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected=0;
  m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest=0;
  m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCountWrited=0;
  m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos=0;
}


/********************************************************************************************************
** ��������: CardBoxConnectReset
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxConnectReset(INT8U ucSelected)
{
  m_usrBoxInfo[ucSelected].usrConnectResponse.ucRetrys=5;	
}

/********************************************************************************************************
** ��������: CardBoxCountReset
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxCountReset(INT8U ucSelected)
{
  m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled=0;
  m_usrBoxInfo[ucSelected].usrCountResponse.ucRetrys=5;
  m_usrBoxInfo[ucSelected].usrCountResponse.ulMachineId=0;	
  m_usrBoxInfo[ucSelected].usrCountResponse.ucCurrentCount=0;
  m_usrBoxInfo[ucSelected].usrCountResponse.ucNewCount=0;
}

/********************************************************************************************************
** ��������: CardBoxPosReset
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void CardBoxPosReset(INT8U ucSelected)
{
  m_usrBoxInfo[ucSelected].usrFlag.usrBit.bPosErr=0;  
  m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums=CARDBOX_POS_ERR_NUMS;
  m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrRetrys=CARDBOX_POS_ERR_RETRYS;  
}

/********************************************************************************************************
** ��������: BoxLoadEvent
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void BoxLoadEvent(INT8U ucSelected)
{
  INT8U ucTmp;
  INT8U ucType=DEV_TYPE();
  
  if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
  #if BOX_ID_CONST_EN==1
    m_usrBoxInfo[ucSelected].ulMachineId=12345678;
  #endif
    if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
      CardBoxSetSelected(BOX_THIRD,BOX_POWER_ON_MODE);
    }
    return;
  }
  
  //װ��
  if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad){
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad=1;
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxUnload=0;
    
  #if BOARD_OLD_EN==0
    CardBoxSetSelected(ucSelected,BOX_POWER_ON_MODE);    
  #else
    CardBoxPower(BOX_POWER_ON_MODE);
  #endif    
    
    if(EepromReadVerifyBytes(CARDMACHINE_MAXCOUNT_ADDR,&ucTmp,1)){
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        ucTmp=CARDMACHINE_MAX_COUNTS;
        EepromWriteVerifyBytes(CARDMACHINE_MAXCOUNT_ADDR,&ucTmp,1);
      }
    }else{
      ucTmp=CARDMACHINE_MAX_COUNTS;
      EepromWriteVerifyBytes(CARDMACHINE_MAXCOUNT_ADDR,&ucTmp,1);
    }
    m_usrBoxInfo[ucSelected].ucMaxCounts=ucTmp;

    if(EepromReadVerifyBytes(CARDMACHINE_ALARM_MAX_ADDR,&ucTmp,1)){
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        ucTmp=CARDMACHINE_ALARM_MAX_COUNTS;
        EepromWriteVerifyBytes(CARDMACHINE_ALARM_MAX_ADDR,&ucTmp,1);
      }
    }else{
      ucTmp=CARDMACHINE_ALARM_MAX_COUNTS;
      EepromWriteVerifyBytes(CARDMACHINE_ALARM_MAX_ADDR,&ucTmp,1);
    }
    m_usrBoxInfo[ucSelected].ucAlarmMax=ucTmp;

    if(EepromReadVerifyBytes(CARDMACHINE_ALARM_MIN_ADDR,&ucTmp,1)){
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        ucTmp=CARDMACHINE_ALARM_MIN_COUNTS;
        EepromWriteVerifyBytes(CARDMACHINE_ALARM_MIN_ADDR,&ucTmp,1);
      }
    }else{
      ucTmp=CARDMACHINE_ALARM_MIN_COUNTS;
      EepromWriteVerifyBytes(CARDMACHINE_ALARM_MIN_ADDR,&ucTmp,1);
    }
    m_usrBoxInfo[ucSelected].ucAlarmMin=ucTmp;    
    
    m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrNums=CARDBOX_POS_ERR_NUMS;
    m_usrBoxInfo[ucSelected].usrConnectResponse.ucPosErrRetrys=3;
    CardBoxConnectReset(ucSelected);
    CardBoxCountReset(ucSelected);    
  }
}

/********************************************************************************************************
** ��������: BoxUnloadEvent
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
void BoxUnloadEvent(INT8U ucSelected)
{
  INT8U ucType=DEV_TYPE();
  
  if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
  #if BOX_ID_CONST_EN==1
    m_usrBoxInfo[ucSelected].ulMachineId=0;
  #endif
    return;
  }
  
  //ж��
  if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxUnload){
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad=0;
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxUnload=1;

  #if BOARD_OLD_EN==0
    CardBoxSetSelected(ucSelected,BOX_POWER_OFF_MODE);    
  #else
    CardBoxPower(BOX_POWER_OFF_MODE);
  #endif
    
    m_usrBoxInfo[ucSelected].ucCounts=0;
    m_usrBoxInfo[ucSelected].ucMaxCounts=0;
    m_usrBoxInfo[ucSelected].ulMachineId=0;
    m_usrBoxInfo[ucSelected].ucAlarmMax=0;	
    m_usrBoxInfo[ucSelected].ucAlarmMin=0;

    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected=0;
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest=0;
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCountWrited=0;
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos=0;
    
    m_usrBoxInfo[ucSelected].usrFlag.usrBit.bPosErr=1;
    
  }
}

/********************************************************************************************************
** ��������: BOXLOAD_VALID
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U BOXLOAD_VALID(INT8U ucSelected)
{
	
  INT8U ucBoxLoadBit=m_ucKeyBit[BOXLOAD1_BIT+ucSelected*8];
  INT32U ulTmp;
  
  if(ucSelected<CARDMACHINE_CARDBOX_NUMS){
    ulTmp=GetKey();
    if(CheckBit(ulTmp,ucBoxLoadBit)){
      return TRUE;
    }
  }
  return FALSE;
}


/********************************************************************************************************
** ��������: BoxPostMsg
** ��������:
** �� �� ��:
**
** �䡡  ��:
**
** ȫ�ֱ���:
** ����ģ��:
**
** ����  ��: John Tonny
** �ա�  ��: 2005��05��01��
**------------------------------------------------------------------------------------------------------
** �� �� ��:
** �ա�  ��:
**------------------------------------------------------------------------------------------------------
*******************************************************************************************************/
INT8U BoxPostMsg(INT8U *pucData,INT8U ucLen)
{
  OS_ERR os_err;
  LIB_ERR lib_err;
  CPU_INT08U  *pMsg;   
        
  pMsg= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_BoxPool,
                                   (CPU_SIZE_T) ucLen,
                                   (LIB_ERR  *)&lib_err);
  if(pMsg!=0){
    Mem_Copy(pMsg,pucData,ucLen);
    OSTaskQPost(&App_TaskBoxTCB, pMsg, ucLen, OS_OPT_POST_FIFO, &os_err);
    return TRUE;
  }
  return FALSE;
}

/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/


