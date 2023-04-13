#include "TOTAL.H"

int main()
{
	int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
	setbkcolor(WHITE);
 	h=(user*)malloc(sizeof(user));//登录的用户
	strcpy(h->parameter[0].name,"abc");
	strcpy(h->parameter[1].name,"acc");
	//strcpy(&h->parameter[0].type,"a");
	h->parameter[1].type='a';
	h->parameter[1].place='a';
	//strcpy(&h->parameter[0].shape,"a");
	h->parameter[1].shape='b';
	strcpy(h->parameter[1].S,"300");
	start();	
	delay(5000);
	return 0;
}
// int main()
// {
// 	int gd=VGA,gm=VGAHI;
// 	int gd=VGA,gm=VGAHI,start_x=400,start_y=100,des_x=100,des_y=300; 
// 	initgraph(&gd,&gm,"..\\borlandc\\bgi");
// 	setbkcolor(WHITE);
// 	setfillstyle(1,LIGHTGRAY);
// 	bar(start_x,start_y,start_x+tra_start_l,start_y+tra_start_d);
// 	tracktor_return(start_x,start_y,des_x,des_y,50,4);
// 	delay(4000);
// 	return 0;
// }

void start()
{
	int i=0,time=0;
	double space=0,harvest=0;
	for(i=0;i<10;i++)
	{
		if(strcmp(h->parameter[i].name,"\0")==0)
		{
			break;
		}
	}
	i--;
	space=atoi(h->parameter[i].S);
	time=space/pick_ph;
	switch(h->parameter[i].place)
	{
		case 'a':
		{
			harvest=space*Xinjinag_har*(1+(rand()%8)/100);
			break;
		}
		case 'b':
		{
			harvest=space*Huanghe_har*(1+(rand()%8)/100);
			break;
		}
		case 'c':
		{
			harvest=space*Chnagjiang_har*(1+(rand()%8)/100);
			break;
		}
	}

	switch(h->parameter[i].type)
	{
		case 'a':
		{
			draw_simu01(time);
			switch(h->parameter[i].shape)
			{
				case 'a':
				{
					start_ainime01(0,space);
					break;
				}
				case 'b':
				{
					cal_tracktor_circle(0,space);
					break;
				}
				case 'c':
				{
					init_field02(h->parameter[i].x,h->parameter[i].y,&h->parameter[i].lenxy,0);
					break;
				}
				case 'd':
				{
					init_field03(h->parameter[i].x,h->parameter[i].y,&h->parameter[i].lenxy,0);
					break;
				}
			}
			if(mode!=3)
				return;
			pick_finish(harvest);
			break;
		}
		
		case 'b':
		{
			draw_simu01(time*0.8);
			switch(h->parameter[i].shape)
			{
				case 'a':
				{
					start_ainime01(1,space);
					break;
				}
				case 'b':
				{
					cal_tracktor_circle(1,space);
					break;
				}
				case 'c':
				{
					init_field02(h->parameter[i].x,h->parameter[i].y,&h->parameter[i].lenxy,1);
					break;
				}
				case 'd':
				{
					init_field03(h->parameter[i].x,h->parameter[i].y,&h->parameter[i].lenxy,1);
					break;
				}
			}
			if(mode!=3)
				return;
			pick_finish(harvest*0.8);
			break;
		}

		default:
			break;
	}


	switch (h->parameter[i].place)
	{
		case 'a':
		{
			h->here[k].total[0]+=harvest;
			break;
		}
		case 'b':
		{
			h->here[k].total[1]+=harvest;
			break;
		}
		case 'c':
		{
			h->here[k].total[2]+=harvest;
			break;
		}
		
		default:
			break;
	}
	return;
}


//draw the process of harvest in animition
void draw_simu01(int time)
{
	char str[8];
	itoa(time,str,10);
    cleardevice();
    setbkcolor(WHITE);
	puthz(150,30,"采摘完成还需",32,32,BLUE);
	settextstyle(3,0,4);
	setcolor(RED);
	outtextxy(350,28,str);
    puthz(450,30,"小时",32,32,BLUE);
	init_based_field();
    //outtextxy()
	quit();
    // mouseinit();
	// start_ainime01(0,x,y,num);
	// pick_finish(temp);
	// tal[c_t]+=temp;
	// if(tal[c_t]>ware_full||tal[c_t]<0)
	// {
	// 	tal[c_t]=ware_full;
	// }
	// for(;;)
	// {
	// 	newmouse(&MouseX,&MouseY,&press);
	// 	press_start();
	// 	delay(20);
	// }
	
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	//closegraph();
	return;
}

void init_based_field()
{
	setfillstyle(1,BROWN);
	bar(0,100,615,500);
	return;
}

//start playing the picking video
void start_ainime01(int t_trac,double space)
{
	int i,x_p,y_p,flag,out,x,y,num;
	double temp_x,temp_y;
	temp_y=sqrt(space/55*32)*10;
	temp_x=temp_y*55/32;
	x=temp_x,y=temp_y,num=temp_x/(tracktor_w*4);
	x/=num;
	i=0,x_p=x_start,y_p=y_start+y-40,flag=0,out=0;
	skip();
	init_field(x,y);
	if(t_trac==0)
	{
		earth_fill01(x_p, y_p);
		init_tracktor01_f(x_p, y_p);
		while (1)
		{
			if (x_p >= 50 + x)
			{
				break;
			}
			for (i = 0; i < num; i++)
			{
				newmouse(&MouseX, &MouseY, &press);
				if (flag == 0)
				{
					if (y_p == 120 + y - 45)
					{
						earth_fill03(x_p + i * x, y_p - 4);
					}
					if (y_p >= 120 + 7)
					{
						earth_fill01(x_p + i * x, y_p);
						init_tracktor01_f(x_p + i * x, y_p);
					}
					if (y_p <= 120 + 7)
					{
						earth_fill03(x_p + i * x, 120);
					}
				}
				else
				{
					if (y_p == 120 + 7)
					{
						earth_fill01(x_p + i * x, y_p - 7);
					}
					if (y_p <= 120 + y - 45)
					{
						earth_fill02(x_p + i * x, y_p);
						init_tracktor01_b(x_p + i * x, y_p);
					}
					if (y_p >= 120 + y - 45)
					{
						earth_fill03(x_p + i * x, 120 + y - 49);
					}
				}
				delay(20 / num);
			}
			if (flag == 0)
			{
				y_p--;
				if (y_p <= 120 + 7)
				{
					for (i = 0; i < num; i++)
						earth_fill03(x_p + i * x, 120);
					flag = 1;
					x_p += 25;
				}
			}
			else
			{
				y_p++;
				if (y_p >= 120 + y - 45)
				{
					for (i = 0; i < num; i++)
						earth_fill03(x_p + i * x, 120 + y - 49);
					flag = 0;
					x_p += 25;
				}
			}
			out = pressed_anime(x * num, y);
			if (out != 0)
			{
				for (i = 1; i <= num; i++)
				{
					init_tracktor01_f(x_start + i * x - x % 25, y_start + 7);
				}
				break;
			}
			// delay(15*num);
		}
		if(mode==0)
		{
			return;
		}
		for(i=1;i<=num;i++)
		{
			if (flag == 1)
				init_tracktor01_f(x_start + i * x - x % 25, y_start + 7);
			else
				init_tracktor01_b(x_start + i * x - x % 25, y_start + y - 45);
		}
	}
	else
	{
		earth_fill01(x_p, y_p);
		init_tracktor02_f(x_p, y_p);
		while (1)
		{
			if (x_p >= 50 + x)
			{
				break;
			}
			for (i = 0; i < num; i++)
			{
				newmouse(&MouseX, &MouseY, &press);
				if (flag == 0)
				{
					if (y_p == 120 + y - 45)
					{
						earth_fill03(x_p + i * x, y_p - 4);
					}
					if (y_p >= 120 + 7)
					{
						earth_fill01(x_p + i * x, y_p);
						init_tracktor02_f(x_p + i * x, y_p);
					}
					if (y_p <= 120 + 7)
					{
						earth_fill03(x_p + i * x, 120);
					}
				}
				else
				{
					if (y_p == 120 + 7)
					{
						earth_fill01(x_p + i * x, y_p - 7);
					}
					if (y_p <= 120 + y - 45)
					{
						earth_fill02(x_p + i * x, y_p);
						init_tracktor02_b(x_p + i * x, y_p);
					}
					if (y_p >= 120 + y - 45)
					{
						earth_fill03(x_p + i * x, 120 + y - 49);
					}
				}
				delay(20 / num);
			}
			if (flag == 0)
			{
				y_p--;
				if (y_p <= 120 + 7)
				{
					for (i = 0; i < num; i++)
						earth_fill03(x_p + i * x, 120);
					flag = 1;
					x_p += 25;
				}
			}
			else
			{
				y_p++;
				if (y_p >= 120 + y - 45)
				{
					for (i = 0; i < num; i++)
						earth_fill03(x_p + i * x, 120 + y - 49);
					flag = 0;
					x_p += 25;
				}
			}
			out = pressed_anime(x * num, y);
			if (out != 0)
			{
				for (i = 1; i <= num; i++)
				{
					init_tracktor02_f(x_start + i * x - x % 25, y_start + 7);
				}
				break;
			}
			// delay(15*num);
		}
		if(mode==0)
		{
			return;
		}
		for(i=1;i<=num;i++)
		{
			if (flag == 1)
				init_tracktor02_f(x_start + i * x - x % 25, y_start + 7);
			else
				init_tracktor02_b(x_start + i * x - x % 25, y_start + y - 45);
		}
	}
}

