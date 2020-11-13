#ifndef INCLUDE_TMP_CONTROL_H_
#define INCLUDE_TMP_CONTROL_H_

#include <common.h>

void lldDriveControlInit(void);
void lldControlSetSteerMotorRawPower(int32_t duty_cycle);
int32_t Check(int32_t duty_cycle, int32_t low,int32_t high);
void lldControlSetSteerMotorPower(int32_t duty_cycle);
#endif
