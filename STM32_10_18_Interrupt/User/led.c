#include "main.h"
#include "led.h"

void led_Init(void)//记得在main里调用该函数
{
	delay_init(72);
	GPIO_InitTypeDef GPIO_InitStructure;//定义GPIO结构类型结构体变量
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);//使能时钟
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; //初始化GPIO配置
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //初始化GPIO配置
	GPIO_Init(GPIOD,& GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_0);//亮灯
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//使能
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //下拉输入模式，默认为高电平
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //初始化GPIO配置
	GPIO_Init(GPIOA,& GPIO_InitStructure);
}
