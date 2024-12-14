/*
 * UART_Private.h
 *
 * Created: 2023-12-08 1:05:10 AM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "../../LIB/Types.h"


const u16 BaudRateArray[TOTAL_SPEED_MODE][TOTAL_CPU_F][TOTAL_BAUD_RATE]=
{{{103, 51, 25, 16, 12,  8},{207,103, 51, 34, 25, 16},{416,207,103, 68 ,51, 34}},
{{207,103, 51, 34, 25, 16},{416,207,103, 68 ,51, 34},{832,416,207,138,103, 68}}};
	

/************************************************************************/
/* USART  REgisters and Macros                                          */
/************************************************************************/

#define	   UBRRL     *((volatile u8*)0x29)	/* USART Baud Rate Register Low */
#define	   UCSRA     *((volatile u8*)0x2B)	/* USART Control and Status Register A */
#define    RXC          7 /* USART Status Register A  */
#define    TXC          6
#define    UDRE         5
#define    FE           4
#define    DOR          3
#define    UPE          2
#define    U2X          1
#define    MPCM         0
#define    UCSRB      *((volatile u8*)0x2A)	/* USART Control and Status Register B */
#define    RXCIE        7 /* USART Control Register B  */
#define    TXCIE        6
#define    UDRIE        5
#define    RXEN         4
#define    TXEN         3
#define    UCSZ         2
#define    UCSZ2        2
#define    RXB8         1
#define    TXB8         0
#define	   UDR       *((volatile u8*)0x2C)	/* USART I/O Data Register */
#define	   UBRRH     *((volatile u8*)0x40)	/* USART Baud Rate Register High */
#define    UCSRC     *((volatile u8*)0x40)	/* USART Control and Status Register C */
#define	   URSEL		7/* USART Register C */
#define    UMSEL        6
#define    UPM1         5
#define    UPM0         4
#define    USBS         3
#define    UCSZ1        2
#define    UCSZ0        1
#define    UCPOL        0

#define INT_USART_RXC		__vector_13		// USART, Rx Complete */
#define INT_USART_UDRE		__vector_14		// USART Data Register Empty */
#define INT_USART_TXC		__vector_15 	// USART, Tx Complete */

#define ISR(vector,...)            \
void vector (void) __attribute__ ((signal,used))__VA_ARGS__ ; \
void vector (void)

#endif /* UART_PRIVATE_H_ */