/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: Global.h
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
#ifdef   GLOBAL_GLOBALS
#define  GLOBAL_EXT
#else
#define  GLOBAL_EXT  extern
#endif


/*******************************************************************************************************
*                                         Config Definition
*******************************************************************************************************/


#define DEBUG_EN							0

#define BUZZ_EN							        1 


#define BOARD_OLD_EN                                                    0

#define BOX_ID_CONST_EN                                                 1

#define COUNT_ID_EN                                                     1

#define PRINT_MOTO_EN                                                   0

#define SCAN_EN                                                         1

#define SCAN_AUTO_EN                                                    0

#define ULTRASOUND_NEW_EN                                               1

#define ULTRASOUND_LEN_7_EN                                             1

/*******************************************************************************************************
*                                         Register Definition
*******************************************************************************************************/



/*******************************************************************************************************
*                                         Hardware Definition
*******************************************************************************************************/



/*******************************************************************************************************
*                                         Constant Definition
*******************************************************************************************************/

#define CRC_INIT_VALUE							1
#define	CRC_POLYNOMIAL							0xA0001

#define TRUE                                                            1
#define FALSE                                                           0  	                                                            

#define BOX_POWER_ON_MODE                                               1
#define BOX_POWER_OFF_MODE                                              0

#define LEDOUT_OFF_MODE                                                 0
#define LEDOUT_ON_MODE                                                  1
#define LEDOUT_TOGGLE_MODE                                              2


#define CARDMACHINE_CARDBOX_NUMS			                3
#define CARDMACHINE_DMOTO_NUMS				                4
#define CARDMACHINE_SMOTO_NUMS				                2

#define UART_RX_PACKET_MAX                                              32
#define UART_RX_LEN_MAX							64//128


#define SMALL_THICK_OUT_TYPE						0x00
#define SMALL_THICK_IN_TYPE						0x01
#define SMALL_THICK_ZIN_TYPE						0x02
#define SMALL_THICK_GIN_TYPE						0x03
#define LARGE_THICK_OUT_TYPE						0x04

#define SMALL_THIN_OUT_TYPE						0x08
#define SMALL_THIN_IN_TYPE						0x09
#define SMALL_THIN_ZIN_TYPE						0x0A
#define SMALL_THIN_GIN_TYPE						0x0B
#define LARGE_THIN_OUT_TYPE						0x0C


#define LARGE_THICK_OUT_DEVICE_TYPE					0x84
#define SMALL_THICK_OUT_DEVICE_TYPE					0x80
#define SMALL_THICK_IN_DEVICE_TYPE					0x82
#define SMALL_THICK_GIN_DEVICE_TYPE					0x85
#define SMALL_THICK_ZIN_DEVICE_TYPE					0x86

#define LARGE_THIN_OUT_DEVICE_TYPE					0x84
#define SMALL_THIN_OUT_DEVICE_TYPE					0x80
#define SMALL_THIN_IN_DEVICE_TYPE					0x82
#define SMALL_THIN_GIN_DEVICE_TYPE					0x85
#define SMALL_THIN_ZIN_DEVICE_TYPE					0x86


//Uart
#define  BSP_GPIO0_UART0_TX                                             DEF_BIT_02    // P0.2                                                 
#define  BSP_GPIO0_UART0_RX                                             DEF_BIT_03    // P0.3                                                
#define  BSP_GPIO2_UART1_TX                                             DEF_BIT_00    // P2.0                                                 
#define  BSP_GPIO2_UART1_RX                                             DEF_BIT_01    // P2.1                                                 
#define  BSP_GPIO0_UART2_TX                                             DEF_BIT_10    // P0.10                                                
#define  BSP_GPIO0_UART2_RX                                             DEF_BIT_11    // P0.11                                                
#define  BSP_GPIO4_UART3_TX                                             DEF_BIT_28    // P4.28                                                
#define  BSP_GPIO4_UART3_RX                                             DEF_BIT_29    // P4.29                                                

//Moto
#if BOARD_OLD_EN==0

#define  BSP_GPIO_DMOTO1_EN1_PORT                                       CSP_GPIO_PORT_NBR_01                                               
#define  BSP_GPIO_DMOTO1_EN2_PORT                                       CSP_GPIO_PORT_NBR_01      

#define  BSP_GPIO_DMOTO1_EN1                                            DEF_BIT_18    // P1.18                                                 
#define  BSP_GPIO_DMOTO1_EN2                                            DEF_BIT_19    // P1.19                                                 

#define  BSP_GPIO_DMOTO2_EN1_PORT                                       CSP_GPIO_PORT_NBR_01                                               
#define  BSP_GPIO_DMOTO2_EN2_PORT                                       CSP_GPIO_PORT_NBR_01     

#define  BSP_GPIO_DMOTO2_EN1                                            DEF_BIT_21    // P1.21                                            
#define  BSP_GPIO_DMOTO2_EN2                                            DEF_BIT_20    // P1.20                                                 

#define  BSP_GPIO_DMOTO3_EN1_PORT                                       CSP_GPIO_PORT_NBR_01                                               
#define  BSP_GPIO_DMOTO3_EN2_PORT                                       CSP_GPIO_PORT_NBR_01   

#define  BSP_GPIO_DMOTO3_EN1                                            DEF_BIT_22    // P1.22                                                 
#define  BSP_GPIO_DMOTO3_EN2                                            DEF_BIT_23    // P1.23                                                 

