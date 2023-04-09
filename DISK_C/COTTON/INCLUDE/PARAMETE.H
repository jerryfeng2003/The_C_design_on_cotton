
#ifndef _PARAMETE_H_
#define _PARAMETE_H_

//判断名字是否为空and重复
int judgename(char name[]);

//判断土地面积是否为数字和空
int judgeS(char name[]);

//把参数写进h，然后把h写进文件里面
void wr_parameter(struct Parameter* abc);

//修改产区
int changeplace(int par);

//修改土地形状
int changeshape(int par);

//修改收割机类型
int changetype(int par);

//修改面积
int changeS(int par);

//删除参数
void deletepar(int par);

//把当前登录的用户重新写进文件
void wr_h(void);
#endif