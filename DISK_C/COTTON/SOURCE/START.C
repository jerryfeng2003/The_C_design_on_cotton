#include "TOTAL.H"

int main()
{
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
	//draw_simu01(x_max,y_max,2);
	select02();
	return 0;
}
// int main()
// {
// 	int gd=VGA,gm=VGAHI; 
// 	initgraph(&gd,&gm,"..\\borlandc\\bgi");
// 	select03();
// 	return 0;
// }

//draw the process of harvest in animition
void draw_simu01(long int x,long int y,int num)
{
    static long int time,temp,*tal;
	static int c_t;
	static char str[8];
	time=25,temp=0,tal=here[k].total,c_t=here[k].cotton_type;
	itoa(time,str,10);
	temp=x*y*0.01+rand()%100;
    cleardevice();
    setbkcolor(WHITE);
	puthz(150,30,"采摘完成还需",32,32,BLUE);
	settextstyle(3,0,4);
	setcolor(RED);
	outtextxy(350,26,str);
    puthz(400,30,"小时",32,32,BLUE);
	init_field(x,y);
    //outtextxy()
	quit();
    mouseinit();
	start_ainime01(0,x,y,num);
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
void start_ainime01(int t_trac,int x,int y,int num)
{
	static int i,x_p,y_p,flag,out;
	i=0,x_p=x_start,y_p=y_start+y-40,flag=0,out=0;
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
	static int re;
	re=0;
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
	if(mouse_press(585,450,625,480)==1)
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
	int i=0;
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
	int i;
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
	int i;
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
	int i;
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
	int i;
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

void select02()
{
	static int x[point_max],y[point_max],flag=0;
	cleardevice();
    setbkcolor(WHITE);
	setcolor(GREEN);
	setlinestyle(0,0,3);
	rectangle(x_start,y_start,x_start+x_max,y_start+y_max);
	puthz(170,30,"请依次在框内选点",32,32,BLUE);
	setfillstyle(1,GREEN);
	bar(200,70,280,115);
	puthz(207,76,"开始",32,32,WHITE);
	setfillstyle(1,RED);
	bar(320,70,400,115);
	puthz(327,76,"完成",32,32,WHITE);
	settextstyle(3,0,4);
	quit();

	mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_select02(x,y,&flag);
		delay(20);
	}
}

void press_select02(int *x,int *y,int *flag)
{
	if(mouse_press(0,0,40,30)==0||mouse_press(200,70,280,115)==0||mouse_press(320,70,400,115)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||mouse_press(200,70,280,115)==2||mouse_press(320,70,400,115)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	if(mouse_press(200,70,280,115)==1&&(*flag)==0)
	{
		pick_points(x,y,flag);
		return;
	}
	if(mouse_press(200,70,280,115)==1&&(*flag)!=0)
	{
		pick_points(x,y,flag);
		return;
	}
	if(mouse_press(320,70,400,115)==1)
	{
		init_field02(x,y,flag);
		return;
	}
}

void pick_wait()
{
	int i;
	for(i=0;i<30;i++)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(10);
	}
}

// void pick_start(int *x,int *y)
// {
// 	while(1)
// 	{
// 		newmouse(&MouseX,&MouseY,&press);
// 		if(mouse_press(x_start,y_start,x_start+x_max,y_start+y_max)==1)
// 		{
// 			*x=MouseX;
// 			*y=MouseY;
// 			break;
// 		}
// 		delay(20);
// 	}
// 	clrmous(MouseX,MouseY);
// 	setfillstyle(1,RED);
// 	bar((*x)-5,(*y)-5,(*x)+5,(*y)+5);
// 	setfillstyle(1,GREEN);
// 	bar(200,70,280,115);
// 	puthz(207,76,"继续",32,32,WHITE);
// 	return;
// }

void pick_points(int *x,int *y,int *flag)
{
	clrmous(MouseX,MouseY);
	setfillstyle(1,WHITE);
	bar(200,70,280,115);
	mouseinit();
	while(*flag==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(x_start,y_start,x_start+x_max,y_start+y_max)==1)
		{
			*x=MouseX;
			*y=MouseY;
			clrmous(MouseX,MouseY);
			setfillstyle(1,GREEN);
			bar(x[*flag]-5,y[*flag]-5,x[*flag]+5,y[*flag]+5);
			(*flag)++;
		}
		delay(20);
	}
	while((*flag)<point_max)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(MouseX!=x[(*flag)-1]&&mouse_press(x_start,y_start,x_start+x_max,y_start+y_max)==1)
		{
			x[*flag]=MouseX;
			y[*flag]=MouseY;
			clrmous(MouseX,MouseY);
			setfillstyle(1,RED);
			bar(x[*flag]-5,y[*flag]-5,x[*flag]+5,y[*flag]+5);
			setcolor(BLUE);
			line(x[(*flag)-1],y[(*flag)-1],x[*flag],y[*flag]);
			(*flag)++;
		}
		if(mouse_press(0,0,40,30)==0||mouse_press(320,70,400,115)==0)
		{
			MouseS=0;
		}
		if(mouse_press(0,0,40,30)==2||mouse_press(320,70,400,115)==2)
		{
			MouseS=1;
		}
		if(mouse_press(0,0,40,30)==1)
		{
			draw_wel();
		}
		// if(mouse_press(200,70,280,115)==1&&(*flag)==0)
		// {
		// 	pick_points(x,y,flag);
		// 	return;
		// }
		// if(mouse_press(200,70,280,115)==1&&(*flag)!=0)
		// {
		// 	pick_points(x,y,flag);
		// 	return;
		// }
		if(mouse_press(320,70,400,115)==1)
		{
			init_field02(x,y,flag);
		}
		delay(20);
	}
}

