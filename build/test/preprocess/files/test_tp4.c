#include "build/temp/_test_tp4.c"
#include "build/test/mocks/mock_i2c.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"
#include "src/RTC.h"


static rtc_date_t date;

static rtc_time_t time;

static rtc_control_t control;



void setUp(void) {}



void tearDown(void) {}



void test_rtcAddressCheck(void)

{

    UnityAssertEqualNumber((UNITY_INT)((0x68)), (UNITY_INT)((RTC_Address())), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}



void test_rtcInitDateCheck(void)

{

    RTC_init_date(&date, 19, 12, 25, 03);



    UnityAssertEqualNumber((UNITY_INT)((19 / 10 * 16 + 19 % 10)), (UNITY_INT)((date.year)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((12 / 10 * 16 + 12 % 10)), (UNITY_INT)((date.month)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((25 / 10 * 16 + 25 % 10)), (UNITY_INT)((date.mday)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_INT);

}



void test_rtcInitTimeCheck(void)

{

    RTC_init_time(&time, 20, 19, 00);



    UnityAssertEqualNumber((UNITY_INT)((20 / 10 * 16 + 20 % 10)), (UNITY_INT)((time.hour)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((19 / 10 * 16 + 19 % 10)), (UNITY_INT)((time.min)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((00 / 10 * 16 + 00 % 10)), (UNITY_INT)((time.sec)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_INT);

}



void test_rtcInitAlarmCheck(void)

{

    RTC_init_alarms(&control, 20, 30, 05);



    UnityAssertEqualNumber((UNITY_INT)((0b10000000 | 20 / 10 * 16 + 20 % 10)), (UNITY_INT)((control.alarm1_hours)), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((0b10000000 | 30 / 10 * 16 + 30 % 10)), (UNITY_INT)((control.alarm1_minutes)), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((05 / 10 * 16 + 05 % 10)), (UNITY_INT)((control.alarm1_seconds)), (

   ((void *)0)

   ), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}



void test_rtcReadCheck(void)

{

    uint8_t buffer[19] = {0, 0, 0, 0, 00 / 10 * 16 + 00 % 10, 19 / 10 * 16 + 19 % 10, 20 / 10 * 16 + 20 % 10, 0, 25 / 10 * 16 + 25 % 10, 12 / 10 * 16 + 12 % 10, 19 / 10 * 16 + 19 % 10, 0, 0, 0, 0, 0, 0, 0, 0};



    i2cRead_CMockExpect(75, 0, RTC_Address(), (uint8_t *)0, 0, 0, buffer, sizeof(buffer), 1);

    i2cRead_CMockReturnMemThruPtr_lectura(76, buffer, (int)(sizeof(buffer) * (int)sizeof(*buffer)));



    RTC_read_time_and_date(&date, &time, 0);



    UnityAssertEqualNumber((UNITY_INT)((19 / 10 * 16 + 19 % 10)), (UNITY_INT)((date.year)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((12 / 10 * 16 + 12 % 10)), (UNITY_INT)((date.month)), (

   ((void *)0)

   ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((25 / 10 * 16 + 25 % 10)), (UNITY_INT)((date.mday)), (

   ((void *)0)

   ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((20 / 10 * 16 + 20 % 10)), (UNITY_INT)((time.hour)), (

   ((void *)0)

   ), (UNITY_UINT)(83), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((19 / 10 * 16 + 19 % 10)), (UNITY_INT)((time.min)), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((00 / 10 * 16 + 00 % 10)), (UNITY_INT)((time.sec)), (

   ((void *)0)

   ), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);

}
