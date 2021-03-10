#ifndef INCLUDE_LLD_STEER_ANGLE_H_
#define INCLUDE_LLD_STEER_ANGLE_H_

#include <common.h>

typedef float buff;
typedef float filterAdc;
typedef float angle_adc;
typedef enum{TICKS = 1, DEG = 28, RAD = 4886}angle_units;
#define CENTER_STEER 1350
#define RIGHT_STEER 970
#define LEFT_STEER 1780

/**
 * @brief Initialization ADC, GPT
 * @note variable InitSteer for protection
 */
void lldSteerAngleInit(void);

/**
 * @brief Get angle of rotation of the servo
 * @args unit (TICKS,DEG,RAD)
 * @returns the angle in the units
 */
angle_adc lldGetSteerAngle(angle_units unit);

#endif