// void pick_points(int *x,int *y,int *flag)
// {
// 	while((*flag)<point_max)
// 	{
// 		newmouse(&MouseX,&MouseY,&press);
// 		if(mouse_press(x_start,y_start,x_start+x_max,y_start+y_max)==1)
// 		{
// 			x[*flag]=MouseX;
// 			y[*flag]=MouseY;
// 			break;
// 		}
// 		delay(20);
// 	}
// 	clrmous(MouseX,MouseY);
// 	setfillstyle(1,RED);
// 	bar(x[*flag]-5,y[*flag]-5,x[*flag]+5,y[*flag]+5);
// 	(*flag)++;
// 	return;
// }

void draw_points(int *x,int *y,int *flag,int *xy_m)
{
	int arr[point_max*2],i;
	for(i=0;i<(*flag);i++)
	{
		if(x[i]<xy_m[0])
		{
			xy_m[0]=x[i];
		}
		if(y[i]<xy_m[1])
		{
			xy_m[1]=y[i];
		}
		if(x[i]>xy_m[2])
		{
			xy_m[2]=x[i];
		}
		if(y[i]>xy_m[3])
		{
			xy_m[3]=y[i];
		}
		arr[2*i]=x[i];
		arr[2*i+1]=y[i];
	}
	setfillstyle(1,WHITE);
	setcolor(WHITE);
	fillpoly(i,arr);
}

/*void pick_points(int *x,int *y)
{
	int xn,yn,i=1;
	setfillstyle(1,RED);
	setlinestyle(0,0,1);
	setcolor(BLUE);
	while(xn<x[0]-5&&xn>x[0]+5&&yn<y[0]-5&&yn>x[0]+5)
	{
		pick_wait();
		bar(xn-5,yn-5,xn+5,yn+5);
		x[i]=xn;
		y[i]=yn;
		i++;
		while(1)
		{
			newmouse(&MouseX,&MouseY,&press);
			if(mouse_press(x_start,y_start,x_start+x_max,y_start+y_max)==1)
			{
				xn=MouseX;
				yn=MouseY;
				break;
			}
			delay(15);
		}
		line(x[i],y[i],xn,yn);
	}
	return;
}*/


