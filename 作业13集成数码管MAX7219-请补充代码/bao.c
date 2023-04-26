#include <reg52.h>
#define u8 unsigned char
#define u16 unsigned int
#include "max7219.h"	

void delay(long i){while(i--);}//±21亿次
/*
patato8421 6666666 2023 04 26
高要求作业 
*/
void main()
{
	MAX_init();//初始化
	MAX_sends(2,0x6d);
	MAX_sends(3,0x7e);
	MAX_sends(4,1);
	MAX_sends(5,0x6d);
	MAX_sends(6,0x6d);
	MAX_sends(7,0);
	MAX_sends(8,0xb3);
//补充8行代码，显示"2023 04 20"
	while(1)  {MAX_sends(1,deng[i++]);delay(20000);if(i==9)i=0;}//显示完了，单片机空闲了，该干嘛干嘛去
}
