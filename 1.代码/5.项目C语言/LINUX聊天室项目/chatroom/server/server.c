/*************************************************************************
	> File Name: server.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月31日 星期二 09时23分31秒
 ************************************************************************/

#include "../common/common.h"
#include "../common/tcp_server.h"
#include "../common/chatroom.h"
#include "../common/color.h"

struct User{
    char name[20];
    int online;
    pthread_t tid;
    int fd;
};


char *conf = "./server.conf";

struct User *client;


void *work(void *arg){
    int sub = *(int *)arg;
    int client_fd = client[sub].fd;
    struct RecvMsg rmsg;
    printf(GREEN"Login "NONE" : %s\n", client[sub].name);
    while (1) {
        rmsg = chat_recv(client_fd);
        if (rmsg.retval < 0) {
            printf(PINK"Logout: "NONE" %s \n", client[sub].name);
            close(client_fd);
            client[sub].online = 0;
            return NULL;
        }
        printf(BLUE"%s"NONE" : %s\n",rmsg.msg.from, rmsg.msg.message);
    }
    return NULL;
}


int find_sub() {
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (!client[i].online) return i;//最小的位置
    }
    return -1;
}

bool check_online(char *name) {
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (client[i].online && !strcmp(name, client[i].name)) {
            printf(YELLOW"W"NONE": %s is online\n", name);
            return true;
        }
    }
    return false;
}


int main() {
    int port, server_listen, fd;
    struct RecvMsg recvmsg;//收信息
    struct Msg msg;
    port = atoi(get_value(conf, "SERVER_PORT"));
    client = (struct User *)calloc(MAX_CLIENT, sizeof(struct User));
    //给User申请空间
    if ((server_listen = socket_create(port)) < 0) {
        perror("socket_create");
        return 1;
    }
    while (1) { 
        if ((fd = accept(server_listen, NULL, NULL)) < 0) {
            perror("accept");
            continue;
        }
        
        recvmsg = chat_recv(fd);//
        if (recvmsg.retval < 0) {
            close(fd);
            continue;
        }
        if (check_online(recvmsg.msg.from)) {
mZstrcpy(msg.message, "You have Already Login System!");
mZchat_send(msg, fd);
            close(fd);
            continue;
            //拒绝连接：
        } 
        msg.flag = 2;
        strcpy(msg.message, "Welcome to this chat room!");
        chat_send(msg, fd);

        int sub;
        sub = find_sub();//找到地址
        client[sub].online = 1;
        client[sub].fd =fd;
        strcpy(client[sub].name, recvmsg.msg.from);//收到名字
        pthread_create(&client[sub].tid, NULL, work, (void *)&sub);
    }
    return 0;
}

