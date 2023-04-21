#include "COMMON.H"
#include "WELCOME.H"
#include "mouse.h"
#include "PARAMETE.H"
#include "HOME.H"
#include "LOGFUN.H"
/*void main()
{
	int gdriver,gmode;
	gdriver=DETECT;
	initgraph(&gdriver,&gmode,"..\\BORLANDC\\BGI");
	draw_wel();
	closegraph();
}*/

// draw the buttons in welcome page
void draw_wel_buttons(void)
{
	clrmous(MouseX, MouseY);
	cleardevice();
	setbkcolor(WHITE);
	puthz(180, 30, "棉花采摘模拟系统", 32, 32, BLUE);
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);

	setfillstyle(1, 13);
	rectangle(450, 110, 550, 170);
	puthz(470, 130, "编辑参数", 16, 16, BLUE);
	rectangle(450, 210, 550, 270);
	puthz(470, 230, "开始模拟", 16, 16, BLUE);
	rectangle(450, 310, 550, 370);
	puthz(470, 330, "参数列表", 16, 16, BLUE);
	rectangle(450, 410, 550, 470);
	puthz(460, 430, "帮助及说明", 16, 16, BLUE);

	line(300, 130, 360, 100);
	line(360, 100, 420, 130);
	line(300, 130, 420, 130);
	rectangle(310, 130, 410, 200);
	puthz(330, 150, "仓库管理", 16, 16, BLUE);

	quit();
	// last();
}

// draw the tractor in welcome page
void draw_wel_tractors()
{
	// The wheels
	int i, d;
	setcolor(BROWN);
	setfillstyle(1, BLUE);
	bar(94, 185, 100, 215);
	bar(200, 185, 206, 215);
	bar(94, 265, 100, 295);
	bar(200, 265, 206, 295);
	setfillstyle(1, RED);

	// The rectangle of the machine
	bar(100, 150, 200, 310);
	rectangle(105, 155, 195, 305);
	setfillstyle(1, YELLOW);
	setlinestyle(0, 0, 1);

	// The small bar
	for (i = 0, d = 80; i < 8; i++)
	{
		bar(d - 2, 125, d + 2, 155);
		rectangle(d - 3, 125, d + 3, 155);
		d += 20;
	}
	setlinestyle(0, 0, 3);
	bar(80, 130, 220, 150);
	rectangle(80, 130, 220, 150);
	for (i = 0, d = 100; i < 6; i++)
	{
		line(d, 130, d, 150);
		d += 20;
	}
	setfillstyle(1, RED);
	bar(130, 120, 170, 160);
	rectangle(130, 120, 170, 160);
}

