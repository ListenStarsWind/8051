#include<reg52.h>
#include<intrins.h>

#define uchar unsigned char
#define uint unsigned int


//延迟函数
void delay(unsigned char z)
{
    uchar x,y;
    for(x = 0; x < z; x++)
    {
        for(y = 0; y < 144; y++);
    }
}

void main()
{
   uint push;
    push = 0xfe;
    while(1)
    {
        P1 = push;
        push = _crol_(push,1);
        delay(200);
    }
}