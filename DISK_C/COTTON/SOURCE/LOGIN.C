#include "TOTAL.H"


void loginit_screen()
{
    cleardevice();
    setbkcolor(WHITE);
    puthz(180,30,"ÃŞ»¨²ÉÕªÄ£ÄâÏµÍ³",32,32,BLUE);
    quit();//ÍË³ö

    //¿ò
    setcolor(BLUE);
    setfillstyle(1,LIGHTGRAY);
    //rectangle(123, 103, 523, 153);
    bar(120, 100, 220, 160);            //ÕËºÅ
    //rectangle(123, 203, 523, 253);
    bar(120, 200, 220, 260);            //ÃÜÂë

    setfillstyle(1,LIGHTGREEN);
    bar(220, 100, 520, 160);  
    bar(220, 200, 520, 260);   

    bar(280, 300, 360, 340);            //µÇÂ¼

    setfillstyle(1,DARKGRAY);
    bar(120, 350, 280, 400);            //Íü¼ÇÃÜÂë
    bar(360, 350, 520, 400);            //×¢²áÕËºÅ
          
    puthz(123,110,"ÕËºÅ£º",32,32,BLUE);
    puthz(123,210,"ÃÜÂë£º",32,32,BLUE);
    puthz(130,360,"Íü¼ÇÃÜÂë",32,32,WHITE);
    puthz(370,360,"×¢²áÕËºÅ",32,32,WHITE);
    puthz(285,305,"µÇÂ¼",32,32,BLUE);


    //¿ìËÙµÇÂ¼
    bar(380, 300, 550, 340); 
    puthz(383, 300,"¿ìËÙµÇÂ¼",32,32,RED);
}

int logenter()
{
    //ÍË³ö
    if(mouse_press(0,0,40,30)==1)
	{
		exit(0);
        return 0;
        
	}
    //µÇÂ¼
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