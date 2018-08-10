/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------???tD??￠---------------------------------------------------------------------------------
*??   ?t   ??: Moto.h
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

#ifdef   MOTO_GLOBALS
#define  MOTO_EXT
#else
#define  MOTO_EXT  extern
#endif

/*
2???μ??úDío?:42BYG48 μ?á÷1.2A,2??àz:1.8
?y?ˉ±èb: 11:20 
D????±??x:17.895-17.9mm,?ü3¤y:56.2367-56.2345mm
?¨??3¤?è85.5-86.0mm
1aμ??a1??àà?70.5mm
?¨?úμ?1aμ?1ü35mm
1aμ?1üμ?3??ú21mm
?ú?á°???27mm,μ2°??í?è8mm

??2??àà?a:b*y/(360/z)=(20/11)*0.2811725=0.511mm
2???2?êy:(86-(86-70)/2)/a=1522?
*/

/*
ê??¨?ú￡o
2???μ??ú￡o1oá??=12?￡?2002?=40mm￡???2?0.2mm￡?20oá??=202?=4mm
?±á÷μ??ú￡o400oá??=60mm￡?20oá??=3mm

?y×aμ?·′×a?ò·′×aμ??y×aDèòa???ó?óê±ê±??100ms
*/
/*******************************************************************************************************
*                                         Config Definition
*******************************************************************************************************/

#define KEY_INTERRUTPT_EN										1

#define CARDBOX_SELECT_EN										0

#define MOTO_INTERFER_TIME_EN								                0

#define DOOR_OPEN_EN                                                                                    0

#define PAPER_RECYCLE_EN                                                                                1

/*******************************************************************************************************
*                                         Register Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Hardware Definition
*******************************************************************************************************/

#define GIN_CARDTOANT_STATE										0x00
#define GIN_ANTTOBOX_STATE										0x01


/*******************************************************************************************************
*                                         Constant Definition
*******************************************************************************************************/

#define SCAN_CLOSE_MODE                         0
#define SCAN_OPEN_MODE                          1
#define SCAN_CLOSE_TIMES                        50                    //5*10ms=50ms
#define SCAN_OPEN_TIMES                         40                    //850*10ms=85000ms


#define DOOR_CLOSE_MODE                         0
#define DOOR_OPEN_MODE                          1

#define FORWARD_TO_BACKWARD_TIME		100
#define BOX_COUNT_WRITE_TIME			100

#define BOX_FIRST				0
#define BOX_SECOND				1
#define BOX_THIRD				2

#define DMOTO_FIRST				0
#define DMOTO_SECOND				1
#define DMOTO_THIRD				2
#define DMOTO_FOURTH				3

#define SMOTO_FIRST				0
#define SMOTO_SECOND				1

#define INTERRUPT_MODE				1
#define NORMAL_MODE				0

#define NOWAIT_MODE				0
#define WAIT_MODE				1

#define DMOTO1_POSA_BIT                      	0				//直流电机1到位开关
#define DMOTO1_POSB_BIT                      	1				//直流电机1到位开关
#define CARD_POSE1_BIT                       	2				//卡夹口开关
#define BOXLOAD1_BIT				3				//卡夹装载开关
#define BOX1_REV1_BIT				4				//保留1
#define BOX1_REV2_BIT				5				//保留2

#define CARDBOX1_POS_BIT                    	6				//卡片到位开关 

#define DMOTO2_POSA_BIT                     	8				//直流电机1到位开关
#define DMOTO2_POSB_BIT                     	9				//直流电机1到位开关
#define CARD_POSE2_BIT                      	10				//卡夹口开关
#define BOXLOAD2_BIT				11				//卡夹装载开关
#define BOX2_REV1_BIT				12				//保留1
#define BOX2_REV2_BIT				13				//保留2

#define CARDBOX2_POS_BIT                    	14				//卡片到位开关 

#define DMOTO3_POSA_BIT                     	16				//直流电机1到位开关
#define DMOTO3_POSB_BIT                     	17				////直流电机1到位开关
#define CARD_POSE3_BIT                      	18				//卡夹口开关
#define BOXLOAD3_BIT				19				//卡夹装载开关
#define BOX3_REV1_BIT				20				//保留1
#define BOX3_REV2_BIT				21				//保留2

#define CARDBOX3_POS_BIT                    	22				//卡片到位开关 

