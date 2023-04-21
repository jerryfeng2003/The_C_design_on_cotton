#ifndef _DSTART_H_
#define _DSTART_H_

#include "COMMON.H"
#include "LOGFUN.H"
#include "START.H"

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
#define co_pak_w 10
#define pick_bar 600
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

void init_tracktor01_f(int x,int y);//initialize the tarcker 01
void init_tracktor01_b(int x,int y);
void init_tracktor02_f(int x,int y);
void init_tracktor02_b(int x,int y);

void earth_fill01(int x,int y);
void earth_fill02(int x,int y);
void earth_fill03(int x,int y);

void earth_cover01(int x,int y);
void earth_cover02(int x,int y);
void earth_cover03(int x,int y);

void init_tracktor01_r(int x,int y);
void init_tracktor01_l(int x,int y);
void init_tracktor02_r(int x,int y);
void init_tracktor02_l(int x,int y);

void init_picker_f(int x,int y);
void init_picker_b(int x,int y);
void init_picker_r(int x,int y);
void init_picker_l(int x,int y);

void init_picker01_f(int x,int y);
void init_picker01_b(int x,int y);
void init_picker01_r(int x,int y);
void init_picker01_l(int x,int y);

#endif