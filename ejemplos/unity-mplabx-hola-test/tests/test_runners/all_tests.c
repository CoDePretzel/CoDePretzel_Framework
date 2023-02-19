#include "unity_fixture.h"
#include "all_tests.h"

static void RunAllTests(void)
{ // All the groups will be registered here
    RUN_TEST_GROUP(hello_led);
}

void run_unity_tests(char * main_path)
{
    UnityBegin(main_path);
    RunAllTests();
    UnityEnd();
}