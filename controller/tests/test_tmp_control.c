#include <tests.h>
#include <tmp_control.h>

void testLED1(void)
{
   led1_control();
}

void testLED2(void)
{
  led2_control();
}

void testGPT(void)
{
    GPT_control();
} 

void testPG3(void)
{
    PG3_control();
}