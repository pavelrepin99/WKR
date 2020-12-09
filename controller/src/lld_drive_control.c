#include <lld_drive_control.h>

#define T 10000
#define F 1000000

static bool init = false;
float steer_k_left = 0;
float steer_k_right = 0;
float steer_b = 0;
float motor_k_back = 0;
float motor_b = 0;
float motor_k_forward = 0;
PWMConfig pwm1conf = {
    .frequency = F,
    .period = T,
    .callback = NULL,
    .channels = {
                 {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},//PE9
                 {.mode = PWM_OUTPUT_ACTIVE_HIGH, .callback = NULL},//PE11
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
    palSetLineMode(PAL_LINE(GPIOE,11),PAL_MODE_ALTERNATE(1));
    palSetLineMode(PAL_LINE(GPIOE,9),PAL_MODE_ALTERNATE(1));
    pwmStart(&PWMD1,&pwm1conf);
    steer_k_left = (LEFT_STEERING_WHEEL-CENTER_STEERING_WHEEL)*(-0.01);
    steer_b = CENTER_STEERING_WHEEL;
    steer_k_right = (CENTER_STEERING_WHEEL-RIGHT_STEERING_WHEEL)*0.01;
    motor_k_back = (STOP_MOTOR - MAX_SPEED_BACK_MOTOR)*0.01;
    motor_b = STOP_MOTOR;
    motor_k_forward = (MAX_SPEED_FORWARD_MOTOR - STOP_MOTOR)*0.01;
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
        duty_cycle=duty_cycle*steer_k_left+steer_b;
    }
    else if(duty_cycle==0)
    {
        duty_cycle=steer_b;
    }
    else if(duty_cycle>0)
    {
        duty_cycle=steer_b-duty_cycle*steer_k_right;
    }
    lldControlSetSteerMotorRawPower(duty_cycle);

}
/**
 * @brief Set raw duty cycle for speed motor
 * @args duty_sycle is raw value
 */
void lldControlSetDrivingMotorRawPower(int32_t duty_cycle)
{
    duty_cycle=Check(duty_cycle,MAX_SPEED_BACK_MOTOR,MAX_SPEED_FORWARD_MOTOR);
    pwmEnableChannel(&PWMD1,0,duty_cycle);
}
/**
 * @brief Set duty cycle percentage for speed motor
 * @args duty_cycle is percentage value
 */
void lldControlSetDrivingMotorPower(int32_t duty_cycle)
{
    duty_cycle = Check(duty_cycle, MAX_BACK_MOTOR, MAX_FORWARD_MOTOR);
    if(duty_cycle<0)
    {
        duty_cycle=duty_cycle*motor_k_back+motor_b;
    }
    else if(duty_cycle==0)
    {
        duty_cycle=motor_b;
    }
    else if(duty_cycle>0)
    {
        duty_cycle = duty_cycle*motor_k_forward+motor_b;
    }
    lldControlSetDrivingMotorRawPower(duty_cycle);
}