//add the press moudules in start page
void press_start(int *bk)
{
	if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(265, 350, 365, 410) == 0)
	{
		MouseS = 0;
	}
	if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(265, 350, 365, 410) == 2)
	{
		MouseS = 1;
	}
	if (mouse_press(0, 0, 40, 30) == 1)
	{
		mode=0;
		*bk=0;
		return;
	}
	else if (mouse_press(265, 350, 365, 410) == 1)
	{
		//draw_home01();
		mode=1;
		mode1=0;
		*bk=0;
		return;
	}
}

// add press moudules in video page
int pressed_anime(int x, int y)
{
	int re;
	re=0;
	if(MouseX>=x_start&&MouseY>=y_start&&MouseX<=x_start+x&&MouseY<=y_start+y)
	{
		clrmous(MouseX, MouseY);
	}
	if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(585, 450, 625, 480) == 0)
	{
		MouseS = 0;
	}
	if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(585, 450, 625, 480) == 2)
	{
		MouseS = 1;
	}
	if (mouse_press(0, 0, 40, 30) == 1)
	{
		mode=0;
		re=1;
	}
	if (mouse_press(585, 450, 625, 480) == 1)
	{
		anime_skip_result(x, y);
		re = 1;
	}
	return re;
}

// show after picking
void pick_finish(int count)
{
	char str[10];
	int bk=0;
	itoa(count,str,10);
	setfillstyle(1,WHITE);
	bar(160,170,470,340);
	setcolor(RED);
	setlinestyle(0, 0, 3);
	rectangle(165, 175, 465, 335);

	puthz(210,190,"采摘完成",32,32,BLUE);
	puthz(210,230,"共计：",32,32,BLUE);
	settextstyle(3,0,4);
	puthz(380,230,"吨",32,32,BLUE);
	outtextxy(300,225,str);
	switch(h->here[k].cotton_type)
	{
	case 0:
	{
		puthz(210, 270, "种类：长绒棉", 32, 32, BLUE);
		break;
	}
	case 1:
	{
		puthz(210, 270, "种类：细绒棉", 32, 32, BLUE);
		break;
	}
	case 2:
	{
		puthz(210, 270, "种类：粗绒棉", 32, 32, BLUE);
		break;
	}
	default:
		break;
	}

	setfillstyle(1,YELLOW);
	bar(265,350,365,410);
	puthz(278,360,"入库",32,32,RED);
	while(1)
	{
		if(bk!=0)
			break;
        newmouse(&MouseX,&MouseY,&press);
		press_start(&bk);
	}
	return;
}

// moudules which skip the video and show the result
void anime_skip_result(int x, int y)
{
	int i = 0;
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x_start, y_start, x_start + x, y_start + y);
	for (i = 0; i < 2000; i++)
	{
		int x_t = rand() % x, y_t = rand() % y;
		line(x_start + x_t, y_start + y_t, x_start + x_t, y_start + y_t);
	}
}

// initialize the cotton field
void init_field(int x, int y)
{
	int i,j;
	setfillstyle(1,WHITE);
	bar(x_start,y_start,x_start+x,y_start+y);
	setcolor(BROWN);
	setlinestyle(0, 0, 1);
	line(50, 120, 50 + x, 120);
	line(50, 120 + y, 50 + x, 120 + y);
	for (i = 50; i <= 50 + x; i += 25)
	{
		int temp = 0;
		for (j = 120; j <= 120 + y; j += 1)
		{
			temp = rand() % 2;
			line(i + temp, j, i + temp, j);
		}
	}
	for (i = 0; i < 5000; i++)
	{
		int x_temp = 0, y_temp = 0;
		x_temp = rand() % x;
		y_temp = rand() % y;
		line(50 + x_temp, 120 + y_temp, 50 + x_temp, 120 + y_temp);
	}
}

// initialize the tarcker 01
void init_tracktor01_f(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, RED);
	bar(x + 3, y - 3, x + 22, y + 38);
	rectangle(x + 3, y - 3, x + 22, y + 38);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y - 6, x + 19, y + 35);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x, y, x + 25, y - 3);
	rectangle(x, y, x + 25, y + 3);
	for (i = x; i <= 25 + x; i += 2)
	{
		bar(i - 1, y + 1, i + 1, y - 4);
		rectangle(i - 1, y + 1, i + 1, y - 4);
	}

	// The driver site
	setfillstyle(1, RED);
	bar(x + 7, y - 5, x + 18, y + 6);
	rectangle(x + 7, y - 5, x + 18, y + 6);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 9, x + 3, y + 15);
	bar(x + 22, y + 9, x + 24, y + 15);
	bar(x + 1, y + 26, x + 3, y + 32);
	bar(x + 22, y + 26, x + 24, y + 32);
}

// initialize the tracktor type 1
void init_tracktor01_b(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, RED);
	bar(x + 3, y, x + 22, y + 41);
	rectangle(x + 3, y, x + 22, y + 41);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y + 3, x + 19, y + 38);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x, y + 38, x + 25, y + 41);
	rectangle(x, y + 38, x + 25, y + 41);
	for (i = x; i <= 25 + x; i += 2)
	{
		bar(i - 1, y + 41, i + 1, y + 37);
		rectangle(i - 1, y + 41, i + 1, y + 37);
	}

	// The driver site
	setfillstyle(1, RED);
	bar(x + 7, y + 43, x + 18, y + 32);
	rectangle(x + 7, y + 43, x + 18, y + 32);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 29, x + 3, y + 23);
	bar(x + 22, y + 29, x + 24, y + 23);
	bar(x + 1, y + 12, x + 3, y + 6);
	bar(x + 22, y + 12, x + 24, y + 6);
}

void init_tracktor01_r(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, RED);
	bar(x - 3, y + 3, x - 38, y + 22);
	rectangle(x - 3, y + 3, x - 38, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 6, y + 6, x - 35, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x, y, x - 3, y + 25);
	rectangle(x, y, x - 3, y + 25);
	for (i = y; i <= 25 + y; i += 2)
	{
		bar(x + 1, i - 1, x - 4, i + 1);
		rectangle(x + 1, i - 1, x - 4, i + 1);
	}

	// The driver site
	setfillstyle(1, RED);
	bar(x - 5, y + 7, x + 6, y + 18);
	rectangle(x - 5, y + 7, x + 6, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 9, y + 1, x - 15, y + 3);
	bar(x - 9, y + 22, x - 15, y + 24);
	bar(x - 26, y + 1, x - 32, y + 3);
	bar(x - 26, y + 22, x - 32, y + 24);
}

void init_tracktor01_l(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, RED);
	bar(x, y + 3, x - 41, y + 22);
	rectangle(x, y + 3, x - 41, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 3, y + 6, x - 38, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x - 38, y, x - 41, y + 25);
	rectangle(x - 38, y, x - 41, y + 25);
	for (i = y; i <= 25 + y; i += 2)
	{
		bar(x - 41, i - 1, x - 37, i + 1);
		rectangle(x - 41, i - 1, x - 37, i + 1);
	}

	// The driver site
	setfillstyle(1, RED);
	bar(x - 43, y + 7, x - 32, y + 18);
	rectangle(x - 43, y + 7, x - 32, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 29, y + 1, x - 23, y + 3);
	bar(x - 29, y + 22, x - 23, y + 24);
	bar(x - 12, y + 1, x - 6, y + 3);
	bar(x - 12, y + 22, x - 6, y + 24);
}

// initialize the tarcker 02 in front
void init_tracktor02_f(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, GREEN);
	bar(x + 3, y - 3, x + 22, y + 38);
	rectangle(x + 3, y - 3, x + 22, y + 38);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y - 6, x + 19, y + 35);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x, y, x + 25, y - 3);
	rectangle(x, y, x + 25, y + 3);
	for (i = x; i <= 25 + x; i += 2)
	{
		bar(i - 1, y + 1, i + 1, y - 4);
		rectangle(i - 1, y + 1, i + 1, y - 4);
	}

	// The driver site
	setfillstyle(1, GREEN);
	bar(x + 7, y - 5, x + 18, y + 6);
	rectangle(x + 7, y - 5, x + 18, y + 6);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 9, x + 3, y + 15);
	bar(x + 22, y + 9, x + 24, y + 15);
	bar(x + 1, y + 26, x + 3, y + 32);
	bar(x + 22, y + 26, x + 24, y + 32);
}

