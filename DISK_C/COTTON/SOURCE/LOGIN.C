#include "TOTAL.H"


void loginit_screen()
{
    cleardevice();
    setbkcolor(WHITE);
    puthz(180,30,"�޻���ժģ��ϵͳ",32,32,BLUE);
    quit();//�˳�

    //��
    setcolor(BLUE);
    setfillstyle(1,LIGHTGRAY);
    //rectangle(123, 103, 523, 153);
    bar(120, 100, 220, 160);            //�˺�
    //rectangle(123, 203, 523, 253);
    bar(120, 200, 220, 260);            //����

    setfillstyle(1,LIGHTGREEN);
    bar(220, 100, 520, 160);  
    bar(220, 200, 520, 260);   

    bar(280, 300, 360, 340);            //��¼

    setfillstyle(1,DARKGRAY);
    bar(120, 350, 280, 400);            //��������
    bar(360, 350, 520, 400);            //ע���˺�
          
    puthz(123,110,"�˺ţ�",32,32,BLUE);
    puthz(123,210,"���룺",32,32,BLUE);
    puthz(130,360,"��������",32,32,WHITE);
    puthz(370,360,"ע���˺�",32,32,WHITE);
    puthz(285,305,"��¼",32,32,BLUE);


    //���ٵ�¼
    bar(380, 300, 550, 340); 
    puthz(383, 300,"���ٵ�¼",32,32,RED);
}

int logenter()
{
    //�˳�
    if(mouse_press(0,0,40,30)==1)
	{
		exit(0);
        return 0;
        
	}
    //��¼
    if(mouse_press(280, 300, 360, 340)==1)
    {
        return 1;
    }
    return 0;
}

void loginit(struct user * now)
{
    INPUT username = {220, 100, 520, 160,"",10,0,0};
	INPUT password = {220, 200, 520, 260,"",10,0,0};
    //struct user all[100];
    loginit_screen();
    mouseinit();
    for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
        if(logenter()==1)
        {
            if(log(username.string,password.string,now)==1)
            {
                return;
            }
        }
        if(mouse_press(380, 300, 550, 340)==1)
        {
            return;
        }
        input_s(223, 100, &username, 16 , 0);
        input_s(223, 200, &password, 16 , 1);
        if(mouse_press(360, 350, 520, 400)==1)
        {
            log_register();
            loginit_screen();
        }
        if(mouse_press(120, 350, 280, 400)==1)
        {
            reset();
            loginit_screen();
        }

    
	delay(15);
	}
}