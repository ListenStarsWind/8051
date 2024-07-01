#include<reg52.h>

#define uint unsigned int
#define uchar unsigned char

sbit KeyS2 = P3^0;
sbit flag = P3^7;//使用该程序时务必将芯片的P3^3脚和P3^7脚相连。

void delay(uint z)
{
    uint x,y;
    for(x=z;x>0;x--)
    for(y=144;y>0;y--);
}

void InterruptInitialization()
{
    EA = 1;
    EX1 = 1;
    IT1 = 1;
}

void int1() interrupt 2
{
    P1 = ~P1;
}

void main()
{
    InterruptInitialization();
    P1 = 0x3c;//1100 0011
    if(KeyS2==0)
    {
        delay(15);
        if(KeyS2==0)
        {
            flag = 1;
            delay(2);
            flag = 0;
            while(!KeyS2);
        }
    }
}

