#include "COMMON.H"
#include "REGISTER.H"
#include "PARAMETE.H"
#include "LOGFUN.H"

void register_screen()
{
    cleardevice();
    setbkcolor(WHITE);
    setfillstyle(1, LIGHTBLUE);
    bar(80, 70, 560, 500);

    setfillstyle(1, LIGHTGRAY);
    puthz(260, 30, "注册账号", 32, 32, BLUE);
    bar(120, 100, 530, 150); // 账号
    puthz(123, 110, "账号", 32, 32, BLUE);
    bar(120, 180, 530, 230); // 密码
    puthz(123, 190, "密码", 32, 32, BLUE);
    bar(120, 260, 530, 310); // 确认密码
    puthz(123, 270, "确认密码", 32, 32, BLUE);
    bar(120, 340, 530, 390); // 电话号码
    puthz(123, 350, "电话号码", 32, 32, BLUE);

    setfillstyle(1, DARKGRAY);
    bar(120, 420, 280, 460); // 返回
    puthz(160, 423, "返回", 32, 32, RED);
    bar(360, 420, 520, 460); // 确认
    puthz(400, 423, "确认", 32, 32, RED);

    setfillstyle(1, WHITE);
    bar(260, 340, 530, 390);
    bar(260, 260, 530, 310);
    bar(220, 180, 530, 230);
    bar(220, 100, 530, 150);
}

void log_register()
{
    // 界面
    INPUT username = {220, 100, 530, 150, "", 10, 0, 1};
    INPUT password = {220, 180, 530, 230, "", 10, 0, 1};
    INPUT realpassword = {260, 260, 530, 310, "", 10, 0, 1};
    INPUT phonenumber = {260, 340, 530, 390, "", 11, 0, 1};

    register_screen();

    for (;;)
    {
        newmouse(&MouseX, &MouseY, &press);
        input_s(260, 260, &realpassword, 16, 1);
        if (input_s(223, 100, &username, 16, 0) == 1)
        {
            setfillstyle(1, CYAN);
            bar(170, 30, 470, 72);
            puthz(180, 32, "账号名最多十位字符", 32, 32, BLUE);
            delay(800);
            setfillstyle(1, 0);
            bar(170, 30, 470, 72);
            puthz(260, 30, "注册账号", 32, 32, BLUE);
        }
        if (input_s(220, 180, &password, 16, 1) == 1)
        {
            setfillstyle(1, CYAN);
            bar(170, 30, 470, 72);
            puthz(180, 32, "密码最多十位字符", 32, 32, BLUE);
            delay(800);
            setfillstyle(1, 0);
            bar(170, 30, 470, 72);
            puthz(260, 30, "注册账号", 32, 32, BLUE);
        }
        if ((input_s(263, 340, &phonenumber, 16, 0)) == 1)
        {
            setfillstyle(1, CYAN);
            bar(170, 30, 470, 72);
            puthz(180, 32, "请输入十一位号码", 32, 32, BLUE);
            delay(800);
            setfillstyle(1, 0);
            bar(170, 30, 470, 72);
            puthz(260, 30, "注册账号", 32, 32, BLUE);
        }
        if (mouse_press(120, 420, 280, 460) == 1)
        {
            return;
        }
        if ((mouse_press(360, 420, 520, 460) == 1) &&
            (username.string[0] != '\0') && (phonenumber.string[0] != '\0') &&
            (password.string[0] != '\0'))
        {
            if ((strcmp(password.string, realpassword.string) != 0))
            {
                setfillstyle(1, CYAN);
                bar(160, 30, 480, 72);
                puthz(170, 32, "确认密码与密码不相同", 32, 32, BLUE);
                delay(800);
                setfillstyle(1, 0);
                bar(160, 30, 480, 72);
                puthz(260, 30, "注册账号", 32, 32, BLUE);
                return;
            }
            if (username_same(username.string, phonenumber.string) == 0)
            {
                wr_user(username.string, password.string, phonenumber.string);
                return;
            }
        }
        delay(15);
    }
}