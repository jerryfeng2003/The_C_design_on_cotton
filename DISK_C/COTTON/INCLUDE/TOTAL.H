#ifndef _TOTAL_H_
#define _TOTAL_H_

#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
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
#include "LOGFUN.H"
#include "REGISTER.H"
#include "RESET.H"
//#include "PARAMETE.H"


extern int location;//1 means the norwestern,0 means others
void quit(void);//the leave button in every page
void finish(void);//the finish button in every page

#endif