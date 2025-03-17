#include "touch.h"
#include "lpc17xx.h"

const short int touch_keys[]={
	8,0,0,0,  //format xs,xe ys,ye
	420,1160,3150,3500, //power dec
	420,1160,2180,2520, //power inc
	420,1160,1360,1770, //off
	420,1160,540,880,   //on
	2746,3056,2344,2800, //lock
	3362,3798,2276,2631,  //sweep
	3580,3770,660,960,   //dec time
	2720,2950,660,960,  //inc time
};


int check_touch(int x,int y){
	int gpv0,gpv1;
	gpv1=touch_keys[0]*4+4;
	for(gpv0=4;gpv0<gpv1;gpv0++){
		if(touch_keys[gpv0]<x && x<touch_keys[gpv0+1]){
		if(touch_keys[gpv0+2]<y && y<touch_keys[gpv0+3]){
			return gpv0/4;
		}	
		}
	}
  return 0;
}



void delay_chip(unsigned int time){
	time*=60;
	while(time--);
}


void enable_touch(void){
	LPC_GPIO0->FIOCLR=0X40;
}

void disable_touch(void){
	LPC_GPIO0->FIOSET=0X40;
}



void setup_touch_interface(void){
	LPC_PINCON->PINSEL0&=~(3<<14|3<<16|3<<18);
	LPC_PINCON->PINSEL0|=2<<14|2<<16|2<<18;	
	LPC_SSP1->CPSR=2;
	LPC_SSP1->CR0=5<<8|7;
	LPC_SSP1->CR1=2;
	LPC_GPIO0->FIODIR&=~(3<<5);
	LPC_GPIO0->FIODIR=1<<6;
}



unsigned char cmd_touch(unsigned char in){
	LPC_SSP1->DR=in;
	while(!(LPC_SSP1->SR & 4)){}
  return LPC_SSP1->DR;
}


int read_ad_touch(void){
	int ret;
	ret=cmd_touch(0)*256;
	delay_chip(1);
	ret|=cmd_touch(0);
	ret>>=3;
	ret&=0xfff;
	return ret;
}


int read_x(void){
	int ret;
	enable_touch();
	delay_chip(1);
	cmd_touch(0x90);
	delay_chip(1);
	ret=read_ad_touch();
	disable_touch();
	return ret;
}

int read_y(void){
	int ret;
	enable_touch();
	delay_chip(1);
	cmd_touch(0xd0);
	delay_chip(1);
	ret=read_ad_touch();
	disable_touch();
	return ret;
}




void read_x_y(int *x,int *y){
	*x=read_x();
	delay_chip(1);
	*y=read_y();
	
}



int touch_read(int *x,int *y){
	int m0,m1,m2;
	int temp[3][2];
	
	*x=0;
	*y=0;
	for(m0=0;m0<3;m0++){
		temp[m0][0]=0;
		temp[m0][1]=0;
	}
	
	for(m0=0;m0<3;m0++){
		if(LPC_GPIO0->FIOPIN & 0X20) return 0;
		read_x_y(&m1,&m2);
		temp[0][0]+=m1;
		temp[0][1]+=m2;
	}
  temp[0][0]/=3;
	temp[0][1]/=3;


	for(m0=0;m0<3;m0++){
		if(LPC_GPIO0->FIOPIN & 0X20) return 0;
		read_x_y(&m1,&m2);
		temp[1][0]+=m1;
		temp[1][1]+=m2;
	}
  temp[1][0]/=3;
	temp[1][1]/=3;


		for(m0=0;m0<3;m0++){
		if(LPC_GPIO0->FIOPIN & 0X20) return 0;
		read_x_y(&m1,&m2);
		temp[2][0]+=m1;
		temp[2][1]+=m2;
	}
		
  temp[2][0]/=3;
	temp[2][1]/=3;


	m0=temp[0][0]>temp[1][0]?temp[0][0]-temp[1][0]:temp[1][0]-temp[0][0];
	m1=temp[1][0]>temp[2][0]?temp[1][0]-temp[2][0]:temp[2][0]-temp[1][0];	
	m2=temp[0][0]>temp[2][0]?temp[0][0]-temp[2][0]:temp[2][0]-temp[0][0];	
	
  if(m0<m1){
		if(m0<m2) *x=(temp[0][0]+temp[1][0])/2;
		else      *x=(temp[0][0]+temp[2][0])/2;
	}
	else{
		if(m1<m2) *x=(temp[2][0]+temp[1][0])/2;
		else      *x=(temp[0][0]+temp[2][0])/2;
	}
	
	m0=temp[0][1]>temp[1][1]?temp[0][1]-temp[1][1]:temp[1][1]-temp[0][1];
	m1=temp[1][1]>temp[2][1]?temp[1][1]-temp[2][1]:temp[2][1]-temp[1][1];	
	m2=temp[0][1]>temp[2][1]?temp[0][1]-temp[2][1]:temp[2][1]-temp[0][1];	
	
  if(m0<m1){
		if(m0<m2) *y=(temp[0][1]+temp[1][1])/2;
		else      *y=(temp[0][1]+temp[2][1])/2;
	}
	else{
		if(m1<m2) *y=(temp[2][1]+temp[1][1])/2;
		else      *y=(temp[0][1]+temp[2][1])/2;
	}	
	
	return 1;
}


















