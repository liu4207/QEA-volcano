#include "stm32f10x.h"                  // Device header
#include "delay.h"

void Key_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}


uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0)
	{
		//delay_ms(20);
		//while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 0);
		KeyNum = 2;
		//delay_ms(40);
	}
	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 0)
	{
		//delay_ms(20);
		//while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 0);
		KeyNum = 3;
		//delay_ms(20);
	}
	
	return KeyNum;
}
