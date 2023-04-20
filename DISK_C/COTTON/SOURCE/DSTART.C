#include "DSTART.H"

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
		rectangle(i - 1, y + 42, i + 1, y + 37);
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
		rectangle(x - 42, i - 1, x - 37, i + 1);
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
		rectangle(i - 1, y + 42, i + 1, y + 37);
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
		rectangle(x - 42, i - 1, x - 37, i + 1);
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
	// if (y % 4 == 0)
	// {
	// 	int x_temp = rand() % 25;
	// 	line(x + x_temp, y + 41, x + x_temp, y + 41);
	// }
}

// earth filling after pick,back
void earth_fill02(int x, int y)
{
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y - 1, x + 25, y + 41);
	// if (y % 4 == 0)
	// {
	// 	int x_temp = rand() % 25;
	// 	line(x + x_temp, y - 1, x + x_temp, y - 1);
	// }
}

// earth filling after pick, turn direction
void earth_fill03(int x, int y)
{
	// int i;
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y, x + 25, y + 50);
	// for (i = 0; i < 10; i++)
	// {
	// 	int x_temp = rand() % 25, y_temp = rand() % 50;
	// 	line(x_temp + x, y_temp + y, x_temp + x, y_temp + y);
	// }
}

// earth filling  ,front and back
void earth_cover01(int x, int y)
{
	setfillstyle(1, BROWN);
	setcolor(WHITE);
	bar(x - 1, y, x + 26, y + 41);
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
	bar(x - 1, y - 1, x - 41, y + 26);
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


// initialize the picker 01
void init_picker_f(int x,int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x + 3, y - 3, x + 22, y + 38);
	rectangle(x + 3, y - 3, x + 22, y + 38);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y - 6, x + 19, y + 35);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x, y, x + 25, y - 3);
	rectangle(x, y, x + 25, y + 3);
	for (i = x; i <= 25 + x; i += 5)
	{
		bar(i - 1, y + 1, i + 1, y - 4);
		rectangle(i - 1, y + 1, i + 1, y - 4);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x + 7, y - 5, x + 18, y + 6);
	rectangle(x + 7, y - 5, x + 18, y + 6);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 9, x + 3, y + 15);
	bar(x + 22, y + 9, x + 24, y + 15);
	bar(x + 1, y + 26, x + 3, y + 32);
	bar(x + 22, y + 26, x + 24, y + 32);
}

void  init_picker_b(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x + 3, y, x + 22, y + 41);
	rectangle(x + 3, y, x + 22, y + 41);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y + 3, x + 19, y + 38);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x, y + 38, x + 25, y + 41);
	rectangle(x, y + 38, x + 25, y + 41);
	for (i = x; i <= 25 + x; i += 5)
	{
		bar(i - 1, y + 41, i + 1, y + 37);
		rectangle(i - 1, y + 42, i + 1, y + 37);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x + 7, y + 43, x + 18, y + 32);
	rectangle(x + 7, y + 43, x + 18, y + 32);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 29, x + 3, y + 23);
	bar(x + 22, y + 29, x + 24, y + 23);
	bar(x + 1, y + 12, x + 3, y + 6);
	bar(x + 22, y + 12, x + 24, y + 6);
}

void init_picker_r(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x - 3, y + 3, x - 38, y + 22);
	rectangle(x - 3, y + 3, x - 38, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 6, y + 6, x - 35, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x, y, x - 3, y + 25);
	rectangle(x, y, x - 3, y + 25);
	for (i = y; i <= 25 + y; i += 5)
	{
		bar(x + 1, i - 1, x - 4, i + 1);
		rectangle(x + 1, i - 1, x - 4, i + 1);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x - 5, y + 7, x + 6, y + 18);
	rectangle(x - 5, y + 7, x + 6, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 9, y + 1, x - 15, y + 3);
	bar(x - 9, y + 22, x - 15, y + 24);
	bar(x - 26, y + 1, x - 32, y + 3);
	bar(x - 26, y + 22, x - 32, y + 24);
}

void init_picker_l(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x, y + 3, x - 41, y + 22);
	rectangle(x, y + 3, x - 41, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 3, y + 6, x - 38, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x - 38, y, x - 41, y + 25);
	rectangle(x - 38, y, x - 41, y + 25);
	for (i = y; i <= 25 + y; i += 5)
	{
		bar(x - 41, i - 1, x - 37, i + 1);
		rectangle(x - 42, i - 1, x - 37, i + 1);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x - 43, y + 7, x - 32, y + 18);
	rectangle(x - 43, y + 7, x - 32, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 29, y + 1, x - 23, y + 3);
	bar(x - 29, y + 22, x - 23, y + 24);
	bar(x - 12, y + 1, x - 6, y + 3);
	bar(x - 12, y + 22, x - 6, y + 24);
}

