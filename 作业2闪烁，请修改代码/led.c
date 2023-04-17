#include "reg51.h"
/*
目前效果：LED黄灯闪烁

低要求：
  LED黄灯，先三长两短，再长时间熄灭。以此循环
  例如，亮2秒灭0.5秒，亮2秒灭0.5秒，亮2秒灭0.5秒，亮0.5秒灭0.5秒，亮0.5秒灭0.5秒，灭5秒。死循环

中要求：
  RGB灯，一个暗，一个亮

高要求：
  LED黄灯，普通闪烁
  同时，RGB灯，一个暗，一个亮
  LED黄灯和RGB灯，互相不影响
*/

sbit led0=P2^0;//定义引脚
sbit led1=P2^1;//定义引脚
sbit led2=P2^2;//定义引脚
long j=0;
int k=0;
void delay(long i){while(i--);}
void delay_s(long i)
{int sum=i/20;
	for(j=0;j<=sum;j+=11)
	{
		led2=0;
		delay(20);//20*1
		led2=1;
		delay(200);//20*10
		}
	
}
void main()
{
	
	led1=0;
	while(1)
	{
		led0=0;//off
		delay_s(22000);//0-40亿
		led0=1;//off
		delay_s(22000);//0-40亿
		

			
		}
		
		

//		led0=0;//on
//		delay_s(5000);


	}
