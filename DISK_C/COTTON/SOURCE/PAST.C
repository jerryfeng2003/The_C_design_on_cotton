#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include "TOTAL.H"

void draw_past01()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"¹ýÍù²ÎÊý",32,32,BLUE);
    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(3);
	}
	closegraph();
}