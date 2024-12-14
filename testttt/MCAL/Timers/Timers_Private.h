/*
 * Timers_Private.h
 *
 * Created: 2023-11-13 9:30:30 PM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

#include "../../LIB/Types.h"
#define TIMSK	 *((volatile u8 *)0x59) // Timer/Counter Interrupt Mask Register
#define TIFR	 *((volatile u8 *)0x58) // Timer/Counter Interrupt Flag Register
#define MCUCR	 *((volatile u8 *)0x55) // MCU Control Register

#define MCUCSR   *((volatile u8 *)0x54) // MCU Control and Status Register
#define ISC2 6
/* ASSR */
/* bits 7-4 reserved */
#define ASSR	*((volatile u8 *)0x42) //Asynchronous Status Register
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0
/************************************************************************/
/* timer 0                                                                      */
/************************************************************************/
#define TCCR0		 *((volatile u8 *)0x53) // Timer counter 0 control register
#define TCNT0		 *((volatile u8 *)0x52) // Timer counter 0 8 bit register
#define OCR0		*((volatile u8*)0X5C)	// Timer counter 0 8compare match
/************************************************************************/
/* timer 1                                                                     */
/************************************************************************/
#define ICR1         *((volatile u16 *)0x46)
#define ICR1L		 *((volatile u8  *)0x46)
#define ICR1H		 *((volatile u8  *)0x47)
#define OCR1B		 *((volatile u16 *)0x48)
#define OCR1BL		 *((volatile u8  *)0x48)
#define OCR1BH       *((volatile u8  *)0x49)
#define OCR1A		 *((volatile u16 *)0x4A)
#define OCR1AL		 *((volatile u8  *)0x4A)
#define OCR1AH       *((volatile u8  *)0x4B)
#define TCNT1        *((volatile u16 *)0x4C)
#define TCNT1L		 *((volatile u8  *)0x4C)
#define TCNT1H		 *((volatile u8  *)0x4D)
#define TCCR1B       *((volatile u8  *)0x4E)
#define TCCR1A       *((volatile u8  *)0x4f)
/************************************************************************/
/* timer 2                                                              */
/************************************************************************/
#define OCR2		  *((volatile u8*)0x43)
#define TCNT2		  *((volatile u8*)0x44)
#define TCCR2		  *((volatile u8*)0x45)
/************************************************************************/
/* timer 0 & macros												        */
/************************************************************************/
/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0
/************************************************************************/
/* Timer 0 PRESCALER											        */
/************************************************************************/
#define TM0_NO_CLK			 0x00
#define TM0_PRESCALER_1		 0x01
#define TM0_PRESCALER_8		 0x02
#define TM0_PRESCALER_64	 0x03
#define TM0_PRESCALER_256	 0x04
#define TM0_PRESCALER_1024	 0x05

/************************************************************************/
/*  OC0 Modes										        */
/************************************************************************/
#define OCO_DISCONNECTED			0
#define OCO_TOGGLE					1
#define OC0_NON_INVERTING			2
#define OC0_INVERTING				3
/************************************************************************/
/* Timer 0 MODES												        */
/************************************************************************/
#define TIMER0_NORMAL_MODE		   0
#define TIMER0_PHASE_CORRECT_MODE  1 
#define TIMER0_CTC_MODE            2
#define TIMER0_FASTPWM_MODE        3 
/************************************************************************/
/* timer 1 & macros                                                     */
/************************************************************************/
/* TCCR1A */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0
/* TCCR1B */
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/************************************************************************/
/* timer 2  & macros                                                    */
/************************************************************************/
/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0
/************************************************************************/
/* timer Special function registers  & macros                           */
/************************************************************************/

/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0

/* TIFR */
#define OCF2    7
#define TOV2    6
#define ICF1    5
#define OCF1A   4
#define OCF1B   3
#define TOV1    2
#define OCF0    1
#define TOV0    0
/************************************************************************/
/*                timer macros										    */
/************************************************************************/
#define Timer0 0x01
#define Timer1 0x04
#define Timer2 0x40

#define INT_TIMER2_COMP		__vector_4		// Timer/Counter2 Compare Match */
#define INT_TIMER2_OVF		__vector_5		// Timer/Counter2 Overflow */
#define INT_TIMER1_CAPT		__vector_6		// Timer/Counter1 Capture Event */
#define INT_TIMER1_COMPA	__vector_7		// Timer/Counter1 Compare Match A */
#define INT_TIMER1_COMPB	__vector_8		// Timer/Counter1 Compare Match B */
#define INT_TIMER1_OVF		__vector_9		// Timer/Counter1 Overflow */
#define INT_TIMER0_COMP		__vector_10		// Timer/Counter0 Compare Match */
#define INT_TIMER0_OVFt		__vector_11		// Timer/Counter0 Overflow */
#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal,used))__VA_ARGS__ ; \
void vector (void)
#endif /* TIMERS_PRIVATE_H_ */