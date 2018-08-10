/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: Hpi.h
*创   建   人: John Tonny
*最后修改日期: 2009年1月01日
*描        述:
*
*--------------历史版本信息-----------------------------------------------------------------------------
* 创建人: John Tonny
* 版  本: V1.0
* 日　期: 2009年1月01日
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

#ifdef   HPI_GLOBALS
#define  HPI_EXT
#else
#define  HPI_EXT  extern
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

#define UART0_SOF                                                       0x02
#define UART0_EOF                                                       0x03

#define UART_SOF                                                        0xFE

#define UART3_SOF                                                       0xCB
#define UART3_CMD                                                       0x55
#define UART3_LEN                                                       0x04
#define UART3_EOF                                                       0x16


#define UART_HEAD							0x02
#define UART_TAIL							0x03


#define UART_CLUSTER0_LEN                                               0x01
#define UART_CLUSTER1_LEN                                               0x01
#define UART_CLUSTER_LEN                                                0x02
#define UART_CMD_LEN                                                    0x01
#define UART_CMD_STATUS_LEN                                             0x01
#define UART_SEQ_LEN                                                    0x01
#define UART_CRC_LEN                                                    0x02

#define UART_HEAD_LEN                                                   (UART_CMD_LEN)
#define UART_TAIL_LEN                                                   (UART_SEQ_LEN)

#define UART_BASIC_TX_LEN                                               (UART_CLUSTER_LEN+UART_CMD_LEN+UART_TAIL_LEN+UART_CRC_LEN)
#define UART_BASIC_RSP_LEN                                              (UART_CLUSTER_LEN+UART_CMD_LEN+UART_CMD_STATUS_LEN+UART_TAIL_LEN+UART_CRC_LEN)

#define UART_SEQ_RPOS                                                   0x06
#define UART_CRC0_RPOS                                                  0x05
#define UART_CRC1_RPOS                                                  0x04


//#define UART_RX_PACKET_MAX															32
//#define UART_RX_LEN_MAX															        64


//
#define CARDMACHINE_READ_MANUFACTURER_CMD	        0x01
#define CARDMACHINE_READ_PRODUCENAME_CMD		0x02
#define CARDMACHINE_READ_VERSION_CMD			0x03

#define CARDMACHINE_READ_MACHINE_ID_CMD			0x04
#define CARDMACHINE_WRITE_MACHINE_ID_CMD		0x05

#define CARDMACHINE_READ_BASIC_INFO_CMD			0x0A
#define CARDMACHINE_WRITE_RESET_CMD			0x0B

#define CARDMACHINE_CLOSE_DOOR_CMD			0x11	
#define CARDMACHINE_READ_COUNT_MAX_CMD			0x19
#define CARDMACHINE_WRITE_COUNT_MAX_CMD			0x1A

#define CARDMACHINE_RECORD_INIT_CMD                     0x29 


#define INFTYPE_POWER_ON      				0x55
#define INFTYPE_BUTTON_PRESS  				0x58

#define INFTYPE_CM_IDLE					0xAA	//


#define CARDMACHINE_READ_DATA_CMD			0xE0    //
#define CARDMACHINE_READ_DEBUGINFO_CMD			0xE2		//
#define UART_COUNT_READ_CMD                             0xE3    //

#define UART_COUNT_ADD_CMD                              0xE7    //
#define UART_COUNT_SUB_CMD                              0xE8    //
#define UART_BOX_UNLOAD_CMD                             0xE9    //
#define UART_COUNT_SET_WRITE                            0xEA    //

#define UART_NOVALID_CMD																0xFF    //

#define SMOTO_WRITE_PARAMS_CMD				0xC0
#define SMOTO_READ_PARAMS_CMD				0xC1
#define DMOTO_WRITE_PARAMS_CMD				0xC2
#define DMOTO_READ_PARAMS_CMD				0xC3
#define AUTOOUT_MODE_WRITE_CMD			        0xC4
#define AUTOOUT_MODE_READ_CMD				0xC5
#define BUZZ_EN_WRITE_CMD				0xC6
#define BUZZ_EN_READ_CMD				0xC7

