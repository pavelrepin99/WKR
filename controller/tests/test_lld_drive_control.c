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
/*
 * @brief Test for speed motor raw duty cycle
 */
void testRawPowerSpeedMotor(void)
{
    int32_t a;
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        for(a=STOP_MOTOR; a<=MAX_SPEED_FORWARD_MOTOR; a+=200)
        {
            lldControlSetDrivingMotorRawPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        for(a=MAX_SPEED_FORWARD_MOTOR; a>=STOP_MOTOR; a-=200)
        {
            a=Check(a,STOP_MOTOR,MAX_SPEED_FORWARD_MOTOR);
            lldControlSetDrivingMotorRawPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        for(a=STOP_MOTOR; a>=MAX_SPEED_BACK_MOTOR; a-=200)
        {
            lldControlSetDrivingMotorRawPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        for(a=MAX_SPEED_BACK_MOTOR; a<=STOP_MOTOR; a+=200)
        {
            a=Check(a,MAX_SPEED_BACK_MOTOR,STOP_MOTOR);
            lldControlSetDrivingMotorRawPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        a=STOP_MOTOR;
    }
}
/*
 * @brief Test for speed motor duty cycle percentage
 */
void testPowerSpeedMotor(void)
{
    int32_t a;
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        for(a=0; a<=MAX_FORWARD_MOTOR; a+=30)
        {
            lldControlSetDrivingMotorPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        for(a=MAX_FORWARD_MOTOR; a>=0; a-=30)
        {
            lldControlSetDrivingMotorPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        for(a=0; a>=MAX_BACK_MOTOR; a-=30)
        {
            lldControlSetDrivingMotorPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        for(a=MAX_BACK_MOTOR; a<=0; a+=30)
        {
            lldControlSetDrivingMotorPower(a);
            time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        }
        time = chThdSleepUntilWindowed (time, S2ST(2)+time);
        a=0;
    }
}
