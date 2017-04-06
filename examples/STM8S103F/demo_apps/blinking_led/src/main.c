#include "pins.h"

#define PIN_LED2    PB5

// stm8: unsigned int = 2 Bytes
void delay(volatile uint16_t time)
{
    while (time --> 0U);
}

// main
int main( void )
{
    GPIO_DDR(PIN_LED2, 1);
    GPIO_CR1(PIN_LED2, 1);
    GPIO_CR2(PIN_LED2, 1);
    GPIO_ODR(PIN_LED2, 0);

    // 100 ms
    uint32_t time = 17000U;

    while (1)
    {
        GPIO_ODR(PIN_LED2, 1);
        delay(time);
        GPIO_ODR(PIN_LED2, 0);
        delay(time);
    }
}
