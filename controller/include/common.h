#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include <ch.h>
#include <hal.h>
#include <stdint.h>


#define PROGRAM_ROUTINE_MASTER 0
#define PROGRAM_ROUTINE_TEST_RAW_POWER_STEER 1
#define PROGRAM_ROUTINE_TEST_POWER_STEER 2
#define PROGRAM_ROUTINE_TEST_RAW_SPEED_MOTOR 3
#define PROGRAM_ROUTINE_TEST_SPEED_MOTOR 4
#define PROGRAM_ROUTINE_TEST_UART 5

#define MAIN_PROGRAM_ROUTINE 5

/**
 * @brief Overflow protection
 * @args duty_cycle is varible to be checked
 * @args low is minimum value
 * @args high is maximum value
 * @return duty_cycle
 */
int32_t Check(int32_t duty_cycle, int32_t low,int32_t high);

#endif
