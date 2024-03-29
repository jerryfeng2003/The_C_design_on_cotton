#include "COMMON.H"
#include "LOGIN.H"
#include "PARAMETE.H"
#include "RESET.H"
#include "LOGFUN.H"


void reset_screen()
{
    cleardevice();
    setbkcolor(WHITE);
    setfillstyle(1,LIGHTBLUE);
    bar(80,80,560,500);

    setfillstyle(1,LIGHTGRAY);
    puthz(260,30,"��������",32,32,BLUE);
    bar(120, 140, 520, 200);            //�˺�
    puthz(123,150,"�˺�",32,32,BLUE);
    bar(120, 220, 520, 280);            //�绰����
    puthz(123,230,"�绰����",32,32,BLUE);
    bar(120, 300, 520, 360);            //������
    puthz(123,310,"������",32,32,BLUE);

    setfillstyle(1,DARKGRAY);
    bar(120, 420, 280, 460);            //����
    puthz(160,423,"����",32,32,BLUE);
    bar(360, 420, 520, 460);            //ȷ��
    puthz(400,423,"ȷ��",32,32,BLUE);

    setfillstyle(1,WHITE);
    bar(220, 140, 520, 200);
    bar(260, 220, 520, 280);
    bar(220, 300, 520, 360);
}


void reset()
{
    INPUT username = {220, 140, 520, 200,"",10,0,1};
	INPUT phonenumber = {260, 220, 520, 280,"",11,0,1};
    INPUT newpassword = {220, 300, 520, 360,"",10,0,1};
    
    reset_screen();

    for(;;)
    {
        newmouse(&MouseX,&MouseY,&press);
        input_s(223, 140, &username, 12 , 0);
        input_s(263, 220, &phonenumber, 12 , 1);
        input_s(223, 300, &newpassword, 12 , 1);
        if(mouse_press(120, 420, 280, 460)==1)
        {
            return;
        }
        if(mouse_press(360, 420, 520, 460)==1)
        {
            if(changepassword(username.string, newpassword.string, phonenumber.string)==1)
            {
                return;
            }
        }
        delay(15);
    }
}