#define DMOTO_SELECT_WRITE_CMD                          0xC8    //
#define DMOTO_SELECT_READ_CMD                           0xC9    //
#define SMOTO_SELECT_WRITE_CMD                          0xCA    //
#define SMOTO_SELECT_READ_CMD                           0xCB    //
#define BOX_SELECT_WRITE_CMD                          	0xCC    //
#define BOX_SELECT_READ_CMD                           	0xCD    //
#define KEY_SELECT_WRITE_CMD                            0xCE    //
#define KEY_SELECT_READ_CMD                             0xCF    //
#define ULTRASOUND_WRITE_CMD                            0xD0    //
#define ULTRASOUND_READ_CMD                             0xD1    //
#define GROUP_SELECT_WRITE_CMD                          0xD2    //
#define GROUP_SELECT_READ_CMD                           0xD3    //
#define SCAN_PARAMS_WRITE_CMD                           0xD4
#define SCAN_PARAMS_READ_CMD                            0xD5





#define UART_RESPONSE_MODE                              0x40


#define INFTYPE_DEVICE_ERR   	     			        0x5E
#define   SUBTYPE_ERR_LOAD_FAIL 				0x11
#define   SUBTYPE_ERR_UNLOAD_FAIL   		                0x12
#define   SUBTYPE_ERR_BOX_LOCK	    		                0x20
#define   SUBTYPE_ERR_BOX_UNLOCK				0x21
#define   SUBTYPE_ERR_BOX1TOANT					0x22			//?¨?D1?úí·3??¨′í?ó
#define   SUBTYPE_ERR_BOX2TOANT					0x23
#define   SUBTYPE_ERR_BOX3TOANT					0x24
#define   SUBTYPE_ERR_BOX_NORESPONSE		                0x25
#define   SUBTYPE_ERR_BOX_PUSH_WRONG		                0x26
#define   SUBTYPE_ERR_DEVICE_MANUAL 		                0x31
#define   SUBTYPE_ERR_WRITE_INF	    		                0x34
#define   SUBTYPE_ERR_READ_INF 	    		                0x35
#define   SUBTYPE_ERR_CARDCOUNT_OVER		                0x36
#define   SUBTYPE_ERR_DEVICE_BUSY	 			0x3B
#define   SUBTYPE_ERR_CARD_ONANT				0x41
#define   SUBTYPE_ERR_NOCARD_ONANT  		                0x42
#define   SUBTYPE_ERR_NOCARD_ONEXIT 		                0x43
#define   SUBTYPE_ERR_CARDBOX_UNLOAD		                0x44
#define   SUBTYPE_ERR_CARD_ONEXIT   		                0x45

#define   SUBTYPE_ERR_CARD_POSITION   	                        0x49
#define   SUBTYPE_ERR_DMOTO1					0x4A
#define   SUBTYPE_ERR_DMOTO2					0x4B
#define   SUBTYPE_ERR_DMOTO3					0x4C
#define   SUBTYPE_ERR_DMOTO4					0x4D
#define   SUBTYPE_ERR_SMOTO1					0x4E
#define   SUBTYPE_ERR_SMOTO2					0x4F

#define   SUBTYPE_ERR_EXIT2ANT_FAIL 		                0x51
#define   SUBTYPE_ERR_ANT2BOX_FAIL			        0x52
#define   SUBTYPE_ERR_BOX2ANT_FAIL			        0x53
#define   SUBTYPE_ERR_ANT2EXIT_FAIL 		                0x54
#define   SUBTYPE_ERR_OPERATE_FAIL  		                0x59
#define   SUBTYPE_ERR_ANT2REV_FAIL 			        0x5A
#define   SUBTYPE_ERR_UNKNOW  	    		                0x5C
#define   SUBTYPE_ERR_HEAD1STATUSERR  	                        0x60
#define   SUBTYPE_ERR_HEAD2STATUSERR  	                        0x61
#define   SUBTYPE_ERR_HEAD3STATUSERR  	                        0x62
#define   SUBTYPE_ERR_CARDCOUNT_ZERO		                0x63
#define   SUBTYPE_ERR_BOX_NOCONNECT			        0x64
#define   SUBTYPE_ERR_CARD_SLIPPED			        0x65								//?¨′ò??
#define   SUBTYPE_ERR_DOOROPEN  			        0x66
#define   SUBTYPE_ERR_PRINTOPEN  			        0x67


#define INFTYPE_CMD_FINISHED  					0x5F
#define INFTYPE_CARD_DEV_SERIAL					0x60
#define INFYPTE_CARD_BOX_SERIAL					0x61
#define INFTYPE_CARD_COUNT    					0x62

