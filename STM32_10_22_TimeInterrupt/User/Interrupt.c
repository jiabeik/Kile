#include "Interrupt.h"
#include "led.h"
#include "main.h"

void TimeInte_Init()//初始化
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//使能时钟
	
	NVIC_InitTypeDef NVIC_InitStructure;//命名结构体
	TIM_TimeBaseInitTypeDef TIME_InitStructure;
	
	TIME_InitStructure.TIM_Prescaler = 10000; //预分频系数,降低计数频率
	TIME_InitStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数模式
	TIME_InitStructure.TIM_Period = 3600; //定时器周期，计数最大值——自动重装载值
	TIME_InitStructure.TIM_ClockDivision = TIM_CKD_DIV1; //定时器时钟分频因子
	TIME_InitStructure.TIM_RepetitionCounter = ENABLE;
	TIM_TimeBaseInit(TIM3,&TIME_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;//配置外部中断 X 的中断优先级
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//配置抢占优先级 0~16
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;//配置子优先级,越低越优先 0~16
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);//将信号传给主板
	
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);//打开时钟，使能溢出中断
	
	TIM_Cmd(TIM3, ENABLE);//使能定时器
}



/*void TIM2_IRQHandler(void)
{
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

void TIM3_IRQHandler(void)
{
	if( TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET)
		{
			GPIO_WriteBit(GPIOD, GPIO_Pin_0, !GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_0));//读取上一次灯的状态
			GPIO_WriteBit(GPIOD, GPIO_Pin_1, !GPIO_ReadOutputDataBit(GPIOD, GPIO_Pin_1));
			TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //将中断标志清除
		}
}

