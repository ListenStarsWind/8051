#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long
sbit S2 = P3^0;
sbit S3 = P3^1;
sbit S4 = P3^2;
sbit S5 = P3^3;
uchar  code dula [10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,};

sbit we = P2^7;
sbit du = P2^6;
void delay(uint z)
{
	uint x,y;
	for(x = z; x > 0; x--)
		for(y = 114; y > 0 ; y--); 		
} 
ulong i;
void dispiay(ulong i)
{
uchar qianwan,baiwan,shiwan,wan,qian,bai,shi,ge;
qianwan = i/10000000;
baiwan  = i%10000000/1000000;
shiwan = i%1000000/100000;
wan = i%100000/10000;
qian = i%10000/1000;
bai = i%1000/100;
shi = i%100/10;
ge = i%10;
		du = 0;
		we = 0;
		delay(5);
		
		P0 = 0XFE;
		we = 1;
		we = 0;
		P0 = dula[qianwan];
		du = 1;
		du = 0;
		delay(5);
		
		P0  = 0xfd;
		we = 1;
		we = 0;
		P0 = dula[baiwan];
		du = 1;
		du = 0;
		delay(5);
		
		P0  = 0xfb;
		we = 1;
		we = 0;
		P0 = dula[shiwan];
		du = 1;
		du = 0;
		delay(5);
		
		P0  = 0xf7;
		we = 1;
		we = 0;
		P0 = dula[wan];
		du = 1;
		du = 0;
		delay(5);

		P0  = 0xef;
		we = 1;
		we = 0;
		P0 = dula[qian];
		du = 1;
		du = 0;
		delay(5);
		
		
		P0  = 0xdf;
		we = 1;
		we = 0;
		P0 = dula[bai];
		du = 1;
		du = 0;
		delay(5);
		
		
		P0  = 0xbf;
		we = 1;
		we = 0;
		P0 = dula[shi];
		du = 1;
		du = 0;
		delay(5);
		
		
		P0  = 0x7f;
		we = 1;
		we = 0;
		P0 = dula[ge];
		du = 1;
		du = 0;
		delay(5);
}




void main()
{
  i = 31415926;
	while(1)
	{		
	  	
			
			if(S2 == 0)//判断S2是否被按下
			{
				delay(20);//按键消抖
					if(S2 == 0)
					{
						if(i>0)//如果大于0则执行减一
						i--;
						while(!S2);//松手检测
					}
			}
		
			if(S3 == 0)//判断S3是否被按下
			{
				delay(20);
					if(S3 == 0)
					{
						if(i<99999999)//如果小于99999999则执行加一
						i++;
						while(!S3);
					}
			}
		dispiay(i);	
	}
}