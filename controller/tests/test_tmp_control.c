#include <tests.h>
#include <tmp_control.h>
void testPWM(void)
{
    int a;
        for(a=0; a<=100; a+=10)
        {
            PWMcontrol(a);
            chThdSleepSeconds(1);
            if(a==100)
            {
                a=-10;
            }
         }
}