void select03()
{
	static int x[dense_points_max],y[dense_points_max],flag=0;
	cleardevice();
    setbkcolor(WHITE);
	setcolor(GREEN);
	setlinestyle(0,0,3);
	rectangle(x_start,y_start,x_start+x_max,y_start+y_max);
	puthz(170,30,"请缓慢移动鼠标勾勒图形",32,32,BLUE);
	setfillstyle(1,GREEN);
	bar(200,70,280,115);
	puthz(207,76,"开始",32,32,WHITE);
	setfillstyle(1,RED);
	bar(320,70,400,115);
	puthz(327,76,"完成",32,32,WHITE);
	settextstyle(3,0,4);
	quit();

	mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_select03(x,y,&flag);
		delay(20);
	}
}

void press_select03(int *x,int *y,int *flag)
{
	if(mouse_press(0,0,40,30)==0||(mouse_press(200,70,280,115)==0&&(*flag==0))||mouse_press(320,70,400,115)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||(mouse_press(200,70,280,115)==2&&(*flag==0))||mouse_press(320,70,400,115)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	if(mouse_press(200,70,280,115)==1&&(*flag)==0)
	{
		dense_pick(x,y,flag);
		return;
	}
	if(mouse_press(320,70,400,115)==1)
	{
		init_field03(x,y,flag);
		return;
	}
}

void dense_pick(int *x,int *y,int *flag)
{
	setfillstyle(1,WHITE);
	clrmous(MouseX,MouseY);
	bar(200,70,280,115);
	setlinestyle(0,0,1);
	setcolor(BLUE);
	while((*flag)==0)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(x_start,y_start,x_start+x_max,y_start+y_max)==1)
		{
			*x=MouseX;
			*y=MouseY;
			clrmous(MouseX,MouseY);
			setfillstyle(1,GREEN);
			bar(x[*flag]-5,y[*flag]-5,x[*flag]+5,y[*flag]+5);
			(*flag)++;
			break;
		}
		delay(20);
	}
	pick_wait();
	setfillstyle(1,RED);
	while((*flag)<dense_points_max)
	{
		if(((*flag)>=5&&abs(MouseX-x[0])<=3&&abs(MouseY-y[0])<=3)||MouseX<=x_start||MouseX>=x_start+x_max\
		||MouseY<=y_start||MouseY>=y_start+y_max)
		{
			line(x[0],y[0],x[(*flag)-1],y[(*flag)-1]);
			return;
		}
		if((MouseX-x[(*flag)-1])*(MouseX-x[(*flag)-1])>=4&&(MouseY-y[(*flag)-1])*(MouseY-y[(*flag)-1])>=4)
		{
			x[*flag]=MouseX;
			y[*flag]=MouseY;
			clrmous(MouseX,MouseY);
			bar(x[*flag]-5,y[*flag]-5,x[*flag]+5,y[*flag]+5);
			line(x[(*flag)-1],y[(*flag)-1],x[(*flag)],y[(*flag)]);
			(*flag)++;
		}
		pick_wait();
	}
	return;
}

void dense_draw_points(int *x,int *y,int *flag,long int *xy_m)
{
	int arr[dense_points_max*2],i;
	for(i=0;i<(*flag);i++)
	{
		if(x[i]<xy_m[0])
		{
			xy_m[0]=x[i];
		}
		if(y[i]<xy_m[1])
		{
			xy_m[1]=y[i];
		}
		if(x[i]>xy_m[2])
		{
			xy_m[2]=x[i];
		}
		if(y[i]>xy_m[3])
		{
			xy_m[3]=y[i];
		}
		arr[2*i]=x[i];
		arr[2*i+1]=y[i];
	}
	setfillstyle(1,WHITE);
	setcolor(WHITE);
	fillpoly(i,arr);
	return;
}

