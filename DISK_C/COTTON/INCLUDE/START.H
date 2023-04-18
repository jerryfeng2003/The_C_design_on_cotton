#ifndef _START_H_
#define _START_H_
#define x_max 550
#define y_max 320
#define x_start 50
#define y_start 120
#define point_max 500
#define dense_points_max 500
#define tracktor_num_max 5
//#define delaytime 20
#define tra_time 80
#define tracktor_w 25
#define tracktor_l 30
#define tra_start_l 50
#define tra_start_d 35
#define pick_ph 2.4
#define Xinjinag_har 2.1
#define Huanghe_har 1.3
#define Chnagjiang_har 1.1
#define p_Up_arrow 0x4800
#define p_Donw_arrow 0x5000
#define p_Enter 0x1C0D

//attention: the warehouse moudule is made by file "HOME.H"
void start(void);
void draw_simu01(int time);//draw the process of harvest in animition
void press_start(int *bk);//add the press moudules
void draw_simu01(int time);//draw the process of harvest in animition
void init_based_field(void);
void init_field(int x,int y);//initialize the cotton field
void init_tracktor01_f(int x,int y);//initialize the tarcker 01
void init_tracktor01_b(int x,int y);

void earth_fill01(int x,int y);
void earth_fill02(int x,int y);
void earth_fill03(int x,int y);

void earth_cover01(int x,int y);
void earth_cover02(int x,int y);
void earth_cover03(int x,int y);

//void earn_anim(int x,int y);
void start_ainime01(int t_trac,double space,int time);
void init_tracktor02_f(int x,int y);
void init_tracktor02_b(int x,int y);
int pressed_anime(int x_sta,int y_sta, int x_des,int y_des);
void anime_skip_result(int x_sta,int y_sta, int x_des,int y_des);
void pick_finish(int count);
void choose_speed(void);
void select02(struct Parameter *abc);
void press_select02(int *x,int *y,int *flag,int *back);
//void pick_start(int *x,int *y);
void pick_points(int *x,int *y,int *flag);
void draw_points(int *arr,int *flag,long int *xy_m);
void init_field02(int *x,int *y,int *flag,int type,int time);

void pick_wait(void);
void select03(struct Parameter *abc);
void press_select03(int *x,int *y,int *flag,int *back);
void dense_pick(int *x,int *y,int *flag);
void dense_draw_points(int *arr,int *flag,long int *xy_m);
void init_field03(int *x,int *y,int *flag,int type,int time);
void dense_init_tracktor01(int *x,int *y,int *flag,long int* xy_m,int num);
void dense_init_tracktor02(int *x,int *y,int *flag,long int* xy_m,int num);
void dense_init_tracktor02(int *x,int *y,int *flag,long int* xy_m,int num);
void start_ainime03_01(int (*tra_d)[4], int num,long int *xy_m);
void start_ainime03_02(int (*tra_d)[4], int num,long int *xy_m);

void circle_field(long int r);
void cal_tracktor_circle(int tpye,double space,int time);
void start_ainime04_01(int (*tra_d)[4],int num);
void start_ainime04_02(int (*tra_d)[4],int num);

long int hellen(int x1,int y1,int x2,int y2,int x3,int y3);
long int cal_poly_field(int *x,int *y,int *flag);
double cal_circle_field(int r);

void init_tracktor01_r(int x,int y);
void init_tracktor01_l(int x,int y);
void init_tracktor02_r(int x,int y);
void init_tracktor02_l(int x,int y);
void select_setoff01(int *xy,int x_end,int y_end);
void select_setoff02(int *xy,int x_s,int y_s,int x_e,int y_e);
void draw_setoff(int *xy);
void tracktor_set_off(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off01(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off02(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off03(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off04(int start_x,int start_y,int des_x,int des_y,int distance,int num);

void tracktor_return(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return01(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return02(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return03(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return04(int start_x,int start_y,int des_x,int des_y,int distance,int num);

void tracktor_set_off0(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off001(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off002(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off003(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off004(int start_x,int start_y,int des_x,int des_y,int distance,int num);

void tracktor_return0(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return001(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return002(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return003(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_return004(int start_x,int start_y,int des_x,int des_y,int distance,int num);

void init_picker_f(int x,int y);
void init_picker_b(int x,int y);
void init_picker_r(int x,int y);
void init_picker_l(int x,int y);
#endif