#define INFTYPE_DEVICE_EVENT  					0x64
#define   SUBTYPE_CARD_OFF_ANT					0x20
#define   SUBTYPE_CARD_ON_ANT 					0x21
#define   SUBTYPE_CARD_AWAY_GATE				0x22
#define   SUBTYPE_CARD_PLUG_GATE				0x23
#define   SUBTYPE_CARDBOX_UNLOAD				0x24
#define   SUBTYPE_CARDBOX_LOAD					0x25


#define INFTYPE_DEVICE_TYPE   					0x66
#define INFTYPE_DEVICE_STATUS 					0x67
#define INFTYPE_CARD_COUNT_MAX					0x68
#define INFTYPE_KEY_TEST_STATUS					0x6A
#define INFTYPE_BOX_CRITIMAX 					0x6B
#define INFTYPE_BOX_CRITIMIN 					0x6C
#define INFTYPE_DEVICE_VER 					0x6F
#define INFTYPE_CARDONBELT 					0x7E
#define INFTYPE_BELTCLEAR 					0x7F
#define INFTYPE_ULTRASOUND_STATUS                               0x6E


#define INFTYPE_BUFFER_OVER_ERR   			        0xC1
#define INFTYPE_PACKAGE_OVER_ERR 				0xC2
#define INFTYPE_INCOMPLETE_ERR 					0xC3
#define INFTYPE_PARITY_ERR   					0xC4
#define INFTYPE_FORMAT_ERR   					0xC5


//?¨?Dí¨??
#define HPI_STATUS_SUCCESS                                      0x00
#define HPI_STATUS_FORMAT_ERR                                   0x32
#define HPI_STATUS_EEPROM_WRITE_ERR                             0x33
#define HPI_STATUS_EEPROM_READ_ERR                              0x34
#define HPI_STATUS_NV_WRITE_ERR                                 0x35
#define HPI_STATUS_NV_READ_ERR                                  0x36
#define HPI_STATUS_DOOR_ERR                                     0x37
#define HPI_STATUS_FORMAT_DATA_ERR                              0x38
#define HPI_STATUS_NO_SUPPORT_CMD_ERR                           0x39
#define HPI_STATUS_NO_SUPPORT_CLUSTER_ERR                       0x3A
#define HPI_STATUS_RECORD_TAIL_FINISH                           0x3B
#define HPI_STATUS_NO_NETWORK_FINISH                            0x3C
#define HPI_STATUS_MSG_ALLOCATE_ERR                             0x3D
#define HPI_STATUS_NO_RESPONSE_ERR                              0x3E
#define HPI_STATUS_CRC_ERR                                      0x3F
#define HPI_STATUS_CARD_IN_OVER_STATE                           0x40
#define HPI_STATUS_CARD_OUT_ZERO_STATE                          0x42
#define HPI_STATUS_COMP_ERR                                     0x43

#define HPI_STATUS_WRITE_SECTOR_ERR                             0x40
#define HPI_STATUS_READ_SECTOR_ERR				0x41
#define HPI_STATUS_WRITE_READ_SECTOR_ERR                        0x42


#define HPI_READER_READ_HEADER_ERR				0x80
#define HPI_READER_WRITE_HEADER_ERR				0xC0
#define HPI_READER_CARD_MATCH_ERR				0x0A 
#define HPI_READER_NOCARD_ERR					0x0B
#define HPI_READER_NOSECTOR_ERR					0x0C
#define HPI_READER_AUTHENTICATE_ERR				0x0D


#define CARDMACHINE_RX_RSP_CLUSTERID_TYPE                       0x0080  //????????????
#define CARDMACHINE_TX_RSP_CLUSTERID_TYPE                       0x0040  //???????????


/*******************************************************************************************************
*                                         Type Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Data Definition
*******************************************************************************************************/


HPI_EXT CardMachineRxData m_usrComm1RxData;


/*******************************************************************************************************
*                                         Macro Definition
*******************************************************************************************************/



/*******************************************************************************************************
*                                         Function Prototypes
*******************************************************************************************************/


HPI_EXT INT8U Uart0LengthProcess(CardMachineRxData *pcommData,INT8U ucLen);

HPI_EXT void SMotoWriteParams(CardMachineRxData *pcommData);
HPI_EXT void SMotoReadParams(CardMachineRxData *pcommData);

HPI_EXT void DMotoWriteParams(CardMachineRxData *pcommData);
HPI_EXT void DMotoReadParams(CardMachineRxData *pcommData);

HPI_EXT void ParamsFlagWrite(CardMachineRxData *pcommData,INT8U ucAddr);
HPI_EXT void ParamsFlagRead(CardMachineRxData *pcommData,INT8U ucAddr);

