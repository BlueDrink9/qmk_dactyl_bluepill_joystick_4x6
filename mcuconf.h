#pragma once

#include_next <mcuconf.h>

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1 TRUE

// Using 3 because my serial pin is TX3
#undef STM32_SERIAL_USE_USART3
#define STM32_SERIAL_USE_USART3 TRUE
