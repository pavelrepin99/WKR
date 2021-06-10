#include <drive_control_system.h>
#include <lld_drive_control.h>
#include <lld_steer_angle.h>
#include <debug.h>

/* 25 - 100%
 * 1  -  4%
 */
#define TICK_ANGLE 4
#define MAX_SPEED (float)0.2
#define MIN_SPEED (float)-0.2
#define TICK_SPEED 5

bool driveInit = FALSE;
int16_t p_err = 0;
int8_t ref_angle = 0;
int16_t real_angle = 0;
float intg = 0;
int16_t steer_control_val = 0;
float ref_speed = 0;
int16_t speed_control_val = 0;
float p_err_speed = 0;
float intg_speed = 0;
float real_speed = 0;
float prev_ref_speed = 0;

PIregulator steerPI = {
    .kp = 0,
    .ki = 0.06,
    .integSaturation = 0,
    .propDeadZone = 0,
};

PIregulator motorPI = {
    .kp = 0.3,
    .ki = 0.02,
    .integSaturation = 0,
    .propDeadZone = 0,
};
PIregulator motorRevs = {
    .kp = 0.3,
    .ki = 0.02,
    .integSaturation = 0,
    .propDeadZone = 0,
};

static THD_WORKING_AREA(regulator,256);
static THD_FUNCTION(CalculationReg,arg)
{
    (void*)arg;
    systime_t time = chVTGetSystemTimeX();
    while(1)
    {
        real_angle = lldGetSteerAngle(DEG);
        real_speed = odometryGetRobotSpeed(CM_S);
        //angle_regulator
        p_err = ref_angle - real_angle;
        intg += p_err * steerPI.ki;
        steer_control_val = (steerPI.kp*p_err + intg)*TICK_ANGLE;
        lldControlSetSteerMotorPower(steer_control_val);

        //Speed regulator
        p_err_speed = ref_speed - real_speed;
        if(ref_speed < 0)
        {
            intg_speed += p_err_speed * motorRevs.ki;
            speed_control_val=(motorRevs.kp*p_err_speed+intg_speed)*TICK_SPEED;
        }
        else if(ref_speed > 0)
        {
            intg_speed += p_err_speed * motorPI.ki;
            speed_control_val = (motorPI.kp*p_err_speed + intg_speed)
                    *TICK_SPEED;
        }
        else if(ref_speed == 0)
        {
            if(abs(ref_speed - real_speed) > 5)
            {
                if(real_speed > 0)
                {
                    speed_control_val = -5;
                }
                else
                {
                    speed_control_val = 5;
                }
             }
             else
             {
                 ResetSpeedRegulator();
                 speed_control_val = 0;
             }
        }
       lldControlSetDrivingMotorPower(speed_control_val);
       time = chThdSleepUntilWindowed(time, MS2ST(20)+time);
    }
}
/**
 * @brief Initialization and create thread
 * @args priority
 */
void driveCSInit(uint8_t prio)
{
    if(driveInit)
        return;
    lldDriveControlInit();
    lldSteerAngleInit();
    odometryInit();
    debug_stream_init();
    chThdCreateStatic(regulator,sizeof(regulator),NORMALPRIO+prio,
                      CalculationReg, NULL);
    driveInit = TRUE;
}
/**
 * @brief Angle setting
 * @args angle (DEG)
 */
void setRefAngle(int8_t angle)
{
    ref_angle = Check(angle, MIN_ANGLE,MAX_ANGLE);
}
/**
 * @brief Reset the values of PI regulator(motor)
 */
void ResetSpeedRegulator(void)
{
    ref_speed = 0;
    speed_control_val = 0;
    intg_speed = 0;
    p_err_speed = 0;
}
/**
 * @brief Reset the values of I regulator(servo)
 */
void ResetSteerRegulator(void)
{
    p_err = 0;
    intg = 0;
    steer_control_val = 0;
    ref_angle = 0;
}
/**
 * @brief Speed setting
 * @args speed (M_S)
 */
void setRefSpeed(float speed, mySpeedUnits units)
{
    if(units!=M_S)
        speed = Check_speed(speed,MIN_SPEED,MAX_SPEED);
    ref_speed = speed * units;
}