// initialize the tracktor type 2 in backward
void init_tracktor02_b(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, GREEN);
	bar(x + 3, y, x + 22, y + 41);
	rectangle(x + 3, y, x + 22, y + 41);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y + 3, x + 19, y + 38);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x, y + 38, x + 25, y + 41);
	rectangle(x, y + 38, x + 25, y + 41);
	for (i = x; i <= 25 + x; i += 2)
	{
		bar(i - 1, y + 41, i + 1, y + 37);
		rectangle(i - 1, y + 41, i + 1, y + 37);
	}

	// The driver site
	setfillstyle(1, GREEN);
	bar(x + 7, y + 43, x + 18, y + 32);
	rectangle(x + 7, y + 43, x + 18, y + 32);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 29, x + 3, y + 23);
	bar(x + 22, y + 29, x + 24, y + 23);
	bar(x + 1, y + 12, x + 3, y + 6);
	bar(x + 22, y + 12, x + 24, y + 6);
}

void init_tracktor02_r(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, GREEN);
	bar(x - 3, y + 3, x - 38, y + 22);
	rectangle(x - 3, y + 3, x - 38, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 6, y + 6, x - 35, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x, y, x - 3, y + 25);
	rectangle(x, y, x - 3, y + 25);
	for (i = y; i <= 25 + y; i += 2)
	{
		bar(x + 1, i - 1, x - 4, i + 1);
		rectangle(x + 1, i - 1, x - 4, i + 1);
	}

	// The driver site
	setfillstyle(1, GREEN);
	bar(x - 5, y + 7, x + 6, y + 18);
	rectangle(x - 5, y + 7, x + 6, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 9, y + 1, x - 15, y + 3);
	bar(x - 9, y + 22, x - 15, y + 24);
	bar(x - 26, y + 1, x - 32, y + 3);
	bar(x - 26, y + 22, x - 32, y + 24);
}

void init_tracktor02_l(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, GREEN);
	bar(x, y + 3, x - 41, y + 22);
	rectangle(x, y + 3, x - 41, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 3, y + 6, x - 38, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, YELLOW);
	bar(x - 38, y, x - 41, y + 25);
	rectangle(x - 38, y, x - 41, y + 25);
	for (i = y; i <= 25 + y; i += 2)
	{
		bar(x - 41, i - 1, x - 37, i + 1);
		rectangle(x - 41, i - 1, x - 37, i + 1);
	}

	// The driver site
	setfillstyle(1, GREEN);
	bar(x - 43, y + 7, x - 32, y + 18);
	rectangle(x - 43, y + 7, x - 32, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 29, y + 1, x - 23, y + 3);
	bar(x - 29, y + 22, x - 23, y + 24);
	bar(x - 12, y + 1, x - 6, y + 3);
	bar(x - 12, y + 22, x - 6, y + 24);
}

// earth filling after pick ,front
void earth_fill01(int x, int y)
{
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y, x + 25, y + 41);
	if (y % 4 == 0)
	{
		int x_temp = rand() % 25;
		line(x + x_temp, y + 41, x + x_temp, y + 41);
	}
}

// earth filling after pick,back
void earth_fill02(int x, int y)
{
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y - 1, x + 25, y + 41);
	if (y % 4 == 0)
	{
		int x_temp = rand() % 25;
		line(x + x_temp, y - 1, x + x_temp, y - 1);
	}
}

// earth filling after pick, turn direction
void earth_fill03(int x, int y)
{
	int i;
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y, x + 25, y + 50);
	for (i = 0; i < 10; i++)
	{
		int x_temp = rand() % 25, y_temp = rand() % 50;
		line(x_temp + x, y_temp + y, x_temp + x, y_temp + y);
	}
}

// earth filling  ,front and back
void earth_cover01(int x, int y)
{
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y, x + 25, y + 41);
	// if(y%4==0)
	// {
	// 	int x_temp=rand()%25;
	// 	line(x+x_temp,y+41,x+x_temp,y+41);
	// }
}

// earth filling ,left and right
void earth_cover02(int x, int y)
{
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y - 1, x - 41, y + 25);
	// if(y%4==0)
	// {
	// 	int x_temp=rand()%25;
	// 	line(x+x_temp,y-1,x+x_temp,y-1);
	// }
}

// earth filling , turn direction
void earth_cover03(int x, int y)
{
	int i;
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y, x + 25, y + 50);
	// for(i=0;i<10;i++)
	// {
	// 	int x_temp=rand()%25,y_temp=rand()%50;
	// 	line(x_temp+x,y_temp+y,x_temp+x,y_temp+y);
	// }
}

void select02(struct Parameter *abc)
{
	int x[point_max], y[point_max], flag = 0, back = 0,i;
	cleardevice();
	setbkcolor(WHITE);
	setcolor(GREEN);
	setlinestyle(0, 0, 3);
	rectangle(x_start, y_start, x_start + x_max, y_start + y_max);
	puthz(170, 30, "请依次在框内选点", 32, 32, BLUE);
	setfillstyle(1, GREEN);
	bar(200, 70, 280, 115);
	puthz(207, 76, "开始", 32, 32, WHITE);
	setfillstyle(1, RED);
	bar(320, 70, 400, 115);
	puthz(327, 76, "完成", 32, 32, WHITE);
	settextstyle(3, 0, 4);
	quit();

	mouseinit();
	while (1)
	{
		if (back != 0)
		{
			return;
		}
		newmouse(&MouseX, &MouseY, &press);
		press_select02(x, y, &flag, &back);
		delay(20);
	}
	abc->lenxy=flag;
	for (i=0;i<dense_points_max;i++)
	{
		abc->x[i]=x[i];
		abc->y[i]=y[i];
	}
}

void press_select02(int *x, int *y, int *flag, int *back)
{
	if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(200, 70, 280, 115) == 0 || mouse_press(320, 70, 400, 115) == 0)
	{
		MouseS = 0;
	}
	if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(200, 70, 280, 115) == 2 || mouse_press(320, 70, 400, 115) == 2)
	{
		MouseS = 1;
	}
	if (mouse_press(0, 0, 40, 30) == 1)
	{
		draw_wel();
	}
	if (mouse_press(200, 70, 280, 115) == 1)
	{
		pick_points(x, y, flag);
		return;
	}
	// if(mouse_press(200,70,280,115)==1&&(*flag)!=0)
	// {
	// 	pick_points(x,y,flag);
	// 	return;
	// }
	if (mouse_press(320, 70, 400, 115) == 1)
	{
		init_field02(x, y, flag);
		*back = 1;
	}
}

void pick_wait()
{
	int i;
	for (i = 0; i < 30; i++)
	{
		newmouse(&MouseX, &MouseY, &press);
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

void pick_points(int *x, int *y, int *flag)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, WHITE);
	bar(200, 70, 280, 115);
	// mouseinit();
	while (*flag == 0)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(x_start, y_start, x_start + x_max, y_start + y_max) == 1)
		{
			*x = MouseX;
			*y = MouseY;
			clrmous(MouseX, MouseY);
			setfillstyle(1, GREEN);
			bar(x[*flag] - 5, y[*flag] - 5, x[*flag] + 5, y[*flag] + 5);
			(*flag)++;
		}
		delay(20);
	}
	while ((*flag) < point_max)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (MouseX != x[(*flag) - 1] && mouse_press(x_start, y_start, x_start + x_max, y_start + y_max) == 1)
		{
			x[*flag] = MouseX;
			y[*flag] = MouseY;
			clrmous(MouseX, MouseY);
			setfillstyle(1, RED);
			bar(x[*flag] - 5, y[*flag] - 5, x[*flag] + 5, y[*flag] + 5);
			setcolor(BLUE);
			line(x[(*flag) - 1], y[(*flag) - 1], x[*flag], y[*flag]);
			(*flag)++;
		}
		if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(320, 70, 400, 115) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(320, 70, 400, 115) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(0, 0, 40, 30) == 1)
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
		if (mouse_press(320, 70, 400, 115) == 1)
		{
			break;
			// init_field02(x,y,flag);
		}
		delay(20);
	}
	return;
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

