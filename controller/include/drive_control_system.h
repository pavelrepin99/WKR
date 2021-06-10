#ifndef INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_
#define INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_

#include <common.h>
#include <robot_odometry.h>

#define MAX_ANGLE 25
#define MIN_ANGLE -25

typedef float regulatorValue;
typedef float regIntgr;

typedef struct
{
    regulatorValue kp;
    regulatorValue ki;
    regulatorValue integSaturation;
    regulatorValue propDeadZone;
}PIregulator;

/**
 * @brief Initialization and create thread
 * @args priority
 */
void driveCSInit(uint8_t prio);

/**
 * @brief Angle setting
 * @args angle (DEG)
 */
void setRefAngle(int8_t angle);

/**
 * @brief Reset the values of PI regulator(motor)
 */
void ResetSpeedRegulator(void);

/**
 * @brief Reset the values of I regulator(servo)
 */
void ResetSteerRegulator(void);

/**
 * @brief Speed setting
 * @args speed (M_S)
 */
void setRefSpeed(float speed, mySpeedUnits units);

#endif
