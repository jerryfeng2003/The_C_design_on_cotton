#include "EDIT.H"
#include "COMMON.H"
#include "IMAGE.h"
#include "PARAMETE.H"
#include "LOGFUN.H"
#include "START.H"

void edit01_screen()
{
	clrmous(MouseX, MouseY);
	cleardevice();
	setbkcolor(WHITE);
	bmp_convert(".\\photo\\map.bmp", ".\\photo\\map.dbm");
	show_dbm(5, 100, ".\\photo\\map.dbm");
	puthz(240, 30, "请选择地区", 32, 32, BLUE);
	quit();
	last();
	setcolor(12); // 淡红色

	// 参数名字
	puthz(50, 90, "参数名字：", 32, 32, BLUE);

	// 按钮
	puthz(80 - 30, 150, "新疆地区", 32, 32, BLUE);
	puthz(400 - 40, 150 + 30, "黄河地区", 32, 32, BLUE);
	puthz(250 - 20, 300 + 20, "长江地区", 32, 32, BLUE);
	setcolor(CYAN);
	bar(120 - 30, 200, 150 - 30, 230);
	bar(440 - 40, 200 + 30, 470 - 40, 230 + 30);
	bar(290 - 20, 350 + 20, 320 - 20, 380 + 20);
	rectangle(230, 80, 520, 130);
}

int edit01(struct Parameter *abc)
{
	INPUT name = {230, 80, 520, 130, "", 10, 0, 0};
	edit01_screen();
	setfillstyle(1, MAGENTA); // 洋红色

	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);
		input_s(233, 80, &name, 16, 0);
		if (mouse_press(100 - 30, 180, 170 - 30, 250) == 2) // 新疆
		{
			setfillstyle(1, MAGENTA);
			bar(120 - 30, 200, 150 - 30, 230);
		}
		else
		{
			setfillstyle(1, CYAN);
			bar(120 - 30, 200, 150 - 30, 230);
		}
		if (mouse_press(100 - 30, 180, 170 - 30, 250) == 1)
		{
			if (judgename(name.string) == 1)
			{
				strcpy(abc->name, name.string);
				abc->place = 'a';
				return 0;
			}
		}

		if (mouse_press(420 - 40, 180 + 30, 490 - 40, 250 + 30) == 2) // 黄河
		{
			setfillstyle(1, MAGENTA);
			bar(440 - 40, 200 + 30, 470 - 40, 230 + 30);
		}
		else
		{
			setfillstyle(1, CYAN);
			bar(440 - 40, 200 + 30, 470 - 40, 230 + 30);
		}
		if (mouse_press(420 - 40, 180 + 30, 490 - 40, 250 + 30) == 1)
		{
			if (judgename(name.string) == 1)
			{
				strcpy(abc->name, name.string);
				abc->place = 'b';
				return 0;
			}
		}

		if (mouse_press(270 - 20, 330 + 20, 340 - 20, 400 + 20) == 2) // 长江
		{
			setfillstyle(1, MAGENTA);
			bar(290 - 20, 350 + 20, 320 - 20, 380 + 20);
		}
		else
		{
			setfillstyle(1, CYAN);
			bar(290 - 20, 350 + 20, 320 - 20, 380 + 20);
		}
		if (mouse_press(270 - 20, 330 + 20, 340 - 20, 400 + 20) == 1)
		{
			if (judgename(name.string) == 1)
			{
				strcpy(abc->name, name.string);
				abc->place = 'c';
				return 0;
			}
		}

		// quit
		if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(0, 450, 40, 480) == 0)
		{
			MouseS = 0;
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
		if (mouse_press(0, 450, 40, 480) == 1)
		{
			return 1;
		}
		delay(15);
	}
	// getchar();
	// closegraph();
}

void edit02_screen(struct Parameter *abc)
{
	clrmous(MouseX, MouseY);
	cleardevice();
	setbkcolor(WHITE);

	quit();
	last();

	puthz(70, 40, "请输入土地面积：", 32, 32, BLUE);
	puthz(490, 40, "公顷", 32, 32, BLUE);
	puthz(70, 100, "本地推荐种植的棉花种类为：", 32, 32, BLUE);

	if (abc->place == 'a')
	{
		puthz(480, 100, "粗绒棉", 32, 32, BLUE);
	}
	else if (abc->place == 'b')
	{
		puthz(480, 100, "长绒棉", 32, 32, BLUE);
	}
	else
	{
		puthz(480, 100, "细绒棉", 32, 32, BLUE);
	}

	// 土地形状
	setfillstyle(1, LIGHTGRAY);
	bar(0, 150, 160, 200);
	bar(0, 230, 160, 280);
	bar(0, 310, 160, 360);
	bar(0, 380, 160, 430);
	puthz(20, 160, "矩形", 32, 32, BLUE);
	puthz(20, 235, "圆形", 32, 32, BLUE);
	puthz(10, 315, "多边形", 32, 32, BLUE);
	puthz(0, 390, "自定义形状", 32, 32, BLUE);

	setfillstyle(1, WHITE);
	bar(200, 150, 600, 460);
	setcolor(RED);
	rectangle(200, 150, 600, 460);
	rectangle(330, 30, 490, 90);
}

