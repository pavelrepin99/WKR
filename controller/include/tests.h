#ifndef INCLUDE_TESTS_H
#define INCLUDE_TESTS_H

#include <common.h>

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
/**
 * @testing the encoder
 * @note variable of encoder displayed in Serial
 */
void testEncoderCommonRoutines(void);

/**
 * @brief test odometry to get distance
 * @note unit of CM
 */
void testRobotOdometryDistance(void);

/**
 * @brief test odometry to get speed of robot and speed of encoder
 */
void testRobotOdometrySpeed(void);

/**
 * @brief test odometry to get speed of robot and speed of encoder
 * @note press 's' call reset variables speed
 */
void testRobotOdometryReset(void);

/*
 * @brief Test get data from ADC and control servo
 * @note s - +20%
 *       d - -10%
 *       ' ' - 0%
 */
void testSteerAngle(void);

#endif
