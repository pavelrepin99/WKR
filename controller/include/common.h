#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#define _USE_MATH_DEFINES
#include <ch.h>
#include <hal.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PROGRAM_ROUTINE_MASTER 0
#define PROGRAM_ROUTINE_TEST_RAW_POWER_WHEELS_ROUTINES 1
#define PROGRAM_ROUTINE_TEST_POWER_WHEELS_ROUTINES 2
#define PROGRAM_ROUTINE_TEST_UART 3
#define PROGRAM_ROUTINE_TEST_ENCODER 4
#define PROGRAM_ROUTINE_ROBOT_ODOMETRY 5
#define PROGRAM_ROUTINE_ROBOT_ODOMETRY_SPEED 6
#define PROGRAM_ROUTINE_TEST_STEER_ANGLE 7
#define PROGRAM_ROUTINE_TEST_SPEED_FILTER 8

#define MAIN_PROGRAM_ROUTINE 5

#define Wheel_Radius 0.04
#define k 0.105

/**
 * @brief Overflow protection
 * @args duty_cycle is varible to be checked
 * @args low is minimum value
 * @args high is maximum value
 * @return duty_cycle
 */
int32_t Check(int32_t duty_cycle, int32_t low,int32_t high);

#endif
