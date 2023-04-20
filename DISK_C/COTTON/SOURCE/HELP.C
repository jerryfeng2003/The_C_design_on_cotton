#include "TOTAL.H"

void draw_help()
{
	setfillstyle(1, 0);
	bar(0, 0, 640, 480);
	puthz(240, 30, "帮助及说明", 32, 32, BLUE);
	quit();
	last();
	puthz(30, 90, "本程序作为棉花自动化采摘之模拟程序，可就我国三大棉花产区进行收割模拟，并计算其收成及模拟仓储过程。", 32, 32, BLUE);

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
	int i, flag = 0, flag1 = 1;
	cleardevice();
	setbkcolor(WHITE);
	draw_help();

	setlinestyle(0,0,5);
	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(320 + 15 - 5, 300 - 10, 320 + 15 + 120 + 5, 380) == 2) // 编辑参数
		{
			if (flag1 == 1)
			{
				edit_help();
				flag = 0;
				flag1 = 0;
			}
		}
		else if (mouse_press(320 - 15 - 120 - 5, 300 - 10, 320 - 15 + 5, 380) == 2) // 开始模拟
		{
			if (flag1 == 1)
			{
				start_help();
				flag = 0;
				flag1 = 0;
			}
		}
		else if (mouse_press(320 + 15 + 150 - 5, 300 - 10, 320 + 15 + 120 + 150 + 5, 380) == 2) // 参数列表
		{
			if (flag1 == 1)
			{
				past_help();
				flag = 0;
				flag1 = 0;
			}
		}
		else if (mouse_press(320 - 15 - 120 - 150 - 5, 300 - 10, 320 - 15 - 150 + 5, 380) == 2) // 仓库管理
		{
			if (flag1 == 1)
			{
				ware_help();
				flag = 0;
				flag1 = 0;
			}
		}
		else
		{
			if (flag == 0)
			{
				clrmous(MouseX, MouseY);
				setfillstyle(1, 0);
				bar(15, 85, 640, 240);
				puthz(25, 90, "本程序作为棉花自动化采摘之模拟程序，可就我国三大棉花产区进行收割模拟，并计算其收成及模拟仓储过程。", 32, 32, BLUE);
				setfillstyle(1, MAGENTA);
				bar(320 + 15 - 5, 300 - 10, 320 + 15 + 120 + 5, 380);
				puthz(320 + 15, 305, "编辑参数", 32, 32, BLUE);
				bar(320 - 15 + 5, 300 - 10, 320 - 15 - 120 - 5, 380);
				puthz(320 - 15 - 120, 305, "开始模拟", 32, 32, BLUE);
				bar(320 + 15 + 150 - 5, 300 - 10, 320 + 15 + 120 + 150 + 5, 380);
				puthz(320 + 15 + 150, 305, "参数列表", 32, 32, BLUE);
				bar(320 - 15 - 150 + 5, 300 - 10, 320 - 15 - 120 - 150 - 5, 380);
				puthz(320 - 15 - 120 - 150, 305, "仓库管理", 32, 32, BLUE);
				flag = 1;
				flag1 = 1;
			}
		}

		if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(0, 450, 40, 480) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(0, 0, 40, 30) == 1)
		{
			exit(0);
		}
		// last
		else if (mouse_press(0, 450, 40, 480) == 1)
		{
			return;
		}
		if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(0, 450, 40, 480) == 0)
		{
			MouseS = 0;
		}
		// quit
		delay(15);
	}
}

void edit_help(void)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, 0);
	bar(15, 85, 640, 240);
	puthz(25, 90, "选择编辑参数按钮即可创建新的参数。参数的数据包括：棉花产区、收割机类型、土地的面积和形状等。", 32, 32, BLUE);
	setcolor(RED);
	rectangle(15, 85, 635, 240);
	setfillstyle(1, RED);
	bar(320 + 15 - 5, 300 - 10, 320 + 15 + 120 + 5, 380);
	puthz(320 + 15, 305, "编辑参数", 32, 32, BLUE);
}
void start_help(void)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, 0);
	bar(15, 85, 640, 240);
	puthz(25, 90, "点击开始模拟按钮即可选择已经创建的参数进行模拟采摘，将会播放采摘动画并显示采摘所需时间。", 32, 32, BLUE);
	setcolor(LIGHTRED);
	rectangle(15, 85, 635, 240);
	setfillstyle(1, LIGHTRED);
	bar(320 - 15 + 5, 300 - 10, 320 - 15 - 120 - 5, 380);
	puthz(320 - 15 - 120, 305, "开始模拟", 32, 32, BLUE);
}
void past_help(void)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, 0);
	bar(15, 85, 640, 240);
	puthz(25, 90, "点击参数列表按钮可以查看已经创建了的参数，并对他们进行修改和删除等操作。", 32, 32, BLUE);
	setcolor(CYAN);
	rectangle(15, 85, 635, 240);
	setfillstyle(1, CYAN);
	bar(320 + 15 + 150 - 5, 300 - 10, 320 + 15 + 120 + 150 + 5, 380);
	puthz(320 + 15 + 150, 305, "参数列表", 32, 32, BLUE);
}
void ware_help(void)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, 0);
	bar(15, 85, 640, 240);
	puthz(25, 90, "点击仓库管理按钮即可对仓库进行管理，可以进行出库和入库等操作", 32, 32, BLUE);
	setcolor(LIGHTGRAY);
	rectangle(15, 85, 635, 240);
	setfillstyle(1, LIGHTGRAY);
	bar(320 - 15 - 150 + 5, 300 - 10, 320 - 15 - 120 - 150 - 5, 380);
	puthz(320 - 15 - 120 - 150, 305, "仓库管理", 32, 32, BLUE);
}

void help(void)
{
	help01();
}