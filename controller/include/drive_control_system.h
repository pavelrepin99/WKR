#ifndef INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_
#define INCLUDE_TMP_DRIVE_CONTROL_SYSTEM_H_

#include <common.h>

typedef float steerValue;
typedef struct
{
    steerValue kp;
    steerValue ki;
    steerValue integSaturation;
    steerValue propDeadZone;
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

#endif
