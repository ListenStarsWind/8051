#include<reg52.h>
#define uchar unsigned char
#define uint  unsigned int
sbit du   = P2 ^ 6;
sbit we   = P2 ^ 7;
int i;
uchar code dula[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void delay(uint z)
{
    uint x, y;
    for (x = z; x > 0; x--)
        for (y = 144; y > 0; y--);
}
   

   void main()
   {
	for(i=0;i<10;i++)
    {
        du = 0;
		we = 0;
		delay(5);
		
		P0 = 0XFE;
		we = 1;
		we = 0;
		P0 = dula[i];
		du = 1;
		du = 0;
		delay(5);
		delay(200);
    }
   }