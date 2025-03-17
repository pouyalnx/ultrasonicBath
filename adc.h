#ifndef _ultra_adc_1
#define _ultra_adc_1

//#define adc_allowed_sample 20
#define adc_power_cal_mode_simple 11
#define adc_simple_freq     350000

extern void setup_adc(void);

//extern int adc_sample(int *);
extern int adc_simple_mode_power(int simple);

//extern void ADC_IRQHandler(void);


#endif

