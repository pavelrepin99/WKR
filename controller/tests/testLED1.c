#include <common.h>
void testLED1(void)
{
    while (true)
        {
           palToggleLine(LINE_LED1);
           chThdSleepSeconds(5);
        }
}


