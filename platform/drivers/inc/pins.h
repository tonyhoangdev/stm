#ifndef PINS_H
#define PINS_H

#include "device_registers.h"

#define PA0 0U
#define PA1 1U
#define PA2 2U
#define PA3 3U
#define PA4 4U
#define PA5 5U
#define PA6 6U
#define PA7 7U

#define PB0 8U
#define PB1 9U
#define PB2 10U
#define PB3 11U
#define PB4 12U
#define PB5 13U
#define PB6 14U
#define PB7 15U

#define PC0 16U
#define PC1 17U
#define PC2 18U
#define PC3 19U
#define PC4 20U
#define PC5 21U
#define PC6 22U
#define PC7 23U

#define PD0 24U
#define PD1 25U
#define PD2 26U
#define PD3 27U
#define PD4 28U
#define PD5 29U
#define PD6 30U
#define PD7 31U

#define PE0 32U
#define PE1 33U
#define PE2 34U
#define PE3 35U
#define PE4 36U
#define PE5 37U
#define PE6 38U
#define PE7 39U

#define PF0 40U
#define PF1 41U
#define PF2 42U
#define PF3 43U
#define PF4 44U
#define PF5 45U
#define PF6 46U
#define PF7 47U

static GPIO_Type * s_gpioBasePtr[] = GPIO_BASE_PTRS;

static inline void GPIO_DDR(uint8_t pin, uint8_t value)
{
    s_gpioBasePtr[pin/8U]->DDR &= ~(1U << (pin % 8));
    s_gpioBasePtr[pin/8U]->DDR |= value << (pin % 8);
}

static inline void GPIO_CR1(uint8_t pin, uint8_t value)
{
    s_gpioBasePtr[pin/8U]->CR1 &= ~(1U << (pin % 8));
    s_gpioBasePtr[pin/8U]->CR1 |= value << (pin % 8);
}

static inline void GPIO_CR2(uint8_t pin, uint8_t value)
{
    s_gpioBasePtr[pin/8U]->CR2 &= ~(1U << (pin % 8));
    s_gpioBasePtr[pin/8U]->CR2 |= value << (pin % 8);
}

static inline void GPIO_ODR(uint8_t pin, uint8_t value)
{
    s_gpioBasePtr[pin/8U]->ODR &= ~(1U << (pin % 8));
    s_gpioBasePtr[pin/8U]->ODR |= value << (pin % 8);
}

static inline uint8_t GPIO_IDR(uint8_t pin)
{
    uint8_t shift = 1U << (pin % 8);
    return (s_gpioBasePtr[pin/8U]->DDR & shift) >> shift;
}

#endif