void draw_points(int *x, int *y, int *flag, int *xy_m)
{
	int arr[point_max * 2], i;
	for (i = 0; i < (*flag); i++)
	{
		if (x[i] < xy_m[0])
		{
			xy_m[0] = x[i];
		}
		if (y[i] < xy_m[1])
		{
			xy_m[1] = y[i];
		}
		if (x[i] > xy_m[2])
		{
			xy_m[2] = x[i];
		}
		if (y[i] > xy_m[3])
		{
			xy_m[3] = y[i];
		}
		arr[2 * i] = x[i];
		arr[2 * i + 1] = y[i];
	}
	setfillstyle(1, WHITE);
	setcolor(WHITE);
	fillpoly(i, arr);
	return;
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

void select03(struct Parameter *abc)
{
	int x[dense_points_max], y[dense_points_max], flag = 0, back=0,i;
	cleardevice();
	setbkcolor(WHITE);
	setcolor(GREEN);
	setlinestyle(0, 0, 3);
	rectangle(x_start, y_start, x_start + x_max, y_start + y_max);
	puthz(170, 30, "请缓慢移动鼠标勾勒图形", 32, 32, BLUE);
	setfillstyle(1, GREEN);
	bar(200, 70, 280, 115);
	puthz(207, 76, "开始", 32, 32, WHITE);
	setfillstyle(1, RED);
	bar(320, 70, 400, 115);
	puthz(327, 76, "完成", 32, 32, WHITE);
	settextstyle(3, 0, 4);
	quit();

	mouseinit();
	while (1)
	{
		if (back != 0)
		{
			return;
		}
		newmouse(&MouseX, &MouseY, &press);
		press_select03(x, y, &flag,&back);
		delay(20);
	}
	abc->lenxy=flag;
	for (i=0;i<dense_points_max;i++)
	{
		abc->x[i]=x[i];
		abc->y[i]=y[i];
	}
}

void press_select03(int *x, int *y, int *flag,int *back)
{
	if (mouse_press(0, 0, 40, 30) == 0 || (mouse_press(200, 70, 280, 115) == 0 && (*flag == 0)) || mouse_press(320, 70, 400, 115) == 0)
	{
		MouseS = 0;
	}
	if (mouse_press(0, 0, 40, 30) == 2 || (mouse_press(200, 70, 280, 115) == 2 && (*flag == 0)) || mouse_press(320, 70, 400, 115) == 2)
	{
		MouseS = 1;
	}
	if (mouse_press(0, 0, 40, 30) == 1)
	{
		draw_wel();
	}
	if (mouse_press(200, 70, 280, 115) == 1 && (*flag) == 0)
	{
		dense_pick(x, y, flag);
		return;
	}
	if (mouse_press(320, 70, 400, 115) == 1)
	{
		init_field03(x, y, flag);
		back=1;
	}
}

void dense_pick(int *x, int *y, int *flag)
{
	setfillstyle(1, WHITE);
	clrmous(MouseX, MouseY);
	bar(200, 70, 280, 115);
	setlinestyle(0, 0, 1);
	setcolor(BLUE);
	while ((*flag) == 0)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(x_start, y_start, x_start + x_max, y_start + y_max) == 1)
		{
			*x = MouseX;
			*y = MouseY;
			clrmous(MouseX, MouseY);
			setfillstyle(1, GREEN);
			bar(x[*flag] - 5, y[*flag] - 5, x[*flag] + 5, y[*flag] + 5);
			(*flag)++;
			break;
		}
		delay(20);
	}
	pick_wait();
	setfillstyle(1, RED);
	while ((*flag) < dense_points_max)
	{
		if (((*flag) >= 5 && abs(MouseX - x[0]) <= 3 && abs(MouseY - y[0]) <= 3) || MouseX <= x_start || MouseX >= x_start + x_max || MouseY <= y_start || MouseY >= y_start + y_max)
		{
			line(x[0], y[0], x[(*flag) - 1], y[(*flag) - 1]);
			return;
		}
		if ((MouseX - x[(*flag) - 1]) * (MouseX - x[(*flag) - 1]) >= 4 && (MouseY - y[(*flag) - 1]) * (MouseY - y[(*flag) - 1]) >= 4)
		{
			x[*flag] = MouseX;
			y[*flag] = MouseY;
			clrmous(MouseX, MouseY);
			bar(x[*flag] - 5, y[*flag] - 5, x[*flag] + 5, y[*flag] + 5);
			line(x[(*flag) - 1], y[(*flag) - 1], x[(*flag)], y[(*flag)]);
			(*flag)++;
		}
		pick_wait();
	}
	return;
}

void dense_draw_points(int *x, int *y, int *flag, long int *xy_m)
{
	int arr[dense_points_max * 2], i;
	for (i = 0; i < (*flag); i++)
	{
		if (x[i] < xy_m[0])
		{
			xy_m[0] = x[i];
		}
		if (y[i] < xy_m[1])
		{
			xy_m[1] = y[i];
		}
		if (x[i] > xy_m[2])
		{
			xy_m[2] = x[i];
		}
		if (y[i] > xy_m[3])
		{
			xy_m[3] = y[i];
		}
		arr[2 * i] = x[i];
		arr[2 * i + 1] = y[i];
	}
	setfillstyle(1, WHITE);
	setcolor(WHITE);
	fillpoly(i, arr);
	return;
}

void init_field02(int *x,int *y,int *flag,int type)
{
	// The meaning of elements in xy_m:
	//[0]:minest of x,[1]:minest of y,[2]:largest of x,[3]:largest of y
	long int xy_m[4]={x_start+x_max,y_start+y_max,x_start,y_start};
	int i,num=0;
	setfillstyle(1,BROWN);
	setlinestyle(0,0,3);
	bar(x_start-5,y_start-5,x_start+x_max+5,y_start+y_max+5);
	draw_points(x,y,flag,xy_m);
	setfillstyle(1,WHITE);
	bar(xy_m[0],xy_m[1],xy_m[2],xy_m[3]);
	setcolor(BROWN);
	for (i = xy_m[0]; i <= xy_m[2]; i += 25)
	{
		int temp = 0, j;
		for (j = xy_m[1]; j <= xy_m[3]; j += 2)
		{
			temp = rand() % 2;
			line(i + temp, j, i + temp, j);
		}
	}
	for (i = 0; i < ((xy_m[2] - xy_m[0]) * (xy_m[3] - xy_m[1])) * 0.01; i++)
	{
		int x_r = rand() % (xy_m[2] - xy_m[0]), y_r = rand() % (xy_m[3] - xy_m[1]);
		line(xy_m[0] + x_r, xy_m[1] + y_r, xy_m[0] + x_r, xy_m[1] + y_r);
	}
	for (i = xy_m[0]; i <= xy_m[2]; i += 25)
	{
		int j = 0;
		for (j = xy_m[1]; j <= xy_m[3]; j++)
		{
			int temp = rand() % 2;
			line(i + temp, j, i + temp, j);
		}
	}
	//setcolor(GREEN);
	//rectangle(xy_m[0],xy_m[1],xy_m[2],xy_m[3]);
	// setcolor(BROWN);
	// for(i=0;i<((xy_m[2]-xy_m[0])*(xy_m[3]-xy_m[1]))/20;i++)
	// {
	// 	int x_r=rand()%(xy_m[2]-xy_m[0]),y_r=rand()%(xy_m[3]-xy_m[1]);
	// 	line(xy_m[0]+x_r,xy_m[1]+y_r,xy_m[0]+x_r,xy_m[1]+y_r);
	// }
	num=(xy_m[2]-xy_m[0])/(tracktor_w*4);
	//delay(1000);
	if(type==0)
		dense_init_tracktor01(x,y,flag,xy_m,num);
	else
		dense_init_tracktor02(x,y,flag,xy_m,num);
}


void init_field03(int *x,int *y,int *flag,int type)
{
	// The meaning of elements in xy_m:
	//[0]:minest of x,[1]:minest of y,[2]:largest of x,[3]:largest of y
	long int xy_m[4]={x_start+x_max,y_start+y_max,x_start,y_start};
	int i,num=0;
	// setfillstyle(1,BROWN);
	// setlinestyle(0,0,3);
	// bar(x_start-5,y_start-5,x_start+x_max+5,y_start+y_max+5);
	dense_draw_points(x,y,flag,xy_m);
	setfillstyle(1,WHITE);
	bar(xy_m[0],xy_m[1],xy_m[2],xy_m[3]);
	setcolor(BROWN);
	for (i = xy_m[0]; i <= xy_m[2]; i += 25)
	{
		int temp = 0, j;
		for (j = xy_m[1]; j <= xy_m[3]; j += 2)
		{
			temp = rand() % 2;
			line(i + temp, j, i + temp, j);
		}
	}
	for (i = 0; i < ((xy_m[2] - xy_m[0]) * (xy_m[3] - xy_m[1])) * 0.01; i++)
	{
		int x_r = rand() % (xy_m[2] - xy_m[0]), y_r = rand() % (xy_m[3] - xy_m[1]);
		line(xy_m[0] + x_r, xy_m[1] + y_r, xy_m[0] + x_r, xy_m[1] + y_r);
	}
	for (i = xy_m[0]; i <= xy_m[2]; i += 25)
	{
		int j = 0;
		for (j = xy_m[1]; j <= xy_m[3]; j++)
		{
			int temp = rand() % 2;
			line(i + temp, j, i + temp, j);
		}
	}
	//setcolor(GREEN);
	//rectangle(xy_m[0],xy_m[1],xy_m[2],xy_m[3]);
	// setcolor(BROWN);
	// for(i=0;i<((xy_m[2]-xy_m[0])*(xy_m[3]-xy_m[1]))/20;i++)
	// {
	// 	int x_r=rand()%(xy_m[2]-xy_m[0]),y_r=rand()%(xy_m[3]-xy_m[1]);
	// 	line(xy_m[0]+x_r,xy_m[1]+y_r,xy_m[0]+x_r,xy_m[1]+y_r);
	// }
	//delay(1000);
	num=(xy_m[2]-xy_m[0])/(tracktor_w*4);
	if(type==0)
		dense_init_tracktor01(x,y,flag,xy_m,num);
	else
		dense_init_tracktor02(x,y,flag,xy_m,num);
}

