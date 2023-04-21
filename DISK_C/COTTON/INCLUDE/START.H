#ifndef _START_H_
#define _START_H_





//attention: the warehouse moudule is made by file "HOME.H"
void start(void);
void draw_simu01(int time);//draw the process of harvest in animition
void press_start(int *bk);//add the press moudules
void draw_simu01(int time);//draw the process of harvest in animition
void init_based_field(void);
void init_field(int x,int y);//initialize the cotton field


//void earn_anim(int x,int y);
void start_ainime01(int t_trac,double space,int time);

int pressed_anime(int x_sta,int y_sta, int x_des,int y_des);
void anime_skip_result(int x_sta,int y_sta, int x_des,int y_des);
void pick_finish(int count,int co_type);
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
void dense_init_tracktor01(int *x,int *y,int *flag,long int* xy_m,int num,int *des_x,int *des_y);
void dense_init_tracktor02(int *x,int *y,int *flag,long int* xy_m,int num,int *des_x,int *des_y);
void start_ainime03_01(int (*tra_d)[4], int num,long int *xy_m,int *des_x,int *des_y);
void start_ainime03_02(int (*tra_d)[4], int num,long int *xy_m,int *des_x,int *des_y);

void circle_field(long int r);
void cal_tracktor_circle(int tpye,double space,int time);
void start_ainime04_01(int (*tra_d)[4],int num,int *des_x,int *des_y);
void start_ainime04_02(int (*tra_d)[4],int num,int *des_x,int *des_y);

long int hellen(int x1,int y1,int x2,int y2,int x3,int y3);
long int cal_poly_field(int *x,int *y,int *flag);
double cal_circle_field(int r);


void select_setoff01(int *xy,int x_end,int y_end);
void select_setoff02(int *xy,int x_s,int y_s,int x_e,int y_e);
void draw_setoff(int *xy);
void tracktor_set_off(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off01(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off02(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off03(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off04(int start_x,int start_y,int des_x,int des_y,int distance,int num);

void tracktor_return(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return01(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return02(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return03(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return04(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);

void tracktor_set_off0(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off001(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off002(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off003(int start_x,int start_y,int des_x,int des_y,int distance,int num);
void tracktor_set_off004(int start_x,int start_y,int des_x,int des_y,int distance,int num);

void tracktor_return0(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return001(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return002(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return003(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);
void tracktor_return004(int start_x,int start_y,int des_x,int des_y,int distance,int num,int *he_x,int *he_y);


void picker_anime(int start_x,int start_y,int *des_x,int *des_y,int distance,int num);
void draw_copak(int x,int y);


void picker_set_off(int *x_p,int *y_p, int start_x,int start_y,int des_x,int des_y,int *time,int num,int *count,int* type);
void picker_set_off01(int *x_p,int *y_p, int des_x, int des_y, int *time, int i,int *count,int *type);
void picker_set_off02(int *x_p,int *y_p, int des_x, int des_y, int *time, int i,int *count,int *type);
void picker_set_off03( int *x_p,int *y_p,int des_x, int des_y, int *time, int i,int *count,int *type);
void picker_set_off04(int *x_p,int *y_p, int des_x, int des_y, int *time, int i,int *count,int *type);

void picker_return(int *x_p,int *y_p,int start_x,int start_y,int des_x,int des_y,int num,int *count,int* type);
void picker_return01(int *x_p,int *y_p, int start_x,int start_y, int i,int *count,int *type);
void picker_return02(int *x_p,int *y_p, int start_x,int start_y, int i,int *count,int *type);
void picker_return03(int *x_p,int *y_p, int start_x,int start_y,  int i,int *count,int *type);
void picker_return04(int *x_p,int *y_p,int start_x,int start_y, int i,int *count,int *type);
#endif