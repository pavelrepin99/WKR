#include <tests.h>
#include <debug.h>
#include <lld_steer_angle.h>
#include <lld_drive_control.h>
#include <drive_control_system.h>

#define angle_inc 1
#define speed_inc 0.01
//#define MATLAB_PI_STEER

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
 * @note passes input and output angle to terminal or matlab
 */
void testPISteerAngle(void)
{
    int16_t angle_input = 0;
    float angle_output = 0;
    bool StartTransfer = FALSE;
    char sym = 0;
    driveCSInit(1);
    debug_stream_init();
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
                    //angle_input += angle_inc;
                    angle_input = 20;
                    break;
                case 'd':
                    angle_input = -20;
                    //angle_input -= angle_inc;
                    break;
                case ' ':
                    angle_input = 0;
                    break;
                case 'o':
                    angle_input = 0;
                    break;
                case 'v':
                    angle_input = -20;
                    break;
                case 'c':
                    angle_input = 20;
                    break;
                default: ;
            }
            //angle_input = Check(angle_input,-25,25);
            setRefAngle(angle_input);
            angle_output = lldGetSteerAngle(DEG);
            angle_output = Check(angle_output, MIN_ANGLE,MAX_ANGLE);
            #ifdef MATLAB_PI_STEER
                if(StartTransfer)
                {
                    sdWrite(&SD7,(uint8_t*)&angle_output,4);
                }
                time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
            #else
                dbgprintf("Input:%d Output:%d\n\r",angle_input, angle_output);
                time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
            #endif
        }
}
/**
 * @brief Test for closed system in speed
 * @note passes input and output speed to terminal or matlab
 */
void testPISpeedMotor(void)
{
    float speed_input = 0;
    float speed_output = 0;
    bool StartTransfer = FALSE;
    char sym = 0;
    driveCSInit(1);
    debug_stream_init();
    ResetSpeedRegulator();
    #ifdef  MATLAB_PI_STEER
        //sdStart( &SD7, &sdcfg );
        //sdStart( &SD3, &sdcfg );
        palSetPadMode(GPIOE,7, PAL_MODE_ALTERNATE(8) );
        palSetPadMode(GPIOE,8, PAL_MODE_ALTERNATE(8) );
        palSetPadMode( GPIOD, 8, PAL_MODE_ALTERNATE(7));
        palSetPadMode( GPIOD, 9, PAL_MODE_ALTERNATE(7));
    #endif
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        setRefAngle(0);
        #ifdef MATLAB_PI_STEER
            sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
            //time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
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
                speed_input += speed_inc;
                break;
            case 'd':
                speed_input -= speed_inc;
                break;
            case ' ':
                speed_input = 0;
                break;
            case 'c':
                speed_input = 0.15;
                break;
            case 'x':
                speed_input = -0.15;
                break;
            default: ;
        }
        /*
         * @brief speed_input in M_S
         */
        setRefSpeed(speed_input, CM_S);
        speed_output = odometryGetRobotSpeed(CM_S);
        #ifdef MATLAB_PI_STEER
        if(StartTransfer)
        {
            sdWrite(&SD3,(uint8_t*)&speed_output,4);
        }
        time = chThdSleepUntilWindowed(time, MS2ST(25)+time);
        #else
            //dbgprintf("In:%d Out:%d\n\r",(int)(speed_input*100),
                      //(int)(speed_output));
            time = chThdSleepUntilWindowed (time, MS2ST(100)+time);
        #endif
}
}
