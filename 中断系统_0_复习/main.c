/*********************************************************************************
 * 【作    者】：	听风若依
 * 【版    本】：	V1.0
 * 【实验平台】：	清翔 QX-MCS51 单片机开发板
 * 【外部晶振】： 	11.0592mhz
 * 【主控芯片】： 	STC89C52
 * 【编译环境】： 	Keil μVisio5
 * 【编辑环境】： 	VS code
 * 【程序功能】： 	定时器0工作模式1，16位定时模式，由定时器0引发中断，执行中断程序。
**********************************************************************************/
 
#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

sbit DU = P2 ^ 6;
sbit WE = P2 ^ 7;
sbit serial_input = P3 ^ 4 ;    // 数据串行输入口
sbit SCLK = P3 ^ 5  ;           // 串行输入上升沿触发口
sbit PCLK = P3 ^ 6;             // 并行输出上升沿触发口

   int p =0;//LatticeScreen()

uchar code arr[][8] =   {   0xE0,0xEF,0x01,0x6D,0x01,0x6D,0x01,0xEF,
                            0xE7,0xF7,0xF7,0xF7,0x80,0xF7,0xFB,0xC3,
                            0xFF,0x83,0xBF,0xBF,0x83,0xFB,0xFB,0x83,
                            0x83,0xFB,0xFB,0x83,0xFB,0xFB,0x83,0xFF,
                        };


ulong code dula[10] = {
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07,
	0x7F,
	0x6F,
};

void delay(uint i)
{
	int x, y;
	for (x = i; x > 0; x--)
		for (y = 144; y > 0; y--)
			;
}

void displayer(ulong z)
{
	int qianwan = z / 10000000;
	int baiwan = z % 10000000 / 1000000;
	int shiwan = z % 1000000 / 100000;
	int wan = z % 100000 / 10000;
	int qian = z % 10000 / 1000;
	int bai = z % 1000 / 100;
	int shi = z % 100 / 10;
	int ge = z % 10;

	
	
		uint nu;

		uint k;

		uint j = 0xfe;

		for (k = 0; k < 8; k++)
		{
			switch (k)
			{
			case 0:
				nu = qianwan;
				break;
			case 1:
				nu = baiwan;
				break;
			case 2:
				nu = shiwan;
				break;
			case 3:
				nu = wan;
				break;
			case 4:
				nu = qian;
				break;
			case 5:
				nu = bai;
				break;
			case 6:
				nu = shi;
				break;
			case 7:
				nu = ge;
				break;
			}

			P0 = 0xff;
			WE = 1;
			WE = 0;

			P0 = dula[nu];
			DU = 1;
			DU = 0;

			P0 = j;
			WE = 1;
			WE = 0;

			delay(1);

			j = _crol_(j, 1);
		}
	
}

void restoration()//50ms复位函数
{
    TH0 = 0X48;
    TL0 = 0XFD;
}

void InterruptInitialization()//中断初始函数
{
    EA = 1;
    ET0 = 1; 
    TR0 = 1;
    TMOD = 0X01;//16位定时计数模式
    restoration();
}



void import(uchar x)
{
    uint a;
    SCLK = 0;
    for (a = 0; a < 8; a++)
    {
        if (x & 0x01)
            serial_input = 1;
        else
            serial_input = 0;
        SCLK = 1;
        SCLK = 0;
        x >>= 1;
    }
}
// 数据写入函数
void output()
{
    PCLK = 0;
    PCLK = 1;
}

void LatticeScreen()//点阵屏显示函数。
{
    uint k;
    
    uchar j ; // 行选初始数据
    j = 0x80;
    for (k = 0; k < 8; k++)
    {
        import(arr[p][k]);
        import(j);
        output();
        j = _cror_(j, 1);
    }
    if(p==3)
    p=0;
}

void main()
{
    InterruptInitialization();
    while(1)
    {
        LatticeScreen();
    }
}

void timer0() interrupt 1
{
    static uint m = 0;
    static ulong n = 0;
    restoration();
    m++;
    if (m == 20)
    {
        n++;
        displayer(n);
        m = 0;
        p++;
    }
    
}
	