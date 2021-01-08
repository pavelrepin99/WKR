#include <common.h>

#ifndef INCLUDE_TESTS_H
#define INCLUDE_TESTS_H
/*------------------------------------------*/
/* Test drive control                      */
/*-----------------------------------------*/

/*
 * @brief Test for steering wheel raw duty cycle
 */
void testRawPowerSteeringWheel(void);

/*
 * @brief Test for steering wheel duty cycle percentage
 */
void testPowerSteeringWheel(void);

/*
 * @brief Test for speed motor raw duty cycle
 */
void testRawPowerSpeedMotor(void);

/*
 * @brief Test for speed motor duty cycle percentage
 */
void testPowerSpeedMotor(void);
/*
 * @brief Test work UART
 */
void testUart(void);
#endif
