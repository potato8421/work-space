#include "reg51.h"
#define u8 unsigned char
/*
	步进电机，2个编码之间，只变化1根信号线
目前效果：逆时针

低要求：改成顺时针转动
中要求：按键切换，控制速度
高要求：按键切换，控制方向
终极要求：切换速度速度、方向
*/	
//u8 code tab0[]={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};//8步
u8 code tab1[]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};//8步
sbit key_fang=P3^0;//方向 切换按键
sbit key_sudu=P3^1;//快慢 切换按键

bit flag_fang=0;//方向
bit flag_sudu=0;//速度

void delay(long i){while(i--);}

void main()
{
  u8 i=0;
	while(1)
  {
		if(i>7)
			i=0;
		
		if(key_fang==0)
		{
			while(key_fang==0);
			flag_fang=!flag_fang;
		}
			if(key_sudu==0)
		{
			while(key_sudu==0);
			flag_sudu=!flag_sudu;
		}
		if(flag_fang)
		{
			P2=tab1[8-i];i++;
		}
		else
		{
			P2=tab1[i++];
		}
		if(flag_sudu)
		{
			delay(1000);//1000--4000逆时针		
		}
		else
		{
			delay(4000);//1000--4000逆时针
		}
  }
}
