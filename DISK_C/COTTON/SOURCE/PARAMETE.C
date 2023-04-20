#include "TOTAL.H"
// 专门用来写有关edit和past的函数

// 键盘输入   mode为0输出文字，mode为1输出*
int input_s(int x, int y, INPUT *word, int size, int mode)
{
    static int p = 0; // 画一个框
    int k = 0;        // 判断是否输出文字
    settextjustify(0, 2);
    if (p == 0)
    {
        setcolor(BLUE);
        rectangle(word->x1, word->y1, word->x2, word->y2);
        setfillstyle(1, 0);
        bar(word->x1 + 2, word->y1 + 2, word->x2 - 2, word->y2 - 2);
        p = 1;
    }
    if (press == 1)
    {
        if (mouse_press(word->x1, word->y1, word->x2, word->y2) == 1)
        {
            word->flag = 1;

            clrmous(MouseX, MouseY);
            setcolor(RED);
            setlinestyle(0, 0, 1);
            rectangle(word->x1, word->y1, word->x2, word->y2);
            setcolor(DARKGRAY);
            k = 1;
        }
        else
        {
            word->flag = 0;

            clrmous(MouseX, MouseY);
            setcolor(BLUE);
            setlinestyle(0, 0, 1);
            rectangle(word->x1, word->y1, word->x2, word->y2);
            // 不可输入则把光标遮蔽掉
            if (mode == 0)
            {
                setfillstyle(1, 0);
                bar(word->x1 + 2, word->y1 + 2, word->x2 - 2, word->y2 - 2);
                setcolor(DARKGRAY);
                outtextxy(x, y, word->string);
            }
            else
            {
                int i;
                setfillstyle(1, 0);
                bar(word->x1 + 2, word->y1 + 2, word->x2 - 2, word->y2 - 2);
                for (i = 0; i < word->cursor; i++)
                {
                    outtextxy(x + i * (2 * size - 2), y, "*");
                }
                setcolor(DARKGRAY);
            }
        }
    }

    // flag为1时表示可以接收键盘输入
    if (word->flag == 1)
    {
        char t;

        if (kbhit())
        {
            t = getch();

            if (t == '\b')
            {
                if (word->cursor > 0)
                {
                    (word->string)[word->cursor - 1] = '\0';
                    (word->cursor)--;
                    k = 1;
                }
            }
            else if (t >= '!' && t <= '~')
            {
                if (word->cursor < word->length)
                {
                    (word->string)[word->cursor] = t;
                    (word->string)[word->cursor + 1] = '\0';
                    (word->cursor)++;
                    k = 1;
                }
                else
                {
                    return 1;
                }
            }
        }
        if (k == 1)
        {
            setcolor(DARKGRAY);
            setlinestyle(0, 0, 1);
            setfillstyle(SOLID_FILL, WHITE);
            settextjustify(LEFT_TEXT, TOP_TEXT);
            settextstyle(SMALL_FONT, HORIZ_DIR, size);
            bar(word->x1 + 2, word->y1 + 2, word->x2 - 2, word->y2 - 2);
            if (mode == 0)
            {
                setcolor(DARKGRAY);
                outtextxy(x, y, word->string);
                line(x + (word->cursor) * (2 * size - 8) + 2, word->y1 + 3, x + (word->cursor) * (2 * size - 8) + 2, word->y2 - 3);
            }
            else
            {
                int i;
                for (i = 0; i < word->cursor; i++)
                {
                    outtextxy(x + i * (2 * size - 2), y, "*");
                }
                setcolor(DARKGRAY);
                line(x + (word->cursor) * (2 * size - 2) + 2, word->y1 + 3, x + (word->cursor) * (2 * size - 2) + 2, word->y2 - 3);
            }
        }
    }
    return 0;
}

int judgename(char name[])
{
    static int i, j;
    if (name[0] == '\0')
    {
        void *buffer;
        unsigned s;
        setfillstyle(1, CYAN);
        bar(240, 30, 470, 70);
        puthz(242, 33, "参数名不能为空", 32, 32, BLUE);
        delay(1000);
        setfillstyle(1, 0);
        bar(240, 30, 470, 70);
        puthz(240, 30, "请选择地区", 32, 32, BLUE);
        return 0;
    }
    for (i = 0; i < h->lenpar; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (name[j] != (h->parameter[i]).name[j])
            {
                break;
            }
            if (name[j] == '\0')
            {
                j = 10;
                break;
            }
        }
        if (j == 10)
        {
            setfillstyle(1, CYAN);
            bar(240, 30, 470, 70);
            puthz(242, 33, "参数名已经存在", 32, 32, BLUE);
            delay(1000);
            setfillstyle(1, 0);
            bar(240, 30, 470, 70);
            puthz(240, 30, "请选择地区", 32, 32, BLUE);

            return 0;
        }
    }
    return 1;
}

