#include "reg52.h"
#include "intrins.h"
#define key P3^2
#define u8 unsigned char
#define u16 unsigned int
/*
ĿǰЧ����ֻ��1����

��Ҫ���ⲿ�жϣ��ı䷽����ɱ���ѭ���ٷ���
��Ҫ���ⲿ�жϣ��ı䷽��break����ѭ����������һͷ��ת
��Ҫ���ⲿ�жϣ�ԭ����ת����
*/
bit fang=0;
u8 a=0;
u8 code deng[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};
void delay(long i)
{	while(i--);}

void main()
{
	EA=1;IT0=1;EX0=1;//�ⲿ�ж�
	while(1)
	{
		if(fang)
		{
			P1=deng[a];//0xfe;//������һ����1111 1110
			delay(2000);a++;if(a==8)a=0;
		}
		else if(!fang)
		{
			P1=deng[a];//0xfe;//������һ����1111 1110
			delay(2000);
			a--;if(a==-1)a=7;
		}
		
	}
}
void bao() interrupt 0//�ⲿ�ж�0
{
	if(key==0)
	{
		fang=!fang;	
	}
}
