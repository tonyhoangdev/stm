#include "pins.h"

#define PIN_CLK     PC3
#define PIN_LATCH   PC4
#define PIN_DATA    PC5

#define PIN_LED2    PD6
#define PIN_TEST    PB5

void delay(volatile unsigned int n)
{
    while (n-- > 0)
        ;
}

void clock()
{
    GPIO_ODR(PIN_CLK, 1);
    delay(100);
    GPIO_ODR(PIN_CLK, 0);
    delay(100);
}

void SendByte(uint8_t data)
{
    uint8_t i, x, da = data;

    for (i = 0; i < 8U; i++)
    {
        x = da & 0x80;

        if (x > 0)
        {
            GPIO_ODR(PIN_DATA, 1);
        }
        else
        {
            GPIO_ODR(PIN_DATA, 0);
        }

        clock();
        da <<= 1U;
    }
}

void sangLevel(uint8_t level)
{
    uint8_t tmp = 0;
    uint8_t i;

    for (i = 0; i < level; i++)
    {
        tmp |= (1 << i);
    }

    GPIO_ODR(PIN_LATCH, 0);
    SendByte(tmp);
    GPIO_ODR(PIN_LATCH, 1);
}

void shiftLeft(uint8_t level,
               uint32_t time)
{
    for (uint8_t i = 0; i < level; i++)
    {
        GPIO_ODR(PIN_LATCH, 0);
        SendByte(1 << i);
        GPIO_ODR(PIN_LATCH, 1);
        delay(time);
    }
}

void shiftRight(uint8_t level,
                uint32_t time)
{
    for (uint8_t i = level; i > 0; i--)
    {
        GPIO_ODR(PIN_LATCH, 0);
        SendByte(1 << i);
        GPIO_ODR(PIN_LATCH, 1);
        delay(time);
    }

    GPIO_ODR(PIN_LATCH, 0);
    SendByte(1 << 0);
    GPIO_ODR(PIN_LATCH, 1);
    delay(time);
}

int main(void)
{
    GPIO_DDR(PIN_CLK, 1);
    GPIO_CR1(PIN_CLK, 1);
    GPIO_CR2(PIN_CLK, 1);
    GPIO_ODR(PIN_CLK, 1);

    GPIO_DDR(PIN_LATCH, 1);
    GPIO_CR1(PIN_LATCH, 1);
    GPIO_CR2(PIN_LATCH, 1);

    GPIO_DDR(PIN_DATA, 1);
    GPIO_CR1(PIN_DATA, 1);
    GPIO_CR2(PIN_DATA, 1);

    GPIO_DDR(PIN_LED2, 1);
    GPIO_CR1(PIN_LED2, 1);
    GPIO_CR2(PIN_LED2, 1);

    GPIO_DDR(PIN_TEST, 1);
    GPIO_CR1(PIN_TEST, 1);
    GPIO_CR2(PIN_TEST, 1);

    while (1)
    {
        GPIO_ODR(PIN_TEST, 1);
        GPIO_ODR(PIN_LED2, 1);
        for (uint8_t i = 0; i < 6; i++)
        {
            sangLevel(i);
            delay(220000);
        }

        for (uint8_t i = 5; i >= 1; i--)
        {
            sangLevel(i);
            delay(220000);
        }
        sangLevel(0);
        delay(220000);

        shiftLeft(5, 220000);
        shiftRight(5, 220000);

        GPIO_ODR(PIN_LED2, 0);
        GPIO_ODR(PIN_TEST, 0);
        delay(220000);
    }
}