int judgeS(char S[])
{
    int i = 0;
    if (S[0] == '\0')
    {
        setfillstyle(1, CYAN);
        bar(80, 100, 380, 140);
        puthz(83, 100, "土地面积不能为空", 32, 32, BLUE);
        delay(1000);
        setfillstyle(1, 0);
        bar(80, 100, 380, 140);
        puthz(70, 100, "本地推荐种植的棉花种类为：", 32, 32, BLUE);
        return 0;
    }
    for (i = 0; i < strlen(S); i++)
    {
        if (S[i] > '9' || S[i] < '0')
        {
            setfillstyle(1, CYAN);
            bar(80, 100, 340, 140);
            puthz(83, 100, "请输入数字", 32, 32, BLUE);
            delay(1000);
            setfillstyle(1, 0);
            bar(80, 100, 340, 140);
            puthz(70, 100, "本地推荐种植的棉花种类为：", 32, 32, BLUE);
            return 0;
        }
    }
    if (S[0] == '0')
    {
        setfillstyle(1, CYAN);
        bar(80, 100, 380, 140);
        puthz(83, 100, "土地面积不能为零", 32, 32, BLUE);
        delay(1000);
        setfillstyle(1, 0);
        bar(80, 100, 380, 140);
        puthz(70, 100, "本地推荐种植的棉花种类为：", 32, 32, BLUE);
        return 0;
    }
    return 1;
}

void wr_parameter(struct Parameter *abc)
{
    FILE *fp;
    user *u = (user *)malloc(sizeof(user));
    int i, j, k, all;
    if ((fp = fopen("User.dat", "rb+")) == NULL)
    {
        puthz(120, 300, "打开错误", 32, 32, BLUE);
        delay(3000);
        return;
    }
    fseek(fp, 0, SEEK_END);
    all = ftell(fp) / sizeof(user); // 文件里user的数量
    for (i = 0; i < all; i++)
    {
        fseek(fp, i * sizeof(user), SEEK_SET);
        fread(u, sizeof(user), 1, fp);
        for (j = 0; j < 10; j++) // 查找账号位置
        {

            if (u->username[j] != h->username[j])
            {
                break;
            }
            if (h->username[j] == '\0')
            {
                j = 10;
                break;
            }
        }
        if (j == 10) // 找到了就修改参数
        {
            // strcpy(h->parameter[h->lenpar].name,abc->name);
            for (k = 0; k < 10; k++)
            {
                h->parameter[h->lenpar].name[k] = abc->name[k];
            }
            h->parameter[h->lenpar].place = abc->place;
            h->parameter[h->lenpar].shape = abc->shape;
            h->parameter[h->lenpar].type = abc->type;
            strcpy(h->parameter[h->lenpar].S, abc->S);
            for (k = 0; k < dense_points_max; k++)
            {
                h->parameter[h->lenpar].x[k] = abc->x[k];
                h->parameter[h->lenpar].y[k] = abc->y[k];
            }
            h->parameter[h->lenpar].lenxy = abc->lenxy;
            h->lenpar += 1;
            fseek(fp, i * sizeof(user), SEEK_SET);
            fwrite(h, sizeof(user), 1, fp);
            puthz(220, 100, "增加参数成功", 32, 32, BLUE);
            delay(2000);
        }
    }
    // char name[10];//名字
    // char place;//产区
    // char shape;//土地形状
    // char type;//收割机类型
    // int S;//面积
    // int xyz[200];//坐标

    free(u);
    u = NULL;
    if (fclose(fp) != 0) // 关闭文件
    {
        puthz(120, 300, "关闭错误", 32, 32, BLUE);
        delay(3000);
        return;
    }
    return;
}

