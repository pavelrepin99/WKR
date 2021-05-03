#include <drive_control_system.h>
#include <lld_drive_control.h>
#include <lld_steer_angle.h>


#define MAX_ANGLE 25
#define MIN_ANGLE -25
/* 25 - 100%
 * 1  -  4%
 */
#define TICK 4
#define MAX_SPEED 0.2
#define MIN_SPEED -0.2
#define TICK_SPEED 5

bool driveInit = FALSE;
int16_t p_err = 0;
int16_t ref_angle = 0;
int16_t real_angle = 0;
int16_t intg = 0;
int16_t steer_control_val = 0;
int16_t ref_speed = 0;
int16_t speed_control_val = 0;
int16_t p_err_speed = 0;
int16_t intg_speed = 0;
int16_t real_speed = 0;

PIregulator pi = {
    .kp_steer = 0,
    .ki_steer = 0,
    .integSaturationSteer = 0,
    .propDeadZoneSteer = 0,
    .kp_motor = 0,
    .ki_motor = 0,
    .integSaturationMotor = 0,
    .propDeadZoneMotor = 0,
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
        if(abs(ref_angle - real_angle) > pi.propDeadZoneSteer)
            p_err = ref_angle - real_angle;
        else
        {
            p_err = 0;
            intg = 0;
        }
        intg += p_err * pi.ki_steer;
        intg = Check(intg,-pi.integSaturationSteer,pi.integSaturationSteer);
        steer_control_val = (pi.kp_steer*p_err + intg)*TICK;
        lldControlSetSteerMotorPower(steer_control_val);
        //Speed regulator
        if(abs(ref_speed - real_speed) > pi.propDeadZoneMotor)
            p_err_speed = ref_speed - real_speed;
        else
        {
            p_err_speed = 0;
            intg_speed = 0;
        }
        intg_speed += p_err_speed * pi.ki_motor;
        intg_speed = Check(intg_speed,-pi.integSaturationMotor,
                           pi.integSaturationMotor);
        speed_control_val = (pi.kp_motor*p_err_speed + intg_speed)*TICK_SPEED;
        lldControlSetDrivingMotorPower(speed_control_val);
        time = chThdSleepUntilWindowed(time, MS2ST(10)+time);
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
    chThdCreateStatic(regulator,sizeof(regulator),NORMALPRIO+prio,
                      CalculationReg, NULL);
    driveInit = TRUE;
}
/**
 * @brief Angle setting
 * @args angle (DEG)
 */
void setRefAngle(int16_t angle)
{
    ref_angle = Check(angle, MIN_ANGLE,MAX_ANGLE);
}

/**
 * @brief Reset the values of PI regulator
 */
void ResetRegulator(void)
{
    p_err = 0;
    intg = 0;
    steer_control_val = 0;
    ref_angle = 0;
    ref_speed = 0;
    speed_control_val = 0;
    intg_speed = 0;
    p_err_speed = 0;
}
/**
 * @brief Speed setting
 * @args speed (M_S)
 */
void setRefSpeed(float speed, mySpeedUnits units)
{
    speed = Check(speed,MIN_SPEED,MAX_SPEED);
    ref_speed = speed * units;
}

