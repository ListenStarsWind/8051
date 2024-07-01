#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
uint key = 20;	
sbit 	LED1 = P1^0;
sbit 	LED2 = P1^1;
sbit 	LED3 = P1^2;
sbit 	LED4 = P1^3;

	
void delay(uint z)
{
    uint x, y;
    for (x = z; x > 0; x--)
        for (y = 114; y > 0; y--)
            ;
}
void KeyValue()
{
			P3 = 0XF0;
			if(P3!= 0XF0)
			{
				delay(20);
				if(P3!= 0XF0)
				{
						switch(P3)
						{
							case 0XE0:key = 0;break;
							case 0XD0:key = 1;break;
							case 0XB0:key = 2;break;
							case 0X70:key = 3;break;
						}
						P3 = 0X0F;
						switch(P3)
						{
							case 0X0E:key = key;break;
							case 0X0D:key = key+4;break;
							case 0X0B:key = key+8;break;
							case 0X07:key = key+12;break;
						}
				
						while(P3!=0x0F);
				}
				
			}	
			P3=0xFF;
			if(P3!= 0XFF)
			{
				delay(20);
				if(P3!= 0XFF)
				{
						switch(P3)
						{
							case 0XFE:key = 16;break;
							case 0XFD:key = 17;break;
							case 0XFB:key = 18;break;
							case 0XF7:key = 19;break;
						}
				
						while(P3 != 0xFF);
				}
			}
				
}

void main()
{
	int a = 1;
		int b = 1;
		int c = 1;
		int d = 1;
	while(1)
	{
		
		KeyValue();
		switch(key)
		{
			        case 16:a = !a,LED1 = a;break;
							case 17:b = !b,LED2 = b;break;
							case 18:c = !c,LED3 = c;break;
							case 19:d = !d,LED4 = d;break;
		}
	}
}
