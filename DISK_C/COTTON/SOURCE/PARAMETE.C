#include "TOTAL.H"

void parameter_screen1()
{
    cleardevice();
    setbkcolor(WHITE);
    setfillstyle(1,LIGHTBLUE);


}

void parameter1()
{

    mouseinit();
    for(;;)
	{
		newmouse(&MouseX,&MouseY,&press);
        if(mouse_press(0,0,40,30)==1)
        {
            exit(0);
            return;
            
        }
    }
}