#define  BSP_GPIO_DMOTO4_EN1_PORT                                       CSP_GPIO_PORT_NBR_01                                               
#define  BSP_GPIO_DMOTO4_EN2_PORT                                       CSP_GPIO_PORT_NBR_01    

#define  BSP_GPIO_DMOTO4_EN1                                            DEF_BIT_25    // P1.25                                                 
#define  BSP_GPIO_DMOTO4_EN2                                            DEF_BIT_24    // P1.24                                                 

#define  BSP_GPIO_SMOTO1_CC_PORT                                        CSP_GPIO_PORT_NBR_01                                             
#define  BSP_GPIO_SMOTO1_CLK_PORT                                       CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_SMOTO1_EN_PORT                                        CSP_GPIO_PORT_NBR_03                                                 
#define  BSP_GPIO_SMOTO1_RST_PORT                                       CSP_GPIO_PORT_NBR_01   

#define  BSP_GPIO_SMOTO1_CC                                             DEF_BIT_27    // P1.27                                                 
#define  BSP_GPIO_SMOTO1_CLK                                            DEF_BIT_28    // P1.28                                                 
#define  BSP_GPIO_SMOTO1_EN                                             DEF_BIT_25    // P3.25                                                 
#define  BSP_GPIO_SMOTO1_RST                                            DEF_BIT_26    // P1.26                                                 

#define  BSP_GPIO_SMOTO2_CC_PORT                                        CSP_GPIO_PORT_NBR_03                                             
#define  BSP_GPIO_SMOTO2_CLK_PORT                                       CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_SMOTO2_EN_PORT                                        CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_SMOTO2_RST_PORT                                       CSP_GPIO_PORT_NBR_01     

#define  BSP_GPIO_SMOTO2_CC                                             DEF_BIT_26    // P3.26                                                 
#define  BSP_GPIO_SMOTO2_CLK                                            DEF_BIT_29    // P1.29                                                 
#define  BSP_GPIO_SMOTO2_EN                                             DEF_BIT_10    // P1.10                                                 
#define  BSP_GPIO_SMOTO2_RST                                            DEF_BIT_09    // P1.09                                                 


#define  BSP_GPIO_DMOTO1_POSA_PORT                                      CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_DMOTO1_POSB_PORT                                      CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_CARD_POSE1_PORT                                       CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_BOXLOAD1_PORT                                         CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_BOX1_REV1_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_BOX1_REV2_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_BOX1_POS_PORT                                         CSP_GPIO_PORT_NBR_01      

// The positionA switch of DC MOTOR1
#define  BSP_GPIO_DMOTO1_POSA                                           DEF_BIT_04    // P0.4  
// The positionB switch of DC MOTOR1
#define  BSP_GPIO_DMOTO1_POSB                                           DEF_BIT_05    // P0.5    
// The position switch of INPUT CARD
#define  BSP_GPIO_CARD_POSE1                                            DEF_BIT_06    // P0.6     
// The position of the BOX LOADER?
#define  BSP_GPIO_BOXLOAD1                                              DEF_BIT_07    // P0.7                                                 
#define  BSP_GPIO_BOX1_REV1                                             DEF_BIT_08    // P0.8                                                 
#define  BSP_GPIO_BOX1_REV2                                             DEF_BIT_09    // P0.9                                                 
#define  BSP_GPIO_BOX1_POS                                              DEF_BIT_01    // P1.1                                                 

#define  BSP_GPIO_DMOTO2_POSA_PORT                                      CSP_GPIO_PORT_NBR_02                                                
#define  BSP_GPIO_DMOTO2_POSB_PORT                                      CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_CARD_POSE2_PORT                                       CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_BOXLOAD2_PORT                                         CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_BOX2_REV1_PORT                                        CSP_GPIO_PORT_NBR_02                                                
#define  BSP_GPIO_BOX2_REV2_PORT                                        CSP_GPIO_PORT_NBR_02                                                
#define  BSP_GPIO_BOX2_POS_PORT                                         CSP_GPIO_PORT_NBR_01       

#define  BSP_GPIO_DMOTO2_POSA                                           DEF_BIT_02    // P2.2                                                 
#define  BSP_GPIO_DMOTO2_POSB                                           DEF_BIT_03    // P2.3                                                 
#define  BSP_GPIO_CARD_POSE2                                            DEF_BIT_04    // P2.4                                                 
#define  BSP_GPIO_BOXLOAD2                                              DEF_BIT_05    // P2.5                                                 
#define  BSP_GPIO_BOX2_REV1                                             DEF_BIT_06    // P2.6                                                 
#define  BSP_GPIO_BOX2_REV2                                             DEF_BIT_07    // P2.7                                                 
#define  BSP_GPIO_BOX2_POS                                              DEF_BIT_04    // P1.4                                                 

#define  BSP_GPIO_DMOTO3_POSA_PORT                                      CSP_GPIO_PORT_NBR_02                                                
#define  BSP_GPIO_DMOTO3_POSB_PORT                                      CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_CARD_POSE3_PORT                                       CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_BOXLOAD3_PORT                                         CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_BOX3_REV1_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_BOX3_REV2_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_BOX3_POS_PORT                                         CSP_GPIO_PORT_NBR_01      

#define  BSP_GPIO_DMOTO3_POSA                                           DEF_BIT_08    // P2.8                                                 
#define  BSP_GPIO_DMOTO3_POSB                                           DEF_BIT_09    // P2.9                                                 
#define  BSP_GPIO_CARD_POSE3                                            DEF_BIT_16    // P0.16                                                 
#define  BSP_GPIO_BOXLOAD3                                              DEF_BIT_15    // P0.15                                                 
#define  BSP_GPIO_BOX3_REV1                                             DEF_BIT_17    // P0.17                                                
#define  BSP_GPIO_BOX3_REV2                                             DEF_BIT_18    // P0.18                                                
#define  BSP_GPIO_BOX3_POS                                              DEF_BIT_08    // P1.8                                                 

