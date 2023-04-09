#include "TOTAL.H"

void draw_help01()
{
	int i;
	cleardevice();
	setbkcolor(WHITE);
	puthz(240, 30, "帮助及说明", 32, 32, BLUE);
	quit();
	last();
	puthz(50, 90, "本程序作为棉花自动化采摘之模拟程序，可就我国三大棉花产区进行收割模拟，并计算其收成及模拟仓储过程。", 32, 32, BLUE);
	

	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);
		// quit
		if (mouse_press(0, 0, 40, 30) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(0, 0, 40, 30) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(0, 0, 40, 30) == 1)
		{
			exit(0);
		}

		// last
		if (mouse_press(0, 450, 40, 480) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(0, 450, 40, 480) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(0, 450, 40, 480) == 1)
		{
			return -1;
		}
		delay(15);
	}
	// closegraph();
}