// draw the cotton field in welcome page
void draw_wel_cofield()
{
	// The cotton field
	int i, d;
	setcolor(BROWN);
	rectangle(50, 100, 300, 400);
	setlinestyle(0, 0, 3);
	for (d = 58; d <= 300; d += 20)
	{
		for (i = 100; i <= 400; i += 2)
		{
			int temp = rand() % 2;
			line(d + temp, i, d + temp, i);
		}
	}
	for (i = 0; i < 1000; i++)
	{
		int t1 = rand() % 250, t2 = rand() % 300;
		line(t1 + 50, t2 + 100, t1 + 50, t2 + 100);
	}
	setfillstyle(1, BROWN);
	bar(78, 130, 222, 400);
	setcolor(WHITE);
	for (i = 0; i < 100; i++)
	{
		int t1 = rand() % 144, t2 = rand() % 270;
		line(t1 + 78, t2 + 130, t1 + 78, t2 + 130);
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

// enter the edit page
void enter_next()
{
	static int flag = 0, flag1 = 1;
	int dian[8] = {300, 130, 360, 100, 420, 130, 300, 130};
	if (mouse_press(450, 110, 550, 170) == 0 || mouse_press(450, 210, 550, 270) == 0 || mouse_press(450, 310, 550, 370) == 0 || mouse_press(450, 410, 550, 470) == 0 ||
		mouse_press(310, 130, 410, 200) == 0 || mouse_press(0, 0, 40, 30) == 0 || mouse_press(0, 450, 40, 480) == 0)
	{
		MouseS = 0;
	}
	if (mouse_press(450, 110, 550, 170) == 2 || mouse_press(450, 210, 550, 270) == 2 || mouse_press(450, 310, 550, 370) == 2 || mouse_press(450, 410, 550, 470) == 2 ||
		mouse_press(310, 130, 410, 200) == 2 || mouse_press(0, 0, 40, 30) == 2 || mouse_press(0, 450, 40, 480) == 2)
	{
		MouseS = 1;
	}

	if (mouse_press(450, 110, 550, 170) == 2)
	{
		if (flag1 == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, CYAN);
			bar(450, 110, 550, 170);
			puthz(470, 130, "编辑参数", 16, 16, BLUE);

			flag = 0;
			flag1 = 0;
		}
	}
	else if (mouse_press(450, 210, 550, 270) == 2)
	{
		if (flag1 == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, CYAN);
			bar(450, 210, 550, 270);
			puthz(470, 230, "开始模拟", 16, 16, BLUE);
			flag = 0;
			flag1 = 0;
		}
	}
	else if (mouse_press(450, 310, 550, 370) == 2)
	{
		if (flag1 == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, CYAN);
			bar(450, 310, 550, 370);
			puthz(470, 330, "参数列表", 16, 16, BLUE);
			flag = 0;
			flag1 = 0;
		}
	}
	else if (mouse_press(450, 410, 550, 470) == 2)
	{
		if (flag1 == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, CYAN);
			bar(450, 410, 550, 470);
			puthz(460, 430, "帮助及说明", 16, 16, BLUE);
			flag = 0;
			flag1 = 0;
		}
	}
	else if (mouse_press(310, 130, 410, 200) == 2)
	{
		if (flag1 == 1)
		{
			clrmous(MouseX, MouseY);
			setfillstyle(1, CYAN);
			bar(310, 130, 410, 200);
			puthz(330, 150, "仓库管理", 16, 16, BLUE);
			fillpoly(4, dian);
			rectangle(310, 130, 410, 200);
			flag = 0;
			flag1 = 0;
		}
	}
	else if (flag == 0)
	{
		clrmous(MouseX, MouseY);
		setfillstyle(1, 0);
		bar(450, 110, 550, 170);
		bar(450, 210, 550, 270);
		bar(450, 310, 550, 370);
		bar(450, 410, 550, 470);

		rectangle(450, 110, 550, 170);
		puthz(470, 130, "编辑参数", 16, 16, BLUE);
		rectangle(450, 210, 550, 270);
		puthz(470, 230, "开始模拟", 16, 16, BLUE);
		rectangle(450, 310, 550, 370);
		puthz(470, 330, "参数列表", 16, 16, BLUE);
		rectangle(450, 410, 550, 470);
		puthz(460, 430, "帮助及说明", 16, 16, BLUE);
		setfillstyle(1, 0);
		bar(300, 100, 420, 200);
		puthz(330, 150, "仓库管理", 16, 16, BLUE);
		rectangle(310, 130, 410, 200);
		line(300, 130, 360, 100);
		line(360, 100, 420, 130);
		line(300, 130, 420, 130);

		flag = 1;
		flag1 = 1;
	}

	// Enter the edit page
	if (mouse_press(450, 110, 550, 170) == 1)
	{
		mode = 2;
	}

	// Enter the simulation page
	if (mouse_press(450, 210, 550, 270) == 1)
	{
		mode = 3;
	}

	// Enter the past arguments
	if (mouse_press(450, 310, 550, 370) == 1)
	{
		mode = 4;
		// draw_past01();
	}

	// Enter the help arguments
	if (mouse_press(450, 410, 550, 470) == 1)
	{
		mode = 5;
		// draw_help01();
	}

	// Enter the home page
	if (mouse_press(310, 130, 410, 200) == 1)
	{
		// draw_home01();
		mode = 1;
		/*else
		{
			draw_home00();
		}*/
	}

	// Exit the program
	if (mouse_press(0, 0, 40, 30) == 1)
	{
		wr_h();
		free(h);
		exit(0);
	}
}

/*Draw the whole welcome page*/
void draw_wel()
{
	draw_wel_buttons();
	draw_wel_cofield();
	draw_wel_tractors();
	quit();
}

void quit(void)
{
    setfillstyle(1,LIGHTBLUE);
    bar(0,0,40,30);
	puthz(3,10,"退出",16,16,WHITE);
}

