#include<reg52.h>
unsigned int i;
void main()
{
    P1 = 0;
    i = 65354;
    while(i--);
    P1 = 0xff;
    i = 65354;
    while(i--);
}