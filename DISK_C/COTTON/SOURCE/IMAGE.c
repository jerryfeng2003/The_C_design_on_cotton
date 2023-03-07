/***********************

��ͼ��ת�������������Ҫ�������ͼƬ�ֱ�����640*480֮��
����VGAHI���˸�棩
����������Q�ң�1105674202 

***********************/
#include <stdio.h>
#include <dos.h>
#include "image.h"
#include <graphics.h>
#include <conio.h>


/*int bmp_convert(char *bmp,char *dbm)	//�� *.bmp ��Ϊ *.dbm,�ַ���bmp��Ϊbmp���ڵ�ַ����dbmpΪ�����ַ
{
//	static int color[16]={0,4,2,6,1,5,3,7,8,12,10,14,9,13,11,15}; ��win��ps 
	static int color[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};//������bc����ɫ��Ŷ�Ӧת����������win��ͼת����
	unsigned char dbmline[640],bmpline[640],pixel[8],Vbyte;
	int ImageW,ImageH,i,j,k,n,now,bmpcom,gg ;
	long hangsize;
	FILE *fbmp,*fdbm;
	union {
		unsigned char val;
		struct {
			unsigned cl:4;
			unsigned ch:4;
		}color;	//��λ�򴢴���ɫ��Ϣ���ֲ���ɫ��Ϣ 
	}MyColor;
	if((fbmp=fopen(bmp,"rb"))==NULL)
	{
		printf("%s\n",bmp);
		printf("Open bmp error!");
		return 1;
	}
	fseek(fbmp,18,SEEK_SET);	//bmpͼ��Ŀ������ļ�ͷ18�ֽں�
	fread(&gg,4,1,fbmp);
   //	fread(&ImageW,4,1,fbmp);
	fread(&ImageH,4,1,fbmp);
	ImageW=gg;
 //	ImageH*=2;
  //	printf("%d ",ImageW);
  //	printf("%d",ImageH);
	if(ImageW==0||ImageH==0||ImageW>640||ImageH>480)
	{
		printf("The image is too large!Please input image below 640*480.");
		fclose(fbmp);
		return 1;
	}
	if((fdbm=fopen(dbm,"wb"))==NULL)
	{
		printf("Creat \"%s\" error!",dbm);
		return 1;
	}
	bmpcom=(ImageW-1)/8+1;	//�д�����Ԫ��
	hangsize=bmpcom*4;	//ÿ���ֽ�����DIB����Ҫ��ÿ���ֽ�Ϊ4���������Ѽ��㲹�㣩
	fwrite(&ImageW,sizeof(int),1,fdbm);
	fwrite(&ImageH,sizeof(int),1,fdbm);
	fseek(fbmp,-hangsize,SEEK_END);
	for(i=0;i<ImageH;i++)
	{
		now=0;
		fread(bmpline,hangsize,1,fbmp);
		fseek(fbmp,-hangsize*2,SEEK_CUR);
		for(n=3;n>=0;n--)	//ÿ�в���ĸ�λ����������
	  // for(n=0;n<=3;n++)
		{
			for(j=0;j<bmpcom;j++)
			{
				Vbyte=0;
				for(k=0;k<4;k++)
				{
					MyColor.val=bmpline[j*4+k];
					pixel[k*2]=color[MyColor.color.ch];
					pixel[k*2+1]=color[MyColor.color.cl];
				}
				for(k=0;k<8;k++)
				{
					Vbyte+=(pixel[k]>>n&1)<<(7-k);
				}
				dbmline[now++]=Vbyte;
			}
		}
		fwrite(dbmline,hangsize,1,fdbm);
	}
	fclose(fdbm);
	fclose(fbmp);
	return 0;
}*/

int show_dbm(int x,int y,char *dbm)	//����dbmp��·��,��(x,y)���ͼƬ(x��Ϊ8�ı���)
{					
	int ImageW,ImageH,n,i,j;
	long hangsize;
	FILE * fdbm;
	char far * per;
	
	per=(char far *)0xA0000000L;

	
//	_VideoBusy=YES;			//hanenvϵͳ�ڵ���ʾ�Ĵ����������� 
	
	if((fdbm=fopen(dbm,"rb"))==NULL)
	{
		printf("%s",dbm);
		getchar();
		printf("Open Error!");
		return 1;
	}
	fread(&ImageW,sizeof(int),1,fdbm);
	fread(&ImageH,sizeof(int),1,fdbm);
  //	printf("%d %d",ImageW,ImageH);
	hangsize=(ImageW-1)/8;
	per=per+x/8+y*80;
	if((ImageH+y)>480)	ImageH=480-y; 	//VGAHI  640*480 
	for(i=0;i<ImageH;i++)
	{
		for(n=8;n>=1;n>>=1)	//�ӵ���λ��ɫƽ��д����0
		{
			outportb(0x3c4,2);
			outportb(0x3c5,n);
			fread(per,hangsize,1,fdbm);
			fseek(fdbm,1,SEEK_CUR);
		}
	   //	fseek(fdbm,hangsize*2,SEEK_CUR);
		per+=80;
	}
	fclose(fdbm);
	
//	_VideoBusy=NO;	
	
	outportb(0x3c5,0xf);
	return 0;
}

