#include <tests.h>
#include <lld_drive_control.h>

/**
 * @brief Test for raw duty cycle
 */
void testRawPower(void)
{
    int32_t a;
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        for(a=1650; a>=500; a-=200)
        {
            lldControlSetSteerMotorRawPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
         }
        a=1650;
     }
}
/**
 * @brief Test for duty cycle percentage
 */
void testPower(void)
{
    int32_t a;
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        for(a=-100; a<=100;a+=30)
        {
            lldControlSetSteerMotorPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        a=-100;
    }
}
