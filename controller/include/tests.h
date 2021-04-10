#ifndef INCLUDE_TESTS_H
#define INCLUDE_TESTS_H

#include <common.h>

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
void testRobotOdometryCommonRoutines(void);

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
/**
 * @brief Test for steering wheel and speed motor
 * @note value raw duty cycle
 */
void testRawPowerWheelsRoutine(void);
/**
 * @brief Test for steering wheel and speed motor
 * @note value percentage
 */
void testPowerWheelsRoutine(void);
/**
 * @brief Test for check speed raw and filtered speed
 * @note data transmitted to matlab
 */
void testRobotOdometryFilterSpeed(void);

#endif

