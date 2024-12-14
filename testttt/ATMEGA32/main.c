/*
 ***** testttt.c
 ****
 * Created: 2023-11-15 10:53:33 PM
 * Author : lenovo
 ****
 **
 */ 
#define F_CPU 8000000UL
#include "LIB/Types.h"
#include "LIB/BIT_OPERATIONS.h"
#include "MCAL/DIO Driver/DIO_Interface.h"
#include "MCAL/PORT Driver/PORT_interface.h"
#include "MCAL/EX_INT Driver/EX_INTERRUPT_Interface.h"
#include "MCAL/UART Driver/UART_Interface.h"
#include "HAL/DC Motor/DCMOTOR_Interface.h"
#include "MCAL/Timers/Timers_Interface.h"
#define Forward			 1
#define Forward_left	 2
#define Forward_Right	 3
#define Backword		 4
#define Backword_left	 5
#define Backword_Right  6
#define Stop			 7
#define Right			 8
#define Left			 9
#define Limit			 10
#define Thereisobsticale 1
#define NOobsticale		 2
volatile u8 UART_Data;
volatile u8 IR_ForwardRead,IR_BackwordRead ,flag_IR_f=0, flag_IR_B=0;
volatile u8 CurState=0xff,OldState=0xff;
DCMOTOR Front_Motor={DIO_PORTB, DIO_PIN0, DIO_PIN1, DCMOTOR_STOP},
		BackMotor  ={DIO_PORTC, DIO_PIN0, DIO_PIN1, DCMOTOR_STOP};
void UART_Fun(){
	//if(UART_Data>0 && UART_Data < Limit ){
			if (CurState==UART_Data){
				OldState=CurState;
			}
			else {
				switch(UART_Data){
					case Forward :
						if(IR_ForwardRead==Thereisobsticale){
							OldState=CurState;
							CurState=Stop;
						}
						else{
							OldState=CurState;
							CurState=Forward;
						}
						break;
					case Forward_left :
						if(IR_ForwardRead==Thereisobsticale){
							OldState=CurState;
							CurState=Stop;
						}
						else{
							OldState=CurState;
							CurState=Forward_left;
						}
						break;
					case Forward_Right :
						if(IR_ForwardRead==Thereisobsticale){
							OldState=CurState;
							CurState=Stop;
						}
						else{
							OldState=CurState;
							CurState=Forward_Right;
						}
						break;
					case Backword :
						if(IR_BackwordRead==Thereisobsticale){
							OldState=CurState;
							CurState=Stop;
						}
						else{
							OldState=CurState;
							CurState=Backword;
						}
						break;
					case Backword_Right :
						if(IR_BackwordRead==Thereisobsticale){
							OldState=CurState;
							CurState=Stop;
						}
						else{
							OldState=CurState;
							CurState=Backword_Right;
						}
						break;
					case Backword_left :
						if(IR_BackwordRead==Thereisobsticale){
							OldState=CurState;
							CurState=Stop;
						}
						else{
							OldState=CurState;
							CurState=Backword_left;
						}
						break;
					case Right :
						OldState=CurState;
						CurState=Right;
						break;
					case Left :
					OldState=CurState;
					CurState=Left;
					break;
				}
			}
				
	//}
}
void Move_Fowrad(void){
	Front_Motor.State=DCMOTOR_STOP;
	DCMOTOR_Control(&Front_Motor);
	BackMotor.State=DCMOTOR_FW;
	DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0);
	//	Timer0_VoidOC0setload(255);
}
void Move_FowradRight(void){
		Front_Motor.State=DCMOTOR_FW;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_FW;
		DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0);
	//	Timer0_VoidOC0setload(179);
}
void Move_Fowradleft(void){
		Front_Motor.State=DCMOTOR_BK;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_FW;
		DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0);
	//	Timer0_VoidOC0setload(179);
}
void Move_Backword(void){
		Front_Motor.State=DCMOTOR_STOP;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_BK;
		DCMOTOR_Control(&BackMotor);
	Timer1_VoidPWMset(0);
	//	Timer0_VoidOC0setload(255);
}
void Move_BackwordRight(void){
		Front_Motor.State=DCMOTOR_FW;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_BK;
		DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0);
	//	Timer0_VoidOC0setload(179);
}
void Move_Backwordleft(void){
		Front_Motor.State=DCMOTOR_BK;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_BK;
		DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0);
	//	Timer0_VoidOC0setload(179);
}
void Turn_Left(void){
		Front_Motor.State=DCMOTOR_BK;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_FW;
		DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0);
	//   Timer0_VoidOC0setload(0);
}
void Turn_Right(void){
		Front_Motor.State=DCMOTOR_FW;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_FW;
		DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0); 
	//Timer0_VoidOC0setload(0);
}
void Do_not_Move(void){
		Front_Motor.State=DCMOTOR_STOP;
		DCMOTOR_Control(&Front_Motor);
		BackMotor.State=DCMOTOR_FW;
		DCMOTOR_Control(&BackMotor);
		Timer1_VoidPWMset(0);
	//	Timer0_VoidOC0setload(0);
}

void IR_Forward_fun(){
	if(flag_IR_f==0){
		EX_INT0_Edge_Detect(RISING_EDGE);
		IR_ForwardRead=Thereisobsticale;
		flag_IR_f=1;
	}
	else if(flag_IR_f==1){
		EX_INT0_Edge_Detect(FALLING_EDGE);
		IR_ForwardRead=NOobsticale;
		flag_IR_f=0;
	}
}
void IR_backword_fun(){
	if(flag_IR_B==0){
		EX_INT0_Edge_Detect(RISING_EDGE);
		IR_BackwordRead=Thereisobsticale;
		flag_IR_B=1;
	}
	else if(flag_IR_B==1){
		EX_INT0_Edge_Detect(FALLING_EDGE);
		IR_BackwordRead=NOobsticale;
		flag_IR_B=0;
	}
}
int main(void)
{
    PORT_voidInit();
	UART_RX_SetCallBack(UART_Fun);
	UART_Init();
	UART_RX_InterruptEnable();
	EX_INT0_Edge_Detect(FALLING_EDGE);
	EX_INT0_SetCallBack(IR_Forward_fun);
	EX_INT1_Edge_Detect(FALLING_EDGE);
	EX_INT1_SetCallBack(IR_backword_fun);
	EX_INT0_Enable();
	EX_INT1_Enable();
	Timer1_VoidTopOCRAset(500);
	Timer1_Init_PostBuild(TIMER1_PHASECORRECT_OCRA_TOP_MODE,TIMER1_SCALER_8,OCRA_DISCONNECTED,OCRB_NON_INVERTING);
	//Timer0_InitPreBuild();
	flag_IR_f=0, flag_IR_B=0;
	sei();
    while (1) 
    {
		switch(CurState){
			case Forward :
				Move_Fowrad();
				break;
			case Forward_left :
				Move_Fowradleft();
				break;
			case Forward_Right :
				Move_FowradRight();
				break;
			case Backword :
				Move_Backword();
				break;
			case Backword_Right :
				Move_BackwordRight();
				break;
			case Backword_left :
				Move_Backwordleft();
				break;
			case Right :
				Turn_Right();
				break;
			case Left :
				Turn_Left();
				break;
		}
    }
}