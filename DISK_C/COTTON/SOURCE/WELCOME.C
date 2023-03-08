#include "TOTAL.H"
int location=0;
/*void main()
{
	int gdriver,gmode;
	gdriver=DETECT;
	initgraph(&gdriver,&gmode,"..\\BORLANDC\\BGI");
	draw_wel();
	closegraph();
}*/

void draw_wel_buttons(void)
{
	int i,d;
	cleardevice();
	setbkcolor(WHITE);
	puthz(180,30,"棉花采摘模拟系统",32,32,BLUE);
	setlinestyle(0,0,1);
	setcolor(DARKGRAY);

	setfillstyle(1,13);
	rectangle(450,110,550,170);
	puthz(470,130,"编辑参数",16,16,BLUE);
	rectangle(450,210,550,270);
	puthz(470,230,"开始模拟",16,16,BLUE);
	rectangle(450,310,550,370);
	puthz(470,330,"过往参数",16,16,BLUE);
	rectangle(450,410,550,470);
	puthz(460,430,"帮助及说明",16,16,BLUE);

	line(300,130,360,100);
	line(360,100,420,130);
	line(300,130,420,130);
	rectangle(310,130,410,200);
	puthz(330,150,"仓库管理",16,16,BLUE);
}

void draw_wel_tractors()
{
	//The wheels
	int i,d;
	setcolor(BROWN);
	setfillstyle(1,BLUE);
	bar(94,185,100,215);
	bar(200,185,206,215);
	bar(94,265,100,295);
	bar(200,265,206,295);
	setfillstyle(1,RED);
   
	//The rectangle of the machine
	bar(100,150,200,310);
	rectangle(105,155,195,305);
	setfillstyle(1,YELLOW);
	setlinestyle(0,0,1);

	//The small bar 
	for(i=0,d=80;i<8;i++)
	{
		bar(d-2,125,d+2,155);
		rectangle(d-3,125,d+3,155);
		d+=20;
	}
	setlinestyle(0,0,3);
	bar(80,130,220,150);
	rectangle(80,130,220,150);
	for(i=0,d=100;i<6;i++)
	{
		line(d,130,d,150);
		d+=20;
	}
	setfillstyle(1,RED);
	bar(130,120,170,160);
	rectangle(130,120,170,160);
}

void draw_wel_cofield()
{
	//The cotton field
	int i,d;
	setcolor(BROWN);
	rectangle(50,100,300,400);
	setlinestyle(0,0,3);
	for(d=58;d<=300;d+=20)
	{
		for(i=100;i<=400;i+=2)
		{
			int temp=rand()%2;
			line(d+temp,i,d+temp,i);
		}
	}
	for(i=0;i<1000;i++)
	{
		int t1=rand()%250,t2=rand()%300;
		line(t1+50,t2+100,t1+50,t2+100);
	}
	setfillstyle(1,BROWN);
	bar(100,310,200,400);
	setcolor(WHITE);
	for(i=0;i<100;i++)
	{
		int t1=rand()%100,t2=rand()%90;
		line(t1+100,t2+310,t1+100,t2+310);
	}
	/*setfillstyle(1,BROWN);
	bar(50,100,300,400);
	setlinestyle(0,0,3);
	setcolor(WHITE);
	for(i=50;i<=300;i+=6)
	{
		for(d=100;d<=400;d+=2)
		{
			int temp=rand()%2;
			line(i+temp,d,i+temp,d);
			//temp=rand()%2;
			//line(i+temp,d,i+temp,d);
		}
	}*/
}

//enter the edit page
void enter_next()
{
	if(mouse_press(450,110,550,170)==0||mouse_press(450,210,550,270)==0\
	||mouse_press(450,310,550,370)==0||mouse_press(450,410,550,470)==0||mouse_press(310,130,410,200)==0)
	{
		MouseS=0;
	}
	if(mouse_press(450,110,550,170)==2||mouse_press(450,210,550,270)==2\
	||mouse_press(450,310,550,370)==2||mouse_press(450,410,550,470)==2||mouse_press(310,130,410,200)==2)
	{
		MouseS=1;
	}

	//Enter the edit page
	if(mouse_press(450,110,550,170)==1)
	{
		draw_edit01();
	}

	//Enter the simulation page
	if(mouse_press(450,210,550,270)==1)
	{
		draw_simu01();
	}

	//Enter the past arguments
	if(mouse_press(450,310,550,370)==1)
	{
		draw_past01();
	}

	//Enter the past arguments
	if(mouse_press(450,410,550,470)==1)
	{
		draw_help01();
	}

	//Enter the home page
	if(mouse_press(310,130,410,200)==1)
	{
		if(location==1)
		{
			draw_home01();
		}
		else
		{
			draw_home00();
		}
	}
	
}

/*Draw the whole welcome page*/
void draw_wel()
{
	int i,d;
	draw_wel_buttons();
	draw_wel_cofield();
	draw_wel_tractors();
	quit();
	mouseinit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		enter_next();
		delay(15);
	}
}
//"C:\\BORLANDC\\BGI"