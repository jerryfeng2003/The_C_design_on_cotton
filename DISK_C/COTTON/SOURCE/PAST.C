#include "TOTAL.H"

void draw_past01()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"¹ýÍù²ÎÊý",32,32,BLUE);
	quit();
    mouseinit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_past();
		delay(15);
	}
	//closegraph();
}

void press_past()
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