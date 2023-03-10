#include "TOTAL.H"

void draw_simu01()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	puthz(150,30,"采摘完成还需",32,32,BLUE);
	settextstyle(3,0,4);
	setcolor(RED);
	outtextxy(350,26,"24");
    puthz(400,30,"小时",32,32,BLUE);
    //outtextxy()
	quit();
    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_start();
		delay(3);
	}
	
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	closegraph();
}

void press_start()
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