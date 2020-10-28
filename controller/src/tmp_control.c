#include <tmp_control.h>
#include <tests.h>
#define T 10000
#define F 500000
PWMConfig pwm1conf = {
    .frequency = F,
    .period = T,
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
void Init(void)
{
    palSetLineMode(PAL_LINE(GPIOB,0),PAL_MODE_ALTERNATE(2));
    pwmStart(&PWMD3,&pwm1conf);
}
int32_t Check(int32_t duty_cycle, int8_t low,int8_t high)
{
    if(duty_cycle<low)
    {
        duty_cycle = low;
    }
    else if(duty_cycle>=high)
    {
        duty_cycle = high;
    }
    return duty_cycle;
}

void PWMcontrol(int32_t duty_cycle)
{
    duty_cycle = Check(duty_cycle,0,100);
    duty_cycle = duty_cycle*T/100;
    pwmEnableChannel(&PWMD3,2,duty_cycle);
}



