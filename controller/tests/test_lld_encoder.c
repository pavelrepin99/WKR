#include <tests.h>
#include <lld_encoder.h>
#include <debug.h>

/**
 * @testing the encoder
 * @note variable of encoder displayed in Serial
 */
void testEncoderCommonRoutines(void)
{
    debug_stream_init();
    systime_t time = chVTGetSystemTime();
    int32_t tc = 0;
    float rc = 0;
    bool dr = 0;
    lldEncoderInit();
    while(1)
    {
         tc = lldGetEncoderRawTicks();
         rc = 1000*lldGetEncoderRawRevs();
         dr = lldGetEncoderDirection();
         dbgprintf("Tic count:%d Rev count:%d Direction:%d\n\r",tc,(int)rc,dr);
         time = chThdSleepUntilWindowed (time, MS2ST(300)+time);
    }
}
