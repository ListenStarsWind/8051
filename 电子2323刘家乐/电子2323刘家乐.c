#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;
sbit LED5 = P1^4;
sbit LED6 = P1^5;
sbit LED7 = P1^6;
sbit LED8 = P1^7;
sbit buzzer = P2^3;
sbit S1 = P3^0;
sbit S2 = P3^1;
sbit S3 = P3^2;
sbit S4 = P3^3;
void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--);
}

void main()
{
		
		 P1 = 0xff;
		 buzzer = 0;
		 delay(100);
		 buzzer = 1;
		

		if(S1 == 0)
		{
		LED1 = 0;
		LED3 = 0;
		LED5 = 0;
		LED7 = 0;
		}
		if(S2 == 0)
		{
		uint a;
		uint b;
		
		a = 0xfe;
		b = 8; 
		delay(100);
			while(b)
			{
			a = _crol_(a,1);
			P1 = a;
			delay(100);
			b = b--;
			}		
		}


		P1 = 0;
		if(S3 == 0)
		{
		P1 = 0X80;
		delay(2000);
		P1 = 0Xc0;
		delay(2000);
		P1 = 0Xe0;
		delay(2000);
		P1 = 0Xf0;
		delay(2000);
		P1 = 0Xf8;
		delay(2000);
		P1 = 0Xfc;
		delay(2000);
		P1 = 0Xfe;
		delay(2000);
		P1 = 0Xff;
		delay(2000);
		
		}

		
		
		/*uint n;
		uint d;
		d = 0X80;
		n = 1;
		P1 = d;
		if(s4 == 0)
			
		{
		d = _cror_(d,n+2);
		P1 = d;
		buzzer = 0;
		delay(50)
		n = n++;
		}*/
		

}