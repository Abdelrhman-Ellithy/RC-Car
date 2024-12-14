/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Timers.c>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Created: 2023-07-22 5:03:16 PM
 *  Author: Abdelrhman Ellithy
 */ 

#include "../../LIB/BIT_OPERATIONS.h"
#include "Timers_Interface.h"
#include "Timers_Config.H"
#include "Timers_Private.h"

static void (*TM0_OV_Fptr_callback)     (void)=NULLPTR;
static void (*TM0_OCO_Fptr_callback)    (void)=NULLPTR;
static void (*Timer1_OVF_Fptr_callback) (void)=NULLPTR;
static void (*Timer1_OCA_Fptr_callback) (void)=NULLPTR;
static void (*Timer1_OCB_Fptr_callback) (void)=NULLPTR;
static void (*Timer1_ICU_Fptr_callback) (void)=NULLPTR;
void Timer0_InitPreBuild(void){
				#if TM0_mode== TIMER0_NORMAL_MODE
									// mode 0
						CLEAR_BIT(TCCR0 , WGM01);
						CLEAR_BIT(TCCR0 , WGM00); 
					
					
				#elif TM0_mode== TIMER0_PHASE_CORRECT_MODE
									// mode 1
						CLEAR_BIT(TCCR0 , WGM01);
						SET_BIT(TCCR0 , WGM00);
						
						
					
				#elif TM0_mode==TIMER0_CTC_MODE 
								// mode 2
						SET_BIT(TCCR0 , WGM01);
						CLEAR_BIT(TCCR0 , WGM00);
					

					
				#elif TM0_mode== TIMER0_FASTPWM_MODE 
								// mode 3 
							SET_BIT(TCCR0, WGM01);
							SET_BIT(TCCR0 , WGM00);
		
				#else
					#error "Incorrect Timer0 mode"
				#endif
				
				#if	TM0_OC_Mode ==OCO_DISCONNECTED
				
					CLEAR_BIT(TCCR0 , COM01);
					CLEAR_BIT(TCCR0 , COM00);
					
				#elif	TM0_OC_Mode ==OCO_TOGGLE
					CLEAR_BIT(TCCR0 , COM01);
					SET_BIT(TCCR0 , COM00);
					
				#elif TM0_OC_Mode == OC0_NON_INVERTING
					SET_BIT(TCCR0, COM01);
					CLEAR_BIT(TCCR0, COM00);
					
				#elif TM0_OC_Mode == OC0_INVERTING
					SET_BIT(TCCR0, COM01);
					SET_BIT(TCCR0, COM00);
				
				#else
					#error "Incorrect Output compare Timer0 mode"
				#endif
				TCNT0 = TM0_TCNT_preload;
				OCR0 = TM0_OC0_preload;
}

void Timer0_Init_PostBuild( Timer0Mode_type mode,Timer0Scaler_type scaler ,OC0Mode_type oc_mode)
{
	switch (mode)
	{
		case TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_PHASECORRECT_MODE:
		SET_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		break;
		case TIMER0_CTC_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
		case TIMER0_FASTPWM_MODE:
		SET_BIT(TCCR0,WGM00);
		SET_BIT(TCCR0,WGM01);
		break;
	}

	TCCR0&=0XF8;
	TCCR0|=scaler;

	switch (oc_mode)
	{
		case OCO_DISCONNECTED:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OCO_TOGGLE:
		SET_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		break;
		case OCO_NON_INVERTING:
		CLEAR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
		case OCO_INVERTING:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);
		break;
	}
	

}
void Timer0_Run(void){
	TCCR0 &= 0xF8 ;
	TCCR0 |= TM0_prescaler;
}
void Timer0_stop(void ){
	TCCR0 &= 0xF8 ;	
}
void Timer0_OV_InterruptEnable(void){
	SET_BIT(TIMSK,TOIE0);
}
void Timer0_OV_InterruptDisable(void){
	CLEAR_BIT(TIMSK,TOIE0);
}
void Timer0_OC_InterruptEnable(void){
	SET_BIT(TIMSK,OCIE0);
}
void Timer0_OC_InterruptDisable(void){
	CLEAR_BIT(TIMSK,OCIE0);
}
void TIMER0_OVFt_SetCallBack(void(*LocalPtr)(void)){
	TM0_OV_Fptr_callback=LocalPtr;
}
void TIMER0_COMP_SetCallBack(void(*LocalPtr)(void)){
	TM0_OCO_Fptr_callback=LocalPtr;
}
void Timer0_VoidOC0setload( u8 laod ){
	OCR0=laod;
}

