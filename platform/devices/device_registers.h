#ifndef DEVICE_REGISTERS_H
#define DEVICE_REGISTERS_H

/*
 * Include the cpu specific register header files.
 *
 * The CPU macro should be declared in the project or makefile.
 */

#if (defined(STM8S103F3P) || defined(STM8S103F3))
    #define STM8S103F_SERIES

    /* Register definitions */
    #include "STM8S103F/include/STM8S103F.h"

#elif (defined(STM8S003F3P) || defined(STM8S003F3))
    #define STM8S003F_SERIES

    /* Register definitions */
    #include "STM8S003F/include/STM8S003F.h"

#else
    #error "No valid CPU defined!"
#endif

#endif /* DEVICE_REGISTERS_H */
/*******************************************************************************
 * EOF
 ******************************************************************************/
