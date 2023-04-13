#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include "mouse.h"


/**************************
MOUSE.c
UPDATER: dengshuumin
FUNCTION: mouse action
ABSTRACT:
		A.mread
		B.newmouse
VERSION: 3.0
***************************/
int MouseX;
int MouseY;
int MouseS;
int press;
void *buffer;
union REGS regs;
int flag=0;



void mouseinit()//锟斤拷始锟斤�?
{
	int retcode;
	int xmin,xmax,ymin,ymax,x_max=625,y_max=480;
	int size;

	xmin=2;
	xmax=x_max-1;
	ymin=8;
	ymax=y_max-2;
	regs.x.ax=0;
	int86(51,&regs,&regs);
	retcode=regs.x.ax;
	if(retcode==0)
	{
		printf("Mouse or Mouse Driver Obsent,Please Install!");
		delay(5000);
	}
	else
	{
		regs.x.ax=7;
		regs.x.cx=xmin;
		regs.x.dx=xmax;
		int86(51,&regs,&regs);
		regs.x.ax=8;
		regs.x.cx=ymin;
		regs.x.dx=ymax;
		int86(51,&regs,&regs);
	}
	MouseS = 0;
	MouseX=320,MouseY=240;
	save_bk_mou(320,240);
	mouse(MouseX,MouseY);
	flag=1;
}

/*****************************
FUNCTION: mouse
DESCRIPTION: 锟斤拷锟斤拷同锟斤拷态锟斤拷锟斤拷锟?
INPUT: x,y
RETURN: 锟斤�?
******************************/
void mouse(int x,int y)
{
	
	switch(MouseS)
	{
		case 1:                                  //锟斤拷锟斤拷锟斤拷锟?
		{
				setcolor(WHITE);
				setlinestyle(0,0,1);
				line(x-1,y+9,x-1,y+8);
				line(x,y+7,x,y+11);
				line(x+1,y+6,x+1,y+13);
				line(x+2,y+8,x+2,y+14);
				line(x+3,y-1,x+3,y+15);
				arc(x+4,y-1,0,180,1);
				line(x+4,y-2,x+4,y+15);
				line(x+5,y-1,x+5,y+16);
				arc(x+6,y+3,0,180,1);
				line(x+6,y+2,x+6,y+16);
				line(x+7,y+3,x+7,y+17);
				arc(x+8,y+5,0,180,1);
				line(x+8,y+4,x+8,y+17);
				line(x+9,y+5,x+9,y+16);
				arc(x+10,y+7,0,180,1);
				line(x+10,y+6,x+10,y+16);
				line(x+11,y+7,x+11,y+13);

				setcolor(DARKGRAY);
				line(x-1,y+9,x-1,y+8);
				line(x-1,y+8,x+1,y+6);
				line(x+1,y+6,x+3,y+10);
				line(x+3,y+10,x+3,y-1);
				arc(x+4,y-1,0,180,1);
				line(x+5,y-1,x+5,y+5);
				arc(x+6,y+3,0,180,1);
				line(x+7,y+3,x+7,y+7);
				arc(x+8,y+5,0,180,1);
				line(x+9,y+5,x+9,y+9);
				arc(x+10,y+7,0,180,1);
				line(x+11,y+7,x+11,y+13);
				arc(x+7,y+13,-90,0,4);
				line(x+7,y+17,x+3,y+15);
				line(x+3,y+15,x+1,y+13);
				line(x+1,y+13,x-1,y+9);
		}
			break;
		case 2:                        //锟斤拷锟?
		{
			setcolor(DARKGRAY);
			setlinestyle(0,0,1);
			line(x+1,y-1,x+9,y-1);
			line(x+1,y+15,x+9,y+15);
			line(x+5,y-1,x+5,y+15);
		}
			break;
		case 3:                        //十锟斤拷
		{
			setcolor(WHITE);
			setlinestyle(0,0,1);
			line(x-1,y+7,x+11,y+7);
			line(x+5,y-1,x+5,y+15);
		}
			break;
		default:              //默锟斤拷锟斤拷锟?
		{
			setlinestyle(0,0,1);
			setcolor(WHITE);
			line(x,y,x,y+13);
			line(x+1,y+1,x+1,y+12);
			line(x+2,y+2,x+2,y+11);
			line(x+3,y+3,x+3,y+10);
			line(x+4,y+4,x+4,y+12);
			line(x+5,y+5,x+5,y+9);
			line(x+5,y+11,x+5,y+14);
			line(x+6,y+6,x+6,y+9);
			line(x+6,y+13,x+6,y+15);
			line(x+7,y+7,x+7,y+9);
			line(x+8,y+8,x+8,y+9);
			line(x+9,y+9,x+9,y+9);
			setcolor(DARKGRAY);
			line(x-1,y-1,x-1,y+14);
			line(x-1,y+14,x+3,y+11);
			line(x+3,y+11,x+3,y+12);
			line(x+3,y+12,x+4,y+13);
			line(x+4,y+13,x+4,y+14);
			line(x+4,y+14,x+7,y+17);
			line(x+7,y+17,x+7,y+13);
			line(x+7,y+13,x+6,y+12);
			line(x+6,y+12,x+6,y+11);
			line(x+6,y+11,x+5,y+10);
			line(x+5,y+10,x+11,y+10);
			line(x+11,y+10,x-1,y-2);
		}
		break;
	}
}

