#include "reg52.h"

#define u8 unsigned char
#define u16 unsigned int
/*
ĿǰЧ����ֻ��1����

��Ҫ��8�������ε������ֱ���ʾ0.1�롣����ѭ��
��Ҫ����������
��Ҫ�󣺰��������ٶ�
�ռ�Ҫ�󣺰��������ٶȣ�ͬʱ���Ʒ���
*/
sbit key_fang=P2^0;//�������� direction
sbit key_sudu=P2^1;//�ٶȿ��� a1 a2 a3 a4 a5

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
		
//		P1=0xfe;//������һ����1111 1110
//		delay(2000);
		
//		P1=1111 1101;//fd
//		delay(2000);
//		
//		P1=FBI;F7
		//�����1000���ƣ�д1000��P1��delay
	
}
