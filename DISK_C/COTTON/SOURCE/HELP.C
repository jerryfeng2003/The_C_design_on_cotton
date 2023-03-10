#include "TOTAL.H"

void draw_help01()
{
    int i;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"°ïÖú¼°ËµÃ÷",32,32,BLUE);
	quit();
    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_help();
		delay(5);
	}
	closegraph();
}

void press_help()
{
	if(mouse_press(0,0,40,30)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
}