/*void mou_pos(int *nx,int *ny,int*nbuttons)//锟斤拷锟斤拷锟斤拷锟轿伙拷锟?
{
	int x0=*nx,y0=*ny;

	mread(nx,ny,nbuttons);
	clrmous(x0,y0);
	save_bk_mou(*nx,*ny);
	drawmous(*nx,*ny);
}

void mread(int *nx,int *ny,int*nbuttons)//锟斤拷锟斤拷锟疥不锟斤拷
{
	int x0=*nx,y0=*ny,buttons0=*nbuttons;
	int xnew,ynew,buttonsnew;

	do{
	regs.x.ax=3;
	int86(51,&regs,&regs);
	buttonsnew=regs.x.bx;
	delay(10);
	regs.x.ax=3;
	int86(51,&regs,&regs);
	if(regs.x.bx==buttonsnew)
		*nbuttons=regs.x.bx;
	else
		*nbuttons=buttons0;
	xnew=regs.x.cx;
	ynew=regs.x.dx;
	}while(xnew==x0&&ynew==y0&&*nbuttons==0);
	*nx=xnew;
	*ny=ynew;
}
*/

/***************************************
FUNCTION: mread
DESCRIPTION: 锟斤拷取锟铰的寄达拷锟斤拷锟斤拷�?
INPUT: nx,ny,nbuttons
RETURN: 锟斤�?
****************************************/
void mread(int *nx,int *ny,int *nbuttons)  
{
	regs.x.ax=3;
	int86(51,&regs,&regs);
	*nx = regs.x.cx;
	*ny = regs.x.dx;
	*nbuttons = regs.x.bx;
}

/*******************************************
FUNCTION: newmouse
DESCRIPTION: 锟斤拷锟阶刺拷锟斤拷锟斤拷浠拷锟斤拷锟斤拷锟斤拷�??
INPUT: nx,ny,nbuttons
RETURN: 锟斤�?
********************************************/
void newmouse(int *nx,int *ny,int *nbuttons)
{
	int xn,yn,buttonsn;
	int x0=*nx,y0=*ny,buttons0=*nbuttons;
	// if(x0>615)
	// {
	// 	clrmous(x0,y0);
	// }
	mread(&xn,&yn,&buttonsn);
	*nx = xn;
	*ny = yn;
	*nbuttons = buttonsn;
	if(buttons0 == *nbuttons)
		*nbuttons = 0;    //使锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤�?
	if(xn == x0 && yn == y0 && buttonsn == buttons0)
		return;            //锟斤拷锟阶刺拷锟斤拷锟斤拷锟街憋拷臃锟斤拷锟絊
	clrmous(x0,y0);        //说锟斤拷锟斤拷锟阶刺拷锟斤拷锟斤拷烁谋�??
	save_bk_mou(*nx,*ny);
	drawmous(*nx,*ny);
}

void save_bk_mou(int nx,int ny)//锟斤拷锟斤拷瓯筹拷锟?
{
	int size;

	size=imagesize(nx-1,ny-2,nx+11,ny+17);
	buffer=malloc(size);
	if(buffer!=NULL)
		getimage(nx-1,ny-2,nx+11,ny+17,buffer);
	else
		printf("Error");
}

void clrmous(int nx,int ny)//锟斤拷锟斤拷锟斤�?
{
	if(flag==1)
	{
		setwritemode(XOR_PUT); 
		mouse(nx,ny);
		putimage(nx-1,ny-2,buffer,COPY_PUT);
		free(buffer);
		flag=0;
		setwritemode(COPY_PUT);
	}
}
void drawmous(int nx,int ny)
{
	if(flag==0)
	{
		setwritemode(COPY_PUT);
	    mouse(nx,ny);
		flag=1;
	}
}



//锟斤拷锟斤拷诳锟斤拷械锟斤拷锟斤拷锟津返伙拷1锟斤拷锟节匡拷锟斤拷未锟斤拷锟斤拷锟斤拷蚍祷�??2锟斤拷锟斤拷锟节匡拷锟斤拷锟津返伙拷0
int mouse_press(int x1, int y1, int x2, int y2)
{
	//锟节匡拷锟叫碉拷锟斤拷锟斤拷蚍祷�??1
	if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 1)
	{
		return 1;
	}
	
	//锟节匡拷锟斤拷未锟斤拷锟斤拷锟斤拷蚍祷锟?2
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 0)
	{
		return 2;
	}
	
	//锟节匡拷锟叫碉拷锟斤拷壹锟斤拷锟斤拷蚍祷�??3
	else if(MouseX > x1 
	&&MouseX < x2
	&&MouseY > y1
	&&MouseY < y2
	&&press == 2)
	{
		return 3;
	}
	
	else
	{
		return 0;
	}
}

