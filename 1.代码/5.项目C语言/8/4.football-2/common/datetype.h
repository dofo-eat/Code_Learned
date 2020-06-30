/*************************************************************************
	> File Name: date.h
	> Author: 
	> Mail: 
	> Created Time: 2020年06月06日 星期六 20时24分08秒
 ************************************************************************/

#ifndef _DATE_H
#define _DATE_H 
#define MAXMSG 1024

struct LogRequest { //登录信息,存放用户发送的
    char name[20];
    int team;  // 0 RED 1 BLUE
    char msg[512];
};

struct LogResponse {
    int type;//成功与否 0 success 1 failed
    char msg[512];//拒绝原因
};

struct Point {
    int x, y;
};

struct User {
    int team;//队伍
    int fd;
    int online;
    char name[20];//客户端名字
    int flag;//未响应次数，用来判定是否在线,当有客户端3次没有响应时就认为没在线
    //struct sockaddr_in addr;//记录用户远程地址
    struct Point loc;
};

struct Map {
    int width;
    int height;
    struct Point start;//区域大小
    int gate_width;//球门
    int gate_height;
};

struct Ctrl {
    int carry;//带球
    int kick;//踢球
    int dirx;
    int diry;
};
/*
struct TransMsg {//客户端只负责控制，服务端负责计算
    int dirx;//方向
    int diry;
    struct Ctrl ctrl;
};
*/
//0x16进制 某一个比特位的权值 1 2 4 8 四个比特代表四个状态
#define FT_TEST 0x01//服务端信条信息
#define FT_WALL 0x02//服务端以字符串方式广播游戏情况
#define FT_MSG 0x04//客户端发送的信息，服务端转发的信息
#define FT_ACK 0x08//客户端对心跳的ACK确认
#define FT_FIN 0x10//客户端，服务端下线前，岁彼此的告知
#define FT_CTL 0x20//客户端发送的控制信息json发送
#define FT_GAME 0x40//服务端向客户端的游戏实时画图 json发送
#define FT_SCORE 0x80
//服务端对客户端关闭的游戏比分变化，json发送(包括进球人)
#define FT_GAMEOVER 0x100//游戏结束

struct FootBallMsg {
    int type;
    int size;
    int team;
    char name[20];
    struct Ctrl ctl;
    char msg[MAXMSG];
};

#endif
