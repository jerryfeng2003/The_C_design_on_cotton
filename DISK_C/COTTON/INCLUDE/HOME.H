#ifndef _HOME_H_
#define _HOME_H_

#define ware_full 29999
#define num_ware 5

void draw_home01(void);//the page of n-w warehouse
//void draw_home00(void);//the page of Y-H warehouse
void warehouse_list(struct user_warehouse * w);
void press_warelist(int *re);
void draw_warehouse(void);//draw the picture of warehouse
void cot_mount(int x,int y);//draw the cotton in warehouse
void draw_trunk(void);//draw the trunk int the page
void in_warehouse(struct user_warehouse *now);//draw the board which show the cotton in warehouse
void detailed_warehouse(long int count);//detail message of warehouse
void press_detwarehouse(void);
void press_home(int *c_t);//add the press moudule
void out_warehouse(void);//page of the cotton out
void press_outware(void);
void out_finish(void);

typedef struct user_warehouse
{
	char ware_name[15];
	int cotton_type;
	long int total[3];
}U_ware;

#endif