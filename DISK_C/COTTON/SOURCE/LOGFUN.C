#include "TOTAL.H"

// 键盘输入
void input_s(int x, int y, INPUT *word, int size, int mode)
{
	if (press == 1)
	{
		if (mouse_press(word->x1, word->y1, word->x2, word->y2) == 1)
		{
			word->flag = 1;

			clrmous(MouseX, MouseY);
			setcolor(RED);
			setlinestyle(0, 0, 1);
			rectangle(word->x1, word->y1, word->x2, word->y2);
			setcolor(DARKGRAY);
			// line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
		}
		else
		{
			word->flag = 0;

			clrmous(MouseX, MouseY);
			setcolor(LIGHTGREEN);
			setlinestyle(0, 0, 1);
			rectangle(word->x1, word->y1, word->x2, word->y2);
			// line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
		}
	}

	// flag为1时表示可以接收键盘输入
	if (word->flag == 1)
	{
		char t;

		if (kbhit())
		{
			t = getch();

			if (t == '\b')
			{
				if (word->cursor > 0)
				{
					(word->string)[word->cursor - 1] = '\0';
					(word->cursor)--;
				}
			}
			else if (t >= '!' && t <= '~')
			{
				if (word->cursor < word->length)
				{
					(word->string)[word->cursor] = t;
					(word->string)[word->cursor + 1] = '\0';
					(word->cursor)++;
				}
			}

			setcolor(DARKGRAY);
			setlinestyle(0, 0, 1);
			setfillstyle(SOLID_FILL, WHITE);
			settextjustify(LEFT_TEXT, TOP_TEXT);
			settextstyle(SMALL_FONT, HORIZ_DIR, size);
			bar(word->x1 + 2, word->y1 + 2, word->x2 - 2, word->y2 - 2);
			if (mode == 0)
			{
				setcolor(DARKGRAY);
				outtextxy(x, y, word->string);
				// line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
			}
			else
			{
				int i;
				for (i = 0; i < word->cursor; i++)
				{
					outtextxy(x + i * (2 * size - 2), y, "*");
				}
				// line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
			}
		}
	}
}

// 录入注册账号到文件
void wr_user(char username1[], char password1[], char phonenumber1[])
{
	FILE *fp;
	int i;
	user *u = (user *)malloc(sizeof(user));
	u->lenpar = 0;
	for (i = 0; i < 3; i++)
	{
		u->here[i].cotton_type = 0;
	}
	if ((fp = fopen("User.dat", "rb+")) == NULL)
	{
		puthz(120, 300, "打开错误", 32, 32, BLUE);
		delay(3000);
		return;
	}
	for (i = 0; i < 10; i++)
	{
		u->username[i] = username1[i];
		u->password[i] = password1[i];
	}
	for (i = 0; i < 12; i++)
	{
		u->phonenumber[i] = phonenumber1[i];
	}
	fseek(fp, 0, SEEK_END);
	fwrite(u, sizeof(user), 1, fp);
	free(u);
	u = NULL;
	if (fclose(fp) != 0) // 关闭文件
	{
		puthz(120, 300, "关闭错误", 32, 32, BLUE);
		delay(3000);
		return;
	}
}

// 判断注册的账号是否已经存在
// return flag为1则存在，0则不存在
int username_same(char username0[])
{
	FILE *fp;
	user *u = (user *)malloc(sizeof(user));
	int i, j, all, flag = 0;
	if ((fp = fopen("User.dat", "rb+")) == NULL)
	{
		puthz(120, 300, "打开错误", 32, 32, BLUE);
		delay(3000);
		return;
	}
	fseek(fp, 0, SEEK_END);
	all = ftell(fp) / sizeof(user);
	for (i = 0; i < all; i++)
	{
		flag = 0;
		fseek(fp, i * sizeof(user), SEEK_SET);
		fread(u, sizeof(user), 1, fp);

		for (j = 0; j < 10; j++) // 查找账号位置
		{
			if (u->username[j] != username0[j])
			{
				break;
			}
			if (username0[j] == '\0')
			{
				j = 10;
				break;
			}
		}
		if (j == 10)
		{
			void *buffer;
			unsigned s;
			setfillstyle(1, CYAN);
			s = imagesize(220, 100, 520, 150);
			buffer = malloc(s);
			getimage(220, 100, 520, 150, buffer);
			bar(220, 100, 520, 150);
			puthz(220, 100, "注册账号已存在", 32, 32, BLUE);
			delay(2000);
			putimage(220, 100, buffer, COPY_PUT);
			flag = 1;
			free(buffer);
		}
	}
	if (flag == 0)
	{
		void *buffer;
		unsigned s;
		setfillstyle(1, CYAN);
		s = imagesize(220, 100, 420, 150);
		buffer = malloc(s);
		getimage(220, 100, 420, 150, buffer);
		bar(220, 100, 420, 150);
		puthz(220, 100, "注册账号成功", 32, 32, BLUE);
		delay(2000);
		putimage(220, 100, buffer, COPY_PUT);
		free(buffer);
	}
	fclose(fp);
	free(u);
	u = NULL;
	return flag;
}

