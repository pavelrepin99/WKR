#include <lld_encoder.h>

#define MAX_TIC 500
int32_t status_white_pin = 0;
static bool init_enc = false;
tic_count_enc tic_count = 0;
rev_count_enc rev_count = 0;
direction_rotation_enc direction_rotation = 0;

/**
 * @brief handler interrupt
 */
static void extcb( EXTDriver *extp, expchannel_t channel )
{
    extp = extp;
    channel = channel;
    status_white_pin = palReadLine(PAL_LINE(GPIOD, 4));
    if(status_white_pin == 0)
    {
        direction_rotation = 1;
        tic_count+=1;
    }
    else if(status_white_pin == 1)
    {
        direction_rotation = 0;
        tic_count-=1;
    }
    if(abs(tic_count) >= MAX_TIC )
    {
        tic_count=0;
        if(direction_rotation == 1)
        {
            rev_count+=1;
        }
        else if(direction_rotation == 0)
        {
            rev_count-=1;
        }
    }
}

/**
 * @brief Initialization Interruption
 * @note variable init_enc for protection
 */
void lldEncoderInit(void)
{
    if(init_enc)
    return;
    static const EXTConfig extcfg = {
    .channels = 
    {
        [0]  = {EXT_CH_MODE_DISABLED, NULL},
        [1]  = {EXT_CH_MODE_DISABLED, NULL},
        [2]  = {EXT_CH_MODE_DISABLED, NULL},
        [3]  = {EXT_CH_MODE_DISABLED, NULL},
        [4]  = {EXT_CH_MODE_DISABLED, NULL},
        [5]  = {EXT_CH_MODE_RISING_EDGE | EXT_CH_MODE_AUTOSTART |
                EXT_MODE_GPIOD, extcb},
        [6]  = {EXT_CH_MODE_DISABLED, NULL},
        [7]  = {EXT_CH_MODE_DISABLED, NULL},
        [8]  = {EXT_CH_MODE_DISABLED, NULL},
        [9]  = {EXT_CH_MODE_DISABLED, NULL},
        [10] = {EXT_CH_MODE_DISABLED, NULL},
        [11] = {EXT_CH_MODE_DISABLED, NULL},
        [12] = {EXT_CH_MODE_DISABLED, NULL},
        [13] = {EXT_CH_MODE_DISABLED, NULL},
        [14] = {EXT_CH_MODE_DISABLED, NULL},
        [15] = {EXT_CH_MODE_DISABLED, NULL},
    }
    };
    extStart( &EXTD1, &extcfg );
    init_enc = true;
}

/**
 * @brief Get number of encoder tics
 * @note maximum tics - number of tics one per revolution
 * @return tics passed by the encoder
 */
tic_count_enc lldGetEncoderRawTicks(void)
{
    return tic_count;
}
/**
 * @brief Get direction of rotation of the encoder
 * @return direction of rotation
 */
direction_rotation_enc lldGetEncoderDirection(void)
{
    return direction_rotation;
}
/**
 * @brief Get number of revolution passed by the encoder
 * @return number of revolutions + number tics
 */
rev_count_enc lldGetEncoderRawRevs(void)
{
    return (rev_count + (float)tic_count/(float)MAX_TIC);
}
/**
 * @brief Reset the value of variables
 * @note variables: number of tics, direction rotation, number of revolution
 */
void lldResetEncoder(void)
{
    direction_rotation = 0;
    tic_count = 0;
    rev_count = 0;
}
