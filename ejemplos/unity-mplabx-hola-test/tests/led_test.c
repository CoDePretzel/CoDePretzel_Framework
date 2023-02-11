/*
 * File:   led_test.c
 * Author: rafael
 *
 * Created on January 29, 2023, 9:58 PM 
 */
#include <stdint.h>

TEST_GROUP(hello_led);

static char expected_led_value;

TEST_SETUP(hello_led)
{
// Setup something before each test in this group
}

TEST_TEAR_DOWN(hello_led)
{
// Do something after each test in this group (like flush a buffer or overwrite a place in memory)
}

static void expect(uint8_t led_state)
{
    expected_led_value = led_state;
}

static void given(uint8)
{

}