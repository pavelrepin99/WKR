#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include <ch.h>
#include <hal.h>

#define LED1 1 /*смена состояния LINE_LED1*/
#define LED2 2 /*непрерывно горит LINE_LED1*/
#define LED3 3 /*таймер GPT*/
#define PORT3 4 /*цифровой выход*/
 
#define MAIN_CHECK 1

void testLED1(void);
void testLED2(void);
void testGPT(void);
void testPORT(void);

#endif
