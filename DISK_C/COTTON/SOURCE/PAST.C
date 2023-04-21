#include "COMMON.H"
#include "PAST.H"
#include "PARAMETE.H"
#include "LOGFUN.H"
#include "time.h"
void past01_screen(void)
{
	int i;
	clrmous(MouseX, MouseY);
	cleardevice();
	clrmous(MouseX, MouseY);
	setbkcolor(WHITE);
	puthz(240, 30, "参数列表", 32, 32, BLUE);
	quit();
	last();

	setfillstyle(1, LIGHTGRAY);
	bar(50, 80, 590, 420);
	settextstyle(0, 0, 2);
	settextjustify(1, 1);

	setfillstyle(1, YELLOW);
	bar(505, 77, 580, 125);
}

int past01()
{
	int i, j, flag = 1;									  // 判断是否换页
	INPUT searchname = {220, 80, 500, 125, "", 10, 0, 0}; // 搜索
	char page[3] = {'1', '/', '1'};
	int barcolor[11] = {1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14};
	page[3] = '\0';
	for (i = 0; i < PAR; i++)
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
	delay(100);
	clrmous(MouseX, MouseY);

	for (;;)
	{
		int pagepar;
		char page2[1];
		page2[1] = '\0';
		page2[0] = page[0];
		pagepar = atoi(page2) - 1;
		newmouse(&MouseX, &MouseY, &press);
		if (h->lenpar != 0)
		{
			input_s(223, 80, &searchname, 16, 0);
		}
		// flag为1则换页
		if (flag == 1)
		{
			if (h->lenpar == 0)
			{
				setfillstyle(1, LIGHTGRAY);
				bar(50, 80, 590, 420);
				settextjustify(1, 1);
				settextstyle(0, 0, 4);
				setcolor(RED);
				outtextxy(320, 250, "No Parameter");
				flag = 0;
			}
			else
			{
				setfillstyle(1, LIGHTGRAY);
				bar(50, 80, 590, 420);
				setfillstyle(1, YELLOW);
				bar(505, 77, 580, 125);
				puthz(130, 83, "搜索", 32, 32, BLUE);
				puthz(505, 83, "确认", 32, 32, RED);
				settextjustify(1, 1);
				setfillstyle(1, 0);
				bar(220, 80, 500, 125);
				rectangle(220, 80, 500, 125);
				settextstyle(0, 0, 2);
				outtextxy(320, 405, page);
				outtextxy(280, 405, "<<");
				outtextxy(360, 405, ">>");
				// settextstyle(0, 0, 3);
				setcolor(BLACK);
				srand((unsigned)time(NULL));
				for (i = 0, j = pagepar * 4; i < (4 > ((h->lenpar) - (pagepar * 4)) ? ((h->lenpar) - (pagepar * 4)) : 4); i++, j++)
				{
					int a, b;
					a = barcolor[rand() % 12];
					b = barcolor[rand() % 12];
					if (a == b)
					{
						a += 1;
					}
					setcolor(a);
					setfillstyle(1, b);
					bar(70, 150 + 60 * i, 320, 150 + 40 + 60 * i);
					if (strlen(h->parameter[j].name) >= 7)
					{
						settextstyle(0, 0, 2);
					}
					else
					{
						settextstyle(0, 0, 3);
					}
					outtextxy(195, 170 + 60 * i, h->parameter[j].name);
				}
				for (i = 0; i < (4 > ((h->lenpar) - (pagepar * 4)) ? ((h->lenpar) - (pagepar * 4)) : 4); i++)
				{
					setfillstyle(1, 14);
					bar(460, 150 + 60 * i, 520, 150 + 40 + 60 * i);
					puthz(474, 160 + 60 * i, "查看", 16, 16, BLUE);
				}
				flag = 0;
			}
		}
		// search  返回-2
		if (mouse_press(505, 77, 580, 125) == 1)
		{
			for (;;)
			{
				int act;
				act = search(searchname.string);
				if (act != -1)
				{
				past02there:
					if (past02(act) == -1)
					{
						goto past02there;
					}
				}
				else
				{
					break;
				}
			}
			return -2;
		}
		// page last
		if (mouse_press(260, 395, 310, 415) == 1)
		{
			if (page[0] > '1')
			{
				page[0] -= 1;
				flag = 1;
				delay(100);
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
				rectangle(220, 80, 500, 125);
			}
		}

		// page next
		if (mouse_press(330, 395, 380, 415) == 1)
		{
			if (page[0] < page[2])
			{
				page[0] += 1;
				flag = 1;
				delay(100);
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
				rectangle(220, 80, 500, 125);
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

		// enter
		if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(0, 450, 40, 480) == 0 || mouse_press(260, 395, 310, 415) == 0 || mouse_press(330, 395, 380, 415) == 0 || mouse_press(510, 80, 580, 125) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(0, 450, 40, 480) == 2 || mouse_press(260, 395, 310, 415) == 2 || mouse_press(330, 395, 380, 415) == 2 || mouse_press(510, 80, 580, 125) == 2)
		{
			MouseS = 1;
		}
		// quit
		if (mouse_press(0, 0, 40, 30) == 1)
		{
			exit(0);
		}
		// last
		if (mouse_press(0, 450, 40, 480) == 1)
		{
			return -1;
		}
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
		puthz(510, 130 + 60 * i, "修改", 16, 16, BLUE);
	}
	setfillstyle(1, CYAN);
	bar(80, 120 + 60 * 4, 150, 160 + 60 * 4);
	puthz(83, 125 + 60 * 4, "返回", 32, 32, BLUE);

	bar(400, 120 + 60 * 4, 550, 160 + 60 * 4);
	puthz(408, 125 + 60 * 4, "修改名字", 32, 32, BLUE);

	setfillstyle(1, RED);
	bar(400 + 40, 30, 480 + 40, 80);
	setcolor(BLACK);
	rectangle(399 + 40, 29, 481 + 40, 81);
	puthz(409 + 40, 38, "删除", 32, 32, BLUE);
}

int past02(int par)
{
	int i;
	past02_screen(par);

	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);

		// 删除按钮
		if (mouse_press(400 + 40, 30, 480 + 40, 80) == 1)
		{
			deletepar(par);
			return 1;
		}
		// 改名字
		if (mouse_press(400, 120 + 60 * 4, 550, 160 + 60 * 4) == 1)
		{
			changeparname(par);
			return -1;
		}
		// 四个修改按钮
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

		// quit,last
		if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 0)
		{
			MouseS = 0;
		}
		if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 2)
		{
			MouseS = 1;
		}
		if (mouse_press(0, 0, 40, 30) == 1)
		{
			exit(0);
		}

		// last
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
		if (act == -1) // 返回主界面
		{
			return;
		}
		else if (act == -2) // 搜索函数
		{
			continue;
		}
	there:
		if (past02(act) == -1)
		{
			goto there;
		}
	}
}
