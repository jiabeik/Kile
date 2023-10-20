#include "main.h"
#include "Interrupt.h"
#include "led.h"

int main()
{
	led_Init();//LED初始化——亮灯
	Inte_Init();//中断初始化
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//优先级分组——跳到中断
	//GPIO_SetBits(GPIOD,GPIO_Pin_0);
	
	while(1)
	{
		if(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4))
		{
			GPIO_SetBits(GPIOD,GPIO_Pin_0);
		}
	}
}
