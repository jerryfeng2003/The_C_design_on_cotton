#include "TOTAL.H"

void draw_past01()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"¹ıÍù²ÎÊı",32,32,BLUE);
	quit();
    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(3);
	}
	closegraph();
}