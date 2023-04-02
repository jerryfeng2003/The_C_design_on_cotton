#include "TOTAL.H"

void draw_edit01(struct Parameter *abc)
{
	void *buffer,*buffer1,*buffer2;
	unsigned s,s1,s2;
    //int i;
	clrmous(MouseX,MouseY);
    cleardevice();
    setbkcolor(WHITE);
	puthz(240,30,"请选择地区",32,32,BLUE);
	quit();
	last();
	mouseinit();
	setcolor(12);//淡红色
	rectangle(50,100,590,420);

	//按钮
	puthz(80,150,"新疆地区",32,32,BLUE);
	puthz(400,150,"长江地区",32,32,BLUE);
	puthz(250,300,"黄河地区",32,32,BLUE);
	setcolor(CYAN);
	bar(120,200,150,230);
	bar(440,200,470,230);
	bar(290,350,320,380);

	//按钮,按下去
	setfillstyle(1,MAGENTA);
	s=imagesize(100,180,170,250);
	buffer=malloc(s);
	getimage(100,180,170,250,buffer);

	s1=imagesize(420,180,490,250);
	buffer1=malloc(s1);
	getimage(420,180,490,250,buffer1);

	s2=imagesize(270,330,340,400);
	buffer2=malloc(s2);
	getimage(270,330,340,400,buffer2);
	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		//press_edit();
		if(mouse_press(100,180,170,250)==2)//新疆
		{
			pieslice(135,215,0,360,20);
		}
		else
		{
			putimage(100,180,buffer,COPY_PUT);
		}
		if(mouse_press(100,180,170,250)==1)
		{
			abc->place='a';
			return;
		}

		if(mouse_press(420,180,490,250)==2)//黄河
		{
			pieslice(455,215,0,360,20);
		}
		else
		{
			putimage(420,180,buffer1,COPY_PUT);
		}
		if(mouse_press(420,180,490,250)==1)
		{
			abc->place='b';
			return;
		}

		if(mouse_press(270,330,340,400)==2)//长江
		{
			pieslice(305,365,0,360,20);
		}
		else
		{
			putimage(270,330,buffer2,COPY_PUT);
		}
		if(mouse_press(270,330,340,400)==1)
		{
			abc->place='c';
			return;
		}

		//quit
		if(mouse_press(0,0,40,30)==0)
		{
			MouseS=0;
		}
		if(mouse_press(0,0,40,30)==2)
		{
			MouseS=1;
		}
		if(mouse_press(0,0,40,30)==1)
		{
			exit(0);
		}

		//last
		if(mouse_press(0,450,40,480)==0)
		{
			MouseS=0;
		}
		if(mouse_press(0,450,40,480)==2)
		{
			MouseS=1;
		}
		if(mouse_press(0,450,40,480)==1)
		{
			draw_wel();
		}
		delay(15);
	}
	//bmp_convert(".\\photo\\map.bmp",".\\photo\\map.dbm");
	//show_dbm(5,100,".\\photo\\map.dbm");
	//getchar();
	//closegraph();
}

int draw_edit02(struct Parameter *abc)
{
	int flag=0;//返回键判断
	INPUT S = {330, 30, 490, 90,"",6,0,0};
	clrmous(MouseX,MouseY);
	cleardevice();
    setbkcolor(WHITE);

	quit();
	last();

	//bar(100,40,360,90);
	puthz(70,40,"请输入土地面积：",32,32,BLUE);
	puthz(490,40,"公顷",32,32,BLUE);
	puthz(90,100,"本地推荐种植的棉花种类为：",32,32,BLUE);
	if (abc->place=='a')
	{
		puthz(500,100,"粗绒棉",32,32,BLUE);
	}
	else if(abc->place=='b')
	{
		puthz(500,100,"长绒棉",32,32,BLUE);
	}
	else 
	{
		puthz(500,100,"细绒棉",32,32,BLUE);
	}

	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(15);
		input_s(333, 30, &S, 16 , 0);
		
		
		//quit
		if(mouse_press(0,0,40,30)==0)
		{
			MouseS=0;
		}
		if(mouse_press(0,0,40,30)==2)
		{
			MouseS=1;
		}
		if(mouse_press(0,0,40,30)==1)
		{
			draw_wel();
		}

		//last
		if(mouse_press(0,450,40,480)==0)
		{
			MouseS=0;
		}
		if(mouse_press(0,450,40,480)==2)
		{
			MouseS=1;
		}
		if(mouse_press(0,450,40,480)==1)
		{
			return 1;
		}
	}

}

int draw_edit03(struct Parameter *abc)
{
	clrmous(MouseX,MouseY);
	cleardevice();
    setbkcolor(WHITE);

	quit();
	last();

	for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
		delay(15);
		
		
		
		//quit
		if(mouse_press(0,0,40,30)==0)
		{
			MouseS=0;
		}
		if(mouse_press(0,0,40,30)==2)
		{
			MouseS=1;
		}
		if(mouse_press(0,0,40,30)==1)
		{
			draw_wel();
		}

		//last
		if(mouse_press(0,450,40,480)==0)
		{
			MouseS=0;
		}
		if(mouse_press(0,450,40,480)==2)
		{
			MouseS=1;
		}
		if(mouse_press(0,450,40,480)==1)
		{
			return 1;
		}
	}
}

void edit(struct User* h)
{
	parameter *abc=(parameter*)malloc(sizeof(parameter));

	edit01:
	draw_edit01(abc);
	
	edit02:
	if (draw_edit02(abc)==1)
	{
		goto edit01;
	}

	if (draw_edit03(abc)==1)
	{
		goto edit02;
	}
}
