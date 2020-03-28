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
#include<unistd.h>

struct Msg {
    int age;
    char name[20];
};

void *print(void *arg) {
    struct Msg* tmp;
    tmp = (struct Msg*)arg;//把arg 强转Msg指针
    printf("name = %s, age = %d\n", tmp->name, tmp->age);
    int retval = 3;
    pthread_exit((void*)&retval);
    //return NULL;
}

int main() {
    void *status;
    pthread_t tid;
    struct Msg msg;
    msg.age = 18;
    strcpy(msg.name, "sxx");
    pthread_create(&tid, NULL, print, (void*)&msg);//指针 函数 参数
    //sleep(1);
    //pthread_join(tid ,NULL);//相当于for循环
    pthread_join(tid, &status);
    printf("%d\n", *(int *)status);
    return 0;
}
//gcc pthread.c -pthrea
