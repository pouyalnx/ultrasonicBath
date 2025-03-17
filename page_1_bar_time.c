#include "lcd.h"
#include "button.h"
#include "menu.h"


#define colour_back 15
#define colour_main 12

unsigned char *ram_picture_c;

unsigned char colour_change_t;


void pixel_t(int x,int y){
	y*=80;
	if(x%2){
		ram_picture_c[y+x/2]&=0xf;
		ram_picture_c[y+x/2]|=colour_change_t*16;
	}
	else{
		ram_picture_c[y+x/2]&=0xf0;
		ram_picture_c[y+x/2]|=colour_change_t;		
	}
}





void put_box_colour(int code){
int gpv0,gpv1,gpv2;
gpv0=19*code+1;

for(gpv1=4;gpv1<21;gpv1++){
for(gpv2=0;gpv2<17;gpv2++){
	pixel_t(gpv2+gpv0,gpv1);
}
}	
}


void control_page_1_bar(void){
int gpv0,gpv1,gpv2;
ram_picture_c=(unsigned char *)(page_lcd+12800);	
if(page_1_1_shodow.value) gpv0=page_1_1_shodow.value-1;
else                      gpv0=0;
	
if(page_1_1.value) gpv1=page_1_1.value-1;
else                      gpv1=0;	

if(gpv1>gpv0) colour_change_t=colour_main;
else{          colour_change_t=colour_back;	

gpv2=gpv0;
gpv0=gpv1;
gpv1=gpv2;	

}

for(gpv2=gpv0;gpv2<gpv1;gpv2++)
put_box_colour(gpv2);	
}



void install_bar_1_page_1(void){
int gpv0;
pos a,b;
ram_picture_c=(unsigned char *)(page_lcd+12800);
copy_img_colour_bar(number_table_1_1);
a.x=160;
b.x=320;
a.y=240;
b.y=a.y+25;
	
for(gpv0=0;gpv0<2000;gpv0++)
ram_picture_c[gpv0]=data_img_page_1_1[gpv0];
	

control_page_1_bar();
write_page_dynamic_addr(ram_picture_c,2000,a,b);	
}












