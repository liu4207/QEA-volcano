#include "stm32f10x.h"
#include "Key.h"
#include "delay.h"
#include "gpio.h"
#include "moto.h"
#include "pwm.h"
#include "adc.h"
#include "usart.h"
#include "encoder.h"

uint8_t KeyNum;

int main(void)
 {	

   Key_Init();
	 SystemInit(); //配置系统时钟为72M   
   delay_init();    //延时函数初始化
   uart_init(9600);		//串口初始化
	 
   PWM_Int(7199,0);      //初始化pwm输出 72000 000 /7199+1=10000 
   delay_ms(5);	 
  
	 moto(1);						//转弯
	 delay_ms(600);
	 //moto(0);						//直行
	 //delay_ms(300);
	 
	 moto(4);
	 delay_ms(1000);
	 delay_ms(1000);
	 
	 moto(5);
	 delay_ms(1000);
	 
	 moto(4);
	 delay_ms(600);
	 
	 moto(0);
	 delay_ms(500);
	 moto(3);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 delay_ms(1000);
	 
	 
	 /*
	 moto(1);
	 delay_ms(400);
	 moto(0);
	 delay_ms(450);
	 
	 moto(1);
	 delay_ms(350);
	 moto(0);
	 delay_ms(450);
	 
	 moto(1);
	 delay_ms(300);
	 moto(0);
	 delay_ms(500);
	 
	 moto(1);
	 delay_ms(350);
	 moto(0);
	 delay_ms(500);
	 
	 moto(1);
	 delay_ms(330);
	 moto(0);
	 delay_ms(10000);
	 delay_ms(10000);
	 
	 moto(3);
	 delay_ms(10000);
	 delay_ms(10000);
	 delay_ms(10000);
	 delay_ms(10000);
	 
	 */
 }
 
 