#ifndef INCLUDE_TMP_CONTROL_H_
#define INCLUDE_TMP_CONTROL_H_

/*------------------------------------------*/
/* Low level driver                     */
/*-----------------------------------------*/

#include <common.h>

#define CENTER_STEERING_WHEEL 1140
#define RIGHT_STEERING_WHEEL 500
#define LEFT_STEERING_WHEEL 1650
#define MIN_STEERING_WHEEL -100
#define MAX_STEERING_WHEEL 100

/**
 * @brief Initialization PWM and pin
 * @note variable init for protection
 */
void lldDriveControlInit(void);

/**
 * @brief Set raw duty cycle for servo
 * @args duty_sycle is raw value
 */
void lldControlSetSteerMotorRawPower(int32_t duty_cycle);

/**
 * @brief Set duty cycle percentage for servo
 * @args duty_cycle is percentage value
 */
void lldControlSetSteerMotorPower(int32_t duty_cycle);
#endif
