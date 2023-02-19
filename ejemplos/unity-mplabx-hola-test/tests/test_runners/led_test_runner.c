#include "unity_fixture.h"

// All the groups need to be included here, with their specific test cases
// If this file doesn't contain a test case, it will not be run and can lead to false positive

TEST_GROUP_RUNNER(hello_led)
{// All the test cases in the group will be registered here
    RUN_TEST_CASE(hello_led, DummyFalse);
    RUN_TEST_CASE(hello_led, TestLEDOn);
}