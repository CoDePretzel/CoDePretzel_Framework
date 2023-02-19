/*
 * File:   led_test.c
 * Author: rafael
 *
 * Created on January 29, 2023, 9:58 PM 
 */
#include <stdint.h>
#include "unity_fixture.h"

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

static void given(uint8_t state_given)
{
    TEST_ASSERT_EQUAL(state_given, expected_led_value);
}

TEST(hello_led, DummyFalse)
{
    // Demo de un test que falla
    TEST_ASSERT_FALSE(1);
}

TEST(hello_led, TestLEDOn)
{
    //Demo de un test positivo, manualmente hacer como que el test pasó
    expect(1); // Escribir el valor esperado del pin del LED  
    given(1); // Manualmente escribiendo el valor esperado, debe de pasar el test
}