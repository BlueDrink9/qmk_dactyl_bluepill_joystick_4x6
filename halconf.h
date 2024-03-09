// For joystick
#pragma once

#define HAL_USE_ADC TRUE
#define HAL_USE_SERIAL TRUE

#define PAL_USE_CALLBACKS TRUE
#define PAL_USE_WAIT TRUE

#define HAL_USE_PWM TRUE

#include_next <halconf.h>
