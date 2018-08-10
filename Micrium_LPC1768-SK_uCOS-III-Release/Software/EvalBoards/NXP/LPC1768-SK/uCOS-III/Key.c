/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------�ļ���Ϣ---------------------------------------------------------------------------------
*��   ��   ��: Key.C
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

#define KEY_GLOBALS
#include "includes.h"

/********************************************************************************************************
** ��������: KeyDeBounce1
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
void KeyDeBounce1(void)
{
  g_usrGetKey1.ulKeyReady=g_usrGetKey1.ulKeyTemp & g_usrGetKey1.ulKeyInput | g_usrGetKey1.ulKeyReady & (g_usrGetKey1.ulKeyTemp^g_usrGetKey1.ulKeyInput);
  
  g_usrGetKey1.ulKeyTemp=g_usrGetKey1.ulKeyInput;
  
  g_usrGetKey1.ulKeyOutput=g_usrGetKey1.ulKeyReady &(~g_usrGetKey1.ulKeyStore | KEY_REPEAT_INST);   		//?????????????????
  
  g_usrGetKey1.ulKeyStore=g_usrGetKey1.ulKeyReady;
}


/********************************************************************************************************
** ��������: KeyDeBounce
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
void KeyDeBounce(void)
{
  g_usrGetKey.ulKeyReady=g_usrGetKey.ulKeyTemp & g_usrGetKey.ulKeyInput | g_usrGetKey.ulKeyReady & (g_usrGetKey.ulKeyTemp^g_usrGetKey.ulKeyInput);
  
  g_usrGetKey.ulKeyTemp=g_usrGetKey.ulKeyInput;
  
  g_usrGetKey.ulKeyOutput=g_usrGetKey.ulKeyReady &(~g_usrGetKey.ulKeyStore | KEY_REPEAT_INST);   		//?????????????????
  
  g_usrGetKey.ulKeyStore=g_usrGetKey.ulKeyReady;
}

/********************************************************************************************************
** ��������: GetKey
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
INT32U GetKey(void)
{  
  INT8U ucType=DEV_TYPE();

#if BOARD_OLD_EN==0  
  INT32U ulTmp=0;
  INT32U ulMaskBit=0x7F7F7F7F;
  INT32U ulXorBit=0xFFFFFFFF;
          
  ulTmp=(FIO0PIN>>4)&0x3F;
  ulTmp|=(FIO1PIN<<5)&0x40;
  
  ulTmp|=(FIO2PIN<<6)&0x3F00;
  ulTmp|=(FIO1PIN<<10)&0x4000;
  
  ulTmp|=(FIO2PIN<<8)&0x30000;
  ulTmp|=(FIO0PIN<<2)&0x40000;
  ulTmp|=(FIO0PIN<<4)&0x80000;
  ulTmp|=(FIO0PIN<<3)&0x300000;
  ulTmp|=(FIO1PIN<<14)&0x400000;
  
  ulTmp|=(FIO0PIN<<5)&0x0F000000;
  ulTmp|=(FIO2PIN<<17)&0x30000000;
  ulTmp|=(FIO2PIN<<20)&0x40000000;
  
  ulXorBit&=~(1<<m_ucKeyBit[BOXLOAD1_BIT]);
  ulXorBit&=~(1<<m_ucKeyBit[BOXLOAD2_BIT]);
  ulXorBit&=~(1<<m_ucKeyBit[BOXLOAD3_BIT]);
  ulXorBit&=~(1<<m_ucKeyBit[BOX3_REV2_BIT]);
  
  if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
    ulXorBit&=~(1<<m_ucKeyBit[DMOTO2_POSA_BIT]);
  }
  
  ulTmp^=ulXorBit;
  ulTmp&=ulMaskBit;
  
#else
    
  INT32U ulTmp=0;
  INT32U ulMaskBit=0x7F7F7F7F;
  INT32U ulXorBit=0xFFFFFFFF;
          
  ulTmp=(FIO0PIN>>15)&0x07;
  ulTmp|=(FIO0PIN>>16)&0x38;
  
  ulTmp|=(FIO1PIN>>10)&0x3F00;
  
  ulTmp|=(FIO1PIN>>8)&0x3F0000;
  
  ulTmp|=(FIO2PIN<<17)&0x07000000;  
  ulTmp|=(FIO2PIN<<16)&0x380000000;  
  
  ulXorBit&=~(1<<m_ucKeyBit[BOXLOAD1_BIT]);
  ulXorBit&=~(1<<m_ucKeyBit[BOXLOAD2_BIT]);
  ulXorBit&=~(1<<m_ucKeyBit[BOXLOAD3_BIT]);
  ulXorBit&=~(1<<m_ucKeyBit[BOX3_REV2_BIT]);
  
  
  ulTmp^=ulXorBit;
  ulTmp&=ulMaskBit;
  
#endif  
  return ulTmp;
}

/********************************************************************************************************
** ��������: GetKeyOutput
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
INT32U GetKeyOutput(void)
{
  INT32U ulTmp;
  
  CPU_SR_ALLOC();
  
  OS_ENTER_CRITICAL();
  ulTmp=g_usrGetKey.ulKeyOutput;
  OS_EXIT_CRITICAL();
  return ulTmp;
}

/********************************************************************************************************
** ��������: KeyConvert
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
INT32U KeyConvert(INT32U ulData)
{
  INT32U ulTmp=0;
  INT32U ulTmp1;
  INT8U ucType=DEV_TYPE();
  
  if(ucType==LARGE_THICK_OUT_TYPE){
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSE1_BIT]) & 0x01);						//?��?D???��?��?a1?,0:��D?��
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO1_POSA_BIT]) & 0x01)<<1;				//?�����¦�??��1��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO1_POSB_BIT]) & 0x01)<<2;				//?�����¦�??��2��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[BOXLOAD1_BIT]) & 0x01)<<3;						//?��?D1����???a1?,0:����??
    ulTmp|=	(m_usrBoxInfo[BOX_FIRST].ucCounts?1:0)<<4;												//?��?D1?D��D?T?��,0:��D?��
    ulTmp|= (m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCardPos?1:0)<<5;					//?��?D1?��??��D?T��???,0:��???
    ulTmp|= 0<<6;																											//����??��?0��o?��??����??��?1��o?������??	�䨮?��?����?2?��1��??��??����??
    ulTmp|= 0<<7;

    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSE2_BIT]) & 0x01)<<8;					//?��?D???��?��?a1?,0:��D?��
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO2_POSA_BIT]) & 0x01)<<9;				//?�����¦�??��1��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO2_POSB_BIT]) & 0x01)<<10; 			//?�����¦�??��2��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[BOXLOAD2_BIT]) & 0x01)<<11;					//?��?D1����???a1?,0:����??
    ulTmp|=	(m_usrBoxInfo[BOX_SECOND].ucCounts?1:0)<<12;												//?��?D1?D��D?T?��,0:��D?��
    ulTmp|= (m_usrBoxInfo[BOX_SECOND].usrFlag.usrBit.bCardPos?1:0)<<13;				//?��?D1?��??��D?T��???,0:��???
    ulTmp|= 0<<14;																										//����??��?0��o?��??����??��?1��o?������??	�䨮?��?����?2?��1��??��??����??
    ulTmp|= 0<<15;

    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSE3_BIT]) & 0x01)<<16;				//?��?D???��?��?a1?,0:��D?��
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO3_POSA_BIT]) & 0x01)<<17;				//?�����¦�??��1��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO3_POSB_BIT]) & 0x01)<<18; 			//?�����¦�??��2��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[BOXLOAD1_BIT]) & 0x01)<<19;					//?��?D1����???a1?,0:����??
    ulTmp|=	(m_usrBoxInfo[BOX_THIRD].ucCounts?1:0)<<20;												//?��?D1?D��D?T?��,0:��D?��
    ulTmp|= (m_usrBoxInfo[BOX_THIRD].usrFlag.usrBit.bCardPos?1:0)<<21;				//?��?D1?��??��D?T��???,0:��???
    ulTmp|= 0<<22;																										//����??��?0��o?��??����??��?1��o?������??	�䨮?��?����?2?��1��??��??����??
    ulTmp|= 0<<23;
    
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01)<<24;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSB_BIT]) & 0x01)<<25;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSC_BIT]) & 0x01)<<26;
    ulTmp|= ((ulData>>m_ucKeyBit[CARDBOX1_POS_BIT]) & 0x01)<<27;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSD_BIT]) & 0x01)<<28;
    ulTmp|= ((ulData>>m_ucKeyBit[CARDBOX2_POS_BIT]) & 0x01)<<29;
    ulTmp|= ((ulData>>m_ucKeyBit[CARDBOX3_POS_BIT]) & 0x01)<<30;
    ulTmp|= 0<<31;
  }else if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_OUT_TYPE || ucType==SMALL_THICK_GIN_TYPE || ucType==SMALL_THIN_IN_TYPE || ucType==SMALL_THIN_OUT_TYPE || ucType==SMALL_THIN_GIN_TYPE){
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSD_BIT]) & 0x01);							//?��?D???��?��?a1?,0:��D?��
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO1_POSA_BIT]) & 0x01)<<1;				//?�����¦�??��1��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[DMOTO1_POSB_BIT]) & 0x01)<<2;				//?�����¦�??��2��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[BOXLOAD1_BIT]) & 0x01)<<3;						//?��?D1����???a1?,0:����??
    ulTmp|=  (m_usrBoxInfo[BOX_FIRST].ucCounts?1:0)<<4;												//?��?D1?D��D?T?��,0:��D?��
    ulTmp|= (m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bCardPos?1:0)<<5;					//?��?D1?��??��D?T��???,0:��???
    ulTmp|= 0<<6;																											//����??��?0��o?��??����??��?1��o?������??	�䨮?��?����?2?��1��??��??����??
    ulTmp|= 0<<7;
    ulTmp|= 0<<15;
    ulTmp|= 0<<23;
    ulTmp|= 0<<31;
    
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSB_BIT]) & 0x01)<<22;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01)<<24;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSC_BIT]) & 0x01)<<25;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSD_BIT]) & 0x01)<<26;
    ulTmp|= ((ulData>>m_ucKeyBit[CARDBOX1_POS_BIT]) & 0x01)<<27;
  }else if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSE_BIT]) & 0x01);					//?��?D???��?��?a1?,0:��D?��
    ulTmp|= 1<<1;				                                                //?�����¦�??��1��????a1?,0:��???
    ulTmp|= 0<<2;				                                                //?�����¦�??��2��????a1?,0:��???
    ulTmp|= ((ulData>>m_ucKeyBit[BOXLOAD1_BIT]) & 0x01)<<3;					//?��?D1����???a1?,0:����??
    ulTmp|=  (m_usrBoxInfo[BOX_FIRST].ucCounts?1:0)<<4;						//?��?D1?D��D?T?��,0:��D?��
    ulTmp|= 1<<5;					                                        //?��?D1?��??��D?T��???,0:��???
    ulTmp|= 0<<6;																											//����??��?0��o?��??����??��?1��o?������??	�䨮?��?����?2?��1��??��??����??
    ulTmp|= 0<<7;
    ulTmp|= 0<<15;
    ulTmp|= 0<<23;
    ulTmp|= 0<<31;
    
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSA_BIT]) & 0x01)<<24;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSB_BIT]) & 0x01)<<25;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSC_BIT]) & 0x01)<<26;
    ulTmp|= ((ulData>>m_ucKeyBit[CARD_POSD_BIT]) & 0x01)<<27;
  }
  //ulTmp1=((ulTmp>>24) & 0xFF) | ((ulTmp>>8) & 0xFF00) | ((ulTmp<<8) & 0xFF0000) | ((ulTmp<<24) & 0xFF000000);
  
  return ~ulTmp;
}


/********************************************************************************************************
** ��������: KeyProcess
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
void Key_Process(void)
{
  OS_ERR os_err;
  
  INT32U ulTmp;
  static INT32U ulKeyOutputOld;
  INT32U ulKeyOutputNew;
  INT8U i;
  INT8U ucCardPosABit;
  INT8U ucCardPosBBit;
  INT8U ucBoxLoadBit;
  
  INT8U ucCmd;
  
 
  INT8U ucType;
  g_usrGetKey.ulKeyInput=GetKey();
  KeyDeBounce();	
  ulKeyOutputOld=g_usrGetKey.ulKeyOutput;

  while (DEF_TRUE) {                                          /* Task body, always written as an infinite loop.       */
    OSTimeDly(5,OS_OPT_TIME_DLY, &os_err) ;         
    g_usrGetKey.ulKeyInput=GetKey();
    KeyDeBounce();	
      
    ulKeyOutputNew=g_usrGetKey.ulKeyOutput;
    if(ulKeyOutputOld!=ulKeyOutputNew){
      if(!m_usrGlobalFlag.usrBit.bKeyTest){
        ulTmp=KeyConvert(ulKeyOutputNew);
        Uart0Pack(INFTYPE_DEVICE_STATUS,0,0,(INT8U *)&ulTmp,4,1);
      }else{
        ulKeyOutputNew|=0x80808080;
        Uart0Pack(INFTYPE_KEY_TEST_STATUS,0,0,(INT8U *)&ulKeyOutputNew,4,1);
      }
      
      ucType=DEV_TYPE();
      if(CARD_AUTO_MODE()){
        if(ucType==SMALL_THICK_GIN_TYPE){
          if(CheckBit(ulKeyOutputNew,m_ucKeyBit[GIN_KEY_BIT])){
            g_ucGInState=GIN_CARDTOANT_STATE;
            if(m_usrGlobalFlag.usrBit.bGCardToBox){
              m_usrGlobalFlag.usrBit.bGCardToBox=0;
            }else{
              m_usrGlobalFlag.usrBit.bGCardToBox=1;
            }
          }
        }
      }
    
      if(ucType==LARGE_THICK_OUT_TYPE || ucType==SMALL_THICK_OUT_TYPE || ucType==SMALL_THICK_ZIN_TYPE){
        ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
        if((CheckBit(ulKeyOutputOld,ucCardPosABit)!=CheckBit(ulKeyOutputNew,ucCardPosABit))  && m_usrGlobalFlag.usrBit.bWaitTakeOut){
          ulTmp=GetKey();
          if(!CheckBit(ulTmp,ucCardPosABit)){
            //ȡ�߿�Ƭ
            m_usrGlobalFlag.usrBit.bCardTakeout=1;
            m_usrGlobalFlag.usrBit.bWaitTakeOut=0;
            g_ucLedMode=LEDOUT_ON_MODE;
          }
        }
      }
    
      if((ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_ZIN_TYPE)){
        ucCardPosABit=m_ucKeyBit[CARD_POSA_BIT];
        ucCardPosBBit=m_ucKeyBit[CARD_POSB_BIT];
        if((CheckBit(ulKeyOutputOld,ucCardPosABit)!=CheckBit(ulKeyOutputNew,ucCardPosABit))){
          ulTmp=GetKey();
          if(CheckBit(ulTmp,ucCardPosABit) && !CheckBit(ulTmp,ucCardPosBBit)){
            //���뿨Ƭ
            m_usrGlobalFlag.usrBit.bCardPlugIn=1;
            if(!CARD_AUTO_MODE()){
              ucCmd=MOTO_IN_TO_ANT_MSG;
              Box_TaskQPost(&App_TaskActionTCB,&ucCmd,1);  
            }
          }
        }
      }
      
      ulKeyOutputOld=ulKeyOutputNew;
      for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
        ucBoxLoadBit=m_ucKeyBit[BOXLOAD1_BIT+i*8];
        if(CheckBit(ulKeyOutputNew,ucBoxLoadBit)){
          if(BOXLOAD_VALID(i)){
            BoxLoadEvent(i);
          }
        }else{
          if(!BOXLOAD_VALID(i)){
            BoxUnloadEvent(i);
          }
        }
      }

      /*for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
        if(m_usrBoxInfo[i].usrFlag.usrBit.bSelftest){
          if(DEV_TYPE()==SMALL_IN_TYPE || DEV_TYPE()==SMALL_GIN_TYPE){
            if(!CheckBit(m_ulKeyOutput,m_ucKeyBit[CARDBOX1_POS_BIT])){
              OS_ENTER_CRITICAL();
              if(g_usrInterruptFlags[i].usrBit.bCardBoxPosLow){
                g_usrInterruptFlags[i].usrBit.bCardBoxPosLow=0;
                m_usrBoxInfo[i].usrFlag.usrBit.bSelftest=0;													//?��?����20,��?o��?��?����21,��??��1y3������3��
              }
              OS_EXIT_CRITICAL();
            }
          }else{
            //����?��
                  
          }
        }
      }*/
      
      /*pucData= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                       (CPU_SIZE_T) 1,
                                       (LIB_ERR  *)&lib_err);
      if(!pucData){
        return;
      }
      
      OSTaskQPost(&App_TaskBox, pucData, 1, OS_OPT_POST_FIFO, &os_err);
      */
      
    }
  }
  
}

/********************************************************************************************************
** ��������: KeyChange
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
void KeyChange(void)
{
  INT32U ulTmp;
  
  ulTmp=KeyConvert(GetKeyOutput());
  Uart0Pack(INFTYPE_DEVICE_STATUS,0,0,(INT8U *)&ulTmp,4,1);
}




/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/


