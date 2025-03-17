#ifndef _menu_object_control
#define _menu_object_control





typedef struct button_stat{
	unsigned char stat;
} button_menu;

typedef struct switch_stat{
	unsigned char stat;
} switch_menu;

typedef struct bar_stat{
	unsigned char stat;
	unsigned short int value;
} bar_menu;




extern button_menu page_3_button[4];

extern switch_menu page_0_switch;
extern button_menu page_0_decrase_switch;
extern button_menu page_0_incrase_switch;



extern bar_menu page_1_bar;
extern bar_menu page_1_bar_shodow;
extern bar_menu page_1_1_shodow;
extern bar_menu page_1_1;
extern bar_menu page_1_bar_text_shodow;
extern bar_menu page_1_bar_text;



extern bar_menu    page_0_time_information;
extern bar_menu    page_0_time_information_shodow;



extern void install_menu_machine(void);
extern void update_page_3(void);
extern void update_page_1(void);
extern void update_page_0(void);







#define button_menu_on   1
#define button_menu_off  0
#define button_menu_push 2

#define switch_menu_mode_0 0
#define switch_menu_mode_1 1


#define bar_menu_enable   1
#define bar_menu_disable  1



#define button_menu_push_colour_low  0
#define button_menu_push_colour_high  147


#define button_menu_on_colour_low    3
#define button_menu_on_colour_high   57


#define button_menu_off_colour_low    0
#define button_menu_off_colour_high  19 

////////////////////////////////////////////////////////////////////////////////////////////////
//////this function source is circle_machine///////////////////////////////////////

extern void cicle(void);


////////////////////////////////////////////////////////////////////////////////////////////////
//////this function source is page1_bar///////////////////////////////////////
extern void install_bar_1_page_1(void);
extern void control_page_1_bar(void);
extern unsigned char *ram_picture_c;
extern void print_power_factor(void);

/////////////////////////////////////////////////////////////////////////////////
/////////////////////page 0 timer bar text function//////////////////////////////
extern void install_page_0_time_bar(void);
extern int page_0_print_a_number(int num,int x,int y);	




#endif
