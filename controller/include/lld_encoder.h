#ifndef INCLUDE_LLD_ENCODER_H_
#define INCLUDE_LLD_ENCODER_H_

#include <common.h>
/*
 * global variables
 */
typedef int32_t tic_count_enc;
typedef float rev_count_enc;
typedef bool direction_rotation_enc;

/**
 * @brief Initialization Interruption
 * @note variable init_enc for protection
 */
void lldEncoderInit(void);
/**
 * @brief Get number of encoder tics
 * @note maximum tics - number of tics one per revolution
 * @return tics passed by the encoder
 */
tic_count_enc lldGetEncoderRawTicks(void);
/**
 * @brief Get direction of rotation of the encoder
 * @return direction of rotation
 */
direction_rotation_enc lldGetEncoderDirection(void);
/**
 * @brief Get number of revolution passed by the encoder
 * @return number of revolutions with fractional part
 */
rev_count_enc lldGetEncoderRawRevs(void);
/**
 * @brief Get direction of rotation of the encoder
 * @return direction of rotation
 */
void lldResetEncoder(void);

#endif
