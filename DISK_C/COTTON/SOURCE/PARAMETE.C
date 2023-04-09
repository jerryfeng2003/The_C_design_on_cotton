#include "TOTAL.H"
// 专门用来写有关edit和past的函数

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
    return 1;
}

void wr_parameter(struct Parameter *abc)
{
    FILE *fp;
    user *u = (user *)malloc(sizeof(user));
    int i, j, k, all;
    if ((fp = fopen("User.txt", "rt+")) == NULL)
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
            for (k = 0; k < N; k++)
            {
                h->parameter[h->lenpar].xyz[k] = abc->xyz[k];
            }
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
    fclose(fp);
    return;
}

// 把当前登录的用户重新写进文件
void wr_h(void)
{
    FILE *fp;
    user *u = (user *)malloc(sizeof(user));
    int i, j, k, all;
    if ((fp = fopen("User.txt", "rt+")) == NULL)
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
    fclose(fp);
    return;
}

// 删除参数
void deletepar(int par)
{
    int i, j;
    par -= 1;
    for (i = par; i < h->lenpar; i++)
    {
        for (j = 0; j < 10; j++)
        {
            h->parameter[par].name[j] = h->parameter[par + 1].name[j];
        }
        h->parameter[par].place = h->parameter[par + 1].place;
        h->parameter[par].shape = h->parameter[par + 1].shape;
        h->parameter[par].type = h->parameter[par + 1].type;
        strcpy(h->parameter[par].S, h->parameter[par + 1].S);
        for (j = 0; j < N; j++)
        {
            h->parameter[par].xyz[j] = h->parameter[par + 1].xyz[j];
        }
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
