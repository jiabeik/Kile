#include "Interrupt.h"
#include "led.h"
#include "main.h"

void Inte_Init()//初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);//使能时钟
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource4);//外部中断线4——PA4引脚

	NVIC_InitTypeDef NVIC_InitStructure;//命名结构体
	EXTI_InitTypeDef EXTI_InitStructure;
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;//配置外部中断 X 的中断优先级
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;//配置抢占优先级 0~16
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;//配置子优先级,越低越优先 0~16
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;//使能外部中断通道
	NVIC_Init(&NVIC_InitStructure);//将信号传给主板
	
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;//配置中断线 X
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling; //设置触发方式,上升沿
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;//使能
	EXTI_Init(&EXTI_InitStructure);//配置
}

void EXTI4_IRQHandler(void)
{
	GPIO_ResetBits(GPIOD,GPIO_Pin_0);
	EXTI_ClearITPendingBit(EXTI_Line4);//清除中断线 X 上的中断标志位	
}