void init_field02(int *x,int *y,int *flag)
{
	//The meaning of elements in xy_m:
	//[0]:minest of x,[1]:minest of y,[2]:largest of x,[3]:largest of y
	static long int xy_m[4]={x_start+x_max,y_start+y_max,x_start,y_start},i;
	setfillstyle(1,BROWN);
	setlinestyle(0,0,3);
	bar(x_start-5,y_start-5,x_start+x_max+5,y_start+y_max+5);
	draw_points(x,y,flag,xy_m);
	setcolor(BROWN);
	for(i=xy_m[0];i<=xy_m[2];i+=25)
	{
		int temp=0,j;
		for(j=xy_m[1];j<=xy_m[3];j+=2)
		{
			temp=rand()%2;
			line(i+temp,j,i+temp,j);
		}
	}
	for(i=0;i<((xy_m[2]-xy_m[0])*(xy_m[3]-xy_m[1]))*0.01;i++)
	{
		int x_r=rand()%(xy_m[2]-xy_m[0]),y_r=rand()%(xy_m[3]-xy_m[1]);
		line(xy_m[0]+x_r,xy_m[1]+y_r,xy_m[0]+x_r,xy_m[1]+y_r);
	}
	//setcolor(GREEN);
	//rectangle(xy_m[0],xy_m[1],xy_m[2],xy_m[3]);
	// setcolor(BROWN);
	// for(i=0;i<((xy_m[2]-xy_m[0])*(xy_m[3]-xy_m[1]))/20;i++)
	// {
	// 	int x_r=rand()%(xy_m[2]-xy_m[0]),y_r=rand()%(xy_m[3]-xy_m[1]);
	// 	line(xy_m[0]+x_r,xy_m[1]+y_r,xy_m[0]+x_r,xy_m[1]+y_r);
	// }
	delay(1000);
	//dense_init_tracktor01(x,y,flag,xy_m,3);
}


void init_field03(int *x,int *y,int *flag)
{
	//The meaning of elements in xy_m:
	//[0]:minest of x,[1]:minest of y,[2]:largest of x,[3]:largest of y
	static long int xy_m[4]={x_start+x_max,y_start+y_max,x_start,y_start},i;
	setfillstyle(1,BROWN);
	setlinestyle(0,0,3);
	bar(x_start-5,y_start-5,x_start+x_max+5,y_start+y_max+5);
	dense_draw_points(x,y,flag,xy_m);
	setcolor(BROWN);
	for(i=xy_m[0];i<=xy_m[2];i+=25)
	{
		int temp=0,j;
		for(j=xy_m[1];j<=xy_m[3];j+=2)
		{
			temp=rand()%2;
			line(i+temp,j,i+temp,j);
		}
	}
	for(i=0;i<((xy_m[2]-xy_m[0])*(xy_m[3]-xy_m[1]))*0.01;i++)
	{
		int x_r=rand()%(xy_m[2]-xy_m[0]),y_r=rand()%(xy_m[3]-xy_m[1]);
		line(xy_m[0]+x_r,xy_m[1]+y_r,xy_m[0]+x_r,xy_m[1]+y_r);
	}
	//setcolor(GREEN);
	//rectangle(xy_m[0],xy_m[1],xy_m[2],xy_m[3]);
	// setcolor(BROWN);
	// for(i=0;i<((xy_m[2]-xy_m[0])*(xy_m[3]-xy_m[1]))/20;i++)
	// {
	// 	int x_r=rand()%(xy_m[2]-xy_m[0]),y_r=rand()%(xy_m[3]-xy_m[1]);
	// 	line(xy_m[0]+x_r,xy_m[1]+y_r,xy_m[0]+x_r,xy_m[1]+y_r);
	// }
	delay(1000);
	dense_init_tracktor01(x,y,flag,xy_m,3);
}

void dense_init_tracktor01(int *x,int *y,int *flag,long int* xy_m,int num)
{
	static int x_d,i,tra_d[tracktor_num_max][4];
	x_d=xy_m[2]-xy_m[0];
	x_d/=num;
	for(i=0;i<num;i++)
	{
		int k=0;
		tra_d[i][0]=xy_m[0]+i*x_d;
		tra_d[i][2]=xy_m[0]+(i+1)*x_d;
		tra_d[i][1]=xy_m[3];
		tra_d[i][3]=xy_m[1];
		while(k<(*flag))
		{
			int target=0;
			if(x[k]>=tra_d[i][0]&&x[k]<=tra_d[i][2])
			{
				if(target==0)
				{
					target=1;
				}
				if(y[k]<tra_d[i][1])
				{
					tra_d[i][1]=y[k];
				}
				if(y[k]>tra_d[i][3])
				{
					tra_d[i][3]=y[k];
				}
			}
			if(target!=0&&(x[k]<tra_d[i][0]||x[k]>tra_d[i][2]))
			{
				break;
			}
			else
			{
				k++;
			}
		}
	}
	start_ainime03_01(tra_d,num);
}

