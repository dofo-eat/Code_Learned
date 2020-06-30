/*************************************************************************
	> File Name: datatype.h
	> Author: 
	> Mail: 
	> Created Time: 2020年06月09日 星期二 21时49分00秒
 ************************************************************************/

#ifndef _DATATYPE_H
#define _DATATYPE_H
#define MAXMSG 1024
struct LogRequest{
    char name[20];
    int team;//0 RED 1 BLUE
    char msg[512];
};

struct LogResponse{
    int type;
    char msg[512];
};

struct Point{
    int x, y;
};

struct User{
    int team; //0  1
    int fd;
    char name[20];
    int flag; //三次没有响应
    int online;
    struct Point loc;//目前所在位置

};
struct Map {
    int width;
    int height;
    struct Point start;//区域大小
    int gate_width;//球门
    int gate_height;
};

struct Ctrl{//控制信息
    int carry;//带球
    int kick;//踢球
    int dirx;
    int diry;
};

/*struct TransMsg{//客户端只负责控制，服务端负责计算
    int dirx, diry;//方向
    struct Ctrl ctrl;
};*/


#define FT_TEST 0x01 //服务端心跳信息
#define FT_WALL 0x02 //服务端以字符串方式广播游戏情况
#define FT_MSG  0x04 //客户端发送的信息，服务端转发的信息
#define FT_ACK 0x08 //客户端对心跳的ACK确认
#define FT_FIN 0x10 //客户端，服务螨下线前，对彼此的告知
#define FT_CTL 0x20 //客户端发送的控制信息json发送
#define FT_GAME 0x40 //服务端向客户端广播的游戏实时图画json发送
#define FT_SCORE 0x80 //服务端对客户端广播的游戏比分变化， ja on发送(包括进球人)
#define FT_GAMEOVER 0x100//游戏结束


struct FootBallMsg{
    int type;
    char name[20];
    int team;
    struct Ctrl ctl;
    int size;
    char msg[MAXMSG];
};

#endif