void cir_bar(int x1,int y1,int x2,int y2,int color)	//��ָ��λ�û���һ��Բ�Ǿ��ο� 
{
	int w=x2-x1,h=y2-y1;
	setcolor(color);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    ellipse(5+x1,10+y1,90,180,5,10);
    line(0+x1,10+y1,0+x1,10+h-20+y1);
    ellipse(5+x1,10+h-20+y1,180,270,5,10);
    line(5+x1,0+y1,5+w-10+x1,0+y1);
    ellipse(5+w-10+x1+1,10+y1,0,90,5,10);
    line(w+x1,10+y1,w+x1,y2-10);
    ellipse(w-5+x1+1,10+h-20+y1,270,360,5,10);
    line(5+x1,h+y1,5+w-10+x1,h+y1);
}

void movetopage(int x1, int y1, int x2, int y2,int page1 ,int page2)	//��ʾҳ��ֲ�ͼ�����ݴ��䣬�������Ͻ����꼰���Ͻ����꣬��page1�ƶ���page2
{	
	int per1, per2;
	int hangsize = (x2 - x1) / 8;
	int high = y2 - y1 + 1;
	register int i, p1, p2;
	if (page1 == 0)
	{
		per2 = 0xA0000000L;
		per1 = 0xA8000000L;
	}
	else
	{
		per1 = 0xA0000000L;
		per2 = 0xA8000000L;
	}
	
	

	per1 = per1 + (x1) / 8 + (y1 ) * 80;
	per2 = per2 + (x1) / 8 + (y1 ) * 80;
	for (i = 0; i <high; i++)		//������Ƶͼ�� 
	{
		for (p1 = 8, p2 = 3; p1 >= 1; p1 >>= 1, p2--)	//�ӵ���λ��ɫƽ��д����0
		{
			outportb(0x3c4, 2);		//��ɫλ��д�Ĵ��� 
			outportb(0x3c5, p1);
			outportb(0x3ce, 4);		//��ɫλ����Ĵ��� 
			outportb(0x3cf, p2);
			if (page1 == 0)
			{
				quick_move_2(per2, per1, hangsize);
			}
			else
			{
				quick_move_1(per2, per1, hangsize);
			}
		}
		per1 += 80;
		per2 += 80;
	}
	outportb(0x3cf,0);		//�ָ����� 
	outportb(0x3c5,0xf);
}

void set_color(int color_no,int red,int green,int blue)	//ָ����ɫ��ţ��޸����Ӧ��rgbֵ 
{
	if(color_no<16)
	{
		_AX=0x1007;	//ѡ��10H��ʾ�ж��еĵ�7�Ź���
		_BL=color_no;
		geninterrupt(0x10);
		color_no=_BH; 
	}
	else
		color_no = 0xff;	//����Ļ��Եɫָ���ɫ��255 
		
	//�޸ĵ�ɫ��Ĵ��� 
	_DH=red;
	_CH=green;
	_CL=blue;
	_BX=color_no;
	_AX=0x1010;
	geninterrupt(0x10);
	
	//������Ļ��Ե��ɫ
	if(color_no==0xff)
	{
		_BH=0xff;
		_AX=0x1001;
		geninterrupt(0x10);
	} 
}

/*��Ϊ�û���д��֧�ֿ��Ѱַ�����ݴ��亯�������ԡ�VGAҳ��ͼ�������ƶ�������������ʾЧ���е�Ӧ�á�һ��*/
int quick_move_1(int Start,int End,int Size)	//StartΪԭ���׵�ַ��EndΪĿ��λ���׵�ַ 	(1 to 0)
{
	asm{
		push es
		push ds
		push di
		push si
		push ax
		push cx
		push dx
		mov ax,0a800h
		mov ds,ax
		mov ax,Start
		mov si,ax
		mov ax,0a000h
		mov es,ax
		mov ax,End
		mov di,ax
		mov cx,Size
		rep movsb
		pop dx
		pop cx
		pop ax
		pop si
		pop di
		pop ds
		pop es
	}
	return 0;
}

int quick_move_2(int Start,int End,int Size)	//StartΪԭ���׵�ַ��EndΪĿ��λ���׵�ַ 	(0 to 1)
{
	asm{
		push es
		push ds
		push di
		push si
		push ax
		push cx
		push dx
		mov ax,0a000h
		mov ds,ax
		mov ax,Start
		mov si,ax
		mov ax,0a800h
		mov es,ax
		mov ax,End
		mov di,ax
		mov cx,Size
		rep movsb
		pop dx
		pop cx
		pop ax
		pop si
		pop di
		pop ds
		pop es
	}
	return 0;
}

void close_display()	//�ر���Ļ��ʾ
{
	_BL=0x32;
	_AH=0x12;
	_AL=0x01;
	geninterrupt(0x10);
}

void open_display()		//����Ļ��ʾ
{
	_BL=0x32;
	_AH=0x12;
	_AL=0x00;
	geninterrupt(0x10);
} 
