#include "COMMON.H"
#include "LOGFUN.H"
#include "LOGIN.H"
#include "PARAMETE.H"
#include "START.H"
#include "HOME.H"
#include "HELP.H"
#include "EDIT.H"
#include "WELCOME.H"
#include "PAST.H"
struct User *h;//登录的用户
int mode=0;
int mode1=0;

void main()
{
    int gd=VGA,gm=VGAHI,i=0;
	h=(user*)malloc(sizeof(user));//登录的用户
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
    loginit();
    for(i=0;i<5;i++)
    {
        char s[10]="ware0";
        s[5]='0'+i+1;
        strcpy(h->here[i].ware_name,s);
    }
    while(1)
    {
        int pre_mode=mode,pre_mode1=mode1;
        switch (mode)
        {
            case 0:  //the welcome page
            {
                draw_wel();
                break;
            }

            case 1: //the home page
            {

                switch(mode1)
                {
                    case -1:
                    {
                        // draw_home01();
                        mode1=0;
                        break;
                    }
                    case 0: //the home main page
                    {
                        draw_home01();
                        break;
                    }
                    case 1: //the warehouse list page
                    {
                        warehouse_list(h->here);
                        break;
                    }
                    case 2: //the detailed warehouse page
                    {
                        detailed_warehouse(h->here[k].total[(h->here[k].cotton_type)]);
                        break;
                    }
                    case 3: //the export cotton page
                    {
                        out_warehouse();
                        break;
                    }
                }
                break;
            }
            case 2: //the edit page
            {
                edit();
                pre_mode=2;
                mode=2;
                break;
            }

            case 3: // the start page
            {
                start();
                pre_mode=3;
                // mode=3;
                break;
            }

            case 4: //the past page
            {
                past(); 
                pre_mode=4;
                mode=4;  
                break;
            }

            case 5:  //the help page
            {
                help();
                break;
            }
            
            default:
                break;
        }
        while(pre_mode==mode&&pre_mode1==mode1)
        {
            newmouse(&MouseX,&MouseY,&press);
            switch (mode)
            {
                case 0:  //the welcome page
                {
                    enter_next();
                    break;
                }

                case 1: //the home page
                {
                    switch(mode1)
                    {
                        case -1: //refresh the home main page
                        {
                            clrmous(MouseX,MouseY);
                            // press_home(&(here[k].cotton_type));
                            mode1=0;
                            break;
                        }
                        case 0: //the home main page
                        {
                            press_home(&(h->here[k].cotton_type));
                            break;
                        }
                        case 1: //the warehouse list page
                        {
                            int re=0;
                            press_warelist(&re);
                            break;
                        }
                        case 2: //the detailed warehouse page
                        {
                            press_detwarehouse();
                            break;
                        }
                        case 3: //the export cotton page
                        {
                            press_outware();
                            break;
                        }
                    }
                    break;
                }
                case 2: //the edit page
                {
                    cleardevice();
                    mode=0;
                    break;
                }

                case 3: // the start page
                {
                    cleardevice();
                    mode=0;
                    break;
                }

                case 4: //the past page
                {
                    cleardevice();
                    mode=0;
                    break;
                }

                case 5:  //the help page
                {
                    cleardevice();
                    mode=0;
                    break;
                }            
                default:
                    break;
            }
            delay(20);
        }
    }
}

