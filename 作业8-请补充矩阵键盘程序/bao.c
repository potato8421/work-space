#include <reg52.H>
#define u8 unsigned char
#define KEY  P3//��������������Ժ���̽ӵ������Ķ˿ں��޸���������ˣ�����ĳ��������޸�  
u8 num1,i;
u8 code keycode[16]={0xee,0xde,0xbe,0x7e,0xed,0xdd,0xbd,0x7d,0xeb,0xdb,0xbb,0x7b,0xe7,0xd7,0xb7,0x77};
void delay(long d){while(d--);}
void main(void) 
{
  KEY=0x0f;//��ʼ״̬����λ�У��͵�ƽ����λ�У��ߵ�ƽ 
  while(1) 
    { 
	   if(KEY!=0x0f)//����а������£���KEY�϶�����ԭ����0x0f
	   {
		   delay(2000);//��ʱ20���룬�Է������ĵ��������񵴣���ɰ��µļ���
//�벹����룬��ⰴ���������ߵ�4λ��ƽ0xf0
//forѭ��keycode������ break
			 if(KEY!=0x0f)num1=KEY;
			 KEY=0xf0;
			 if(KEY!=0x0f)num1=KEY+num1;
			 for(i=0;i<16;i++){if(num1==keycode[i]) break;}
		   KEY=0x0f;//KEY���0x0f���ָ���ʼ״̬
	     while(KEY!=0x0f);//������ڰ��£��ȴ�����
			 P2=i;//P2�������BCD�����
	   }
    } 
}

