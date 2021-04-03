#include <tests.h>
#include <robot_odometry.h>
#include <debug.h>
#include <lld_encoder.h>
#include <lld_drive_control.h>

#define speed_delta_pr 30
/**
 * @brief test odometry to get distance
 * @note unit of CM
 */
void testRobotOdometryDistance(void)
{
    int32_t dist = 0;
    int32_t speed_value = 0;
    debug_stream_init();
    lldEncoderInit();
    lldDriveControlInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
       char sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
       switch(sym)
       {
           case 'a':
               speed_value += speed_delta_pr;
               break;
           case 'd':
               speed_value -= speed_delta_pr;
               break;
           case ' ':
               speed_value = 0;
               break;
           default: ;
        }
        speed_value=Check(speed_value,MAX_BACK_MOTOR,
                                           MAX_FORWARD_MOTOR);
        lldControlSetDrivingMotorPower(speed_value);
        dist = odometryGetRobotDistance(CM);
        dbgprintf("Distance:%d \n\r",dist);
        time = chThdSleepUntilWindowed (time, MS2ST(200)+time);
    }
}
