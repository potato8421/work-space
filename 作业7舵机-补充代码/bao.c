#include "reg51.h"
#define u8 unsigned char
#define u16 unsigned int

sbit pwm=P2^0;//����PWM��
/*
�ߵ͵�ƽ�ķ��������ƽǶ�
��������20ms
�й�220V 50Hz=20ms������110V 60Hz

	ĿǰЧ����ת����+90��
��Ҫ��ת����0��
��Ҫ��ת������ת��+90�ȣ�Ȼ��-90�ȣ�Ȼ����0��
��Ҫ����+90��Ȼ��-90�������(ѧ�����2λ-22.5)*3
����2��
*/
void delay(u16 i){while(i--);}
void sudu1()
{
	pwm=1;delay(2.1*110);//����ʱ��
	pwm=0;delay(2.1*110);//����ʱ��
}
void sudu2()
{
	pwm=1;delay(0.9*110);//����ʱ��
	pwm=0;delay(0.9*110);//����ʱ��
}
void sudu3()
{
	pwm=1;delay(1.494*110);//����ʱ��
	pwm=0;delay(1.494*110);//����ʱ��
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