int edit02(struct Parameter *abc)
{
	// int flag = 0; // 返回键判断
	int flagcan = 0, flagcan1 = 1;
	INPUT S = {330, 30, 490, 90, "", 6, 0, 0};

	edit02_screen(abc);

	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);
		delay(15);
		input_s(333, 30, &S, 16, 0);

		// 土地形状按钮，停留在上面
		if (mouse_press(0, 150, 160, 200) == 2) // 矩形
		{
			if (flagcan1 == 1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 1;
				setfillstyle(1, MAGENTA);
				bar(0, 150, 160, 200);
				puthz(20, 160, "矩形", 32, 32, BLUE);
				setfillstyle(10, BROWN);
				rectangle(240, 190, 560, 420);
				bar(241, 191, 559, 419);

				flagcan = 0;
				flagcan1 = 0;
			}
		}
		else if (mouse_press(0, 230, 160, 280) == 2) // 圆形
		{
			if (flagcan1 == 1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 1;
				setfillstyle(1, MAGENTA);
				bar(0, 230, 160, 280);
				puthz(20, 235, "圆形", 32, 32, BLUE);
				setfillstyle(10, LIGHTGRAY);
				circle(400, 305, 121);
				pieslice(400, 305, 0, 360, 120);
				line(280, 305, 520, 305);
				line(400, 185, 400, 425);

				flagcan = 0;
				flagcan1 = 0;
			}
		}
		else if (mouse_press(0, 310, 160, 360) == 2) // 多边形
		{
			if (flagcan1 == 1)
			{
				int dindian[8] = {220, 270, 350, 270, 285, 170, 220, 270}, dindian2[10] = {560, 420, 560, 330, 400, 330, 400, 400, 560, 420}; // 200,150,600,460
				clrmous(MouseX, MouseY);
				MouseS = 1;
				setfillstyle(1, MAGENTA);
				bar(0, 310, 160, 360);
				puthz(10, 315, "多边形", 32, 32, BLUE);
				setfillstyle(10, LIGHTGRAY);
				fillpoly(4, dindian);
				fillpoly(5, dindian2);
				setlinestyle(0, 0, 3);
				line(220, 440, 580, 170);
				flagcan = 0;
				flagcan1 = 0;
			}
		}
		else if (mouse_press(0, 380, 160, 430) == 2) // 自定义图形
		{
			if (flagcan1 == 1)
			{
				clrmous(MouseX, MouseY);
				MouseS = 1;
				setlinestyle(0, 0, 15);
				setfillstyle(1, MAGENTA);
				bar(0, 380, 160, 430);
				puthz(0, 390, "自定义图形", 32, 32, BLUE);
				setfillstyle(1, LIGHTGRAY);
				arc(400, 230, -90, 180, 60);
				line(400, 290, 400, 370);
				setfillstyle(1, BLACK);
				circle(400, 390, 10);

				flagcan = 0;
				flagcan1 = 0;
			}
		}
		else
		{
			if (flagcan == 0)
			{
				clrmous(MouseX, MouseY);
				MouseS = 0;
				setfillstyle(1, LIGHTGRAY);
				bar(0, 150, 160, 200);
				puthz(20, 160, "矩形", 32, 32, BLUE);
				bar(0, 380, 160, 430);
				puthz(0, 390, "自定义图形", 32, 32, BLUE);
				bar(0, 310, 160, 360);
				puthz(10, 315, "多边形", 32, 32, BLUE);
				bar(0, 230, 160, 280);
				puthz(20, 235, "圆形", 32, 32, BLUE);
				setfillstyle(1, WHITE);
				bar(200, 150, 600, 460);
				setcolor(RED);
				rectangle(200, 150, 600, 460);
				flagcan = 1;
				flagcan1 = 1;
			}
		}

		if (mouse_press(0, 150, 160, 200) == 1) // 矩形
		{
			if (judgeS(S.string) == 1)
			{
				strcpy(abc->S, S.string);
				abc->shape = 'a';
				return 0;
			}
		}
		else if (mouse_press(0, 230, 160, 280) == 1) // 圆形
		{
			if (judgeS(S.string) == 1)
			{
				strcpy(abc->S, S.string);
				abc->shape = 'b';
				return 0;
			}
		}
		else if (mouse_press(0, 300, 160, 350) == 1) // 多边形
		{
			if (judgeS(S.string) == 1)
			{
				strcpy(abc->S, S.string);
				abc->shape = 'c';
				select02(abc);
				return 0;
			}
		}
		else if (mouse_press(0, 370, 160, 420) == 1) // 自定义图形
		{
			if (judgeS(S.string) == 1)
			{
				strcpy(abc->S, S.string);
				abc->shape = 'd';
				select03(abc);
				return 0;
			}
		}

		// quit
		if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(0, 450, 40, 480) == 0)
		{
			MouseS = 0;
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
		if (mouse_press(0, 450, 40, 480) == 1)
		{
			return 1;
		}
	}
}

