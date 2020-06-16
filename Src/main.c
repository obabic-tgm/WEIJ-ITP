/**
  ******************************************************************************
  * @file    GPIO/GPIO_EXTI/Src/main.c 
  * @author  MCD Application Team
  * @brief   This example describes how to configure and use GPIOs through 
  *          the STM32F4xx HAL API.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @addtogroup GPIO_EXTI
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void EXTILine0_Config(void);
static void EXTILine4_Config(void);

/* DKupert-Methoden */
static void sendSignal(int);




/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */

int status = 0;

int main(void)
{
 /* This sample code shows how to use STM32F4xx GPIO HAL API to toggle PD12, PD13,
    PD14, and PD14 IOs (connected to LED4, LED3, LED5 and LED6 on STM32F401C-DISCO board (MB1115B)) 
    in an infinite loop.
    To proceed, 3 steps are required: */

  /* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
     */
  HAL_Init();
 
  /* Configure LED3, LED4, LED5 and LED6 */
  BSP_LED_Init(LED3);
  BSP_LED_Init(LED4);
  BSP_LED_Init(LED5);
  BSP_LED_Init(LED6);

  /* Configure the system clock to 168 MHz */
  SystemClock_Config();
  
  /* Configure EXTI Line0 (connected to PA0 pin) in interrupt mode */
  EXTILine0_Config();  
  EXTILine4_Config();

  /* Infinite loop */
	/* ROT PIN5*/
	/* GELB PIN6*/
	/* GRÜN PIN7*/
  while (1){

    if(status == 0){
		  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);  
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
    }else{
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);  
      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
    }

/*
    //Rot
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET);
		for(int i = 0; i < 200; i++){
			sendSignal(1);
		}
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
		for(int i = 0; i < 200; i++){
			sendSignal(3);
		}
		/* HAL_NVIC_SystemReset();*/
		
		/*
		for(int  i = 0; i < 4; i++){
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
			for(int i = 0; i < 50; i++){
				sendSignal(4);
			}
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_SET);
			for(int i = 0; i < 50; i++){
				sendSignal(4);
			}
		}

		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, GPIO_PIN_RESET);
  */
		/*
		LED5 = ROT
		LED3 = GELB
		LEC4 = GRÜN

		BSP_LED_Toggle(LED5);
		HAL_Delay(5000);
		BSP_LED_Toggle(LED3);
		HAL_Delay(3000);
		BSP_LED_Toggle(LED5);
		BSP_LED_Toggle(LED3);
		BSP_LED_Toggle(LED4);
		HAL_Delay(4000);
		for(int  i = 0; i < 4; i++){

			BSP_LED_Toggle(LED4);
			HAL_Delay(1000);
		}
		BSP_LED_Toggle(LED4);
		*/

	
	}

}


static void sendSignal(int colorCode){
HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);

	switch(colorCode){
		case 1:
			for(int i = 0; i < 3; i++){
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
							
			}
		break;
		case 2:
			for(int i = 0; i < 2; i++){
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
							
			}
			
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
		break;
		case 3:
			for(int i = 0; i < 2; i++){
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
				HAL_Delay(5);
				HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
							
			}
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
		break;
		case 4:
			
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
			
		break;
		case 5:
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET); 
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
			HAL_Delay(5);
			HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
		break;
	}
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 168000000
  *            HCLK(Hz)                       = 168000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 8000000
  *            PLL_M                          = 8
  *            PLL_N                          = 336
  *            PLL_P                          = 2
  *            PLL_Q                          = 7
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 5
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable Power Control clock */
  __HAL_RCC_PWR_CLK_ENABLE();
  
  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

  /* STM32F405x/407x/415x/417x Revision Z devices: prefetch is supported  */
  if (HAL_GetREVID() == 0x1001)
  {
    /* Enable the Flash prefetch */
    __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
  }
}

/**
  * @brief  Configures EXTI Line0 (connected to PA0 pin) in interrupt mode
  * @param  None
  * @retval None
  */
static void EXTILine0_Config(void)
{
  GPIO_InitTypeDef   GPIO_InitStructure;

  /* Enable GPIOA clock */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  
  /* Configure PA0 pin as input floating */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = GPIO_PIN_0;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);



/*
	GPIO_InitStructure.Pin = GPIO_PIN_12;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
*/
	/* DKupert */

	GPIO_InitStructure.Pin = GPIO_PIN_5;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	GPIO_InitStructure.Pin = GPIO_PIN_6;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_7;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_NOPULL;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_15;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_InitStructure.Pin = GPIO_PIN_2;
	GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Speed = GPIO_SPEED_FAST;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

}

static void EXTILine4_Config(void)
{
  GPIO_InitTypeDef   GPIO_InitStructure;

  /* Enable GPIOA clock */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  
  /* Configure PA0 pin as input floating */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  GPIO_InitStructure.Pin = GPIO_PIN_4;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* Enable and set EXTI Line0 Interrupt to the lowest priority */
  HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}
/**
  * @brief EXTI line detection callbacks
  * @param GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

  if(status == 0){
    status = 1;
  }else{
    status = 0;
  }


}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* Turn LED5 on */
  BSP_LED_On(LED5);
  while(1)
  {
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

