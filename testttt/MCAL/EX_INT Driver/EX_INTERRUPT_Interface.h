/*
 * EX_INTERRUPT.h
 *
 * Created: 2023-09-26 2:22:14 PM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}Edge_trriger;

void EX_INT0_Enable();
void EX_INT1_Enable();
void EX_INT2_Enable();

void EX_INT0_Disable();
void EX_INT1_Disable();
void EX_INT2_Disable();

void EX_INT0_Edge_Detect(Edge_trriger Edge_type);
void EX_INT1_Edge_Detect(Edge_trriger Edge_type);
void EX_INT2_Edge_Detect(Edge_trriger Edge_type);

void EX_INT0_SetCallBack(void(*LocalPtr_callback)(void));
void EX_INT1_SetCallBack(void(*LocalPtr_callback)(void));
void EX_INT2_SetCallBack(void(*LocalPtr_callback)(void));

#endif /* EX_INTERRUPT_H_ */