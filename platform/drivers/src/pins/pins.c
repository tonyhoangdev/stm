#include "pins.h"

GPIO_Type * g_gpioBasePtr[] = GPIO_BASE_PTRS;

void GPIO_DDR(uint8_t pin, uint8_t value)
{
    g_gpioBasePtr[pin >> 3U]->DDR &= (uint8_t)~(1U << (pin & 0x07U));
    g_gpioBasePtr[pin >> 3U]->DDR |= (uint8_t)(value << (pin & 0x07U));
}

void GPIO_CR1(uint8_t pin, uint8_t value)
{
    g_gpioBasePtr[pin >> 3U]->CR1 &= (uint8_t)~(1U << (pin & 0x07U));
    g_gpioBasePtr[pin >> 3U]->CR1 |= (uint8_t)(value << (pin & 0x07U));
}

void GPIO_CR2(uint8_t pin, uint8_t value)
{
    g_gpioBasePtr[pin >> 3U]->CR2 &= (uint8_t)~(1U << (pin & 0x07U));
    g_gpioBasePtr[pin >> 3U]->CR2 |= (uint8_t)(value << (pin & 0x07U));
}

void GPIO_ODR(uint8_t pin, uint8_t value)
{
    g_gpioBasePtr[pin >> 3U]->ODR &= (uint8_t)~(1U << (pin & 0x07U));
    g_gpioBasePtr[pin >> 3U]->ODR |= (uint8_t)(value << (pin & 0x07U));
}

uint8_t GPIO_IDR(uint8_t pin)
{
    uint8_t shift = (uint8_t)(pin & 0x07U);
    uint8_t mask = (uint8_t)(1U << (pin & 0x07U));
    return (uint8_t)((g_gpioBasePtr[pin >> 3U]->DDR & mask) >> shift);
}
