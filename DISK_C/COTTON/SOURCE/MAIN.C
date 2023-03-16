#include "TOTAL.H"

/*int main()
{
    int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
	draw_wel();
	return 0;
}*/

void quit(void)
{
    setfillstyle(1,LIGHTBLUE);
    bar(0,0,40,30);
	puthz(3,10,"退出",16,16,WHITE);
}

/*void text_input(char *str,int x1,int y1,int x2,int y2,int t_x,int t_y,int t_size)
{
	char temp,*p;
	int i, n=t_x,get,arr[10]={p_0,p_1,p_2,p_4,p_5,p_6,p_7,p_8,p_9};
	clrmous(MouseX,MouseY);
	p=str;
	setfillstyle(1,WHITE);
	setcolor(DARKGRAY);
	bar(x1,y1,x2,y2);
	while(bioskey(1))
	{
		get=bioskey(0);
	}
	while(*p!='\0')
	{
		if (get==p_Enter)
		{
			break;
		}
		for(i=0;i<10;i++)
		{
			if(arr[i]==get)
			{
				temp=i+'0';
			}
		}
		*p=temp;
		p++;
		outtextxy(n,t_y,&temp);
		get=bioskey(0);
		n+=t_size;
	}
}*/

void input_text(char *id, int x, int y, int charnum, int color, int flag)
{ // flag==1  显示

#define h 32
#define w 18
#define space 0
#define SX x + 5 // START X
#define SY y - 5

    //int k = 0;

    int i = 0;
    char t;
    clrmous(MouseX, MouseY);
    setfillstyle(SOLID_FILL, color);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    setcolor(DARKGRAY);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 4);
    settextjustify(LEFT_TEXT, TOP_TEXT);

    while (bioskey(1))
    {
        t = bioskey(0);
    }

    while (*(id + i) != '\0')
        i++;
    line(SX+i*w,SY,SX+i*w,SY+h);
    while (1)
    {
		setfillstyle(1,WHITE);
        t = bioskey(0);
        if (i<charnum)
        {
            if (t!='\n'&& t!='\r'&&t !=' '&& t != 033)
            { // 033:Esc
                if (t != '\b')
                {
                    *(id + i) = t;
                    *(id + i + 1) = '\0';
                    bar(SX+i*w-1+space,SY - 1,SX +i*w+1+space,SY+h); //遮盖光标
                    if (flag)
                        outtextxy(SX + i * 18, SY, id + i); //输出刚输入的字符t
                    else
                    {
                        outtextxy(SX + i * 18, SY, "*");
                    }
                    i++;
                    line(SX + i * w + space, SY, SX +i*w +space,SY+h);
                }
                else if (t == '\b' && i > 0)
                {
                    bar(SX+i*w-1+space,SY-1,SX+i*w+1+space,SY+h); //遮盖光标
                    i--;                                             //减少一个字数
                    bar(SX+i*w,SY,SX + i * w + w, SY + h);            //遮盖文字
                    line(SX+i*w+space, SY, SX + i * w + space, SY + h); //绘制光标
                    *(id + i) = '\0';
                    *(id + i + 1) = '\0';
                }
            }
            else
            {
                bar(SX+i * w - 1 + space,SY - 1, SX + i * w + 1+ space, SY+ h); //遮盖光标
                break;
            }
        }
        else
        {
            if (t!='\n'&&t!='\r' && t != ' '&&t!=033)
            { // 033:Esc
                if (t == '\b' && i > 0)
                {
                    bar(SX+i*w-1+space,SY-1,SX + i * w + 1 + space, SY + h); //遮盖光标
                    i--;                                                                 //减少一个字数
                    bar(SX + i * w, SY, SX + i *w+w,SY+h);                         //遮盖文字
                    line(SX + i * w + space, SY, SX + i * w + space,SY + h);            //绘制光标
                    *(id + i) = '\0';
                    *(id + i + 1) = '\0';
                }
            }
            else
            {
                bar(SX+i*w -1+space,SY-1,SX+i*w+1+space,SY+h); //遮盖光标
                break;
            }
        }
    }
    //return i;
}

/*int ch_to_int(char *str)
{
	int out=0;
	char *p=str;
	while(*p!='\0')
	{
		out*=10;
		out+=*p-'0';
	}
	return out;
}*/