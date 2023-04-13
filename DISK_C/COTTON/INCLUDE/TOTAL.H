#ifndef _TOTAL_H_
#define _TOTAL_H_

#define p_A 0x1E61
#define p_B 0x3062 
#define p_C 0x2E63
#define p_D 0x2064
#define p_E 0x1265
#define p_F 0x2166
#define p_G 0x2267
#define p_H 0x2368
#define p_I 0x1769
#define p_J 0x246A
#define p_K 0x256B
#define p_L 0x266C
#define p_M 0x326D
#define p_N 0x316E
#define p_O 0x186F
#define p_P 0x1970
#define p_Q 0x1071
#define p_R 0x1372
#define p_S 0x1F73
#define p_T 0x1474
#define p_U 0x1675 
#define p_V 0x2F76
#define p_W 0x1177
#define p_X 0x2D78 
#define p_Y 0x1579 
#define p_Z 0x2C7A 
#define p_0 0x0B30 
#define p_1 0x0231
#define p_2 0x0332
#define p_3 0x0433
#define p_4 0x0534 
#define p_5 0x0635
#define p_6 0x0736 
#define p_7 0x0837
#define p_8 0x0938
#define p_9 0x0A39
#define p_Backspace 0x0E08
#define p_Enter 0x1C0D
#define p_Left_arrow 0x4B00
#define p_Right_arrow 0x4D00
#define p_Up_arrow 0x4800
#define p_Donw_arrow 0x5000
#define p_SpaceBar 3920

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<malloc.h>
#include<bios.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include ".\\HZK\\HZ.H"
#include "mouse.h"
#include "IMAGE.h"
#include "WELCOME.H"
#include "EDIT.H"
#include "START.H"
#include "PAST.H"
#include "HELP.H"
#include "HOME.H"
#include "LOGIN.H"
#include "REGISTER.H"
#include "RESET.H"
#include "LOGFUN.H"
#include "PARAMETE.H"


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