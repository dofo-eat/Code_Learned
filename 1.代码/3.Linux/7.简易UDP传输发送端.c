/*************************************************************************
	> File Name: 7.简易UDP传输发送端.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月26日 星期二 14时12分39秒
 ************************************************************************/
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>         
#include <unistd.h>
#include <strings.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
 
int main()
{
    //创建一个套结字
    int lfd,ret;
    lfd = socket(AF_INET,SOCK_DGRAM,0);
    
    //封装套结字地址结构
    struct sockaddr_in saddr,caddr;
    caddr.sin_family = AF_INET;
    caddr.sin_port = htons(5555);
    caddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
    //绑定套结字地址到套结字描述字
    ret = bind(lfd,(struct sockaddr*)&caddr,sizeof(caddr));
    if(ret < 0)
    {
        perror("bind fail:");
        return -1;
    }
    //封装套结字地址结构
    
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(4444);
    saddr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
    char buf[1024]="test udp protcol !";
    int addrlen;
    while(1)
    {
        /*一直向saddr的地址（接收端IP和端口号），发送udp包*/
        sendto(lfd,buf,1024,0,(struct sockaddr*)&saddr,sizeof(saddr));
        
        sleep(3);   
    }   
    close(lfd);
    
    return 0;
}
