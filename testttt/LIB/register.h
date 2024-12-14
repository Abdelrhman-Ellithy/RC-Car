/*
 * register.h
 *
 * Created: 2023-07-12 6:09:29 PM
 *  Author: Abdelrahman Ellithy
 */ 

#ifndef REGISTER_H_
#define REGISTER_H_

/************************************************************************/
/* typedefs for this file                                                                     */
/************************************************************************/
#include "Types.h"
/************************************************************************/
/*          Definition For Group A 									    */
/************************************************************************/
#define PORTA  	    (((volatile Register*)0x3B)->ByteAccess)
#define DDRA    	(((volatile Register*)0x3A)->ByteAccess)
#define PINA        (((volatile Register*)0x39)->ByteAccess)
/************************************************************************/
/*          Definition For Group B									    */
/************************************************************************/
#define PORTB   (((volatile Register*)0x38)->ByteAccess)
#define DDRB    (((volatile Register*)0x37)->ByteAccess)
#define PINB    (((volatile Register*)0x36)->ByteAccess)
/************************************************************************/
/*          Definition For Group C									   */
/************************************************************************/
#define PORTC   (((volatile Register*)0x35)->ByteAccess)
#define DDRC    (((volatile Register*)0x34)->ByteAccess)
#define PINC    (((volatile Register*)0x33)->ByteAccess)
/************************************************************************/
/*          Definition For Group D									   */
/************************************************************************/
#define PORTD   (((volatile Register*)0x32)->ByteAccess)
#define DDRD    (((volatile Register*)0x31)->ByteAccess)
#define PIND    (((volatile Register*)0x30)->ByteAccess)
/************************************************************************/
/*   Special function Registers                                                                   */
/************************************************************************/
#define SFIOR (((volatile Register*)0x50)->ByteAccess) // Special Function I/O Register
#define SREG  (((volatile Register*)0x5F)->ByteAccess) // AVR Status Register
#define OCR0  (((volatile Register*)0x5C)->ByteAccess) // output compare reg timer 0
#define GICR  (((volatile Register*)0x5B)->ByteAccess) // general interrupt control register
#define GIFR  (((volatile Register*)0x5A)->ByteAccess) // general interrupt flag register
#define PUD 2
#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal,used))__VA_ARGS__ ; \
void vector (void)


#define TIMSK	 (((volatile Register*)0x59)->ByteAccess) // Timer/Counter Interrupt Mask Register
#define TIFR	 (((volatile Register*)0x58)->ByteAccess) // Timer/Counter Interrupt Flag Register
#define MCUCR	 (((volatile Register*)0x55)->ByteAccess) // MCU Control Register

#define MCUCSR   (((volatile Register*)0x54)->ByteAccess) // MCU Control and Status Register
#define ISC2 6
/* ASSR */
/* bits 7-4 reserved */
#define ASSR (((volatile Register*)0x42)->ByteAccess) //Asynchronous Status Register 
#define AS2     3
#define TCN2UB  2
#define OCR2UB  1
#define TCR2UB  0
/************************************************************************/
/* timer 0                                                                      */
/************************************************************************/
#define TCCR0 (((volatile Register*)0x53)->ByteAccess) // Timer counter 0 control register
#define TCNT0 (((volatile Register*)0x52)->ByteAccess) // Timer counter 0 8 bit register
/************************************************************************/
/* timer 1                                                                     */
/************************************************************************/
#define ICR1         ((volatile  u16 *)0x46)
#define ICR1L		 (((volatile Register*)0x46)->ByteAccess)
#define ICR1H		 (((volatile Register*)0x47)->ByteAccess)
#define OCR1B		 ((volatile	 u16 *)0x48)
#define OCR1BL		 (((volatile Register*)0x48)->ByteAccess)
#define OCR1BH       (((volatile Register*)0x49)->ByteAccess)
#define OCR1A		 ((volatile  u16 *)0x4A)
#define OCR1AL		 (((volatile Register*)0x4A)->ByteAccess)
#define OCR1AH       (((volatile Register*)0x4B)->ByteAccess)
#define TCNT1        ((volatile  u16 *)0x4C)
#define TCNT1L		 (((volatile Register*)0x4C)->ByteAccess)
#define TCNT1H		 (((volatile Register*)0x4D)->ByteAccess)
#define TCCR1B       (((volatile Register*)0x4E)->ByteAccess)
#define TCCR1A       (((volatile Register*)0x4f)->ByteAccess)
/************************************************************************/
/* timer 2                                                              */
/************************************************************************/
#define OCR2      (((volatile Register*)0x43)->ByteAccess)
#define TCNT2     (((volatile Register*)0x44->ByteAccess)
#define TCCR2     (((volatile Register*)0x45)->ByteAccess)
/************************************************************************/
/* ADC_Registers                                                         */
/************************************************************************/ 
#define ADMUX (((volatile Register*)0x27)->ByteAccess) // ADC Multiplexer Selection Register
#define ADLAR 5
#define REFS0 6
#define REFS1 7

