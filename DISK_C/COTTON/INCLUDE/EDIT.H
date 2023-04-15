#ifndef _EDIT_H_
#define _EDIT_H_

void edit01_screen(void);
int edit01(struct Parameter *abc);//The first in edit:choose area
void edit02_screen(struct Parameter *abc);
int edit02(struct Parameter *abc);//The Second in edit:define size and shape of the field
void edit03_screen(void);
int edit03(struct Parameter *abc);//Choose the type of tractors and cotton
//void press_edit();//add the press moudule

void edit(void);

#endif