#include "reg52.h"
#define u8 unsigned char
#define u16 unsigned int
#include "uart.h"
/*
	目前效果：
开机后，打印一串字符
接收到上位机信息后，P1显示对应的ASCII
patato8421 6666666 2023 04 26
高要求作业 
低要求：按下按键后，打印输出自己的姓名学号
中要求：串口收到信息后，控制电机的方向
高要求：串口收到01234，控制电机的方向、速度
*/
sbit key1=P3^2;//按下后，打印姓名学号
sbit motor1=P2^0;
sbit motor2=P2^1;
u8 flag=0;//0停机，1顺快，2顺慢，3逆快，4逆慢

void delay(long i){while(i--);}

void main()
{
	UART1_init();//9600bps
	UART1_Sends("湾大电子，F u everyday\r\n");
	motor1=0;motor2=0;//停机
	
	while(1)
	{
		if(key1==0)//按下了？
		{
			while(key1==0);//等待放手
//补充代码，发送姓名学号
				UART1_Sends("2104413122\r 2104413125\r\n");

		}
//补充代码，根据flag控制电机方向、速度
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

void UART_INT(void) interrupt 4//接收到上位机信息
{
	if(RI)//串口输入引起的中断
	{
		P1=SBUF;//P1显示收到字符的ASCII
		RI=0;//清空中断
//补充代码，改变电机flag
		flag=SBUF;
	}
	else TI=0;//串口输出引起的中断
}