void dense_init_tracktor01(int *x, int *y, int *flag, long int *xy_m, int num)
{
	int x_d,i,tra_d[tracktor_num_max][4];
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
				if(y[k]<tra_d[i][1])
				{
					tra_d[i][1]=y[k];
				}
				if(y[k]>tra_d[i][3])
				{
					tra_d[i][3]=y[k];
				}
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

void dense_init_tracktor02(int *x,int *y,int *flag,long int* xy_m,int num)
{
	int x_d,i,tra_d[tracktor_num_max][4];
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
				if(y[k]<tra_d[i][1])
				{
					tra_d[i][1]=y[k];
				}
				if(y[k]>tra_d[i][3])
				{
					tra_d[i][3]=y[k];
				}
				break;
			}
			else
			{
				k++;
			}
		}
	}
	start_ainime03_02(tra_d,num);
}

void start_ainime03_01(int (*tra_d)[4], int num)
{
	int type[tracktor_num_max],x_p[tracktor_num_max],y_p[tracktor_num_max],i;
	for(i=0;i<num;i++)
	{
		type[i] = 0;
		x_p[i] = tra_d[i][0];
		y_p[i] = y_start + y_max - 40;
	}
	while (1)
	{
		int count=0;
		newmouse(&MouseX,&MouseY,&press);
		for(i=0;i<num;i++)
		{
			if (type[i] == 4)
			{
				count++;
			}
		}
		for (i = 0; i < num; i++)
		{
			if ((type[i] != 0 && y_p[i] - 40 >= y_start + y_max) || x_p[i] >= tra_d[i][2])
			{
				if (type[i] != 4)
				{
					init_tracktor01_f(x_p[i] - 25, y_p[i]);
					type[i] = 4;
				}
				else
				{
					continue;
				}
			}
			else if (type[i] == 0)
			{
				earth_fill01(x_p[i], y_p[i]);
				init_tracktor01_f(x_p[i], y_p[i]);
				y_p[i]--;
				if (y_p[i] <= tra_d[i][1])
				{
					earth_fill03(x_p[i], y_p[i] - 7);
					type[i] = 1;
					x_p[i] += 25;
				}
				delay(20 / (num - count));
				continue;
			}
			else if (type[i] == 1)
			{
				earth_fill02(x_p[i], y_p[i]);
				init_tracktor01_b(x_p[i], y_p[i]);
				y_p[i]++;
				if (y_p[i] + 40 >= tra_d[i][3])
				{
					if (x_p[i] + 25 > tra_d[i][2])
					{
						type[i] = 3;
					}
					else
					{
						earth_fill03(x_p[i], y_p[i] - 1);
						earth_fill03(x_p[i], y_p[i] + 2);
						type[i] = 2;
						x_p[i] += 25;
					}
				}
				delay(20 / (num - count));
				continue;
			}
			else if (type[i] = 2)
			{
				earth_fill01(x_p[i], y_p[i]);
				init_tracktor01_f(x_p[i], y_p[i]);
				y_p[i]--;
				if (y_p[i] <= tra_d[i][1])
				{
					earth_fill03(x_p[i], y_p[i] - 7);
					type[i] = 1;
					x_p[i] += 25;
				}
				delay(20 / (num - count));
				continue;
			}
			else if (type[i] = 3)
			{
				earth_fill02(x_p[i], y_p[i]);
				init_tracktor01_b(x_p[i], y_p[i]);
				y_p[i]++;
			}
		}
		if (count >= num)
		{
			break;
		}
	}
}

void start_ainime03_02(int (*tra_d)[4], int num)
{
	int type[tracktor_num_max],x_p[tracktor_num_max],y_p[tracktor_num_max],i;
	for(i=0;i<num;i++)
	{
		type[i] = 0;
		x_p[i] = tra_d[i][0];
		y_p[i] = y_start + y_max - 40;
	}
	while (1)
	{
		int count=0;
		newmouse(&MouseX,&MouseY,&press);
		for(i=0;i<num;i++)
		{
			if (type[i] == 4)
			{
				count++;
			}
		}
		for (i = 0; i < num; i++)
		{
			if ((type[i] != 0 && y_p[i] - 40 >= y_start + y_max) || x_p[i] >= tra_d[i][2])
			{
				if (type[i] != 4)
				{
					init_tracktor02_f(x_p[i] - 25, y_p[i]);
					type[i] = 4;
				}
				else
				{
					continue;
				}
			}
			else if (type[i] == 0)
			{
				earth_fill01(x_p[i], y_p[i]);
				init_tracktor02_f(x_p[i], y_p[i]);
				y_p[i]--;
				if (y_p[i] <= tra_d[i][1])
				{
					earth_fill03(x_p[i], y_p[i] - 7);
					type[i] = 1;
					x_p[i] += 25;
				}
				delay(20 / (num - count));
				continue;
			}
			else if (type[i] == 1)
			{
				earth_fill02(x_p[i], y_p[i]);
				init_tracktor02_b(x_p[i], y_p[i]);
				y_p[i]++;
				if (y_p[i] + 40 >= tra_d[i][3])
				{
					if (x_p[i] + 25 > tra_d[i][2])
					{
						type[i] = 3;
					}
					else
					{
						earth_fill03(x_p[i], y_p[i] - 1);
						earth_fill03(x_p[i], y_p[i] + 2);
						type[i] = 2;
						x_p[i] += 25;
					}
				}
				delay(20 / (num - count));
				continue;
			}
			else if (type[i] = 2)
			{
				earth_fill01(x_p[i], y_p[i]);
				init_tracktor02_f(x_p[i], y_p[i]);
				y_p[i]--;
				if (y_p[i] <= tra_d[i][1])
				{
					earth_fill03(x_p[i], y_p[i] - 7);
					type[i] = 1;
					x_p[i] += 25;
				}
				delay(20 / (num - count));
				continue;
			}
			else if (type[i] = 3)
			{
				earth_fill02(x_p[i], y_p[i]);
				init_tracktor02_b(x_p[i], y_p[i]);
				y_p[i]++;
			}
		}
		if (count >= num)
		{
			break;
		}
	}
}
void circle_field(long int r)
{
	long int x0 = (2 * x_start + x_max) / 2, y0 = (2 * y_start + y_max) / 2;
	int i;
	setfillstyle(1,WHITE);
	fillellipse(x0,y0,r,r);
	setfillstyle(1,BROWN);
	bar(x_start,y_start,x_start+x_max,y_start+y_max);
	if(r>=y_max/2-3)
	{
		r = y_max / 2 - 3;
	}
	setfillstyle(1, WHITE);
	fillellipse(x0, y0, r, r);
	setcolor(BROWN);
	for (i = 0; i < 4 * r * r / 20; i++)
	{
		int x_r = rand() % (2 * r), y_r = rand() % (2 * r);
		line(x0 - r + x_r, y0 - r + y_r, x0 - r + x_r, y0 - r + y_r);
	}
	for (i = x0 - r; i <= x0 + r; i += 25)
	{
		int j = 0;
		for (j = y0 - r; j <= y0 + r; j++)
		{
			int temp = rand() % 2;
			line(i + temp, j, i + temp, j);
		}
	}
}

