/*************************************************************************
	> File Name: udp_epoll.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月04日 星期四 19时10分31秒
 ************************************************************************/

#include"./color.h"
#include"./head.h"
#include"./common.h"
#include"./udp_client.h"
#include"./udp_server.h"
#define MAX 50

extern int port;
extern struct User *rteam;
extern struct User *bteam;
extern int bepollfd, repollfd;

void add_event(int epollfd, int fd, int events){
    struct epoll_event ev;
    ev.events = events;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    DBG(YELLOW "EPOLL" NONE " : After Epoll Add.\n");
}

void add_event_ptr(int epollfd, int fd, int events, struct User *user) {
    struct epoll_event ev;
    ev.events = events;
    ev.data.ptr = (void *)user;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    DBG(GREEN "Sub Thread" NONE" : After Epoll Add %s.\n", user->name);
}

void del_event(int epollfd, int fd){
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, NULL);
}

int udp_connect(int epollfd, struct sockaddr_in *serveraddr){
    int sockfd;
    
    if((sockfd = socket_create_udp(port)) < 0){
        perror("socket_udp");
        return -1;
    }
 
    DBG(GREEN"INFO"NONE" : Before connect.\n");
    if((connect(sockfd, (struct sockaddr*)serveraddr, sizeof(struct sockaddr))) < 0){
        perror("connect");
        return -1;
    }
    DBG(GREEN "INFO" NONE " : After connect.\n");
    return sockfd;
}

int check_online(struct LogRequest *request) {
    for (int i = 0; i < MAX; i++) {
        if (rteam[i].online && !strcmp(rteam[i].name, request->name)) return 1;
        if (bteam[i].online && !strcmp(bteam[i].name, request->name)) return 1;
    }
    return 0;
}

int udp_accept(int epollfd, int fd, struct User *user){
    struct sockaddr_in client;
    int new_fd, ret;
    struct LogRequest request;
    struct LogResponse response;
    bzero(&request, sizeof(request));//用来清空一个地址段的数据
    bzero(&response, sizeof(response));

    socklen_t len = sizeof(struct sockaddr_in);
    ret = recvfrom(fd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&client, &len);//对端地址放在client里
    
    if(ret != sizeof(request)){
        response.type = 1;//说明失败了
        strcpy(response.msg, "Login failed with Network errors!");
        sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);//将失败消息发给客户端
        return -1;
    }
    if (check_online(&request)) {//判断重复登录
        response.type = 1;
        strcpy(response.msg, "You Are Already Playing This Somewhere!");
        sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);
        return -1;
    }

    response.type = 0;//成功了
    strcpy(response.msg, "Login succes, Enjoy yourself");
    sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);//将成功消息发给客户端

    if (request.team) {//为真表示蓝队
        DBG(GREEN"INFO"NONE" : "BLUE" %s on %s:%d login! (%s)\n"NONE, request.name, inet_ntoa(client.sin_addr), ntohs(client.sin_port), response.msg);
    } else { 
        DBG(GREEN"INFO"NONE" : "RED" %s on %s:%d login! (%s)\n"NONE, request.name, inet_ntoa(client.sin_addr), ntohs(client.sin_port), response.msg);
    }
    strcpy(user->name, request.name);
    user->team = request.team;
    new_fd = udp_connect(epollfd, &client);
    user->fd = new_fd;//保存fd 
    return new_fd;
}

int find_sub(struct User *team) {
    for (int i = 0; i < MAX; i++) {
        if (!team[i].online) return i;
    }
    return -1;
}

void add_to_sub_reactor(struct User *user) {
    struct User *team = (user->team ? bteam : rteam);
    DBG (YELLOW"Main Thread : "NONE"Add to sub_reactor\n");
    int sub = find_sub(team);
    team[sub] = *user;
    team[sub].online = 1;
    team[sub].flag = 10;//尝试连接数
    DBG(L_RED"sub = %d, name = %s\n"NONE, sub, team[sub].name);
    if (user->team)
        add_event_ptr(bepollfd, team[sub].fd, EPOLLIN | EPOLLET, &team[sub]);
        //用边缘模式
    else 
        add_event_ptr(repollfd, team[sub].fd, EPOLLIN | EPOLLET, &team[sub]);
        
}
