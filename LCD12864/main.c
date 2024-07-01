#include "stc15f2k60s2.h"
#include "absacc.h"
#include <intrins.h>
#include "12864.c"

/***************
12864液晶实验
详见README文件
***************/


//针对STC15W4K56S4系列IO口初始化
//io口初始化 P0~7 为准双向IO口   
void IO_init(void)
{
  P0M0 = 0X00;	P0M1 = 0X00;
	P1M0 = 0X00;  P1M1 = 0X00;
	P2M0 = 0X00;	P2M1 = 0X00;
	P3M0 = 0X00;	P3M1 = 0X00;
	P4M0 = 0X00;	P4M1 = 0X00;  	
	P5M0 = 0X00;	P5M1 = 0X00;  	
	P6M0 = 0X00;	P6M1 = 0X00;  	
	P7M0 = 0X00;	P7M1 = 0X00;  
}

void main()
{	
	uchar i;	
	IO_init();	 //针对STC15W4K56S4 IO口初始化
	
  //设置STC单片机的P20 P21 22为推挽输出
	P2M1 &= ~(1<<2),P2M0 |=  (1<<2); 
	P2M1 &= ~(1<<1),P2M0 |=  (1<<1); 
	P2M1 &= ~(1<<0),P2M0 |=  (1<<0); 	
		
  initlcd();
	for(i=0;i<1;i++)//左移动
	{
 		dis(0,0,"                ");
		dis(1,0,"                ");
		delayms(800);
		dis(0,0,"智能家居模拟控制");
		dis(1,0,"AHZYJSXY1");
		delayms(8000);
		//write_cmd(0x0);
		dis(0,0,"能家居模拟控制智");
		dis(1,0,"ZYJSXY1       AH");
		delayms(8000);
		//write_cmd(0x01);
		dis(0,0,"家居模拟控制智能");
		dis(1,0,"JSXY1       AHZY");
		delayms(8000);
		//write_cmd(0x01);
		dis(0,0,"居模拟控制智能家");
		dis(1,0,"XY1       AHZYJS");
		delayms(8000);
		//write_cmd(0x01);
		dis(0,0,"模拟控制智能家居");
		dis(1,0,"1       AHZYJSXY");
		delayms(8000);
		//write_cmd(0x01);
		dis(0,0,"拟控制智能家居模");
		dis(1,0,"      AHZYJSXY1 ");
		delayms(8000);
		//write_cmd(0x01);
		dis(0,0,"控制智能家居模拟");
		dis(1,0,"    AHZYJSXY1   ");
		delayms(8000);
		//write_cmd(0x01);
		dis(0,0,"制智能家居模拟控");
		dis(1,0,"  AHZYJSXY1     ");
		delayms(8000);
		//write_cmd(0x01);
		dis(0,0,"智能家居模拟控制");
		dis(1,0,"AHZYJSXY1       ");
		delayms(8000);
	}
	for(i=0;i<1;i++)
	{
			dis(0,0,"                ");
			dis(1,0,"                ");
			dis(0,0,"水位：0.00");
			dis(1,0,"温湿度：0.00");		
			//dis(2,0,"13");		
			//dis(3,0,"14");		
				
			dis(6,0,"水位：0.00");	
			dis(7,0,"温湿度：0.00");		
			//dis(4,0,"13");	
			//dis(5,0,"14");
				
			write_cmd(0x34);		
			write_cmd(0x03);		
			gun_shang();		
			write_cmd(0x03);	
	}
	while(1)
	{
		
	}

			
	
}
