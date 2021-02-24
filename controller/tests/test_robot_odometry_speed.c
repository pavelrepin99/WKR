#include <tests.h>
#include <robot_odometry.h>
#include <debug.h>
#include <lld_encoder.h>

/**
 * @brief test odometry to get speed of robot and speed of encoder
 */
void testRobotOdometrySpeed(void)
{
    float speed_robot = 0;
    float speed_enc = 0;
    debug_stream_init();
    systime_t time = chVTGetSystemTime();
    odometryInit();
    while(1)
    {
        speed_robot = odometryGetRobotSpeed(CM_S);
        speed_enc = odometryGetEncoderSpeed();
        dbgprintf("Speed_enc:%d Speed_robot:%d \n\r",
                  (int)speed_enc,(int)speed_robot);
        time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
    }
}

/**
 * @brief test odometry to get speed of robot and speed of encoder
 * @note press 's' call reset variables speed
 */
void testRobotOdometryReset(void)
{
    float speed_robot = 0;
    float speed_enc = 0;
    char sym = 0;
    debug_stream_init();
    odometryInit();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        sym = sdGetTimeout(&SD3, US2ST(1));
        if(sym == 's')
        {
            odometryReset();
        }
        speed_robot = odometryGetRobotSpeed(CM_S);
        speed_enc = odometryGetEncoderSpeed();
        dbgprintf("Speed_enc:%d Speed_robot:%d \n\r",
                  (int)speed_enc,(int)speed_robot);
        time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
    }
}
