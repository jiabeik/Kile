#include "led.h"

int main()
{
	led_Init();
	while(1)
	{
		Set();
	}
}