#define CARD_POSA_BIT                      	24				//A-B-C-D-E
#define CARD_POSB_BIT                      	25				//B
#define CARD_POSC_BIT                      	26				//C
#define CARD_POSD_BIT                      	27				//D
#define CARD_POSE_BIT                      	28				//E
#define CARD_POSF_BIT                      	29				//F

#define SELFTEST_KEY_BIT                    	30				//自检开关

#define GIN_KEY_BIT				BOX3_REV2_BIT		        //灌卡开关 CARD_POSF_BIT

#define DMOTO_PWM_700				700
#define DMOTO_PWM_800				800
#define DMOTO_PWM_900				900
#define DMOTO_PWM_1000				1000
#define DMOTO_PWM_1500				1500
#define DMOTO_FREQ_DEFAULT			2000
#define DMOTO_PWM_DEFAULT			DMOTO_PWM_1000

#define DMOTO_TIME_DEFAULT			150
#define DMOTO_TIME_SK_DEFAULT			80
#define DMOTO_TIME_GK_DEFAULT			70

#define SMOTO_FREQ_500US                  	50
#define SMOTO_FREQ_600US                  	60
#define SMOTO_FREQ_700US                  	70
#define SMOTO_FREQ_1000US                  	100
#define SMOTO_FREQ_1500US                  	150
#define SMOTO_FREQ_2500US                  	250

#define SMOTO_FREQ_DEFAULT                 	SMOTO_FREQ_700US
#define SMOTO_COUNT_DEFAULT			1200

#define SMOTO_COUNT_GK_CLEAR_DEFAULT		1800
#define SMOTO_COUNT_GK_INTOANT_DEFAULT		1800
#define SMOTO_COUNT_GK_ANTTOBOX_DEFAULT		600
#define SMOTO_COUNT_GK_ANTTOOUT_DEFAULT		800
#define SMOTO_COUNT_ZIN_ANTTOOUT_DEFAULT        800
#define SMOTO_COUNT_ZIN_PAPER_RECYCLE_DEFAULT   800

#define SMOTO_COUNT_ANTTOBOX_DEFAULT		400

#define ULTRASOUND_DISTANCE_DEFAULT             150
#define ULTRASOUND_TIMES_DEFAULT                10

#define MOTO_FORWARD_MODE                       0x00
#define MOTO_BACKWARD_MODE                      0x01

#define TAKEOUT_OVERTIME_DEFAULT                0x64

#define MOTO_RETRYS                             0x03

#define CARDMACHINE_MAX_COUNTS			100
#define CARDMACHINE_ALARM_MAX_COUNTS		90
#define CARDMACHINE_ALARM_MIN_COUNTS		10

#define SWITCH_DELAY_TIME_DEFAULT		50						//x*10us
#define MOTO_INTERFER_TIME_DEFAULT		100                                             //100ms

#define CARDBOX_POS_ERR_RETRYS			0x04
#define CARDBOX_POS_ERR_NUMS			0x08

#define BOXMOTO_FREQUENCE_PER_CARD  		5*1698/3


#define ACTION_DELAY_TIME_DEFAULT               5

//·μ??é????úD??￠3￡á?---------------------------------------------------------
#define INFTYPE_POWER_ON      			0x55
#define INFTYPE_BUTTON_PRESS  			0x58

#define INFTYPE_CM_IDLE				0xAA	//

#define INFTYPE_DEVICE_ERR   	     		0x5E
#define   SUBTYPE_ERR_LOAD_FAIL 		0x11
#define   SUBTYPE_ERR_UNLOAD_FAIL   		0x12
#define   SUBTYPE_ERR_BOX_LOCK	    		0x20
#define   SUBTYPE_ERR_BOX_UNLOCK		0x21
#define   SUBTYPE_ERR_BOX1TOANT			0x22			//?¨?D1?úí·3??¨′í?ó
#define   SUBTYPE_ERR_BOX2TOANT			0x23
#define   SUBTYPE_ERR_BOX3TOANT			0x24
#define   SUBTYPE_ERR_BOX_NORESPONSE		0x25
#define   SUBTYPE_ERR_BOX_PUSH_WRONG		0x26
#define   SUBTYPE_ERR_DEVICE_MANUAL 		0x31
#define   SUBTYPE_ERR_WRITE_INF	    		0x34
#define   SUBTYPE_ERR_READ_INF 	    		0x35
#define   SUBTYPE_ERR_CARDCOUNT_OVER		0x36
#define   SUBTYPE_ERR_DEVICE_BUSY	 	0x3B
#define   SUBTYPE_ERR_CARD_ONANT		0x41
#define   SUBTYPE_ERR_NOCARD_ONANT  		0x42
#define   SUBTYPE_ERR_NOCARD_ONEXIT 		0x43
#define   SUBTYPE_ERR_CARDBOX_UNLOAD		0x44
#define   SUBTYPE_ERR_CARD_ONEXIT   		0x45

