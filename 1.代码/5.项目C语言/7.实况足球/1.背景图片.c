/*************************************************************************
	> File Name: 1.背景图片.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月31日 星期日 12时57分17秒
 ************************************************************************/
#include<ncurses.h>
#include<unistd.h>
/*int main(){
    initscr();
    WINDOW *m1 = newwin(35, 105, 0, 0);
    box(m1, 0, 0);
    wrefresh(m1);
    sleep(200);
    endwin();
}*/

int main() {
    initscr();
    WINDOW *m1 = newwin(35, 105, 0, 0);
    box(m1, 0, 0);
    move(4, 4);
    hline('-', 10);
    vline('|', 10);
    getch();
    move(10, 10);
    clrtobot();
    getch();
    move(4,4);
    clrtoeol();
    getch();
    endwin();
    return 0;
}
