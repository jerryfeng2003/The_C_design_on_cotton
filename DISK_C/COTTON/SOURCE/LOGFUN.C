#include "TOTAL.H"

//��������
void input_s(int x, int y, INPUT *word, int size, int mode)
{
	if(press == 1)
	{
		if(mouse_press(word->x1,word->y1,word->x2,word->y2)==1)
		{
			word->flag = 1;
			
			clrmous(MouseX,MouseY);
			setcolor(RED);
			setlinestyle(0,0,1);
			rectangle(word->x1,word->y1,word->x2,word->y2);
			setcolor(DARKGRAY);
			line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
		}
		else
		{
			word->flag = 0;
			
			clrmous(MouseX,MouseY);
			setcolor(LIGHTGREEN);
			setlinestyle(0,0,1);
			rectangle(word->x1,word->y1,word->x2,word->y2);
			line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
		}	
	}
	
	//flagΪ1ʱ��ʾ���Խ��ռ�������
	if(word->flag == 1)
	{
		char t;
		
		if(kbhit())
		{
			t = getch();
			
			if(t=='\b')
			{
				if(word->cursor > 0)
				{
					(word->string)[word->cursor-1]='\0';
					(word->cursor)--;
				}
			}
			else if(t>='!' && t<='~')
			{
				if(word->cursor < word->length)
				{
					(word->string)[word->cursor]=t;
					(word->string)[word->cursor+1]='\0';
					(word->cursor)++;
				}
			}
			
			setcolor(DARKGRAY);
			setlinestyle(0,0,1);
			setfillstyle(SOLID_FILL,WHITE);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			settextstyle(SMALL_FONT,HORIZ_DIR,size);
			bar(word->x1+2,word->y1+2,word->x2-2,word->y2-2);
			if(mode == 0)
			{
				setcolor(DARKGRAY);
				outtextxy(x,y,word->string);
				line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
			}
			else
			{
				int i;
				for(i=0;i<word->cursor;i++)
				{
					outtextxy(x+i*(2*size-2),y,"*");
				}
				line(x+(word->cursor)*(2*size-2)+2,y,x+(word->cursor)*(2*size-2)+2,y+2*(2*size-2));
			}
		}
	}
}



//¼��ע���˺ŵ��ļ�
void wr_user(char username1[],char password1[],char phonenumber1[])
{
	FILE *fp;
	user *u = (user*)malloc(sizeof(user));
	int i;
	if((fp=fopen("User.txt","rt+"))==NULL)
	{
		puthz(120,300,"�򿪴���",32,32,BLUE);
		delay(3000);
		return ;
	}
	for(i=0;i<10;i++)
	{
		u->username[i]=username1[i];
		u->password[i]=password1[i];
	}
	for(i=0;i<12;i++)
	{
		u->phonenumber[i]=phonenumber1[i];
	}
	fseek(fp,0,SEEK_END);
	fwrite(u,sizeof(user),1,fp);
	free(u);
	u=NULL;
	if(fclose(fp) != 0)//�ر��ļ�
	{
		puthz(120,300,"�رմ���",32,32,BLUE);
		delay(3000);
		return ;
	}
}

//�ж�ע����˺��Ƿ��Ѿ�����
//return flagΪ1����ڣ�0�򲻴���
int username_same(char username0[])
{
	FILE *fp;
	user *u = (user*)malloc(sizeof(user));
	int i,j,all,flag=0;
	if((fp=fopen("User.txt","rt+"))==NULL)
	{
		puthz(120,300,"�򿪴���",32,32,BLUE);
		delay(3000);
		return ;
	}
	fseek(fp,0,SEEK_END);
	all=ftell(fp)/sizeof(user);
	for(i=0;i<all;i++)
	{
		flag=0;
		fseek(fp,i*sizeof(user),SEEK_SET);
		fread(u,sizeof(user),1,fp);
    
		for(j=0;j<10;j++)//�����˺�λ��
		{
			if(u->username[j]!=username0[j])
			{
				break;
			}
			if(username0[j]=='\0')
			{
				j=10;
				break;
			}
		}
		if (j==10)
		{
			void *buffer;
			unsigned s;
			setfillstyle(1,CYAN);
			s=imagesize(220,100,520,150);
			buffer=malloc(s);
			getimage(220,100,520,150,buffer);
			bar(220,100,520,150);
			puthz(220,100,"ע���˺��Ѵ���",32,32,BLUE);
			delay(2000);
			putimage(220,100,buffer,COPY_PUT);
			flag=1;
		}
		free(u);
		u=NULL;
	}
	if (flag==0)
	{
		void *buffer;
		unsigned s;
		setfillstyle(1,CYAN);
		s=imagesize(220,100,420,150);
		buffer=malloc(s);
		getimage(220,100,420,150,buffer);
		bar(220,100,420,150);
		puthz(220,100,"ע���˺ųɹ�",32,32,BLUE);
		delay(2000);
		putimage(220,100,buffer,COPY_PUT);
	}
	fclose(fp);
	return flag;
}

