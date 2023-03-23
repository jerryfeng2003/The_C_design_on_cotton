#include "TOTAL.H"
long int total[3];
int c_t=0;
char str[15];

//the page of n-w warehouse
void draw_home01()
{
    int i,temp=0,num_ware=0;
	U_ware here[10];
    //int num;
    cleardevice();
    setbkcolor(WHITE);
	draw_warehouse();
	draw_trunk();
	if(location==1)
	{
		puthz(180,30,"西北地区：室外仓库",32,32,BLUE);
	}
	else
	{
		puthz(120,30,"黄河、长江流域：室内仓库",32,32,BLUE);
		setfillstyle(1,DARKGRAY);
		bar(320,90,800,120);
		setfillstyle(1,LIGHTBLUE);
		bar(350,120,360,500);
	}
	if(strcmp(str,"\0"))
	{
		temp=atoi(str);
		if(temp>total[c_t])
		{
			temp=total[c_t];
		}
		total[c_t]-=temp;
		for(i=0;i<15;i++)
		{
			str[i]='\0';
		}
	}
	in_warehouse(total[c_t],c_t);
    mouseinit();
	quit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_home(c_t);
		delay(15);
	}
}

//add the press moudule
void press_home()
{
	if(mouse_press(0,0,40,30)==0||mouse_press(53,90,280,190)==0||mouse_press(26,130,46,150)==0\
	||mouse_press(287,130,307,150)==0||mouse_press(100,300,200,360)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||mouse_press(53,90,280,190)==2||mouse_press(26,130,46,150)==2\
	||mouse_press(287,130,307,150)==2||mouse_press(100,300,200,360)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	if(mouse_press(100,300,200,360)==1)
	{
		warehouse_list();
	}
	if(mouse_press(287,130,307,150)==1)
	{
		c_t--;
		if(c_t<0)
		{
			c_t=2;
		}
		draw_home01();
	}
	if(mouse_press(26,130,46,150)==1)
	{
		c_t++;
		if(c_t>2)
		{
			c_t=0;
		}
		draw_home01();
	}
	else if(mouse_press(53,90,280,190)==1)
	{
		detailed_warehouse(total[c_t]);
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

//draw the board which show the cotton in warehouse
void in_warehouse(int count,int cotton_type)
{
	char str1[8];
	int arr1[6]={32-5,140,47-5,132,47-5,148},arr2[6]={301+5,140,286+5,132,286+5,148};
	setfillstyle(1,LIGHTGRAY);
	setlinestyle(0,0,1);
	bar(53,90,280,190);
	puthz(60,110,"库存量：",16,16,WHITE);
	puthz(200,110,"吨",16,16,WHITE);
	puthz(60,145,"棉花种类：",16,16,WHITE);
	setfillstyle(1,BROWN);
	bar(100,300,200,360);
	puthz(115,320,"仓库列表",16,16,YELLOW);
	switch (cotton_type)
	{
	case 0:
		puthz(138,145,"长绒棉",16,16,RED);
		break;
	case 1:
		puthz(138,145,"细绒棉",16,16,RED);
		break;
	case 2:
		puthz(138,145,"粗绒棉",16,16,RED);
		break;	
	default:
		break;
	}
	setcolor(RED);
	itoa(count,str1,10);
	settextstyle(1,0,2);
	outtextxy(130,105,str1);
	setfillstyle(1,LIGHTBLUE);
	setcolor(BLUE);
	fillellipse(41-5,140,10,10);
	fillellipse(292+5,140,10,10);
	setfillstyle(1,LIGHTGRAY);
	fillpoly(3,arr1);
	fillpoly(3,arr2);

}

void warehouse_list()
{
	//int i=0;
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(1,LIGHTGRAY);
	puthz(220,30,"当前仓库列表",32,32,BLUE);
	bar(100,100,540,400);

	quit();
	last();

	mouseinit();
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_warelist();
		delay(15);
	}
}

void press_warelist()
{
	if(mouse_press(0,0,40,30)==0||mouse_press(0,450,40,480)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||mouse_press(0,450,40,480)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,450,40,480)==1)
	{
		draw_home01();
	}
	else if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
}

//detail message of warehouse
void detailed_warehouse(int count)
{
	char str1[8];
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(1,LIGHTGRAY);
	puthz(220,30,"当前仓储信息",32,32,BLUE);
	bar(100,100,540,300);
	puthz(120,130,"库存量：",32,32,WHITE);
	puthz(400,130,"吨",32,32,WHITE);
	puthz(120,220,"棉花种类：",32,32,WHITE);
	puthz(280,220,"长绒棉",32,32,RED);
	itoa(count,str1,10);
	setcolor(RED);
	settextstyle(1,0,4);
	outtextxy(250,125,str1);
	last();

	setfillstyle(1,LIGHTBLUE);
	bar(140,320,240,380);
	setfillstyle(1,RED);
	bar(380,320,480,380);
	puthz(155,333,"采摘",32,32,WHITE);
	puthz(395,333,"出库",32,32,WHITE);

	mouseinit();
	quit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_detwarehouse(count);
		delay(15);
	}
}


