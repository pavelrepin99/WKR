#include <tests.h>
#include <robot_odometry.h>
#include <debug.h>
#include <lld_encoder.h>

/**
 * @brief test odometry to get distance
 * @note unit of CM
 */
void testRobotOdometryDistance(void)
{
    int32_t dist = 0;
    debug_stream_init();
    systime_t time = chVTGetSystemTime();
    lldEncoderInit();
    while(1)
    {
        dist = odometryGetRobotDistance(CM);
        dbgprintf("Distance:%d \n\r",dist);
        time = chThdSleepUntilWindowed (time, MS2ST(200)+time);
    }
}