// 把当前登录的用户重新写进文件
void wr_h(void)
{
    FILE *fp;
    user *u = (user *)malloc(sizeof(user));
    int i, j, k, all;
    if ((fp = fopen("User.dat", "rb+")) == NULL)
    {
        puthz(120, 300, "打开错误", 32, 32, BLUE);
        delay(3000);
        return;
    }
    fseek(fp, 0, SEEK_END);
    all = ftell(fp) / sizeof(user); // 文件里user的数量
    for (i = 0; i < all; i++)
    {
        fseek(fp, i * sizeof(user), SEEK_SET);
        fread(u, sizeof(user), 1, fp);
        for (j = 0; j < 10; j++)
        {

            if (u->username[j] != h->username[j])
            {
                break;
            }
            if (h->username[j] == '\0')
            {
                j = 10;
                break;
            }
        }
        if (j == 10) // 找到了就把h传进去
        {
            fseek(fp, i * sizeof(user), SEEK_SET);
            fwrite(h, sizeof(user), 1, fp);
        }
    }

    free(u);
    u = NULL;
    if (fclose(fp) != 0) // 关闭文件
    {
        puthz(120, 300, "关闭错误", 32, 32, BLUE);
        delay(3000);
        return;
    }
    return;
}

// 删除参数
void deletepar(int par)
{
    int i, j, k;
    par -= 1;
    for (i = par; i < h->lenpar; i++)
    {
        parcpy(&(h->parameter[par]), &(h->parameter[par + 1]));
    }
    h->lenpar -= 1;
    wr_h();
}

// 下面四个返回1为修改成功，返回-1为无修改

// 修改产区
int changeplace(int par)
{
    char choose;
    clrmous(MouseX, MouseY);
    setfillstyle(1, BROWN);
    bar(100, 130, 540, 370);
    puthz(220, 150, "请重新选择产区", 32, 32, BLUE);
    setfillstyle(1, CYAN);
    bar(150, 290, 240, 340);
    puthz(153, 293, "返回", 32, 32, BLUE);
    bar(400, 290, 490, 340);
    puthz(403, 293, "确认", 32, 32, BLUE);

    setfillstyle(1, LIGHTRED);
    bar(305, 240, 335, 270);
    puthz(300, 200, "长江", 16, 16, BLUE);
    bar(180, 240, 210, 270);
    puthz(175, 200, "新疆", 16, 16, BLUE);
    bar(430, 240, 460, 270);
    puthz(425, 200, "黄河", 16, 16, BLUE);

    quit();

    for (;;)
    {
        delay(15);
        newmouse(&MouseX, &MouseY, &press);

        if (mouse_press(305, 240, 335, 270) == 1) // 长江
        {
            clrmous(MouseX, MouseY);
            choose = 'c';
            setfillstyle(1, BROWN);
            bar(180, 240, 460, 270);
            setfillstyle(1, BLUE);
            bar(305, 240, 335, 270);
            setfillstyle(1, LIGHTRED);
            bar(180, 240, 210, 270);
            bar(430, 240, 460, 270);
        }
        if (mouse_press(180, 240, 210, 270) == 1) // 新疆
        {
            clrmous(MouseX, MouseY);
            choose = 'a';
            setfillstyle(1, BROWN);
            bar(180, 240, 460, 270);
            setfillstyle(1, BLUE);
            bar(180, 240, 210, 270);
            setfillstyle(1, LIGHTRED);
            bar(305, 240, 335, 270);
            bar(430, 240, 460, 270);
        }
        if (mouse_press(430, 240, 460, 270) == 1) // 黄河
        {
            clrmous(MouseX, MouseY);
            choose = 'b';
            setfillstyle(1, BROWN);
            bar(180, 240, 460, 270);
            setfillstyle(1, BLUE);
            bar(430, 240, 460, 270);
            setfillstyle(1, LIGHTRED);
            bar(180, 240, 210, 270);
            bar(305, 240, 335, 270);
        }

        if (mouse_press(150, 290, 240, 340) == 1) // 返回
        {
            return -1;
        }
        if (mouse_press(400, 290, 490, 340) == 1) // 确认
        {
            h->parameter[par - 1].place = choose;
            wr_h();
            return 1;
        }
    }
}

