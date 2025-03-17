#ifndef lpc_lcd_123
#define lpc_lcd_123
#include "lpc17xx.h"



#define wr 256
#define rs 512
#define cs 1024
#define rd 2048
#define rst 4096
#define lcd_page_size 15000
//21760






extern unsigned char high_byte_pattern[16];
extern unsigned char low_byte_pattern[16];
#define back_ground_colour_code_two_pixel 0xff



struct POSITION{
	short int x,y;
};

typedef struct POSITION   pos;

extern unsigned char page_lcd[15000];
extern unsigned char page_lcd_2[952];

extern void setup_lcd_base(void);
extern void update_lcd_page(int page);
extern void print_img(const unsigned char *data,uint32_t data_size,pos start,pos end);
extern void copy_img_colour_bar(const unsigned char *data);



extern void write_page(const unsigned char *pattern,unsigned int size,pos start,pos end);
extern void write_page_dynamic_addr(unsigned char *pattern,unsigned int size,pos start,pos end);

#endif

