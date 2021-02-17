#include <robot_odometry.h>
#include <lld_encoder.h>

coeffwheelshaft Kws = 2 * M_PI * Wheel_Radius * k;
distanceCrossWheel distance;

/**
 * @brief Get distance traveled by the robot
 * @args units(MM, CM, M)
 * @return distance
 */
distanceCrossWheel odometryGetRobotDistance(myDistUnits units)
{
    rev_count_enc rev_count = lldGetEncoderRawRevs();
    return rev_count * Kws * units;
}