// 修改土地形状
int changeshape(int par)
{
    char choose;
    clrmous(MouseX, MouseY);
    setfillstyle(1, BROWN);
    bar(100, 130, 540, 370);
    puthz(200, 150, "请重新选择土地形状", 32, 32, BLUE);
    setfillstyle(1, CYAN);
    bar(150, 290, 240, 340);
    puthz(153, 293, "返回", 32, 32, BLUE);
    bar(400, 290, 490, 340);
    puthz(403, 293, "确认", 32, 32, BLUE);

    setfillstyle(1, YELLOW);
    pieslice(170, 240, 0, 360, 20);
    puthz(155, 195, "矩形", 16, 16, BLUE);
    pieslice(270, 240, 0, 360, 20);
    puthz(255, 195, "圆形", 16, 16, BLUE);
    pieslice(370, 240, 0, 360, 20);
    puthz(340, 195, "多边形", 16, 16, BLUE);
    pieslice(470, 240, 0, 360, 20);
    puthz(425, 195, "自定义图形", 16, 16, BLUE);

    for (;;)
    {
        delay(15);
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(150, 220, 190, 360) == 1) // 矩形
        {
            clrmous(MouseX, MouseY);
            choose = 'a';
            setfillstyle(1, BROWN);
            bar(150, 220, 490, 260);
            setfillstyle(1, YELLOW);
            pieslice(270, 240, 0, 360, 20);
            pieslice(370, 240, 0, 360, 20);
            pieslice(470, 240, 0, 360, 20);
            setfillstyle(1, BLUE);
            pieslice(170, 240, 0, 360, 20);
        }
        if (mouse_press(250, 220, 290, 360) == 1) // 圆形
        {
            clrmous(MouseX, MouseY);
            choose = 'b';
            setfillstyle(1, BROWN);
            bar(150, 220, 490, 260);
            setfillstyle(1, YELLOW);
            pieslice(170, 240, 0, 360, 20);
            pieslice(370, 240, 0, 360, 20);
            pieslice(470, 240, 0, 360, 20);
            setfillstyle(1, BLUE);
            pieslice(270, 240, 0, 360, 20);
        }
        if (mouse_press(350, 220, 390, 360) == 1) // 多边形
        {
            clrmous(MouseX, MouseY);
            choose = 'c';
            setfillstyle(1, BROWN);
            bar(150, 220, 490, 260);
            setfillstyle(1, YELLOW);
            pieslice(270, 240, 0, 360, 20);
            pieslice(170, 240, 0, 360, 20);
            pieslice(470, 240, 0, 360, 20);
            setfillstyle(1, BLUE);
            pieslice(370, 240, 0, 360, 20);
        }
        if (mouse_press(450, 220, 490, 360) == 1) // 自定义图形
        {
            clrmous(MouseX, MouseY);
            choose = 'd';
            setfillstyle(1, BROWN);
            bar(150, 220, 490, 260);
            setfillstyle(1, YELLOW);
            pieslice(270, 240, 0, 360, 20);
            pieslice(370, 240, 0, 360, 20);
            pieslice(170, 240, 0, 360, 20);
            setfillstyle(1, BLUE);
            pieslice(470, 240, 0, 360, 20);
        }
        if (mouse_press(150, 290, 240, 340) == 1) // 返回
        {
            return -1;
        }
        if (mouse_press(400, 290, 490, 340) == 1) // 确认
        {
            if (choose == 'c')
            {
                select02(&(h->parameter[par - 1]));
            }
            else if (choose == 'd')
            {
                select03(&(h->parameter[par - 1]));
            }
            h->parameter[par - 1].shape = choose;
            wr_h();
            return 1;
        }
    }
}

// 修改收割机类型
int changetype(int par)
{
    char choose;
    clrmous(MouseX, MouseY);
    setfillstyle(1, BROWN);
    bar(100, 130, 540, 370);
    puthz(220, 150, "请重新选择产区", 32, 32, BLUE);
    setfillstyle(1, CYAN);
    bar(150, 290, 240, 340);
    puthz(153, 293, "返回", 32, 32, BLUE);
    bar(400, 290, 490, 340);
    puthz(403, 293, "确认", 32, 32, BLUE);

    setfillstyle(1, YELLOW);
    pieslice(200, 240, 0, 360, 20);
    puthz(175, 195, "垂直式", 16, 16, BLUE);
    pieslice(440, 240, 0, 360, 20);
    puthz(415, 195, "水平式", 16, 16, BLUE);

    for (;;)
    {
        delay(15);
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(180, 220, 220, 260) == 1) // 垂直式
        {
            clrmous(MouseX, MouseY);
            choose = 'a';
            setfillstyle(1, BROWN);
            bar(180, 220, 460, 260);
            setfillstyle(1, YELLOW);
            pieslice(440, 240, 0, 360, 20);
            setfillstyle(1, BLUE);
            pieslice(200, 240, 0, 360, 20);
        }
        if (mouse_press(420, 220, 460, 260) == 1) // 水平式
        {
            clrmous(MouseX, MouseY);
            choose = 'b';
            setfillstyle(1, BROWN);
            bar(180, 220, 460, 260);
            setfillstyle(1, YELLOW);
            pieslice(200, 240, 0, 360, 20);
            setfillstyle(1, BLUE);
            pieslice(440, 240, 0, 360, 20);
        }
        if (mouse_press(150, 290, 240, 340) == 1) // 返回
        {
            return -1;
        }
        if (mouse_press(400, 290, 490, 340) == 1) // 确认
        {
            h->parameter[par - 1].type = choose;
            wr_h();
            return 1;
        }
    }
}