void cal_tracktor_circle(int type,double space)
{
	long int x0=(2*x_start+x_max)/2,y0=(2*y_start+y_max)/2,r;
	int tra_d[tracktor_num_max][4],i,d,num;
	r=sqrt(space/3.1415926)*10;
	num=2*r/(tracktor_w*4);
	if(r>=y_max/2-3)
	{
		r = y_max / 2 - 3;
	}
	d = 2 * r / num;
	for (i = 0; i < num; i++)
	{
		tra_d[i][0] = x0 - r + i * d;
		tra_d[i][2] = tra_d[i][0] + d;
		if (tra_d[i][0] <= x0)
		{
			tra_d[i][1] = y0 - sqrt(r * r - (r - d * (i + 1)) * (r - d * (i + 1)));
		}
		else
		{
			tra_d[i][1] = y0 - sqrt(r * r - (r - d * i) * (r - d * i));
		}
		tra_d[i][3] = 2 * y0 - tra_d[i][1];
	}
	tra_d[num / 2 - 1][1] = y0 - r;
	tra_d[num / 2 - 1][3] = y0 + r;
	tra_d[num / 2][1] = y0 - r;
	tra_d[num / 2][3] = y0 + r;
	// if(num%2==0)
	// {
	// 	for(i=0;i<num/2;i++)
	// 	{
	// 		tra_d[i][0]=x0-r+i*d;
	// 		tra_d[i][2]=tra_d[i][0]+d;
	// 		tra_d[i][1]=y0-sqrt(r*r-(r-d*(i+1))*(r-d*(i+1)));
	// 		tra_d[i][3]=2*y0-tra_d[i][1];
	// 	}
	// 	tra_d[i-1][1]=y0-r;
	// 	tra_d[i-1][3]=y0+r;
	// 	for(i=num/2;i<num;i++)
	// 	{
	// 		tra_d[i][0]=2*x0-tra_d[num-i-1][2];
	// 		tra_d[i][2]=2*x0-tra_d[num-i-1][0];
	// 		tra_d[i][1]=tra_d[num-i-1][1];
	// 		tra_d[i][3]=tra_d[num-i-1][3];
	// 	}
	// }
	// else
	// {
	// 	for(i=0;i<num/2;i++)
	// 	{
	// 		tra_d[i][0]=x0-r+i*d;
	// 		tra_d[i][2]=tra_d[i][0]+d;
	// 		tra_d[i][1]=y0-sqrt(r*r-(r-d*(i+1))*(r-d*(i+1)));
	// 		tra_d[i][3]=2*y0-tra_d[i][1];
	// 	}
	// 	tra_d[i][1]=y0-r;
	// 	tra_d[i][3]=y0+r;
	// 	for(i=num/2+1;i<num;i++)
	// 	{
	// 		tra_d[i][0]=2*x0-tra_d[num-i-1][2];
	// 		tra_d[i][2]=2*x0-tra_d[num-i-1][0];
	// 		tra_d[i][1]=tra_d[num-i-1][1];
	// 		tra_d[i][3]=tra_d[num-i-1][3];
	// 	}
	// }
	circle_field(r);
	if(type==0)
		start_ainime04_01(tra_d,num);
	else
		start_ainime04_02(tra_d,num);
	return;
}

void start_ainime04_01(int (*tra_d)[4],int num)
{
	int x0=(2*x_start+x_max)/2,y0=(2*y_start+y_max)/2,type[tracktor_num_max],i\
	,x_p[tracktor_num_max],y_p[tracktor_num_max];
	for(i=0;i<num;i++)
	{
		type[i]=0;
		x_p[i]=tra_d[i][0];
		y_p[i]=y_start+y_max-40;
	}
	while(1)
	{
		int count=0;
        newmouse(&MouseX,&MouseY,&press);
		for(i=0;i<num;i++)
		{
			if(type[i]==4)
			{
				count++;
			}
		}
		for(i=0;i<num;i++)
		{
			if((type[i]!=0&&y_p[i]-40>=y_start+y_max)||x_p[i]>=tra_d[i][2])
			{
				if(type[i]!=4)
				{
					init_tracktor01_f(x_p[i]-25,y_p[i]);
					type[i]=4;
				}
				else
				{
					continue;
				}
			}
			else if(type[i]==0)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor01_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					type[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(type[i]==1)
			{
				earth_fill02(x_p[i],y_p[i]);
				init_tracktor01_b(x_p[i],y_p[i]);
				y_p[i]++;
				if(y_p[i]+40>=tra_d[i][3])
				{
					if(x_p[i]+25>tra_d[i][2])
					{
						type[i]=3;
					}
					else
					{
						earth_fill03(x_p[i],y_p[i]-1);
						earth_fill03(x_p[i],y_p[i]+2);
						type[i]=2;
						x_p[i]+=25;
					}
				}
				delay(20/(num-count));
				continue;
			}
			else if (type[i]=2)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor01_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					type[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(type[i]=3)
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

void start_ainime04_02(int (*tra_d)[4],int num)
{
	int x0=(2*x_start+x_max)/2,y0=(2*y_start+y_max)/2,type[tracktor_num_max],i\
	,x_p[tracktor_num_max],y_p[tracktor_num_max];
	for(i=0;i<num;i++)
	{
		type[i]=0;
		x_p[i]=tra_d[i][0];
		y_p[i]=y_start+y_max-40;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==4)
			{
				count++;
			}
		}
		for(i=0;i<num;i++)
		{
			if((type[i]!=0&&y_p[i]-40>=y_start+y_max)||x_p[i]>=tra_d[i][2])
			{
				if(type[i]!=4)
				{
					init_tracktor02_f(x_p[i]-25,y_p[i]);
					type[i]=4;
				}
				else
				{
					continue;
				}
			}
			else if(type[i]==0)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor02_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					type[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(type[i]==1)
			{
				earth_fill02(x_p[i],y_p[i]);
				init_tracktor02_b(x_p[i],y_p[i]);
				y_p[i]++;
				if(y_p[i]+40>=tra_d[i][3])
				{
					if(x_p[i]+25>tra_d[i][2])
					{
						type[i]=3;
					}
					else
					{
						earth_fill03(x_p[i],y_p[i]-1);
						earth_fill03(x_p[i],y_p[i]+2);
						type[i]=2;
						x_p[i]+=25;
					}
				}
				delay(20/(num-count));
				continue;
			}
			else if (type[i]=2)
			{
				earth_fill01(x_p[i],y_p[i]);
				init_tracktor02_f(x_p[i],y_p[i]);
				y_p[i]--;
				if(y_p[i]<=tra_d[i][1])
				{
					earth_fill03(x_p[i],y_p[i]-7);
					type[i]=1;
					x_p[i]+=25;
				}
				delay(20/(num-count));
				continue;
			}
			else if(type[i]=3)
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

long int hellen(int x1, int y1, int x2, int y2, int x3, int y3)
{
	long int a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)), b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3)),
			 c = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2)), p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}

long int cal_poly_field(int *x, int *y, int *flag)
{
	int x0 = (x[0] + x[(*flag) / 2]) / 2, y0 = (y[0] + y[(*flag) / 2]) / 2, i;
	long int s_field = 0;
	for (i = 0; i < (*flag) - 2; i++)
	{
		s_field += hellen(x0, y0, x[i], y[i], x[i + 1], y[i + 1]);
	}
	s_field += hellen(x0, x0, x[i], y[i], x[0], x[0]);
	return s_field;
}

double cal_circle_field(int r)
{
	double pi = 3.1415926;
	return pi * r * r;
}

void tracktor_set_off(int start_x, int start_y, int des_x, int des_y, int distance, int num)
{
	if (start_x < des_x && start_y < des_y)
	{
		tracktor_set_off01(start_x, start_y, des_x, des_y, distance, num);
	}
	else if (start_x < des_x && start_y > des_y)
	{
		tracktor_set_off02(start_x, start_y, des_x, des_y, distance, num);
	}
	else if (start_x > des_x && start_y < des_y)
	{
		tracktor_set_off03(start_x, start_y, des_x, des_y, distance, num);
	}
	else
	{
		tracktor_set_off04(start_x, start_y, des_x, des_y, distance, num);
	}
}

// start_x<des_x&&start_y<des_y
void tracktor_set_off01(int start_x, int start_y, int des_x, int des_y, int distance, int num)
{
	int x_p[tracktor_num_max], y_p[tracktor_num_max], type[tracktor_num_max], time[tracktor_num_max], i;
	for (i = 0; i < num; i++)
	{
		type[i] = 0;
		time[i] = i * distance;
		x_p[i] = (2 * start_x + tra_start_l) / 2 - tracktor_w / 2;
		y_p[i] = start_y + tra_start_d + 1;
	}
	while (1)
	{
		int count = 0;
		for (i = 0; i < num; i++)
		{
			if (time[i] > 0)
			{
				time[i]--;
				continue;
			}
			if (type[i] == 2)
			{
				count++;
				continue;
			}
			if (type[i] == 0)
			{
				earth_cover01(x_p[i], y_p[i]);
				y_p[i]++;
				init_tracktor01_b(x_p[i], y_p[i]);
				if (y_p[i] >= des_y)
				{
					earth_cover01(x_p[i], y_p[i]);
					earth_cover01(x_p[i], y_p[i] + 5);
					type[i] = 1;
					x_p[i] += tracktor_l;
					init_tracktor01_r(x_p[i], y_p[i]);
					continue;
				}
			}
			if (type[i] == 1)
			{
				earth_cover02(x_p[i], y_p[i]);
				x_p[i]++;
				init_tracktor01_r(x_p[i], y_p[i]);
				if (x_p[i] >= des_x + (num - i - 1) * distance)
				{
					earth_cover02(x_p[i],y_p[i]);
					earth_cover02(x_p[i]+7,y_p[i]);
					type[i]=2;
					//init_tracktor01_f(x_p[i],y_p[i]-35);
					continue;
				}
			}
		}
		if (count >= num)
		{
			break;
		}
		delay(20);
	}
}

// start_x<des_x&&start_y>des_y
void tracktor_set_off02(int start_x, int start_y, int des_x, int des_y, int distance, int num)
{
	int x_p[tracktor_num_max], y_p[tracktor_num_max], type[tracktor_num_max], time[tracktor_num_max], i;
	for (i = 0; i < num; i++)
	{
		type[i] = 0;
		time[i] = i * distance;
		x_p[i] = (2 * start_x + tra_start_l) / 2 - tracktor_w / 2;
		y_p[i] = start_y - tra_start_d - 1 - tracktor_l;
	}
	while (1)
	{
		int count = 0;
		for (i = 0; i < num; i++)
		{
			if (time[i] > 0)
			{
				time[i]--;
				continue;
			}
			if (type[i] == 2)
			{
				count++;
				continue;
			}
			if (type[i] == 0)
			{
				earth_cover01(x_p[i], y_p[i]);
				y_p[i]--;
				init_tracktor01_f(x_p[i], y_p[i]);
				if (y_p[i] <= des_y)
				{
					earth_cover01(x_p[i], y_p[i]);
					earth_cover01(x_p[i], y_p[i] - 7);
					type[i] = 1;
					x_p[i] += tracktor_l;
					init_tracktor01_r(x_p[i], y_p[i]);
					continue;
				}
			}
			if (type[i] == 1)
			{
				earth_cover02(x_p[i], y_p[i]);
				x_p[i]++;
				init_tracktor01_r(x_p[i], y_p[i]);
				if (x_p[i] >= des_x + (num - i - 1) * distance)
				{
					earth_cover02(x_p[i],y_p[i]);
					earth_cover02(x_p[i]+7,y_p[i]);
					type[i]=2;
					//init_tracktor01_f(x_p[i],y_p[i]-35);
					continue;
				}
			}
		}
		if (count >= num)
		{
			break;
		}
		delay(20);
	}
}

// start_x>des_x&&start_y<des_y
void tracktor_set_off03(int start_x, int start_y, int des_x, int des_y, int distance, int num)
{
	int x_p[tracktor_num_max], y_p[tracktor_num_max], type[tracktor_num_max], time[tracktor_num_max], i;
	for (i = 0; i < num; i++)
	{
		type[i] = 0;
		time[i] = i * distance;
		x_p[i] = (2 * start_x + tra_start_l) / 2 - tracktor_w / 2;
		y_p[i] = start_y + tra_start_d + 1;
	}
	while (1)
	{
		int count = 0;
		for (i = 0; i < num; i++)
		{
			if (time[i] > 0)
			{
				time[i]--;
				continue;
			}
			if (type[i] == 2)
			{
				count++;
				continue;
			}
			if (type[i] == 0)
			{
				earth_cover01(x_p[i], y_p[i]);
				y_p[i]++;
				init_tracktor01_b(x_p[i], y_p[i]);
				if (y_p[i] >= des_y)
				{
					earth_cover01(x_p[i], y_p[i]);
					earth_cover01(x_p[i], y_p[i] + 5);
					type[i] = 1;
					x_p[i] += tracktor_l;
					init_tracktor01_l(x_p[i], y_p[i]);
					continue;
				}
			}
			if (type[i] == 1)
			{
				earth_cover02(x_p[i] + 5, y_p[i]);
				x_p[i]--;
				init_tracktor01_l(x_p[i], y_p[i]);
				if (x_p[i] <= des_x + i * distance)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-5,y_p[i]);
					type[i]=2;
					//init_tracktor01_f(x_p[i]-50,y_p[i]-35);
					continue;
				}
			}
		}
		if (count >= num)
		{
			break;
		}
		delay(20);
	}
}

