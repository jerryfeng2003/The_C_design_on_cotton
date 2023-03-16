#include "TOTAL.H"

int main()
{
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
	draw_simu01();
	return 0;
}

//draw the process of harvest in animition
void draw_simu01()
{
    int x=50,y=400,time=25;
	char here[8];
	itoa(time,here,10);
    cleardevice();
    setbkcolor(WHITE);
	puthz(150,30,"采摘完成还需",32,32,BLUE);
	settextstyle(3,0,4);
	setcolor(RED);
	outtextxy(350,26,here);
    puthz(400,30,"小时",32,32,BLUE);
	init_field(x_max,y_max);
	earth_fill01(50,400);
	init_tracktor01_f(50,400);
    //outtextxy()
	quit();
    mouseinit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		y-=1;
		if(y>=120)
		{
			earth_fill01(x,y);
			init_tracktor01_f(x,y);
		}
		press_start();
		delay(15);
	}
	
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	//closegraph();
}

//add the press moudules
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

//initialize the cotton field
void init_field(int x,int y)
{
	int i,j;
	setcolor(BROWN);
	setlinestyle(0,0,1);
	line(50,120,50+x,120);
	line(50,120+y,50+x,120+y);
	for(i=50;i<=50+x;i+=25)
	{
		int temp=0;
		for(j=120;j<=120+y;j+=1)
		{
			temp=rand()%2;
			line(i+temp,j,i+temp,j);
		}
	}
	for(i=0;i<5000;i++)
	{
		int x_temp=0,y_temp=0;
		x_temp=rand()%x;
		y_temp=rand()%y;
		line(50+x_temp,120+y_temp,50+x_temp,120+y_temp);
	}
}

//initialize the tarcker 01
void init_tracktor01_f(int x,int y)
{
	int i,j;
	setlinestyle(0,0,1);
	setcolor(DARKGRAY);
	//The main rectangle
	setfillstyle(1,RED);
	bar(x+3,y-3,x+22,y+38);
	rectangle(x+3,y-3,x+22,y+38);
	setcolor(BROWN);
	setlinestyle(0,0,3);
	rectangle(x+6,y-6,x+19,y+35);

	//The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0,0,1);
	setfillstyle(1,YELLOW);
	bar(x,y,x+25,y-3);
	rectangle(x,y,x+25,y+3);
	for(i=x;i<=25+x;i+=2)
	{
		bar(i-1,y+1,i+1,y-4);
		rectangle(i-1,y+1,i+1,y-4);
	}

	//The driver site
	setfillstyle(1,RED);
	bar(x+7,y-5,x+18,y+6);
	rectangle(x+7,y-5,x+18,y+6);

	//The wheels
	setfillstyle(1,BLUE);
	bar(x+1,y+9,x+3,y+15);
	bar(x+22,y+9,x+24,y+15);
	bar(x+1,y+26,x+3,y+32);
	bar(x+22,y+26,x+24,y+32);
}

void earth_fill01(int x,int y)
{
	int i;
	setfillstyle(1,BROWN);
	setcolor(WHITE);
	bar(x,y,x+25,y+40);
	if(y%3==0)
	{
		for(i=0;i<1;i++)
		{
			int x_temp=rand()%25;
			line(x+x_temp,y+40,x+x_temp,y+40);
		}
	}

}

