/*************************************************************************
	> File Name: common.h
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月31日 星期二 09时11分25秒
 ************************************************************************/
#ifndef _COMMON_H
#define _COMMON_H
char conf_ans[50] = {0};
char *get_value(char *path, char *key);
void make_nonblock_ioctl(int fd);
void make_block_ioctl(int fd);
void make_nonblock(int fd);
void make_block(int fd);
#endif

