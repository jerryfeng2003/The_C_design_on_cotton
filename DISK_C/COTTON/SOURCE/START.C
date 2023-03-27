#include "TOTAL.H"

/*int main()
{
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
	draw_simu01();
	return 0;
}*/

//draw the process of harvest in animition
void draw_simu01(long int x,long int y,int num)
{
    long int time=25,temp=0,*tal=here[k].total;
	int c_t=here[k].cotton_type;
	char here[8];
	itoa(time,here,10);
	temp=x*y*0.01+rand()%100;
    cleardevice();
    setbkcolor(WHITE);
	puthz(150,30,"采摘完成还需",32,32,BLUE);
	settextstyle(3,0,4);
	setcolor(RED);
	outtextxy(350,26,here);
    puthz(400,30,"小时",32,32,BLUE);
	init_field(x,y);
    //outtextxy()
	quit();
    mouseinit();
	start_ainime(0,x,y,num);
	pick_finish(temp);
	tal[c_t]+=temp;
	if(tal[c_t]>ware_full||tal[c_t]<0)
	{
		tal[c_t]=ware_full;
	}
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_start();
		delay(20);
	}
	
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	//closegraph();
}


//start playing the picking video
void start_ainime(int t_trac,int x,int y,int num)
{
	int i,x_p=x_start,y_p=y_start+y-40,flag=0,out=0;
	x/=num;
	skip();
	if(t_trac==0)
	{
		earth_fill01(x_p,y_p);
		init_tracktor01_f(x_p,y_p);
		while(1)
		{
			if(x_p>=50+x)
			{
				break;
			}
			for(i=0;i<num;i++)
			{
				newmouse(&MouseX,&MouseY,&press);
				if(flag==0)
				{
					if(y_p==120+y-45)
					{
						earth_fill03(x_p+i*x,y_p-4);
					}
					if(y_p>=120+7)
					{
						earth_fill01(x_p+i*x,y_p);
						init_tracktor01_f(x_p+i*x,y_p);
					}
					if(y_p<=120+7)
					{
						earth_fill03(x_p+i*x,120);
					}
				}
				else
				{
					if(y_p==120+7)
					{
						earth_fill01(x_p+i*x,y_p-7);
					}
					if(y_p<=120+y-45)
					{
						earth_fill02(x_p+i*x,y_p);
						init_tracktor01_b(x_p+i*x,y_p);
					}
					if(y_p>=120+y-45)
					{
						earth_fill03(x_p+i*x,120+y-49);
					}
				}
				delay(20/num);
			}
			if(flag==0)
			{
				y_p--;
				if(y_p<=120+7)
				{
					for(i=0;i<num;i++)
						earth_fill03(x_p+i*x,120);
					flag=1;
					x_p+=25;
				}
			}
			else
			{
				y_p++;
				if(y_p>=120+y-45)
				{
					for(i=0;i<num;i++)
						earth_fill03(x_p+i*x,120+y-49);
					flag=0;
					x_p+=25;
				}
			}
			out=pressed_anime(x*num,y);
			if(out!=0)
			{
				for(i=1;i<=num;i++)
				{
					init_tracktor01_f(x_start+i*x-x%25,y_start+7);
				}
				return;
			}
			//delay(15*num);
		}
		for(i=1;i<=num;i++)
		{
			if(flag==1)
				init_tracktor01_f(x_start+i*x-x%25,y_start+7);
			else
				init_tracktor01_b(x_start+i*x-x%25,y_start+y-45);
		}
	}
	else
	{
		earth_fill01(x_p,y_p);
		init_tracktor02_f(x_p,y_p);
		while(1)
		{
			if(x_p>=50+x)
			{
				break;
			}
			for(i=0;i<num;i++)
			{
				newmouse(&MouseX,&MouseY,&press);
				if(flag==0)
				{
					if(y_p==120+y-45)
					{
						earth_fill03(x_p+i*x,y_p-4);
					}
					if(y_p>=120+7)
					{
						earth_fill01(x_p+i*x,y_p);
						init_tracktor02_f(x_p+i*x,y_p);
					}
					if(y_p<=120+7)
					{
						earth_fill03(x_p+i*x,120);
					}
				}
				else
				{
					if(y_p==120+7)
					{
						earth_fill01(x_p+i*x,y_p-7);
					}
					if(y_p<=120+y-45)
					{
						earth_fill02(x_p+i*x,y_p);
						init_tracktor02_b(x_p+i*x,y_p);
					}
					if(y_p>=120+y-45)
					{
						earth_fill03(x_p+i*x,120+y-49);
					}
				}
				delay(20/num);
			}
			if(flag==0)
			{
				y_p--;
				if(y_p<=120+7)
				{
					for(i=0;i<num;i++)
						earth_fill03(x_p+i*x,120);
					flag=1;
					x_p+=25;
				}
			}
			else
			{
				y_p++;
				if(y_p>=120+y-45)
				{
					for(i=0;i<num;i++)
						earth_fill03(x_p+i*x,120+y-49);
					flag=0;
					x_p+=25;
				}
			}
			out=pressed_anime(x*num,y);
			if(out!=0)
			{
				for(i=1;i<=num;i++)
				{
					init_tracktor02_f(x_start+i*x-x%25,y_start+7);
				}
				return;
			}
			//delay(15*num);
		}
		for(i=1;i<=num;i++)
		{
			if(flag==1)
				init_tracktor02_f(x_start+i*x-x%25,y_start+7);
			else
				init_tracktor02_b(x_start+i*x-x%25,y_start+y-45);
		}
	}
}

