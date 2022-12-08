/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
uint8_t STATE_Current = 0;
uint8_t STATE_Last = 0;
uint32_t Timer_Debouncing = 0;
uint32_t LED_Timer = 0;
uint8_t LED_Effect = 1;
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  STATE_Current = HAL_GPIO_ReadPin(GPIOA, BUTTON_Pin);
	  if(STATE_Current != STATE_Last)
	  {
		  if(HAL_GetTick() - Timer_Debouncing >= 20)
		  {
			  if(STATE_Current == 1)
			  {
				  HAL_GPIO_WritePin(GPIOC, LED_Button_Pin, 0);
				  if(LED_Effect == 2)
					  LED_Effect = 0;
				  LED_Effect++;
				  GPIOB->ODR = GPIOB->ODR & ~(GPIOB->ODR);
			  }else
			  {
				  HAL_GPIO_WritePin(GPIOC, LED_Button_Pin, 1);
			  }
			  Timer_Debouncing = HAL_GetTick();
			  STATE_Last = STATE_Current;
		  }
	  }

	  switch (LED_Effect) {
		case 1:
			if(HAL_GetTick() - LED_Timer >= 1000)
			{
				LED_Timer = HAL_GetTick();
			}

			if(HAL_GetTick() - LED_Timer < 500)
			{
				GPIOB->ODR = GPIOB->ODR | (0x000001F8); // 0000 0001 1111 1000 -> 0x01F8
			}else
			{
				GPIOB->ODR = GPIOB->ODR & ~(0x000001F8); // -> 0000 0000 0000 0000
			}
			break;

		case 2:
			if(HAL_GetTick() - LED_Timer >= 1800)
			{
				LED_Timer = HAL_GetTick();
			}
			if(HAL_GetTick() - LED_Timer < 300)
			{
				HAL_GPIO_WritePin(GPIOB, LED6_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED1_Pin, 1);
			}else if((HAL_GetTick() - LED_Timer >= 300) && (HAL_GetTick() - LED_Timer < 600))
			{
				HAL_GPIO_WritePin(GPIOB, LED1_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED2_Pin, 1);
			}else if((HAL_GetTick() - LED_Timer >= 600) && (HAL_GetTick() - LED_Timer < 900))
			{
				HAL_GPIO_WritePin(GPIOB, LED2_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED3_Pin, 1);
			}else if((HAL_GetTick() - LED_Timer >= 900) && (HAL_GetTick() - LED_Timer < 1200))
			{
				HAL_GPIO_WritePin(GPIOB, LED3_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED4_Pin, 1);
			}else if((HAL_GetTick() - LED_Timer >= 1200) && (HAL_GetTick() - LED_Timer < 1600))
			{
				HAL_GPIO_WritePin(GPIOB, LED4_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED5_Pin, 1);
			}else if((HAL_GetTick() - LED_Timer >= 1600) && (HAL_GetTick() - LED_Timer < 1800))
			{
				HAL_GPIO_WritePin(GPIOB, LED5_Pin, 0);
				HAL_GPIO_WritePin(GPIOB, LED6_Pin, 1);
			}
			break;

		default:
			break;
	}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_Button_GPIO_Port, LED_Button_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : LED_Button_Pin */
  GPIO_InitStruct.Pin = LED_Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : BUTTON_Pin */
  GPIO_InitStruct.Pin = BUTTON_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(BUTTON_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_Pin LED2_Pin LED3_Pin LED4_Pin
                           LED5_Pin LED6_Pin */
  GPIO_InitStruct.Pin = LED1_Pin|LED2_Pin|LED3_Pin|LED4_Pin
                          |LED5_Pin|LED6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
