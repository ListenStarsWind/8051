#ifndef __12864_H
#define __12864_H

//---����ͷ�ļ�---//
#include "stc15f2k60s2.h"

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif


//---����ʹ�õ�IO��---//
#define LCD12864_DATAPORT P0	  //����IO��

sbit RS  =  P2^0;      //����������Ĵ���ѡ������    TFT_D10  A8 
sbit RW  =  P2^1;      //Һ����/д����                 TFT_D8   A9
sbit E =  P2^2;      //Һ��ʹ�ܿ���									 TFT_D9   A10



//---����ȫ�ֺ���---//
void delayms(uint i);
void read_busy();
void write_cmd(uchar cmd);
void write_dat(uchar dat);
void initlcd();
void dis(uchar x,uchar y,uchar code *s);
void gun_xia();
void gun_shang();

#endif
