#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint  unsigned int
#define ulong unsigned long
sbit DIO = P3^4;
sbit S_CLK = P3^5;
sbit O_CLK = P3^6;
sbit du   = P2 ^ 6;
sbit we   = P2 ^ 7;
int i,j,n;
int q = 18;
int Key = 19;
uchar k;
uchar code dula[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x40, 0x00};
uchar code tabel[19][8]={
0xFF,0xDD,0xDD,0xDD,0xC1,0xDD,0xDD,0xE3,//A
0x87,0xBB,0xBB,0x87,0xBB,0xBB,0x87,0xFF,//B
0xC7,0xBF,0xBF,0xBF,0xBF,0xBF,0xBF,0xC7,//C
0x87,0xBB,0xBB,0xBB,0xBB,0xBB,0xBB,0x87,//D
0xFF,0x87,0xBF,0xBF,0x87,0xBF,0xBF,0x87,//E
0xFF,0xBF,0xBF,0xBF,0x87,0xBF,0xBF,0x87,//F
0xFF,0xC7,0xBB,0xBB,0xA3,0xBF,0xBF,0xC3,//G
0xFF,0xBB,0xBB,0xBB,0x83,0xBB,0xBB,0xBB,//H
0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,//I
0xFF,0xCF,0xF7,0xF7,0xF7,0xF7,0xF7,0xFF,//J
0xFF,0xDB,0xD7,0xD7,0xCF,0xD7,0xD7,0xDB,//K
0xFF,0xE3,0xEF,0xEF,0xEF,0xEF,0xEF,0xEF,//L
0xBB,0xBB,0xBB,0xAB,0xAB,0x93,0x93,0xBB,//M
0xFF,0xB7,0xB7,0xA7,0xA7,0x97,0x97,0xB7,//N
0xC7,0xBB,0xBB,0xBB,0xBB,0xBB,0xBB,0xC7,//O
0xDF,0xDF,0xDF,0xDF,0xC3,0xDD,0xDD,0xC3,//P
0xFF,0xFF,0xE0,0xDD,0xDD,0xDD,0xE3,0xFF,//Q
0x7F,0x7D,0x7B,0x77,0x0F,0x77,0x77,0x0F,//R
0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF //清屏
};

void delay(uint z)
{
    uint x, y;
    for (x = z; x > 0; x--)
        for (y = 144; y > 0; y--);
}
   

void Send_Byte(uchar dat)//8位串行输入函数
{
    for(i=0;i<8;i++)
    {
        S_CLK = 0;
        if(dat & 0x01)
        {
            DIO = 1;
        }
        else
        {
            DIO = 0;
        }
         S_CLK = 1;
          dat>>=1;
    }
}


void KeyDetection()
{
    P3 = 0xf0;
    if(P3!=0xf0)
    {
        delay(10);
        if(P3!=0xf0)
        {
            switch(P3)
            {
                case 0xe0:Key = 0;q = 0;break;
                case 0xd0:Key = 1;q = 1;break;
                case 0xb0:Key = 2;q = 2;break;
                case 0x70:Key = 3;q = 3;break;
            }
            P3 = 0x0f;
            switch(P3)
            {
                case 0x0e:Key =Key;q = q;break;
                case 0x0d:Key = Key+4;q = q+4;break;
                case 0x0b:Key = Key+8;q = q+8;break;
                case 0x07:Key = Key+12;q = q+12;break;
            }
            while(P3!=0X0f);
        }
    }
    P3 = 0xff;
    if(P3!=0xff)
    {
            delay(10);
            if(P3!=0xff)
            {
                switch(P3)
                {
                    case 0xfe:Key = 16;q = 16;break;
                    case 0xfd:Key = 17;q = 17;break;
                    case 0xfb:Key = 18;q = 18;break;
                    case 0xf7:Key = 19;q = 19;break;
                }
                while(P3!=0xff);
            }
    }
}


void dispiay(ulong m)
{
uchar qianwan,baiwan,shiwan,wan,qian,bai,shi,ge;
qianwan = m/10000000;
baiwan  = m%10000000/1000000;
shiwan = m%1000000/100000;
wan = m%100000/10000;
qian = m%10000/1000;
bai = m%1000/100;
shi = m%100/10;
ge = m%10;
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

void LatticeScreen()
{
     k = 0x80;
  for(j=0;j<8;j++)
    {
        O_CLK = 0;
        KeyDetection();
        Send_Byte(tabel[q][j]);//一定要记住q是依据按键变化的，这部分我还没写
        Send_Byte(k);
        O_CLK = 1;
        k = _cror_(k,1);
    }
}


//void NixieTube()
//{
//     P0 = 0xfe;
//    we = 1;
//    we = 0;
//    du = 1;
//    while(1)
//   {
//        KeyDetection();
//        P0 = dula[Key];
//    }
//}


void main()
{
    dispiay(31415926);
}