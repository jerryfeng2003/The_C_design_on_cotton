#include "TOTAL.H"

void draw_edit01()
{
    int i;
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"ÇëÑ¡ÔñµØÇø",32,32,BLUE);
	quit();
	setfillstyle(1,LIGHTBLUE);
	bar(600,600,700,700);
    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,40,30)==1)
        {
            return;
        }
		delay(5);
	}
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	closegraph();
}
