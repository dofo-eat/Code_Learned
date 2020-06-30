/*************************************************************************
	> File Name: game.h
	> Author: 
	> Mail: 
	> Created Time: 2020年06月02日 星期二 18时35分36秒
 ************************************************************************/
#ifndef _GAME_H
#define _GAME_H
//宏展开意思为参数name 有值吗如果有就用没有就用默认的default参数
#define DEFARG(name, default_value) \
((#name[0]) ? (name + 0) : default_value)
//分别是 窗口 用户 消息 type
#define Show_Message(arg0, arg1, arg2, arg3)\
show_message(DEFARG(arg0, Message), DEFARG(arg1, NULL),\
             arg2, DEFARG(arg3, 0))

#define MAX 50  // 最大游戏人数/队

struct Map court;
WINDOW *Football, *Message, *Help, *Score, *Write, *Football_t;

WINDOW *create_newwin(int width, int height, int start_x, int start_y);
void destory_win(WINDOW *win);
void gotoxy(int x, int y);
void gotoxy_putc(int x, int y, int c);
void gotoxy_puts(int x, int y, char *s);
void w_gotoxy_putc(WINDOW *win, int x, int y, int c);
void w_gotoxy_puts(WINDOW *win, int x, int y, char *s);
void init_football();
void *draw(void *arg);
void show_message(WINDOW *win, struct User *user, char *msg, int type);
#endif
