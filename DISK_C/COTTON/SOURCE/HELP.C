#include "TOTAL.H"

void draw_help()
{
	setfillstyle(1,0);
	bar(0,0,640,480);
	puthz(240, 30, "帮助及说明", 32, 32, BLUE);
	quit();
	last();
	puthz(50, 90, "本程序作为棉花自动化采摘之模拟程序，可就我国三大棉花产区进行收割模拟，并计算其收成及模拟仓储过程。", 32, 32, BLUE);

	setfillstyle(1, MAGENTA);
	bar(320 + 15 - 5, 300 - 10, 320 + 15 + 120 + 5, 380);
	puthz(320 + 15, 305, "编辑参数", 32, 32, BLUE);
	bar(320 - 15 + 5, 300 - 10, 320 - 15 - 120 - 5, 380);
	puthz(320 - 15 - 120, 305, "开始模拟", 32, 32, BLUE);
	bar(320 + 15 + 150 - 5, 300 - 10, 320 + 15 + 120 + 150 + 5, 380);
	puthz(320 + 15 + 150, 305, "参数列表", 32, 32, BLUE);
	bar(320 - 15 - 150 + 5, 300 - 10, 320 - 15 - 120 - 150 - 5, 380);
	puthz(320 - 15 - 120 - 150, 305, "仓库管理", 32, 32, BLUE);
}
void help01()
{
	int i;
	cleardevice();
	setbkcolor(WHITE);
	draw_help();

	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(320 + 15 - 5, 300 - 10, 320 + 15 + 120 + 5, 380) == 2) // 编辑参数
		{
			edit_help();
		}

		// quit
		if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(0, 450, 40, 480) == 0)
		{
			MouseS = 0;
		}
		else if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(0, 450, 40, 480) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(0, 0, 40, 30) == 1)
		{
			exit(0);
		}
		// last
		else if (mouse_press(0, 450, 40, 480) == 1)
		{
			return;
		}
		delay(15);
	}
	// closegraph();
}

void edit_help(void)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1,BLUE);
	bar(120,80,520,400);
	
}
void start_help(void);
void past_help(void);
void ware_help(void);

void help(void)
{
	help01();
}