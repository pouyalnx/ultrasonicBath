#ifndef _timer_con_machine
#define _timer_con_machine

extern struct timer_con_stat{
	int time_cont;
  volatile	int time_value;
	volatile  int update_req;
}on_off_timer;


extern  void TIMER0_IRQHandler(void);
extern  void start_timer_on_off(void);
extern 	void stop_timer_on_off(void); 


////////////////////////////////////////////
////////////////////////////////////////////

extern struct main_core_stat{
  volatile int power_stat;
	volatile int power_value;
	volatile int mode;
}stat_power;




extern void turn_on_module(void);
extern void  sweep_mode_operation(void);
extern void normal_mode_operation(void);
extern void TIMER1_IRQHandler(void);















#endif
