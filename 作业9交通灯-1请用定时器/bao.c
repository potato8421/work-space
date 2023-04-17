#include "reg51.h"
#define u8 unsigned char
/*
以前的延时，全部是通过delay实现的，太特么方便了
LED亮暗、流水灯、数码管、蜂鸣器、直流、步进、舵机、按键、键盘……
delay(long i){while(i--);}，老子一行搞定！
还有谁？
交通灯！
11NHz晶振下，实物定时1秒大概delay(20000)，只有0.868秒
本来，规定红灯30秒，结果变成了26秒
被投诉，被开除，饿死冻死在桥洞
掏出单片机小精灵，通过硬件定时器实现us级精准定时

目前：每50ms自动中断1次。请在中断子程序补充交通灯代码
低要求：硬件定时，实现东西、南北的红灯、绿灯交替变化
中要求：红灯10s，绿灯7s，黄灯3s
高要求：同上，黄灯闪烁几次，且数码管显示南北方向的10s、7s、3s倒计时
*/
u8 ms50=0,miao=0,miao1=0;
//u8 code deng[]={0x0B,0x0E,0x0D,0x0F};
u8 deng[]={0xBE,0xBD,0xBF,0xBD,0xBF,0xEB,0xDB,0xFB,0xDB,0xFB};
void T0_init(void)//定时器初始化
{
    TMOD = 0x01;
    TH0 = 0x3C;
    TL0 = 0xB0;
    EA = 1;
    ET0 = 1;
    TR0 = 1;
}

void main(void)
{
	T0_init();//定时器初始化
	while(1);//周期20秒
}

void T0_INT(void) interrupt 1//每隔50ms自动进来一次
{
    TH0 = 0x3C;//恢复定时器的数值
    TL0 = 0xB0;//恢复定时器的数值
//请补充程序，控制ms50和miao
	ms50++;
	if(ms50%20==0) miao++;//1s
	if(miao<=7&&miao>=0)miao1=7-miao;
	else if(miao>7&&miao<=10)miao1=11-miao;
	else miao1=21-miao;
	P3=((miao1/10)<<4)+(miao1%10);//BCD数码管，高4位，低4位
//	if(miao==0)P2=deng[0];//南北绿，东西红101 1 1110
//else if请补充程序，控制南北红，东西绿
	if(miao==1)P2=deng[0];
	else if(miao==7)P2=deng[1];
	else if(miao==8)P2=deng[2];
	else if(miao==9)P2=deng[3];
	else if(miao==10)P2=deng[4];
	else if(miao==11)P2=deng[5];
	else if(miao==17)P2=deng[6];
	else if(miao==18)P2=deng[7];
	else if(miao==19)P2=deng[8];
	else if(miao==20)P2=deng[9];

	if(miao==20)miao=0;
}
