#include "reg51.h"
#define u8 unsigned char
#define u16 unsigned int

sbit pwm=P2^0;//发出PWM波
/*
高低电平的方波，控制角度
整个周期20ms
中国220V 50Hz=20ms，美国110V 60Hz

	目前效果：转动到+90度
低要求：转动到0度
中要求：转动到先转到+90度，然后-90度，然后是0度
高要求：先+90，然后-90，最后是(学号最后2位-22.5)*3
误差±2°
*/
void delay(u16 i){while(i--);}
void sudu1()
{
	pwm=1;delay(2.1*110);//调整时间
	pwm=0;delay(2.1*110);//调整时间
}
void sudu2()
{
	pwm=1;delay(0.9*110);//调整时间
	pwm=0;delay(0.9*110);//调整时间
}
void sudu3()
{
	pwm=1;delay(1.494*110);//调整时间
	pwm=0;delay(1.494*110);//调整时间
}
u16 k=0;
void main()
{
	while(1)
	{
		k++;
		if(k>1000&&k<1500)
			sudu3();
		else if(k>500&&k<1000)
			sudu2();
		else if(k>0&&k<=500)
			sudu1();
		else if(k==1500)
			k=0;
	}
	

}
