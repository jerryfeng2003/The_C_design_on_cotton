#include "TOTAL.H"


void register_screen()
{
    cleardevice();
    setbkcolor(WHITE);
    setfillstyle(1,LIGHTBLUE);
    bar(80,70,560,500);

    setfillstyle(1,LIGHTGRAY);
    puthz(260,30,"ע���˺�",32,32,BLUE);
    bar(120, 100, 520, 150);            //�˺�
    puthz(123,110,"�˺�",32,32,BLUE);
    bar(120, 180, 520, 230);            //����
    puthz(123,190,"����",32,32,BLUE);
    bar(120, 260, 520, 310);            //ȷ������
    puthz(123,270,"ȷ������",32,32,BLUE);
    bar(120, 340, 520, 390);            //�绰����
    puthz(123,350,"�绰����",32,32,BLUE);

    setfillstyle(1,DARKGRAY);
    bar(120, 420, 280, 460);            //����
    puthz(160,423,"����",32,32,RED);
    bar(360, 420, 520, 460);            //ȷ��
    puthz(400,423,"ȷ��",32,32,RED);

    setfillstyle(1,WHITE);
    bar(260, 340, 520, 390);
    bar(260, 260, 520, 310);
    bar(220, 180, 520, 230);
    bar(220, 100, 520, 150);
}

void log_register()
{
    //����
    INPUT username = {220, 100, 520, 150,"",10,0,1};
	INPUT password = {220, 180, 520, 230,"",10,0,1};
    INPUT realpassword = {260, 260, 520, 310,"",10,0,1};
	INPUT phonenumber = {260, 340, 520, 390,"",11,0,1};

    register_screen();


    for(;;)
    {
        newmouse(&MouseX,&MouseY,&press);
        input_s(223, 100, &username, 10 , 0);
        input_s(223, 180, &password, 10 , 1);
        input_s(260, 260, &realpassword, 10 , 1);
        input_s(260, 340, &phonenumber, 12 , 0);
        if(mouse_press(120, 420, 280, 460)==1)
        {
            return ;
        }
        if((mouse_press(360, 420, 520, 460)==1)&&
        (username.string[0]!='\0') && (phonenumber.string[0]!='\0') && 
        (password.string[0]!='\0')&&(strcmp(password.string,realpassword.string)==0))
        {
            if (username_same(username.string)==0)
            {
                wr_user(username.string,password.string,phonenumber.string);
                return;
            }
            
        }
        delay(15);
    }
   
    
}