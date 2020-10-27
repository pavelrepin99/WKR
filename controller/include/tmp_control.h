#ifndef INCLUDE_TMP_CONTROL_H_
#define INCLUDE_TMP_CONTROL_H_

#include <common.h>

void Init(void);
void PWMcontrol(int32_t duty_cycle);
int32_t Check(int32_t duty_cycle, int8_t low,int8_t high);

#endif
