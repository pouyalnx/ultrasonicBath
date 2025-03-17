#include "lcd.h"
#include "lpc17xx.h"


unsigned char page_lcd[15000];
unsigned char page_lcd_2[952];
unsigned char high_byte_pattern[16]={

223, //colour 0
13,  //colour 1
127,  //colour 2
159, 
	
//0 ,  
//248,  
//252,  
//254, 
255, 
127,
175,
231,   
92,   
100,     
0,   
106,  
147,   
147	,  //colour 0
150,   
150	,	
};
unsigned char low_byte_pattern[16]={
	4,//0, 
  0,//	0,
	254,//16,
  4,//	160,
	252,
	224,
	229,
	255,
	244,
	189,
	17,
 217,
	155,
150,
150,
150
};





void lcd_delay_func(unsigned int time){
	while(time>0) time--;
}


void lcd_cs_enable(void){
	LPC_GPIO2->FIOCLR=cs;
	lcd_delay_func(5);
}

void lcd_cs_disable(void){
	lcd_delay_func(20);	
	LPC_GPIO2->FIOSET=cs;
}


void lcd_switch_cmd(void){
LPC_GPIO2->FIOCLR=rs;	
}

void lcd_switch_data(void){
LPC_GPIO2->FIOSET=rs;	
}


void write_lcd(unsigned char data){
LPC_GPIO2->FIOCLR=0XFF;
LPC_GPIO2->FIOCLR=wr;
LPC_GPIO2->FIOSET=data;
LPC_GPIO2->FIOSET=wr;	
}







void cmd(unsigned char in){
	lcd_switch_cmd();
	write_lcd(in);
}


void data(unsigned char in){
	lcd_switch_data();
	write_lcd(in);
}






void lcd_set_draw_area(int xs,int xe,int ys,int ye){
cmd(0x2a);
data(xs/256);
data(xs%256);
data(xe/256);	
data(xe%256);	
cmd(0x2b); 	
data(ys/256);
data(ys%256);
data(ye/256);
data(ye%256);
}


void setup_lcd_base(void){
	LPC_GPIO2->FIODIR=0XFFF;
	LPC_GPIO2->FIOSET=rst;
	lcd_delay_func(100000);
	LPC_GPIO2->FIOCLR=rst;
	lcd_delay_func(100000);	
  LPC_GPIO2->FIOSET=rst;
	lcd_delay_func(100000);		
  LPC_GPIO2->FIOSET=rd|wr|rs|cs;
	LPC_GPIO2->FIOCLR=rd;
  lcd_cs_enable();

	
	   cmd(0X01);
	 lcd_delay_func(10000);
   cmd(0x11);
   lcd_delay_func(10000);
	cmd(0x13);
  cmd(0xb0);
	cmd(0x3a);
	data(0x5);	
	cmd(0xc0);
	data(0x3b);
	data(0);
	data(2);
	data(0x11);
	data(0);
	cmd(0xc1);
	data(0x10);
	data(0x10);
	data(0x68);
	cmd(0xc5);
	data(1);
	cmd(0xc8);
	data(0);
	data(0x30);
	data(0x36);
	data(0x5d);
	data(0x4);
	data(0x16);
	data(0x37);
	data(0x75);
	data(0x77);
	data(0x54);
	data(0x6);
	data(0x12);
	cmd(0xd0);
	data(0x7);
	data(0x40);
	data(0x1f);
	cmd(0xd1);
	data(0);
	data(0x18);
	data(0x1f);
	cmd(0xd2);
	data(0x1);
	data(0x11);
	cmd(0xe4);
	data(0xa);
	cmd(0xf0);
	data(1);
	cmd(0xf3);
	data(0x40);
	data(0xa);
	cmd(0xf7);
	data(0x80);
	cmd(0x36);	
	data(0x08);
	cmd(0x3a);
	data(0x5);
	cmd(0xb3);
	data(0);
	data(0);
	data(0);
	data(0x11);
	cmd(0x2b);
	data(0);
	data(0);
	data(1);
	data(0x3f);
	cmd(0x2a);
	data(0);
	data(0);
	data(1);
	data(0xdf);
  cmd(0x29);
	cmd(0x36);
	data(0x08);
	cmd(0x3a);
	data(0x5);
	  LPC_GPIO2->FIOSET=rd|wr|rs|cs;
 lcd_cs_disable();
}	



