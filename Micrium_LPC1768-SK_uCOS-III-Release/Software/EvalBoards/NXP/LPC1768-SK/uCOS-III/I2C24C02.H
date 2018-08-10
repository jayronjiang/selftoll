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

#ifdef   I2C24C02_GLOBALS
#define  I2C24C02_EXT
#else
#define  I2C24C02_EXT  extern
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


//24C02地址
#define ROMDEVADDR 0	//eeprom设备地址

#define ROMADDR_0 0x00
#define ROMADDR_DEVSERIAL ROMADDR_0
#define ROMADDR_DEVADDR ROMADDR_DEVSERIAL+4
#define ROMADDR_DEVMAXCRITINUM ROMADDR_DEVADDR+1
#define ROMADDR_DEVMINCRITINUM ROMADDR_DEVMAXCRITINUM+4

#define ROMADDR_BOX1SERIAL ROMADDR_DEVMINCRITINUM+4
#define ROMADDR_BOX1CARDNUM ROMADDR_BOX1SERIAL+9
#define ROMADDR_BOX1MAXNUM ROMADDR_BOX1CARDNUM+5
#define ROMADDR_BOX1MAXCRITINUM ROMADDR_BOX1MAXNUM+5
#define ROMADDR_BOX1MINCRITINUM ROMADDR_BOX1MAXCRITINUM+5

#define ROMADDR_BOX2SERIAL ROMADDR_BOX1MINCRITINUM+5
#define ROMADDR_BOX2CARDNUM ROMADDR_BOX2SERIAL+9
#define ROMADDR_BOX2MAXNUM ROMADDR_BOX2CARDNUM+5
#define ROMADDR_BOX2MAXCRITINUM ROMADDR_BOX2MAXNUM+5
#define ROMADDR_BOX2MINCRITINUM ROMADDR_BOX2MAXCRITINUM+5

#define ROMADDR_BOX3SERIAL ROMADDR_BOX2MAXNUM+5
#define ROMADDR_BOX3CARDNUM ROMADDR_BOX3SERIAL+9
#define ROMADDR_BOX3MAXNUM ROMADDR_BOX3CARDNUM+5
#define ROMADDR_BOX3MAXCRITINUM ROMADDR_BOX3MAXNUM+5
#define ROMADDR_BOX3MINCRITINUM ROMADDR_BOX3MAXCRITINUM+5

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


I2C24C02_EXT uint8_t EepromWriteBytes( uint8_t romAddr, uint8_t *info, uint8_t infolen );
I2C24C02_EXT uint8_t EepromReadBytes( uint8_t romAddr, uint8_t *info, uint8_t infolen );

I2C24C02_EXT uint8_t EepromWriteVerifyBytes( uint8_t romAddr, uint8_t *info, uint8_t infolen );
I2C24C02_EXT uint8_t EepromReadVerifyBytes(uint8_t romAddr,uint8_t *info,uint8_t infolen);


/*******************************************************************************************************
**                            End Of File
*******************************************************************************************************/




