#include "reg51.h"
#define u8 unsigned char
/*
��ǰ����ʱ��ȫ����ͨ��delayʵ�ֵģ�̫��ô������
LED��������ˮ�ơ�����ܡ���������ֱ������������������������̡���
delay(long i){while(i--);}������һ�и㶨��
����˭��
��ͨ�ƣ�
11NHz�����£�ʵ�ﶨʱ1����delay(20000)��ֻ��0.868��
�������涨���30�룬��������26��
��Ͷ�ߣ��������������������Ŷ�
�ͳ���Ƭ��С���飬ͨ��Ӳ����ʱ��ʵ��us����׼��ʱ

Ŀǰ��ÿ50ms�Զ��ж�1�Ρ������ж��ӳ��򲹳佻ͨ�ƴ���
��Ҫ��Ӳ����ʱ��ʵ�ֶ������ϱ��ĺ�ơ��̵ƽ���仯
��Ҫ�󣺺��10s���̵�7s���Ƶ�3s
��Ҫ��ͬ�ϣ��Ƶ���˸���Σ����������ʾ�ϱ������10s��7s��3s����ʱ
*/
u8 ms50=0,miao=0,miao1=0;
//u8 code deng[]={0x0B,0x0E,0x0D,0x0F};
u8 deng[]={0xBE,0xBD,0xBF,0xBD,0xBF,0xEB,0xDB,0xFB,0xDB,0xFB};
void T0_init(void)//��ʱ����ʼ��
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
	T0_init();//��ʱ����ʼ��
	while(1);//����20��
}

void T0_INT(void) interrupt 1//ÿ��50ms�Զ�����һ��
{
    TH0 = 0x3C;//�ָ���ʱ������ֵ
    TL0 = 0xB0;//�ָ���ʱ������ֵ
//�벹����򣬿���ms50��miao
	ms50++;
	if(ms50%20==0) miao++;//1s
	if(miao<=7&&miao>=0)miao1=7-miao;
	else if(miao>7&&miao<=10)miao1=11-miao;
	else miao1=21-miao;
	P3=((miao1/10)<<4)+(miao1%10);//BCD����ܣ���4λ����4λ
//	if(miao==0)P2=deng[0];//�ϱ��̣�������101 1 1110
//else if�벹����򣬿����ϱ��죬������
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
