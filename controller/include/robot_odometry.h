#ifndef INCLUDE_ROBOT_ODOMETRY_H_
#define INCLUDE_ROBOT_ODOMETRY_H_

#include <common.h>

typedef enum {MM = 1000, CM = 100, M = 1}myDistUnits;
typedef float coeffwheelshaft; //transmission ratio between wheel and shaft
typedef float distanceCrossWheel;
typedef float speedOdometry;
typedef float speedEncoder;
typedef enum {MM_S = 1000, CM_S = 100, M_S = 1}mySpeedUnits;

/**
 * @brief Get distance traveled by the robot
 * @args units(MM, CM, M)
 * @return distance
 */
distanceCrossWheel odometryGetRobotDistance(myDistUnits units);

/**
 * @brief Initialization virtual timer
 * @note period 10ms
 */
void odometryInit(void);

/**
 * @brief Get speed of robot
 * @args units(MM_S, CM_S, M_S)
 * @return speed of robot
 */
speedOdometry odometryGetRobotSpeed(mySpeedUnits units);

/**
 * @brief Get speed of encoder
 * @args units revolutions per second
 * @return speed of encoder
 */
speedEncoder odometryGetEncoderSpeed(void);

/**
 * @brief Reset the value of variables
 * @note variables: speed of robot, speed of encoder
 */
void odometryReset(void);

speedOdometry odometryGetRobotSpeedNoFilter(mySpeedUnits units);

#endif