#define  BSP_GPIO_CARD_POSA_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_CARD_POSB_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_CARD_POSC_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_CARD_POSD_PORT                                        CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_CARD_POSE_PORT                                        CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_CARD_POSF_PORT                                        CSP_GPIO_PORT_NBR_02     

#define  BSP_GPIO_CARD_POSA                                             DEF_BIT_19    // P0.19                                                 
#define  BSP_GPIO_CARD_POSB                                             DEF_BIT_20    // P0.20                                                 
#define  BSP_GPIO_CARD_POSC                                             DEF_BIT_21    // P0.21                                                 
#define  BSP_GPIO_CARD_POSD                                             DEF_BIT_22    // P0.22                                                 
#define  BSP_GPIO_CARD_POSE                                             DEF_BIT_11    // P2.11                                                 
#define  BSP_GPIO_CARD_POSF                                             DEF_BIT_12    // P2.12                                                


#define  BSP_GPIO_AUTOCARD_PORT                                         CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_AUTOCARD                                              DEF_BIT_23    // P0.23                                                 
#define  BSP_GPIO_AUTOCARD_BIT                                          23                                                 

#define  BSP_GPIO_DEV_TYPE_PORT                                         CSP_GPIO_PORT_NBR_00
// There are 3 different device types, big card, small card, and self terminal
#define  BSP_GPIO_DEV1_TYPE                                             DEF_BIT_24    // P0.24                                                 
#define  BSP_GPIO_DEV2_TYPE                                             DEF_BIT_25    // P0.25                                                 
#define  BSP_GPIO_DEV3_TYPE                                             DEF_BIT_26    // P0.26         
#define  BSP_GPIO_DEV1_TYPE_BIT                                         24                                                 
#define  BSP_GPIO_DEV2_TYPE_BIT                                         25                                                 
#define  BSP_GPIO_DEV3_TYPE_BIT                                         26                                                 

#define  BSP_GPIO_BOX1_SELECT_PORT                                      CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_BOX2_SELECT_PORT                                      CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_BOX3_SELECT_PORT                                      CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_BOX1_SELECT                                           DEF_BIT_14    // P1.14                                                 
#define  BSP_GPIO_BOX2_SELECT                                           DEF_BIT_15    // P1.15                                                
#define  BSP_GPIO_BOX3_SELECT                                           DEF_BIT_17    // P1.17                                                	
#define  BSP_GPIO_BOX1_SELECT_BIT                                       14                                                 
#define  BSP_GPIO_BOX2_SELECT_BIT                                       15                                                
#define  BSP_GPIO_BOX3_SELECT_BIT                                       17                                                	


#define  BSP_GPIO_SELFTEST_KEY_PORT                                     CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_SELFTEST_KEY                                          DEF_BIT_10    //P2.10                                                 

//Buzz
#define  BSP_GPIO_BUZZ_OUT_PORT                                         CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPI0_BUZZ_OUT                                              DEF_BIT_16    //P1.16

#else

#define  BSP_GPIO_DMOTO1_EN1_PORT                                       CSP_GPIO_PORT_NBR_01                                               
#define  BSP_GPIO_DMOTO1_EN2_PORT                                       CSP_GPIO_PORT_NBR_01     

#define  BSP_GPIO_DMOTO1_EN1                                            DEF_BIT_14   // P1.14                                                
#define  BSP_GPIO_DMOTO1_EN2                                            DEF_BIT_15   // P1.15                                                

#define  BSP_GPIO_DMOTO2_EN1_PORT                                       CSP_GPIO_PORT_NBR_01                                               
#define  BSP_GPIO_DMOTO2_EN2_PORT                                       CSP_GPIO_PORT_NBR_01       

#define  BSP_GPIO_DMOTO2_EN1                                            DEF_BIT_16    // P1.16                                          
#define  BSP_GPIO_DMOTO2_EN2                                            DEF_BIT_17    // P1.17                                               

#define  BSP_GPIO_DMOTO3_EN1_PORT                                       CSP_GPIO_PORT_NBR_00                                               
#define  BSP_GPIO_DMOTO3_EN2_PORT                                       CSP_GPIO_PORT_NBR_00        

#define  BSP_GPIO_DMOTO3_EN1                                            DEF_BIT_04    // P0.4                                                 
#define  BSP_GPIO_DMOTO3_EN2                                            DEF_BIT_05    // P0.5                                                 

#define  BSP_GPIO_DMOTO4_EN1_PORT                                       CSP_GPIO_PORT_NBR_00                                               
#define  BSP_GPIO_DMOTO4_EN2_PORT                                       CSP_GPIO_PORT_NBR_00       

#define  BSP_GPIO_DMOTO4_EN1                                            DEF_BIT_06    // P0.6                                                 
#define  BSP_GPIO_DMOTO4_EN2                                            DEF_BIT_07    // P0.7                                                 

#define  BSP_GPIO_SMOTO1_CC_PORT                                        CSP_GPIO_PORT_NBR_01                                             
#define  BSP_GPIO_SMOTO1_CLK_PORT                                       CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_SMOTO1_EN_PORT                                        CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_SMOTO1_RST_PORT                                       CSP_GPIO_PORT_NBR_01          

