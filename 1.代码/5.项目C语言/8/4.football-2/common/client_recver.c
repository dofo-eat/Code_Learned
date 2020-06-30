/*************************************************************************
	> File Name: client_recver.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月13日 星期六 14时13分10秒
 ************************************************************************/
#include "head.h"
#include "common.h"
#include "game.h"

extern int sockfd;

void *client_recv(void *arg) {
    while (1) {
        struct FootBallMsg msg;
        struct User user;
        bzero(&msg, sizeof(msg));
        recv(sockfd, (void *)&msg, sizeof(msg), 0);
        strcpy(user.name, msg.name);
        //找到用户名和队伍
        user.team = msg.team;
        //判断具体是什么
        if (msg.type & FT_TEST) {
            DBG(RED"HeartBeat from Server ❤ \n"NONE);
            msg.type = FT_ACK;
            send(sockfd, (void  *)&msg, sizeof(msg), 0);          
        } else if (msg.type & FT_MSG) {
            //用户发送的信息
            DBG(GREEN"Server Msg : "NONE"%s\n", msg.msg);
            Show_Message(, &user, msg.msg, 0);
        } else if (msg.type & FT_WALL) {
            //服务端发来的信息
           Show_Message(, NULL, msg.msg, 1); 
        } else if (msg.type & FT_FIN) {
            //说明服务端在尝试关闭
            DBG(GREEN"Server is going to stop.\n"NONE);
            endwin();
            exit(0);
        } else {
            DBG(GREEN"Msg Unsupport"NONE);
        }
    }
}

