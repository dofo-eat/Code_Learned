/*************************************************************************
	> File Name: client1.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月07日 星期日 10时45分27秒
 ************************************************************************/

#include "../common/head.h"
#include "../common/udp_client.h"

char server_ip[20] = {0};
int server_port = 0;
char *conf = "./client.conf";

int main(int argc, char **argv)  {
    int opt, sockfd;
    struct LogRequest request;
    struct LogResponse response;
    bzero(&request, sizeof(request));
    while ((opt = getopt(argc, argv, "h:p:n:t:m:")) != -1) {
        switch (opt) {
            case 'h':
                strcpy(server_ip, optarg);
                break;
            case 'p':
                server_port = atoi(optarg);
                break;
            case 'n':
                strcpy(request.name, optarg);
                break;
            case 't':
                request.team = atoi(optarg);
                break;
            case 'm':
                strcpy(request.msg, optarg);
                break;
            default:
                fprintf(stderr, "Usage : %s [-h host] [-p port]!\n", argv[0]);
                exit(1);

        }
    }

    argc -= (optind - 1);
    argv += (optind - 1);

    if (argc  > 1) {
        fprintf(stderr, "Usage : %s [-h host] [-p port]!\n", argv[0]);
        exit(1);
    }

    if (!server_port) server_port = atoi(get_value(conf, "SERVERPORT"));
    if (!strlen(server_ip)) strcpy(server_ip, get_value(conf, "SERVERIP"));
    if (!strlen(request.name)) strcpy(request.name, get_value(conf, "NAME"));
    if (!strlen(request.msg)) strcpy(request.msg, get_value(conf, "LOGMSG"));
    if (!request.team) request.team = atoi(get_value(conf, "TEAM"));

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(server_port);
    server.sin_addr.s_addr = inet_addr(server_ip);

    socklen_t len = sizeof(server);

    DBG(GREEN"INFO"NONE" : server_ip = %s, server_port = %d, name = %s, team = %s logmsg = %s\n", server_ip, server_port, request.name, (request.team ? "BLUE" : "RED"), request.msg);

    if ((sockfd = socket_udp()) < 0) {
        perror("socket_udp");
        exit(1);
    }

    sendto(sockfd, (void *)&request, sizeof(request), 0, (struct sockaddr *)&server, len);

    int ret = recvfrom(sockfd, (void *)&response, sizeof(response), 0, (struct sockaddr *)&server, &len);
    if (ret != sizeof(response) || response.type) {
        DBG(RED"ERROR : "NONE"The Game Server refused your login.\n\tThis May be helpfull: %s\n", response.msg);
        exit(1);
    }

    DBG(GREEN"SERVER : "NONE" %s \n", response.msg);
    connect(sockfd, (struct sockaddr *)&server, len);

    sleep(10);

    return 0;
}
