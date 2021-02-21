#include <robot_odometry.h>
#include <lld_encoder.h>

static virtual_timer_t speed_t;
coeffwheelshaft Kws = 2 * M_PI * Wheel_Radius * k;
distanceCrossWheel distance;
static bool init_tim = 0;
speedOdometry speed = 0;
speedEncoder speed_enc;
float turn = 0;
float prev_turn = 0;
float dist = 0;
float prev_dist = 0;

/**
 * @brief handler interrupt of virtual timer
 */
static void tim_s(void *arg)
{
    (void)arg;
    dist = odometryGetRobotDistance(CM)*0.001;
    speed = (dist - prev_dist)*0.001;
    prev_dist = dist;
    turn = lldGetEncoderRawRevs();
    speed_enc = (turn - prev_turn)*0.001;
    prev_turn = turn;
    chVTSetI(&speed_t, MS2ST(10), tim_s, NULL);
}

/**
 * @brief Initialization virtual timer
 * @note period 10ms
 */
void odometryInit(void)
{
    if(init_tim)
        return;
    chVTObjectInit(&speed_t);
    chVTSet(&speed_t, MS2ST(10), tim_s, NULL);
    init_tim = true;
}

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

/**
 * @brief Get speed of robot
 * @args units(MM_S, CM_S, M_S)
 * @return speed of robot
 */
speedOdometry odometryGetRobotSpeed(mySpeedUnits units)
{
    return speed*units;
}

/**
 * @brief Get speed of encoder
 * @args units revolutions per second
 * @return speed of encoder
 */
speedEncoder odometryGetEncoderSpeed(void)
{
    return speed_enc;
}

/**
 * @brief Reset the value of variables
 * @note variables: speed of robot, speed of encoder
 */
void odometryReset(void)
{
    speed = 0;
    speed_enc = 0;
    turn = 0;
    prev_turn = 0;
}