// 修改面积
int changeS(int par)
{
    INPUT S = {245, 220, 445, 260, "", 6, 0, 0};
    clrmous(MouseX, MouseY);
    setfillstyle(1, BROWN);
    bar(100, 130, 540, 370);
    puthz(220, 150, "请重新输入面积", 32, 32, BLUE);
    setfillstyle(1, CYAN);
    bar(150, 290, 240, 340);
    puthz(153, 293, "返回", 32, 32, BLUE);
    bar(400, 290, 490, 340);
    puthz(403, 293, "确认", 32, 32, BLUE);
    puthz(170, 220, "面积：", 32, 32, BLUE);
    setfillstyle(1, 0);
    bar(245, 220, 445, 260);

    for (;;)
    {
        delay(15);
        newmouse(&MouseX, &MouseY, &press);
        input_s(248, 220, &S, 16, 0);

        if (mouse_press(150, 290, 240, 340) == 1) // 返回
        {
            return -1;
        }
        if (mouse_press(400, 290, 490, 340) == 1) // 确认
        {
            strcpy(h->parameter[par - 1].S, S.string);
            wr_h();
            return 1;
        }
    }
}

void parcpy(struct Parameter *a, struct Parameter *b)
{
    int k;
    for (k = 0; k < 10; k++)
    {
        a->name[k] = b->name[k];
    }
    a->place = b->place;
    a->shape = b->shape;
    a->type = b->type;
    strcpy(a->S, b->S);
    for (k = 0; k < dense_points_max; k++)
    {
        a->x[k] = b->x[k];
        a->y[k] = b->y[k];
    }
    a->lenxy = b->lenxy;
}

