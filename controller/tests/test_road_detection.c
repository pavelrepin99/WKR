#include <tests.h>
#include <debug.h>
#include <drive_control_system.h>

static const SerialConfig sdcfg = {
                .speed  = 115200,
                .cr1    = 0,
                .cr2    = 0,
                .cr3    = 0
            };


void testPyserial(void)
{
    ResetSteerRegulator();
    int16_t sym = 0;
    int8_t angle = 0;
    int8_t speed = 0;
    int8_t start = 0;
    debug_stream_init();
    driveCSInit(1);
    sdStart(&SD7, &sdcfg );
    palSetPadMode(GPIOE,7, PAL_MODE_ALTERNATE(8) );
    palSetPadMode(GPIOE,8, PAL_MODE_ALTERNATE(8) );
    systime_t time = chVTGetSystemTime();
    while(1)
    {
        sdReadTimeout(&SD3,(uint8_t*)&sym,3,TIME_IMMEDIATE);
        int8_t *buf = (int8_t*)&sym;
        start = buf[0];
        angle = buf[1];
        speed = buf[2];
        setRefAngle(angle);
        setRefSpeed(speed, M_S);
        dbgprintf("start:%d angle:%d speed:%d\n\r",start,angle, speed);
        time = chThdSleepUntilWindowed(time, MS2ST(20)+time);
    }
}
