#include "TOTAL.H"

void draw_home01()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	puthz(180,30,"��������������ֿ�",32,32,BLUE);
    mouseinit();
	quit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(3);
	}
	closegraph();
}

void draw_home00()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	puthz(120,30,"�ƺӡ������������ڲֿ�",32,32,BLUE);
	quit();
    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(4);
	}
	closegraph();
}