#define  BSP_GPIO_SMOTO1_CC                                             DEF_BIT_01    // P1.1                                                 
#define  BSP_GPIO_SMOTO1_CLK                                            DEF_BIT_00    // P1.0                                                 
#define  BSP_GPIO_SMOTO1_EN                                             DEF_BIT_04    // P1.4                                                 
#define  BSP_GPIO_SMOTO1_RST                                            DEF_BIT_04    // P1.4                                                 

#define  BSP_GPIO_SMOTO2_CC_PORT                                        CSP_GPIO_PORT_NBR_01                                             
#define  BSP_GPIO_SMOTO2_CLK_PORT                                       CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_SMOTO2_EN_PORT                                        CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_SMOTO2_RST_PORT                                       CSP_GPIO_PORT_NBR_01         

#define  BSP_GPIO_SMOTO2_CC                                             DEF_BIT_09    // P1.09                                                 
#define  BSP_GPIO_SMOTO2_CLK                                            DEF_BIT_08    // P1.08                                                 
#define  BSP_GPIO_SMOTO2_EN                                             DEF_BIT_10    // P1.10                                                 
#define  BSP_GPIO_SMOTO2_RST                                            DEF_BIT_10    // P1.10                                                 


#define  BSP_GPIO_DMOTO1_POSA_PORT                                      CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_DMOTO1_POSB_PORT                                      CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_CARD_POSE1_PORT                                       CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_BOXLOAD1_PORT                                         CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_BOX1_REV1_PORT                                        CSP_GPIO_PORT_NBR_01                                                
#define  BSP_GPIO_BOX1_REV2_PORT                                        CSP_GPIO_PORT_NBR_01                                                
#define  BSP_GPIO_BOX1_POS_PORT                                         CSP_GPIO_PORT_NBR_01           

#define  BSP_GPIO_DMOTO1_POSA                                           DEF_BIT_20    // P0.20                                               
#define  BSP_GPIO_DMOTO1_POSB                                           DEF_BIT_21    // P0.21                                                
#define  BSP_GPIO_CARD_POSE1                                            DEF_BIT_08    // P2.8                                                 
#define  BSP_GPIO_BOXLOAD1                                              DEF_BIT_28    // P1.28                                                
#define  BSP_GPIO_BOX1_REV1                                             DEF_BIT_21    // P1.21                                                
#define  BSP_GPIO_BOX1_REV2                                             DEF_BIT_21    // P1.21                                                
#define  BSP_GPIO_BOX1_POS                                              DEF_BIT_24    // P1.24                                                

#define  BSP_GPIO_DMOTO2_POSA_PORT                                      CSP_GPIO_PORT_NBR_02                                                
#define  BSP_GPIO_DMOTO2_POSB_PORT                                      CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_CARD_POSE2_PORT                                       CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_BOXLOAD2_PORT                                         CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_BOX2_REV1_PORT                                        CSP_GPIO_PORT_NBR_01                                                
#define  BSP_GPIO_BOX2_REV2_PORT                                        CSP_GPIO_PORT_NBR_01                                                
#define  BSP_GPIO_BOX2_POS_PORT                                         CSP_GPIO_PORT_NBR_01                                                

#define  BSP_GPIO_DMOTO2_POSA                                           DEF_BIT_11    // P2.11                                                
#define  BSP_GPIO_DMOTO2_POSB                                           DEF_BIT_12    // P2.12                                                
#define  BSP_GPIO_CARD_POSE2                                            DEF_BIT_09    // P2.9                                                 
#define  BSP_GPIO_BOXLOAD2                                              DEF_BIT_27    // P1.27                                                
#define  BSP_GPIO_BOX2_REV1                                             DEF_BIT_20    // P1.20                                                
#define  BSP_GPIO_BOX2_REV2                                             DEF_BIT_20    // P1.20                                                
#define  BSP_GPIO_BOX2_POS                                              DEF_BIT_23    // P1.23                                                

#define  BSP_GPIO_DMOTO3_POSA_PORT                                      CSP_GPIO_PORT_NBR_02                                                
#define  BSP_GPIO_DMOTO3_POSB_PORT                                      CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_CARD_POSE3_PORT                                       CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_BOXLOAD3_PORT                                         CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_BOX3_REV1_PORT                                        CSP_GPIO_PORT_NBR_01                                                
#define  BSP_GPIO_BOX3_REV2_PORT                                        CSP_GPIO_PORT_NBR_01                                              
#define  BSP_GPIO_BOX3_POS_PORT                                         CSP_GPIO_PORT_NBR_01                                                 

#define  BSP_GPIO_DMOTO3_POSA                                           DEF_BIT_13    // P2.13                                                
#define  BSP_GPIO_DMOTO3_POSB                                           DEF_BIT_29    // P1.29                                                
#define  BSP_GPIO_CARD_POSE3                                            DEF_BIT_16    // P0.16                                                 
#define  BSP_GPIO_BOXLOAD3                                              DEF_BIT_26    // P1.26                                                 
#define  BSP_GPIO_BOX3_REV1                                             DEF_BIT_19    // P0.17                                                
#define  BSP_GPIO_BOX3_REV2                                             DEF_BIT_19    // P0.18                                                
#define  BSP_GPIO_BOX3_POS                                              DEF_BIT_22    // P1.22                                                

#define  BSP_GPIO_CARD_POSA_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_CARD_POSB_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_CARD_POSC_PORT                                        CSP_GPIO_PORT_NBR_00                                                
#define  BSP_GPIO_CARD_POSD_PORT                                        CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_CARD_POSE_PORT                                        CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_CARD_POSF_PORT                                        CSP_GPIO_PORT_NBR_01                                                

