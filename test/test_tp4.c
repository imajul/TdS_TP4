
#include "RTC.h"
#include "unity.h"
#include "mock_i2c.h"

#define I2Cport 0

// SETEO DE FECHA, HORA Y ALARMA
#define ANIO 19
#define MES 12
#define DIA_MES 25
#define DIA_SEMANA 03
#define HORA 20
#define MINUTOS 19
#define SEGUNDOS 00
#define ALARMA_HORA 20
#define ALARMA_MINUTOS 30
#define ALARMA_SEGUNDOS 05

// DEFINICION DE SETEOS EN FORMATO BCD
#define xANIO               ANIO / 10 * 16 + ANIO % 10
#define xMES                MES / 10 * 16 + MES % 10
#define xDIA_MES            DIA_MES / 10 * 16 + DIA_MES % 10
#define xHORA               HORA / 10 * 16 + HORA % 10
#define xMINUTOS            MINUTOS / 10 * 16 + MINUTOS % 10
#define xSEGUNDOS           SEGUNDOS / 10 * 16 + SEGUNDOS % 10
#define xALARMA_HORA        ALARMA_HORA / 10 * 16 + ALARMA_HORA % 10
#define xALARMA_MINUTOS     ALARMA_MINUTOS / 10 * 16 + ALARMA_MINUTOS % 10
#define xALARMA_SEGUNDOS    ALARMA_SEGUNDOS / 10 * 16 + ALARMA_SEGUNDOS % 10

static rtc_date_t date;
static rtc_time_t time;
static rtc_control_t control;

void setUp(void) {}

void tearDown(void) {}

void test_rtcAddressCheck(void)
{
    TEST_ASSERT_EQUAL(0x68, RTC_Address());
}

void test_rtcInitDateCheck(void)
{
    RTC_init_date(&date, ANIO, MES, DIA_MES, DIA_SEMANA);

    TEST_ASSERT_EQUAL(xANIO, date.year); 
    TEST_ASSERT_EQUAL(xMES, date.month);
    TEST_ASSERT_EQUAL(xDIA_MES, date.mday);
}

void test_rtcInitTimeCheck(void)
{
    RTC_init_time(&time, HORA, MINUTOS, SEGUNDOS);

    TEST_ASSERT_EQUAL(xHORA, time.hour);
    TEST_ASSERT_EQUAL(xMINUTOS, time.min);
    TEST_ASSERT_EQUAL(xSEGUNDOS, time.sec);
}

void test_rtcInitAlarmCheck(void)
{
    RTC_init_alarms(&control, ALARMA_HORA, ALARMA_MINUTOS, ALARMA_SEGUNDOS);

    TEST_ASSERT_EQUAL(0b10000000 | xALARMA_HORA, control.alarm1_hours);
    TEST_ASSERT_EQUAL(0b10000000 | xALARMA_MINUTOS, control.alarm1_minutes);
    TEST_ASSERT_EQUAL(xALARMA_SEGUNDOS, control.alarm1_seconds);
}

void test_rtcReadCheck(void)
{
    uint8_t buffer[19] = {0, 0, 0, 0, xSEGUNDOS, xMINUTOS, xHORA, 0, xDIA_MES, xMES, xANIO, 0, 0, 0, 0, 0, 0, 0, 0};

    i2cRead_Expect(I2Cport, RTC_Address(), (uint8_t *)0, 0, FALSE, buffer, sizeof(buffer), TRUE);
    i2cRead_ReturnArrayThruPtr_lectura(buffer, sizeof(buffer));

    RTC_read_time_and_date(&date, &time, I2Cport);

    TEST_ASSERT_EQUAL(xANIO, date.year); 
    TEST_ASSERT_EQUAL(xMES, date.month);
    TEST_ASSERT_EQUAL(xDIA_MES, date.mday);
    TEST_ASSERT_EQUAL(xHORA, time.hour);
    TEST_ASSERT_EQUAL(xMINUTOS, time.min);
    TEST_ASSERT_EQUAL(xSEGUNDOS, time.sec);
}