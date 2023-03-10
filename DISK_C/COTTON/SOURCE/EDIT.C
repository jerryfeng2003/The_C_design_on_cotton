#include "TOTAL.H"

void draw_edit01()
{
    int i;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"ÇëÑ¡ÔñµØÇø",32,32,BLUE);
	quit();
    mouseinit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_edit();
		delay(15);
	}
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	//closegraph();
}

void press_edit()
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
