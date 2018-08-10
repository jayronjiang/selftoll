/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------�ļ���Ϣ---------------------------------------------------------------------------------
*��   ��   ��: Global.C
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

#define HPI_GLOBALS
#include "includes.h"

unsigned char m_ucCompileDate[]=__DATE__;
unsigned char m_ucCompileTime[]=__TIME__;
unsigned char m_ucVersion[]="V1.00.00";

//Ӧ������:������03ǰһ���ֽ�Ϊ���յ��������ʾ��ȷӦ������


/********************************************************************************************************
** ��������: Uart0LengthProcess
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
INT8U Uart0LengthProcess(CardMachineRxData *pcommData,INT8U ucLen)
{
  if(pcommData->ucLen==ucLen){
    return TRUE;
  }
  Uart0Pack(INFTYPE_INCOMPLETE_ERR,pcommData->ucAddr,pcommData->ucSeq,0,0,0);
  return FALSE;	
}

/********************************************************************************************************
** ��������: SMotoWriteParams
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
void SMotoWriteParams(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,4)){
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<CARDMACHINE_SMOTO_NUMS){
      pcommData->ucData[4]=0x00;
      ucTmp=(INT8U)(atoi((const char *)&pcommData->ucData[1]));
      if(ucTmp<SMOTO_FREQ_600US || ucTmp>SMOTO_FREQ_2500US){
        Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,0,0,0);
        return;
      }
      if(EepromWriteVerifyBytes(SMOTO_FREQ_ADDR+ucSelected*4,&ucTmp,1)){
        m_ucSMotoFreq[ucSelected]=ucTmp;
        Mem_Copy(&ucData[0],pcommData->ucData,4);
        ucData[4]=pcommData->ucCmd;
        Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
      }else{
        ucData[0]=SUBTYPE_ERR_WRITE_INF;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }
    }else{
      ucData[0]=SUBTYPE_ERR_UNKNOW;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: SMotoReadParams
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
void SMotoReadParams(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  INT8U ucSelected;

  if(Uart0LengthProcess(pcommData,1)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<CARDMACHINE_SMOTO_NUMS){
      if(!EepromReadVerifyBytes(SMOTO_FREQ_ADDR+ucSelected*4,&ucTmp,1)){
        ucTmp=SMOTO_FREQ_DEFAULT;
        EepromWriteVerifyBytes(SMOTO_FREQ_ADDR+ucSelected*4,&ucTmp,1);
      }
      if(ucTmp<SMOTO_FREQ_600US || ucTmp>SMOTO_FREQ_2500US){
        ucTmp=SMOTO_FREQ_DEFAULT;
        EepromWriteVerifyBytes(SMOTO_FREQ_ADDR+ucSelected*4,&ucTmp,1);
      }
      ucData[0]=pcommData->ucData[0];
      SprintF(&ucData[1],3,ucTmp);
      ucData[4]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
    }else{
      ucData[0]=SUBTYPE_ERR_UNKNOW;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: DMotoWriteParams
** ��������:
** �� �� ��: ���1�ֽ�+����ٶ�4�ֽ�
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
void DMotoWriteParams(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT16U uiPwm;
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,5)){
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<CARDMACHINE_DMOTO_NUMS){
      pcommData->ucData[5]=0;
      uiPwm=atoi((const char *)&pcommData->ucData[1]);
      if(uiPwm<DMOTO_PWM_700 || uiPwm>DMOTO_FREQ_DEFAULT){
        Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,0,0,0);
        return;
      }
      if(EepromWriteVerifyBytes(DMOTO_PWM_ADDR+ucSelected*4,(INT8U *)&uiPwm,2)){
        m_uiDMotoPwm[ucSelected]=uiPwm;
        Mem_Copy(&ucData[0],pcommData->ucData,5);
        ucData[5]=pcommData->ucCmd;
        Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,6,0);
      }else{
        ucData[0]=SUBTYPE_ERR_WRITE_INF;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }
    }else{
      ucData[0]=SUBTYPE_ERR_UNKNOW;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: DMotoReadParams
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
void DMotoReadParams(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT16U uiPwm;
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,1)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<CARDMACHINE_DMOTO_NUMS){
      if(!EepromReadVerifyBytes(DMOTO_PWM_ADDR+ucSelected*4,(INT8U *)&uiPwm,2)){
        uiPwm=DMOTO_FREQ_DEFAULT;
        EepromWriteVerifyBytes(DMOTO_PWM_ADDR+ucSelected*4,(INT8U *)&uiPwm,2);
      }
      if(uiPwm<DMOTO_PWM_700 || uiPwm>DMOTO_FREQ_DEFAULT){
        uiPwm=DMOTO_FREQ_DEFAULT;
        EepromWriteVerifyBytes(DMOTO_PWM_ADDR+ucSelected*4,(INT8U *)&uiPwm,2);
      }
      SprintF(ucData,4,uiPwm);
      ucData[4]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
    }
  }else{
    ucData[0]=SUBTYPE_ERR_UNKNOW;
    Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
  }
}

/********************************************************************************************************
** ��������: ParamsFlagWrite
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
void ParamsFlagWrite(CardMachineRxData *pcommData,INT8U ucAddr)
{
  INT8U ucData[64];
  INT8U ucTmp;
  
  if(Uart0LengthProcess(pcommData,1)){
    pcommData->ucData[1]=0;
    ucTmp=atoi((const char *)pcommData->ucData);
    if(ucTmp){
      ucTmp=0x01;
    }
    if(EepromWriteVerifyBytes(ucAddr,&ucTmp,1)){
      SprintF(ucData,1,ucTmp);
      ucData[1]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: ParamsFlagRead
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
void ParamsFlagRead(CardMachineRxData *pcommData,INT8U ucAddr)
{
  INT8U ucData[64];
  INT8U ucTmp;
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(!EepromReadVerifyBytes(ucAddr,&ucTmp,1)){
      ucTmp=0x1;
      EepromWriteVerifyBytes(ucAddr,&ucTmp,1);
    }
    SprintF(ucData,1,ucTmp);
    ucData[1]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
  }
}

/********************************************************************************************************
** ��������: AutoOutModeWrite
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
void AutoOutModeWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  
  if(Uart0LengthProcess(pcommData,1)){
    ucTmp=0x01;
    if(pcommData->ucData[0]==0x30){
      ucTmp=0x00;
    }
    if(EepromWriteVerifyBytes(AUTOOUT_MODE_ADDR,&ucTmp,1)){
      SprintF(ucData,1,ucTmp);
      ucData[1]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: AutoOutModeRead
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
void AutoOutModeRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(!EepromReadVerifyBytes(AUTOOUT_MODE_ADDR,&ucTmp,1)){
      ucTmp=0x1;
      EepromWriteVerifyBytes(AUTOOUT_MODE_ADDR,&ucTmp,1);
    }
    SprintF(ucData,1,ucTmp);
    ucData[1]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
  }
}

/********************************************************************************************************
** ��������: BuzzEnWrite
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
void BuzzEnWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp[2];
  
  if(Uart0LengthProcess(pcommData,2)){
    m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bBuzzEn=1;
    ucTmp[0]=0x01;
    if(pcommData->ucData[0]==0x30){
      ucTmp[0]=0x00;
      m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bBuzzEn=0;
    }
    ucTmp[1]=pcommData->ucData[1]&0x03;
    m_usrBoxInfo[BOX_FIRST].ucBuzzMode=ucTmp[1];
    if(EepromWriteVerifyBytes(BUZZ_EN_ADDR,ucTmp,2)){
      SprintF(ucData,1,ucTmp[0]);
      SprintF(&ucData[1],1,ucTmp[1]);
      ucData[2]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,3,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: BuzzEnRead
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
void BuzzEnRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp[2];
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(!EepromReadVerifyBytes(BUZZ_EN_ADDR,ucTmp,2)){
      ucTmp[0]=0x1;
      ucTmp[1]=0x0;
      EepromWriteVerifyBytes(BUZZ_EN_ADDR,ucTmp,2);
    }
    SprintF(ucData,1,ucTmp[0]);
    SprintF(&ucData[1],1,ucTmp[1]);
    ucData[2]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,3,0);
  }
}

/********************************************************************************************************
** ��������: DMotoSelectWrite
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
void DMotoSelectWrite(CardMachineRxData *pcommData)
{  
  INT8U ucData[64];
  INT8U i;
  INT8U j;
  INT8U ucErr=0;
  
  if(Uart0LengthProcess(pcommData,7)){
    for(i=0;i<7;i++){
      ucData[i]=pcommData->ucData[i]-0x30;
      if(i<4 && ucData[i]>=0x34){
        ucErr=1;
        break;
      }
      if(i>=4 && ucData[i]>=0x33){
        ucErr=1;
        break;
      }
    }
    for(i=0;i<4;i++){
      for(j=i+1;j<4;j++){
        if(ucData[i]==ucData[j]){
          ucErr=1;
          break;
        }
      }
    }
    for(i=4;i<7;i++){
      for(j=i+1;j<7;j++){
        if(ucData[i]==ucData[j]){
          ucErr=1;
          break;
        }
      }
    }
    

    if(ucErr){
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,0,0,0);
      return;
    }
    ucData[8]=ucData[0] | (ucData[1]<<4);
    ucData[9]=ucData[2] | (ucData[3]<<4);
    ucData[10]=ucData[4] | (ucData[5]<<4);
    ucData[11]=ucData[6] ;
    if(EepromWriteVerifyBytes(DMOTO_SELECT_ADDR,&ucData[8],4)){
      for(i=0;i<7;i++){
        m_ucDMotoBit[i]=ucData[i];
      }
      Mem_Copy(&ucData[0],pcommData->ucData,7);
      ucData[7]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,8,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: DMotoSelectRead
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
void DMotoSelectRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U i;
  
  if(Uart0LengthProcess(pcommData,0)){			
    DMotoSelectGet(0);
    for(i=0;i<7;i++){
      ucData[i]=m_ucDMotoBit[i]+0x30;
    }
    ucData[7]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,8,0);
  }
}

/********************************************************************************************************
** ��������: SMotoSelectWrite
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
void SMotoSelectWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U i;
  INT8U ucErr=0;
  
  if(Uart0LengthProcess(pcommData,2)){
    for(i=0;i<2;i++){
      ucData[i]=pcommData->ucData[i]-0x30;
      if(ucData[i]>=0x33){
        ucErr=1;
        break;
      }
    }
    if(ucData[0]==ucData[1]){
      ucErr=1;
    }
    
    if(ucErr){
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,0,0,0);
      return;
    }
    if(EepromWriteVerifyBytes(SMOTO_SELECT_ADDR,ucData,2)){
      m_ucSMotoBit[0]=ucData[0];
      m_ucSMotoBit[1]=ucData[1];
      Mem_Copy(&ucData[0],pcommData->ucData,2);
      ucData[2]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,3,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: SMotoSelectRead
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
void SMotoSelectRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  if(Uart0LengthProcess(pcommData,0)){			
    SMotoSelectGet(0);
    ucData[0]=m_ucSMotoBit[0]+0x30;
    ucData[1]=m_ucSMotoBit[1]+0x30;
    ucData[2]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,3,0);
  }
}

/********************************************************************************************************
** ��������: BoxSelectWrite
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
void BoxSelectWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U i;
  INT8U j;
  INT8U ucErr=0;
  
  if(Uart0LengthProcess(pcommData,3)){
    for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
      ucData[i]=pcommData->ucData[i]-0x30;
      if(ucData[i]>=(0x30+CARDMACHINE_CARDBOX_NUMS)){
        ucErr=1;
        break;
      }
    }
    for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
      for(j=i+1;j<CARDMACHINE_CARDBOX_NUMS;j++){
        if(ucData[i]==ucData[j]){
          ucErr=1;
          break;
        }
      }
    }
    
    if(ucErr){
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,0,0,0);
      return;
    }
    ucData[8]=ucData[0] | (ucData[1]<<4);
    ucData[9]=ucData[2];
    if(EepromWriteVerifyBytes(BOX_SELECT_ADDR,&ucData[8],2)){
      m_ucUartBit[0]=ucData[0];
      m_ucUartBit[1]=ucData[1];      
      m_ucUartBit[2]=ucData[2];
      Mem_Copy(&ucData[0],pcommData->ucData,3);
      ucData[3]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,4,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: BoxSelectRead
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
void BoxSelectRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U i;
  
  if(Uart0LengthProcess(pcommData,0)){			
    BoxSelectGet(0);
    for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
      ucData[i]=m_ucUartBit[i]+0x30;
    }
    ucData[3]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,4,0);
  }
}

/********************************************************************************************************
** ��������: KeySelectWrite
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
void KeySelectWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  INT8U i;
  INT8U j;
  INT8U ucErr=0;
  
  CPU_SR_ALLOC();
  
  if(Uart0LengthProcess(pcommData,32)){
    for(i=0;i<32;i++){
      ucData[i]=pcommData->ucData[i]-0x30;
      if(ucData[i]>=0x31){
        ucErr=1;
        break;
      }
    }
    for(i=0;i<32;i++){
      for(j=i+1;j<32;j++){
        if(ucData[i]==ucData[j]){
          ucErr=1;
          break;
        }
      }
    }

    if(ucErr){
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,0,0,0);
      return;
    }
    ucErr=0;
    KeyBitEncode(ucData);
    for(i=0;i<4;i++){
      if(!EepromWriteVerifyBytes(KEY0_SELECT_ADDR+i*8,&ucData[i*6],6)){
        ucErr=1;
        break;
      }
    }
    if(!ucErr){
      KeyBitDecode(ucData);
      OS_ENTER_CRITICAL();
      for(j=0;j<32;j++){
              m_ucKeyBit[j]=ucData[j];
      }
      OS_EXIT_CRITICAL();
      Mem_Copy(&ucData[0],pcommData->ucData,32);
      ucData[32]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,33,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: KeySelectRead
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
void KeySelectRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U i;
  
  if(Uart0LengthProcess(pcommData,0)){			
    KeySelectGet(0);
    for(i=0;i<32;i++){
      ucData[i]=m_ucKeyBit[i]+0x30;
    }
    ucData[32]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,33,0);
  }
}

/********************************************************************************************************
** ��������: UltraSoundWrite
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
void UltraSoundWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp[2];
  
  if(Uart0LengthProcess(pcommData,6)){
    ucData[0]=pcommData->ucData[3];
    pcommData->ucData[3]=0x00;
    ucTmp[0]=atoi((const char *)&pcommData->ucData[0]);
    pcommData->ucData[3]=ucData[0];
    pcommData->ucData[6]=0x00;
    ucTmp[1]=atoi((const char *)&pcommData->ucData[3]);
    if(EepromWriteVerifyBytes(ULTRASOUND_PARAMS_ADDR,ucTmp,2)){
      SprintF(ucData,3,ucTmp[0]);
      SprintF(&ucData[3],3,ucTmp[1]);
      ucData[6]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,7,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: UltraSoundRead
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
void UltraSoundRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp[2];
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(!EepromReadVerifyBytes(ULTRASOUND_PARAMS_ADDR,ucTmp,2)){
      ucTmp[0]=ULTRASOUND_DISTANCE_DEFAULT;
      ucTmp[1]=ULTRASOUND_TIMES_DEFAULT;
      EepromWriteVerifyBytes(ULTRASOUND_PARAMS_ADDR,ucTmp,2);
    }
    SprintF(&ucData[0],3,ucTmp[0]);
    SprintF(&ucData[3],3,ucTmp[1]);
    ucData[6]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,7,0);
  }
}

/********************************************************************************************************
** ��������: GroupSelectWrite
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
void GroupSelectWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  
  if(Uart0LengthProcess(pcommData,1)){
    ucTmp=pcommData->ucData[0]-0x30;
    if(ucTmp<=2){
      if(EepromWriteVerifyBytes(GROUP_SELECT_ADDR,&ucTmp,1)){
        SprintF(ucData,1,ucTmp);
        ucData[1]=pcommData->ucCmd;
        Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
      }else{
        ucData[0]=SUBTYPE_ERR_WRITE_INF;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }
    }else{
      ucData[0]=SUBTYPE_ERR_UNKNOW;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: GroupSelectRead
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
void GroupSelectRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(!EepromReadVerifyBytes(GROUP_SELECT_ADDR,&ucTmp,1)){
      ucTmp=0x00;
      EepromWriteVerifyBytes(GROUP_SELECT_ADDR,&ucTmp,1);
    }
    SprintF(ucData,1,ucTmp);
    ucData[1]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
  }
}

/********************************************************************************************************
** ��������: ScanParamsWrite
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
void ScanParamsWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp[2];
  
  if(Uart0LengthProcess(pcommData,6)){
    ucData[0]=pcommData->ucData[3];
    pcommData->ucData[3]=0x00;
    ucTmp[0]=atoi((const char *)&pcommData->ucData[0]);
    pcommData->ucData[3]=ucData[0];
    pcommData->ucData[6]=0x00;
    ucTmp[1]=atoi((const char *)&pcommData->ucData[3]);
    if(EepromWriteVerifyBytes(SCAN_PARAMS_ADDR,ucTmp,2)){
      SprintF(ucData,3,ucTmp[0]);
      SprintF(&ucData[3],3,ucTmp[1]);
      ucData[6]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,7,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: ScanParamsRead
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
void ScanParamsRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp[2];
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(!EepromReadVerifyBytes(SCAN_PARAMS_ADDR,ucTmp,2)){
      ucTmp[0]=SCAN_OPEN_TIMES;
      ucTmp[1]=SCAN_CLOSE_TIMES;
      EepromWriteVerifyBytes(SCAN_PARAMS_ADDR,ucTmp,2);
    }
    SprintF(&ucData[0],3,ucTmp[0]);
    SprintF(&ucData[3],3,ucTmp[1]);
    ucData[6]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,7,0);
  }
}

/********************************************************************************************************
** ��������: DMotoMove
** ��������: 1�ֽڵ��+1�ֽڷ���(30:����,31����)+3�ֽ�ʱ��
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
void DMotoMove(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT16U uiSteps;
  INT8U ucSelected;
  INT16U uiTime;
  
  if(Uart0LengthProcess(pcommData,7)){	
    ucSelected=0x00;
    if(pcommData->ucData[0]>=0x30 && pcommData->ucData[0]<=0x39){
      ucSelected=pcommData->ucData[0]-0x30;
    }
    if(ucSelected<CARDMACHINE_DMOTO_NUMS){
      pcommData->ucData[7]=0;
      uiTime=(atoi((const char *)&pcommData->ucData[2]));
      uiSteps=m_uiDMotoPwm[ucSelected];
      if(pcommData->ucData[1]==0x30){
        DMotoStart(DMOTO_FREQ_DEFAULT,uiSteps,MOTO_FORWARD_MODE,uiTime,ucSelected);
      }else if(pcommData->ucData[1]==0x31){
        DMotoStart(DMOTO_FREQ_DEFAULT,uiSteps,MOTO_BACKWARD_MODE,uiTime,ucSelected);
      }else{
        MOTO_DC_DISABLED(ucSelected,0);
      }
      ucData[0]=pcommData->ucData[0];
      ucData[1]=pcommData->ucData[1];
      ucData[2]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,3,0);
    }else{
      ucData[0]=SUBTYPE_ERR_UNKNOW;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: SMotoMove
** ��������: 1�ֽڵ��+1�ֽڷ���(30:����,31����)+4�ֽ�������
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
void SMotoMove(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT16U uiSteps;	
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,6)){			
    ucSelected=0x00;
    if(pcommData->ucData[0]>=0x30 && pcommData->ucData[0]<=0x39){
      ucSelected=pcommData->ucData[0]-0x30;
    }
    if(ucSelected<CARDMACHINE_SMOTO_NUMS){
      pcommData->ucData[6]=0;
      uiSteps=(INT16U)(atoi((const char *)&pcommData->ucData[2]));
      if(pcommData->ucData[1]==0x30){
        SMotoStart(m_ucSMotoFreq[ucSelected],uiSteps,MOTO_FORWARD_MODE,ucSelected);
      }else{
        SMotoStart(m_ucSMotoFreq[ucSelected],uiSteps,MOTO_BACKWARD_MODE,ucSelected);
      }
      ucData[0]=pcommData->ucData[0];
      ucData[1]=pcommData->ucData[1];
      ucData[2]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,3,0);
    }else{
      ucData[0]=SUBTYPE_ERR_UNKNOW;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardToBox
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
void CardToBox(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  if(Uart0LengthProcess(pcommData,1)){			
    g_ucGInState=GIN_CARDTOANT_STATE;
    if(pcommData->ucData[0]>=0x31){
      m_usrGlobalFlag.usrBit.bGCardToBox=1;
      m_usrGlobalFlag.usrBit.bGCardToOut=0;
    }else{
      m_usrGlobalFlag.usrBit.bGCardToBox=0;
      m_usrGlobalFlag.usrBit.bGCardToOut=0;
    }
    ucData[0]=pcommData->ucData[0];
    ucData[1]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
  }
}

/********************************************************************************************************
** ��������: CardToOut
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
void CardToOut(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
	
  if(Uart0LengthProcess(pcommData,1)){			
    if(pcommData->ucData[0]==0x31){
      m_usrGlobalFlag.usrBit.bGCardToBox=0;
      m_usrGlobalFlag.usrBit.bGCardToOut=1;
    }else{
      m_usrGlobalFlag.usrBit.bGCardToBox=0;
      m_usrGlobalFlag.usrBit.bGCardToOut=0;
    }
    ucData[0]=pcommData->ucData[0];
    ucData[1]=pcommData->ucCmd;
    Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
  }
}

/********************************************************************************************************
** ��������: KeyTest
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
void KeyTest(CardMachineRxData *pcommData)
{
  INT8U ucData[16]={0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38};
  
  INT32U ulKeyOutput;
  INT8U ucCmd;
  
  CPU_SR_ALLOC();
  if(Uart0LengthProcess(pcommData,9)){		
    if(Mem_Cmp(ucData,&pcommData->ucData[1],8)){
      if(pcommData->ucData[0]==0x31){
        m_usrGlobalFlag.usrBit.bKeyTest=1;
        OS_ENTER_CRITICAL();
        ulKeyOutput=g_usrGetKey.ulKeyOutput | 0x80808080;
        OS_EXIT_CRITICAL();
        Uart0Pack(INFTYPE_KEY_TEST_STATUS,0,0,(INT8U *)&ulKeyOutput,4,1);
        ucCmd=DISPLAY_KEY_TEST_MSG;
        Box_TaskLcdQPost(&App_TaskLcdTCB,&ucCmd,1);
        
      }else{
        m_usrGlobalFlag.usrBit.bKeyTest=0;
        OS_ENTER_CRITICAL();
        g_usrGlobalFlag.usrBit.bGKey=0;
        OS_EXIT_CRITICAL();
        ucCmd=DISPLAY_MAIN_MSG;
        Box_TaskLcdQPost(&App_TaskLcdTCB,&ucCmd,1);
      }
      ucData[0]=pcommData->ucData[0];
      ucData[1]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,2,0);
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineIdWrite
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
void CardMachineIdWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  if(Uart0LengthProcess(pcommData,4)){			
    if(EepromWriteVerifyBytes(CARDMACHINE_ID_ADDR,pcommData->ucData,4)){
      Mem_Copy(ucData,pcommData->ucData,4);
      Uart0Pack(INFTYPE_CARD_DEV_SERIAL,pcommData->ucAddr,pcommData->ucSeq,ucData,4,0);
    }else{
      ucData[0]=SUBTYPE_ERR_WRITE_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineIdRead
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
void CardMachineIdRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(EepromReadVerifyBytes(CARDMACHINE_ID_ADDR,ucData,4)){
      Uart0Pack(INFTYPE_CARD_DEV_SERIAL,pcommData->ucAddr,pcommData->ucSeq,ucData,4,0);
    }else{
      ucData[0]=SUBTYPE_ERR_READ_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineAddrWrite
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
void CardMachineAddrWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  if(Uart0LengthProcess(pcommData,4)){			
    if(pcommData->ucData[0]>=0x10){
      if(EepromWriteVerifyBytes(CARDMACHINE_SELFADDR_ADDR,pcommData->ucData,1)){
        Mem_Copy(ucData,pcommData->ucData,4);
        Uart0Pack(INFTYPE_CARD_DEV_SERIAL,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }else{
        ucData[0]=SUBTYPE_ERR_WRITE_INF;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineAddrRead
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
void CardMachineAddrRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  if(Uart0LengthProcess(pcommData,1)){			
    if(EepromReadVerifyBytes(CARDMACHINE_ID_ADDR,ucData,1)){
      Uart0Pack(ucData[0],pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }else{
      ucData[0]=SUBTYPE_ERR_READ_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineAlarmMaxWrite
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
void CardMachineAlarmMaxWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  INT8U i;
  
  if(Uart0LengthProcess(pcommData,5)){			
    pcommData->ucData[5]=0;
    ucTmp=(INT8U)(atoi((const char *)&pcommData->ucData[1]));
    if(ucTmp<=CARDMACHINE_MAX_COUNTS){
      if(EepromWriteVerifyBytes(CARDMACHINE_ALARM_MAX_ADDR,&ucTmp,1)){
        for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
          m_usrBoxInfo[i].ucAlarmMax=ucTmp;
        }
        Mem_Copy(ucData,pcommData->ucData,5);
        Uart0Pack(INFTYPE_BOX_CRITIMAX,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
      }else{
        ucData[0]=SUBTYPE_ERR_WRITE_INF;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineAlarmMaxRead
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
void CardMachineAlarmMaxRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;	
  
  if(Uart0LengthProcess(pcommData,1)){			
    if(EepromReadVerifyBytes(CARDMACHINE_ALARM_MAX_ADDR,&ucTmp,1)){
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        ucTmp=CARDMACHINE_ALARM_MAX_COUNTS;
        EepromWriteVerifyBytes(CARDMACHINE_ALARM_MAX_ADDR,&ucTmp,1);
      }
      ucData[0]=pcommData->ucData[0];
      SprintF(&ucData[1],4,ucTmp);
      Uart0Pack(INFTYPE_BOX_CRITIMAX,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
    }else{
      ucData[0]=SUBTYPE_ERR_READ_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineAlarmMinWrite
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
void CardMachineAlarmMinWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  INT8U i;
  
  if(Uart0LengthProcess(pcommData,5)){			
    pcommData->ucData[5]=0;
    ucTmp=(INT8U)(atoi((const char *)&pcommData->ucData[1]));
    if(ucTmp<=CARDMACHINE_MAX_COUNTS){
      if(EepromWriteVerifyBytes(CARDMACHINE_ALARM_MIN_ADDR,&ucTmp,1)){
        for(i=0;i<CARDMACHINE_CARDBOX_NUMS;i++){
          m_usrBoxInfo[i].ucAlarmMin=ucTmp;
        }
        Mem_Copy(ucData,pcommData->ucData,5);
        Uart0Pack(INFTYPE_BOX_CRITIMIN,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
      }else{
        ucData[0]=SUBTYPE_ERR_WRITE_INF;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineAlarmMinRead
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
void CardMachineAlarmMinRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;	
  
  if(Uart0LengthProcess(pcommData,1)){			
    if(EepromReadVerifyBytes(CARDMACHINE_ALARM_MIN_ADDR,&ucTmp,1)){
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        ucTmp=CARDMACHINE_ALARM_MIN_COUNTS;
        EepromWriteVerifyBytes(CARDMACHINE_ALARM_MIN_ADDR,&ucTmp,1);
      }
      ucData[0]=pcommData->ucData[0];
      SprintF(&ucData[1],4,ucTmp);
      Uart0Pack(INFTYPE_BOX_CRITIMIN,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
    }else{
      ucData[0]=SUBTYPE_ERR_READ_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineMaxCountWrite
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
void CardMachineMaxCountWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  
  if(Uart0LengthProcess(pcommData,5)){			
    pcommData->ucData[5]=0;
    ucTmp=(INT8U)(atoi((const char *)&pcommData->ucData[1]));
    if(ucTmp<=CARDMACHINE_MAX_COUNTS){
      if(EepromWriteVerifyBytes(CARDMACHINE_MAXCOUNT_ADDR,&ucTmp,1)){
        Mem_Copy(ucData,pcommData->ucData,5);
        Uart0Pack(INFTYPE_CARD_DEV_SERIAL,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
      }else{
        ucData[0]=SUBTYPE_ERR_WRITE_INF;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineMaxCountRead
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
void CardMachineMaxCountRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;	
  
  if(Uart0LengthProcess(pcommData,1)){			
    if(EepromReadVerifyBytes(CARDMACHINE_MAXCOUNT_ADDR,&ucTmp,1)){
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        ucTmp=CARDMACHINE_MAX_COUNTS;
        EepromWriteVerifyBytes(CARDMACHINE_MAXCOUNT_ADDR,&ucTmp,1);
      }
      ucData[0]=pcommData->ucData[0];
      SprintF(&ucData[1],4,ucTmp);
      Uart0Pack(ucData[0],pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
    }else{
      ucData[0]=SUBTYPE_ERR_READ_INF;
      Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineStateRead
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
void CardMachineStateRead(CardMachineRxData *pcommData)
{
  INT32U ulTmp;
  
  CPU_SR_ALLOC();
  if(Uart0LengthProcess(pcommData,0)){		
    OS_ENTER_CRITICAL();
    ulTmp=~g_usrGetKey.ulKeyOutput;
    OS_EXIT_CRITICAL();
    Uart0Pack(INFTYPE_DEVICE_STATUS,pcommData->ucAddr,pcommData->ucSeq,(INT8U *)&ulTmp,4,0);
  }
}

/********************************************************************************************************
** ��������: CardMachineTypeRead
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
void CardMachineTypeRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  
  if(Uart0LengthProcess(pcommData,0)){			
    if(DEV_TYPE()==SMALL_THICK_OUT_TYPE){
      //С������
      ucData[0]=SMALL_THICK_OUT_DEVICE_TYPE;
      Uart0Pack(INFTYPE_DEVICE_TYPE,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }else if(DEV_TYPE()==SMALL_THICK_IN_TYPE){
      //С�տ���
      ucData[0]=SMALL_THICK_IN_DEVICE_TYPE;
      Uart0Pack(INFTYPE_DEVICE_TYPE,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }else if(DEV_TYPE()==LARGE_THICK_OUT_TYPE){
      ucData[0]=LARGE_THICK_OUT_DEVICE_TYPE;
      Uart0Pack(INFTYPE_DEVICE_TYPE,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }else if(DEV_TYPE()==SMALL_THICK_GIN_TYPE){
      ucData[0]=SMALL_THICK_GIN_DEVICE_TYPE;
      Uart0Pack(INFTYPE_DEVICE_TYPE,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }else if(DEV_TYPE()==SMALL_THICK_ZIN_TYPE){
      ucData[0]=SMALL_THICK_IN_DEVICE_TYPE;
      Uart0Pack(INFTYPE_DEVICE_TYPE,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
    }else{
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineVersionRead
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
void CardMachineVersionRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucLen;
  
  if(Uart0LengthProcess(pcommData,1)){	
    ucLen=GetVersion(ucData);
    Uart0Pack(INFTYPE_DEVICE_VER,pcommData->ucAddr,pcommData->ucSeq,ucData,ucLen,0);
  }
}

/********************************************************************************************************
** ��������: CardMachineDataRead
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
void CardMachineDataRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8S usLen;
  INT8S usAddr;
  INT8S usAddr1;
  
  if(Uart0LengthProcess(pcommData,3)){	
    usAddr=AscToByte(pcommData->ucData[0]);
    usAddr1=AscToByte(pcommData->ucData[1]);
    usLen=AscToByte(pcommData->ucData[2]);
    if(usAddr<0 || usAddr1<0 || usLen<0){
      return;
    }
    usAddr=(usAddr<<4)+usAddr1;
    usAddr=(usAddr/8)*8;
    if(usAddr+usLen<256 && usLen<=8){
      ucData[0]=pcommData->ucData[0];
      ucData[1]=pcommData->ucData[1];
      ucData[2]=pcommData->ucData[2];
      EepromReadBytes((INT8U)usAddr,&ucData[32],(INT8U)usLen);
      BytesToAscs(&ucData[32],(INT8U)usLen,&ucData[3]);
      ucData[3+usLen*2]=pcommData->ucCmd;
      Uart0Pack(pcommData->ucCmd,pcommData->ucAddr,pcommData->ucSeq,ucData,4+usLen*2,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardMachineDataWrite
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
void CardMachineDataWrite(CardMachineRxData *pcommData)
{
  if(Uart0LengthProcess(pcommData,0)){	
          
  }
}

/********************************************************************************************************
** ��������: CardBoxVersionRead
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
void CardBoxVersionRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,1)){	
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
    #if BOARD_OLD_EN==0
      ucData[0]=pcommData->ucSeq;
      UartPack(CARDMACHINE_READ_VERSION_CMD,UART_RESPONSE_MODE,1,ucData,ucSelected);
    #else
      ucData[0]=BOX_UART_SEND_MSG;
      ucData[1]=CARDMACHINE_READ_VERSION_CMD;
      ucData[2]=UART_RESPONSE_MODE;
      ucData[3]=ucSelected;
      
      ucData[4]=pcommData->ucSeq;
      BoxPostMsg(ucData,5);
    #endif          
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxIdWrite
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
void CardBoxIdWrite(CardMachineRxData *pcommData)
{
  INT8U ucSelected;	
  INT8U ucData[64];
  INT32U *pulTmp;
  
  if(Uart0LengthProcess(pcommData,9)){		
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
    #if BOARD_OLD_EN==0
      pulTmp=(INT32U *)&ucData[0];
      pcommData->ucData[9]=0;
      *pulTmp=atoi((const char *)&pcommData->ucData[1]);
      if(*pulTmp>99999999){
        Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      }else{
        ucData[4]=pcommData->ucSeq;
        UartPack(CARDMACHINE_WRITE_MACHINE_ID_CMD,UART_RESPONSE_MODE,5,ucData,ucSelected);
      }
    #else
      pulTmp=(INT32U *)&ucData[4];
      pcommData->ucData[9]=0;
      *pulTmp=atoi((const char *)&pcommData->ucData[1]);
      if(*pulTmp>99999999){
        Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      }else{
        ucData[0]=BOX_UART_SEND_MSG;
        ucData[1]=CARDMACHINE_WRITE_MACHINE_ID_CMD;
        ucData[2]=UART_RESPONSE_MODE;
        ucData[3]=ucSelected;
        
        ucData[8]=pcommData->ucSeq;
        BoxPostMsg(ucData,9);
      }
    #endif
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxIdRead
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

*******************************************************************************************************/
void CardBoxIdRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucSelected;	
  INT8U ucType=DEV_TYPE();
  
  if(Uart0LengthProcess(pcommData,1)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
      if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
        ucData[0]=pcommData->ucData[0];
        if(m_usrBoxInfo[ucSelected].ulMachineId>99999999){
          m_usrBoxInfo[ucSelected].ulMachineId=99999999;
        }
        SprintF(&ucData[1],8,m_usrBoxInfo[ucSelected].ulMachineId);
        Uart0Pack(INFYPTE_CARD_BOX_SERIAL,pcommData->ucAddr,pcommData->ucSeq,ucData,9,0);
      }else{
        if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad && m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
          ucData[0]=pcommData->ucData[0];
          if(m_usrBoxInfo[ucSelected].ulMachineId>99999999){
            m_usrBoxInfo[ucSelected].ulMachineId=99999999;
          }
          SprintF(&ucData[1],8,m_usrBoxInfo[ucSelected].ulMachineId);
          Uart0Pack(INFYPTE_CARD_BOX_SERIAL,pcommData->ucAddr,pcommData->ucSeq,ucData,9,0);
        }
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxCountWrite
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
void CardBoxCountWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,5)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
      pcommData->ucData[5]=0;
      ucTmp=(INT8U)(atoi((const char *)&pcommData->ucData[1]));
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      }else{
        if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled){
          ucData[0]=SUBTYPE_ERR_DEVICE_BUSY;
          Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
        }else{
        #if BOARD_OLD_EN==0          
          ucData[0]=ucTmp;
          ucData[1]=0x00;
          ucData[2]=pcommData->ucSeq;
          UartPack(UART_COUNT_SET_WRITE,UART_RESPONSE_MODE,3,ucData,ucSelected);
        #else
          ucData[0]=BOX_UART_SEND_MSG;
          ucData[1]=UART_COUNT_SET_WRITE;
          ucData[2]=UART_RESPONSE_MODE;
          ucData[3]=ucSelected;
          
          ucData[4]=ucTmp;
          ucData[5]=0x00;
          ucData[6]=pcommData->ucSeq;
          BoxPostMsg(ucData,7);
        #endif          
        }
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxCountRead
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
void CardBoxCountRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucSelected;	
  INT8U ucType=DEV_TYPE();
  
  if(Uart0LengthProcess(pcommData,1)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
      if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
        ucData[0]=pcommData->ucData[0];
        SprintF(&ucData[1],4,m_usrBoxInfo[ucSelected].ucCounts);
        Uart0Pack(INFTYPE_CARD_COUNT,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
      }else{
        if(m_usrBoxInfo[ucSelected].usrFlag.usrBit.bBoxLoad && m_usrBoxInfo[ucSelected].usrFlag.usrBit.bConnected){
          ucData[0]=pcommData->ucData[0];
          SprintF(&ucData[1],4,m_usrBoxInfo[ucSelected].ucCounts);
        #if COUNT_ID_EN==0          
          Uart0Pack(INFTYPE_CARD_COUNT,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
        #else
          SprintF(&ucData[5],8,m_usrBoxInfo[ucSelected].ulMachineId);
          Uart0Pack(INFTYPE_CARD_COUNT,pcommData->ucAddr,pcommData->ucSeq,ucData,13,0);
        #endif          
        }
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxCountWrite
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
void CardBoxMaxCountWrite(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucTmp;
  INT8U i;
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,5)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
      pcommData->ucData[5]=0;
      for(i=0;i<4;i++){
        if(AscToByte(pcommData->ucData[i])<0){
          pcommData->ucData[i]=0x30;
        }
      }
      ucTmp=(INT8U)(atoi((const char *)&pcommData->ucData[1]));
      if(ucTmp>CARDMACHINE_MAX_COUNTS){
        Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
      }else{
        if(!EepromWriteVerifyBytes(CARDMACHINE_MAXCOUNT_ADDR,&ucTmp,1)){
          ucData[0]=SUBTYPE_ERR_WRITE_INF;
          Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
        }
        Uart0Pack(INFTYPE_CARD_COUNT_MAX,pcommData->ucAddr,pcommData->ucSeq,&pcommData->ucData[0],5,0);
        
        m_usrBoxInfo[ucSelected].ucMaxCounts=ucTmp;
      #if BOARD_OLD_EN==0        
        ucData[0]=ucTmp;
        ucData[1]=0x00;
        ucData[2]=pcommData->ucSeq;
        UartPack(CARDMACHINE_WRITE_COUNT_MAX_CMD,UART_RESPONSE_MODE,3,ucData,ucSelected);
      #else
        ucData[0]=BOX_UART_SEND_MSG;
        ucData[1]=CARDMACHINE_WRITE_COUNT_MAX_CMD;
        ucData[2]=UART_RESPONSE_MODE;
        ucData[3]=ucSelected;
        
        ucData[4]=ucTmp;
        ucData[5]=0x00;
        ucData[6]=pcommData->ucSeq;
        BoxPostMsg(ucData,7);
      #endif          
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxMaxCountRead
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
void CardBoxMaxCountRead(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucSelected;	
  INT8U ucType=DEV_TYPE();
  
  if(Uart0LengthProcess(pcommData,1)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
      if(ucType==SMALL_THICK_ZIN_TYPE || ucType==SMALL_THIN_ZIN_TYPE){
        ucData[0]=pcommData->ucData[0];
        SprintF(&ucData[1],4,500);
        Uart0Pack(INFTYPE_CARD_COUNT_MAX,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
      }else{
        ucData[0]=pcommData->ucData[0];
        SprintF(&ucData[1],4,m_usrBoxInfo[ucSelected].ucMaxCounts);
        Uart0Pack(INFTYPE_CARD_COUNT_MAX,pcommData->ucAddr,pcommData->ucSeq,ucData,5,0);
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxRecordInit
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
void CardBoxRecordInit(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucSelected;	
  
  if(Uart0LengthProcess(pcommData,1)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
      if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled){
        ucData[0]=SUBTYPE_ERR_DEVICE_BUSY;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }else{
      #if BOARD_OLD_EN==0        
        ucData[0]=pcommData->ucSeq;
        UartPack(CARDMACHINE_RECORD_INIT_CMD,UART_RESPONSE_MODE,1,ucData,ucSelected);
      #else
        ucData[0]=BOX_UART_SEND_MSG;
        ucData[1]=CARDMACHINE_RECORD_INIT_CMD;
        ucData[2]=UART_RESPONSE_MODE;
        ucData[3]=ucSelected;
        
        ucData[4]=pcommData->ucSeq;
        BoxPostMsg(ucData,5);
      #endif
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxCountAddSub
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
void CardBoxCountAddSub(CardMachineRxData *pcommData)
{
  INT8U ucData[64];
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,2)){
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
      if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled){
        ucData[0]=SUBTYPE_ERR_DEVICE_BUSY;
        Uart0Pack(INFTYPE_DEVICE_ERR,pcommData->ucAddr,pcommData->ucSeq,ucData,1,0);
      }else{
        if(pcommData->ucData[1]==0x30){
        #if BOARD_OLD_EN==0        
          ucData[0]=pcommData->ucSeq;
          UartPack(UART_COUNT_ADD_CMD,UART_RESPONSE_MODE,1,ucData,ucSelected);
        #else
          ucData[0]=BOX_UART_SEND_MSG;
          ucData[1]=UART_COUNT_ADD_CMD;
          ucData[2]=UART_RESPONSE_MODE;
          ucData[3]=ucSelected;
          
          ucData[4]=pcommData->ucSeq;
          BoxPostMsg(ucData,5);
        #endif
        }else if(pcommData->ucData[1]==0x31){
        #if BOARD_OLD_EN==0        
          ucData[0]=pcommData->ucSeq;
          UartPack(UART_COUNT_SUB_CMD,UART_RESPONSE_MODE,1,ucData,ucSelected);
        #else
          ucData[0]=BOX_UART_SEND_MSG;
          ucData[1]=UART_COUNT_SUB_CMD;
          ucData[2]=UART_RESPONSE_MODE;
          ucData[3]=ucSelected;
          
          ucData[4]=pcommData->ucSeq;
          BoxPostMsg(ucData,5);
        #endif
        }else{
          Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
        }
      }
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxMotoMove
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
void CardBoxMotoMove(CardMachineRxData *pcommData)
{
  INT8U ucData[32];
  INT8U ucSelected;
  
  if(Uart0LengthProcess(pcommData,2)){			
    ucSelected=pcommData->ucData[0]-0x30;
    if(ucSelected<=CARDMACHINE_CARDBOX_NUMS-1){
    #if BOARD_OLD_EN==0      
      ucData[0]=0xA2;
      ucData[1]=0x06;
      ucData[2]=pcommData->ucData[1]-0x30;
      ucData[3]=pcommData->ucSeq;
      
      UartPack(CARDMACHINE_CLOSE_DOOR_CMD,UART_RESPONSE_MODE,4,ucData,ucSelected);
    #else
      ucData[0]=BOX_UART_SEND_MSG;
      ucData[1]=UART_COUNT_SUB_CMD;
      ucData[2]=UART_RESPONSE_MODE;
      ucData[3]=ucSelected;
      
      ucData[4]=0xA2;
      ucData[5]=0x06;
      ucData[6]=pcommData->ucData[1]-0x30;
      ucData[7]=pcommData->ucSeq;
      BoxPostMsg(ucData,8);
    #endif
    }else{
      Uart0Pack(INFTYPE_FORMAT_ERR,pcommData->ucAddr,pcommData->ucSeq,NULL,0,0);
    }
  }
}

/********************************************************************************************************
** ��������: UartLengthProcess
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
INT8U UartLengthProcess(CommRxData *pcommData,INT8U ucLen)
{
  if(pcommData->ucLen==UART_BASIC_RSP_LEN+ucLen){
    return TRUE;
  }	
  return FALSE;		
}

/********************************************************************************************************
** ��������: CardBoxRecordInitResponse
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
void CardBoxRecordInitResponse(CommRxData *pcommData,INT8U ucSelected)
{
  INT8U ucData[32];
  
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  if(UartLengthProcess(pcommData,0)){
    if(!pcommData->ucStatus){
      m_usrBoxInfo[ucSelected].ucCounts=0;
      ucData[0]=ucSelected+0x30;
      SprintF(&ucData[1],4,m_usrBoxInfo[ucSelected].ucCounts);
    #if COUNT_ID_EN==0          
      Uart0Pack(INFTYPE_CARD_COUNT,m_ucMachineAddr,pcommData->ucData[0],ucData,5,0);
    #else
      SprintF(&ucData[5],8,m_usrBoxInfo[ucSelected].ulMachineId);
      Uart0Pack(INFTYPE_CARD_COUNT,m_ucMachineAddr,pcommData->ucData[0],ucData,13,0);
    #endif          
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxMachineIdResponse
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
void CardBoxMachineIdResponse(CommRxData *pcommData,INT8U ucSelected)
{
  INT8U ucData[32];
	
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  if(UartLengthProcess(pcommData,4)){
    if(!pcommData->ucStatus){
      m_usrBoxInfo[ucSelected].ulMachineId=*((int32u *)&pcommData->ucData[0]);
      ucData[0]=ucSelected+0x30;
      SprintF(&ucData[1],8,m_usrBoxInfo[ucSelected].ulMachineId);
      Uart0Pack(INFYPTE_CARD_BOX_SERIAL,m_ucMachineAddr,pcommData->ucData[4],ucData,9,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxBasicInfoResponse
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
void CardBoxBasicInfoResponse(CommRxData *pcommData,INT8U ucSelected)
{
  INT8U ucBit;	
  INT8U ucData[64];
  INT8U ucType=DEV_TYPE();
  
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  if(UartLengthProcess(pcommData,9)){
    CardBoxConnectReset(ucSelected);
    if(!pcommData->ucStatus){
      ucBit=m_ucKeyBit[BOXLOAD1_BIT+ucSelected*8];
      if(!CheckBit(g_usrGetKey.ulKeyOutput,ucBit)){
        return;
      }
                                                      
      if(m_usrBoxInfo[ucSelected].ucCounts!=pcommData->ucData[4]){
        ucData[0]=DISPLAY_MAIN_MSG;
        Box_TaskLcdQPost(&App_TaskLcdTCB,ucData,1);
      }
      
      m_usrBoxInfo[ucSelected].ulMachineId=*((int32u *)&pcommData->ucData[0]);
      m_usrBoxInfo[ucSelected].ucCounts=pcommData->ucData[4];
      m_usrBoxInfo[ucSelected].ucBoxMaxCounts=pcommData->ucData[6];
      
      if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled && m_usrBoxInfo[ucSelected].ucCounts==m_usrBoxInfo[ucSelected].usrCountResponse.ucNewCount){
        CardBoxCountReset(ucSelected);
      }
      
      if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THICK_GIN_TYPE){
        //�տ�
        if((pcommData->ucData[8]&0x03)==0x02){
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos=1;												//��λ
          if(!m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest){
            CardBoxPosReset(ucSelected);
          }
        }else{
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos=0;
        }
      }else if(ucType==SMALL_THICK_OUT_TYPE || ucType==LARGE_THICK_OUT_TYPE){
        //����
        if((pcommData->ucData[8]&0x03)==0x01){
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos=1;												//��λ
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bSelftest=0;
          CardBoxPosReset(ucSelected);
        }else{
          m_usrBoxInfo[ucSelected].usrFlag.usrBit.bCardPos=0;
        }
      }
      BoxConnected(ucSelected);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxCountAddSubResponse
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
void CardBoxCountAddSubResponse(CommRxData *pcommData,INT8U ucSelected)
{
  INT8U ucData[32];
	
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  if(UartLengthProcess(pcommData,2)){
    if(!pcommData->ucStatus){
      if(m_usrBoxInfo[ucSelected].ucCounts!=pcommData->ucData[0]){
        ucData[0]=DISPLAY_MAIN_MSG;
        Box_TaskLcdQPost(&App_TaskLcdTCB,ucData,1);
      }
      
      m_usrBoxInfo[ucSelected].ucCounts=pcommData->ucData[0];
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
}

/********************************************************************************************************
** ��������: CardBoxCountResponse
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
void CardBoxCountResponse(CommRxData *pcommData,INT8U ucSelected)
{
  INT8U ucData[32];
      
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  if(UartLengthProcess(pcommData,2)){
    if(!pcommData->ucStatus){
      if(m_usrBoxInfo[ucSelected].ucCounts!=pcommData->ucData[0]){
        ucData[0]=DISPLAY_MAIN_MSG;
        Box_TaskLcdQPost(&App_TaskLcdTCB,ucData,1);
      }
      m_usrBoxInfo[ucSelected].ucCounts=pcommData->ucData[0];
      
      if(m_usrBoxInfo[ucSelected].usrCountResponse.ucEnabled && m_usrBoxInfo[ucSelected].ucCounts==m_usrBoxInfo[ucSelected].usrCountResponse.ucNewCount){
        CardBoxCountReset(ucSelected);
      }
      
      ucData[0]=ucSelected+0x30;
      SprintF(&ucData[1],4,pcommData->ucData[0]);
    #if COUNT_ID_EN==0          
      Uart0Pack(INFTYPE_CARD_COUNT,m_ucMachineAddr,pcommData->ucData[2],ucData,5,0);
    #else
      SprintF(&ucData[5],8,m_usrBoxInfo[ucSelected].ulMachineId);
      Uart0Pack(INFTYPE_CARD_COUNT,m_ucMachineAddr,pcommData->ucData[2],ucData,13,0);
    #endif          
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxMaxCountResponse
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
void CardBoxMaxCountResponse(CommRxData *pcommData,INT8U ucSelected)
{
  INT8U ucData[32];
  
  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  if(UartLengthProcess(pcommData,2)){
    if(!pcommData->ucStatus){
      ucData[0]=ucSelected+0x30;
      SprintF(&ucData[1],4,pcommData->ucData[0]);
      Uart0Pack(INFTYPE_CARD_COUNT_MAX,m_ucMachineAddr,pcommData->ucData[2+1],ucData,5,0);
    }
  }
}

/********************************************************************************************************
** ��������: CardBoxVersioinResponse
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
void CardBoxVersionResponse(CommRxData *pcommData,INT8U ucSelected)
{
  INT8U ucData[32];

  if(ucSelected>=CARDMACHINE_CARDBOX_NUMS){
    return;
  }
  
  if(!pcommData->ucStatus){
    ucData[0]=ucSelected+0x30;
    Mem_Copy(&ucData[1],pcommData->ucData,pcommData->ucLen-6);
    Uart0Pack(0x9A,m_ucMachineAddr,pcommData->ucData[pcommData->ucLen-3-3],ucData,pcommData->ucLen-6+1,0);
  }
}

/********************************************************************************************************
** ��������: GetVersion
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
INT8U GetVersion(INT8U *pucData)
{
  INT8U ucTmp;
  INT8U ucLen;
  
  ucLen=sizeof(m_ucVersion)-1;
  Mem_Copy(&pucData[0],m_ucVersion,ucLen);
  ucTmp=ucLen;
  pucData[ucTmp++]=0x20;
  ucLen=sizeof(m_ucCompileDate)-1;
  Mem_Copy(&pucData[ucTmp],m_ucCompileDate,ucLen);
  ucTmp+=ucLen;
  pucData[ucTmp++]=0x20;
  ucLen=sizeof(m_ucCompileTime)-1;
  Mem_Copy(&pucData[ucTmp],m_ucCompileTime,ucLen);
  ucTmp+=ucLen;	
  return ucTmp;
}




/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/
