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
    puthz(260,30,"忘记密码",32,32,BLUE);
    bar(120, 140, 520, 200);            //账号
    puthz(123,150,"账号",32,32,BLUE);
    bar(120, 220, 520, 280);            //电话号码
    puthz(123,230,"电话号码",32,32,BLUE);
    bar(120, 300, 520, 360);            //新密码
    puthz(123,310,"新密码",32,32,BLUE);

    setfillstyle(1,DARKGRAY);
    bar(120, 420, 280, 460);            //返回
    puthz(160,423,"返回",32,32,BLUE);
    bar(360, 420, 520, 460);            //确认
    puthz(400,423,"确认",32,32,BLUE);

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
