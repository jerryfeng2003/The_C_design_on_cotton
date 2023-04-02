#ifndef _LOGFUN_H_
#define _LOGFUN_H_



typedef struct Input
{
	int x1;//输入框坐标
	int y1;
	int x2;
	int y2;
	char string[19];
	char length;//输入的最大长度
	char cursor;//光标位置
	char flag;//0代表不能输入，1代表可以输入
}INPUT;



typedef struct User
{
    char username[10];
    char password[10];
    char phonenumber[12];
	//char parameter[30];
}user;


void input_s(int x,int y,INPUT *word,int size,int mode);//键盘输入
void reset();//忘记密码
void wr_user(char username[],char password[],char phonenumber[]);
int changepassword(char username0[],char newpassword0[],char phonenumber0[]);
int logg(char username0[],char password0[],struct user* loguser);


#endif