#ifndef _GAME_H
#define _GAME_H
#include <curses.h>

#define MAX 50 //Maximum number of users


struct Map court;

WINDOW *Football, *Message, *Help, *Score, *Write;

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
    Message = create_newwin(court.width, 5, court.start.x, court.start.y + court.heigth);
    Help = create_newwin(20, court.heigth, court.start.x + court.width, court.start.y);
    Score = create_newwin(20, 5, court.start.x + court.width, court.start.y + court.heigth);
    Write = create_newwin(court.width + 20, 5, court.start.x, court.start.y + court.heigth + 5);
}

void *draw(void *arg) {
    initfootball();
    while (1) {
        sleep(10);
    }
}

#endif
