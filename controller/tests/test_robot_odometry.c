#include <tests.h>
#include <robot_odometry.h>
#include <debug.h>
#include <lld_encoder.h>
#include <lld_drive_control.h>

//#define MATLAB_ODOMETRY
#define speed_delta_pr 30

#ifdef MATLAB_ODOMETRY
    static const SerialConfig sdcfg = {
            .speed  = 115200,
            .cr1    = 0,
            .cr2    = 0,
            .cr3    = 0
        };
#endif
/**
 * @brief test odometry to get distance
 * @note unit of CM
 */
void testRobotOdometryCommonRoutines(void)
{
    float dist = 0;
    int16_t speed_value = 0;
    float speed_rb = 0;
    float speed_nf = 0;
    bool StartTransfer = FALSE;
    debug_stream_init();
    lldEncoderInit();
    lldDriveControlInit();
    odometryInit();

    #ifdef MATLAB_ODOMETRY
    sdStart( &SD7, &sdcfg );
    palSetPadMode(GPIOE,7, PAL_MODE_ALTERNATE(8) );
    palSetPadMode(GPIOE,8, PAL_MODE_ALTERNATE(8) );
    #endif
    systime_t time = chVTGetSystemTime();
    while(1)
    {
       char sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
       switch(sym)
       {
           case 'a':
               speed_value += speed_delta_pr;
               break;
           case 'd':
               speed_value -= speed_delta_pr;
               break;
           case ' ':
               speed_value = 0;
               break;
           default: ;
        }
        speed_value=Check(speed_value,MAX_BACK_MOTOR,
                                           MAX_FORWARD_MOTOR);
        lldControlSetDrivingMotorPower(speed_value);
        dist = odometryGetRobotDistance(CM);
        speed_rb = odometryGetRobotSpeed(CM_S);
        speed_nf = odometryGetRobotSpeedNoFilter(CM_S);
        #ifdef MATLAB_ODOMETRY
            char start_sym = sdGetTimeout(&SD7, TIME_IMMEDIATE);
            time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
            if(start_sym == 's')
            {
                StartTransfer = TRUE;
            }
            if(StartTransfer)
            {
               sdWrite(&SD7,(uint8_t*)&dist,4);
               sdWrite(&SD7,(uint8_t*)&speed_rb,4);
               sdWrite(&SD7,(uint8_t*)&speed_nf,4);
            }
            time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
        #else
          dbgprintf("Distance:%d Speed:%d \n\r",(int)dist,(int)(speed_rb));
          time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
        #endif
    }
}
