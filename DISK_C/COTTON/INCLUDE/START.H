#ifndef _START_H_
#define _START_H_
#define x_max 550
#define y_max 320
#define x_start 50
#define y_start 120
#define point_max 50
#define dense_points_max 2000
#define tracktor_num_max 10

//attention: the warehouse moudule is made by file "HOME.H"
void draw_simu01(long int x,long int y,int num);//draw the process of harvest in animition
void press_start(void);//add the press moudules
void init_field(int x,int y);//initialize the cotton field
void init_tracktor01_f(int x,int y);//initialize the tarcker 01
void init_tracktor01_b(int x,int y);
void earth_fill01(int x,int y);
void earth_fill02(int x,int y);
void earth_fill03(int x,int y);
void earn_anim(int x,int y);
void start_ainime01(int t_trac,int x,int y,int num);
void init_tracktor02_f(int x,int y);
void init_tracktor02_b(int x,int y);
int pressed_anime(int x,int y);
void anime_skip_result(int x,int y);
void pick_finish(int count);

void select02(void);
void press_select02(int *x,int *y,int *flag);
void pick_start(int *x,int *y);
void pick_points(int *x,int *y,int *flag);
void draw_points(int *x,int *y,int *flag,int *xy_m);
void init_field02(int *x,int *y,int *flag);

void pick_wait(void);
void select03(void);
void press_select03(int *x,int *y,int *flag);
void dense_pick(int *x,int *y,int *flag);
void dense_draw_points(int *x,int *y,int *flag,long int *xy_m);
void init_field03(int *x,int *y,int *flag);
void dense_init_tracktor01(int *x,int *y,int *flag,long int* xy_m,int num);
void start_ainime03_01(int (*tra_d)[4],int num);
void start_ainime03_02(int (*tra_d)[4],int num);
#endif