#include "lpc17xx.h"
#include "pwm.h"
#include "0.h"


int setup_pwm(void){
	

	
	LPC_PWM1->TCR=2;
	LPC_PWM1->PR=0;
	LPC_PWM1->MCR=2;
	LPC_PWM1->PCR=0xA08;
	update_pwm(safe_freq,safe_power_decarsor_factor);
	//if(update_pwm(safe_freq,safe_power_decarsor_factor)) LPC_GPIO1->FIOCLR=16;
	
	LPC_PWM1->TCR=9;
	LPC_PINCON->PINSEL3&=~((0X3<<4)|(3<<10));  //P1.18 P1.21
	LPC_PINCON->PINSEL3|=((2<<4)|(2<<10));
	LPC_PINCON->PINMODE3&=~((3<<4)|(3<<10));  
 	LPC_PINCON->PINMODE3|=((2<<4)|(2<<10));	

  return 1;
 }


int stop_pwm(void){
	LPC_PINCON->PINSEL3&=~((0X3<<4)|(3<<10));  //P1.21 P1.18
  
	LPC_GPIO1->FIODIR|=1<<20|1<<23;
  LPC_GPIO1->FIOSET|=1<<20|1<<23;
	
	LPC_PWM1->TCR=2;
	return 1;
}

int update_pwm(int freq,int power_decrasor){
	int t,safe_t,power_t;
	
	t=pwm_module_freq/freq;
	safe_t=safe_t_priod_on_of_transistor;
	power_t=(t/2-safe_t-power_safe_period_non_error)*(100-power_decrasor)/100;
	
	if(power_t<0) return 0;
	
	if(t<max_t_size_for_out && t>min_t_size_for_out){
  LPC_PWM1->MR0=t;
	t/=2;
  safe_t/=2;
	power_t/=2;
  LPC_PWM1->MR1=t+power_t+safe_t; //IF NEEDED I WILL CHANGE THIS POWER TO 2*POWER FOR THIS SECTION
  LPC_PWM1->MR2=t-power_t-safe_t;
	LPC_PWM1->MR3=power_t+safe_t;
	LPC_PWM1->LER=0XF;
	return 1;
	}
	return 0;
}