void skip(void)
{
    setfillstyle(1,LIGHTBLUE);
    bar(585,450,625,480);
    puthz(625-40+3,480-30+10,"跳过",16,16,WHITE);
}

void next(void)
{
    setfillstyle(1,LIGHTBLUE);
    bar(585,450,625,480);
    puthz(625-40+3,480-30+10,"下页",16,16,WHITE);
}

void last(void)
{
    setfillstyle(1,LIGHTBLUE);
    bar(0,450,40,480);
    puthz(4,480-30+10,"返回",16,16,WHITE);
}

/*void text_input(char *str,int x1,int y1,int x2,int y2,int t_x,int t_y,int t_size)
{
	char temp,*p;
	int i, n=t_x,get,arr[10]={p_0,p_1,p_2,p_4,p_5,p_6,p_7,p_8,p_9};
	clrmous(MouseX,MouseY);
	p=str;
	setfillstyle(1,WHITE);
	setcolor(DARKGRAY);
	bar(x1,y1,x2,y2);
	while(bioskey(1))
	{
		get=bioskey(0);
	}
	while(*p!='\0')
	{
		if (get==p_Enter)
		{
			break;
		}
		for(i=0;i<10;i++)
		{
			if(arr[i]==get)
			{
				temp=i+'0';
			}
		}
		*p=temp;
		p++;
		outtextxy(n,t_y,&temp);
		get=bioskey(0);
		n+=t_size;
	}
}*/

void input_text(char *id, int x, int y, int charnum, int color, int flag)
{ // flag==1  显示

#define h 32
#define w 18
#define space 0
#define SX x + 5 // START X
#define SY y - 5

    //int k = 0;

    int i = 0;
    char t;
    clrmous(MouseX, MouseY);
    setfillstyle(SOLID_FILL, color);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setcolor(DARKGRAY);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    settextjustify(LEFT_TEXT, TOP_TEXT);

    while (bioskey(1))
    {
        t = bioskey(0);
    }

    while (*(id + i) != '\0')
        i++;
    line(SX+i*w,SY,SX+i*w,SY+h);
    while (1)
    {
		setfillstyle(1,WHITE);
        t = bioskey(0);
        if (i<charnum)
        {
            if (t!='\n'&& t!='\r'&&t !=' '&& t != 033)
            { // 033:Esc
                if (t != '\b')
                {
                    *(id + i) = t;
                    *(id + i + 1) = '\0';
                    bar(SX+i*w-1+space,SY - 1,SX +i*w+1+space,SY+h); //遮盖光标
                    if (flag)
                        outtextxy(SX + i * 18, SY, id + i); //输出刚输入的字符t
                    else
                    {
                        outtextxy(SX + i * 18, SY, "*");
                    }
                    i++;
                    line(SX + i * w + space, SY, SX +i*w +space,SY+h);
                }
                else if (t == '\b' && i > 0)
                {
                    bar(SX+i*w-1+space,SY-1,SX+i*w+1+space,SY+h); //遮盖光标
                    i--;                                             //减少一个字数
                    bar(SX+i*w,SY,SX + i * w + w, SY + h);            //遮盖文字
                    line(SX+i*w+space, SY, SX + i * w + space, SY + h); //绘制光标
                    *(id + i) = '\0';
                    *(id + i + 1) = '\0';
                }
            }
            else
            {
                bar(SX+i * w - 1 + space,SY - 1, SX + i * w + 1+ space, SY+ h); //遮盖光标
                break;
            }
        }
        else
        {
            if (t!='\n'&&t!='\r' && t != ' '&&t!=033)
            { // 033:Esc
                if (t == '\b' && i > 0)
                {
                    bar(SX+i*w-1+space,SY-1,SX + i * w + 1 + space, SY + h); //遮盖光标
                    i--;                                                                 //减少一个字数
                    bar(SX + i * w, SY, SX + i *w+w,SY+h);                         //遮盖文字
                    line(SX + i * w + space, SY, SX + i * w + space,SY + h);            //绘制光标
                    *(id + i) = '\0';
                    *(id + i + 1) = '\0';
                }
            }
            else
            {
                bar(SX+i*w -1+space,SY-1,SX+i*w+1+space,SY+h); //遮盖光标
                break;
            }
        }
    }
    //return i;
}