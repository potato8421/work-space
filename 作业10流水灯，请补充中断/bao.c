#include "reg52.h"
#include "intrins.h"
#define key P3^2
#define u8 unsigned char
#define u16 unsigned int
/*
目前效果：只亮1个灯

低要求：外部中断，改变方向，完成本次循环再反向
中要求：外部中断，改变方向，break本次循环，反向另一头跳转
高要求：外部中断，原地跳转反向
*/
bit fang=0;
u8 a=0;
u8 code deng[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void delay(long i)
{	while(i--);}

void main()
{
	EA=1;IT0=1;EX0=1;//外部中断
	while(1)
	{
		if(fang)
		{
			P1=deng[a];//0xfe;//点亮第一个灯1111 1110
			delay(2000);a++;if(a==8)a=0;
		}
		else if(!fang)
		{
			P1=deng[a];//0xfe;//点亮第一个灯1111 1110
			delay(2000);
			a--;if(a==-1)a=7;
		}
		
	}
}
void bao() interrupt 0//外部中断0
{
	if(key==0)
	{
		fang=!fang;	
	}
}
