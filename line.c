#include<reg52.h>
#include<intrins.h>

sbit xin1 = P2^0;
sbit xin2 = P2^1;
sbit xin3 = P2^2;
sbit xin4 = P2^3;

void delay(unsigned char i)
{
    unsigned char m, n;
    for(m = i; m > 0; m--)
    for (n = 125; n > 0; n--);
}

void YanzShuchu( )
{
	unsigned char i;
    P1 = 0x01;
    for(i=0;i<=8;i++)
    {
        delay(2000);
        P1 = _crol_(P1,1);
        
    }
}

/**************************************************************
????:????????,P1????????,???????????
**************************************************************/

void YanZheng()
{
    xin1 = 1;
    YanzShuchu();
    xin1 = 0,xin2 = 1;
    YanzShuchu();
    xin2 = 0,xin3 = 1;
    YanzShuchu();
    xin3 = 0,xin4 = 1;
    YanzShuchu();
    xin4 = 0;
}

void JiexianCeshi()
{
	unsigned char i;
    P1 = 0x01;
    for(i=0;i<=8;i++)
    {
        int flag = 1;
        unsigned char tem = P1;
        while(flag)
        {
            if(P1==tem) delay(3000);
            if(P1==0) 
            {
                P1 = _crol_(tem,1);
                flag = 0;
            }
            if (P1>tem)
            {
                YanZheng();
                flag = 0;
                
            }
        }

    }
}

void main()
{
    xin1 = 1, P1 = 0, xin1 = 0;
    xin2 = 1, P1 = 0, xin2 = 0;
    xin3 = 1, P1 = 0, xin3 = 0;
    xin4 = 1, P1 = 0, xin4 = 0;
    xin1 = 1,JiexianCeshi(),xin1 = 0;
    xin2 = 1,JiexianCeshi(),xin2 = 0;
    xin3 = 1,JiexianCeshi(),xin3 = 0;
    xin4 = 1,JiexianCeshi(),xin4 = 0;
    
}