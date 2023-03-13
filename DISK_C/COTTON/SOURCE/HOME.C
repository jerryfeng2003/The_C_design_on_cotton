#include "TOTAL.H"

void draw_home01()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	if(location==1)
	{
		puthz(180,30,"西北地区：室外仓库",32,32,BLUE);
	}
	else
	{
		puthz(120,30,"黄河、长江流域：室内仓库",32,32,BLUE);
	}
	draw_warehouse();
	draw_trunk();
	in_warehouse(999);
    mouseinit();
	quit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_home();
		delay(15);
	}
}

void press_home()
{
	if(mouse_press(0,0,40,30)==0||mouse_press(53,90,280,190)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||mouse_press(53,90,280,190)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	if(mouse_press(53,90,280,190)==1)
	{
		detail_warehouse();
	}
}

/*void draw_home00()
{
    int i;
    //int num;
    cleardevice();
    setbkcolor(WHITE);

	quit();
    mouseinit();
	for(i=0;i<1000;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(4);
	}
}*/

void in_warehouse(int count)
{
	char str1[8];
	setfillstyle(1,LIGHTGRAY);
	bar(53,90,280,190);
	puthz(60,110,"库存量：",16,16,WHITE);
	puthz(60,145,"棉花种类：",16,16,WHITE);
	puthz(138,145,"长绒棉",16,16,RED);
	setcolor(RED);
	itoa(count,str1,10);
	settextstyle(1,0,2);
	outtextxy(130,105,str1);
}

void detail_warehouse()
{
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(1,LIGHTGRAY);
	bar(100,100,540,300);
	mouseinit();
	quit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_dewarehouse();
		delay(15);
	}
}

void press_dewarehouse()
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
		draw_home01();
	}
}

void draw_trunk()
{
	setfillstyle(1,RED);
	//setcolor(DARKGRAY);
	bar(50,210,160,260);
	setfillstyle(1,LIGHTGRAY);
	bar(160,225,190,260);
	setfillstyle(1,DARKGRAY);
	fillellipse(175,255,11,11);
	fillellipse(76,255,11,11);
	fillellipse(104,255,11,11);
	setfillstyle(1,LIGHTBLUE);
	bar(165,230,185,240);
}

void draw_warehouse()
{
	int i,j,y_d=160;
	setcolor(DARKGRAY);
	setlinestyle(0,0,3);
	line(0,230,640,230);
	for(i=0;i<4;i++)
	{
		int x_d=400;
		for(j=0;j<3;j++)
		{
			int m=rand()%10;
			cot_mount(x_d+m,y_d);
			x_d+=70;
		}
		y_d+=80;
	}
}

void cot_mount(int x,int y)
{
	int i,d_y=y;
	setcolor(DARKGRAY);
	//setlinestyle(0,0,3);
	setfillstyle(0,WHITE);
	for(i=0;i<4;i++)
	{
		rectangle(x,d_y,x+50,d_y+30);
		bar(x,d_y,x+50,d_y+30);
		d_y+=30;
	}
}

/*int main()
{
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
	draw_home01();
	closegraph();
	return 0;
}*/