//add the press moudules in start page
void press_start()
{
	if(mouse_press(0,0,40,30)==0||mouse_press(265,350,365,410)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||mouse_press(265,350,365,410)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	else if(mouse_press(265,350,365,410)==1)
	{
		draw_home01();
	}
}

//add press moudules in video page
int pressed_anime(int x,int y)
{
	int re=0;
	if(MouseX>=x_start&&MouseY>=y_start&&MouseX<=x_start+x&&MouseY<=y_start+y)
	{
		clrmous(MouseX,MouseY);
	}
	if(mouse_press(0,0,40,30)==0||mouse_press(585,450,625,480)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||mouse_press(585,450,625,480)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	else if(mouse_press(585,450,625,480)==1)
	{
		anime_skip_result(x,y);
		re=1;
	}
    return re;
}

//show after picking 
void pick_finish(int count)
{
	char str[10];
	itoa(count,str,10);
	setfillstyle(1,WHITE);
	bar(160,170,470,340);
	setcolor(RED);
	setlinestyle(0,0,3);
	rectangle(165,175,465,335);

	puthz(210,190,"采摘完成",32,32,BLUE);
	puthz(210,230,"共计：",32,32,BLUE);
	settextstyle(3,0,4);
	puthz(380,230,"吨",32,32,BLUE);
	outtextxy(300,225,str);
	puthz(210,270,"种类：长绒棉",32,32,BLUE);

	setfillstyle(1,YELLOW);
	bar(265,350,365,410);
	puthz(278,360,"入库",32,32,RED);
}

//moudules which skip the video and show the result
void anime_skip_result(int x,int y)
{
	int i;
	setfillstyle(1,BROWN);
	setcolor(WHITE);
	bar(x_start,y_start,x_start+x,y_start+y);
	for(i=0;i<2000;i++)
	{
		int x_t=rand()%x,y_t=rand()%y;
		line(x_start+x_t,y_start+y_t,x_start+x_t,y_start+y_t);
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

//initialize the tracktor type 1
void init_tracktor01_b(int x,int y)
{
	int i,j;
	setlinestyle(0,0,1);
	setcolor(DARKGRAY);
	//The main rectangle
	setfillstyle(1,RED);
	bar(x+3,y,x+22,y+41);
	rectangle(x+3,y,x+22,y+41);
	setlinestyle(0,0,3);
	rectangle(x+6,y+3,x+19,y+38);

	//The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0,0,1);
	setfillstyle(1,YELLOW);
	bar(x,y+38,x+25,y+41);
	rectangle(x,y+38,x+25,y+41);
	for(i=x;i<=25+x;i+=2)
	{
		bar(i-1,y+41,i+1,y+37);
		rectangle(i-1,y+41,i+1,y+37);
	}

	//The driver site
	setfillstyle(1,RED);
	bar(x+7,y+43,x+18,y+32);
	rectangle(x+7,y+43,x+18,y+32);

	//The wheels
	setfillstyle(1,BLUE);
	bar(x+1,y+29,x+3,y+23);
	bar(x+22,y+29,x+24,y+23);
	bar(x+1,y+12,x+3,y+6);
	bar(x+22,y+12,x+24,y+6);
}

//initialize the tarcker 02 in front 
void init_tracktor02_f(int x,int y)
{
	int i,j;
	setlinestyle(0,0,1);
	setcolor(DARKGRAY);
	//The main rectangle
	setfillstyle(1,GREEN);
	bar(x+3,y-3,x+22,y+38);
	rectangle(x+3,y-3,x+22,y+38);
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
	setfillstyle(1,GREEN);
	bar(x+7,y-5,x+18,y+6);
	rectangle(x+7,y-5,x+18,y+6);

	//The wheels
	setfillstyle(1,BLUE);
	bar(x+1,y+9,x+3,y+15);
	bar(x+22,y+9,x+24,y+15);
	bar(x+1,y+26,x+3,y+32);
	bar(x+22,y+26,x+24,y+32);
}

//initialize the tracktor type 2 in backward
void init_tracktor02_b(int x,int y)
{
	int i,j;
	setlinestyle(0,0,1);
	setcolor(DARKGRAY);
	//The main rectangle
	setfillstyle(1,GREEN);
	bar(x+3,y,x+22,y+41);
	rectangle(x+3,y,x+22,y+41);
	setlinestyle(0,0,3);
	rectangle(x+6,y+3,x+19,y+38);

	//The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0,0,1);
	setfillstyle(1,YELLOW);
	bar(x,y+38,x+25,y+41);
	rectangle(x,y+38,x+25,y+41);
	for(i=x;i<=25+x;i+=2)
	{
		bar(i-1,y+41,i+1,y+37);
		rectangle(i-1,y+41,i+1,y+37);
	}

	//The driver site
	setfillstyle(1,GREEN);
	bar(x+7,y+43,x+18,y+32);
	rectangle(x+7,y+43,x+18,y+32);

	//The wheels
	setfillstyle(1,BLUE);
	bar(x+1,y+29,x+3,y+23);
	bar(x+22,y+29,x+24,y+23);
	bar(x+1,y+12,x+3,y+6);
	bar(x+22,y+12,x+24,y+6);
}

//earth filling after pick ,front
void earth_fill01(int x,int y)
{
	setfillstyle(1,BROWN);
	setcolor(WHITE);
	bar(x-1,y,x+25,y+41);
	if(y%4==0)
	{
		int x_temp=rand()%25;
		line(x+x_temp,y+41,x+x_temp,y+41);
	}
}

//earth filling after pick,back
void earth_fill02(int x,int y)
{
	setfillstyle(1,BROWN);
	setcolor(WHITE);
	bar(x-1,y-1,x+25,y+41);
	if(y%4==0)
	{
		int x_temp=rand()%25;
		line(x+x_temp,y-1,x+x_temp,y-1);
	}
}

//earth filling after pick, turn direction
void earth_fill03(int x,int y)
{
	int i;
	setfillstyle(1,BROWN);
	setcolor(WHITE);
	bar(x-1,y,x+25,y+50);
	for(i=0;i<10;i++)
	{
		int x_temp=rand()%25,y_temp=rand()%50;
		line(x_temp+x,y_temp+y,x_temp+x,y_temp+y);
	}
}
