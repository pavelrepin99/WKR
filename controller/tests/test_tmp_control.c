#include <tests.h>
#include <tmp_control.h>
void testPWM(void)
{
    int8_t a;
    Init();
    for(a=0; a<=100; a+=10)
    {
        PWMcontrol(a);
        chThdSleepSeconds(1);
        a=Check(a,0, -10);
     }
}
