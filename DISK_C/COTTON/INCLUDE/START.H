#ifndef _START_H_
#define _START_H_
#define x_max 550
#define y_max 320

//attention: the warehouse moudule is made by file "HOME.H"
void draw_simu01(void);//draw the process of harvest in animition
void press_start(void);//add the press moudules
void init_field(int x,int y);//initialize the cotton field
void init_tracktor01_f(int x,int y);//initialize the tarcker 01
void earth_fill01(int x,int y);
void earn_anim(int x,int y);
#endif