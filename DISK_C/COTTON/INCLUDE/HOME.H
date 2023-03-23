#ifndef _HOME_H_
#define _HOME_H_
#define ware_full 29999

void draw_home01(void);//the page of n-w warehouse
//void draw_home00(void);//the page of Y-H warehouse
void warehouse_list(void);
void press_warelist(void);
void draw_warehouse(void);//draw the picture of warehouse
void cot_mount(int x,int y);//draw the cotton in warehouse
void draw_trunk(void);//draw the trunk int the page
void in_warehouse(int count,int cotton_type);//draw the board which show the cotton in warehouse
void detailed_warehouse(int count);//detail message of warehouse
void press_detwarehouse(int count);
void press_home(int cotton_type);//add the press moudule
void out_warehouse(int count);//page of the cotton out
void press_outware(int count,char*str);
void out_finish(void);

typedef struct user_warehouse
{
	char ware_name[15];
	long int total[3];
}U_ware;

#endif