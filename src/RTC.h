/*=============================================================================
 * Author: Ignacio Majul <imajul89@gmail.com>
 * Date: 2019/12/10
 *===========================================================================*/

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _DS3132_H_
#define _DS3132_H_

/*==================[inclusions]=============================================*/

#include <stdint.h>

/*==================[c++]====================================================*/
#ifdef __cplusplus
extern "C"
{
#endif

/*==================[macros]=================================================*/

#define TRUE 1
#define FALSE 0

// EEPROM24C32 total memory size in bytes
#define EEPROM_32_K_BIT 4096 // Memory size [bytes]

// EEPROM24C32 single page size (in bytes)
#define EEPROM24C32_PAGE_SIZE 32 // [bytes per page]

// EEPROM24C32 & DS3231 I2C address
#define EEPROM24C32_CTRL_CODE 0xA // 0b1010
#define DS3231_SLAVE_ADDRESS 0x68 // 0b1101000

// Function aliases
#define eeprom24C32ReadByte eeprom24C32ReadRandom

// Function utilities
#define EEPROM_ADDRESS_HIGH(address) ((uint8_t)((address & (0xFFFFFF00)) >> 8))
#define EEPROM_ADDRESS_LOW(address) ((uint8_t)(address & (0x000000FF)))

// ----------------------------------------------------------------------------

// EEPROM24C32 total memory size in bytes
// #define EEPROM24C32_MEMORY_SIZE   4 KBytes
#define EEPROM24C32_FIRST_MEMORY_ADDRESS 0x0000
#define EEPROM24C32_LAST_MEMORY_ADDRESS 0x0FFF
#define EEPROM24C32_MEMORY_SIZE (EEPROM24C32_LAST_MEMORY_ADDRESS + 1) //

// EEPROM24C32_MEMORY_SIZE / EEPROM24C32_PAGE_SIZE
#define EEPROM24C32_PAGE_AMOUNT EEPROAM24C32_MEMORY_SIZE / EEPROM24C32_PAGE_SIZE

	/*==================[typedef]================================================*/

	typedef struct
	{
		uint8_t year;  /* 0 to 99 */
		uint8_t month; /* 1 to 12   */
		uint8_t mday;  /* 1 to 31   */
		uint8_t wday;  /* 1 to 7    */
	} rtc_date_t;

	typedef struct
	{
		uint8_t hour; /* 0 to 23   */
		uint8_t min;  /* 0 to 59   */
		uint8_t sec;  /* 0 to 59   */
	} rtc_time_t;

	typedef struct
	{
		uint8_t alarm1_seconds; /* 0 to 59   */
		uint8_t alarm1_minutes; /* 0 to 59   */
		uint8_t alarm1_hours;	/* 1–12 + AM/PM / 00–23 */
		uint8_t alarm1_DY_DT;	/* 01 to 7  or 1 to 31 */
		uint8_t alarm2_minutes; /* 0 to 59   */
		uint8_t alarm2_hours;	/* 1–12 + AM/PM / 00–23 */
		uint8_t alarm2_DY_DT;	/* 01 to 7  or 1 to 31 */
		uint8_t control;
		uint8_t control_status;
		uint8_t aging_offset;
		uint8_t MSB_temp; /* temperatura byte superior */
		uint8_t LSB_temp; /* temperatura byte inferior */
	} rtc_control_t;

	typedef enum  
	{
		header,
		segundo,
		minuto,
		hora,
		dia_semana,
		dia_mes,
		mes,
		anio,
		a1segundo,
		a1minuto,
		a1hora,
		a1dydt,
		a2minuto,
		a2hora,
		a2dydt,
		ctrl,
		ctrl_status

	}registers;

	/*==================[external functions declaration]=========================*/

	//-----------------------------------------------------------------------------
	//  RTC and EEPROM MANAGEMENT
	//-----------------------------------------------------------------------------

	uint8_t RTC_Address(void);

	//-----------------------------------------------------------------------------
	// INITIALIZATION
	//-----------------------------------------------------------------------------

	void RTC_init_date ( rtc_date_t* now, uint8_t anio, uint8_t mes, uint8_t dia_mes, uint8_t dia_semana);
	void RTC_init_time ( rtc_time_t* now, uint8_t hora, uint8_t minuto, uint8_t segundo);
	void RTC_init_alarms ( rtc_control_t* now, uint8_t hora_alarma, uint8_t minuto_alarma, uint8_t segundo_alarma);

	//-----------------------------------------------------------------------------
	// WRITE OPERATIONS
	//-----------------------------------------------------------------------------

	// Write time registers
	void RTC_write_registers(rtc_date_t *date, rtc_time_t *time, rtc_control_t *control, int32_t i2c);

	// Reset alarm flags
	void RTC_reset_alarm(rtc_control_t *time, int32_t i2c);

	//-----------------------------------------------------------------------------
	// READ OPERATIONS
	//-----------------------------------------------------------------------------

	// Read time registers
	void RTC_read_time_and_date(rtc_date_t *date, rtc_time_t* time, uint8_t i2c);

// Current Address Read

/*==================[c++]====================================================*/
#ifdef __cplusplus
}
#endif

/*==================[end of file]============================================*/
#endif /* _DS3132_H_ */