#define ADCSRA (((volatile Register*)0x26)->ByteAccess) // ADC Control and Status Register A
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7
#define ADCL (((volatile Register*)0x24)->ByteAccess) // The ADC Data lower Register 
#define ADCH (((volatile Register*)0x25)->ByteAccess) // The ADC Data higher Register
/************************************************************************/
/*     WDTCR Watchdog Timer Control Register                            */
/************************************************************************/ 
#define WDTCR    (((volatile Register*)0x41)->ByteAccess)
/* bits 7-5 reserved */
#define WDTOE   4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0
/************************************************************************/
/* USART  REgisters and Macros                                          */
/************************************************************************/
#define	   UBRRL     (((volatile Register*)0x29)->ByteAccess)	/* USART Baud Rate Register Low */
#define	   UCSRA     (((volatile Register*)0x2B)->ByteAccess)	/* USART Control and Status Register A */
#define    RXC          7 /* USART Status Register A  */
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0
#define UCSRB     (((volatile Register*)0x2A)->ByteAccess)	/* USART Control and Status Register B */
#define    RXCIE        7 /* USART Control Register B  */
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0
#define		UDR       (((volatile Register*)0x2C)->ByteAccess)	/* USART I/O Data Register */
#define		UBRRH     (((volatile Register*)0x40)->ByteAccess)	/* USART Baud Rate Register High */
#define 	UCSRC     (((volatile Register*)0x40)->ByteAccess)	/* USART Control and Status Register C */
#define	   URSEL		7/* USART Register C */
#define    UMSEL        6 
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0
/************************************************************************/
/* SPI                                                                   */
/************************************************************************/ 
#define	   SPCR       (((volatile Register*)0x2D)->ByteAccess) /* SPI Control Register */
#define    SPIE         7		/* SPI Control Register - SPCR */
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0
#define	   SPSR       (((volatile Register*)0x2E)->ByteAccess) /* SPI Status Register */
#define    SPIF         7 /* SPI Status Register - SPSR */
#define    WCOL         6
#define    SPI2X        0
#define	   SPDR       (((volatile Register*)0x2F)->ByteAccess) /* SPI I/O Data Register */
/************************************************************************/
/*               EEPROM	                                               */
/************************************************************************/
#define EECR	(((volatile Register*)0x3C)->ByteAccess)/* EEPROM Control Register */
#define EEDR	(((volatile Register*)0x3D)->ByteAccess)/* EEPROM Data Register */
#define EEAR	(*(volatile u16 *)0x3E)/* EEPROM Address Register */
#define EEARL	(((volatile Register*)0x3E)->ByteAccess)
#define EEARH	(((volatile Register*)0x3F)->ByteAccess)

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
#define TWBR    (((volatile Register*)0x20)->ByteAccess)
#define TWSR    (((volatile Register*)0x21)->ByteAccess)
#define TWAR    (((volatile Register*)0x22)->ByteAccess)
#define TWDR    (((volatile Register*)0x23)->ByteAccess)
/************************************************************************/
/* interrupt vectors                                                                     */
/************************************************************************/


#define INT_SPI_STC			__vector_12		// Serial Transfer Complete */
#define INT_USART_RXC		__vector_13		//USART, Rx Complete */
#define INT_USART_UDRE		__vector_14		// USART Data Register Empty */
#define INT_USART_TXC		__vector_15 	// USART, Tx Complete */
#define INT_EE_RDY			__vector_17 	// EEPROM Ready
#define INT_ANA_COMP		__vector_18		// Analog Comparator */
#define INT_TWI				__vector_19		// 2-wire Serial Interface */
#define INT_SPM_RDY			__vector_20 	// Store Program Memory Ready */


#endif /* REGISTER_H_ */