/*************************************************************************
	> File Name: 27.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 19时31分43秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<curses.h>

int main() {
    initscr();
    clear();
    move(10, 20);
    addstr("hello world!");
    refresh();
//gcc 27.c -lncurses
   // endwin();
    return 0;
}
