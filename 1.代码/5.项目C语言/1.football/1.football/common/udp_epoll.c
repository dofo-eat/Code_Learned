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
    //添加事件
    struct epoll_event ev;
    ev.events = events;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    //          fd       操作         操作对象  
    DBG(YELLOW "EPOLL" NONE " : After Epoll Add.\n");
}

void add_event_ptr(int epollfd, int fd, int events, struct User *user) {
    struct epoll_event ev;
    ev.events = events;
    ev.data.ptr = (void *)user;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
    DBG(GREEN "Sub Thread" NONE" : After Epoll Add %s.\n", user->name);
}

void del_event(int epollfd, int fd, int events){
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = events;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &ev);
}

int udp_connect(int epollfd, struct sockaddr_in *serveraddr){
    int sockfd;
    
    if((sockfd = socket_create_udp(port)) < 0){
        //socket_create_udp用来创建一个绑定了端口的套接字
        perror("socket_udp");
        return -1;
    }
 
    /*if((sockfd = socket_udp()) < 0){
        perror("socket_udp");
        return -1;
    }*/
    DBG(GREEN"INFO"NONE" : Before connect.\n");
    if((connect(sockfd, (struct sockaddr*)serveraddr, sizeof(struct sockaddr))) < 0){
        perror("connect");
        return -1;
    }
    DBG(GREEN "INFO" NONE " : After connect.\n");
    //int ret = send(sockfd, "     login!", sizeof("     login!"), 0);
    //连接成功后发送login给client
    //DBG(RED "RET= %d\n" NONE, ret);
    //add_event(epollfd, sockfd, EPOLLIN);
    return sockfd;
}

int udp_accept(int epollfd, int fd, struct User *user){
    //epollfd用谁管理 fd用谁收
    struct sockaddr_in client;
    int new_fd, ret;
    struct LogRequest request;
    struct LogResponse response;
    bzero(&request, sizeof(request));//用来清空一个地址段的数据
    bzero(&response, sizeof(response));

    socklen_t len = sizeof(struct sockaddr_in);
    ret = recvfrom(fd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&client, &len);//对端地址放在client里
    
    if(ret != sizeof(request)){
    //判断对方发的包是否能收起会不会发生沾包拆包问题, 不会发生，UDP报文承载量大于用户发的量，大多数情况不会有问题包的出现
        response.type = 1;//说明失败了
        strcpy(response.msg, "Login failed");
        sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);//将失败消息发给客户端
        return -1;
    }

    response.type = 0;//成功了
    strcpy(response.msg, "Login succes, Enjoy yourself");
    sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);//将成功消息发给客户端

    if (request.team) {//为真表示蓝队
        DBG(GREEN"INFO"NONE" : "BLUE" %s on %s:%d login! (%s)\n"NONE, request.name, inet_ntoa(client.sin_addr), ntohs(client.sin_port), response.msg);
    //inet_ntoa网络字节序转字符串 网络字节序转化成本地字节序
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
    for (int i = 0; i < MAX; i++) {//给新用户分配一个未被用的fd
        if (!team[i].online) return i;
    }
    return -1;
}

void add_to_sub_reactor(struct User *user) {
    struct User *team = (user->team ? bteam : rteam);
    DBG (YELLOW"Main Thread : "NONE"Add to sub_reactor\n");
    int sub = find_sub(team);
    team[sub] = *user;//把user值存进去,*取值.数组中存放的是结构体
    team[sub].online = 1;
    team[sub].flag = 10;//尝试连接数
    DBG(L_RED"sub = %d, name = %s\n"NONE, sub, team[sub].name);
    /*
     * team[sub].flag--;
       if(team[sub].flag == 0) {
       
            sendto(fd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&client, len);
        }
    */
    
    if (user->team)
        add_event_ptr(bepollfd, team[sub].fd, EPOLLIN | EPOLLET, &team[sub]);
        
        //用边缘模式
    else 
        add_event_ptr(repollfd, team[sub].fd, EPOLLIN | EPOLLET, &team[sub]);
        
}


