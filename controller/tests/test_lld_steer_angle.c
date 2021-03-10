#include <tests.h>
#include <debug.h>
#include <lld_drive_control.h>
#include <lld_steer_angle.h>

/*
 * @brief Test get data from ADC and control servo
 * @note s - +20%
 *       d - -10%
 *       ' ' - 0%
 */
void testSteerAngle(void)
{
    float angle_servo = 0;
    float duty_cycle = 0;
    char sym = 0;
    debug_stream_init();
    lldSteerAngleInit();
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
        if(sym == ' ')
        {
            angle_servo = 0;
        }
        else
        {
            if(sym == 's')
            {
                duty_cycle += 20;
                lldControlSetSteerMotorPower(duty_cycle);
            }
            else if(sym == 'd')
            {
                duty_cycle -= 10;
                lldControlSetSteerMotorPower(duty_cycle);
            }
            angle_servo = lldGetSteerAngle(RAD);
        }
        dbgprintf("Angle:%d \n\r",(int)angle_servo);
        time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
    }
}
