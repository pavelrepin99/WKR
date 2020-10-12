#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include <ch.h>
#include <hal.h>

#define PROGRAM_ROUTINE_TEST_LED1 0 /*palToggleLine*/
#define PROGRAM_ROUTINE_TEST_LED2 1 /*palSetLine*/
#define PROGRAM_ROUTINE_TEST_LED3 2 /*GPT*/
#define PROGRAM_ROUTINE_TEST_PORT3 3 /*PG3 and GPT*/
 
#define MAIN_PROGRAM_ROUTINE PROGRAM_ROUTINE_TEST_PORT3

#endif