#define  BSP_GPIO_CARD_POSA                                             DEF_BIT_15    // P0.15                                                 
#define  BSP_GPIO_CARD_POSB                                             DEF_BIT_17    // P0.17                                                 
#define  BSP_GPIO_CARD_POSC                                             DEF_BIT_19    // P0.19                                                 
#define  BSP_GPIO_CARD_POSD                                             DEF_BIT_07    // P2.7                                                 
#define  BSP_GPIO_CARD_POSE                                             DEF_BIT_18    // P1.18                                                 
#define  BSP_GPIO_CARD_POSF                                             DEF_BIT_18    // P1.18                                                

#define  BSP_GPIO_AUTOCARD_PORT                                         CSP_GPIO_PORT_NBR_01                                                 
#define  BSP_GPIO_AUTOCARD                                              DEF_BIT_25    // P1.25                                                 
#define  BSP_GPIO_AUTOCARD_BIT                                          25                                                 

#define  BSP_GPIO_DEV_TYPE_PORT                                         CSP_GPIO_PORT_NBR_00
#define  BSP_GPIO_DEV2_TYPE_PORT                                        CSP_GPIO_PORT_NBR_03                                                 
#define  BSP_GPIO_DEV3_TYPE_PORT                                        CSP_GPIO_PORT_NBR_03                                                 
#define  BSP_GPIO_DEV1_TYPE                                             DEF_BIT_18    // P0.18                                                 
#define  BSP_GPIO_DEV2_TYPE                                             DEF_BIT_25    // P3.25                                                 
#define  BSP_GPIO_DEV3_TYPE                                             DEF_BIT_26    // P3.26                                                 
#define  BSP_GPIO_DEV1_TYPE_BIT                                         18                                                 
#define  BSP_GPIO_DEV2_TYPE_BIT                                         25                                                 


#define  BSP_GPIO_BOX1_SELECT_PORT                                      CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_BOX2_SELECT_PORT                                      CSP_GPIO_PORT_NBR_00                                                 
#define  BSP_GPIO_BOX3_SELECT_PORT                                      CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_BOX1_SELECT                                           DEF_BIT_00    // P0.0                                                 
#define  BSP_GPIO_BOX2_SELECT                                           DEF_BIT_01    // P0.1                                                
#define  BSP_GPIO_BOX3_SELECT                                           DEF_BIT_02    // P2.2                                                	
#define  BSP_GPIO_BOX1_SELECT_BIT                                       0                                                 
#define  BSP_GPIO_BOX2_SELECT_BIT                                       1                                                
#define  BSP_GPIO_BOX3_SELECT_BIT                                       2                                                	


#define  BSP_GPIO_SELFTEST_KEY_PORT                                     CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_SELFTEST_KEY                                          DEF_BIT_10    //P2.10                                                 

//Buzz
#define  BSP_GPIO_BUZZ_OUT_PORT                                         CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPI0_BUZZ_OUT                                              DEF_BIT_04    //P2.4

#endif

#define  BSP_GPIO_SCAN_PORT                                             CSP_GPIO_PORT_NBR_02                                                 
#define  BSP_GPIO_SCAN_OUT                                              DEF_BIT_00    // P2.0                                                 


//Lcd


#define DISPLAY_SELFTEST_MSG                     0
#define DISPLAY_MAIN_MSG                         1
#define DISPLAY_WRITING_MSG                      2
#define DISPLAY_INFO_MSG                         10


#define DISPLAY_ERR_MSG                          80


#define DISPLAY_POS_ERR_MSG                      3
#define DISPLAY_WRITE_ERR_MSG                    4
#define DISPLAY_COMM_ERR_MSG                     5
#define DISPLAY_UNLOAD_MSG                       6
#define DISPLAY_SWITCH_ERR_MSG                   7
#define DISPLAY_KEY_TEST_MSG                     8

#define DISPLAY_INFO_ONANT_HAVING_CARD_CMD       0
#define DISPLAY_INFO_ONEXIT_HAVING_CARD_CMD      1
#define DISPLAY_INFO_ONANTEXIT_HAVING_CARD_CMD   2
#define DISPLAY_INFO4_CMD                        0



//TASK
#define TASK_LCD                                0
#define TASK_BOX                                1
#define TASK_ACTION                             2

//MOTO
#define MOTO_STEP_MOVE_MSG                      0
#define MOTO_DC_MOVE_MSG                        1

#define MOTO_IN_TO_ANT_MSG                      0x20

#define MOTO_ANT_TO_BOX_MSG                     0x21

#define MOTO_BOX_TO_ANT_MSG                     0x10
#define MOTO_BOX_TO_ANT_B_MSG                   0x13

#define MOTO_ANT_TO_OUT_MSG                     0x11
#define MOTO_ANT_TO_OUT_B_MSG                   0x22

#define MOTO_ANT_TO_REV_MSG                     0x23

#define MOTO_DOOR_OPEN_MSG                      0x38
#define MOTO_PRINT_OPEN_MSG                     0x39

#define SCAN_OPEN_MSG                           0x3C


#define POWER_ON_SELFTEST_MSG                   99

/*******************************************************************************************************
*                                         Type Definition
*******************************************************************************************************/


typedef struct _Sound_Buzz {
  INT8U ucMode;
  INT8U ucTimes;
  INT8U ucKFrequence;
  INT8U ucGFrequence;
  INT8U ucKCurrent;
  INT8U ucGCurrent;
  INT8U ucPrior;
	
  INT8U ucBakTimes;
  INT16U uiStopFrequence;
  INT8U ucRepeatTimes;
}SOUNDBUZZ,*PSOUNDBUZZ;