HPI_EXT void AutoOutModeWrite(CardMachineRxData *pcommData);
HPI_EXT void AutoOutModeRead(CardMachineRxData *pcommData);
HPI_EXT void BuzzEnWrite(CardMachineRxData *pcommData);
HPI_EXT void BuzzEnRead(CardMachineRxData *pcommData);

HPI_EXT void DMotoSelectWrite(CardMachineRxData *pcommData);
HPI_EXT void DMotoSelectRead(CardMachineRxData *pcommData);
HPI_EXT void SMotoSelectWrite(CardMachineRxData *pcommData);
HPI_EXT void BoxSelectRead(CardMachineRxData *pcommData);
HPI_EXT void BoxSelectWrite(CardMachineRxData *pcommData);
HPI_EXT void SMotoSelectRead(CardMachineRxData *pcommData);
HPI_EXT void KeySelectWrite(CardMachineRxData *pcommData);
HPI_EXT void KeySelectRead(CardMachineRxData *pcommData);
HPI_EXT void UltraSoundWrite(CardMachineRxData *pcommData);
HPI_EXT void UltraSoundRead(CardMachineRxData *pcommData);
HPI_EXT void GroupSelectWrite(CardMachineRxData *pcommData);
HPI_EXT void GroupSelectRead(CardMachineRxData *pcommData);
HPI_EXT void ScanParamsWrite(CardMachineRxData *pcommData);
HPI_EXT void ScanParamsRead(CardMachineRxData *pcommData);


HPI_EXT void DMotoMove(CardMachineRxData *pcommData);
HPI_EXT void SMotoMove(CardMachineRxData *pcommData);
HPI_EXT void CardToBox(CardMachineRxData *pcommData);
HPI_EXT void CardToOut(CardMachineRxData *pcommData);

HPI_EXT void KeyTest(CardMachineRxData *pcommData);

HPI_EXT void CardMachineIdWrite(CardMachineRxData *pcommData);
HPI_EXT void CardMachineIdRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineAddrWrite(CardMachineRxData *pcommData);
HPI_EXT void CardMachineAddrRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineAlarmMaxWrite(CardMachineRxData *pcommData);
HPI_EXT void CardMachineAlarmMaxRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineAlarmMinWrite(CardMachineRxData *pcommData);
HPI_EXT void CardMachineAlarmMinRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineMaxCountWrite(CardMachineRxData *pcommData);
HPI_EXT void CardMachineMaxCountRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineStateRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineTypeRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineVersionRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineDataRead(CardMachineRxData *pcommData);
HPI_EXT void CardMachineDataWrite(CardMachineRxData *pcommData);

HPI_EXT void CardBoxVersionRead(CardMachineRxData *pcommData);
HPI_EXT void CardBoxIdWrite(CardMachineRxData *pcommData);
HPI_EXT void CardBoxIdRead(CardMachineRxData *pcommData);
HPI_EXT void CardBoxCountWrite(CardMachineRxData *pcommData);
HPI_EXT void CardBoxCountRead(CardMachineRxData *pcommData);
HPI_EXT void CardBoxMaxCountWrite(CardMachineRxData *pcommData);
HPI_EXT void CardBoxMaxCountRead(CardMachineRxData *pcommData);
HPI_EXT void CardBoxRecordInit(CardMachineRxData *pcommData);
HPI_EXT void CardBoxCountAddSub(CardMachineRxData *pcommData);
HPI_EXT void CardBoxMotoMove(CardMachineRxData *pcommData);


HPI_EXT INT8U UartLengthProcess(CommRxData *pcommData,INT8U ucLen);

HPI_EXT void CardBoxRecordInitResponse(CommRxData *pcommData,INT8U ucSelected);
HPI_EXT void CardBoxMachineIdResponse(CommRxData *pcommData,INT8U ucSelected);
HPI_EXT void CardBoxBasicInfoResponse(CommRxData *pcommData,INT8U ucSelected);
HPI_EXT void CardBoxCountAddSubResponse(CommRxData *pcommData,INT8U ucSelected);
HPI_EXT void CardBoxCountResponse(CommRxData *pcommData,INT8U ucSelected);
HPI_EXT void CardBoxMaxCountResponse(CommRxData *pcommData,INT8U ucSelected);
HPI_EXT void CardBoxVersionResponse(CommRxData *pcommData,INT8U ucSelected);

HPI_EXT INT8U GetVersion(INT8U *pucData);




/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/
