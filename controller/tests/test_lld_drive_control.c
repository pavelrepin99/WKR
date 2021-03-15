#include <tests.h>
#include <lld_drive_control.h>
#include <debug.h>

#define speed_delta 200
#define steer_delta 200
#define speed_delta_pr 30
#define steer_delta_pr 30

/**
 * @brief Test for steering wheel and speed motor
 * @note value raw duty cycle
 */
void testRawPowerWheelsRoutine(void)
{
    int32_t speed_value = 0;
    int32_t steer_value = 0;
    char sym = 0;
    lldDriveControlInit();
    debug_stream_init();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
        switch(sym)
        {
            case 'a':
                speed_value += speed_delta;
                break;
            case 'd':
                speed_value -= speed_delta;
                break;
            case ' ':
                speed_value = STOP_MOTOR;
                steer_value = CENTER_STEERING_WHEEL;
                break;
            case 'q':
                steer_value += steer_delta;
                break;
            case 'e':
                steer_value -= steer_delta;
                break;
        }
        speed_value=Check(speed_value,MAX_SPEED_BACK_MOTOR,
                        MAX_SPEED_FORWARD_MOTOR);
        steer_value=Check(steer_value, RIGHT_STEERING_WHEEL,
                        LEFT_STEERING_WHEEL);
        lldControlSetDrivingMotorRawPower(speed_value);
        lldControlSetSteerMotorRawPower(steer_value);
        dbgprintf("Angle:%d Speed:%d \n\r",(int)steer_value,(int)speed_value);
        time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
    }
}

/**
 * @brief Test for steering wheel and speed motor
 * @note value percentage
 */
void testPowerWheelsRoutine(void)
{
    int32_t speed_value = 0;
    int32_t steer_value = 0;
    char sym = 0;
    lldDriveControlInit();
    debug_stream_init();
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
        switch(sym)
        {
            case 'a':
                speed_value += speed_delta_pr ;
                break;
            case 'd':
                speed_value -= speed_delta_pr ;
                break;
            case ' ':
                speed_value = 0;
                steer_value = 0;
                break;
            case 'q':
                steer_value += steer_delta_pr;
                break;
            case 'e':
                steer_value -= steer_delta_pr;
                break;
        }
        speed_value=Check(speed_value,MAX_BACK_MOTOR,
                                   MAX_FORWARD_MOTOR);
        steer_value=Check(steer_value, MIN_STEERING_WHEEL,
                                  MAX_STEERING_WHEEL);
        lldControlSetDrivingMotorPower(speed_value);
        lldControlSetSteerMotorPower(steer_value);
        dbgprintf("Angle:%d Speed:%d \n\r",(int)steer_value,(int)speed_value);
        time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
}
}
