#include <common.h>

void search_test(void);

int main(void)
{
    halInit();
    chSysInit();
    search_test();
}

void search_test(void)
{
#if (MAIN_CHECK == LED1)
    testLED1();
#elif (MAIN_CHECK == LED2)
    testLED2();
#elif (MAIN_CHECK == LED3)
    testGPT();
#elif (MAIN_CHECK == PORT3)
    testPORT();
#endif
}
