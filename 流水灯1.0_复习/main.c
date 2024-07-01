#include<reg52.h>
sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;
sbit LED5 = P1^4;
sbit LED6 = P1^5;
sbit LED7 = P1^6;
sbit LED8 = P1^7;
unsigned int i;
void main()
{
    while(1)
    {
    LED1 = 0;
    i = 65435;
    while(i--);

    LED2 = 0;
    i = 65435;
    while(i--);

    LED3 = 0;
    i = 65435;
    while(i--);

    LED4 = 0;
    i = 65435;
    while(i--);

    LED5 = 0;
    i = 65435;
    while(i--);

    LED6 = 0;
    i = 65435;
    while(i--);

    LED7 = 0;
    i = 65435;
    while(i--);

    LED8 = 0;
    i = 65435;
    while(i--);

    P1 = 0xff;
    }
}