// start_x>=des_x&&start_y>=des_y
void tracktor_set_off04(int start_x, int start_y, int des_x, int des_y, int distance, int num)
{
	int x_p[tracktor_num_max], y_p[tracktor_num_max], type[tracktor_num_max], time[tracktor_num_max], i;
	for (i = 0; i < num; i++)
	{
		type[i] = 0;
		time[i] = i * distance;
		x_p[i] = (2 * start_x + tra_start_l) / 2 - tracktor_w / 2;
		y_p[i] = start_y - tra_start_d - 1 - tracktor_l;
	}
	while (1)
	{
		int count = 0;
		for (i = 0; i < num; i++)
		{
			if (time[i] > 0)
			{
				time[i]--;
				continue;
			}
			if (type[i] == 2)
			{
				count++;
				continue;
			}
			if (type[i] == 0)
			{
				earth_cover01(x_p[i], y_p[i]);
				y_p[i]--;
				init_tracktor01_f(x_p[i], y_p[i]);
				if (y_p[i] <= des_y)
				{
					earth_cover01(x_p[i], y_p[i]);
					earth_cover01(x_p[i], y_p[i] - 7);
					type[i] = 1;
					x_p[i] += tracktor_l;
					init_tracktor01_r(x_p[i], y_p[i]);
					continue;
				}
			}
			if (type[i] == 1)
			{
				earth_cover02(x_p[i] + 7, y_p[i]);
				x_p[i]--;
				init_tracktor01_l(x_p[i], y_p[i]);
				if (x_p[i] <= des_x + i * distance)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-5,y_p[i]);
					type[i]=2;
					//init_tracktor01_f(x_p[i]-50,y_p[i]-35);
					continue;
				}
			}
		}
		if (count >= num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return(int start_x, int start_y, int des_x, int des_y, int distance, int num)
{
	if(start_x<des_x&&start_y>des_y)
	{
		tracktor_return01(start_x, start_y, des_x, des_y, distance, num);
	}
	else if(start_x>des_x&&start_y>des_y)
	{
		tracktor_return02(start_x,start_y,des_x,des_y,distance,num);
	}
	else if(start_x<des_x&&start_y<des_y)
	{
		tracktor_return03(start_x,start_y,des_x,des_y,distance,num);
	}
	else
	{
		tracktor_return04(start_x,start_y,des_x,des_y,distance,num);
	}
}

void tracktor_return01(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[i]=0;
		x_p[i]=des_x+i*distance;
		y_p[i]=des_y;
		earth_fill03(x_p[i],y_p[i]);
		x_p[i]-=tracktor_l;
		y_p[i]-=tracktor_w;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]--;
				init_tracktor01_l(x_p[i],y_p[i]);
				if(x_p[i]<=((2*start_x+tra_start_l)/2-tracktor_w/2)+50)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-6,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]++;
				init_tracktor01_b(x_p[i],y_p[i]);
				if(y_p[i]>=start_y-48)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]+5);
					type[i]=2;
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return02(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[num-1-i]=0;
		x_p[num-1-i]=des_x+i*distance;
		y_p[num-1-i]=des_y;
		earth_fill03(x_p[i],y_p[i]);
		x_p[num-1-i]+=tracktor_l;
		y_p[num-1-i]-=tracktor_w;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]++;
				init_tracktor01_r(x_p[i],y_p[i]);
				if(x_p[i]>=((2*start_x+tra_start_l)/2-tracktor_w/2))
				{
					earth_cover02(x_p[i]+6,y_p[i]);
					earth_cover02(x_p[i]-2,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]++;
				init_tracktor01_b(x_p[i],y_p[i]);
				if(y_p[i]>=start_y-48)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]+5);
					type[i]=2;
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return03(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[i]=0;
		x_p[i]=des_x+i*distance;
		y_p[i]=des_y;
		earth_fill03(x_p[i],y_p[i]);
		x_p[i]-=tracktor_l;
		y_p[i]-=tracktor_w;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]--;
				init_tracktor01_l(x_p[i],y_p[i]);
				if(x_p[i]<=((2*start_x+tra_start_l)/2-tracktor_w/2)+50)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-6,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					y_p[i]-=tracktor_l;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]--;
				init_tracktor01_f(x_p[i],y_p[i]);
				if(y_p[i]<=start_y+tra_start_l-6)
				{
					earth_cover01(x_p[i],y_p[i]-7);
					earth_cover01(x_p[i],y_p[i]+3);
					type[i]=2;
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return04(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[num-1-i]=0;
		x_p[num-1-i]=des_x+i*distance+tracktor_l;
		y_p[num-1-i]=des_y-tracktor_w;
		earth_fill03(x_p[i],y_p[i]);
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]++;
				init_tracktor01_r(x_p[i],y_p[i]);
				if(x_p[i]>=((2*start_x+tra_start_l)/2-tracktor_w/2))
				{
					earth_cover02(x_p[i]+6,y_p[i]);
					earth_cover02(x_p[i]-2,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					y_p[i]-=tracktor_w;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]--;
				init_tracktor01_f(x_p[i],y_p[i]);
				if(y_p[i]<=start_y+tra_start_l-6)
				{
					earth_cover01(x_p[i],y_p[i]-7);
					earth_cover01(x_p[i],y_p[i]+3);
					type[i]=2;
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_set_off0(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	if(start_x<des_x&&start_y<des_y)
	{
		tracktor_set_off001(start_x,start_y,des_x,des_y,distance,num);
	}
	else if(start_x<des_x&&start_y>des_y)
	{
		tracktor_set_off002(start_x,start_y,des_x,des_y,distance,num);
	}
	else if(start_x>des_x&&start_y<des_y)
	{
		tracktor_set_off003(start_x,start_y,des_x,des_y,distance,num);
	}
	else
	{
		tracktor_set_off004(start_x,start_y,des_x,des_y,distance,num);
	}
}

//start_x<des_x&&start_y<des_y
void tracktor_set_off001(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max], y_p[tracktor_num_max], type[tracktor_num_max], time[tracktor_num_max], i;
	for (i = 0; i < num; i++)
	{
		type[i] = 0;
		time[i] = i * distance;
		x_p[i] = (2 * start_x + tra_start_l) / 2 - tracktor_w / 2;
		y_p[i] = start_y + tra_start_d + 1;
	}
	while (1)
	{
		int count = 0;
		for (i = 0; i < num; i++)
		{
			if (time[i] > 0)
			{
				time[i]--;
				continue;
			}
			if (type[i] == 2)
			{
				count++;
				continue;
			}
			if (type[i] == 0)
			{
				earth_cover01(x_p[i], y_p[i]);
				y_p[i]++;
				init_tracktor02_b(x_p[i],y_p[i]);
				if(y_p[i]>=des_y)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]+5);
					type[i]=1;
					x_p[i]+=tracktor_l;
					init_tracktor02_r(x_p[i],y_p[i]);
					continue;
				}
			}
			if (type[i] == 1)
			{
				earth_cover02(x_p[i], y_p[i]);
				x_p[i]++;
				init_tracktor02_r(x_p[i],y_p[i]);
				if(x_p[i]>=des_x+(num-i-1)*distance)
				{
					earth_cover02(x_p[i],y_p[i]);
					earth_cover02(x_p[i]+7,y_p[i]);
					type[i]=2;
					//init_tracktor02_f(x_p[i],y_p[i]-35);
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

//start_x<des_x&&start_y>des_y
void tracktor_set_off002(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],time[tracktor_num_max],i;
	for(i=0;i<num;i++)
	{
		type[i]=0;
		time[i]=i*distance;
		x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
		y_p[i]=start_y-tra_start_d-1-tracktor_l;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(time[i]>0)
			{
				time[i]--;
				continue;
			}
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]--;
				init_tracktor02_f(x_p[i],y_p[i]);
				if(y_p[i]<=des_y)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]-7);
					type[i]=1;
					x_p[i]+=tracktor_l;
					init_tracktor02_r(x_p[i],y_p[i]);
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover02(x_p[i],y_p[i]);
				x_p[i]++;
				init_tracktor02_r(x_p[i],y_p[i]);
				if(x_p[i]>=des_x+(num-i-1)*distance)
				{
					earth_cover02(x_p[i],y_p[i]);
					earth_cover02(x_p[i]+7,y_p[i]);
					type[i]=2;
					//init_tracktor02_f(x_p[i],y_p[i]-35);
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

//start_x>des_x&&start_y<des_y
void tracktor_set_off003(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],time[tracktor_num_max],i;
	for(i=0;i<num;i++)
	{
		type[i]=0;
		time[i]=i*distance;
		x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
		y_p[i]=start_y+tra_start_d+1;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(time[i]>0)
			{
				time[i]--;
				continue;
			}
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]++;
				init_tracktor02_b(x_p[i],y_p[i]);
				if(y_p[i]>=des_y)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]+5);
					type[i]=1;
					x_p[i]+=tracktor_l;
					init_tracktor02_l(x_p[i],y_p[i]);
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover02(x_p[i]+5,y_p[i]);
				x_p[i]--;
				init_tracktor02_l(x_p[i],y_p[i]);
				if(x_p[i]<=des_x+i*distance)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-5,y_p[i]);
					type[i]=2;
					//init_tracktor02_f(x_p[i]-50,y_p[i]-35);
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

