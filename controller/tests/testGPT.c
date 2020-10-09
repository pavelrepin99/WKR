#include <common.h>

void testGPT(void)
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
    
    while(true)
    {
        palSetLine(LINE_LED1);
        gptPolledDelay(delayDriver, gpt3conf.frequency*5);
        palClearLine(LINE_LED1);
        gptPolledDelay(delayDriver, gpt3conf.frequency*5);
    }
}
