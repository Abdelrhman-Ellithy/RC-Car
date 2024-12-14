/*
 * DIO_Interface.h
 *
 * Created: 2023-11-10 10:11:41 AM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
 
#include "../../LIB/Types.h"
typedef struct{
	volatile u8*DDR;
	volatile u8*PORT;
	volatile u8*PIN;
}GPIO_PORT;
static GPIO_PORT PORT_A={((volatile u8*)0x3A),((volatile u8*)0x3B),((volatile u8*)0x39)}
				,PORT_B={((volatile u8*)0x37),((volatile u8*)0x38),((volatile u8*)0x36)}
				,PORT_C={((volatile u8*)0x34),((volatile u8*)0x35),((volatile u8*)0x33)}
				,PORT_D={((volatile u8*)0x31),((volatile u8*)0x32),((volatile u8*)0x30)};

 // Port Defines
#define  DIO_PORTA  &PORT_A
#define  DIO_PORTB  &PORT_B
#define  DIO_PORTC  &PORT_C
#define  DIO_PORTD  &PORT_D


 // PIN Defines
#define DIO_PIN0   0
#define DIO_PIN1   1
#define DIO_PIN2   2
#define DIO_PIN3   3
#define DIO_PIN4   4
#define DIO_PIN5   5
#define DIO_PIN6   6
#define DIO_PIN7   7


 // PIN Directions
#define DIO_PIN_OUTPUT		1
#define DIO_PIN_INPUT	    0

 // PIN Value Options
#define DIO_PIN_HIGH		1
#define DIO_PIN_LOW			0

 // PORT Directions
#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0x00

#define DIO_PORT_HIGH      0xFF
#define DIO_PORT_LOW       0x00

/************************************************************************/
/* define  functions											    */
/************************************************************************/
void DIO_PIN_init( GPIO_PORT* portname ,u8 pinnumber , u8 drirection );
void DIO_PORT_init( GPIO_PORT*portname , u8 drirection );
void DIO_PORT_bits_init( GPIO_PORT*portname , u8 bits );

void DIO_PIN_write( GPIO_PORT* portname ,u8 pinnumber , u8 value );
void DIO_PORT_write( GPIO_PORT* portname , u8 value );
void DIO_low_Nipple_write( GPIO_PORT* portname , u8 bits );
void DIO_high_Nipple_write( GPIO_PORT* portname, u8 bits );

void DIO_PIN_read( GPIO_PORT* portname ,u8 pinnumber , u8 * value);
void DIO_PORT_read( GPIO_PORT* portname , u8 * value);

void DIO_PIN_toggle( GPIO_PORT* portname ,u8 pinnumber );
void DIO_PORT_toggle( GPIO_PORT* portname );

#endif /* DIO_INTERFACE_H_ */