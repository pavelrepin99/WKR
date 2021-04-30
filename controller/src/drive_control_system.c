#include <drive_control_system.h>
#include <lld_drive_control.h>
#include <lld_steer_angle.h>

#define MAX_ANGLE 25
#define MIN_ANGLE -25
/* 25 - 100%
 * 1  -  4%
 */
#define RIGHT_TICK 4
#define LEFT_TICK -4

bool driveInit = FALSE;
int16_t p_err = 0;
int16_t ref_angle = 0;
int16_t real_angle = 0;
int16_t intg = 0;
int16_t intg_prev = 0;
int16_t steer_control_val = 0;

PIregulator pi = {
    .kp = 0,
    .ki = 0,
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
        if(abs(ref_angle - real_angle) > pi.propDeadZone)
            p_err = ref_angle - real_angle;
        else
        {
            p_err = 0;
            intg = 0;
        }
        intg += p_err * pi.ki;
        intg = Check(intg,-pi.integSaturation,pi.integSaturation);
        steer_control_val = pi.kp*p_err + intg;
        if(p_err < 0)
        {
            steer_control_val = steer_control_val * LEFT_TICK;
        }
        else if(p_err > 0)
        {
            steer_control_val = steer_control_val * RIGHT_TICK;
        }
        lldControlSetSteerMotorPower(steer_control_val);
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
    ref_angle = Check(angle, MAX_ANGLE, MIN_ANGLE);
}

/**
 * @brief Reset the values of PI regulator
 */
void ResetRegulator(void)
{
    p_err = 0;
    intg = 0;
    steer_control_val = 0;
    intg_prev = 0;
    ref_angle = 0;
}

