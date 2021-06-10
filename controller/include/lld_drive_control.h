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
#define STOP_MOTOR 1500
#define MAX_SPEED_FORWARD_MOTOR 1650
#define MAX_SPEED_BACK_MOTOR 1350
#define MAX_BACK_MOTOR -100
#define MAX_FORWARD_MOTOR 100

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

/**
 * @brief Set raw duty cycle for speed motor
 * @args duty_sycle is raw value
 */
void lldControlSetDrivingMotorRawPower(int32_t duty_cycle);

/**
 * @brief Set duty cycle percentage for speed motor
 * @args duty_cycle is percentage value
 */
void lldControlSetDrivingMotorPower(int32_t duty_cycle);

float getIntg(void);

#endif