/****************************************************
FUNCTION NAME:this function is updated for new applications

function input:

function output:

description:now it act clearing display

notic:
*************************************************************/
void update_lcd_page(int page){
	int gpv0;
	//unsigned char help;
	lcd_cs_enable();
  lcd_set_draw_area(160*page,160*page+160-1,24,295);
	cmd(0x3a);
	data(0x5);  
	cmd(0x36);
	data(0x10|0x20);
	cmd(0x2c);
	
	lcd_switch_data();
	for(gpv0=0;gpv0<21760;gpv0++){
	/*
	help=page_lcd[gpv0];
	help&=0xf;	
	write_lcd(high_byte_pattern[help]);
	write_lcd(low_byte_pattern[help]);
	help=page_lcd[gpv0];
	help/=16;	
	write_lcd(high_byte_pattern[help]);
	write_lcd(low_byte_pattern[help]);
	*/
	write_lcd(high_byte_pattern[0xf]);
	write_lcd(low_byte_pattern[0xf]);
	write_lcd(high_byte_pattern[0xf]);
	write_lcd(low_byte_pattern[0xf]);		
	}
  lcd_cs_disable();
}


/****************************************************
function input:write diplay with ont using ram

function output:

description:for having faster speed i  use this function

start pos<end postion(for all objects x and y)
else unknown stat

size is byte  or 2pixel/byte

notic:good for buttons
*************************************************************/
void write_page(const unsigned char *pattern,unsigned int size,pos start,pos end){
int gpv0,gpv1;
	lcd_cs_enable();
	lcd_set_draw_area(start.x,end.x-1,24+start.y,23+end.y);
	cmd(0x3a);
	data(0x5);  
	cmd(0x36);
	data(0x10|0x20);
	cmd(0x2c);
	lcd_switch_data();	
	for(gpv0=0;gpv0<size;gpv0++){
  gpv1=pattern[gpv0-2] & 0xf;
	write_lcd(high_byte_pattern[gpv1]);	
	write_lcd(low_byte_pattern[gpv1]);
		
  gpv1=(pattern[gpv0-2]/16) & 0xf;
	write_lcd(high_byte_pattern[gpv1]);	
	write_lcd(low_byte_pattern[gpv1]);		
	}
lcd_cs_disable();	
}


/****************************************************
function input:

function output:

description:  

notic:
*************************************************************/

void write_page_dynamic_addr(unsigned char *pattern,unsigned int size,pos start,pos end){
int gpv0,gpv1;
	lcd_cs_enable();
	lcd_set_draw_area(start.x,end.x-1,24+start.y,23+end.y);
	cmd(0x3a);
	data(0x5);  
	cmd(0x36);
	data(0x10|0x20);
	cmd(0x2c);
	lcd_switch_data();	
	for(gpv0=0;gpv0<size;gpv0++){
  gpv1=pattern[gpv0-2] & 0xf;
	write_lcd(high_byte_pattern[gpv1]);	
	write_lcd(low_byte_pattern[gpv1]);
		
  gpv1=(pattern[gpv0-2]/16) & 0xf;
	write_lcd(high_byte_pattern[gpv1]);	
	write_lcd(low_byte_pattern[gpv1]);		
	}
lcd_cs_disable();	
}


































/****************************************************
function input:  const data,start pos

function output: 

description:  

notic: this function dont payattention to the colour plate
or data type just replace data

data size uint is byte or duble pixel byte
*************************************************************/
void print_img(const unsigned char *data,uint32_t data_size,pos start,pos end){
	uint32_t gpv0,gpv1,gpv2,gpv3;
	
	start.x/=2;
	end.x/=2;

	
	
	gpv1=start.y*80+start.x;
	gpv2=start.x;
	gpv3=start.y;
	
	
	for(gpv0=0;gpv0<data_size;gpv0++){
	page_lcd[gpv1]=data[gpv0-2];
		
	gpv1++;
  gpv2++;


  if(gpv2==end.x){
		gpv2=start.x;
		gpv3++;
	  gpv1=gpv3*80+start.x;		
	}
	}
	
}
/****************************************************
function input:

function output:

description:

notic:
*************************************************************/

 void copy_img_colour_bar(const unsigned char *number_table){
	 int gpv0,gpv1,gpv2;
	 	 gpv1=2*(number_table[0]+1);
    for(gpv0=2,gpv2=0;gpv0<gpv1;gpv0+=2){
    high_byte_pattern[gpv2]=number_table[gpv0];
	  low_byte_pattern[gpv2++]=number_table[gpv0+1]; 	 
	 }	
 }
