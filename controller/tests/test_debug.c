#include <test_debug.h>
#include <debug.h>

/*
 * @brief Test work UART
 */
void testUart(void)
{   int32_t i;
    debug_stream_init();
    systime_t time = chVTGetSystemTime();
    while(1)
    {   for(i=1; i<=100; i++)
        {
            dbgprintf("I am the danger!, %d\n\r",i);
            time = chThdSleepUntilWindowed (time, MS2ST(500)+time);
        }
        i=1;
        time = chThdSleepUntilWindowed (time, MS2ST(500)+time);
    }
}
