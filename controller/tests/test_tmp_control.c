#include <tests.h>
#include <tmp_control.h>

void testLED1(void)
{
   led1control();
}

void testLED2(void)
{
  led2control();
}

void testGPT(void)
{
    GPTcontrol();
} 

void testPG3(void)
{
    PG3control();
}