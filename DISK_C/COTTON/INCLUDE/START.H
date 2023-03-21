#ifndef _START_H_
#define _START_H_
#define x_max 550
#define y_max 320
#define x_start 50
#define y_start 120

//attention: the warehouse moudule is made by file "HOME.H"
void draw_simu01(void);//draw the process of harvest in animition
void press_start(void);//add the press moudules
void init_field(int x,int y);//initialize the cotton field
void init_tracktor01_f(int x,int y);//initialize the tarcker 01
void init_tracktor01_b(int x,int y);
void earth_fill01(int x,int y);
void earth_fill02(int x,int y);
void earth_fill03(int x,int y);
void earn_anim(int x,int y);
void start_ainime(int t_trac,int x,int y,int num);
void init_tracktor02_f(int x,int y);
void init_tracktor02_b(int x,int y);
int pressed_anime(int x,int y);
void anime_skip_result(int x,int y);
void pick_finish(int count);

#endif