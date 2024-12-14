/************************************************************************/
/*      * DIO.c										**********************
* Created: 2023-07-12 6:59:50 PM					*********************
*  Author: Abdelrahman Ellithy								            */
/************************************************************************/
#include "../../LIB/BIT_OPERATIONS.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"

void DIO_PIN_init( GPIO_PORT* portname ,u8 pinnumber , u8 drirection ){
	
		
		if (drirection==DIO_PIN_OUTPUT)
		{
			SET_BIT(*(portname->DDR),pinnumber);
		}
		else if (drirection==DIO_PIN_INPUT)
		{
			CLEAR_BIT(*(portname->DDR),pinnumber);
		}
		
	
}
void DIO_PORT_init(  GPIO_PORT* portname , u8 drirection ){
	
		if (drirection==DIO_PORT_OUTPUT)
		{
			SET_REG(*(portname->DDR));
		}
		else if (drirection==DIO_PORT_INPUT)
		{
			CLEAR_REG(*(portname->DDR));
		}
		
}
void DIO_PORT_bits_init(  GPIO_PORT* portname , u8 bits ){
		WRITE_REG(*(portname->DDR),bits);		
}

void DIO_PIN_write(  GPIO_PORT* portname ,u8 pinnumber , u8 value ){
	

		if (value==DIO_PIN_HIGH)
		{
			SET_BIT(*(portname->PORT),pinnumber);
			
		}
		else if (value==DIO_PIN_LOW)
		{
			CLEAR_BIT(*(portname->PORT),pinnumber);
		}
		
	
}
void DIO_PORT_write(  GPIO_PORT* portname , u8 value ){
			WRITE_REG(*(portname->PORT),value);		
}
void DIO_PORT_write_bits(  GPIO_PORT* portname , u8 bits ){
			CLEAR_bits(*(portname->PORT),bits);
			Set_bits(PORTA,bits);
}
void DIO_PIN_read(  GPIO_PORT* portname ,u8 pinnumber , u8 * value){

		*value = ((*(portname->PIN))&(1<<pinnumber) );		
	
}
void DIO_PORT_read(  GPIO_PORT* portname , u8 * value){
			 GET_REG(*(portname->PIN),*value);		
}

void DIO_PIN_toggle(  GPIO_PORT* portname ,u8 pinnumber ){
		TOGGLE_BIT(*(portname->PORT),pinnumber);
}
void DIO_PORT_toggle( GPIO_PORT* portname ){
		TOGGLE_REG(*(portname->PORT));
}
void DIO_voidWriteHighNibbles( GPIO_PORT* portname ,u8 Copy_u8value)
{
			Copy_u8value = (Copy_u8value<<4) ;
			CLEAR_High_nipple(*(portname->PORT));                   // make sure the high bits = 0000
			*(portname->PORT)|=Copy_u8value;			//Set only the high nibble of the port A by the given value
}
void DIO_voidWriteLowNibbles( GPIO_PORT* portname ,u8 Copy_u8value)
{
		Copy_u8value&=0x0f;
			CLEAR_low_nipple(*(portname->PORT));                 //Set only the high nibble of the port A by the given value
			*(portname->PORT) |= Copy_u8value;	
}
