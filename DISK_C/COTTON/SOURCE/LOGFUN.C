#include "COMMON.H"
#include "LOGFUN.H"
#include "PARAMETE.H"

// 录入注册账号到文件
void wr_user(char username1[], char password1[], char phonenumber1[])
{
	FILE *fp;
	int i,j;
	user *u = (user *)malloc(sizeof(user));
	u->lenpar = 0;
	for (i = 0; i < 5; i++)
	{
		u->here[i].cotton_type = 0;
	}
	for (i=0;i<5;i++)
	{
		u->here[i].ware_name[0]='\0';
		for (j=0;j<3;j++)
		{
			u->here[i].total[j]=0;
		}
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

// 判断注册的账号是否已经存在和电话号码是否正确
// return flag为1则存在，0则不存在
int username_same(char username0[], char phonenumber0[])
{
	FILE *fp;
	user *u = (user *)malloc(sizeof(user));
	int i, j, all, flag = 0;
	if ((fp = fopen("User.dat", "rb+")) == NULL)
	{
		puthz(120, 300, "打开错误", 32, 32, BLUE);
		delay(3000);
		return 0;
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
			setfillstyle(1, CYAN);
			bar(200, 30, 440, 72);
			puthz(210, 32, "注册账号已存在", 32, 32, BLUE);
			delay(1200);
			setfillstyle(1, 0);
			bar(200, 30, 440, 72);
			puthz(260, 30, "注册账号", 32, 32, BLUE);
			flag = 1;
		}
	}
	if (strlen(phonenumber0) != 11)
	{
		setfillstyle(1, CYAN);
		bar(180, 30, 460, 72);
		puthz(190, 32, "请输入十一位号码", 32, 32, BLUE);
		delay(1200);
		setfillstyle(1, 0);
		bar(180, 30, 460, 72);
		puthz(260, 30, "注册账号", 32, 32, BLUE);
		flag = 1;
	}
	if (flag == 0)
	{
		setfillstyle(1, CYAN);
		bar(200, 30, 440, 72);
		puthz(210, 32, "注册账号成功", 32, 32, BLUE);
		delay(1200);
		setfillstyle(1, 0);
		bar(200, 30, 440, 72);
		puthz(260, 30, "注册账号", 32, 32, BLUE);
	}
	if (fclose(fp) != 0) // 关闭文件
	{
		puthz(120, 300, "关闭错误", 32, 32, BLUE);
		delay(3000);
		return 0;
	}
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
	// char a[2];
	// a[2] = '\0';

	if ((fp = fopen("User.dat", "rb+")) == NULL)
	{
		puthz(120, 300, "打开错误", 32, 32, BLUE);
		delay(3000);
		return 0;
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
					parcpy(&(h->parameter[l]),&(u->parameter[l]));
				}
				for (l = 0; l < 5; l++)
				{
					// for (k = 0; k < 15; k++)
					// {
					// 	h->here[l].ware_name[k] = u->here[l].ware_name[k];
					// }
					strcpy(h->here[l].ware_name,u->here[l].ware_name);
					for (k = 0; k < 3; k++)
					{
						h->here[l].total[k] = u->here[l].total[k];
					}
					h->here[l].cotton_type = u->here[l].cotton_type;
				}
				flag = 1;
				break;
			}
		}
	}
	if ((j != 10) && (flag == 0))
	{
		setfillstyle(1, CYAN);
		bar(220, 30, 420, 80);
		puthz(250, 35, "账号未注册", 32, 32, BLUE);
		delay(1000);
		setfillstyle(1, 0);
		bar(220, 30, 420, 80);
		puthz(180, 30, "棉花模拟采集系统", 32, 32, BLUE);
	}
	else if ((k != 10) && (flag == 0))
	{
		setfillstyle(1, CYAN);
		bar(220, 30, 420, 80);
		puthz(250, 35, "密码不正确", 32, 32, BLUE);
		delay(1000);
		setfillstyle(1, 0);
		bar(220, 30, 420, 80);
		puthz(180, 30, "棉花模拟采集系统", 32, 32, BLUE);
	}
	else if (flag == 0)
	{
		setfillstyle(1, CYAN);
		bar(240, 30, 400, 80);
		puthz(250, 35, "登录失败", 32, 32, BLUE);
		delay(1000);
		setfillstyle(1, 0);
		bar(240, 30, 400, 80);
		puthz(180, 30, "棉花模拟采集系统", 32, 32, BLUE);
	}
	if (fclose(fp) != 0) // 关闭文件
	{
		puthz(120, 300, "关闭错误", 32, 32, BLUE);
		delay(3000);
		return 0;
	}
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
		return 0;
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
		delay(1500);
	}
	else
	{
		setfillstyle(1, CYAN);
		bar(220, 80, 420, 130);
		puthz(220, 85, "更改密码失败", 32, 32, BLUE);
		delay(1200);
		setfillstyle(1, LIGHTBLUE);
		bar(220, 80, 420, 130);
	}

	free(u);
	u = NULL;
	if (fclose(fp) != 0) // 关闭文件
	{
		puthz(120, 300, "关闭错误", 32, 32, BLUE);
		delay(3000);
		return 0;
	}
	return flag;
}