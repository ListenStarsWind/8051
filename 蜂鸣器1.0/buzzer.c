#include<reg52.h>
#include <intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit buzzer = P2^3;
uint temp;

void delay(uint z)
{
		uint x, y;
		for(x = z; x>0;x--)
		for(y = 114;y>0;y--);
}



void main()
{
		temp = 0xfe;
		P1 = temp;
		delay(100);
		while(1)
		{
			temp = _crol_(temp,1);
			P1 = temp;
		buzzer = 0;
		delay(100);
		}
}