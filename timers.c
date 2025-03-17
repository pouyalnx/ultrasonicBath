#include "lpc17xx.h"
#include "timers.h"
#include "pwm.h"
#include "adc.h"



void stop_timer_on_off(void){
		NVIC_DisableIRQ(TIMER0_IRQn);
	  LPC_TIM0->TCR=2;
}



#define time_const_div 60

void start_timer_on_off(void){
	on_off_timer.time_cont=0;
	on_off_timer.update_req=0;
	LPC_TIM0->TCR=2;
	LPC_TIM0->IR=1;
	LPC_TIM0->MCR=1;
	LPC_TIM0->MR0=time_const_div*2;
	LPC_TIM0->PR=25000000;
	LPC_TIM0->TCR=1;
	NVIC_EnableIRQ(TIMER0_IRQn);
}



void TIMER0_IRQHandler(void){
	LPC_TIM0->IR=1;
	on_off_timer.time_cont=LPC_TIM0->TC/time_const_div;
	LPC_TIM0->MR0=(on_off_timer.time_cont+2)*time_const_div;
	on_off_timer.update_req=1;
}






/****************************************************
FUNCTION NAME:INSTALL MODE 0

function input:

function output:

description:

notic:
*************************************************************/
///memory for operations



struct sys_conf{
	int currnt_freq;	
}sys_all_opertation_val;

#define max_freq_lock_mode 31000
#define min_freq_lock_mode 26000
#define step_freq_lock_mode  125


#define max_range_freq_sweepadc_mode 32000
#define min_range_freq_sweepadc_mode 25000
#define safe_step_sweepadc_mode      60

#define left_band_ranf_sweepadc_mode 1500
#define right_band_ranf_sweepadc_mode 1500


#define point_per_band_sweep_mode    50

struct sweep_configurations{
	int results[point_per_band_sweep_mode];
  int n;
  int start_freq;	
}sweep_control;



///start of functions
void turn_on_module(void){
	LPC_TIM1->TCR=2;
	LPC_TIM1->MCR=3;
	if(stat_power.mode){
	LPC_TIM1->MR0=250; //4kHZ FREQ  50 point at 80 hz
	sweep_control.n=0;
	sweep_control.start_freq=safe_freq-left_band_ranf_sweepadc_mode;
	sys_all_opertation_val.currnt_freq=sweep_control.start_freq;
	}
	else{
	LPC_TIM1->MR0=250;	//4 khz    40 point at 100 hz
  sys_all_opertation_val.currnt_freq=min_freq_lock_mode;	
	}
	LPC_TIM1->PR=100; //in freq 1mhz
	LPC_TIM1->TCR=1;
	
	NVIC_EnableIRQ(TIMER1_IRQn);
	setup_pwm();
	update_pwm(sys_all_opertation_val.currnt_freq,stat_power.power_value);
}



/****************************************************
FUNCTION NAME:

function input:

function output:

description:

notic:
*************************************************************/

void  sweep_mode_operation(void){
	int gpv0,gpv1,gpv2;
	sweep_control.results[sweep_control.n]=adc_simple_mode_power(adc_simple_freq/sys_all_opertation_val.currnt_freq);
  sweep_control.n++;
	if(sweep_control.n>=point_per_band_sweep_mode){
		for(gpv0=0,gpv1=0,gpv2=0;gpv0<point_per_band_sweep_mode;gpv0++){
		if(sweep_control.results[gpv0]>gpv1){
			gpv1=sweep_control.results[gpv0];
			gpv2=gpv0;
		}
		}
		
		sweep_control.start_freq=sweep_control.start_freq+gpv2*safe_step_sweepadc_mode-left_band_ranf_sweepadc_mode;
		if(sweep_control.start_freq>max_range_freq_sweepadc_mode) sweep_control.start_freq=max_range_freq_sweepadc_mode-left_band_ranf_sweepadc_mode;
		else if(sweep_control.start_freq<min_range_freq_sweepadc_mode) sweep_control.start_freq=min_range_freq_sweepadc_mode;
		sweep_control.n=0;
	}
	sys_all_opertation_val.currnt_freq=sweep_control.n*safe_step_sweepadc_mode+sweep_control.start_freq;	
}


void normal_mode_operation(void){
	sys_all_opertation_val.currnt_freq+=step_freq_lock_mode;
	if(sys_all_opertation_val.currnt_freq>max_freq_lock_mode) sys_all_opertation_val.currnt_freq=min_freq_lock_mode;
}



void TIMER1_IRQHandler(void){
	LPC_TIM1->IR=1;
	if(stat_power.power_stat){
		
		if(stat_power.mode){ //sweep mode
		sweep_mode_operation();	
		}
		else{               //normal mode
		normal_mode_operation();
		}
		update_pwm(sys_all_opertation_val.currnt_freq,stat_power.power_value);
	}
	else{
		stop_pwm();
		LPC_TIM1->TCR=2;
	  NVIC_DisableIRQ(TIMER1_IRQn);
	}
}



