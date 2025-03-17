#ifndef _del_touch_123
#define _del_touch_123



extern void setup_touch_interface(void);
extern int touch_read(int *x,int *y);
extern int check_touch(int x,int y);

//////////////////////////////////////
////////debug function///////////////
extern void setup_debug_uart(void);
extern void debug_text(char *in);	

#endif

