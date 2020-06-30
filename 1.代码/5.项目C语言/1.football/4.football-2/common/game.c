/*************************************************************************
	> File Name: game.h
	> Author: 
	> Mail: 
	> Created Time: 2020年06月02日 星期二 18时35分36秒
 ************************************************************************/
 #include "head.h"

extern struct Map court;
extern  WINDOW *Football, *Message, *Help, *Score, *Write, *Football_t;
int message_num = 0;

WINDOW *create_newwin(int width, int height, int start_x, int start_y) {//创建窗口
    WINDOW *win;
    //为了方便将先创建的窗口封装一下
    win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    wrefresh(win);
    return win;
}

void destory_win(WINDOW *win) {//销毁窗口
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
//用来把box周边画出来的线删掉
    wrefresh(win);
    delwin(win);
    return;
}

void gotoxy(int x, int y) {
    move(y, x);
    return;
}

void gotoxy_puc(int x, int y, int c) {
    move(y, x);
    addch(c);
    move(LINES - 1, 1);
    refresh();
    return;
}

void gotoxy_puts(int x, int y, char *s) {
    move(y, x);
    addstr(s);
    move(LINES - 1, 1);
    refresh();
    return;
}

void w_gotoxy_putc(WINDOW *win, int x, int y, int c) {//每个窗口有自己的xy,
    mvwaddch(win, y, x, c);//在窗口x, y上插入字符
    move(LINES - 1, 1);
    wrefresh(win);
    return;
}

void w_gotoxy_puts(WINDOW *win, int x, int y, char *s) {
    mvwprintw(win, y, x, s);//在窗口x, y上插入字符串
    move(LINES - 1, 1);
    wrefresh(win);
    return;
}

void init_football() {
    initscr();
    clear();
    if (!has_colors() || start_color() == ERR) {
        endwin();
        fprintf(stderr, "Your termial not support color!\n");
        exit(1);
    }
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);//初始化
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    
    Football_t = create_newwin(court.width + 4, court.height + 2, court.start.x - 2, court.start.y - 1);
    Football = subwin(Football_t,court.height, court.width, court.start.x, 
                             court.start.y);//场地
    box(Football, 0, 0);
    WINDOW *Message_t = create_newwin(court.width + 4, 7, court.start.x - 2,
                            court.start.y + court.height + 1);//右侧帮助栏
    Message = subwin(Message_t, 5, court.width + 2, 
                    court.start.y + court.height + 2, court.start.x - 1);
    //创建虚拟窗体, 在Message_t上创建虚拟窗体
    //先y在x，宽度为原宽度减2，court.width-2为了去掉边框
    scrollok(Message, 1);//Message 这个窗口可以滚动查看

    Help = create_newwin(20, court.height + 2, court.start.x + court.width + 2,
                         court.start.y - 1);
    Score = create_newwin(20, 7, court.start.x + court.width + 2,
                          court.start.y + court.height + 1);//右下角比分栏
    Write = create_newwin(court.width + 20, 5, court.start.x - 2,
                          court.start.y + court.height + 8);//下方
    return;
}

void *draw(void *arg) {
    init_football();
    while (1) {
        sleep(10);
    }
    return NULL;
}

void show_message(WINDOW *win, struct User *user, char *msg, int type) {
    //win在哪个窗口上显示信息 user 用户
   time_t time_now = time(NULL);
    struct tm* tm = localtime(&time_now);
    char timestr[20] = {0};
    char username[80] = {0};
    sprintf(timestr, "%02d:%02d:%02d ", tm->tm_hour, tm->tm_min, tm->tm_sec);//时间格式 不够两位0补齐
    if (type) {
        //type=1系统信息
        wattron(win, COLOR_PAIR(4));
        strcpy(username, "Server Info : ");
    } else { 
        //用户消息
        if (user->team)
            wattron(win, COLOR_PAIR(6));
        else 
            wattron(win, COLOR_PAIR(2));
        //用来拿到用户名字设置颜色
        sprintf(username, "%s : ", user->name);
    }
    //屏幕滚动相关
    if (message_num < 4) {
        w_gotoxy_puts(win, 10, message_num, username);
        //时间占8个单位所以用户名从10开始
        wattron(win, COLOR_PAIR(3));//恢复，覆盖上一个颜色
        w_gotoxy_puts(win, 10 + strlen(username), message_num, msg);
        wattron(win, COLOR_PAIR(5));
        w_gotoxy_puts(win, 1, message_num, timestr);//输出时间
        message_num++;
    } else {
        message_num = 4;
        scroll(win);
        w_gotoxy_puts(win, 10, message_num, username);
        wattron(win, COLOR_PAIR(3));//恢复
        w_gotoxy_puts(win, 10 + strlen(username), message_num, msg);
        wattron(win, COLOR_PAIR(5));
        w_gotoxy_puts(win, 1, message_num, timestr);
        message_num++;
    }
    wrefresh(win);
}

