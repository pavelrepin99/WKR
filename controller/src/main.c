#include <common.h>
#include <tests.h>

static void searchtest(void);

int main(void)
{
    halInit();
    chSysInit();

    #if (MAIN_PROGRAM_ROUTINE != PROGRAM_ROUTINE_MASTER)
        searchtest();
    #endif
}

static void searchtest(void)
{
#if (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_RAW_POWER_STEER)
    testRawPowerSteeringWheel();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_POWER_STEER)
    testPowerSteeringWheel();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_RAW_SPEED_MOTOR)
    testRawPowerSpeedMotor();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_SPEED_MOTOR)
    testPowerSpeedMotor();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_UART)
    testUart();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_ENCODER)
    testEncoderCommonRoutines();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_ROBOT_ODOMETRY)
    testRobotOdometryDistance();
#endif
}