// initialize the picker after pick
void init_picker01_f(int x,int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	//The cotton package
	setfillstyle(1,WHITE);
	bar(x,y-1,x+tracktor_w,y-1+co_pak_w);

	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x + 3, y - 3, x + 22, y + 38);
	rectangle(x + 3, y - 3, x + 22, y + 38);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y - 6, x + 19, y + 35);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x, y, x + 25, y - 3);
	rectangle(x, y, x + 25, y + 3);
	for (i = x; i <= 25 + x; i += 5)
	{
		bar(i - 1, y + 1, i + 1, y - 4);
		rectangle(i - 1, y + 1, i + 1, y - 4);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x + 7, y - 5, x + 18, y + 6);
	rectangle(x + 7, y - 5, x + 18, y + 6);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 9, x + 3, y + 15);
	bar(x + 22, y + 9, x + 24, y + 15);
	bar(x + 1, y + 26, x + 3, y + 32);
	bar(x + 22, y + 26, x + 24, y + 32);
}

void  init_picker01_b(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	//The cotton package
	setfillstyle(1,WHITE);
	bar(x,y+42,x+tracktor_w,y+42-co_pak_w);

	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x + 3, y, x + 22, y + 41);
	rectangle(x + 3, y, x + 22, y + 41);
	setlinestyle(0, 0, 3);
	rectangle(x + 6, y + 3, x + 19, y + 38);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x, y + 38, x + 25, y + 41);
	rectangle(x, y + 38, x + 25, y + 41);
	for (i = x; i <= 25 + x; i += 5)
	{
		bar(i - 1, y + 41, i + 1, y + 37);
		rectangle(i - 1, y + 42, i + 1, y + 37);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x + 7, y + 43, x + 18, y + 32);
	rectangle(x + 7, y + 43, x + 18, y + 32);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x + 1, y + 29, x + 3, y + 23);
	bar(x + 22, y + 29, x + 24, y + 23);
	bar(x + 1, y + 12, x + 3, y + 6);
	bar(x + 22, y + 12, x + 24, y + 6);
}

void init_picker01_r(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	//The cotton package
	setfillstyle(1,WHITE);
	bar(x+1,y,x+1-co_pak_w,y+tracktor_w);

	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x - 3, y + 3, x - 38, y + 22);
	rectangle(x - 3, y + 3, x - 38, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 6, y + 6, x - 35, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x, y, x - 3, y + 25);
	rectangle(x, y, x - 3, y + 25);
	for (i = y; i <= 25 + y; i += 5)
	{
		bar(x + 1, i - 1, x - 4, i + 1);
		rectangle(x + 1, i - 1, x - 4, i + 1);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x - 5, y + 7, x + 6, y + 18);
	rectangle(x - 5, y + 7, x + 6, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 9, y + 1, x - 15, y + 3);
	bar(x - 9, y + 22, x - 15, y + 24);
	bar(x - 26, y + 1, x - 32, y + 3);
	bar(x - 26, y + 22, x - 32, y + 24);
}

void init_picker01_l(int x, int y)
{
	int i;
	setlinestyle(0, 0, 1);
	setcolor(DARKGRAY);
	//The cotton package
	setfillstyle(1,WHITE);
	bar(x-42,y,x-42+co_pak_w,y+tracktor_w);

	// The main rectangle
	setfillstyle(1, LIGHTGRAY);
	bar(x, y + 3, x - 41, y + 22);
	rectangle(x, y + 3, x - 41, y + 22);
	setlinestyle(0, 0, 3);
	rectangle(x - 3, y + 6, x - 38, y + 19);

	// The samll bars
	setcolor(DARKGRAY);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CYAN);
	bar(x - 38, y, x - 41, y + 25);
	rectangle(x - 38, y, x - 41, y + 25);
	for (i = y; i <= 25 + y; i += 5)
	{
		bar(x - 41, i - 1, x - 37, i + 1);
		rectangle(x - 42, i - 1, x - 37, i + 1);
	}

	// The driver site
	setfillstyle(1, LIGHTBLUE);
	bar(x - 43, y + 7, x - 32, y + 18);
	rectangle(x - 43, y + 7, x - 32, y + 18);

	// The wheels
	setfillstyle(1, BLUE);
	bar(x - 29, y + 1, x - 23, y + 3);
	bar(x - 29, y + 22, x - 23, y + 24);
	bar(x - 12, y + 1, x - 6, y + 3);
	bar(x - 12, y + 22, x - 6, y + 24);
}
