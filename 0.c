#include "lpc17xx.h"
#include "pwm.h"
#include "adc.h"
#include "0.h"
#include "lcd.h"
#include "button.h"
#include "menu.h"
#include "touch.h"
#include "timers.h"



#define touch_sample 100

#define power_max_val 100
#define power_min_val 2

#define time_min_val 0
#define time_max_val 98

#define time_factor 2
#define power_factor 2


struct timer_con_stat on_off_timer;
struct main_core_stat stat_power;
/****************************************************
FUNCTION NAME:for timer 0 request

function input:

function output:

description:

notic:
*************************************************************/
void update_req_from_on_off_tim(void){
					if(on_off_timer.time_value==on_off_timer.time_cont){
				  stop_timer_on_off();
					
						
          page_3_button[2].stat=1;
          page_3_button[3].stat=0;						
          update_page_3();
					page_1_1.value=0;
					update_page_1();					
					page_0_decrase_switch.stat=0;
					page_0_incrase_switch.stat=0;	
					page_0_time_information.value=on_off_timer.time_value;
					update_page_0();					
					
					//stop system machine		requset
/////////////////////////////////////					
					stat_power.power_stat=0;			
				}
				else{
					page_1_1.value=10*on_off_timer.time_cont/on_off_timer.time_value;
					update_page_1();
					page_0_time_information.value=on_off_timer.time_value-on_off_timer.time_cont;
					update_page_0();
				}
}

