#include "led.h"
#include "delay.h"

void led_Init(void)//记得在main里调用该函数
{
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO结构类型结构体变量
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;//二进制按位与，实现连接两个外设
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //初始化GPIO配置
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //初始化GPIO配置
	GPIO_Init(GPIOD,& GPIO_InitStructure);
	delay_init(72);
}

void Set()//闪灯
{
	GPIO_SetBits(GPIOD,GPIO_Pin_0);//输出高电平
	delay_ms(500);//暂停500毫秒
	GPIO_ResetBits(GPIOD,GPIO_Pin_0);//输出低电平
	GPIO_SetBits(GPIOD,GPIO_Pin_1);//输出高电平
	delay_ms(500);//暂停500毫秒
	GPIO_ResetBits(GPIOD,GPIO_Pin_1);//输出低电平
}


