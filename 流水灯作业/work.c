#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
uchar temp;

void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--);
}

void main()
{
	
	
	
	
	{
				temp = 0xf0;
		    P1 = temp;
				delay(100);
				while(1)
			{
				temp = _crol_(temp,1);
				P1 = temp;
				delay(1000);
			}
	}
}