#include <lld_drive_control.h>

#define T 10000
#define F 1000000
#define DIFF_LEFT_SW LEFT_STEERING_WHEEL-CENTER_STEERING_WHEEL
#define DIFF_RIGHT_SW CENTER_STEERING_WHEEL-RIGHT_STEERING_WHEEL

static bool init = false;

PWMConfig pwm1conf = {
    .frequency = F,
    .period = T,
    .callback = NULL,
    .channels = {
                 {.mode = PWM_OUTPUT_DISABLED, .callback = NULL},
                 {.mode = PWM_OUTPUT_ACTIVE_HIGH,    .callback = NULL},
                 {.mode = PWM_OUTPUT_DISABLED,    .callback = NULL},
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
    if(init)
    return;
    {
        palSetLineMode(PAL_LINE(GPIOE,11),PAL_MODE_ALTERNATE(1));
        pwmStart(&PWMD1,&pwm1conf);
    }
    init = true;
}

/**
 * @brief Set raw duty cycle for servo
 * @args duty_sycle is raw value
 */
void lldControlSetSteerMotorRawPower(int32_t duty_cycle)
{
    duty_cycle = Check(duty_cycle, RIGHT_STEERING_WHEEL, LEFT_STEERING_WHEEL);
    pwmEnableChannel(&PWMD1,1,duty_cycle);
}
/**
 * @brief Set duty cycle percentage for servo
 * @args duty_cycle is percentage value
 */
void lldControlSetSteerMotorPower(int32_t duty_cycle)
{
    duty_cycle = Check(duty_cycle, MIN_STEERING_WHEEL, MAX_STEERING_WHEEL);
    if(duty_cycle<0)
    {
        duty_cycle=(duty_cycle*(DIFF_LEFT_SW )*(-0.01)+CENTER_STEERING_WHEEL);
    }
    else if(duty_cycle==0)
    {
        duty_cycle=CENTER_STEERING_WHEEL;
    }
    else if(duty_cycle>0)
    {
        duty_cycle=CENTER_STEERING_WHEEL-duty_cycle*(DIFF_RIGHT_SW)*0.01;
    }
    lldControlSetSteerMotorRawPower(duty_cycle);

}