typedef union __GLOBAL_FLAGS {
  INT8U ucFlag;
  struct{
    INT8U  bDispUpdate:1;							//定时更新显示
    INT8U  bBoxConnect:1;							//定时连接卡夹
    INT8U  bBoxConnectEn:1;							//连接卡夹使能
    INT8U  bBoxCountUpdate:1;							//定时重试写入卡数
    INT8U  bBoxChange:1;							//卡夹通道切换
    INT8U  bLedOutMode:2;							//出卡口LED灯模式，01：常亮，00：灭，10：闪烁
    INT8U  bGKey:1;
  }usrBit;
}GLOBAL_FLAGS,*P_GLOBAL_FLAGS;

typedef union __MODUAL_FLAGS {
  INT8U ucFlag;
  struct{
    INT8U  bCardPlugIn:1;							//插入卡片
    INT8U  bCardTakeout:1;							//取走卡片	
    INT8U  bGCardToBox:1;							//灌卡标志		
    INT8U  bGCardToOut:1;							//退卡标志		
    INT8U  bKeyTest:1;								//开关测试标志
    INT8U  bWaitTakeOut:1;                                                      //等待卡片拔出
  }usrBit;
}MODUAL_FLAGS,*P_MODUAL_FLAGS;

typedef union {
  INT16U ucFlag;
  struct{
    INT8U  bBoxLoad:1;								//已装载卡夹
    INT8U  bBoxUnload:1;							//已卸载卡夹
    INT8U  bConnected:1;							//已连接卡夹	
    INT8U  bSelftest:1;								//自检标志
    INT8U  bCountWrited:1;							//卡数已写入
    INT8U  bCardPos:1;								//卡片到位
    INT8U  bPosLow:1;								//到位开关低电平(遮挡)
    INT8U  bBuzzEn:1;								//提示音
    INT8U  bCommErr:1;                                                          //通讯错误
    INT8U  bPosErr:1;                                                           //卡片到位错误
    INT8U  bDMotoErr:1;                                                         //直流电机错误
    INT8U  bSMotoErr:1;                                                         //步进电机错误
  }usrBit;
}BOXINFO_FLAGS,*P_BOXINFO_FLAGS;

typedef struct
{
  INT8U ucRetrys;								//连接重试次数
  INT8U ucPosErrNums;								//未到位次数
  INT8U ucPosErrRetrys;								//未到位重试次数
}CONNECT_STRUCT;

typedef struct
{
  INT8U ucEnabled;
  INT32U ulMachineId;
  INT8U ucCurrentCount;
  INT8U ucNewCount;
  INT8U ucRetrys;
}COUNT_UPDATE;

typedef struct
{
    INT8U  ucCounts;							        //卡夹当前卡数
    INT8U  ucMaxCounts;								//卡机最大卡数
    INT32U ulMachineId;								//卡夹序列号
    INT8U  ucAlarmMax;								//卡机报警上限
    INT8U  ucAlarmMin;								//卡机报警下限
    INT8U  ucBoxMaxCounts;							//卡夹最大卡数
    INT8U  ucBuzzMode;								//提示音模式
    INT8U  ucTimes;                                                             //装载后延时时间次数
    BOXINFO_FLAGS usrFlag;																						
    COUNT_UPDATE usrCountResponse;
    CONNECT_STRUCT usrConnectResponse;
}BOXINFO;

typedef struct _Key_Value
{
  INT32U ulKeyValue;
  INT32U ulKeyTemp;
  INT32U ulKeyStore;
  INT32U ulKeyReady;
  INT32U ulKeyInput;
  INT32U ulKeyOutput;
  //INT32U ulKeyRepeat;
}KEYVALUE,*PKEYVALUE;


typedef struct
{
  int8u ucHead;
  int8u ucLen;
  int16u uiCluster;
  int8u ucCmd;
  int8u ucData[UART_RX_LEN_MAX-5];
}CommTxData;

typedef struct
{
  int8u ucHead;
  int8u ucLen;
  int16u uiCluster;
  int8u ucCmd;
  int8u ucStatus;
  int8u ucData[UART_RX_LEN_MAX];
}CommRxData;


typedef struct
{
  int8u ucHead;
  int8u ucAddr;
  int8u ucSeq;
  int8u ucCmd;
  int8u ucData[59];
  int8u ucLen;
}CardMachineRxData;

typedef struct _DMOTO {
  INT8U ucDirection;  
  INT16U uiFreq;  
  INT16U uiPwm; 
  INT8U ucEnabled;
  INT16U uiTime;
}DMOTO, *PDMOTO;

typedef struct _SMOTO {
  INT8U ucDirection;	// 0: forward, 1:backward
  INT8U ucFreq;		//The pulse clk for the step motor(*10us), 60:600us.
  INT16U uiCounts;		// How long does the step motor run (*10ms), 90:900ms.
  INT16U uiBakCounts;
  INT8U ucEnabled; 	//0: disable, 1:enable
  INT16U uiTime;		// How long does the step motor run timeout (*10ms).
}SMOTO, *PSMOTO;

typedef union __MOTO_FLAGS {
  INT16U uiFlag;
  struct{
    INT8U  bCardA:1;
    INT8U  bCardB:1;
    INT8U  bCardC:1;
    INT8U  bCardD:1;
  }usrBit;
}MOTO_FLAGS,*P_MOTO_FLAGS;

