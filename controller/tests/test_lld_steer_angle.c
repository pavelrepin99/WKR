#include <tests.h>
#include <debug.h>
#include <lld_drive_control.h>
#include <lld_steer_angle.h>

#define INCREASE_ANGLE 20
#define DECRISE_ANGLE 10

int unit = DEG;

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
        switch(sym)
        {
            case ' ':
                angle_servo = 0;
                duty_cycle = 0;
                break;
            case 's':
                duty_cycle += INCREASE_ANGLE;
                angle_servo = lldGetSteerAngle(unit);
                break;
            case 'd':
                duty_cycle -= DECRISE_ANGLE;
                angle_servo = lldGetSteerAngle(unit);
                break;
        }
        lldControlSetSteerMotorPower(duty_cycle);
        dbgprintf("Angle:%d \n\r",(int)angle_servo);
        time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
    }
}
