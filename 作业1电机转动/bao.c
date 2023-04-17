#include <reg52.h>
/*
  低要求：添加代码，控制P11的灯
  中要求：添加P16、P17的引脚命名，添加代码，使电机能够启、停
  高要求：添加黄灯及代码，使之工作
*/
sbit dong0=P1^0;//东西红，南北绿
sbit dong1=P1^1;
sbit dong2=P1^2;
sbit dong3=P1^6;
sbit dong4=P1^7;
void delay(long i){while(i--);}//延时0到40亿次
void delay_s()
{
dong3=!dong3;
		delay(5000);//延时一段时间
		dong4=!dong4;
		delay(5000);//延时一段时间


}
void main(void)//void空，可以省略
{
	dong0=0;
//	dong1=0;
//	dong2=0;
	dong4=0;
	dong3=0;
	//开机默认全部高电平，全灭；先设置其中1路为低电平
	while(1)
	{
		
		P2=~P2;//P2端口的8个引脚，全部取反
		//dong=!dong;//!位取反，~所有位取反
		dong2=1;
		//delay(5000);
		dong0=1;//灭
		//delay(5000);//延时一段时间
		dong1=0;//灭
		delay_s();//延时一段时间
		
		dong0=1;//灭
		//delay(5000);//延时一段时间
		dong1=1;//灭
		//delay(5000);//延时一段时间
		dong2=0;
		delay_s();
		
		dong1=1;//灭
		//delay(5000);//延时一段时间
		dong2=1;
		//delay(5000);
		dong0=0;//灭
		delay_s();//延时一段时间
		
		

		
	}
}
