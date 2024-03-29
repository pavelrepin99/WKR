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
#if (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_RAW_POWER_WHEELS_ROUTINES)
    testRawPowerWheelsRoutine();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_POWER_WHEELS_ROUTINES)
    testPowerWheelsRoutine();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_UART)
    testUart();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_ENCODER)
    testEncoderCommonRoutines();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_ROBOT_ODOMETRY)
    testRobotOdometryCommonRoutines();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_ROBOT_ODOMETRY_SPEED)
    testRobotOdometryReset();
#elif (MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_STEER_ANGLE)
    testSteerAngle();
#elif(MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_SPEED_FILTER)
    testRobotOdometryFilterSpeed();
#elif(MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_DCS_ANGLE)
    testPISteerAngle();
#elif(MAIN_PROGRAM_ROUTINE == PROGRAM_ROUTINE_TEST_DCS_SPEED)
    testPISpeedMotor();
#elif(MAIN_PROGRAM_ROUTINE == TEST_PY)
    testPyserial();
#endif
}
