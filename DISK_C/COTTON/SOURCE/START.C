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
		delay(3);
	}
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	closegraph();
}

void quit(void)
{
    setfillstyle(1,LIGHTBLUE);
    bar(0,0,40,30);
	puthz(3,10,"退出",16,16,WHITE);
}