/*************************************************************************************************************
 * 【作    者】：	听风若依
 * 【版    本】：	V1.0
 * 【实验平台】：	清翔 QX-MCS51 单片机开发板
 * 【外部晶振】： 11.0592mhz
 * 【主控芯片】： STC89C52
 * 【编译环境】： Keil μVisio5
 * 【编辑环境】： VS code
 * 【模式说明】： 定时器0工作模式1，16位定时模式。定时器1工作模式2, 8位自动重装。串口工作方式1，比特率9600。
 * 【使用说明】： 以中断方式进行串口通信，将接收到的数据用数码管显示。	
 **************************************************************************************************************/
#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
#define ulong unsigned long
sbit DU = P2 ^ 6;
sbit WE = P2 ^ 7;
ulong number = 0;
uchar code DUnumber[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; // 共阴极数码管段选表
uchar code WEnumber[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};             // 八位数码管位选表（低电位表示选中该数码管)
/*===========================================
函数	： disply(ulong i)
参数    ： i 设定显示数字，取值范围0-99999999
描述	： 八位共阴极数码管显示函数。
===========================================*/
void disply(ulong i)
{

    static uchar location;
    P0 = 0xFF;
    WE = 1;
    P0 = WEnumber[location];
    WE = 0;
    switch (location)
    {
    case 0:
        DU = 1;
        P0 = DUnumber[number / 10000000];
        DU = 0;
        break;
    case 1:
        DU = 1;
        P0 = DUnumber[number % 10000000 / 1000000];
        DU = 0;
        break;
    case 2:
        DU = 1;
        P0 = DUnumber[number % 1000000 / 100000];
        DU = 0;
        break;
    case 3:
        DU = 1;
        P0 = DUnumber[number % 100000 / 10000];
        DU = 0;
        break;
    case 4:
        DU = 1;
        P0 = DUnumber[number % 10000 / 1000];
        DU = 0;
        break;
    case 5:
        DU = 1;
        P0 = DUnumber[number % 1000 / 100];
        DU = 0;
        break;
    case 6:
        DU = 1;
        P0 = DUnumber[number % 100 / 10];
        DU = 0;
        break;
    case 7:
        DU = 1;
        P0 = DUnumber[number % 10];
        DU = 0;
        break;
    }
    location++;
    if (8 == location)
        location = 0;
}
/*=================================================
函数	：Initializer0()
参数	：无
返回值：无
描述	：定时器0初始化，用于控制数码管显示接收数据。
=================================================*/
void Initializer0()
{
    EA = 1;
    ET0 = 1;
    TR0 = 1;
		TMOD |= 0X01;
    // 一轮机器周期耗时1.085us,12轮时钟周期为一轮机器周期。
    TL0 = 0XFE;
    TH0 = 0XC9; // 定时15ms。
}
/*=================================================
函数	：Initializer1()
参数	：无
返回值：无
描述	：以中断方式进行串口通信的初始化。
=================================================*/
void Initializer1()
{
	EA = 1;
	ES = 1;
	TR1 = 1;
	TMOD |= 0X20;
	SM0 = 0;
	SM1 = 1;
	REN = 1;
	TL1 = 0XFD;
	TH1 = 0XFD;
}	

void main()
{
	Initializer0();
	Initializer1();
    while(1);
}

/*=========================================
函数	：timer0()
参数	：无
返回值：无
描述	：定时器0溢出引发中断，显示接收数据。
=========================================*/
void Timer0() interrupt 1
{
    TL0 = 0XFE;
    TH0 = 0XC9; 
    disply(number);
}
/*=========================================
函数	：UART()
参数	：无
返回值：无
描述	：串口通信中断函数
=========================================*/
//注意SNBF是8位寄存器，最大是0XFF,所以发送的数据不能超过这个数。
void UART() interrupt 4
{
	ulong i = 0;
	if(RI)//判断是否接收完成。
	 {
		 RI = 0;
		 number = SBUF;
		 i = number;
      SBUF = ++i;
	 }
	 if(TI)//判断是否发送完成。
	 TI = 0;
}