#define   SUBTYPE_ERR_CARD_POSITION   	        0x49
#define   SUBTYPE_ERR_DMOTO1			0x4A
#define   SUBTYPE_ERR_DMOTO2			0x4B
#define   SUBTYPE_ERR_DMOTO3			0x4C
#define   SUBTYPE_ERR_DMOTO4			0x4D
#define   SUBTYPE_ERR_SMOTO1			0x4E
#define   SUBTYPE_ERR_SMOTO2			0x4F

#define   SUBTYPE_ERR_EXIT2ANT_FAIL 		0x51
#define   SUBTYPE_ERR_ANT2BOX_FAIL		0x52
#define   SUBTYPE_ERR_BOX2ANT_FAIL		0x53
#define   SUBTYPE_ERR_ANT2EXIT_FAIL 		0x54
#define   SUBTYPE_ERR_OPERATE_FAIL  		0x59
#define   SUBTYPE_ERR_ANT2REV_FAIL 		0x5A
#define   SUBTYPE_ERR_UNKNOW  	    		0x5C
#define   SUBTYPE_ERR_HEAD1STATUSERR  	        0x60
#define   SUBTYPE_ERR_HEAD2STATUSERR  	        0x61
#define   SUBTYPE_ERR_HEAD3STATUSERR  	        0x62
#define   SUBTYPE_ERR_CARDCOUNT_ZERO		0x63
#define   SUBTYPE_ERR_BOX_NOCONNECT		0x64
#define   SUBTYPE_ERR_CARD_SLIPPED		0x65								//?¨′ò??
#define   SUBTYPE_ERR_DOOROPEN_FAIL		0x66								//?¨′ò??
#define   SUBTYPE_ERR_PRINTOPEN_FAIL		0x67								//?¨′ò??


#define INFTYPE_CMD_FINISHED  			0x5F
#define INFTYPE_CARD_DEV_SERIAL			0x60
#define INFYPTE_CARD_BOX_SERIAL			0x61
#define INFTYPE_CARD_COUNT    			0x62

#define INFTYPE_DEVICE_EVENT  			0x64
#define   SUBTYPE_CARD_OFF_ANT			0x20
#define   SUBTYPE_CARD_ON_ANT 			0x21
#define   SUBTYPE_CARD_AWAY_GATE		0x22
#define   SUBTYPE_CARD_PLUG_GATE		0x23
#define   SUBTYPE_CARDBOX_UNLOAD		0x24
#define   SUBTYPE_CARDBOX_LOAD			0x25


#define INFTYPE_DEVICE_TYPE   			0x66
#define INFTYPE_DEVICE_STATUS 			0x67
#define INFTYPE_CARD_COUNT_MAX			0x68
#define INFTYPE_KEY_TEST_STATUS			0x6A
#define INFTYPE_BOX_CRITIMAX 			0x6B
#define INFTYPE_BOX_CRITIMIN 			0x6C
#define INFTYPE_DEVICE_VER 			0x6F
#define INFTYPE_CARDONBELT 			0x7E
#define INFTYPE_BELTCLEAR 			0x7F


#define INFTYPE_BUFFER_OVER_ERR   		0xC1
#define INFTYPE_PACKAGE_OVER_ERR 		0xC2
#define INFTYPE_INCOMPLETE_ERR 			0xC3
#define INFTYPE_PARITY_ERR   			0xC4
#define INFTYPE_FORMAT_ERR   			0xC5


