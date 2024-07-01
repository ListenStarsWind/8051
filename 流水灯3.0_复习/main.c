#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int

uint temp;

void delay(uint z)
{
    uint x,y;
    for(x=z;x>0;x--)
    for(y=144;y>0;y--);
}

void main()
{
    temp = 0xfe;
    P1 = 0xfe;
    delay(20);
    while(1)
    {
        temp = _crol_(temp,1);
        P1 = temp;
        delay(20);
    }
}