int choosepar(void)
{
    int i, j, flag = 1;
    char page[3] = {'1', '/', '1'};
    int barcolor[11] = {1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14};
    clrmous(MouseX, MouseY);
    delay(200);
    cleardevice();
    setbkcolor(WHITE);
    puthz(240, 30, "请选择参数", 32, 32, BLUE);
    quit();
    last();
    delay(15);

    setfillstyle(1, LIGHTGRAY);
    bar(50, 80, 590, 420);
    settextstyle(0, 0, 2);
    settextjustify(1, 1);

    page[3] = '\0';
    for (i = 0; i < 10; i++)
    {
        char a[1];
        a[1] = '\0';
        if ((h->lenpar / 4) == i)
        {
            itoa(i, a, 10);
            page[2] = a[0];
            if ((h->lenpar % 4) != 0)
            {
                itoa(i + 1, a, 10);
                page[2] = a[0];
            }
        }
    }
    for (;;)
    {
        int pagepar;
        char page2[1];
        page2[1] = '\0';
        page2[0] = page[0];
        pagepar = atoi(page2) - 1;
        newmouse(&MouseX, &MouseY, &press);

        if (flag == 1)
        {
            if (h->lenpar == 0)
            {
                setfillstyle(1, LIGHTGRAY);
                bar(50, 80, 590, 420);
                settextjustify(1, 1);
                settextstyle(0, 0, 4);
                setcolor(RED);
                outtextxy(320, 250, "No Parameter");
                flag = 0;
            }
            else
            {
                setfillstyle(1, LIGHTGRAY);
                bar(50, 80, 590, 420);
                settextstyle(0, 0, 2);
                outtextxy(320, 405, page);
                outtextxy(280, 405, "<<");
                outtextxy(360, 405, ">>");
                settextstyle(0, 0, 3);
                setcolor(DARKGRAY);

                for (i = 0, j = pagepar * 4; i < (4 > ((h->lenpar) - (pagepar * 4)) ? ((h->lenpar) - (pagepar * 4)) : 4); i++, j++)
                {
                    setfillstyle(1, barcolor[rand() % 12]);
                    bar(90, 150 + 60 * i, 300, 150 + 40 + 60 * i);
                    outtextxy(195, 170 + 60 * i, h->parameter[j].name);
                }

                for (i = 0; i < (4 > ((h->lenpar) - (pagepar * 4)) ? ((h->lenpar) - (pagepar * 4)) : 4); i++)
                {
                    setfillstyle(1, 14);
                    bar(460, 150 + 60 * i, 520, 150 + 40 + 60 * i);
                    puthz(470, 160 + 60 * i, "选择", 16, 16, BLUE);
                }
                flag = 0;
            }
        }
        if (mouse_press(260, 395, 310, 415) == 1)
        {
            if (page[0] > '1')
            {
                page[0] -= 1;
                flag = 1;
                delay(100);
            }
            else
            {
                setfillstyle(1, CYAN);
                bar(230, 30, 450, 80);
                puthz(240, 30, "第一页啦", 32, 32, BLUE);
                delay(300);
                setfillstyle(1, 0);
                bar(230, 30, 450, 80);
                puthz(240, 30, "参数列表", 32, 32, BLUE);
            }
        }
        // page next
        if (mouse_press(330, 395, 380, 415) == 1)
        {
            if (page[0] < page[2])
            {
                page[0] += 1;
                flag = 1;
                delay(100);
            }
            else if (page[0] == page[2])
            {
                setfillstyle(1, CYAN);
                bar(230, 30, 450, 80);
                puthz(240, 30, "最后一页啦", 32, 32, BLUE);
                delay(300);
                setfillstyle(1, 0);
                bar(230, 30, 450, 80);
                puthz(240, 30, "参数列表", 32, 32, BLUE);
            }
        }

        // 四个选择按钮
        if ((mouse_press(460, 150 + 60 * 0, 520, 150 + 40 + 60 * 0) == 1) && ((h->lenpar - (pagepar * 4)) > 0))
        {
            int pagepar;
            char page2[1];
            page2[1] = '\0';
            page2[0] = page[0];
            pagepar = atoi(page2) - 1;

            clrmous(MouseX, MouseY);
            return (pagepar)*4 + 1;
        }
        if ((mouse_press(460, 150 + 60 * 1, 520, 150 + 40 + 60 * 1) == 1) && ((h->lenpar - (pagepar * 4)) > 1))
        {
            int pagepar;
            char page2[1];
            page2[1] = '\0';
            page2[0] = page[0];
            pagepar = atoi(page2) - 1;
            clrmous(MouseX, MouseY);

            return (pagepar)*4 + 2;
        }
        if ((mouse_press(460, 150 + 60 * 2, 520, 150 + 40 + 60 * 2) == 1) && ((h->lenpar - (pagepar * 4)) > 2))
        {
            int pagepar;
            char page2[1];
            page2[1] = '\0';
            page2[0] = page[0];
            pagepar = atoi(page2) - 1;
            clrmous(MouseX, MouseY);

            return (pagepar)*4 + 3;
        }
        if ((mouse_press(460, 150 + 60 * 3, 520, 150 + 40 + 60 * 3) == 1) && ((h->lenpar - (pagepar * 4)) > 3))
        {
            int pagepar;
            char page2[1];
            page2[1] = '\0';
            page2[0] = page[0];
            pagepar = atoi(page2) - 1;
            clrmous(MouseX, MouseY);

            return (pagepar)*4 + 4;
        }

        // enter
        if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(0, 450, 40, 480) == 0 || mouse_press(260, 395, 310, 415) == 0 || mouse_press(330, 395, 380, 415) == 0 || mouse_press(510, 80, 580, 125) == 0)
        {
            MouseS = 0;
        }
        if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(0, 450, 40, 480) == 2 || mouse_press(260, 395, 310, 415) == 2 || mouse_press(330, 395, 380, 415) == 2 || mouse_press(510, 80, 580, 125) == 2)
        {
            MouseS = 1;
        }
        // quit
        if (mouse_press(0, 0, 40, 30) == 1)
        {
            exit(0);
        }
        // last
        if (mouse_press(0, 450, 40, 480) == 1)
        {
            return -1;
        }
    }
}

