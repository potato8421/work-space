#include "reg52.h"
#define u8 unsigned char
#define u16 unsigned int
#include "uart.h"
/*
	ĿǰЧ����
�����󣬴�ӡһ���ַ�
���յ���λ����Ϣ��P1��ʾ��Ӧ��ASCII
patato8421 6666666 2023 04 26
��Ҫ����ҵ 
��Ҫ�󣺰��°����󣬴�ӡ����Լ�������ѧ��
��Ҫ�󣺴����յ���Ϣ�󣬿��Ƶ���ķ���
��Ҫ�󣺴����յ�01234�����Ƶ���ķ����ٶ�
*/
sbit key1=P3^2;//���º󣬴�ӡ����ѧ��
sbit motor1=P2^0;
sbit motor2=P2^1;
u8 flag=0;//0ͣ����1˳�죬2˳����3��죬4����

void delay(long i){while(i--);}

void main()
{
	UART1_init();//9600bps
	UART1_Sends("�����ӣ�F u everyday\r\n");
	motor1=0;motor2=0;//ͣ��
	
	while(1)
	{
		if(key1==0)//�����ˣ�
		{
			while(key1==0);//�ȴ�����
//������룬��������ѧ��
				UART1_Sends("2104413122\r 2104413125\r\n");

		}
//������룬����flag���Ƶ�������ٶ�
		switch(flag)
		{
			case '0':P2=0x00;break;
			case '1':P2=0x01;break;
			case '2':P2=0x01;delay(110*17);P2=0x00;delay(110*17);break;
			case '3':P2=0x02;break;
			case '4':P2=0x02;delay(110*17);P2=0x00;delay(110*17);break;		
		}
	}
}

void UART_INT(void) interrupt 4//���յ���λ����Ϣ
{
	if(RI)//��������������ж�
	{
		P1=SBUF;//P1��ʾ�յ��ַ���ASCII
		RI=0;//����ж�
//������룬�ı���flag
		flag=SBUF;
	}
	else TI=0;//�������������ж�
}
