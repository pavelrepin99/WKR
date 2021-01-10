#include <tests.h>
#include <debug.h>

/*
 * @brief Test work UART
 */
void testUart(void)
{   int32_t i=1;
    debug_stream_init();
    systime_t time = chVTGetSystemTime();
    while(i<=100)
    { 
        dbgprintf("I am the danger!, %d\n\r",i++);
        time = chThdSleepUntilWindowed (time, MS2ST(500)+time);
    }
}
