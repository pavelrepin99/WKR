#include <tests.h>
#include <lld_encoder.h>
#include <lld_drive_control.h>
#include <debug.h>

#define speed_delta_pr 30
#define MATLAB

#ifdef MATLAB
    static const SerialConfig sdcfg = {
            .speed  = 115200,
            .cr1    = 0,
            .cr2    = 0,
            .cr3    = 0
        };
#endif
/**
 * @testing the encoder
 * @note variable of encoder displayed in Serial
 */
void testEncoderCommonRoutines(void)
{
    float tc = 0;
    float rc = 0;
    float dr = 0;
    int32_t speed_value = 0;
    char sym = 0;
    char start_sym = 0;
    bool StartTransfer = FALSE;
    lldDriveControlInit();
    lldEncoderInit();
    debug_stream_init();
    #ifdef MATLAB
    sdStart( &SD7, &sdcfg );
    palSetPadMode(GPIOE,7, PAL_MODE_ALTERNATE(8) );
    palSetPadMode(GPIOE,8, PAL_MODE_ALTERNATE(8) );
    #endif
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        sym = sdGetTimeout(&SD3, TIME_IMMEDIATE);
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
        tc = lldGetEncoderRawTicks();
        rc = lldGetEncoderRawRevs();
        dr = lldGetEncoderDirection();
        #ifdef MATLAB
            start_sym = sdGetTimeout(&SD7, TIME_IMMEDIATE);
            time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
            if(start_sym == 's')
            {
                StartTransfer = TRUE;
            }
            if(StartTransfer)
            {
               sdWrite(&SD7,(uint8_t*)&tc,4);
               sdWrite(&SD7,(uint8_t*)&rc,4);
               sdWrite(&SD7,(uint8_t*)&dr,4);
            }
            time = chThdSleepUntilWindowed (time, MS2ST(10)+time);
        #else
            dbgprintf("Tic count:%d Rev count:%d Direction:%d\n\r",tc,
                      (int)rc,dr);
            time = chThdSleepUntilWindowed (time, MS2ST(300)+time);
        #endif
    }
}
