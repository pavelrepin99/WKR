#include <tests.h>
#include <debug.h>
#include <lld_steer_angle.h>
#include <drive_control_system.h>

#define angle_inc 1
#define MATLAB_PI_STEER

#ifdef MATLAB_PI_STEER
    static const SerialConfig sdcfg = {
            .speed  = 115200,
            .cr1    = 0,
            .cr2    = 0,
            .cr3    = 0
        };
#endif

/**
 * @brief Test for closed system in angle
 * @note passes input and output angle to terminal
 */
void testPISteerAngle(void)
{
    int16_t angle_input = 0;
    int16_t angle_output = 0;
    bool StartTransfer = FALSE;
    char sym = 0;
    driveCSInit(1);
    debug_stream_init();
    lldSteerAngleInit();
    #ifdef  MATLAB_PI_STEER
        sdStart( &SD7, &sdcfg );
        palSetPadMode(GPIOE,7, PAL_MODE_ALTERNATE(8) );
        palSetPadMode(GPIOE,8, PAL_MODE_ALTERNATE(8) );
    #endif
    systime_t time = chVTGetSystemTime();
    while(1)
        {
            #ifdef MATLAB_PI_STEER
                sym = sdGetTimeout(&SD7, TIME_IMMEDIATE);
                time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
                if(sym == 's')
                {
                    StartTransfer = TRUE;
                }
            #else
                sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
            #endif
            switch(sym)
            {
                case 'a':
                    angle_input += angle_inc;
                    break;
                case 'd':
                    angle_input -= angle_inc;
                    break;
                case ' ':
                    angle_input = 0;
                    break;
                default: ;
            }
            setRefAngle(angle_input);
            angle_output = lldGetSteerAngle(DEG);
            #ifdef MATLAB_PI_STEER
                if(StartTransfer)
                {
                    sdWrite(&SD7,(uint8_t*)&angle_input,2);
                    sdWrite(&SD7,(uint8_t*)&angle_output,2);
                }
                time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
            #else
                dbgprintf("Input:%d Output:%d\n\r",angle_input, angle_output);
                time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
            #endif
        }
}

