/*************************************************************************
	> File Name: 1.背景图片.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 20时21分05秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ncurses.h>

int a[40][120];

int main() {
    initscr();
    for(int i = 0; i <= 120; i++){
        printw("-");
        if(i == 120) printw(">");
    }
    for(int i = 0; i <= 40; i++) {
        for(int j = 0; j <= 120; j++) {
            a[i][0] && printw("|");
        }
    }
    refresh();
    //endwin();
    
    
    return 0;
}