ISR(INT_TIMER0_OVFt){
	if(TM0_OV_Fptr_callback!=NULLPTR){
		TM0_OV_Fptr_callback();
	}
}
ISR(INT_TIMER0_COMP){
	if(TM0_OCO_Fptr_callback!=NULLPTR){
		TM0_OCO_Fptr_callback();
	}
}
/************************************************************************/
/* Timer 1                                                              */
/************************************************************************/
void Timer1_Init_PostBuild( Timer1Mode_type mode,Timer1Scaler_type scaler,OC1A_Mode_type oc1a_mode,OC1B_Mode_type oc1b_mode)

{
	switch (mode)
	{
		case TIMER1_NORMAL_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		CLEAR_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_CTC_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_CTC_OCRA_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		CLEAR_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		CLEAR_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_ICR_TOP_MODE:
		CLEAR_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		
		case TIMER1_FASTPWM_OCRA_TOP_MODE:
		SET_BIT(TCCR1A,WGM10);
		SET_BIT(TCCR1A,WGM11);
		SET_BIT(TCCR1B,WGM12);
		SET_BIT(TCCR1B,WGM13);
		break;
		case TIMER1_PHASECORRECT_OCRA_TOP_MODE:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
	}
	switch (oc1a_mode)
	{
		case OCRA_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_TOGGLE:
		SET_BIT(TCCR1A,COM1A0);
		CLEAR_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
		case OCRA_INVERTING:
		SET_BIT(TCCR1A,COM1A0);
		SET_BIT(TCCR1A,COM1A1);
		break;
	}
	switch (oc1b_mode)
	{
		case OCRB_DISCONNECTED:
		CLEAR_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_TOGGLE:
		SET_BIT(TCCR1A,COM1B0);
		CLEAR_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_NON_INVERTING:
		CLEAR_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
		case OCRB_INVERTING:
		SET_BIT(TCCR1A,COM1B0);
		SET_BIT(TCCR1A,COM1B1);
		break;
	}
	
	
	TCCR1B&=0XF8;
	TCCR1B|=scaler;

}

void Timer1_InputCaptureEdge(ICU_Edge_type edge)
{
	if(edge==RISING)
	SET_BIT(TCCR1B,ICES1);
	
	else if(edge==FALLING)
	CLEAR_BIT(TCCR1B,ICES1);

}
void Timer1_ICU_InterruptEnable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void Timer1_ICU_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TICIE1);
}
void Timer1_OVF_InterruptEnable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void Timer1_OVF_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,TOIE1);
}
void Timer1_OCA_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void Timer1_OCA_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1A);
}
void Timer1_OCB_InterruptEnable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void Timer1_OCB_InterruptDisable(void)
{
	CLEAR_BIT(TIMSK,OCIE1B);
}
void Timer1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OVF_Fptr_callback=LocalFptr;
}
void Timer1_OCA_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCA_Fptr_callback=LocalFptr;
}
void Timer1_OCB_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_OCB_Fptr_callback=LocalFptr;
}
void Timer1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	Timer1_ICU_Fptr_callback=LocalFptr;
}
void Timer1_VoidTopOCRAset(u16 laod ){
	OCR1A=laod;
}
void Timer1_VoidPWMset(u16 load ){
	if(load>=0 && load<=100){
	OCR1B=(u16)( (u32)(load*OCR1A)/100ul);	
	}
}
ISR(INT_TIMER1_OVF)
{
	if(Timer1_OVF_Fptr_callback!=NULLPTR)
	{
		Timer1_OVF_Fptr_callback();
	}
}
ISR(INT_TIMER1_COMPA)
{
	if(Timer1_OCA_Fptr_callback!=NULLPTR)
	{
		Timer1_OCA_Fptr_callback();
	}
}
ISR(INT_TIMER1_COMPB)
{
	if(Timer1_OCB_Fptr_callback!=NULLPTR)
	{
		Timer1_OCB_Fptr_callback();
	}
}
ISR(INT_TIMER1_CAPT)
{
	if(Timer1_ICU_Fptr_callback!=NULLPTR)
	{
		Timer1_ICU_Fptr_callback();
	}
}