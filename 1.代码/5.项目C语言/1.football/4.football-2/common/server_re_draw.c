/*************************************************************************
	> File Name: server_re_sraw.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月14日 星期日 20时29分46秒
 ************************************************************************/
#include "head.h"
#include "game.h"
#define MAX 50

extern struct User *rteam, *bteam;
extern WINDOW *Football;

void re_draw_player(int team, char *name, struct Point *loc) {
    char p = 'K';
    if (team)
        wattron(Football, COLOR_PAIR(6));//标记为相应颜色
    else
        wattron(Football, COLOR_PAIR(2));
    w_gotoxy_putc(Football, loc->x, loc->y, p);
    w_gotoxy_puts(Football, loc->x + 1, loc->y - 1, name);
}

void re_draw_team(struct User*team) {
    for (int i = 0; i < MAX; i++) {
        if (!team[i].online) continue;
        //将在线用户进行重新绘制
        re_draw_player(team[i].team, team[i].name, &team[i].loc);
    }
}

void re_draw() {
    //wclear(Football);
    werase(Football_t);
    //清空界面
    box(Football_t, 0, 0);
    box(Football, 0, 0);
    re_draw_team(rteam);//重新绘制
    re_draw_team(bteam);
    wrefresh(Football_t);
}