void start_ainime03_01(int (*tra_d)[4],int num)
{
	static int mode[tracktor_num_max],x_p[tracktor_num_max],y_p[tracktor_num_max],i;
	for(i=0;i<tracktor_num_max;i++)
	{
		mode[i]=0;
		x_p[i]=tra_d[i][0];
		y_p[i]=y_start+y_max-40;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(mode[i]==4)
			{
				count++;
			}
		}
		for(i=0;i<num;i++)
		{
			if((mode[i]!=0&&y_p[i]-40>=y_start+y_max)||x_p[i]>=tra_d[i][2])
			{
				if(mode[i]!=4)
				{
					init_tracktor01_f(x_p[i]-25,y_p[i]);
					mode[i]=4;
				}
				else
				{
					continue;
				}
			}
			else if(mode[i]==0)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor01_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					mode[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(mode[i]==1)
			{
				earth_fill02(x_p[i],y_p[i]);
				init_tracktor01_b(x_p[i],y_p[i]);
				y_p[i]++;
				if(y_p[i]+40>=tra_d[i][3])
				{
					if(x_p[i]+25>tra_d[i][2])
					{
						mode[i]=3;
					}
					else
					{
						earth_fill03(x_p[i],y_p[i]-1);
						earth_fill03(x_p[i],y_p[i]+2);
						mode[i]=2;
						x_p[i]+=25;
					}
				}
				delay(20/(num-count));
				continue;
			}
			else if (mode[i]=2)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor01_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					mode[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(mode[i]=3)
			{
				earth_fill02(x_p[i],y_p[i]);
				init_tracktor01_b(x_p[i],y_p[i]);
				y_p[i]++;
			}
		}
		if(count>=num)
		{
			break;
		}
	}
}

void start_ainime03_02(int (*tra_d)[4],int num)
{
	static int mode[tracktor_num_max],x_p[tracktor_num_max],y_p[tracktor_num_max],i;
	for(i=0;i<tracktor_num_max;i++)
	{
		mode[i]=0;
		x_p[i]=tra_d[i][0];
		y_p[i]=y_start+y_max-40;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(mode[i]==4)
			{
				count++;
			}
		}
		for(i=0;i<num;i++)
		{
			if((mode[i]!=0&&y_p[i]-40>=y_start+y_max)||x_p[i]>=tra_d[i][2])
			{
				if(mode[i]!=4)
				{
					init_tracktor02_f(x_p[i]-25,y_p[i]);
					mode[i]=4;
				}
				else
				{
					continue;
				}
			}
			else if(mode[i]==0)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor02_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					mode[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(mode[i]==1)
			{
				earth_fill02(x_p[i],y_p[i]);
				init_tracktor02_b(x_p[i],y_p[i]);
				y_p[i]++;
				if(y_p[i]+40>=tra_d[i][3])
				{
					if(x_p[i]+25>tra_d[i][2])
					{
						mode[i]=3;
					}
					else
					{
						earth_fill03(x_p[i],y_p[i]-1);
						earth_fill03(x_p[i],y_p[i]+2);
						mode[i]=2;
						x_p[i]+=25;
					}
				}
				delay(20/(num-count));
				continue;
			}
			else if (mode[i]=2)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor02_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					mode[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(mode[i]=3)
			{
				earth_fill02(x_p[i],y_p[i]);
				init_tracktor02_b(x_p[i],y_p[i]);
				y_p[i]++;
			}
		}
		if(count>=num)
		{
			break;
		}
	}
}