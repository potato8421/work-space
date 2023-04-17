#include "reg52.h"

#define u8 unsigned char
#define u16 unsigned int
/*
目前效果：只亮1个灯

低要求：8个灯依次点亮，分别演示0.1秒。依次循环
中要求：左右流动
高要求：按键控制速度
终极要求：按键控制速度，同时控制方向
*/
sbit key_fang=P2^0;//方向左右 direction
sbit key_sudu=P2^1;//速度快慢 a1 a2 a3 a4 a5

void delay(long i){while(i--);}

void main()
{
	
	int c[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
	int a=1;
	
	int i=0;
	long b[]={1,5,8,11,14};
	int j=0;
	
	while(1)
	{ 
		if(key_fang==0)
		{
			while(1)
			{if(key_fang==1)
				break;
			}
			a++;
		}
		
		
		
		if(key_sudu==0)
		{
			while(1)
			{if(key_sudu==1)
				break;
			}
			if(j>=0&&j<4)
			j++;
			
			else 
				j=0;
		}
		
		
		
		
		if(a%2==1)
		{	
			if(i>7)
		{
			i=0;
		}
		P1=c[i++];
	
		delay(20000/b[j]);
		}
		
		
		else if(a%2==0)
		{
			if(i<0)
		{
			i=7;
		}
		P1=c[i--];
		
		delay(20000/b[j]);
		}
		
	}
//	
//		
//		
//		
//		
//		
//		
//		
//		
//		
//		
//		
//		
//		
//		
		
//		P1=0xfe;//点亮第一个灯1111 1110
//		delay(2000);
		
//		P1=1111 1101;//fd
//		delay(2000);
//		
//		P1=FBI;F7
		//如果有1000个灯，写1000个P1、delay
	
}