//?¨?Dí¨??
#define HPI_STATUS_SUCCESS                      0x00
#define HPI_STATUS_FORMAT_ERR                   0x32
#define HPI_STATUS_EEPROM_WRITE_ERR             0x33
#define HPI_STATUS_EEPROM_READ_ERR              0x34
#define HPI_STATUS_NV_WRITE_ERR                 0x35
#define HPI_STATUS_NV_READ_ERR                  0x36
#define HPI_STATUS_DOOR_ERR                     0x37
#define HPI_STATUS_FORMAT_DATA_ERR              0x38
#define HPI_STATUS_NO_SUPPORT_CMD_ERR           0x39
#define HPI_STATUS_NO_SUPPORT_CLUSTER_ERR       0x3A
#define HPI_STATUS_RECORD_TAIL_FINISH           0x3B
#define HPI_STATUS_NO_NETWORK_FINISH            0x3C
#define HPI_STATUS_MSG_ALLOCATE_ERR             0x3D
#define HPI_STATUS_NO_RESPONSE_ERR              0x3E
#define HPI_STATUS_CRC_ERR                      0x3F
#define HPI_STATUS_CARD_IN_OVER_STATE           0x40
#define HPI_STATUS_CARD_OUT_ZERO_STATE          0x42
#define HPI_STATUS_COMP_ERR                     0x43

#define HPI_STATUS_WRITE_SECTOR_ERR             0x40
#define HPI_STATUS_READ_SECTOR_ERR		0x41
#define HPI_STATUS_WRITE_READ_SECTOR_ERR        0x42


#define HPI_READER_READ_HEADER_ERR		0x80
#define HPI_READER_WRITE_HEADER_ERR		0xC0
#define HPI_READER_CARD_MATCH_ERR		0x0A 
#define HPI_READER_NOCARD_ERR			0x0B
#define HPI_READER_NOSECTOR_ERR			0x0C
#define HPI_READER_AUTHENTICATE_ERR		0x0D

//EEPROM μ??·
#define SCAN_PARAMS_ADDR                        0x00
#define SMOTO_FREQ_ADDR				0x04							//2???μ??ú×a?ù
#define GROUP_SELECT_ADDR                       0x0C
#define DMOTO_PWM_ADDR				0x10							//?±á÷μ??ú×a?ù
#define AUTOOUT_MODE_ADDR			0x20							//×??ˉ·￠?¨?￡ê?(0:·￠?¨μ???μ?;????:·￠?¨μ??¨?ú
#define BUZZ_EN_ADDR				0x24							//0:2??ì;????:?ì

#define CARDMACHINE_SELFADDR_ADDR		0x28
#define CARDMACHINE_ID_ADDR			0x30
#define CARDMACHINE_MAXCOUNT_ADDR		0x38
#define CARDMACHINE_ALARM_MAX_ADDR		0x3C
#define CARDMACHINE_ALARM_MIN_ADDR		0x40
#define ULTRASOUND_PARAMS_ADDR			0x44							

#define DMOTO_SELECT_ADDR		        0x48
#define SMOTO_SELECT_ADDR			0x54
#define BOX_SELECT_ADDR				0x58
#define KEY0_SELECT_ADDR			0x60
#define KEY1_SELECT_ADDR			0x68
#define KEY2_SELECT_ADDR			0x70
#define KEY3_SELECT_ADDR			0x78




/*******************************************************************************************************
*                                         Type Definition
*******************************************************************************************************/



/*******************************************************************************************************
*                                         Data Definition
*******************************************************************************************************/

/*******************************************************************************************************
*                                         Macro Definition
*******************************************************************************************************/



/*******************************************************************************************************
*                                         Function Prototypes
*******************************************************************************************************/

MOTO_EXT void MotoInit(void);

MOTO_EXT void SMotoHook(void);
MOTO_EXT void DMotoHook(void);

MOTO_EXT void MotoTime(void);
/*
MOTO_EXT void TakeoutTime(void);
*/

MOTO_EXT void SMotoStart(INT8U ucFreq,INT16U uiCounts,INT8U ucDirection,INT8U ucSelected);
MOTO_EXT void DMotoStart(INT16U uiFreq,INT16U uiPwm,INT8U ucDirection,INT16U uiMotoTime,INT8U ucSelected);

MOTO_EXT void MOTO_DC_FORWARD(INT8U ucSelected);
MOTO_EXT void MOTO_DC_BACKWARD(INT8U ucSelected);
MOTO_EXT void MOTO_DC_DISABLED(INT8U ucSelected,INT8U ucMode);
MOTO_EXT void MOTO_DC_CLK(INT8U ucSelected);

MOTO_EXT void MOTO_STEP_FORWARD(INT8U ucSelected);
MOTO_EXT void MOTO_STEP_BACKWARD(INT8U ucSelected);
MOTO_EXT void MOTO_STEP_ENABLED(INT8U ucSelected);
MOTO_EXT void MOTO_STEP_DISABLED(INT8U ucSelected,INT8U ucMode);
MOTO_EXT void MOTO_STEP_CLK(INT8U ucSelected);

