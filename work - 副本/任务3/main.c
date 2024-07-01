#include <reg52.h>
#define uchar unsigned char
#define uint  unsigned int
sbit du   = P2 ^ 6;
sbit we   = P2 ^ 7;
uchar Key = 19;

uchar code dula[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x76, 0x38, 0x40, 0x00};

void delay(uint z)
{
    uint x, y;
    for (x = z; x > 0; x--)
        for (y = 144; y > 0; y--);
}
   

void KeyValue()
{
    P3 = 0xf0;
    if (P3 != 0xf0) {
        delay(10);
        if (P3 != 0xf0) {
            switch (P3) {
                case 0xe0:Key = 0;break;
                case 0xd0:Key = 1;break;
                case 0xb0:Key = 2;break;
                case 0x70:Key = 3;break;
            }    
                
                P3 = 0x0f;
                switch(P3)
                {
                    case 0x0e:Key =Key;break;
                    case 0x0d:Key = Key+4;break;
                    case 0x0b:Key = Key+8;break;
                    case 0x07:Key = Key+12;break;
                }
                while(P3!=0x0f);
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
                    case 0xfe:Key = 16;break;
                    case 0xfd:Key = 17;break;
                    case 0xfb:Key = 18;break;
                    case 0xf7:Key = 19;break;
                }
                while(P3!=0xff);
            }
        }

}

     

void main()
{    
    P0 = 0xfe;
    we = 1;
    we = 0;

    du = 1;
    while(1)
    {
        KeyValue();
        P0 = dula[Key];

    }
    
		
}
