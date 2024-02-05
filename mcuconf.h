#pragma once

#include_next <mcuconf.h>

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE

// Using 2 because my serial pin is TX2
#undef STM32_SERIAL_USE_USART2
#define STM32_SERIAL_USE_USART2 TRUE