MOTO_EXT void Action_Process(void);

MOTO_EXT void PowerOnSelftest(void);

MOTO_EXT INT8U SMotoMoveWait(INT16U uiCounts,INT8U ucDirection,INT8U ucSelected);
MOTO_EXT void DMotoMoveWait(INT16U uiTime,INT8U ucDirection,INT8U ucSelected);

MOTO_EXT INT8U DMotoPosAValid(INT8U ucSelected);
MOTO_EXT INT8U DMotoPosBValid(INT8U ucSelected);
MOTO_EXT INT8U DMotoPosAWaitEnter(INT16U uiWaitTime,INT8U ucSelected);
MOTO_EXT INT8U DMotoPosBWaitEnter(INT16U uiWaitTime,INT8U ucSelected);

MOTO_EXT INT8U SMotoReset(INT8U ucMode,INT8U ucSelected);
MOTO_EXT INT8U MotoReset(INT8U ucMode,INT8U ucSelected);

MOTO_EXT void DMotoSwitchStop(void);

MOTO_EXT INT8U GCardToAnt(INT8U ucRetrys);
MOTO_EXT INT8U GAntToBox(void);
MOTO_EXT INT8U GAntToOut(void);

MOTO_EXT INT8U BoxToAnt(void);
MOTO_EXT INT8U AntToOut(void);
MOTO_EXT INT8U InToAnt(void);
MOTO_EXT INT8U AntToBox(void);
MOTO_EXT INT8U ZInToAnt(void);
MOTO_EXT INT8U ZAntToBox(void);
MOTO_EXT INT8U ZAntToOut(void);
MOTO_EXT INT8U ZDoorOpen(INT8U ucState);
MOTO_EXT INT8U ZPrintOpen(INT8U ucState);

MOTO_EXT INT8U GCardToAntProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U GAntToBoxProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U GAntToOutProcess(CardMachineRxData *pcommRx1Data);

MOTO_EXT INT8U BoxToAntProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U AntToOutProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U InToAntProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U AntToBoxProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U ZInToAntProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U ZAntToBoxProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U ZAntToOutProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U ZDoorOpenProcess(CardMachineRxData *pcommRx1Data,INT8U ucState);
MOTO_EXT INT8U ZPrintOpenProcess(CardMachineRxData *pcommRx1Data,INT8U ucState);

MOTO_EXT INT8U InToAntPreProcess(INT32U ulState);
MOTO_EXT INT8U AntToBoxPreProcess(INT32U ulState);
MOTO_EXT INT8U BoxToAntPreProcess(void);
MOTO_EXT INT8U AntToOutPreProcess(INT32U ulState);

MOTO_EXT INT8U MotoReset(INT8U ucMode,INT8U ucSelected);

MOTO_EXT INT8U LBoxToChannel(INT8U ucSelected);
MOTO_EXT INT8U LChannelToAnt(void);
MOTO_EXT INT8U LAntToOut(void);
MOTO_EXT INT8U LAntToRev(void);

MOTO_EXT INT8U LBoxToAntProcess(CardMachineRxData *pcommRx1Data,INT8U ucSelected);
MOTO_EXT INT8U LAntToOutProcess(CardMachineRxData *pcommRx1Data);
MOTO_EXT INT8U LAntToRevProcess(CardMachineRxData *pcommRx1Data);

MOTO_EXT INT8U LMotoReset(INT8U ucSelected);

MOTO_EXT INT8U PlugInClear(INT16U uiCount);

MOTO_EXT INT8U AntToOutPreProcess(INT32U ulState);
MOTO_EXT INT8U LBoxToAntPreProcess(void);
MOTO_EXT INT8U AntToBoxPreProcess(INT32U ulState);
MOTO_EXT INT8U BoxToAntPreProcess(void);
MOTO_EXT INT8U LAntToOutPreProcess(INT32U ulState);
MOTO_EXT INT8U InToAntPreProcess(INT32U ulState);

MOTO_EXT void LOutAutoEvent(void);
MOTO_EXT void SOutAutoEvent(void);
MOTO_EXT void SInAutoEvent(void);
MOTO_EXT void ZInAutoEvent(void);
MOTO_EXT void SGInAutoEvent(void);



/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/

