/*=============================================================================
 * Author: Ignacio Majul <imajul89@gmail.com>
 * Date: 2019/12/10
 *===========================================================================*/

/*==================[inclusions]=============================================*/
#include "RTC.h" // <= own header
#include "i2c.h"

#define eeprom24C32DelayMs delayInaccurateMs

/*==================[internal data definition]===============================*/
// DEBUG_PRINT_ENABLE

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

//-----------------------------------------------------------------------------
// MANAGEMENT
//-----------------------------------------------------------------------------

uint8_t RTC_Address(void)
{
	//           0b1101000
	return (DS3231_SLAVE_ADDRESS);
}

void RTC_init_date(rtc_date_t *now, uint8_t anio, uint8_t mes, uint8_t dia_mes, uint8_t dia_semana)
{
	now->year = (((anio / 10) << 4) | (anio % 10));
	now->month = (((mes / 10) << 4) | (mes % 10));
	now->mday = (((dia_mes / 10) << 4) | (dia_mes % 10));
	now->wday = (((dia_semana / 10) << 4) | (dia_semana % 10));
}

void RTC_init_time(rtc_time_t *now, uint8_t hora, uint8_t minuto, uint8_t segundo)
{
	now->hour = (((hora / 10) << 4) | (hora % 10));
	now->min = (((minuto / 10) << 4) | (minuto % 10));
	now->sec = (((segundo / 10) << 4) | (segundo % 10));
}

void RTC_init_alarms(rtc_control_t *now, uint8_t hora_alarma, uint8_t minuto_alarma, uint8_t segundo_alarma)
{
	now->alarm1_seconds = (((segundo_alarma / 10) << 4) | (segundo_alarma % 10));			 /* 0 to 59   */
	now->alarm1_minutes = 0b10000000 | (((minuto_alarma / 10) << 4) | (minuto_alarma % 10)); /* 0 to 59   */
	now->alarm1_hours = 0b10000000 | (((hora_alarma / 10) << 4) | (hora_alarma % 10));		 /* 1–12 + AM/PM / 00–23 */
	now->alarm1_DY_DT = 0b10000000;															 /* bit 7 = Alarm when hours, minutes, and seconds match. LSB=01 to 7  or 1 to 31 */
	now->alarm2_minutes = 0;																 /* 0 to 59   */
	now->alarm2_hours = 0;																	 /* 1–12 + AM/PM / 00–23 */
	now->alarm2_DY_DT = 0;																	 /* 01 to 7  or 1 to 31 */
	now->control = 0b00000101;																 /* Alarm 1 enable & Interrupt Control enable */
	now->control_status = 0;
	now->aging_offset;
	now->MSB_temp; /* temperatura byte superior */
	now->LSB_temp; /* temperatura byte inferior */
}

//-----------------------------------------------------------------------------
// WRITE OPERATIONS
//-----------------------------------------------------------------------------

// Write time registers
void RTC_write_registers(rtc_date_t *date, rtc_time_t *time, rtc_control_t *control, int32_t i2c)
{
	uint8_t dato[17];

	dato[header] = 0x00;
	dato[segundo] = time->sec;
	dato[minuto] = time->min;
	dato[hora] = time->hour;
	dato[dia_semana] = date->wday;
	dato[dia_mes] = date->mday;
	dato[mes] = date->month;
	dato[anio] = date->year;
	dato[a1segundo] = control->alarm1_seconds;
	dato[a1minuto] = control->alarm1_minutes;
	dato[a1hora] = control->alarm1_hours;
	dato[a1dydt] = control->alarm1_DY_DT;
	dato[a2minuto] = control->alarm2_minutes;
	dato[a2hora] = control->alarm2_hours;
	dato[a2dydt] = control->alarm2_DY_DT;
	dato[ctrl] = control->control;
	dato[ctrl_status] = control->control_status;

	i2cWrite(i2c,RTC_Address(),dato,sizeof(dato),TRUE );
}

// Reset alarm flags
void RTC_reset_alarm(rtc_control_t *time, int32_t i2c)
{
	uint8_t dato[2];

	dato[0] = 0x0F;
	dato[1] = time->control_status;

	i2cWrite(i2c,RTC_Address(),dato,2,TRUE );
}

// Byte Write

//-----------------------------------------------------------------------------
// READ OPERATIONS
//-----------------------------------------------------------------------------

// Read time registers
void RTC_read_time_and_date(rtc_date_t *date, rtc_time_t* time, uint8_t i2c)
{
	uint8_t lectura[19] = {0};

	i2cRead(i2c, RTC_Address(), 0, 0, FALSE, lectura, sizeof(lectura), TRUE);

	date->year = lectura[10];
	date->month = lectura[9];
	date->mday = lectura[8];
	date->wday = lectura[7];
	time->hour = lectura[6];
	time->min = lectura[5];
	time->sec = lectura[4];
}

/*==================[ISR external functions definition]======================*/

/*==================[end of file]============================================*/