// 搜索
int search(char name[])
{
    int i, j, flag = 0;
    clrmous(MouseX, MouseY);
    cleardevice();
    clrmous(MouseX, MouseY);
    setbkcolor(WHITE);
    quit();

    setfillstyle(1, LIGHTGRAY);
    bar(50, 80, 590, 420);
    settextstyle(0, 0, 3);
    settextjustify(1, 1);
    outtextxy(320, 60, name);

    for (i = 0; i < h->lenpar; i++)
    {
        for (j = 0; j < 10; j++) // 查找账号位置
        {
            if (name[j] != h->parameter[i].name[j])
            {
                break;
            }
            if (name[j] == '\0')
            {
                j = 10;
                break;
            }
        }
        if (j == 10)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        setfillstyle(1, BLUE);
        bar(90, 150, 300, 150 + 40);
        setfillstyle(1, YELLOW);
        bar(460, 150, 520, 150 + 40);
        puthz(470, 160, "查看", 16, 16, BLUE);
        settextstyle(0, 0, 3);
        settextjustify(1, 1);
        outtextxy(195, 170, h->parameter[i].name);
    }
    else
    {
        settextstyle(0, 0, 3);
        settextjustify(1, 1);
        outtextxy(320, 250, "the parameter");
        outtextxy(320, 200, "Can not find");
    }

    setfillstyle(1, CYAN);
    bar(80, 120 + 60 * 4, 150, 160 + 60 * 4);
    puthz(83, 125 + 60 * 4, "返回", 32, 32, BLUE);

    for (;;)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(460, 150, 520, 150 + 40) == 1)
        {
            return i + 1;
        }
        // enter
        if (mouse_press(0, 0, 40, 30) == 0 || mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 0)
        {
            MouseS = 0;
        }
        if (mouse_press(0, 0, 40, 30) == 2 || mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 2)
        {
            MouseS = 1;
        }
        // quit
        if (mouse_press(0, 0, 40, 30) == 1)
        {
            exit(0);
        }

        if (mouse_press(80, 120 + 60 * 4, 150, 160 + 60 * 4) == 1)
        {
            return -1;
        }
    }
}

void changewarename(int wi)
{
    int i, j;
    INPUT name = {195, 220, 445, 270, "", 6, 0, 0};
    clrmous(MouseX, MouseY);
    setfillstyle(1, CYAN);
    bar(100, 130, 540, 370);
    puthz(180, 150, "请重新输入仓库名字", 32, 32, BLUE);
    setfillstyle(1, CYAN);
    bar(150, 290, 240, 340);
    puthz(153, 293, "返回", 32, 32, BLUE);
    bar(400, 290, 490, 340);
    puthz(403, 293, "确认", 32, 32, BLUE);
    setfillstyle(1, 0);
    bar(195, 220, 445, 270);

    for (;;)
    {
        delay(15);
        newmouse(&MouseX, &MouseY, &press);
        input_s(198, 220, &name, 16, 0);

        if (mouse_press(150, 290, 240, 340) == 1) // 返回
        {
            return -1;
        }
        if (mouse_press(400, 290, 490, 340) == 1) // 确认
        {
            strcpy(h->here[wi-1].ware_name, name.string);
            wr_h();
            return 1;
        }
    }
    wr_h();
}

void changeparname(int par)
{
    int i, j;
    INPUT name = {195, 220, 445, 270, "", 6, 0, 0};
    clrmous(MouseX, MouseY);
    setfillstyle(1, BROWN);
    bar(100, 130, 540, 370);
    puthz(180, 150, "请重新输入参数名字", 32, 32, BLUE);
    setfillstyle(1, CYAN);
    bar(150, 290, 240, 340);
    puthz(153, 293, "返回", 32, 32, BLUE);
    bar(400, 290, 490, 340);
    puthz(403, 293, "确认", 32, 32, BLUE);
    setfillstyle(1, 0);
    bar(195, 220, 445, 270);

    for (;;)
    {
        delay(15);
        newmouse(&MouseX, &MouseY, &press);
        input_s(198, 220, &name, 16, 0);

        if (mouse_press(150, 290, 240, 340) == 1) // 返回
        {
            return -1;
        }
        if (mouse_press(400, 290, 490, 340) == 1) // 确认
        {
            strcpy(h->parameter[par-1].name, name.string);
            wr_h();
            return 1;
        }
    }
    wr_h();
}