#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include <ch.h>
#include <hal.h>

#define LED1 1 /*palToggleLine*/
#define LED2 2 /*palSetLine*/
#define LED3 3 /*GPT*/
#define PORT3 4 /*PG3 and GPT*/
 
#define MAIN_CHECK 1

void testLED1(void);
void testLED2(void);
void testGPT(void);
void testPORT(void);

#endif
