#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include "TOTAL.H"

void draw_help01()
{
    int i;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"������˵��",32,32,BLUE);

    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(5);
	}
	closegraph();
}