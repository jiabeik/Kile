#include "main.h"
#include "Interrupt.h"
#include "led.h"

int main()
{
	led_Init();//LED初始化——亮灯
	TimeInte_Init();//中断初始化
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//优先级分组——跳到中断
	//GPIO_SetBits(GPIOD,GPIO_Pin_0);
	while(1)
	{
			
	}
}



/*void TIM2_IRQHandler(void)
{
	
	int i = 2;
	if( TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET && i/2==1)//产生定时中断
	{
		LED0_ON();
		LED1_OFF();
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //将中断标志清除
		i = 1;
	}
	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET && i/2==1)//产生定时中断
	{
		LED1_ON();
		LED0_OFF();
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //将中断标志清除
		i = 2;
	}
		switch(i)
	{
		case 0:
			LED1_ON();
			LED0_OFF();
			i++;
			break;
		case 1:
			LED0_OFF();
			LED1_ON();
			i=0;
			break;
	}
	TIM_ClearFlag(TIM2,TIM_FLAG_Update); //清除更新中断标志位
}*/

