/*
 * EX_INTERRUPT.c
 *
 * Created: 2023-09-26 2:23:07 PM
 *  Author: lenovo
 */ 

#include "../../LIB/BIT_OPERATIONS.h"
#include "EX_INTERRUPT_Private.h"
#include "EX_INTERRUPT_Interface.h"

static void (*INT0_Fptr_callback) (void)=NULLPTR;
static void (*INT1_Fptr_callback) (void)=NULLPTR;
static void (*INT2_Fptr_callback) (void)=NULLPTR;

void EX_INT0_Enable(){
	SET_BIT(GICR,INT0);
}
void EX_INT1_Enable(){
	SET_BIT(GICR,INT1);
}
void EX_INT2_Enable(){
	SET_BIT(GICR,INT2);
}

void EX_INT0_Disable(){
	CLEAR_BIT(GICR, INT0);
}
void EX_INT1_Disable(){
	CLEAR_BIT(GICR, INT0);
}
void EX_INT2_Disable(){
	CLEAR_BIT(GICR, INT0);
}

void EX_INT0_Edge_Detect(Edge_trriger Edge_type){
		MASK_REG(GICR,0xFC);
		GICR|=Edge_type;
}

void EX_INT1_Edge_Detect(Edge_trriger Edge_type){
	MASK_REG(GICR,0xF3);
	GICR|= (Edge_type<<2);
}

void EX_INT2_Edge_Detect(Edge_trriger Edge_type){
	switch(Edge_type){
		case RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
		default:
			CLEAR_BIT(MCUCSR,ISC2);
	}
}

void EX_INT0_SetCallBack(void(*LocalPtr_callback)(void)){
	INT0_Fptr_callback=LocalPtr_callback;
}
void EX_INT1_SetCallBack(void(*LocalPtr_callback)(void)){
	INT1_Fptr_callback=LocalPtr_callback;
}
void EX_INT2_SetCallBack( void(*LocalPtr_callback)(void) ){
	INT2_Fptr_callback=LocalPtr_callback;
}

ISR(EX_INT0_vect)
{
	if(INT0_Fptr_callback!=NULLPTR){
		INT0_Fptr_callback();
	}
}
ISR(EX_INT1_vect)
{
	if(INT1_Fptr_callback!=NULLPTR){
		INT1_Fptr_callback();
	}
}
ISR(EX_INT2_vect)
{
	if(INT2_Fptr_callback!=NULLPTR){
		INT2_Fptr_callback();
	}
}
