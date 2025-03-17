#ifndef _lpc_sys_pwm
#define _lpc_sys_pwm

#define safe_freq  27000
#define safe_power_decarsor_factor 5
#define power_var                  1 
#define pwm_module_freq            100000000

/*
ns transistor_switching_time 

ns=pwm_module_freq*transistor_on_off_time

*/



#define safe_t_priod_on_of_transistor 500 //5us required //attention maybe changed



#define min_t_size_for_out 2500
#define max_t_size_for_out 5000

#define power_safe_period_non_error 100

/*
up_value=pwm_freq/input_freq
max_freq 40khz
min_freq 20khz

*/



extern int setup_pwm(void);
extern int stop_pwm(void);
extern int update_pwm(int freq,int power_decrasor);

#endif


