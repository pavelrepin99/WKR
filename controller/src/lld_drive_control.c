#include <lld_drive_control.h>
#include <tests.h>
#define T 10000
#define F 1000000
#define CENTER 1140
#define RIGHT 500
#define LEFT 1650

bool init = false;
PWMConfig pwm1conf = {
    .frequency = F,
    .period = T,
    .callback = NULL,
    .channels = {
                 {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
                 {.mode = PWM_OUTPUT_ACTIVE_HIGH,    .callback = NULL},
                 {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL},// Channel 2 is working CH3 = PB0
                 {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL}
                 },
    .cr2 = 0,
    .dier = 0
};
/**
 * @brief Initialization PWM and pin
 * @note variable init for protection
 */
void lldDriveControlInit(void)
{
    if(init == false)
    {
        palSetLineMode(PAL_LINE(GPIOE,11),PAL_MODE_ALTERNATE(1));
        pwmStart(&PWMD1,&pwm1conf);
    }
    init = true;
}
/**
 * @brief Overflow protection
 */
int32_t Check(int32_t duty_cycle, int32_t low,int32_t high)
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
/**
 * @brief Set raw duty cycle for servo
 */
void lldControlSetSteerMotorRawPower(int32_t duty_cycle)
{
    duty_cycle = Check(duty_cycle, RIGHT, LEFT);
    pwmEnableChannel(&PWMD1,1,duty_cycle);
}
/**
 * @brief Set duty cycle percentage for servo
 */
void lldControlSetSteerMotorPower(int32_t duty_cycle)
{
    duty_cycle = Check(duty_cycle, -100, 100);
    if(duty_cycle<0)
    {
        duty_cycle=(duty_cycle*(LEFT-CENTER)/(-100)+CENTER);
        duty_cycle=Check(duty_cycle,CENTER, LEFT);
    }
    else if(duty_cycle==0)
    {
        duty_cycle=CENTER;
    }
    else if(duty_cycle>0)
    {
        duty_cycle=CENTER-duty_cycle*RIGHT/100;
        duty_cycle=Check(duty_cycle,RIGHT,CENTER);
    }
    lldControlSetSteerMotorRawPower(duty_cycle);

}




