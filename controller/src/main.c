#include <common.h>
#include <tests.h>

static void search_test(void);

int main(void)
{
    halInit();
    chSysInit();
    search_test();
}

static void search_test(void)
{
#if (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_LED1)
    testLED1();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_LED2)
    testLED2();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_LED3)
    testGPT();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_PORT3)
    testPG3();
#endif
}
