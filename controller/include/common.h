#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include <ch.h>
#include <hal.h>

#define PROGRAM_ROUTINE_MASTER 0
#define PROGRAM_ROUTINE_TEST_LED1 1 /*palToggleLine*/
#define PROGRAM_ROUTINE_TEST_LED2 2 /*palSetLine*/
#define PROGRAM_ROUTINE_TEST_LED3 3 /*GPT*/
#define PROGRAM_ROUTINE_TEST_PORT3 4 /*PG3 and GPT*/
 
#define MAIN_PROGRAM_ROUTINE PROGRAM_ROUTINE_TEST_LED2

#endif
