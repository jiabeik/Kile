#include "main.h"
#include "led.h"

void led_Init(void)//记得在main里调用该函数
{
	delay_init(72);
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO结构类型结构体变量
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);//使能时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //初始化GPIO配置
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //初始化GPIO配置
	GPIO_Init(GPIOD,& GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_0);
	GPIO_ResetBits(GPIOD,GPIO_Pin_1);//灭灯
}

void LED0_ON(void)
{
	GPIO_SetBits(GPIOD,GPIO_Pin_0);//0亮灯
}

void LED0_OFF(void)
{
	GPIO_ResetBits(GPIOD,GPIO_Pin_0);//0灭灯
}

void LED1_ON(void)
{
	GPIO_SetBits(GPIOD,GPIO_Pin_1);//1亮灯
}

void LED1_OFF(void)
{
	GPIO_ResetBits(GPIOD,GPIO_Pin_1);//1灭灯
}

