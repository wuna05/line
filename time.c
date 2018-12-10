/*********************
定时器
**********************/

#include <reg52.h>
#include <include.h>

typedef enum {tcon0,tcon1}tcon;
typedef enum {un,en = 0x1000}gate;
typedef enum {timer,counter = 0x100}ct;
typedef enum {mode1,mode2,mode3,mode4}mode;

void TMODINIT()
{
	TMOD = 0;
}
void SetTmod(tcon t,gate g,ct c,mode m)
{
	switch(t){
		case tcon1:
			TMOD = (TMOD & 0x1111) | ((g | c | m) << 4);
			break;
		case tcon0:
			TMOD = (TMOD & 0x11110000) | ((g | c | m) << 4);
			break;
		default:
			break;
	}
}
/*********************************
功能：设置定时器
参数：n：初值
*******************************/
void SetTimer(tcon t,mode m,uint16 n)
{
	setTmod(t,en,timer,m);
	TH0 = n / 256;
	TL0 = n % 256;
}
/******************
功能：定时器/计数器开始工作
**********************/
void StartTCON(tcon t)
{
	switch(t){
		case tcon0:{
			TR0 = 1;
			break;
		}
		case tcon1:{
			TR1 = 1;
			break;
		}
		default:
			break;
	}
}
void SetIE()
{
	IE = 0x10101010;//打开定时中断允许
}
/***********************************
定时器0中断函数
***********************************/
void timer0() interrupt 1 
{

}
/***********************************
定时器1中断函数
***********************************/
void timer1() interrupt 3
{

}