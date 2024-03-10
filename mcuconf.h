#pragma once

#include_next <mcuconf.h>

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE

// Using 3 because my serial pin is TX3
#undef STM32_SERIAL_USE_USART3
#define STM32_SERIAL_USE_USART3 TRUE

// For bluepill, A3 is timer 2 so I need to enable that. However, timer 2 is the
// default for other functions on the board, so I need to first change the main timer to 3, to free up timer 2 (and pin A3) for the LED PWM.
#undef STM32_ST_USE_TIMER
#define STM32_ST_USE_TIMER 3
#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE
