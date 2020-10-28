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
#if (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_PWM)
    testPWM();
#endif
}