/****************************************************
FUNCTION NAME:control function

function input:

function output:

description:

notic:
*************************************************************/
int control(void){
	int x,y,key;
int xrel,yrel;
	unsigned int time;
	
	//control varibles
	unsigned char pre_process;

	setup_pwm();	
	stop_pwm();
	setup_lcd_base();
  setup_touch_interface();
	install_menu_machine();
//  setup_debug_uart();
  setup_adc();
	//update_pwm(27000,0);
	stop_timer_on_off();
	
	
	//first boundry counds
	stat_power.power_stat=0; //of
	stat_power.power_value=power_min_val;
	on_off_timer.time_value=time_min_val;
	on_off_timer.update_req=0;
	stat_power.mode=0;
	
	page_1_bar.value=power_min_val*20;
	page_1_bar_text.value=power_min_val;
	update_page_1();
	
	
	page_0_decrase_switch.stat=1;
	update_page_0();
	
	page_3_button[2].stat=2; //disable off key
	update_page_3();
	//
	
	
		while(1){
			
			if(on_off_timer.update_req){
        update_req_from_on_off_tim();
				on_off_timer.update_req=0;
			}
			
			
			if(touch_read(&x,&y)){
	    
      for(time=0;time<80000;time++){}
      
			for(time=0,x=0,y=0;time<touch_sample;time++){
			touch_read(&xrel,&yrel);
      x+=xrel;			
      y+=yrel;				
			}
			
      xrel=x/touch_sample;
			yrel=y/touch_sample;
			
			
			if(touch_read(&x,&y)){				
			x=xrel;
			y=yrel;				
			key=check_touch(x,y);
			
			if(key){
			//sa step	
			pre_process=0;
      switch(key){
				case 1:
					if(stat_power.power_value>power_min_val){
				  page_3_button[0].stat=2;
				  update_page_3();
					pre_process=1;	
					}
					
				break;
				case 2:
					if(stat_power.power_value<power_max_val){
				  page_3_button[1].stat=2;
				  update_page_3();
					pre_process=1;	
					}
					
				break;
				case 3:
					if(stat_power.power_stat!=0){
				  page_3_button[2].stat=2;
				  update_page_3();
					}
				break;
				case 4:
				if(stat_power.power_stat!=1){	
				page_3_button[3].stat=2;
				 update_page_3();
				}
				break;
				
				case 5:
					//empty
				break;
				case 6:
					//empty
				break;
				
				
				case 7:
					if(on_off_timer.time_value>time_min_val && stat_power.power_stat!=1){
					page_0_decrase_switch.stat=2;
				  update_page_0();
					pre_process=1;
					}
				break;
				case 8:
					if(on_off_timer.time_value<time_max_val && stat_power.power_stat!=1){					
					page_0_incrase_switch.stat=2;
				  update_page_0();
					pre_process=1;	
					}
				break;	
			}
			
			
			}
			
      while(touch_read(&x,&y)){
			
				if(on_off_timer.update_req){
        update_req_from_on_off_tim();
				on_off_timer.update_req=0;
			}
				
			}
			
			//sb unit
        switch(key){
				case 1:
				  if(stat_power.power_value>power_min_val){
						
						if(stat_power.power_value<=power_max_val){
							page_3_button[1].stat=0;
						}
						
           stat_power.power_value-=power_factor;
						
						if(stat_power.power_value==power_min_val){
						page_3_button[0].stat=1;
             update_page_3();
             pre_process=0;							
						}
           
						page_1_bar_text.value=stat_power.power_value;
						page_1_bar.value=stat_power.power_value*20;
            update_page_1();
						
						//proceesing requests
						
						//
					}									
				break;
				case 2:
					if(stat_power.power_value<power_max_val){
				  
					if(stat_power.power_value>=power_min_val){
						page_3_button[0].stat=0;
					}
					
					stat_power.power_value+=power_factor;
				  
					if(stat_power.power_value==power_max_val){
						page_3_button[1].stat=1;
						update_page_3();
						pre_process=0;
					}
					
					page_1_bar_text.value=stat_power.power_value;
					page_1_bar.value=stat_power.power_value*20;
					update_page_1();
					
					
					//processing request
				
				 //
					}
				break;
				case 3:
					if(stat_power.power_stat!=0){
						page_3_button[2].stat=1;
						page_3_button[3].stat=0;						
						
						update_page_3();
						page_0_decrase_switch.stat=0;
						page_0_incrase_switch.stat=0;
						
						update_page_0();
						
						page_1_1.value=0;
						
						update_page_1();
						
						stat_power.power_stat=0; //off
						
						if(on_off_timer.time_value){
							stop_timer_on_off();
							on_off_timer.update_req=0;
					    page_1_1.value=0;
					    update_page_1();					
					    page_0_time_information.value=on_off_timer.time_value;
				    	update_page_0();
						}
						//off process in system
						
					}
				break;
				case 4:
				if(stat_power.power_stat!=1){
						page_3_button[2].stat=0;
						page_3_button[3].stat=1;						
						
						update_page_3();
						page_0_decrase_switch.stat=1;
						page_0_incrase_switch.stat=1;
						
						update_page_0();
						
						page_1_1.value=0; //maybe not needed
						update_page_1();
						
						stat_power.power_stat=1; //on
 					  turn_on_module(); //install real pwm module
					
	          if(on_off_timer.time_value){
            start_timer_on_off();
						}							
						
					//on process in system
						
					}
				break;
					
				case 5:
					if(stat_power.mode==0 && stat_power.power_stat!=1){
						stat_power.mode=1;
						page_0_switch.stat=1;
						update_page_0();
					}
				break;
				
				case 6:
					if(stat_power.mode==1 && stat_power.power_stat!=1){
						stat_power.mode=0;
						page_0_switch.stat=0;
						update_page_0();
					}
				break;

				
					
				case 7:
					if(on_off_timer.time_value>time_min_val && stat_power.power_stat!=1){
						
						if(on_off_timer.time_value==time_max_val){
							page_0_incrase_switch.stat=0;
						}
						
						
						on_off_timer.time_value-=time_factor;
						
						page_0_time_information.value=on_off_timer.time_value;
						
						if(on_off_timer.time_value==time_min_val){
							page_0_decrase_switch.stat=1;
							update_page_0();
							pre_process=0;
						}
						
					}
				break;
				
				case 8:
          if(on_off_timer.time_value<time_max_val && stat_power.power_stat!=1){
						
						if(on_off_timer.time_value==time_min_val){
							page_0_decrase_switch.stat=0;
						}
					
						on_off_timer.time_value+=time_factor;
					
						page_0_time_information.value=on_off_timer.time_value;
						
						if(on_off_timer.time_value==time_max_val){
							page_0_incrase_switch.stat=1;
							update_page_0();
							pre_process=0;
						}
						
					}
				break;
				
			}
				
      //sc unit				
      switch(key){
				case 1:
					if(pre_process){
				  page_3_button[0].stat=0;
				  update_page_3();
					}
				break;
				case 2:
					if(pre_process){
					page_3_button[1].stat=0;
				  update_page_3();
					}
				break;
				case 3:
					//empty
				break;
				case 4:
					//empty
				break;
				
				case 5:
					//empty
				break;
				case 6:
					//empty
				break;
				
				case 7:
					if(pre_process){
				  page_0_decrase_switch.stat=0;
				  update_page_0();
					}
				break;
				case 8:
					if(pre_process){
					page_0_incrase_switch.stat=0;
				  update_page_0();
					}
				break;
				
			}				
			}			
			
	    for(time=0;time<999000;time++);
			}
			

			
		}		
}


/****************************************************
FUNCTION NAME:main

function input:

function output:

description:

notic:
*************************************************************/

int main(){
return control();
}

