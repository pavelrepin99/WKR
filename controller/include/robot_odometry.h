#ifndef INCLUDE_ROBOT_ODOMETRY_H_
#define INCLUDE_ROBOT_ODOMETRY_H_

#include <common.h>

typedef enum {MM = 1000, CM = 100, M = 1}myDistUnits;
typedef float coeffwheelshaft; //transmission ratio between wheel and shaft
typedef float distanceCrossWheel;

/**
 * @brief Get distance traveled by the robot
 * @args units(MM, CM, M)
 * @return distance
 */
distanceCrossWheel odometryGetRobotDistance(myDistUnits units);

#endif
