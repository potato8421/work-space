#include "reg51.h"
/*
ĿǰЧ����LED�Ƶ���˸

��Ҫ��
  LED�Ƶƣ����������̣��ٳ�ʱ��Ϩ���Դ�ѭ��
  ���磬��2����0.5�룬��2����0.5�룬��2����0.5�룬��0.5����0.5�룬��0.5����0.5�룬��5�롣��ѭ��

��Ҫ��
  RGB�ƣ�һ������һ����

��Ҫ��
  LED�Ƶƣ���ͨ��˸
  ͬʱ��RGB�ƣ�һ������һ����
  LED�Ƶƺ�RGB�ƣ����಻Ӱ��
*/

sbit led0=P2^0;//��������
sbit led1=P2^1;//��������
sbit led2=P2^2;//��������
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
		delay_s(22000);//0-40��
		led0=1;//off
		delay_s(22000);//0-40��
		

			
		}
		
		

//		led0=0;//on
//		delay_s(5000);


	}
