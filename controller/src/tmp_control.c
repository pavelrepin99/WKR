#include <tmp_control.h>
#include <tests.h>

GPTConfig gpt3conf = {
        .frequency    = 10000,
        .callback     = NULL,
        .cr2          = 0,
        .dier         = 0
    };
void GPTcontrol(void)
{
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

void led1control(void)
{
    while (true)
        {
           palToggleLine(LINE_LED1);
           chThdSleepSeconds(5);
        }
}

void led2control(void)
{
    while (true)
        {
           palSetLine(LINE_LED1);
        }
}

void PG3control(void)
{
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


