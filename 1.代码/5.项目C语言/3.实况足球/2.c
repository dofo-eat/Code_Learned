/*************************************************************************
	> File Name: 2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月31日 星期日 14时32分23秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<curses.h>
#define LEFTEDGE 10
#define RIGHTEDGE 70
#define ROW 10
//行号

int main() {
    char message[20] = "hello!";
    char blank[20] = "                  ";
    int col = 0;
    int dir = 1;
    int row = 0;
    int dirx = 1;
    int diry = 1;
    initscr();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_RED);
    //初始化颜色对列
    while(1) {
        move(row, col);
        attron(COLOR_PAIR(1));
        //开启属性
        addstr(message);
        attroff(COLOR_PAIR(1));
        move(LINES -1, COLS - 1);
        refresh();
        usleep(10000);
        move(row, col);
        addstr(blank);
        col += diry;
        row +=dirx;
        if(col >= RIGHTEDGE) {
            diry = -1;
        }
        if(col <= LEFTEDGE) diry = +1;
        if(row>= LINES - 1)dirx = -1;
        if(row <= 1) dirx = +1;
    }
    return 0;
}
