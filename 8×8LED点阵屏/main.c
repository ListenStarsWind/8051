#include<reg52.h>
sbit DIO = P3^4;
sbit S_CLK = P3^5;
sbit O_CLK = P3^6;
void main()
{
    unsigned char i,dat,j;
    dat = 0xfe;
    for(i=0;i<8;i++)
    {
        S_CLK = 0;
        O_CLK = 0;
        if(dat & 0x01)
        {
            DIO = 1;
        }
        else
        {
            DIO = 0;
        }
        S_CLK = 1;
        dat >>= 1; 
    }
    dat = 0x80;
    for(j=8;j>0;j--)
    {
        S_CLK = 0;
        O_CLK = 0;
        if(dat & 0x01)
        {
            DIO = 1 ;
        }
        else
        {
            DIO = 0;
        }
        S_CLK = 1;
        dat >>= 1; 
    }
    O_CLK = 1;
    while(1);
}