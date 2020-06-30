/*************************************************************************
	> File Name: send_ctl.c
	> Author: 
	> Mail: 
	> Created Time: 2020年06月14日 星期日 20时07分56秒
 ************************************************************************/
#include "head.h"

extern int sockfd;
extern struct FootBallMsg ctl_msg;

void send_ctl() {
    //发送控制信息
    if (ctl_msg.ctl.dirx || ctl_msg.ctl.diry)
        send(sockfd, (void *)&ctl_msg, sizeof(ctl_msg), 0);
    ctl_msg.ctl.dirx = ctl_msg.ctl.diry = 0;
    //ctl_msg.ctl.dirx ctl_msg.ctl.diry指的是这次客户想移动的距离,而不是定值，所以需要清空
}
