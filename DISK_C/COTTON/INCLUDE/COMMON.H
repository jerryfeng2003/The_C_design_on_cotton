#ifndef _COMMON_H_
#define _COMMON_H_

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<malloc.h>
#include<bios.h>
#include<math.h>
#include<string.h>
#include "mouse.h"
#include<conio.h>
#include ".\\HZK\\HZ.H"

//extern U_ware here[5];
extern int k;
extern int mode;
extern int mode1;
//extern char str[15];
extern struct User*h;
void quit(void);//the leave button in every page
void skip(void);
void next(void);
void last(void);
void finish(void);//the finish button in every page
//void text_input(char *str,int x1,int y1,int x2,int y2,int t_x,int t_y,int t_size);//the input function for English characters and numbers
//int ch_to_int(char *str);
void input_text(char *id, int x, int y, int charnum, int color, int flag);

#endif