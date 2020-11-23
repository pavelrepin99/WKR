#include <tests.h>
#include <lld_drive_control.h>

/*
 * @brief Test for steering wheel raw duty cycle
 */
void testRawPowerSteeringWheel(void)
{
    int32_t a;
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        for(a=LEFT_STEERING_WHEEL; a>=RIGHT_STEERING_WHEEL; a-=200)
        {
            lldControlSetSteerMotorRawPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
         }
        a=LEFT_STEERING_WHEEL;
        time = chThdSleepUntilWindowed (time, S2ST(2)+time);
     }
}
/*
 * @brief Test for steering wheel duty cycle percentage
 */
void testPowerSteeringWheel(void)
{
    int32_t a;
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {

        for(a=MIN_STEERING_WHEEL; a<=MAX_STEERING_WHEEL;a+=30)
        {
            lldControlSetSteerMotorPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        a=MIN_STEERING_WHEEL;
        time = chThdSleepUntilWindowed (time, S2ST(2)+time);
    }
}
