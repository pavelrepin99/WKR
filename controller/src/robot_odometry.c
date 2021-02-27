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
float previous_filtered_speed_lpf = 0; 
float current_speed = 0;
float filtered_speed = 0;
#define VTIME_PERIOD_MS 10
#define MS_TO_SEC 100
#define FILTER 1
#define K 0.5

/**
 * @brief handler interrupt of virtual timer
 */
static void tim_s(void *arg)
{
    (void)arg;
    dist = odometryGetRobotDistance(CM)/CM;
    current_speed = (dist - prev_dist)*MS_TO_SEC;
    prev_dist = dist;
    #ifdef FILTER
        filtered_speed = current_speed * (1-K) + previous_filtered_speed_lpf * K;
        previous_filtered_speed_lpf = filtered_speed;
        current_speed = filtered_speed;
    #endif
    speed = current_speed;
    turn = lldGetEncoderRawRevs();
    speed_enc = (turn - prev_turn)*MS_TO_SEC;
    prev_turn = turn;
    chSysLockFromISR();
    chVTSetI(&speed_t, MS2ST(VTIME_PERIOD_MS), tim_s, NULL);
    chSysUnlockFromISR();
}

/**
 * @brief Initialization virtual timer
 * @note period 10ms
 */
void odometryInit(void)
{
    if(init_tim)
        return;
    lldEncoderInit();
    chVTObjectInit(&speed_t);
    chVTSet(&speed_t, MS2ST(VTIME_PERIOD_MS), tim_s, NULL);
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
