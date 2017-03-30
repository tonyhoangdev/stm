/*!
 * @author MinhHT3
 * @file STM8S103F.h
 * @version Rev1.0
 * @date 2017-03-29
 * @brief Peripheral Access Layer for STM8S103F
 *
 * This file contains register definitions and macros for easy access to their bit fields.
 *
 */

/*******************************************************************************
 * MCU activation
 ******************************************************************************/

#ifndef STM8S103F_H
#define STM8S103F_H

#include <stdint.h>

/*******************************************************************************
 * Generic macros
 ******************************************************************************/

/* IO definitions (Access restrictions to peripheral registers) */
#ifndef __IO
#ifdef __cplusplus
    #define   __I     volatile            /*!< Defines 'read only' permissions        */
#else
    #define   __I     volatile const      /*!< Defines 'read only' permissions        */
#endif
#define       __O     volatile            /*!< Defines 'write only' permissions       */
#define       __IO    volatile            /*!< Defines 'read / write' permissions     */
#endif


/*******************************************************************************
 * GPIO Peripheral Access Layer
 ******************************************************************************/

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO_Peripheral Access Layer
 * @{
 */


/** GPIO - Size of Registers Arrays */

/** GPIO - Register Layout Typedef */
typedef struct
{
    __IO uint8_t ODR;                          /**< Port output data register, offset: 0x0 */
    __I  uint8_t IDR;                          /**< Port pin input register, offset: 0x1 */
    __IO uint8_t DDR;                          /**< Port data direction register, offset: 0x2 */
    __IO uint8_t CR1;                          /**< Port control register 1, offset: 0x3 */
    __IO uint8_t CR2;                          /**< Port control register 1, offset: 0x4 */
} GPIO_Type, *GPIO_MemMapPtr;

/** Number of instances of the GPIO module. */
#define GPIO_INSTANCE_COUNT             (6u)


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                     (0x00005000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                          ((GPIO_Type *)GPIOA_BASE)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                     (0x00005005u)
/** Peripheral GPIOB base pointer */
#define GPIOB                          ((GPIO_Type *)GPIOB_BASE)
/** Peripheral GPIOC base address */
#define GPIOC_BASE                     (0x0000500Au)
/** Peripheral GPIOC base pointer */
#define GPIOC                          ((GPIO_Type *)GPIOC_BASE)
/** Peripheral GPIOD base address */
#define GPIOD_BASE                     (0x0000500Fu)
/** Peripheral GPIOD base pointer */
#define GPIOD                          ((GPIO_Type *)GPIOD_BASE)
/** Peripheral GPIOE base address */
#define GPIOE_BASE                     (0x00005014u)
/** Peripheral GPIOE base pointer */
#define GPIOE                          ((GPIO_Type *)GPIOE_BASE)
/** Peripheral GPIOF base address */
#define GPIOF_BASE                     (0x00005019u)
/** Peripheral GPIOF base pointer */
#define GPIOF                          ((GPIO_Type *)GPIOF_BASE)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                 { GPIOA_BASE, GPIOB_BASE, GPIOC_BASE, GPIOD_BASE, GPIOE_BASE, GPIOF_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                  { GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOF }

/*******************************************************************************
 * GPIO Register Masks
 ******************************************************************************/

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* ODR Bit Fields */
#define GPIO_ODR_ODR0_MASK                       0x1u
#define GPIO_ODR_ODR0_SHIFT                      0u
#define GPIO_ODR_ODR0_WIDTH                      1u
#define GPIO_ODR_ODR0(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR0_SHIFT))&GPIO_ODR_ODR0_MASK)
#define GPIO_ODR_ODR1_MASK                       0x2u
#define GPIO_ODR_ODR1_SHIFT                      1u
#define GPIO_ODR_ODR1_WIDTH                      1u
#define GPIO_ODR_ODR1(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR1_SHIFT))&GPIO_ODR_ODR1_MASK)
#define GPIO_ODR_ODR2_MASK                       0x4u
#define GPIO_ODR_ODR2_SHIFT                      2u
#define GPIO_ODR_ODR2_WIDTH                      1u
#define GPIO_ODR_ODR2(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR2_SHIFT))&GPIO_ODR_ODR2_MASK)
#define GPIO_ODR_ODR3_MASK                       0x8u
#define GPIO_ODR_ODR3_SHIFT                      3u
#define GPIO_ODR_ODR3_WIDTH                      1u
#define GPIO_ODR_ODR3(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR3_SHIFT))&GPIO_ODR_ODR3_MASK)
#define GPIO_ODR_ODR4_MASK                       0x10u
#define GPIO_ODR_ODR4_SHIFT                      4u
#define GPIO_ODR_ODR4_WIDTH                      1u
#define GPIO_ODR_ODR4(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR4_SHIFT))&GPIO_ODR_ODR4_MASK)
#define GPIO_ODR_ODR5_MASK                       0x20u
#define GPIO_ODR_ODR5_SHIFT                      5u
#define GPIO_ODR_ODR5_WIDTH                      1u
#define GPIO_ODR_ODR5(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR5_SHIFT))&GPIO_ODR_ODR5_MASK)
#define GPIO_ODR_ODR6_MASK                       0x40u
#define GPIO_ODR_ODR6_SHIFT                      6u
#define GPIO_ODR_ODR6_WIDTH                      1u
#define GPIO_ODR_ODR6(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR6_SHIFT))&GPIO_ODR_ODR6_MASK)
#define GPIO_ODR_ODR7_MASK                       0x80u
#define GPIO_ODR_ODR7_SHIFT                      7u
#define GPIO_ODR_ODR7_WIDTH                      1u
#define GPIO_ODR_ODR7(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_ODR_ODR7_SHIFT))&GPIO_ODR_ODR7_MASK)
/* IDR Bit Fields */
#define GPIO_IDR_IDR0_MASK                       0x1u
#define GPIO_IDR_IDR0_SHIFT                      0u
#define GPIO_IDR_IDR0_WIDTH                      1u
#define GPIO_IDR_IDR0(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR0_SHIFT))&GPIO_IDR_IDR0_MASK)
#define GPIO_IDR_IDR1_MASK                       0x2u
#define GPIO_IDR_IDR1_SHIFT                      1u
#define GPIO_IDR_IDR1_WIDTH                      1u
#define GPIO_IDR_IDR1(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR1_SHIFT))&GPIO_IDR_IDR1_MASK)
#define GPIO_IDR_IDR2_MASK                       0x4u
#define GPIO_IDR_IDR2_SHIFT                      2u
#define GPIO_IDR_IDR2_WIDTH                      1u
#define GPIO_IDR_IDR2(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR2_SHIFT))&GPIO_IDR_IDR2_MASK)
#define GPIO_IDR_IDR3_MASK                       0x8u
#define GPIO_IDR_IDR3_SHIFT                      3u
#define GPIO_IDR_IDR3_WIDTH                      1u
#define GPIO_IDR_IDR3(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR3_SHIFT))&GPIO_IDR_IDR3_MASK)
#define GPIO_IDR_IDR4_MASK                       0x10u
#define GPIO_IDR_IDR4_SHIFT                      4u
#define GPIO_IDR_IDR4_WIDTH                      1u
#define GPIO_IDR_IDR4(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR4_SHIFT))&GPIO_IDR_IDR4_MASK)
#define GPIO_IDR_IDR5_MASK                       0x20u
#define GPIO_IDR_IDR5_SHIFT                      5u
#define GPIO_IDR_IDR5_WIDTH                      1u
#define GPIO_IDR_IDR5(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR5_SHIFT))&GPIO_IDR_IDR5_MASK)
#define GPIO_IDR_IDR6_MASK                       0x40u
#define GPIO_IDR_IDR6_SHIFT                      6u
#define GPIO_IDR_IDR6_WIDTH                      1u
#define GPIO_IDR_IDR6(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR6_SHIFT))&GPIO_IDR_IDR6_MASK)
#define GPIO_IDR_IDR7_MASK                       0x80u
#define GPIO_IDR_IDR7_SHIFT                      7u
#define GPIO_IDR_IDR7_WIDTH                      1u
#define GPIO_IDR_IDR7(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_IDR_IDR7_SHIFT))&GPIO_IDR_IDR7_MASK)
/* DDR Bit Fields */
#define GPIO_DDR_DDR0_MASK                       0x1u
#define GPIO_DDR_DDR0_SHIFT                      0u
#define GPIO_DDR_DDR0_WIDTH                      1u
#define GPIO_DDR_DDR0(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR0_SHIFT))&GPIO_DDR_DDR0_MASK)
#define GPIO_DDR_DDR1_MASK                       0x2u
#define GPIO_DDR_DDR1_SHIFT                      1u
#define GPIO_DDR_DDR1_WIDTH                      1u
#define GPIO_DDR_DDR1(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR1_SHIFT))&GPIO_DDR_DDR1_MASK)
#define GPIO_DDR_DDR2_MASK                       0x4u
#define GPIO_DDR_DDR2_SHIFT                      2u
#define GPIO_DDR_DDR2_WIDTH                      1u
#define GPIO_DDR_DDR2(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR2_SHIFT))&GPIO_DDR_DDR2_MASK)
#define GPIO_DDR_DDR3_MASK                       0x8u
#define GPIO_DDR_DDR3_SHIFT                      3u
#define GPIO_DDR_DDR3_WIDTH                      1u
#define GPIO_DDR_DDR3(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR3_SHIFT))&GPIO_DDR_DDR3_MASK)
#define GPIO_DDR_DDR4_MASK                       0x10u
#define GPIO_DDR_DDR4_SHIFT                      4u
#define GPIO_DDR_DDR4_WIDTH                      1u
#define GPIO_DDR_DDR4(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR4_SHIFT))&GPIO_DDR_DDR4_MASK)
#define GPIO_DDR_DDR5_MASK                       0x20u
#define GPIO_DDR_DDR5_SHIFT                      5u
#define GPIO_DDR_DDR5_WIDTH                      1u
#define GPIO_DDR_DDR5(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR5_SHIFT))&GPIO_DDR_DDR5_MASK)
#define GPIO_DDR_DDR6_MASK                       0x40u
#define GPIO_DDR_DDR6_SHIFT                      6u
#define GPIO_DDR_DDR6_WIDTH                      1u
#define GPIO_DDR_DDR6(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR6_SHIFT))&GPIO_DDR_DDR6_MASK)
#define GPIO_DDR_DDR7_MASK                       0x80u
#define GPIO_DDR_DDR7_SHIFT                      7u
#define GPIO_DDR_DDR7_WIDTH                      1u
#define GPIO_DDR_DDR7(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_DDR_DDR7_SHIFT))&GPIO_DDR_DDR7_MASK)
/* CR1 Bit Fields */
#define GPIO_CR1_C0_MASK                         0x1u
#define GPIO_CR1_C0_SHIFT                        0u
#define GPIO_CR1_C0_WIDTH                        1u
#define GPIO_CR1_C0(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C0_SHIFT))&GPIO_CR1_C0_MASK)
#define GPIO_CR1_C1_MASK                         0x2u
#define GPIO_CR1_C1_SHIFT                        1u
#define GPIO_CR1_C1_WIDTH                        1u
#define GPIO_CR1_C1(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C1_SHIFT))&GPIO_CR1_C1_MASK)
#define GPIO_CR1_C2_MASK                         0x4u
#define GPIO_CR1_C2_SHIFT                        2u
#define GPIO_CR1_C2_WIDTH                        1u
#define GPIO_CR1_C2(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C2_SHIFT))&GPIO_CR1_C2_MASK)
#define GPIO_CR1_C3_MASK                         0x8u
#define GPIO_CR1_C3_SHIFT                        3u
#define GPIO_CR1_C3_WIDTH                        1u
#define GPIO_CR1_C3(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C3_SHIFT))&GPIO_CR1_C3_MASK)
#define GPIO_CR1_C4_MASK                         0x10u
#define GPIO_CR1_C4_SHIFT                        4u
#define GPIO_CR1_C4_WIDTH                        1u
#define GPIO_CR1_C4(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C4_SHIFT))&GPIO_CR1_C4_MASK)
#define GPIO_CR1_C5_MASK                         0x20u
#define GPIO_CR1_C5_SHIFT                        5u
#define GPIO_CR1_C5_WIDTH                        1u
#define GPIO_CR1_C5(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C5_SHIFT))&GPIO_CR1_C5_MASK)
#define GPIO_CR1_C6_MASK                         0x40u
#define GPIO_CR1_C6_SHIFT                        6u
#define GPIO_CR1_C6_WIDTH                        1u
#define GPIO_CR1_C6(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C6_SHIFT))&GPIO_CR1_C6_MASK)
#define GPIO_CR1_C7_MASK                         0x80u
#define GPIO_CR1_C7_SHIFT                        7u
#define GPIO_CR1_C7_WIDTH                        1u
#define GPIO_CR1_C7(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR1_C7_SHIFT))&GPIO_CR1_C7_MASK)
/* CR2 Bit Fields */
#define GPIO_CR2_C0_MASK                         0x1u
#define GPIO_CR2_C0_SHIFT                        0u
#define GPIO_CR2_C0_WIDTH                        1u
#define GPIO_CR2_C0(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C0_SHIFT))&GPIO_CR2_C0_MASK)
#define GPIO_CR2_C1_MASK                         0x2u
#define GPIO_CR2_C1_SHIFT                        1u
#define GPIO_CR2_C1_WIDTH                        1u
#define GPIO_CR2_C1(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C1_SHIFT))&GPIO_CR2_C1_MASK)
#define GPIO_CR2_C2_MASK                         0x4u
#define GPIO_CR2_C2_SHIFT                        2u
#define GPIO_CR2_C2_WIDTH                        1u
#define GPIO_CR2_C2(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C2_SHIFT))&GPIO_CR2_C2_MASK)
#define GPIO_CR2_C3_MASK                         0x8u
#define GPIO_CR2_C3_SHIFT                        3u
#define GPIO_CR2_C3_WIDTH                        1u
#define GPIO_CR2_C3(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C3_SHIFT))&GPIO_CR2_C3_MASK)
#define GPIO_CR2_C4_MASK                         0x10u
#define GPIO_CR2_C4_SHIFT                        4u
#define GPIO_CR2_C4_WIDTH                        1u
#define GPIO_CR2_C4(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C4_SHIFT))&GPIO_CR2_C4_MASK)
#define GPIO_CR2_C5_MASK                         0x20u
#define GPIO_CR2_C5_SHIFT                        5u
#define GPIO_CR2_C5_WIDTH                        1u
#define GPIO_CR2_C5(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C5_SHIFT))&GPIO_CR2_C5_MASK)
#define GPIO_CR2_C6_MASK                         0x40u
#define GPIO_CR2_C6_SHIFT                        6u
#define GPIO_CR2_C6_WIDTH                        1u
#define GPIO_CR2_C6(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C6_SHIFT))&GPIO_CR2_C6_MASK)
#define GPIO_CR2_C7_MASK                         0x80u
#define GPIO_CR2_C7_SHIFT                        7u
#define GPIO_CR2_C7_WIDTH                        1u
#define GPIO_CR2_C7(x)                           (((uint32_t)(((uint32_t)(x))<<GPIO_CR2_C7_SHIFT))&GPIO_CR2_C7_MASK)

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


#endif /* end of STM8S103F_H */
