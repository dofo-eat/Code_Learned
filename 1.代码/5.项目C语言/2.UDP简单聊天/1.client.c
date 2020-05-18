/*************************************************************************
	> File Name: 1.client.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月17日 星期日 13时24分18秒
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>

#define N 128

typedef struct
{
    char type;
    char name[32];
    char text[N];
}MSG;

int main(int argc,char *argv[])
{
    int socketfd;
    socklen_t addr_len;
    pid_t pid;
    MSG msg;
    struct sockaddr_in server_addr;
    if(argc < 3)
    {
        printf("uasge: %s ip port\n",argv[0]);
        exit(-1);
    }

    if((socketfd = socket(PF_INET,SOCK_DGRAM,0)) < 0)
    {
        perror("socket");
        exit(-1);
    }
    printf("input name:\n");
    fgets(msg.name,64,stdin);
    msg.name[strlen(msg.name) - 1] = '\0';
    msg.type='L';

    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    addr_len = sizeof(server_addr);
    
    if(sendto(socketfd,&msg,sizeof(msg),0,(struct sockaddr*)&server_addr,addr_len) < 0)
    {
        perror("sendto3");
        exit(-1);
    }

    if((pid = fork()) == -1 )
    {
        perror("fork");
        exit(-1);
    }
    if(pid == 0)
    {
        while(1)
        {
            fgets(msg.text,N,stdin);
            msg.text[strlen(msg.text) - 1] = '\0';

            if(strncmp(msg.text,"quit",4) == 0)
            {
                msg.type = 'Q';
                if(sendto(socketfd,&msg,sizeof(msg),0,(struct sockaddr*)&server_addr,addr_len) < 0)
                {
                    perror("sendto2");
                    exit(-1);
                }
                kill(getppid(),SIGKILL);
                break;  
            }
            else
            {
                msg.type='B';
                if(sendto(socketfd,&msg,sizeof(msg),0,(struct sockaddr*)&server_addr,addr_len) < 0)
                {
                    perror("sendto1");
                    exit(-1);
                }   
            }
        
        }
        close(socketfd);
    }

    if(pid > 0)
    {
        while(1)
        {
            if(recvfrom(socketfd,&msg,sizeof(msg),0,(struct sockaddr*)&server_addr,&addr_len) < 0)
            {
                perror("recvfrom");
                exit(-1);
            }
        
            switch(msg.type)
            {
                case 'L':
                    printf("%s login\n",msg.name);
                    break;
                case 'B':
                    printf("from %s> %s\n",msg.name,msg.text);
                    break;
                case 'Q':
                    printf("%s quit\n",msg.name);
                    break;
            }
        }
    }   
    return 0;
}
