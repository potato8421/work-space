#include <reg52.h>
/*
  ��Ҫ����Ӵ��룬����P11�ĵ�
  ��Ҫ�����P16��P17��������������Ӵ��룬ʹ����ܹ�����ͣ
  ��Ҫ����ӻƵƼ����룬ʹ֮����
*/
sbit dong0=P1^0;//�����죬�ϱ���
sbit dong1=P1^1;
sbit dong2=P1^2;
sbit dong3=P1^6;
sbit dong4=P1^7;
void delay(long i){while(i--);}//��ʱ0��40�ڴ�
void delay_s()
{
dong3=!dong3;
		delay(5000);//��ʱһ��ʱ��
		dong4=!dong4;
		delay(5000);//��ʱһ��ʱ��


}
void main(void)//void�գ�����ʡ��
{
	dong0=0;
//	dong1=0;
//	dong2=0;
	dong4=0;
	dong3=0;
	//����Ĭ��ȫ���ߵ�ƽ��ȫ������������1·Ϊ�͵�ƽ
	while(1)
	{
		
		P2=~P2;//P2�˿ڵ�8�����ţ�ȫ��ȡ��
		//dong=!dong;//!λȡ����~����λȡ��
		dong2=1;
		//delay(5000);
		dong0=1;//��
		//delay(5000);//��ʱһ��ʱ��
		dong1=0;//��
		delay_s();//��ʱһ��ʱ��
		
		dong0=1;//��
		//delay(5000);//��ʱһ��ʱ��
		dong1=1;//��
		//delay(5000);//��ʱһ��ʱ��
		dong2=0;
		delay_s();
		
		dong1=1;//��
		//delay(5000);//��ʱһ��ʱ��
		dong2=1;
		//delay(5000);
		dong0=0;//��
		delay_s();//��ʱһ��ʱ��
		
		

		
	}
}
