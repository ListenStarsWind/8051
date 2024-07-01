#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
uint teep;
void delay(unsigned int z)
{
			uint x,y;
			for(x = z; x > 0; x--)
			for(y = 114; y > 0 ; y--);
}
void main()
{
teep = 0xfe;
P1 = teep;
delay(100);
			while(1)
			{
			teep = _crol_(teep,1);
			P1 = teep;
			delay(100);
			}
}