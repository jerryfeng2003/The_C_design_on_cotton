#include "TOTAL.H"
void past01_screen(void)
{
	int i;
	clrmous(MouseX, MouseY);
	cleardevice();
	setbkcolor(WHITE);
	puthz(240, 30, "参数列表", 32, 32, BLUE);
	quit();
	last();

	setfillstyle(1, LIGHTGRAY);
	bar(50, 100, 590, 420);
	settextstyle(0, 0, 2);
	settextjustify(1, 1);
}

int past01()
{
	int i, j, flag = 1; // 判断是否换页
	char page[3] = {'1', '/', '1'};
	int barcolor[11] = {1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14};
	page[3] = '\0';
	for (i = 0; i < 10; i++)
	{
		char a[1];
		a[1] = '\0';
		if ((h->lenpar / 4) == i)
		{
			itoa(i, a, 10);
			page[2] = a[0];
			if ((h->lenpar % 4) != 0)
			{
				itoa(i + 1, a, 10);
				page[2] = a[0];
			}
		}
	}
	past01_screen();

	for (;;)
	{
		int pagepar;
		char page2[1];
		page2[1] = '\0';
		page2[0] = page[0];
		pagepar = atoi(page2) - 1;
		newmouse(&MouseX, &MouseY, &press);
		// flag为1则换页
		if (flag == 1)
		{
			setfillstyle(1, LIGHTGRAY);
			bar(50, 100, 590, 420);
			outtextxy(320, 405, page);
			outtextxy(280, 405, "<<");
			outtextxy(360, 405, ">>");
			for (i = 0, j = pagepar * 4; i < (4 > ((h->lenpar) - (pagepar * 4)) ? ((h->lenpar) - (pagepar * 4)) : 4); i++, j++)
			{
				setfillstyle(1, barcolor[rand() % 12]);
				bar(90, 150 + 60 * i, 300, 150 + 40 + 60 * i);
				outtextxy(195, 170 + 60 * i, h->parameter[j].name);
			}
			for (i = 0; i < (4 > ((h->lenpar) - (pagepar * 4)) ? ((h->lenpar) - (pagepar * 4)) : 4); i++)
			{
				setfillstyle(1, 14);
				bar(460, 150 + 60 * i, 520, 150 + 40 + 60 * i);
				puthz(470, 160 + 60 * i, "查看", 16, 16, BLUE);
			}
			flag = 0;
		}

		// page last
		if (mouse_press(260, 395, 310, 415) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(260, 395, 310, 415) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(260, 395, 310, 415) == 1)
		{
			if (page[0] > '1')
			{
				page[0] -= 1;
				flag = 1;
			}
			else
			{
				setfillstyle(1, CYAN);
				bar(230, 30, 450, 80);
				puthz(240, 30, "第一页啦", 32, 32, BLUE);
				delay(300);
				setfillstyle(1, 0);
				bar(230, 30, 450, 80);
				puthz(240, 30, "参数列表", 32, 32, BLUE);
			}
		}
		// page next
		if (mouse_press(330, 395, 380, 415) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(330, 395, 380, 415) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(330, 395, 380, 415) == 1)
		{
			if (page[0] < page[2])
			{
				page[0] += 1;
				flag = 1;
			}
			else if (page[0] == page[2])
			{
				setfillstyle(1, CYAN);
				bar(230, 30, 450, 80);
				puthz(240, 30, "最后一页啦", 32, 32, BLUE);
				delay(300);
				setfillstyle(1, 0);
				bar(230, 30, 450, 80);
				puthz(240, 30, "参数列表", 32, 32, BLUE);
			}
		}

		// 四个查看按钮
		if ((mouse_press(460, 150 + 60 * 0, 520, 150 + 40 + 60 * 0) == 1) && ((h->lenpar - (pagepar * 4)) > 0))
		{
			int pagepar;
			char page2[1];
			page2[1] = '\0';
			page2[0] = page[0];
			pagepar = atoi(page2) - 1;

			return (pagepar)*4 + 1;
		}
		if ((mouse_press(460, 150 + 60 * 1, 520, 150 + 40 + 60 * 1) == 1) && ((h->lenpar - (pagepar * 4)) > 1))
		{
			int pagepar;
			char page2[1];
			page2[1] = '\0';
			page2[0] = page[0];
			pagepar = atoi(page2) - 1;

			return (pagepar)*4 + 2;
		}
		if ((mouse_press(460, 150 + 60 * 2, 520, 150 + 40 + 60 * 2) == 1) && ((h->lenpar - (pagepar * 4)) > 2))
		{
			int pagepar;
			char page2[1];
			page2[1] = '\0';
			page2[0] = page[0];
			pagepar = atoi(page2) - 1;

			return (pagepar)*4 + 3;
		}
		if ((mouse_press(460, 150 + 60 * 3, 520, 150 + 40 + 60 * 3) == 1) && ((h->lenpar - (pagepar * 4)) > 3))
		{
			int pagepar;
			char page2[1];
			page2[1] = '\0';
			page2[0] = page[0];
			pagepar = atoi(page2) - 1;

			return (pagepar)*4 + 4;
		}

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
}

void past02_screen(int par)
{
	int i;
	clrmous(MouseX, MouseY);
	cleardevice();
	setbkcolor(WHITE);
	settextstyle(0, 0, 3);
	settextjustify(1, 1);
	setcolor(BLUE);
	outtextxy(320, 45, h->parameter[par - 1].name);
	quit();

	setfillstyle(1, LIGHTGRAY);
	bar(50, 100, 590, 420);
	puthz(80, 120, "产区：", 32, 32, BLUE);
	if (h->parameter[par - 1].place == 'a')
	{
		puthz(180, 120, "新疆", 32, 32, BLUE);
	}
	else if (h->parameter[par - 1].place == 'b')
	{
		puthz(180, 120, "黄河", 32, 32, BLUE);
	}
	else if (h->parameter[par - 1].place == 'c')
	{
		puthz(180, 120, "长江", 32, 32, BLUE);
	}

	puthz(80, 120 + 60, "土地形状：", 32, 32, BLUE);
	if (h->parameter[par - 1].shape == 'a')
	{
		puthz(240, 120 + 60, "矩形", 32, 32, BLUE);
	}
	else if (h->parameter[par - 1].shape == 'b')
	{
		puthz(240, 120 + 60, "圆形", 32, 32, BLUE);
	}
	else if (h->parameter[par - 1].shape == 'c')
	{
		puthz(240, 120 + 60, "多边形", 32, 32, BLUE);
	}
	else if (h->parameter[par - 1].shape == 'd')
	{
		puthz(240, 120 + 60, "自定义图形", 32, 32, BLUE);
	}

	puthz(80, 120 + 60 * 2, "收割机类型：", 32, 32, BLUE);
	if (h->parameter[par - 1].type == 'a')
	{
		puthz(260, 120 + 60 * 2, "垂直式收割机", 32, 32, BLUE);
	}
	else if (h->parameter[par - 1].type == 'b')
	{
		puthz(260, 120 + 60 * 2, "水平式收割机", 32, 32, BLUE);
	}

	puthz(80, 120 + 60 * 3, "面积：", 32, 32, BLUE);
	settextjustify(0, 2);
	outtextxy(180, 130 + 60 * 3, h->parameter[par - 1].S);
	puthz(320, 120 + 60 * 3, "公顷", 32, 32, BLUE);

	setfillstyle(1, YELLOW);
	for (i = 0; i < 4; i++)
	{
		bar(500, 118 + 60 * i, 550, 118 + 40 + 60 * i);
		puthz(505, 125 + 60 * i, "修改", 16, 16, BLUE);
	}
	setfillstyle(1, CYAN);
	bar(80, 120 + 60 * 4, 150, 160 + 60 * 4);
	puthz(83, 125 + 60 * 4, "返回", 32, 32, BLUE);

	setfillstyle(1, RED);
	bar(400, 30, 480, 80);
	setcolor(BLACK);
	rectangle(399, 29, 481, 81);
	puthz(409, 38, "删除", 32, 32, BLUE);
}

int past02(int par)
{
	int i;
	past02_screen(par);

	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);

		// 删除按钮
		if (mouse_press(400, 30, 480, 80) == 1)
		{
			deletepar(par);
			return 1;
		}

		//四个修改按钮
		if (mouse_press(500, 118 + 60 * 0, 550, 118 + 40 + 60 * 0) == 1) // place
		{
			changeplace(par);
			return -1;
		}
		if (mouse_press(500, 118 + 60 * 1, 550, 118 + 40 + 60 * 1) == 1) // shape
		{
			changeshape(par);
			return -1;
		}
		if (mouse_press(500, 118 + 60 * 2, 550, 118 + 40 + 60 * 2) == 1) // type
		{
			changetype(par);
			return -1;
		}
		if (mouse_press(500, 118 + 60 * 3, 550, 118 + 40 + 60 * 3) == 1) // S
		{
			changeS(par);
			return -1;
		}

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
		if (mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 1)
		{
			return 1;
		}
		delay(15);
	}
}
void past()
{
	int act, i;

	for (;;)
	{
		act = past01();
		if (act == -1)
		{
			return;
		}
		there:
		if (past02(act)==-1)
		{
			goto there;
		}
	}
}
