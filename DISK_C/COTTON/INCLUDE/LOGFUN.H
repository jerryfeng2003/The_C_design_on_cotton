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



<<<<<<< Updated upstream
=======
// 产区，面积，形状（坐标），收割机类型，名字

// 产区：a--新疆；b--黄河；c--长江；分别对应：粗绒棉，长绒棉，细绒棉
// 面积：123（数字）
// 形状：a--矩形；b--圆形；c--多边形；d自定义形状
// 坐标：c/d才用：x1,y1,x2,y2,x3,y3....
// 收割机类型：a垂直/b水平
// 名字：abcdefg

typedef struct Parameter
{
    char name[10];//名字
    char place;//产区
	char shape;//土地形状
    char type;//收割机类型
	int S;//面积
	int xyz[200];//坐标
}parameter;

>>>>>>> Stashed changes
typedef struct User
{
    char username[10];
    char password[10];
    char phonenumber[12];
	char parameter[10];//参数列表
	int lenpar;//参数个数
}user;


void input_s(int x,int y,INPUT *word,int size,int mode);//键盘输入
void reset();//忘记密码
void wr_user(char username[],char password[],char phonenumber[]);
int changepassword(char username0[],char newpassword0[],char phonenumber0[]);
int logg(char username0[],char password0[],struct user* loguser);


#endif