void press_detwarehouse(int count)
{
	if(mouse_press(0,0,40,30)==0||mouse_press(140,320,240,380)==0||mouse_press(380,320,480,380)==0\
	||mouse_press(0,450,40,480)==0)
	{
		MouseS=0;
	}
	if(mouse_press(0,0,40,30)==2||mouse_press(140,320,240,380)==2||mouse_press(380,320,480,380)==2\
	||mouse_press(0,450,40,480)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	if(mouse_press(0,450,40,480)==1)
	{
		draw_home01();
	}
	if(mouse_press(140,320,240,380)==1)
	{
		draw_simu01(x_max,y_max,5);
	}
	if(mouse_press(380,320,480,380)==1)
	{
		out_warehouse(count);
	}
}

//page of the cotton out
void out_warehouse(int count)
{
	//int out;
	//int kick=0;
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(1,LIGHTGRAY);
	puthz(220,30,"请输入出库量",32,32,BLUE);

	setfillstyle(1,LIGHTGRAY);
	bar(100,100,540,300);
	setfillstyle(1,WHITE);
	bar(130,150,510,250);
	puthz(460,190,"吨",32,32,BLUE);
	setfillstyle(1,RED);
	bar(270,320,370,380);
	puthz(285,333,"完成",32,32,WHITE);
	last();

	mouseinit();
	quit();
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		press_outware(count,str);
		delay(15);
	}
	//return out;
}

void press_outware(int count,char*str)
{
	if(mouse_press(0,0,40,30)==0||mouse_press(130,150,510,250)==0||mouse_press(270,320,370,380)==0\
	||mouse_press(0,450,40,480)==0)
	{
		MouseS=0;
	}	if(mouse_press(0,0,40,30)==2||mouse_press(130,150,510,250)==2||mouse_press(270,320,370,380)==2\
	||mouse_press(0,450,40,480)==2)
	{
		MouseS=1;
	}
	if(mouse_press(0,0,40,30)==1)
	{
		draw_wel();
	}
	if(mouse_press(0,450,40,480)==1)
	{
		detailed_warehouse(count);
	}
	if(mouse_press(0,0,40,30)==1)
	{
		detailed_warehouse(count);
	}
	if(mouse_press(130,150,510,250)==1)
	{
		input_text(str,140,190,15,DARKGRAY,1);
		return;
	}
	if(mouse_press(270,320,370,380)==1)
	{
		out_finish();
	}
	//return out;
}

void out_finish()
{
	setfillstyle(1,WHITE);
	bar(200,160,430,240);
	setcolor(BLUE);
	setlinestyle(0,0,3);
	rectangle(200,160,430,240);
	puthz(220,180,"出库完成",48,48,RED);
	delay(1000);
	draw_home01();
}

//draw the trunk int the page
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

//draw the picture of warehouse
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

//draw the cotton in warehouse
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