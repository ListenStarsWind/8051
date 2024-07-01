#ifndef __12864_H
#define __12864_H

//---包含头文件---//
#include "stc15f2k60s2.h"

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif


//---定义使用的IO口---//
#define LCD12864_DATAPORT P0	  //数据IO口

sbit RS  =  P2^0;      //（数据命令）寄存器选择输入    TFT_D10  A8 
sbit RW  =  P2^1;      //液晶读/写控制                 TFT_D8   A9
sbit E =  P2^2;      //液晶使能控制									 TFT_D9   A10



//---声明全局函数---//
void delayms(uint i);
void read_busy();
void write_cmd(uchar cmd);
void write_dat(uchar dat);
void initlcd();
void dis(uchar x,uchar y,uchar code *s);
void gun_xia();
void gun_shang();

#endif
