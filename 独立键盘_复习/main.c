#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

sbit DU = P2 ^ 6;
sbit WE = P2 ^ 7;

sbit S2 = P3 ^ 0;
sbit S3 = P3 ^ 1;
sbit S4 = P3 ^ 2;
sbit S5 = P3 ^ 3;

ulong code dula[10] = {
    0x3F,
    0x06,
    0x5B,
    0x4F,
    0x66,
    0x6D,
    0x7D,
    0x07,
    0x7F,
    0x6F,
};

void delay(uint i)
{
    int x, y;
    for (x = i; x > 0; x--)
        for (y = 144; y > 0; y--)
            ;
}

void displayer(ulong z)
{
    int qianwan = z / 10000000;
    int baiwan = z % 10000000 / 1000000;
    int shiwan = z % 1000000 / 100000;
    int wan = z % 100000 / 10000;
    int qian = z % 10000 / 1000;
    int bai = z % 1000 / 100;
    int shi = z % 100 / 10;
    int ge = z % 10;

    uint nu;

    uint k;

    uint j = 0xfe;

    for (k = 0; k < 8; k++)
    {
        switch (k)
        {
        case 0:
            nu = qianwan;
            break;
        case 1:
            nu = baiwan;
            break;
        case 2:
            nu = shiwan;
            break;
        case 3:
            nu = wan;
            break;
        case 4:
            nu = qian;
            break;
        case 5:
            nu = bai;
            break;
        case 6:
            nu = shi;
            break;
        case 7:
            nu = ge;
            break;
        }

        P0 = 0xff;
        WE = 1;
        WE = 0;

        P0 = dula[nu];
        DU = 1;
        DU = 0;

        P0 = j;
        WE = 1;
        WE = 0;

        delay(1);

        j = _crol_(j, 1);
    }
}

void main()
{
    ulong number = 12345678;
    while (1)
    {
        if (0 == S2)
        {
            delay(5);
            if (0 == S2 && number >= 0)
            {
                number--;
                while (!S2)
                    ;
            }
        }
        if (0 == S3)
        {
            delay(5);
            if (0 == S3 && number <= 99999999)
            {
                number++;
                while (!S3)
                    ;
            }
        }
        if (0 == S4)
        {
            delay(5);
            if (0 == S4)
            {
                number = 0;
                while (!S4)
                    ;
            }
        }
        if (0 == S5)
        {
            delay(5);
            if (0 == S5 && number >= 0)
            {
                number = 99999999;
                while (!S5)
                    ;
            }
        }
        displayer(number);
    }
}