typedef union __INTERRUPT_FLAGS {
  INT8U ucFlag;
  struct{
    INT8U  bDMotoPosAPre:1;
    INT8U  bDMotoPosBPre:1;
    INT8U  bDMotoPosA:1;
    INT8U  bDMotoPosB:1;
    INT8U  bCardBoxPosLow:1;
  }usrBit;
}INTERRUPT_FLAGS,*P_INTERRUPT_FLAGS;

typedef union __ERROR_FLAGS {
  INT8U ucFlag;
  struct{
    INT8U  bDMotoPosA1:1;                                                                  
    INT8U  bDMotoPosA2:1;        
    INT8U  bDMotoPosA3:1;        
    INT8U  bBoxToAnt:1;
    INT8U  bSystem:1;
    INT8U  bSelfTest:2;
  }usrBit;
}ERROR_FLAGS,*P_ERROR_FLAGS;

typedef struct _SCAN {
  INT16U b14Times:14;
  INT16U bMode:1;
  INT16U bEnabled:1;
}SCAN, *PSCAN;



/*******************************************************************************************************
*                                         Data Definition
*******************************************************************************************************/

GLOBAL_EXT  INT8U g_ucScanOpenTime;                     
GLOBAL_EXT  INT8U g_ucScanCloseTime;                     

#if SCAN_EN==1
GLOBAL_EXT SCAN g_usrScan;
#endif

GLOBAL_EXT INT8U g_ucLedMode;
GLOBAL_EXT INT8U g_ucLedErrMode;

GLOBAL_EXT INT8U g_ucJLed1Mode;
GLOBAL_EXT INT8U g_ucJLed2Mode;


#if BUZZ_EN>0
GLOBAL_EXT SOUNDBUZZ g_usrBuzz;
#endif

GLOBAL_EXT INT8U g_ucBoxCurSelected;																										//当前选择的卡夹通道
GLOBAL_EXT INT8U m_ucBoxCurWorking;																											//当前工作卡夹

GLOBAL_EXT INT8U m_ucMachineAddr;																												//卡机地址
GLOBAL_EXT INT8U m_ucBoxAddr;																														//卡夹地址

GLOBAL_EXT INT8U m_ucDMotoRetrys;																												//光电开关损坏后，直流电机重试次数

GLOBAL_EXT KEYVALUE g_usrGetKey;
GLOBAL_EXT INT32U m_ulKeyOutput;

GLOBAL_EXT KEYVALUE g_usrGetKey1;

GLOBAL_EXT INT8U m_strVersion[32];
GLOBAL_EXT GLOBAL_FLAGS g_usrGlobalFlag;
GLOBAL_EXT MODUAL_FLAGS m_usrGlobalFlag;
GLOBAL_EXT BOXINFO m_usrBoxInfo[CARDMACHINE_CARDBOX_NUMS];

GLOBAL_EXT INT8U m_ucCardBoxTxSeq;

GLOBAL_EXT INT8U g_ucGKeyTime;
GLOBAL_EXT INT8U g_ucGInState;

GLOBAL_EXT INT8U m_ucDMotoBit[CARDMACHINE_DMOTO_NUMS+CARDMACHINE_DMOTO_NUMS];
GLOBAL_EXT INT8U m_ucSMotoBit[CARDMACHINE_SMOTO_NUMS];
GLOBAL_EXT INT8U m_ucUartBit[CARDMACHINE_CARDBOX_NUMS];
GLOBAL_EXT INT8U m_ucKeyBit[32];
GLOBAL_EXT INT8U m_ucBoxBit[CARDMACHINE_DMOTO_NUMS];
GLOBAL_EXT INT16U m_uiDMotoPwm[CARDMACHINE_DMOTO_NUMS];
GLOBAL_EXT INT8U m_ucSMotoFreq[CARDMACHINE_SMOTO_NUMS];

GLOBAL_EXT DMOTO g_usrDMoto[CARDMACHINE_DMOTO_NUMS];              //?±á÷μ??ú
GLOBAL_EXT SMOTO g_usrSMoto[CARDMACHINE_SMOTO_NUMS];              //2???μ??ú

GLOBAL_EXT MOTO_FLAGS g_usrMotoFlags;
GLOBAL_EXT INT8U g_ucCommTime;						
//GLOBAL_EXT INT8U g_ucCommTime1;						
//GLOBAL_EXT INT8U g_ucCommTime2;						
//GLOBAL_EXT INT16U g_uiTakeoutOvertime;    //è?3??¨??ê±??
//GLOBAL_EXT INT8U g_ucPowerTime;						//?¨?Dí¨μ?oó?óê±ê±??
//GLOBAL_EXT INT16U g_uiWaitPosTime;				//?¨?D?′μ???μè′yê±??

//GLOBAL_EXT INT8U g_ucWorkState;

GLOBAL_EXT INTERRUPT_FLAGS g_usrInterruptFlags[CARDMACHINE_DMOTO_NUMS];
GLOBAL_EXT ERROR_FLAGS m_usrErrorFlags;

/*******************************************************************************************************
*                                         Macro Definition
*******************************************************************************************************/


#define CheckBit(x,y) 			                        (x& (1<<y))
#define ClrBit(x,y)					        (x&=(~(1<<y)))
#define SetBit(x,y)					        (x|=(1<<y))

#define ValidBit(x,y)                                           CheckBit(x,y)
#define NoValidBit(x,y)                                         !CheckBit(x,y)

