#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H

#include <ch.h>
#include <hal.h>

#define LED1 1 /*����� ��������� LINE_LED1*/
#define LED2 2 /*���������� ����� LINE_LED1*/
#define LED3 3 /*������ GPT*/
#define PORT3 4 /*�������� �����*/
 
#define MAIN_CHECK 1

void testLED1(void);
void testLED2(void);
void testGPT(void);
void testPORT(void);

#endif
