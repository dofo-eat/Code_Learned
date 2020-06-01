/*************************************************************************
	> File Name: 2.test.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月31日 星期日 12时39分23秒
 ************************************************************************/
#include<ncurses.h>
#include<unistd.h>

int main(){

    initscr();
    cbreak();
    noecho();
    start_color();
   // init_pair(1,COLOR_BLACK,COLOR_BLUE);
    WINDOW *m = newwin(35,105,0,0);
    box(m,0,0);
    wrefresh(m);
    sleep(2020);
    endwin();
    return 0;

}
