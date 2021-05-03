#ifndef INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_
#define INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_

#include <common.h>
#include <robot_odometry.h>

typedef float regulatorValue;

typedef struct
{
    regulatorValue kp_steer;
    regulatorValue ki_steer;
    regulatorValue integSaturationSteer;
    regulatorValue propDeadZoneSteer;
    regulatorValue kp_motor;
    regulatorValue ki_motor;
    regulatorValue integSaturationMotor;
    regulatorValue propDeadZoneMotor;
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
void setRefAngle(int16_t angle);

/**
 * @brief Reset the values of PI regulator
 */
void ResetRegulator(void);
/**
 * @brief Speed setting
 * @args speed (M_S)
 */
void setRefSpeed(float speed, mySpeedUnits units);

#endif
