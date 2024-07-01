#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit du = P2^6;
sbit we = P2^7;
uchar key = 20;
uchar code dula[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x76,0x38,0x40,0x00};
void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--); 		
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
						case 0Xd0:key = 1;break;
						case 0Xb0:key = 2;break;
						case 0X70:key = 3;break;
						}
				
				while = (P3 != 0xF0);
				}
				
			}	
			P3 = 0X0F;
			if(P3!= 0X0F)
			{
				delay(20);
				if(P3!= 0X0F)
				{
						switch(P3)
						{
						case 0X0e:key = key;break;
						case 0X0d:key = key+4;break;
						case 0X0b:key = key+8;break;
						case 0X07:key = key+12;break;
						}
				
				while = (P3 != 0x0f);
				}
				
				P3 = 0XfF;
			if(P3!= 0XfF)
			{
				delay(20);
				if(P3!= 0XfF)
				{
						switch(P3)
						{
						case 0Xfe:key = 16;break;
						case 0Xfd:key = 17;break;
						case 0Xfb:key = 18;break;
						case 0Xf7:key = 19;break;
						}
				
				while = (P3 != 0xfe);
				}
				
}



void main()
{
			while(1)
	{
			du = 0;
			we = 0;
			delay(5);
			
			
			P0 = 0Xfe;
			we = 1;
			we = 0;
			
			KeyValue();
			P0 = dula[key];
			du = 1;
			du = 0;
			
	}		
}