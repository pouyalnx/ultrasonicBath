#include "menu.h"
#include "lcd.h"
#include "button.h"



/****************************************************

page 1 functions
function input:

function output:

description:

notic:
*************************************************************/

bar_menu page_1_bar_shodow;
bar_menu page_1_bar;

bar_menu page_1_1_shodow;
bar_menu page_1_1;


bar_menu page_1_bar_text_shodow;
bar_menu page_1_bar_text;



void  update_page_1(void){
	pos a,b;
	
	if(page_1_bar.value!=page_1_bar_shodow.value){
	a.x=160;
	b.x=320;	
	a.y=42;	
  b.y=a.y+160;		
	cicle();
	page_1_bar_shodow.value=page_1_bar.value;	
	write_page_dynamic_addr(page_lcd,12800,a,b);
	}
	
	if(page_1_1.value!=page_1_1_shodow.value){
		a.x=160; 
    b.x=320;
    a.y=240;
    b.y=a.y+25;
		control_page_1_bar();
		page_1_1_shodow.value=page_1_1.value;
	  copy_img_colour_bar(number_table_1_1);
		write_page_dynamic_addr(ram_picture_c,2000,a,b);
	}
	
	if(page_1_bar_text_shodow.value!=page_1_bar_text.value){
	a.x=160;
	b.x=320;	
	a.y=42;	
  b.y=a.y+160;		
	cicle();		
  print_power_factor(); 
	write_page_dynamic_addr(page_lcd,12800,a,b);		
	}
	
}


void page_1_install(void){
	page_1_bar.stat=bar_menu_enable;
	page_1_bar.value=0;
	page_1_bar_shodow.value=2000;
  update_page_1(); 

	
	page_1_1.stat=1;
  page_1_1_shodow.value=0;
	page_1_1.value=0;
	
	
	page_1_bar_text.stat=1;
  page_1_bar_text.value=0;
  page_1_bar_text_shodow.value=1;	
	
	install_bar_1_page_1();
}


/****************************************************
function input:

function output:

description:

notic:
*************************************************************/

button_menu page_3_button[4];

button_menu page_3_button_shodow[4];


void update_page_3_button(int i){
		pos a,b;
	a.x=30+160*2;
	b.x=130+160*2;
	a.y=i*65+12;
	b.y=a.y+50;
	if(page_3_button[i].stat!=page_3_button_shodow[i].stat){
		switch(page_3_button[i].stat){
			case button_menu_on:
				high_byte_pattern[3]=button_menu_on_colour_high;
				low_byte_pattern[3]=button_menu_on_colour_low;			
			break;
			case button_menu_off:
				high_byte_pattern[3]=button_menu_off_colour_high;
				low_byte_pattern[3]=button_menu_off_colour_low;			
			break;			
			case button_menu_push:
				high_byte_pattern[3]=button_menu_push_colour_high;
				low_byte_pattern[3]=button_menu_push_colour_low;			
			break;			
		}
		page_3_button_shodow[i].stat=page_3_button[i].stat;
    
		switch(i){
			case 0:
		  write_page(data_img_page_3_0,2500,a,b);	
		  break;
			case 1:
		  write_page(data_img_page_3_1,2500,a,b);	
		  break;
			case 2:
		  write_page(data_img_page_3_2,2500,a,b);	
		  break;
			case 3:
		  write_page(data_img_page_3_3,2500,a,b);	
		  break;			
		}
		}
}

void update_page_3(void){
	copy_img_colour_bar(number_table_page_3);
	update_page_3_button(0);
	update_page_3_button(1);
	update_page_3_button(2);
	update_page_3_button(3);	
}


/****************************************************
page 0 area

function input:

function output:

description:

notic:
*************************************************************/



switch_menu page_0_switch;
switch_menu page_0_switch_shodow;

button_menu page_0_decrase_switch;
button_menu page_0_incrase_switch;

button_menu page_0_decrase_switch_shodow;
button_menu page_0_incrase_switch_shodow;

bar_menu    page_0_time_information;
bar_menu    page_0_time_information_shodow;

