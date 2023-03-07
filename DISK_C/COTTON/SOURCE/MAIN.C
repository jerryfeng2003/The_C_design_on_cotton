#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include "TOTAL.H"

int main()
{
    int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	draw_wel();
	return 0;
}