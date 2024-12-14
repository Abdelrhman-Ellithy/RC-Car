/*
 * UART_Interface.h
 *
 * Created: 2023-12-08 1:05:43 AM
 *  Author: Abdelrahman Ellithy
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
/*
void UART_Init(void);
void UART_TX_SetCallBack(void (*LocalFptr)(void));
void UART_RX_SetCallBack(void (*LocalFptr)(void));

void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);
void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);
*/
void uart_init();
void uart_enable_rx_interrupt();
char uart_receive();
#endif /* UART_INTERFACE_H_ */