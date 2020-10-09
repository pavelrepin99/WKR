#include <common.h>

void testPORT(void)
{
    halInit();
    chSysInit();
    GPTConfig gpt3conf = {
            .frequency    = 10000,
            .callback     = NULL,
            .cr2          = 0,
            .dier         = 0
    };
    GPTDriver *delayDriver =&GPTD3;
    gptStart(delayDriver, &gpt3conf);
    palSetPadMode(GPIOG,3,PAL_MODE_OUTPUT_PUSHPULL);
        while(true)
        {
            palSetPad(GPIOG,3);
            gptPolledDelay(delayDriver, gpt3conf.frequency*5);
            palClearPad(GPIOG,3);
            gptPolledDelay(delayDriver, gpt3conf.frequency*5);
        }
}
