#ifndef _LOGFUN_H_
#define _LOGFUN_H_



typedef struct
{
	int x1;//���������
	int y1;
	int x2;
	int y2;
	char string[19];
	char length;//�������󳤶�
	char cursor;//���λ��
	char flag;//0�����������룬1������������
}INPUT;



typedef struct 
{
    char username[10];
    char password[10];
    char phonenumber[12];
	//char parameter[30];
}user;


void input_s(int x,int y,INPUT *word,int size,int mode);//��������
void reset();//��������
void wr_user(char username[],char password[],char phonenumber[]);
int changepassword(char username0[],char newpassword0[],char phonenumber0[]);
int log(char username0[],char password0[],struct user* loguser);



#endif