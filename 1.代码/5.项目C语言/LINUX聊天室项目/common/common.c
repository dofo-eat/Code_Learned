/*************************************************************************
	> File Name: common.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月31日 星期二 09时08分53秒
 ************************************************************************/
#include "head.h"

char *get_value(char *path, char *key) {
    FILE *fp = NULL;
    ssize_t nrd;//读文件
    char *line = NULL, *sub = NULL;//配置文件以行的形式去读取  下标等于空
    extern char conf_ans[50];
    size_t linecap;
    if (path == NULL || key == NULL) {
        fprintf(stderr, "Error in argument!\n");
        return NULL;
    }
    if ((fp = fopen(path, "r")) == NULL) {
        perror("fopen");
        return NULL;
    }
    while ((nrd = getline(&line, &linecap, fp)) != -1) {
        if ((sub = strstr(line, key)) == NULL) 
            continue;
        else {
            if (line[strlen(key)] == '=') {
                //行的第几个字符可以找到ip地址
                strncpy(conf_ans, sub + strlen(key) + 1, nrd - strlen(key) - 2);//后面的ip地址的长度
                *(conf_ans + nrd - strlen(key) - 2) = '\0';
                //将最后一个字符设置为\0
                break;
            }
        }
    }
    free(line);
    fclose(fp);
    if (sub == NULL) {
        return NULL;
    }
    return conf_ans;
}



void make_nonblock_ioctl(int fd){
    unsigned long ul = 1;
    ioctl(fd, FIONBIO, &ul);
}


void make_block_ioctl(int fd) {
    unsigned long ul = 0;
    ioctl(fd, FIONBIO, &ul);
}


void make_nonblock(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return;
    }
    flag |= O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}

void make_block(int fd) {
    int flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        return ;
    }
    flag &= ~O_NONBLOCK;
    fcntl(fd, F_SETFL, flag);
}

