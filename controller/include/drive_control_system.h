#ifndef INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_
#define INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_

#include <common.h>

typedef int16_t angleValue;
typedef float steerValue;
typedef struct
{
    steerValue kp;
    steerValue ki;
    steerValue integSaturation;
    steerValue propDeadZone;
}PIregulator_Steer ;

/**
 * @brief Initialization and create thread
 * @args priority
 */
void driveCSInit(tprio_t prio);

/**
 * @brief Get setting angle
 * @args angle (DEG)
 * @returns the angle [-25;25]
 */
angleValue RefAngle(int16_t angle);

/**
 * @brief Reset the values of PI regulator
 */
void ResetRegulator(void);

#endif
