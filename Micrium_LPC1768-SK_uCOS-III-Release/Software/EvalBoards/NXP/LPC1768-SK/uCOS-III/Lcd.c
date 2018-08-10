/****************************************Copyright (c)****************************************************
** 
**                                      
**
**                                   
**
**--------------File Info---------------------------------------------------------------------------------
** File name:			uart.c
** modified Date:  		2011-4-15
** Last Version:		V1.00
** Descriptions:		
**	                    
*********************************************************************************************************/

#define LCD_GLOBALS
#include "includes.h"

/********************************************************************************************************
** 函数名称: LcdWriteByte
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
void LcdWriteByte(int8u wByte, int8u bByteType)	//bByteType: 1-Data, 0-Cmd
{
  LIB_ERR lib_err;
  SERIAL_ERR err;
  OS_ERR os_err;
  CPU_INT08U *pucTx;

  pucTx= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                   (CPU_SIZE_T)2,
                                   (LIB_ERR  *)&lib_err);
  if(!pucTx){
    return;
  }
  pucTx[0]=wByte;
  pucTx[1]=bByteType;
                                      
  Serial_Wr((SERIAL_IF_NBR   )Uart_SerTraceIF_Nbr[1],
            (void           *)pucTx,
            (CPU_SIZE_T      )2,
            (CPU_INT32U      )10,
            (SERIAL_ERR     *)&err);     
  
  Mem_PoolBlkFree(&m_UartBufPool, pucTx, &lib_err);
  if (lib_err != LIB_MEM_ERR_NONE)  {
    //error
  }
  OSTimeDly(3,OS_OPT_TIME_DLY, &os_err) ;         
}

/********************************************************************************************************
** 函数名称: SetLcd_ErrLed
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
void SetLcd_ErrLed(int8u b)
{
  LIB_ERR lib_err;
  SERIAL_ERR err;
  OS_ERR os_err;
  CPU_INT08U *pucTx;

  pucTx= (CPU_INT08U *)Mem_PoolBlkGet((MEM_POOL *)&m_UartBufPool,
                                   (CPU_SIZE_T)2,
                                   (LIB_ERR  *)&lib_err);
  if(!pucTx){
    return;
  }
  
  pucTx[0]=0xFF;
  if(b==1){
    pucTx[1]=0x81;
  }else{
    pucTx[1]=0x81;
  }
  
  Serial_Wr((SERIAL_IF_NBR   )Uart_SerTraceIF_Nbr[1],
            (void           *)pucTx,
            (CPU_SIZE_T      )2,
            (CPU_INT32U      )10,
            (SERIAL_ERR     *)&err);     
  
  Mem_PoolBlkFree(&m_UartBufPool, pucTx, &lib_err);
  if (lib_err != LIB_MEM_ERR_NONE)  {
    //error
  }
  OSTimeDly(3,OS_OPT_TIME_DLY, &os_err) ;         
}

/********************************************************************************************************
** 函数名称: LcdClear
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
void LcdClear(void)
{
  LcdWriteByte(0x01,0);
  LcdWriteByte(0x02,0);
}

/********************************************************************************************************
** 函数名称: LcdLocateCursor
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
void LcdLocateCursor(uint8_t Row, uint8_t RowPos)
{
  uint8_t CursorAddr=0x80;	//第一行地址0x80-0x8F, 第二行地址0x90-0x9F, ....
  //if(Row>1) return;
  //if(RowPos>7) return;
  CursorAddr+=RowPos;
  CursorAddr=CursorAddr+(Row<<4);
  LcdWriteByte(CursorAddr, 0);
}

/********************************************************************************************************
** 函数名称: LcdShowChar
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
void LcdShowChar(uint8_t Char)	//在当前光标位置显示字符
{
  LcdWriteByte(Char,1);
}

/********************************************************************************************************
** 函数名称: LcdShowStr
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
void LcdShowStr(int8u *szStr)	//在当前光标位置显示字符串
{
  while(*szStr){
    LcdWriteByte(*szStr,1);
    szStr++;
  }
}

/********************************************************************************************************
** 函数名称: SetGraphMemLocate
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
void SetGraphMemLocate(int8u x, int8u y)
{
  LcdWriteByte(0x80+y,0);
  LcdWriteByte(0x80+x,0);
}

/********************************************************************************************************
** 函数名称: LcdInit
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
void LcdInit(int8u bTextMode)	//0-图形模式，1-字符模式
{
  if(bTextMode){
    //LcdWriteByte(0x20,0);	//基本指令操作
    //DelayCycle(DELAY_VAL);
    //LcdWriteByte(0x24,0);	//扩充指令操作
    //DelayCycle(DELAY_VAL);
    LcdWriteByte(0x20,0);	//基本指令操作
    LcdWriteByte(0x80,0);
    //LcdWriteByte(0x26,0);	//指定在资料写入或读取时，光标的移动方向
    //DelayCycle(DELAY_VAL);
    LcdWriteByte(0x0C,0);	//开显示，关光标，不闪烁。
  }else{
    LcdWriteByte(0x26,0);
    LcdWriteByte(0x80,0);
    LcdWriteByte(0x80,0);
  }
}


/********************************************************************************************************
** 函数名称: Lcd_Process
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
void Lcd_Process(void)	//0-图形模式，1-字符模式
{
  
  LIB_ERR               lib_err;
  OS_ERR                os_err;
  CPU_TS                ts;
  CPU_CHAR              *pMsg; 
  OS_MSG_SIZE           msgSize;
  INT8U                 ucType;
  
  INT16U                uiTime=1000;
  static CPU_INT08U    ucCmd=DISPLAY_SELFTEST_MSG;
  
  LcdInit(1);  					
  LcdClear();

  while(DEF_TRUE){
    pMsg = (CPU_CHAR *)OSTaskQPend(uiTime, OS_OPT_PEND_BLOCKING, &msgSize, &ts, &os_err);
    if(pMsg){
      //if(*pMsg>=ucCmd){
        ucCmd=*pMsg;
      //}
    }
    ucType=DEV_TYPE();
    if(ucType!=LARGE_THICK_OUT_TYPE || ucType==LARGE_THIN_OUT_TYPE){
      switch(ucCmd){
        case DISPLAY_SELFTEST_MSG:
          DisplaySelftest();
          break;
        case DISPLAY_MAIN_MSG:
          DisplayMain();
          break;
        case DISPLAY_WRITING_MSG:
          DisplayWriting();
          break;
        case DISPLAY_POS_ERR_MSG:
          DisplayPosErr();
          break;
        case DISPLAY_KEY_TEST_MSG:
          DisplayKeyTest();
          break;
      }
    }
    if(pMsg){
      Mem_PoolBlkFree(&m_BoxPool, pMsg, &lib_err);
      if (lib_err != LIB_MEM_ERR_NONE)  {
        //error
      }        
    }
  }
}


/********************************************************************************************************
** 函数名称: DisplayCommErr
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
void DisplayCommErr(void)
{
  LcdLocateCursor(0,0);
  LcdShowStr(" 卡夹通讯异常！ ");
  LcdLocateCursor(1,0);
  LcdShowStr("请卸载或更换卡夹");
  SetLcd_ErrLed(1);  

}

/********************************************************************************************************
** 函数名称: DisplayUnload
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
void DisplayUnlode(void)
{
  LcdLocateCursor(0,0);
  LcdShowStr(" 未检测到卡夹！ ");
  LcdLocateCursor(1,0);
  LcdShowStr("  请装载卡夹！   ");
}

/********************************************************************************************************
** 函数名称: DisplayPosErr
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
void DisplayPosErr(void)
{
  LcdLocateCursor(0,0);
  LcdShowStr(" 卡夹通讯异常！ ");
  LcdLocateCursor(1,0);
  LcdShowStr("请卸载或更换卡夹");
  SetLcd_ErrLed(1);  

}

/********************************************************************************************************
** 函数名称: DisplayWriteErr
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
void DisplayWriteErr(void)
{
  LcdLocateCursor(0,0);
  LcdShowStr(" 写入卡数错误！ ");
  LcdLocateCursor(1,0);
  LcdShowStr("请卸载后重新装载");
}


/********************************************************************************************************
** 函数名称: DisplayKeyTest
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
void DisplayKeyTest(void)
{
  LcdLocateCursor(0,0);
  LcdShowStr("光电管正在检测");
  LcdLocateCursor(1,0);
  LcdShowStr("    请等待！    ");
}

/********************************************************************************************************
** 函数名称: DisplaySwitchErr
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
void DisplaySwitchErr(INT8U ucMode)
{
  
}


/********************************************************************************************************
** 函数名称: DisplaySelftest
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
void DisplaySelftest(void)
{
  LcdLocateCursor(0,0);
  LcdShowStr("  卡机正在自检  ");
  LcdLocateCursor(1,0);
  LcdShowStr("    请等待！    ");
}

/********************************************************************************************************
** 函数名称: DisplayMain
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
void DisplayMain(void)
{
  INT8U ucType=DEV_TYPE();
  INT8U ucAutoMode=CARD_AUTO_MODE();
  INT8U ucData[32];
  
  LcdLocateCursor(0,0);
  if(ucType==SMALL_THICK_OUT_TYPE || ucType==SMALL_THIN_OUT_TYPE){
    if(ucAutoMode){
      LcdShowStr("自动模式--发卡中");
    }else{
      LcdShowStr("控制模式--发卡中");
    }
  }else if(ucType==SMALL_THICK_IN_TYPE || ucType==SMALL_THIN_IN_TYPE){
    if(ucAutoMode){
      LcdShowStr("自动模式--收卡中");
    }else{
      LcdShowStr("控制模式--收卡中");
    }
  }else if(ucType==SMALL_THICK_GIN_TYPE || ucType==SMALL_THIN_GIN_TYPE){
    if(ucAutoMode){
      if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bSelftest){
        LcdShowStr("自动模式--灌卡中");
      }else{
        LcdShowStr("自动模式--自检中");
      }
    }else{
      if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bSelftest){
        LcdShowStr("控制模式--灌卡中");
      }else{
        LcdShowStr("控制模式--自检中");
      }
    }
  }
  LcdLocateCursor(1,0);
  if(!m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bBoxLoad){
    LcdShowStr("  未装载卡夹！  ");  
  }else{
    LcdShowStr("卡夹");
    LcdLocateCursor(1,2);
    if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
      SprintF(ucData,4,m_usrBoxInfo[BOX_FIRST].ulMachineId);
      LcdShowStr(ucData);
    }else{
      LcdShowStr("----");
    }
    
    LcdLocateCursor(1,4);
    LcdShowStr("卡数");
    LcdLocateCursor(1,6);
    if(m_usrBoxInfo[BOX_FIRST].usrFlag.usrBit.bConnected){
      SprintF(ucData,4,m_usrBoxInfo[BOX_FIRST].ucCounts);
      LcdShowStr(ucData);
    }else{
      LcdShowStr("----");
    }
  }
}

/********************************************************************************************************
** 函数名称: DisplayWriting
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
void DisplayWriting(void)
{
  OS_ERR os_err;
  INT8U ucCmd;
  
  LcdLocateCursor(0,0);
  LcdShowStr("写入中--请勿卸载");
  OSTimeDly(1000,OS_OPT_TIME_DLY, &os_err) ;         
  ucCmd=DISPLAY_MAIN_MSG;
  Box_TaskLcdQPost(&App_TaskLcdTCB,&ucCmd,1);
}

/********************************************************************************************************
** 函数名称: DisplayKeyTest
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
void DisplayKetTest(void)
{
  LcdLocateCursor(0,0);
  LcdShowStr(" 光电管正在检测 ");
  LcdLocateCursor(1,0);
  LcdShowStr("    请等待！    ");
}



/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/
