#include "lpc17xx.h"
#include "adc.h"

/*
int buffer_s[50];
int buffer_pointer;
int max_value;
volatile int stat;
*/

void setup_adc(void){
	LPC_PINCON->PINSEL1&=~(0X3<<14);
	LPC_PINCON->PINSEL1|=(1<<14);
	LPC_ADC->ADCR=1<<8|1<<21;
  //stat=LPC_ADC->ADDR0;
	//stat=0;
}

/****************************************************
FUNCTION NAME:AFTER CHANGING MODE THIS FUNCTION IS UNUSED

function input:

function output:

description:

notic:
*************************************************************/
/*
int adc_sample(int *max){
	int gpv0;
  switch(stat){
		case 0:
		LPC_ADC->ADCR=1<<21|1<<8|1<<24|1;
		LPC_ADC->ADINTEN=1;
		NVIC_EnableIRQ(ADC_IRQn);
		buffer_pointer=0;
		stat=1;
		return 0;
	  case 1:
		//NOTHING	
		return 0;
		case 2:
		max_value=0;
		for(gpv0=0;gpv0<adc_allowed_sample;gpv0++){
     if(buffer_s[gpv0]>max_value) max_value=buffer_s[gpv0];
		}
		*max=max_value;
		stat=0;
		return 1;
	}
	return 0;
}

void ADC_IRQHandler(void){
	buffer_s[buffer_pointer++]=(LPC_ADC->ADDR0 >> 4) & 0XFFF;
	if(buffer_pointer<adc_allowed_sample){
		LPC_ADC->ADCR=1<<24|1<<21|1<<8|1;
	}
	else{
		stat=2;
		NVIC_DisableIRQ(ADC_IRQn);
	}
}
*/
/****************************************************
FUNCTION NAME:for new system i used new function
because

cortex m3 need 12 cycle for running irq
switching from max value of signal to power of signal in period 

function input:

function output:

description:

notic:
*************************************************************/

int adc_simple_mode_power(int simple){
int value;
value=0;
while(simple--){
LPC_ADC->ADCR=1<<21|7<<8|1<<24|1;
while(!(LPC_ADC->ADGDR & 0X80000000));
value+=(LPC_ADC->ADDR0 >> 4) & 0XFFF;	
}
return value/simple;
}

























