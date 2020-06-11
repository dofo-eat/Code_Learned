/*************************************************************************
	> File Name: 3.test.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月31日 星期日 13时49分21秒
 ************************************************************************/
#include<curses.h>
#include<stdio.h>

int main() {
    initscr();
    WINDOW *m1 = newwin(35, 105, 0, 0);
    box(m1, 0, 0);
    refresh();
    getch();
    endwin();
    return 0;
}
