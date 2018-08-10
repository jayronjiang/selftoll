/*******************************************************************************************************
*
*                                 (c) Copyright 2004-2007, John Tonny
*
*                                           All Rights Reserved
*
********************************************************************************************************
*
*--------------文件信息---------------------------------------------------------------------------------
*文   件   名: I2c.h
*创   建   人: John Tonny
*最后修改日期: 2005年05月01日
*描        述:
*              
*--------------历史版本信息-----------------------------------------------------------------------------
* 创建人: John Tonny
* 版  本: V1.0
* 日　期: 2005年05月01日
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

#ifdef   I2C_GLOBALS
#define  I2C_EXT
#else
#define  I2C_EXT  extern
#endif


/*******************************************************************************************************
*                                         Config Definition
*******************************************************************************************************/

#define FAST_MODE_PLUS      0

/*******************************************************************************************************
*                                         Register Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Hardware Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Constant Definition
*******************************************************************************************************/


#define I2CBUFSIZE              64

#define I2CMASTER               0x01
#define I2CSLAVE                0x02

#define PCF8594_ADDR            0xA0
#define READ_WRITE              0x01

#define RD_BIT                  0x01

#define I2C_IDLE                0
#define I2C_STARTED             1
#define I2C_RESTARTED           2
#define I2C_REPEATED_START      3
#define DATA_ACK                4
#define DATA_NACK               5
#define I2C_BUSY                6
#define I2C_NO_DATA             7
#define I2C_NACK_ON_ADDRESS     8
#define I2C_NACK_ON_DATA        9
#define I2C_ARBITRATION_LOST    10
#define I2C_TIME_OUT            11
#define I2C_OK                  12

#define I2CONSET_I2EN           (0x1<<6)  // I2C Control Set Register 
#define I2CONSET_AA             (0x1<<2)
#define I2CONSET_SI             (0x1<<3)
#define I2CONSET_STO            (0x1<<4)
#define I2CONSET_STA            (0x1<<5)

#define I2CONCLR_AAC            (0x1<<2)  // I2C Control clear Register 
#define I2CONCLR_SIC            (0x1<<3)
#define I2CONCLR_STAC           (0x1<<5)
#define I2CONCLR_I2ENC          (0x1<<6)

#define I2DAT_I2C	        0x00000000  // I2C Data Reg 
#define I2ADR_I2C		0x00000000  // I2C Slave Address Reg 
#define I2SCLH_SCLH		0x00000080  // I2C SCL Duty Cycle High Reg 
#define I2SCLL_SCLL		0x00000080  // I2C SCL Duty Cycle Low Reg 
#define I2SCLH_HS_SCLH		0x00000008  // Fast Plus I2C SCL Duty Cycle High Reg 
#define I2SCLL_HS_SCLL		0x00000008  // Fast Plus I2C SCL Duty Cycle Low Reg 


/*******************************************************************************************************
*                                         Type Definition
*******************************************************************************************************/

typedef enum {
	I2C_STATUS_DONE,	            // Transfer done successfully 
	I2C_STATUS_NAK,		            // NAK received during transfer 
	I2C_STATUS_ARBLOST,	            // Aribitration lost during transfer 
	I2C_STATUS_BUSERR,	            // Bus error in I2C transfer 
	I2C_STATUS_TIMEOUT,
	I2C_STATUS_BUSY,	            // I2C is busy doing transfer 
} I2C_STATUS_T;

typedef struct {
	uint8_t slaveAddr;		    // 7-bit I2C Slave address 
	const uint8_t *txBuff;	            // Pointer to array of bytes to be transmitted 
	int     txSz;			    // Number of bytes in transmit array,if 0 only receive transfer will be carried on 
	uint8_t *rxBuff;		    // Pointer memory where bytes received from I2C be stored 
	int     rxSz;			    // Number of bytes to received,if 0 only transmission we be carried on 
	uint32_t timeOut;
	I2C_STATUS_T status;	            //Status of the current I2C transfer 
	
} I2C_XFER_T;

/*******************************************************************************************************
*                                         Data Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Macro Definition
*******************************************************************************************************/


/*******************************************************************************************************
*                                         Function Prototypes
*******************************************************************************************************/


I2C_EXT void I2c0Init( void );
I2C_EXT uint32_t I2c0Start(void);
I2C_EXT uint32_t I2c0Stop(void);

I2C_EXT uint8_t I2cSend(uint8_t slaveAddr, uint8_t *txBuf,uint8_t txLen,uint8_t *rxBuf, uint8_t rxLen);

/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/