//��¼���ж��˺��Ƿ����and�����Ƿ���ȷ
int log(char username0[],char password0[],struct user* loguser)
{
	FILE *fp;
	user *u=(user*)malloc(sizeof(user));
	int i,j,k,flag=0,all;

	if((fp=fopen("User.txt","rt+"))==NULL)
	{
		puthz(120,300,"�򿪴���",32,32,BLUE);
		delay(3000);
		return ;
	}
	fseek(fp,0,SEEK_END);
	all=ftell(fp)/sizeof(user);
	for(i=0;i<all;i++)
	{
		
		fseek(fp,i*sizeof(user),SEEK_SET);
		fread(u,sizeof(user),1,fp);
		//outtextxy(100+200*i,180,u->username);
		//outtextxy(100+200*i,280,u->password);

		for(j=0;j<10;j++)//�����˺�λ��
		{
			if(u->username[j]!=username0[j])
			{
				break;
			}
			if(username0[j]=='\0')
			{
				j=10;
				break;
			}
		}
		if(j==10)//����ҵ����˺žͿ�ʼ�ȶ�����
		{
			for(k=0;k<10;k++)
			{
				if(u->password[k]!=password0[k])
				{
					break;
				}
				if(password0[k]=='\0')
				{
					k=10;
					break;
				}
			}
			if(k==10)
			{
				flag=1;
				loguser=u;
				break;
			}
		}
		free(u);
		u=NULL;
	}
	if (flag==0)
	{
		void *buffer;
		unsigned s;
		setfillstyle(1,CYAN);
		s=imagesize(220,100,420,150);
		buffer=malloc(s);
		getimage(220,100,420,150,buffer);
		bar(220,100,420,150);
		puthz(220,100,"��¼ʧ��",32,32,BLUE);
		delay(1000);
		putimage(220,100,buffer,COPY_PUT);
	}
	fclose(fp);
	return flag;
}

int changepassword(char username0[],char newpassword0[],char phonenumber0[])
{
	FILE *fp;
	user *u=(user*)malloc(sizeof(user));
	int i,j,k,flag=0,all;
	
	if((fp=fopen("User.txt","rt+"))==NULL)
	{
		puthz(120,300,"�򿪴���",32,32,BLUE);
		delay(3000);
		return ;
	}
	fseek(fp,0,SEEK_END);
	all=ftell(fp)/sizeof(user);
	for (i=0;i<all;i++)
	{
		fseek(fp,i*sizeof(user),SEEK_SET);
		fread(u,sizeof(user),1,fp);
		for(j=0;j<10;j++)//�����˺�λ��
		{
			
			if(u->username[j]!=username0[j])
			{
				break;
			}
			if(username0[j]=='\0')
			{
				j=10;
				break;
			}
		}
		if (j==10)//�ҵ��˾��жϵ绰����������ȷ
		{
			
			for(j=0;j<12;j++)
			{
				
				if(u->phonenumber[j]!=phonenumber0[j])
				{
					//outtextxy(200,200,u->phonenumber);
					break;
				}
				if(phonenumber0[j]=='\0')
				{
					j=12;
					break;
				}
			}
			if (j==12)//�绰������ȷ�͸�����
			{
				//outtextxy(200,200,u->phonenumber);
				for(k=0;k<10;k++)
				{
					u->password[k]=newpassword0[k];
				}
				fseek(fp,i*sizeof(user),SEEK_SET);
				fwrite(u,sizeof(user),1,fp);
				flag=1;
			}
		}

	}
	if (flag==1)
	{
		setfillstyle(1,CYAN);
		bar(220,100,420,150);
		puthz(220,100,"��������ɹ�",32,32,BLUE);
		delay(2000);
	}
	else
	{
		void *buffer;
		unsigned s;
		setfillstyle(1,CYAN);
		s=imagesize(220,100,420,150);
		buffer=malloc(s);
		getimage(220,100,420,150,buffer);
		bar(220,100,420,150);
		puthz(220,100,"��������ʧ��",32,32,BLUE);
		delay(2000);
		putimage(220,100,buffer,COPY_PUT);
	}

	free(u);
	u=NULL;
	fclose(fp);
	return flag;
}