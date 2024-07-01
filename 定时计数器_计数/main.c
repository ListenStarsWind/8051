/*********************************************************************************
* 【作    者】：	听风若依
* 【版    本】：	V1.0
* 【实验平台】：	清翔 QX-MCS51 单片机开发板
* 【外部晶振】： 	11.0592mhz	
* 【主控芯片】： 	STC89C52
* 【编译环境】： 	Keil μVisio5
* 【编辑环境】： 	VS code		
* 【程序功能】： 	计数器0工作模式1，16位计数模式，//定时器1工作模式1，16位定时模式。每过1秒，通过P1^0口对P3^4施加一次外部脉冲，用数码管显示脉冲次数。		   			            			    
* 【使用说明】： 	用一根杜邦线把P34引脚对应排针与P10引脚对应的排针链接到一起
					P10产生方波 数码管显示方波次数
**********************************************************************************/
#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

uchar i = 0;//毫秒储存变量

ulong k = 0;//秒储存变量
uchar  code dula [10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,};//共阴极数码管段选表

sbit we = P2^7;//数码管位选
sbit du = P2^6;//数码管段选
sbit pulse = P1^0;//外部脉冲施加口

/*====================================
函数	： delay(uint z)
参数	：z 延时毫秒设定，取值范围0-65535
返回值	：无
描述	：12T/Fosc11.0592M毫秒级延时
====================================*/
void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--); 		
} 

void CounterInitialization()//计数器0初始化函数
{
	TR0 = 1;     //计数器0启动
	TMOD |= 0x05;//计数器0工作模式1,16位计数模式
	TL0 = 0x00;
	TH0 = 0x00;
}

void TimerInitialization()//定时器1初始化函数
{
	TR1 = 1;	 //计数器0启动
	TMOD |= 0X10; //计数器0工作模式1,16位计数模式
    TH1 = 0x4b;
	TL1 = 0xfd; //定时50ms
}

/*====================================
函数	：display(uchar i)
参数	：i 显示数值，取值范围0-99999999
返回值	：无
描述	：三位共阴数码管动态显示
====================================*/
void dispiay(ulong i)
{
uchar qianwan,baiwan,shiwan,wan,qian,bai,shi,ge;
qianwan = i/10000000;
baiwan  = i%10000000/1000000;
shiwan = i%1000000/100000;
wan = i%100000/10000;
qian = i%10000/1000;
bai = i%1000/100;
shi = i%100/10;
ge = i%10;
		du = 0;
		we = 0;
		delay(5);
		
		P0 = 0XFE;
		we = 1;
		we = 0;
		P0 = dula[qianwan];
		du = 1;
		du = 0;
		delay(5);
		
		P0  = 0xfd;
		we = 1;
		we = 0;
		P0 = dula[baiwan];
		du = 1;
		du = 0;
		delay(5);
		
		P0  = 0xfb;
		we = 1;
		we = 0;
		P0 = dula[shiwan];
		du = 1;
		du = 0;
		delay(5);
		
		P0  = 0xf7;
		we = 1;
		we = 0;
		P0 = dula[wan];
		du = 1;
		du = 0;
		delay(5);

		P0  = 0xef;
		we = 1;
		we = 0;
		P0 = dula[qian];
		du = 1;
		du = 0;
		delay(5);
		
		
		P0  = 0xdf;
		we = 1;
		we = 0;
		P0 = dula[bai];
		du = 1;
		du = 0;
		delay(5);
		
		
		P0  = 0xbf;
		we = 1;
		we = 0;
		P0 = dula[shi];
		du = 1;
		du = 0;
		delay(5);
		
		
		P0  = 0x7f;
		we = 1;
		we = 0;
		P0 = dula[ge];
		du = 1;
		du = 0;
		delay(5);
}

void main()
{
    CounterInitialization();//计数器0初始化
	TimerInitialization(); //定时器1初始化
	while (k < 99999999)
	{
		while (i < 20)
		{
			if (1 == TF1)
			{
				TF1 = 0;
				TL1 = 0xfd;
				TH1 = 0x4b;
				i++;
			}
		}
		if (20 == i)
		{
		    i = 0;
			pulse = ~pulse;
		}
		dispiay(TL0);
		dispiay(TL0);
		dispiay(TL0);
		dispiay(TL0);
    dispiay(TL0);
		dispiay(TL0);
		
	}
}
