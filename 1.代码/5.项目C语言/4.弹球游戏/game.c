/*************************************************************************
	> File Name: game.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月31日 星期日 20时25分01秒
 ************************************************************************/
#include "game.h"
int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    initgame();

    signal(14, drawgame);
    
    struct itimerval itimer;
    itimer.it_interval.tv_sec = 0;
    itimer.it_interval.tv_usec = 100000;
    itimer.it_value.tv_sec = 0;
    itimer.it_value.tv_usec = 1000;
    setitimer(ITIMER_REAL, &itimer, NULL);
   
    Opoint.x = cx;
    Opoint.y = Y - 4;

    attron(COLOR_PAIR(4));
    gotoxy_putc(Opoint.x, Opoint.y, 'o');
    attroff(COLOR_PAIR(4));

    refresh();

    while (1) {
        int c = getch();
        switch(c) {
            case KEY_LEFT:
                Bdir.x -= 2;
                break;
            case KEY_RIGHT:
                Bdir.x += 2;
                break;
            case KEY_UP:
                if (flag) break;
                flag = 1; //球离开板
                Odir.x = dir_r[get_random(2)];
                Odir.y = -1;
                break;
            default:
                break;
        } 
    }
    
    getch();
    endwin();
    return 0;
}