// 登录，判断账号是否存在and密码是否正确
int logg(char username0[], char password0[])
{
	FILE *fp;
	user *u = (user *)malloc(sizeof(user));
	int i, j, k, l, o, flag = 0, all;

	if ((fp = fopen("User.dat", "rb+")) == NULL)
	{
		puthz(120, 300, "打开错误", 32, 32, BLUE);
		delay(3000);
		return;
	}
	fseek(fp, 0, SEEK_END);
	all = ftell(fp) / sizeof(user);
	for (i = 0; i < all; i++)
	{

		fseek(fp, i * sizeof(user), SEEK_SET);
		fread(u, sizeof(user), 1, fp);
		// outtextxy(100+200*i,180,u->username);
		// outtextxy(100+200*i,280,u->password);
		// outtextxy(100+200*i,380,"666");
		//delay(2000);

		for (j = 0; j < 10; j++) // 查找账号位置
		{
			if (u->username[j] != username0[j])
			{
				break;
			}
			if (username0[j] == '\0')
			{
				j = 10;
				break;
			}
		}
		if (j == 10) // 如果找到了账号就开始比对密码
		{
			for (k = 0; k < 10; k++)
			{
				if (u->password[k] != password0[k])
				{
					break;
				}
				if (password0[k] == '\0')
				{
					k = 10;
					break;
				}
			}
			if (k == 10)
			{
				strcpy(h->username, u->username);
				strcpy(h->password, u->password);
				strcpy(h->phonenumber, u->phonenumber);
				h->lenpar = u->lenpar;
				for (l = 0; l < u->lenpar; l++)
				{
					for (o = 0; o < 10; o++)
					{
						h->parameter[l].name[o] = u->parameter[l].name[o];
					}
					h->parameter[l].place = u->parameter[l].place;
					h->parameter[l].shape = u->parameter[l].shape;
					h->parameter[l].type = u->parameter[l].type;
					strcpy(h->parameter[l].S, u->parameter[l].S);
					for (k = 0; k < dense_points_max; k++)
					{
						h->parameter[l].x[k] = u->parameter[l].x[k];
						h->parameter[l].y[k] = u->parameter[l].y[k];
					}
					h->parameter[l].lenxy = u->parameter[l].lenxy;
				}
				for (l = 0; l < 5; l++)
				{
					for (k = 0; k < 15; k++)
					{
						h->here[l].ware_name[k] = u->here[l].ware_name[k];
					}
					for (k = 0; k < 3; k++)
					{
						h->here[l].total[k] = u->here[l].total[k];
					}
					h->here[l].cotton_type = u->here[l].cotton_type;
				}
				flag=1;
				break;
			}
		}
	}
	if (flag == 0)
	{
		void *buffer;
		unsigned s;
		setfillstyle(1, CYAN);
		s = imagesize(220, 100, 420, 150);
		buffer = malloc(s);
		getimage(220, 100, 420, 150, buffer);
		bar(220, 100, 420, 150);
		puthz(220, 100, "登录失败", 32, 32, BLUE);
		delay(1000);
		putimage(220, 100, buffer, COPY_PUT);
		free(buffer);
	}
	fclose(fp);
	free(u);
	u = NULL;
	return flag;
}

int changepassword(char username0[], char newpassword0[], char phonenumber0[])
{
	FILE *fp;
	user *u = (user *)malloc(sizeof(user));
	int i, j, k, flag = 0, all;

	if ((fp = fopen("User.dat", "rb+")) == NULL)
	{
		puthz(120, 300, "打开错误", 32, 32, BLUE);
		delay(3000);
		return;
	}
	fseek(fp, 0, SEEK_END);
	all = ftell(fp) / sizeof(user);
	for (i = 0; i < all; i++)
	{
		fseek(fp, i * sizeof(user), SEEK_SET);
		fread(u, sizeof(user), 1, fp);
		for (j = 0; j < 10; j++) // 查找账号位置
		{

			if (u->username[j] != username0[j])
			{
				break;
			}
			if (username0[j] == '\0')
			{
				j = 10;
				break;
			}
		}
		if (j == 10) // 找到了就判断电话号码正不正确
		{

			for (j = 0; j < 12; j++)
			{

				if (u->phonenumber[j] != phonenumber0[j])
				{
					// outtextxy(200,200,u->phonenumber);
					break;
				}
				if (phonenumber0[j] == '\0')
				{
					j = 12;
					break;
				}
			}
			if (j == 12) // 电话号码正确就改密码
			{
				// outtextxy(200,200,u->phonenumber);
				for (k = 0; k < 10; k++)
				{
					u->password[k] = newpassword0[k];
				}
				fseek(fp, i * sizeof(user), SEEK_SET);
				fwrite(u, sizeof(user), 1, fp);
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		setfillstyle(1, CYAN);
		bar(220, 100, 420, 150);
		puthz(220, 100, "更改密码成功", 32, 32, BLUE);
		delay(2000);
	}
	else
	{
		void *buffer;
		unsigned s;
		setfillstyle(1, CYAN);
		s = imagesize(220, 100, 420, 150);
		buffer = malloc(s);
		getimage(220, 100, 420, 150, buffer);
		bar(220, 100, 420, 150);
		puthz(220, 100, "更改密码失败", 32, 32, BLUE);
		delay(2000);
		putimage(220, 100, buffer, COPY_PUT);
		free(buffer);
	}

	free(u);
	u = NULL;
	fclose(fp);
	return flag;
}