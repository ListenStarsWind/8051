#include <reg52.h>
#include <intrins.h>

#define uint unsigned int

uint wenumber;
uint flag;
uint arr[7] = {0x6d, 0x5b, 0x3f, 0x06, 0x4f, 0x06, 0x66};

sbit DU = P2 ^ 6;
sbit WE = P2 ^ 7;

void main()
{
    while (1)
    {
        wenumber = 0xfe;
        for (flag = 0; flag < 7; flag++)
        {
            P0 = 0;
            DU = 1;
            DU = 0;

            P0 = wenumber;
            WE = 1;
            WE = 0;

            P0 = arr[flag];
            DU = 1;
            DU = 0;

            if (6 == flag)
                break;

            wenumber = _crol_(wenumber, 1);
        }
    }
}