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
 void write_cmd(uchar cmd)   //向lcd写一命令
{
	read_busy();  					 //查忙
	RS=0;							 //命令/数据选择,为0时选择命令 
	RW=0;							 //读/写选择，为0时选择写
	E=0;
//	_nop_();
//  	_nop_(); 
	delayms(20);	
	P0=cmd;				 //送入命令
	delayms(1);				//等待
	E=1;							
	delayms(1);
	E=0;
}
//////////////////////////////////////////////////////////////////////////////////////////
void write_dat(uchar dat) 	//向LCD写一数据
{
	read_busy(); 
	RS=1;            //H为数据
	RW=0;
	E=0;
	P0=dat;
	delayms(1);
	E=1;
	delayms(1);
	E=0;
}
//////////////////////////////////////////////////////////////////////////////
void initlcd()    //LCD初始化
{
	//PSB=1;     //设置为8BIT并口工作模式  H并行 L串行
	delayms(5);
	write_cmd(0x34);
	delayms(2);
	write_cmd(0x30);  //选择扩充指令集
	delayms(2);
	write_cmd(0x0c);  //开显示，无游标
	delayms(2);
	write_cmd(0x01);	//清除显示，并且设定地址指针为00H
	delayms(2);
	write_cmd(0x06);	//指定在资料的读取及写入时，设定游标的移动方向及指定显示的移位
}
////////////////////////////////////////////////////////////////////////////////////////////
void dis(uchar x,uchar y,uchar code *s)  //任意位置显示字符串
{                     //x为横坐标，y位纵坐标，*s表示指针，为数据的首地址
	switch(x)    						//选择纵坐标
	{
		case 0:write_cmd(0x80+y);break;  //第一行
		case 1:write_cmd(0x90+y);break;	 //第二行
		case 2:write_cmd(0x88+y);break;  //第三行
		case 3:write_cmd(0x98+y);break;  //第四行
		case 4:write_cmd(0xa0+y);break;  //第五行 2
		case 5:write_cmd(0xb0+y);break;	 //第六行 3
		case 6:write_cmd(0xa8+y);break;  //第七行 0
		case 7:write_cmd(0xb8+y);break;  //第八行 1
		default:break;
	}
	while(*s>0)										 //写入数据，直到数据为空
	{
		write_dat(*s);									 //写数据
		delayms(10);									//下一字符
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