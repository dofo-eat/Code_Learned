/*************************************************************************
	> File Name: pthread.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月26日 星期四 19时50分15秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<pthread.h>

void *print(void *arg) {
    printf("%s\n", arg);
    return NULL;
}

int main() {
    pthread_t tid;
    char msg[1024] = {0};
    scanf("%s\n", msg);
    pthread_create(&tid, NULL, print, (void*)msg);//指针 函数 参数
    return 0;
}
