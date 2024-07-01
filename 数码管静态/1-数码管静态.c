	#include<reg52.h>
	#define uint unsigned int
	#define uchar unsigned char
sbit we = P2^7;
sbit du = P2^6;
void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--); 		
} 
void main()
{
		
		
		P0 = 0XFF;
		we = 1;
		P0 = 0xfe;
		we = 0;
		delay(5);
		P0 = 0;
		du = 1;
		P0 = 0x6d;
		du = 0;
		
	  P0 = 0XFF;
		we = 1;
		P0 = 0xfd;
		we = 0;
		delay(5);
		P0 = 0;
		du = 1;
		P0 = 0x5B;
		du = 0;
		
		P0 = 0XFF;
		we = 1;
		P0 = 0xfb;
		we = 0;
		delay(5);
		P0 = 0;
		du = 1;
		P0 = 0x4F;
		du = 0;
		
}
		