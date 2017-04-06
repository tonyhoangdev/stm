/**
 ******************************************************************************
 * @file    Project/main.c
 * @author  MCD Application Team
 * @version V2.2.0
 * @date    30-September-2014
 * @brief   Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_clk.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TIM4_PERIOD       125
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
volatile uint32_t TimingDelay = 0;
/* Private function prototypes -----------------------------------------------*/
void TimingDelay_Decrement(void);
void delay(volatile uint32_t time);
static void CLK_Config(void);
static void TIM4_Config(void);
static void GPIO_Config(void);
/* Private functions ---------------------------------------------------------*/

void main(void)
{
    /* Clock configuration -----------------------------------------*/
    CLK_Config();
    /* GPIO configuration -----------------------------------------*/
    GPIO_Config();
    /* TIM4 configuration -----------------------------------------*/
    TIM4_Config();

    /* Infinite loop */
    while (1)
    {
        GPIO_WriteReverse(GPIOB, GPIO_PIN_5);
        delay(600);
    }

}

static void CLK_Config(void)
{
    /* Initialization of the clock */
    /* Clock divider to HSI/1 */
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1);
}

static void TIM4_Config(void)
{
    /* TIM4 configuration:
    - TIM4CLK is set to 16 MHz, the TIM4 Prescaler is equal to 128 so the TIM1 counter
    clock used is 16 MHz / 128 = 125 000 Hz
    - With 125 000 Hz we can generate time base:
    max time base is 2.048 ms if TIM4_PERIOD = 255 --> (255 + 1) / 125000 = 2.048 ms
    min time base is 0.016 ms if TIM4_PERIOD = 1   --> (  1 + 1) / 125000 = 0.016 ms
    - In this example we need to generate a time base equal to 1 ms
    so TIM4_PERIOD = (0.001 * 125000 - 1) = 124 */

    /* Time base configuration */
    TIM4_TimeBaseInit(TIM4_PRESCALER_128, TIM4_PERIOD);
    /* Clear TIM4 update flag */
    TIM4_ClearFlag(TIM4_FLAG_UPDATE);
    /* Enable update interrupt */
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);

    /* enable interrupts */
    enableInterrupts();

    /* Enable TIM4 */
    TIM4_Cmd(ENABLE);
}

static void GPIO_Config(void)
{
    GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
}

void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    {
        TimingDelay--;
    }
}

void delay(volatile uint32_t time)
{
    TimingDelay = time;

    while (TimingDelay != 0);
}

#ifdef USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *   where the assert_param error has occurred.
 * @param file: pointer to the source file name
 * @param line: assert_param error line source number
 * @retval : None
 */
void assert_failed(u8* file, u32 line)
{
    /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while (1)
    {
    }
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
