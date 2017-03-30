#include "pins.h"

#define PIN_LED2    PB5

//
void delay(volatile unsigned int n)
{
    while (n --> 0);
}

//
int main( void )
{
    GPIO_DDR(PIN_LED2, 1);
    GPIO_CR1(PIN_LED2, 1);
    GPIO_CR2(PIN_LED2, 1);
    GPIO_ODR(PIN_LED2, 0);

    while (1)
    {
        GPIO_ODR(PIN_LED2, 1);
        delay(720000);
        GPIO_ODR(PIN_LED2, 0);
        delay(720000);
    }
}