void edit03_screen()
{
	int dindian0[10] = {100, 150, 100, 200, 250, 200, 250, 150, 100, 150};
	clrmous(MouseX, MouseY);
	cleardevice();
	setbkcolor(WHITE);

	quit();
	last();

	puthz(160, 30, "请选择收割机类型", 32, 32, BLUE);
	puthz(140, 70, "（自动计算所需数量）", 32, 32, BLUE);

	setfillstyle(1, LIGHTGRAY);
	bar(70, 120, 570, 420);

	setfillstyle(1, RED);
	bar(100, 150, 250, 350);
	setcolor(0); // 白色
	setlinestyle(0, 0, 3);
	drawpoly(5, dindian0);
	rectangle(100, 240, 250, 275);
	rectangle(100, 275, 250, 300);
	setlinestyle(0, 0, 5);
	rectangle(100, 300, 250, 325);
	rectangle(100, 325, 250, 340);
	setlinestyle(0, 0, 2);
	rectangle(150, 340, 200, 350);
	bar(150, 350, 200, 380);
	setfillstyle(1, YELLOW);
	bar(100, 340, 150, 350);
	bar(200, 340, 250, 350);
	setfillstyle(1, BLUE);
	bar(90, 170, 100, 220);
	bar(90 + 160, 170, 100 + 160, 220);
	bar(90, 250, 100, 300);
	bar(90 + 160, 250, 100 + 160, 300);

	setfillstyle(1, GREEN);
	bar(100 + 290, 150, 250 + 290, 350);
	setcolor(0); // 白色
	setlinestyle(0, 0, 3);
	rectangle(100 + 290, 150, 250 + 290, 200);
	rectangle(100 + 290, 240, 250 + 290, 275);
	rectangle(100 + 290, 275, 250 + 290, 300);
	setlinestyle(0, 0, 5);
	rectangle(100 + 290, 300, 250 + 290, 325);
	rectangle(100 + 290, 325, 250 + 290, 340);
	setlinestyle(0, 0, 2);
	rectangle(150 + 290, 340, 200 + 290, 350);
	setfillstyle(1, YELLOW);
	bar(100 + 290 - 25, 340, 150 + 290, 350);
	bar(200 + 290, 340, 250 + 290 + 25, 350);
	setfillstyle(1, BLUE);
	bar(90 + 290, 170, 100 + 290, 220);
	bar(90 + 160 + 290, 170, 100 + 160 + 290, 220);
	bar(90 + 290, 250, 100 + 290, 300);
	bar(90 + 160 + 290, 250, 100 + 160 + 290, 300);

	puthz(110, 130, "垂直式收割机", 16, 16, BLUE);
	puthz(400, 130, "水平式收割机", 16, 16, BLUE);
}

int edit03(struct Parameter *abc)
{
	int flag = 0;

	edit03_screen();

	for (;;)
	{
		newmouse(&MouseX, &MouseY, &press);
		delay(15);

		// 收割机按钮 70, 120, 570, 420
		if (mouse_press(70, 120, 300, 420) == 2)
		{
			if (flag == 0)
			{
				MouseS = 1;
				setcolor(RED);
				setlinestyle(0, 0, 5);
				rectangle(70, 120, 300, 420);

				flag = 1;
			}
		}
		else if (mouse_press(70, 120, 300, 420) == 1)
		{
			abc->type = 'a';
			return 0;
		}
		else if (mouse_press(340, 120, 570, 420) == 2)
		{
			if (flag == 0)
			{
				MouseS = 1;
				setcolor(RED);
				setlinestyle(0, 0, 5);
				rectangle(340, 120, 570, 420);

				flag = 1;
			}
		}
		else if (mouse_press(340, 120, 570, 420) == 1)
		{
			abc->type = 'b';
			return 0;
		}
		else
		{
			if (flag == 1)
			{
				MouseS = 0;
				setlinestyle(0, 0, 5);
				setcolor(LIGHTGRAY);
				rectangle(340, 120, 570, 420);
				rectangle(70, 120, 300, 420);
				flag = 0;
			}
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
			return 1;
		}
	}
}
// 产区，面积，形状（坐标），收割机类型，名字
// 产区place：a--新疆；b--黄河；c--长江；分别对应：粗绒棉，长绒棉，细绒棉
// 面积S：123（数字）
// 形状shape：a--矩形；b--圆形；c--多边形；d自定义形状
// 坐标xyz：c/d才用：x1,y1,x2,y2,x3,y3....
// 收割机类型type：a垂直/b水平
// 名字name：abcdefg

// 土地形状按钮，按下去
void edit()
{
	parameter *abc = (parameter *)malloc(sizeof(parameter));

edit01:
	if (edit01(abc) == 1)
	{
		return;
	}

edit02:
	if (edit02(abc) == 1)
	{
		goto edit01;
	}

	if (edit03(abc) == 1)
	{
		goto edit02;
	}
	wr_parameter(abc);
	free(abc);
	// h->parameter[h->lenpar]=*abc;
}
