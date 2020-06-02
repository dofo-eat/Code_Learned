/*************************************************************************
	> File Name: game.h
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月02日 星期二 18时35分41秒
 ************************************************************************/

#ifndef _GAME_H
#define _GAME_H
#include<curses.h>
#define MAX 50

struct LogData{
    char name[20];
    int team;//0 red 1 blue
};

struct Point{
    int x;
    int y;
};

struct User{
    int team;
    char name[20];
    int flag;//未响应次数
    struct sockaddr_in addr;
    struct Point loc;
};

struct Map {
    int width;
    int heigth;
    struct Point start;
    int gate_width;
    int gate_height;
};

struct Ctrl {
    int carry;
    int kick;
};

struct TransMsg {
    int dirx;
    int diry;
    struct Ctrl ctrl;
};

struct Map court;

WINDOW *football{
    int football;
    int message;

}

WINDOW *create_newwin(int width, int heigth, int startx, int starty) {
    WINDOW *win;
    win = newwin(heigth, width, starty, startx);
    box(win, 0, 0);
    wrefresh();
    return win;
}

void destory_win(WINDOW *win) {
    wborder(win, ' ', ' ',  ' ',' ',  ' ', ' ',  ' ', ' ');
    wrefresh(win);
    delwin(win);
}

void gotoxy(int x, int y) {
    move(y, x);
}

void gotoxy_putc(int x, int y, int c) {
    move(y, x);
    addch(c);
    move(LINES- 1, 1);
    refresh();
} 

void gotoxy_puts(int x, int y, char * s) {
    move(y, x);
    addstr(s);
    move(LINES - 1, 1);
    refresh();
} 

void w_gotoxy_putc(WINDOW *win, int x, int y, int c) {
    mvwaddch(win, y, x, c);
    move(LINES - 1, 1);
    wrefresh(win);
}

void w_gotoxy_puts(WINDOW *win, int x, int y, char *s) {
    mvwaddch(win, y, x, s);
    move(LINES - 1);
    wrefresh(win);
}

void initfootball() {
    initscr();
    clear();
    if(!has_color() || start_color() == ERR) {
        endwin();
        fprintf(stderr, "终端不支持颜色！\n");
        exit(1);
    }
    init_pair(1, COLOR_CREEN, COLOR_BALCK);
    init_pair(2, COLOR_RED, COLOR_BALCK);
    init_pair(3, COLOR_WHITE, COLOR_BALCK);
    init_pair(4, COLOR_YELLOW, COLOR_BALCK);
    init_pair(5, COLOR_CYAN, COLOR_BALCK);
    init_pair(6, COLOR_BLUE, COLOR_BALCK);

    Creat_newwin(court.width, court.height);
}

void *draw () {
    
}

#endif
