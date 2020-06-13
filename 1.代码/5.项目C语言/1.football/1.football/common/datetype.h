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
    int heigth;
    struct Point start;//区域大小
    int gate_width;//球门
    int gate_height;
};

struct Ctrl {
    int carry;//带球
    int kick;//踢球
};

struct TransMsg {//客户端只负责控制，服务端负责计算
    int dirx;//方向
    int diry;
    struct Ctrl ctrl;
};

#define FT_TEST 0x01//测试 是否在线心跳
#define FT_WALL 0x02//广播
#define FT_MSG 0x04
#define FT_ACK 0x08
#define FT_FIN 0x10
//0x16进制 某一个比特位的权值 1 2 4 8 四个比特代表四个状态

struct FootBallMsg {
    int type;
    int size;
    int team;
    char name[20];
    char msg[MAXMSG];
};

#endif
