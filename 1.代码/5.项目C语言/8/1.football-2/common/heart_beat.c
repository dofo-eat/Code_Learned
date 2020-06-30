/*************************************************************************
	> File Name: heart_beat.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 23时02分33秒
 ************************************************************************/

#include"datatype.h"
#include "head.h"
#include"./game.h"
#include"./udp_epoll.h"

#define MAX 50
extern int bepollfd, repollfd;
extern struct User *rteam, *bteam;

void heart_beat_team(struct User *team){
    struct FootBallMsg msg;
    msg.type = FT_TEST;
    for(int i = 0; i < MAX; i++){
        if(team[i].online){//在线
            if(!team[i].flag){//还有连接次数，如果为0就意味着失联次数超过特定值就该设置为掉线了
                team[i].online = 0;
                continue;
            }

            send(team[i].fd,(void *)&msg, sizeof(msg), 0);
            team[i].flag--;

            if(team[i].flag <= 0){
                char tmp[512] = {0};
                sprintf(tmp, "%s is remove from list.",team[i].name);
                Show_Message( , NULL, tmp, 1);
                team[i].online = 0;

                int epollfd_tmp = (team[i].team ? bepollfd :repollfd);
                del_event(epollfd_tmp, team[i].fd);
            }
        }
    }
    return;
}


void *heart_beat(void *arg){
    while(1){
        sleep(10);
        heart_beat_team(bteam);
        heart_beat_team(rteam);
    }
    return NULL;
}