void update_page_0(void){
	pos a,b;
	
	if(page_0_switch.stat!=page_0_switch_shodow.stat){
		a.x=0;
		b.x=160;
		
		a.y=80;
		b.y=130;
		
		
		switch(page_0_switch.stat){
			case switch_menu_mode_0:
		  copy_img_colour_bar(number_table_0_1_0);
			write_page(data_img_0_1_0,4000,a,b);			
			break;
			case switch_menu_mode_1:
		  copy_img_colour_bar(number_table_0_1_1);				
			write_page(data_img_0_1_1,4000,a,b);
			break;
		}	
		page_0_switch_shodow.stat=page_0_switch.stat;
	}
	
	
	if(page_0_decrase_switch.stat!=page_0_decrase_switch_shodow.stat){
		 
	 switch(page_0_decrase_switch.stat){
		 case 0:
			 copy_img_colour_bar(button_menu_0_4_5_0_colour_table);
		 break;
		 case 1:
			 copy_img_colour_bar(button_menu_0_4_5_1_colour_table);
		 break;
		 case 2:
			 copy_img_colour_bar(button_menu_0_4_5_2_colour_table);
		 break;		 
	}

	a.x=10;
	a.y=220;
	b.x=a.x+30;
	b.y=a.y+30;
	write_page(button_menu_0_5,450,a,b);  	
	
		page_0_decrase_switch_shodow.stat=page_0_decrase_switch.stat;
   }
	
	
	if(page_0_incrase_switch.stat!=page_0_incrase_switch_shodow.stat){
		 
	 switch(page_0_incrase_switch.stat){
		 case 0:
			 copy_img_colour_bar(button_menu_0_4_5_0_colour_table);
		 break;
		 case 1:
			 copy_img_colour_bar(button_menu_0_4_5_1_colour_table);
		 break;
		 case 2:
			 copy_img_colour_bar(button_menu_0_4_5_2_colour_table);
		 break;		 
	}

   	a.x=120;
	  a.y=220;
	  b.x=a.x+30;
   	b.y=a.y+30;
	 write_page(button_menu_0_4,450,a,b);  	
	
		page_0_incrase_switch_shodow.stat=page_0_incrase_switch.stat;
	}
	
	if(page_0_time_information.value!=page_0_time_information_shodow.value){
		a.x=0;
		a.x=page_0_print_a_number(page_0_time_information.value/10,a.x,0);
		a.x=page_0_print_a_number(page_0_time_information.value%10,a.x,0);
    a.x=50,
    a.y=218;
    b.x=a.x+56;
    b.y=a.y+34;
		write_page_dynamic_addr(page_lcd_2+2,952,a,b);
		page_0_time_information_shodow.value=page_0_time_information.value;
	}
	
	
}





void install_page_0(void){
	pos start,end;
	start.x=0;
	start.y=0;
	end.y=60;
	end.x=160;
	copy_img_colour_bar(number_table_0_0);
	write_page(data_img_0_0,4800,start,end);
	
	start.x=35;
	end.x=start.x+30;
	
	start.y=255;
	end.y=start.y+20;


	copy_img_colour_bar(number_table_timer_texts);
	write_page(timer_desc_text_min,300,start,end);	


	start.x=100;
	end.x=start.x+60;
	
	start.y=190;
	end.y=start.y+30;
	
	write_page(timer_desc_text,900,start,end);	
		
	page_0_switch.stat=switch_menu_mode_0;
	page_0_switch_shodow.stat=switch_menu_mode_1;

  page_0_decrase_switch.stat=0;	
	page_0_decrase_switch_shodow.stat=1;
	
	page_0_incrase_switch.stat=0;
	page_0_incrase_switch_shodow.stat=1;
	
	
	install_page_0_time_bar();
	
	page_0_time_information_shodow.value=1;
	page_0_time_information.stat=1;
	page_0_time_information.value=0;
	update_page_0();
	
}



/****************************************************
end of page 0

function input:

function output:

description:

notic:
*************************************************************/



void install_menu_machine(void){
	int gpv0;
	
	for(gpv0=0;gpv0<lcd_page_size;gpv0++){
		page_lcd[gpv0]=0xee;
	}
	
	
	update_lcd_page(0);  //this function changed
	update_lcd_page(1);
	update_lcd_page(2);	
	
	
	
  page_3_button[0].stat=button_menu_off;
  page_3_button[1].stat=button_menu_off;	
  page_3_button[2].stat=button_menu_off;
  page_3_button[3].stat=button_menu_off;

	page_3_button_shodow[0].stat=button_menu_on;
  page_3_button_shodow[1].stat=button_menu_on;	
  page_3_button_shodow[2].stat=button_menu_on;
  page_3_button_shodow[3].stat=button_menu_on;
	
	
	update_page_3();
	install_page_0();
	page_1_install();
}




