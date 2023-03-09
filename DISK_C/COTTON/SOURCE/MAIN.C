#include "TOTAL.H"

int main()
{
    int gd=VGA,gm=VGAHI; 
	initgraph(&gd,&gm,"..\\borlandc\\bgi");
	draw_wel();
	return 0;
}

void quit(void)
{
    setfillstyle(1,LIGHTBLUE);
    bar(0,0,40,30);
	puthz(3,10,"ÍË³ö",16,16,WHITE);
}