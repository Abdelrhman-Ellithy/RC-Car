/*
 * UART_Program.c
 *
 * Created: 2023-12-08 1:06:03 AM
 *  Author: Abdelrahman Ellithy
 */ 
#include "../../LIB/BIT_OPERATIONS.h"
#include "../../LIB/Types.h"
#include "UART_Config.h"
#include "UART_Private.h"
#include "UART_Interface.h"

extern UART_Data;
static void (*UART_RX_Fptr_SetCallBack) (void);
static void (*UART_TX_Fptr_SetCallBack) (void);

void UART_Init(void)
{
	u8  UCSRC_var=0;
	u16 UBRR_var=25;
	/***************************** transmission speed***************************/
	#if (SPEED_MODE==NORMAL_SPEED)
		CLEAR_BIT(UCSRA,U2X);
	#elif (SPEED_MODE==DOUBLE_SPEED)
		SET_BIT(UCSRA,U2X);
	#endif

	//******************set URSEL to write data to UCSRC register***************/
	SET_BIT(UCSRC_var,URSEL);
	
	//********************************synch***********************************/
	#if (SYNCH_MODE==SYNCH)
		SET_BIT(UCSRC_var,UMSEL)
	#elif (SYNCH_MODE==ASYNCH)
		CLEAR_BIT(UCSRC_var,UMSEL);
	#endif
	//*****************************parity mode*******************************/
	
	#if (PARITY_MODE==NO_PARITY)
	CLEAR_BIT(UCSRC_var,UPM0);
	CLEAR_BIT(UCSRC_var,UPM1);
	#elif (PARITY_MODE==EVEN_PARITY)
	CLEAR_BIT(UCSRC_var,UPM0);
	SET_BIT(UCSRC_var,UPM1);
	#elif (PARITY_MODE==ODD_PARITY)
	SET_BIT(UCSRC_var,UPM0);
	SET_BIT(UCSRC_var,UPM1);
	#endif
	//************************Data bits*******************************/
	#if (N_DATA_BITS==_5_DATA_BITS)
		CLEAR_BIT(UCSRC_var,UCSZ0);
		CLEAR_BIT(UCSRC_var,UCSZ1);
		CLEAR_BIT(UCSRC_var,UCSZ2);
	#elif (N_DATA_BITS==_6_DATA_BITS)
		SET_BIT(UCSRC_var,UCSZ0);
		CLEAR_BIT(UCSRC_var,UCSZ1);
		CLEAR_BIT(UCSRC_var,UCSZ2);
	#elif (N_DATA_BITS==_7_DATA_BITS)
		CLEAR_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
	#elif (N_DATA_BITS==_8_DATA_BITS)
		SET_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
	#elif (N_DATA_BITS==_9_DATA_BITS)
		SET_BIT(UCSRC_var,UCSZ0);
		SET_BIT(UCSRC_var,UCSZ1);
		SET_BIT(UCSRB,UCSZ2);
	#endif
	//************************Stop bits*******************************/
	#if (N_STOP_BITS==ONE_STOP_BIT)
		CLEAR_BIT(UCSRC_var,USBS);
	#elif (N_STOP_BITS==TWO_STOP_BIT)
		SET_BIT(UCSRC_var,USBS);
	#endif
	//*****************set UCSRC value   *******************************/
	UCSRC=UCSRC_var;

	//************************Baud rate *******************************/

	UBRR_var= BaudRateArray[SPEED_MODE][CPU_F][BUAD_RATE];
	UBRRH = (u8)(UBRR_var>>8);
	UBRRL = (u8)UBRR_var;
	
	//************************Enable  *******************************/
	//enable UART  receiver.
	SET_BIT(UCSRB,RXEN);
	//enable UART  transmitter .
    //SET_BIT(UCSRB,TXEN);
}

void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}

void UART_RX_SetCallBack(void(*LocalFptr)(void))
{
	UART_RX_Fptr_SetCallBack = LocalFptr;
}

void UART_TX_SetCallBack(void(*LocalFptr)(void))
{
	UART_TX_Fptr_SetCallBack = LocalFptr;
}
 ISR(INT_USART_RXC)
 {
	 if (UART_RX_Fptr_SetCallBack!=NULLPTR)
	 {
		 UART_Data=UDR;
		 UART_RX_Fptr_SetCallBack();
	 }
 }

 ISR(INT_USART_TXC)
 {
	 if (UART_TX_Fptr_SetCallBack!=NULLPTR)
	 {
		 UART_TX_Fptr_SetCallBack();
	 }
 }
