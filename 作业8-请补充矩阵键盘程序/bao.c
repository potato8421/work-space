#include <reg52.H>
#define u8 unsigned char
#define KEY  P3//定义变量，方便以后键盘接到其他的端口后，修改这里就行了，下面的程序不用再修改  
u8 num1,i;
u8 code keycode[16]={0xee,0xde,0xbe,0x7e,0xed,0xdd,0xbd,0x7d,0xeb,0xdb,0xbb,0x7b,0xe7,0xd7,0xb7,0x77};
void delay(long d){while(d--);}
void main(void) 
{
  KEY=0x0f;//初始状态，高位列，低电平；低位行，高电平 
  while(1) 
    { 
	   if(KEY!=0x0f)//如果有按键按下，则KEY肯定不是原来的0x0f
	   {
		   delay(2000);//延时20毫秒，以防按键的弹簧上下振荡，造成按下的假象
//请补充代码，检测按键，交换高低4位电平0xf0
//for循环keycode数组检测 break
			 if(KEY!=0x0f)num1=KEY;
			 KEY=0xf0;
			 if(KEY!=0x0f)num1=KEY+num1;
			 for(i=0;i<16;i++){if(num1==keycode[i]) break;}
		   KEY=0x0f;//KEY输出0x0f，恢复初始状态
	     while(KEY!=0x0f);//如果还在按下，等待放手
			 P2=i;//P2口输出给BCD数码管
	   }
    } 
}

