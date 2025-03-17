#include "lpc17xx.h"
#include "touch.h"







void setup_debug_uart(void){
	LPC_PINCON->PINSEL0&=~(0XF0);
	LPC_PINCON->PINSEL0|=0X50;
	LPC_UART0->LCR=0X83;
	LPC_UART0->FDR=229;
  LPC_UART0->DLL=10;
  LPC_UART0->DLM=0;
	LPC_UART0->LCR=3;
	LPC_UART0->FCR=1;
}





void send_char(char i){
	LPC_UART0->THR=i;
	while(!(LPC_UART0->LSR & 0X20));
}

void debug_text(char *in){
	int gpv0;
	for(gpv0=0;in[gpv0];gpv0++){
		send_char(in[gpv0]);
	}
}


