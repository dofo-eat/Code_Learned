#include "./common/head.h"

extern struct Map court;
extern WINDOW *Football, *Message, *Help, *Score, *Write;
int Message_num = 0;

WINDOW *create_newwin(int width, int heigth, int startx, int starty) {
    WINDOW *win;
    win = newwin(heigth, width, starty, startx);
    box(win, 0, 0); //当我们创建了一个窗口之后却无法看见它,所以我们现在要做的就是让窗口显示出来。box()函数可以在已定义的窗口外围画上边框。
    wrefresh(win);
    return win;
}

void destroy_win(WINDOW * win) {
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win);
    delwin(win);
}

void gotoxy(int x, int y) {
    move(y, x);
}

void gotoxy_putc(int x, int y, int c) {
    move(y, x);
    addch(c);
    move(LINES - 1, 1);
    refresh();
}

void gotoxy_puts(int x, int y, char* s) {
    move(y, x);
    addstr(s);
    move(LINES - 1, 1);
    refresh();
}

void w_gotoxy_putc(WINDOW *win, int x, int y, int c){
    mvwaddch(win, y, x, c);//移动到窗口指定位置打印字符
    move(LINES - 1, 1);
    wrefresh(win);
}

void w_gotoxy_puts(WINDOW *win, int x, int y, char *s) {
    mvwprintw(win, y, x, s);
    move(LINES - 1, 1);
    wrefresh(win);
}

void initfootball() {
    initscr();
    clear();
    if (!has_colors() || start_color() == ERR) {
        endwin();
        fprintf(stderr, "your terminal not surport color！\n");
        exit(1);
    }
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    
    Football = create_newwin(court.width, court.heigth, court.start.x, court.start.y);
    WINDOW *Message_t = create_newwin(court.width, 7, court.start.x, court.start.y + court.heigth);
    Message = subwin(Message_t, 5, court.width - 2, court.start.y + court.heigth, court.start.x);
    scrollok(Message, 1);
    Help = create_newwin(20, court.heigth, court.start.x + court.width, court.start.y);
    Score = create_newwin(20, 7, court.start.x + court.width, court.start.y + court.heigth);
    Write = create_newwin(court.width + 20, 5, court.start.x, court.start.y + court.heigth + 7);
}

void *draw(void *arg) {
    initfootball();
    while (1) {
        sleep(10);
    }
}

void show_message(WINDOW *win, struct User *user, char *msg, int type) {
    time_t time_now = time(NULL);
    struct tm* tm = localtime(&time_now);
    char timestr[20] = {0};
    char username[80] = {0};
    sprintf(timestr, "%02d:%02d:%02d ", tm->tm_hour, tm->tm_min, tm->tm_sec);
    if(type) {
        wattron(win,COLOR_PAIR(4));
        strcpy(username, "server Info :");
        //系统消息
    } else {
        if(user->team) {
            wattron(win,COLOR_PAIR(6));
        }
        else {
            wattron(win,COLOR_PAIR(2));
        }
        sprintf(username, "%s:",user->name);
    }
    if(Message_num < 4) {
        w_gotoxy_puts(win, 10, Message_num, username);    
        wattron(win, COLOR_PAIR(3));
        w_gotoxy_puts(win, 10 + strlen(username), Message_num, msg);
        wattron(win, COLOR_PAIR(5));
        w_gotoxy_puts(win, 1, Message_num, timestr);
        Message_num++;
    } else {
        Message_num = 4;
        scroll(win);
        w_gotoxy_puts(win, 10, Message_num, username);    
        wattron(win, COLOR_PAIR(3));
        w_gotoxy_puts(win, 10 + strlen(username), Message_num, msg);
        wattron(win, COLOR_PAIR(5));
        w_gotoxy_puts(win, 1, Message_num, timestr);
        Message_num++;
    }
    wrefresh(win);
}

