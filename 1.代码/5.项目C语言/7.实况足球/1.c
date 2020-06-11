/*************************************************************************
	> File Name: 1.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月31日 星期日 14时11分38秒
 ************************************************************************/

#include<stdio.h>
#include<curses.h>
#include<unistd.h>

int main() {
    initscr();
    for(int i = 0; i < LINES; i++) {
        move(i, i+1);
        if(i % 2 == 0) {
            standout();
        }
        addstr("hello!");
        if(i % 2 == 0) {
            standend();
        }
        move(LINES, COLS);
        sleep(1);
        refresh();
        move(i - 1, i);
        addstr("            ");
        move(LINES -2, COLS - 2);
        refresh();
    }
    getch();
    endwin();
    return 0;
}
