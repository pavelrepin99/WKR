
#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_

#include "common.h"

/**
 * @brief Initialization UART
 */
void debug_stream_init( void );
/**
 * @brief Output function
 * @args debug_stream
 * @args ap
 * @args const char* format
 */
void dbgprintf( const char* format, ... );

#endif 
