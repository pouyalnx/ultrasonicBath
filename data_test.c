#include    "0.h" 



		}
   
		
	switch(page){
	case 0:
	 for(gpv0=0;gpv0<80*272;gpv0++){
		page_lcd[gpv0]=0xee; 
	 }

  a.x=0;
  a.y=0;
	b.y=60;
	b.x=160;
	copy_img(number_table_0);
	print_img(data_img00,4800,a,b);

  a.x=0;
  a.y=100;
	b.y=150;
	b.x=160;
	print_img(data_img01,4000,a,b);	 

  a.x=30;
  a.y=150;
	b.y=200;
	b.x=130;
	print_img(data_img012,2500,a,b);	 	 
	 
	
  a.x=30;
  a.y=210;
	b.y=260;
	b.x=130;
	print_img(data_img02,2500,a,b);	
	
	break;
			
	case 2:
		copy_img(number_table); 
		
	 
	 for(gpv0=0;gpv0<80*272;gpv0++){
		page_lcd[gpv0]=0xee; 
	 }
		
	 a.x=30;
	 a.y=10;
	 b.x=130;
	 b.y=60;
	 
	 print_img(data_img1,2500,a,b);

	 a.x=30;
	 a.y=80;
	 b.x=130;
	 b.y=130;
	 
	 print_img(data_img2,2500,a,b);

	 a.x=30;
	 a.y=150;
	 b.x=130;
	 b.y=200;
	 
	 print_img(data_img3,2500,a,b);	 
	 
	 a.x=30;
	 a.y=220;
	 b.x=130;
	 b.y=270;
	 
	 print_img(data_img4,2500,a,b);	 
	 break;
   }
	 
   update_lcd_page(page);

		
const unsigned char data_imgxxx[]={


//4 bit mode img

0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x22, 0x11, 0x11, 0x11, 0x12, 0x11, 0x11, 0x11, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 
0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x21, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x22, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 
0x11, 0x11, 0x11, 0x22, 0x12, 0x11, 0x11, 0x12, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 
0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 0x21, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 
0x11, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 0x21, 0x22, 
0x22, 0x11, 0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x01, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x21, 0x12, 0x21, 0x12, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x21, 
0x12, 0x11, 0x11, 0x21, 0x22, 0x22, 0x11, 0x11, 0x12, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 
0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 0x21, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 
0x11, 0x21, 0x11, 0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x00, 0x10, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x22, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 0x21, 0x12, 0x11, 
0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x01, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 
0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x21, 0x22, 0x22, 0x12, 0x11, 0x12, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x12, 0x11, 0x21, 0x11, 
0x11, 0x11, 0x22, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x22, 0x11, 0x11, 0x21, 0x22, 0x22, 0x12, 
0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 
0x21, 0x12, 0x11, 0x21, 0x11, 0x11, 0x11, 0x21, 0x11, 
0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 
0x11, 0x11, 0x22, 0x21, 0x12, 0x11, 0x12, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x21, 0x12, 0x11, 0x21, 0x12, 0x11, 0x22, 
0x12, 0x11, 0x11, 0x22, 0x11, 0x11, 0x21, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 0x11, 0x21, 
0x12, 0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x21, 0x22, 
0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 
0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 
0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x12, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x10, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x12, 0x21, 0x22, 
0x12, 0x22, 0x22, 0x22, 0x12, 0x11, 0x11, 0x21, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 
0x12, 0x11, 0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x01, 0x00, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x22, 0x22, 0x12, 0x21, 0x22, 0x11, 0x21, 0x22, 0x22, 
0x11, 0x11, 0x11, 0x21, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x22, 0x21, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x12, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 
0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x12, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x10, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x22, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 
0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x21, 0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x21, 0x12, 0x11, 0x11, 
0x11, 0x21, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x22, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x22, 
0x22, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 
0x11, 0x21, 0x22, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x22, 
0x11, 0x11, 0x11, 0x21, 0x22, 0x12, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 
0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x22, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 
0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x12, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 
0x22, 0x22, 0x12, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x10, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x03, 0x00, 
};

const unsigned char number_table[]={


4, 0,  //size of table colours 


223, 4, //colour 0
13, 0, //colour 1
127, 254, //colour 2
159, 4, //colour 3

};
