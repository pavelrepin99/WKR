#include <common.h>
#include <tests.h>

static void searchtest(void);

int main(void)
{
    halInit();
    chSysInit();

    #if (MAIN_PROGRAM_ROUTINE != PROGRAM_ROUTINE_MASTER)
        searchtest();
    #endif
}

static void searchtest(void)
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