#define OS_ENTER_CRITICAL()                                     CPU_CRITICAL_ENTER() 
#define OS_EXIT_CRITICAL()                                      CPU_CRITICAL_EXIT()


#define TIMER0_ENABLED()					T0TCR=1
#define TIMER1_ENABLED()					T1TCR=1
#define TIMER2_ENABLED()					T2TCR=1
#define TIMER3_ENABLED()					T3TCR=1

#define TIMER0_SET(uiTime) 				        T0TC=0;T0MR0=uiTime
#define TIMER1_SET(uiTime) 				        T1TC=0;T1MR0=uiTime
#define TIMER2_SET(uiTime) 				        T2TC=0;T2MR0=uiTime
#define TIMER3_SET(uiTime) 				        T3TC=0;T3MR0=uiTime

#define TIMER0_DISABLED()					T1TCR=0
#define TIMER1_DISABLED()					T1TCR=0
#define TIMER2_DISABLED()					T2TCR=0
#define TIMER3_DISABLED()					T3TCR=0

#define PWM1_ENABLED()						PWM1IR=0xFF;PWM1TCR=0x09
#define PWM1_DISABLED()						PWM1IR=0xFF;PWM1TCR=0x00
#define PWM1_SET(uiMR0,uiMR1)			                PWM1MR0=uiMR0;PWM1MR1=uiMR1

#define SMOTO_SET_TIME(uiTime)                                  TIMER1_SET(uiTime)
#define SMOTO_ENABLED()                                         TIMER1_ENABLED()
#define SMOTO_DISABLED()                                        TIMER1_DISABLED()

#define DMOTO_ENABLED()                                         PWM1_ENABLED()
#define DMOTO_DISABLED()                                        PWM1_DISABLED()
#define DMOTO_SET_TIME(uiMR0,uiMR1)                             PWM1_SET(uiMR0,uiMR1)

#define KEY_ENABLED()						TIMER1_ENABLED()
#define KEY_DISABLED()						//TIMER1_DISABLED()

#if DEBUG_EN>0
#define DebugInfo(ucCmd,pucData,ucLen)	Uart0Pack(ucCmd,0,0,pucData,ucLen,1)
#define DebugInfoA(ucCmd,pucData,ucLen)	Uart0Pack(ucCmd,0,0,pucData,ucLen,1)
#else
#define DebugInfo(ucCmd,pucData,ucLen)	(ucCmd,pucData,ucLen)
#define DebugInfoA(ucCmd,pucData,ucLen)	(ucCmd,pucData,ucLen)
#endif


/*******************************************************************************************************
*                                         Function Prototypes
*******************************************************************************************************/

GLOBAL_EXT void GlobalInit(void);
GLOBAL_EXT void HardwareInit(void);
GLOBAL_EXT void RitInit(void);
GLOBAL_EXT void Timer0Init (void);
GLOBAL_EXT void Timer1Init (void);
GLOBAL_EXT void Timer2Init (void);
GLOBAL_EXT void Timer3Init (void);
GLOBAL_EXT void PWM1Init (void);
GLOBAL_EXT void ScanInit(void);

GLOBAL_EXT int16u RevCrc16Bytes(int8u *pucData,int8u usrLength,int16u uiPolynomial);
GLOBAL_EXT void BytesToAscs(INT8U *pucSource,INT8U ucLen,INT8U *pucDest);
GLOBAL_EXT INT8S AscToByte(INT8U ucData);
GLOBAL_EXT INT8S ByteToAsc(INT8U ucData);
GLOBAL_EXT void SprintF(INT8U *pucData,INT8U ucLen,INT32U ulData);


GLOBAL_EXT void SMotoFreqGet(void);
GLOBAL_EXT void DMotoPwmGet(void);
GLOBAL_EXT INT8U AutoOutModeGet(void);
GLOBAL_EXT INT8U BuzzEnGet(void);


GLOBAL_EXT void CardBoxBasicInfoSend(INT8U ucMode,INT8U ucSelected);
GLOBAL_EXT void CardCountUpdateSend(INT8U ucMode,INT8U ucSelected);


GLOBAL_EXT INT8U CardBoxGetSelected(void);
GLOBAL_EXT INT8U CardBoxGetSelectedA(void);
GLOBAL_EXT INT8U CardBoxSetSelected(INT8U ucSelected,INT8U ucMode);
GLOBAL_EXT INT8U CardBoxPower(INT8U ucMode);


GLOBAL_EXT void DMotoSelectGet(INT8U ucMode);
GLOBAL_EXT void SMotoSelectGet(INT8U ucMode);
GLOBAL_EXT void BoxSelectGet(INT8U ucMode);
GLOBAL_EXT void KeySelectGet(INT8U ucMode);
GLOBAL_EXT void KeyBitEncode(INT8U *pucData);
GLOBAL_EXT void KeyBitDecode(INT8U *pucData);

GLOBAL_EXT INT8U GroupSelectGet(void);
GLOBAL_EXT void ScanParamsGet(void);


GLOBAL_EXT INT8U DMotoPosBySelected(INT8U ucSelected);
GLOBAL_EXT INT8U DMotoByPos(INT8U ucPos);

GLOBAL_EXT INT8U DEV_TYPE(void);
GLOBAL_EXT INT8U CARD_AUTO_MODE(void);


GLOBAL_EXT INT8U Box_TaskQPost(OS_TCB *p_tcb,INT8U *p_ucMsg,INT8U ucLen);
GLOBAL_EXT INT8U Box_TaskLcdQPost(OS_TCB *p_tcb,INT8U *p_ucMsg,INT8U ucLen);


/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/
