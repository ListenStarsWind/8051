#include "12864.h"

///////////////////////////////////////////////////////////////////////
void delayms(uint i)
{
	uchar j;
  while(i--)
			for(j=10;j>0;j--);
}
/////////////////////////////////////////////////////////////////////
void read_busy()
{
		uchar busy;
	  P0 = 0x00;
		RS = 0;
		RW = 1;
		do
		{
				E = 1;
				delayms(2);
				busy = P0;
				E = 0;
			 
				
		}while(busy & 0x80);
}
////////////////////////////////////////////////////////////////////////////////////////
 void write_cmd(uchar cmd)   //��lcdдһ����
{
	read_busy();  					 //��æ
	RS=0;							 //����/����ѡ��,Ϊ0ʱѡ������ 
	RW=0;							 //��/дѡ��Ϊ0ʱѡ��д
	E=0;
//	_nop_();
//  	_nop_(); 
	delayms(20);	
	P0=cmd;				 //��������
	delayms(1);				//�ȴ�
	E=1;							
	delayms(1);
	E=0;
}
//////////////////////////////////////////////////////////////////////////////////////////
void write_dat(uchar dat) 	//��LCDдһ����
{
	read_busy(); 
	RS=1;            //HΪ����
	RW=0;
	E=0;
	P0=dat;
	delayms(1);
	E=1;
	delayms(1);
	E=0;
}
//////////////////////////////////////////////////////////////////////////////
void initlcd()    //LCD��ʼ��
{
	//PSB=1;     //����Ϊ8BIT���ڹ���ģʽ  H���� L����
	delayms(5);
	write_cmd(0x34);
	delayms(2);
	write_cmd(0x30);  //ѡ������ָ�
	delayms(2);
	write_cmd(0x0c);  //����ʾ�����α�
	delayms(2);
	write_cmd(0x01);	//�����ʾ�������趨��ַָ��Ϊ00H
	delayms(2);
	write_cmd(0x06);	//ָ�������ϵĶ�ȡ��д��ʱ���趨�α���ƶ�����ָ����ʾ����λ
}
////////////////////////////////////////////////////////////////////////////////////////////
void dis(uchar x,uchar y,uchar code *s)  //����λ����ʾ�ַ���
{                     //xΪ�����꣬yλ�����꣬*s��ʾָ�룬Ϊ���ݵ��׵�ַ
	switch(x)    						//ѡ��������
	{
		case 0:write_cmd(0x80+y);break;  //��һ��
		case 1:write_cmd(0x90+y);break;	 //�ڶ���
		case 2:write_cmd(0x88+y);break;  //������
		case 3:write_cmd(0x98+y);break;  //������
		case 4:write_cmd(0xa0+y);break;  //������ 2
		case 5:write_cmd(0xb0+y);break;	 //������ 3
		case 6:write_cmd(0xa8+y);break;  //������ 0
		case 7:write_cmd(0xb8+y);break;  //�ڰ��� 1
		default:break;
	}
	while(*s>0)										 //д�����ݣ�ֱ������Ϊ��
	{
		write_dat(*s);									 //д����
		delayms(10);									//��һ�ַ�
		s++;
	}
}


void gun_xia()
{
 uchar i;
 for (i=63;i>0;i--)
 { 
  write_cmd(0x40+i);
		delayms(80000);
  write_cmd(0x30);
 }
}
 void gun_shang()
{
 uchar i;

 for (i=1;i<64;i++)
 { 
  write_cmd(0x40+i);
		delayms(3000);
  write_cmd(0x30);
 }
}