//start_x>=des_x&&start_y>=des_y
void tracktor_set_off004(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],time[tracktor_num_max],i;
	for(i=0;i<num;i++)
	{
		type[i]=0;
		time[i]=i*distance;
		x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
		y_p[i]=start_y-tra_start_d-1-tracktor_l;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(time[i]>0)
			{
				time[i]--;
				continue;
			}
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]--;
				init_tracktor02_f(x_p[i],y_p[i]);
				if(y_p[i]<=des_y)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]-7);
					type[i]=1;
					x_p[i]+=tracktor_l;
					init_tracktor02_r(x_p[i],y_p[i]);
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover02(x_p[i]+7,y_p[i]);
				x_p[i]--;
				init_tracktor02_l(x_p[i],y_p[i]);
				if(x_p[i]<=des_x+i*distance)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-5,y_p[i]);
					type[i]=2;
					//init_tracktor02_f(x_p[i]-50,y_p[i]-35);
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return0(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	if(start_x<des_x&&start_y>des_y)
	{
		tracktor_return001(start_x,start_y,des_x,des_y,distance,num);
	}
	else if(start_x>des_x&&start_y>des_y)
	{
		tracktor_return002(start_x,start_y,des_x,des_y,distance,num);
	}
	else if(start_x<des_x&&start_y<des_y)
	{
		tracktor_return003(start_x,start_y,des_x,des_y,distance,num);
	}
	else
	{
		tracktor_return004(start_x,start_y,des_x,des_y,distance,num);
	}
}

void tracktor_return001(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[i]=0;
		x_p[i]=des_x+i*distance;
		y_p[i]=des_y;
		earth_fill03(x_p[i],y_p[i]);
		x_p[i]-=tracktor_l;
		y_p[i]-=tracktor_w;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]--;
				init_tracktor02_l(x_p[i],y_p[i]);
				if(x_p[i]<=((2*start_x+tra_start_l)/2-tracktor_w/2)+50)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-6,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]++;
				init_tracktor02_b(x_p[i],y_p[i]);
				if(y_p[i]>=start_y-48)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]+5);
					type[i]=2;
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return002(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[num-1-i]=0;
		x_p[num-1-i]=des_x+i*distance;
		y_p[num-1-i]=des_y;
		earth_fill03(x_p[i],y_p[i]);
		x_p[num-1-i]+=tracktor_l;
		y_p[num-1-i]-=tracktor_w;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]++;
				init_tracktor02_r(x_p[i],y_p[i]);
				if(x_p[i]>=((2*start_x+tra_start_l)/2-tracktor_w/2))
				{
					earth_cover02(x_p[i]+6,y_p[i]);
					earth_cover02(x_p[i]-2,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]++;
				init_tracktor02_b(x_p[i],y_p[i]);
				if(y_p[i]>=start_y-48)
				{
					earth_cover01(x_p[i],y_p[i]);
					earth_cover01(x_p[i],y_p[i]+5);
					type[i]=2;
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return003(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[i]=0;
		x_p[i]=des_x+i*distance;
		y_p[i]=des_y;
		earth_fill03(x_p[i],y_p[i]);
		x_p[i]-=tracktor_l;
		y_p[i]-=tracktor_w;
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]--;
				init_tracktor02_l(x_p[i],y_p[i]);
				if(x_p[i]<=((2*start_x+tra_start_l)/2-tracktor_w/2)+50)
				{
					earth_cover02(x_p[i]+2,y_p[i]);
					earth_cover02(x_p[i]-6,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					y_p[i]-=tracktor_l;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]--;
				init_tracktor02_f(x_p[i],y_p[i]);
				if(y_p[i]<=start_y+tra_start_l-6)
				{
					earth_cover01(x_p[i],y_p[i]-7);
					earth_cover01(x_p[i],y_p[i]+3);
					type[i]=2;
					continue;
				}
			}
		}
		if(count>=num)
		{
			break;
		}
		delay(20);
	}
}

void tracktor_return004(int start_x,int start_y,int des_x,int des_y,int distance,int num)
{
	int x_p[tracktor_num_max],y_p[tracktor_num_max],type[tracktor_num_max],i;
	if(distance<tracktor_l)
	{
		distance=tracktor_l;
	}
	for(i=0;i<num;i++)
	{
		type[num-1-i]=0;
		x_p[num-1-i]=des_x+i*distance+tracktor_l;
		y_p[num-1-i]=des_y-tracktor_w;
		earth_fill03(x_p[i],y_p[i]);
	}
	while(1)
	{
		int count=0;
		for(i=0;i<num;i++)
		{
			if(type[i]==2)
			{
				count++;
				continue;
			}
			if(type[i]==0)
			{
				earth_cover02(x_p[i]+2,y_p[i]);
				x_p[i]++;
				init_tracktor02_r(x_p[i],y_p[i]);
				if(x_p[i]>=((2*start_x+tra_start_l)/2-tracktor_w/2))
				{
					earth_cover02(x_p[i]+6,y_p[i]);
					earth_cover02(x_p[i]-2,y_p[i]);
					x_p[i]=(2*start_x+tra_start_l)/2-tracktor_w/2;
					y_p[i]-=tracktor_w;
					type[i]=1;
					continue;
				}
			}
			if(type[i]==1)
			{
				earth_cover01(x_p[i],y_p[i]);
				y_p[i]--;
				init_tracktor02_f(x_p[i],y_p[i]);
				if(y_p[i]<=start_y+tra_start_l-6)
				{
					earth_cover01(x_p[i],y_p[i]-7);
					earth_cover01(x_p[i],y_p[i]+3);
					type[i]=2;
					continue;
				}
			}
		}
		if (count >= num)
		{
			break;
		}
		delay(20);
	}
}