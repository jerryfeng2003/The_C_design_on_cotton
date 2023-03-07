#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include "TOTAL.H"

void draw_edit01()
{
    int i;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"ÇëÑ¡ÔñµØÇø",32,32,BLUE);

    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(5);
	}
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	closegraph();
}
