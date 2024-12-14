/*
 * Timers_Config.h
 *
 * Created: 2023-09-11 8:00:26 AM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_
#include "Timers_Private.h"

#define TM0_prescaler TM0_PRESCALER_1
#define TM0_mode TIMER0_PHASE_CORRECT_MODE
#define TM0_TCNT_preload 0x00
#define TM0_OC_Mode  OC0_NON_INVERTING
#define TM0_OC0_preload 0x00
 
#endif /* TIMERS_CONFIG_H*/