#include <tmp_control.h>
#include <tests.h>
const int period = 10000;
PWMConfig pwm1conf = {
    .frequency = 500000,
    .period = 10000,
    .callback = NULL,
    .channels = {
                 {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
                 {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL},
                 {.mode = PWM_OUTPUT_ACTIVE_HIGH,    .callback = NULL},// Channel 2 is working CH3 = PB0
                 {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL}
                 },
    .cr2 = 0,
    .dier = 0
};
void PWMcontrol(int duty_cycle)
{
    if(duty_cycle<0)
    {
        duty_cycle = 0;
    }
    else if(duty_cycle>100)
    {
        duty_cycle = 100;
    }
    duty_cycle = duty_cycle*period/100;
    palSetLineMode(PAL_LINE(GPIOB,0),PAL_MODE_ALTERNATE(2));
    pwmStart(&PWMD3,&pwm1conf);
    pwmEnableChannel(&PWMD3,2,duty_cycle);
}


