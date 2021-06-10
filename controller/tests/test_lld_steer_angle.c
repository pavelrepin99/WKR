#include <tests.h>
#include <debug.h>
#include <lld_drive_control.h>
#include <lld_steer_angle.h>

#define INCREASE_ANGLE 15
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
    int16_t duty_cycle = 0;
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
                //duty_cycle = 0;
                duty_cycle = 1140; //center
                angle_servo = lldGetSteerAngle(unit);
                break;
            case 's':
                //duty_cycle += INCREASE_ANGLE;
                duty_cycle = 500; //right
                angle_servo = lldGetSteerAngle(unit);
                break;
            case 'd':
                //duty_cycle -= DECRISE_ANGLE;
                duty_cycle = 1650;//left
                angle_servo = lldGetSteerAngle(unit);
                break;
        }
//        duty_cycle = Check(duty_cycle,-46,33);
//        lldControlSetSteerMotorPower(duty_cycle);
        lldControlSetSteerMotorRawPower(duty_cycle); //test
        dbgprintf("Angle:%d input:%d\n\r",(int)angle_servo, duty_cycle);
        time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
    }
}
