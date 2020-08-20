/*************************************************************************
	> File Name: haizei_test.c
	> Author: 
	> Mail: 
	> Created Time: 2020年01月14日 星期二 19时08分57秒
 ************************************************************************/
#include <haizei_test.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_N 1000
struct Func_Data head, *tail = &head;

int RUN_ALL_TESTS() {
    struct Func_Data *p = head.next; 
    for (; p != NULL; p = p->next) {
        printf(GREEN"[=== RUN ===] %s\n", p->func_name);
        p->func();
    }
    return 0;
}


void add_function(Func_T func, const char *str) {
    struct Func_Data *p = (struct Func_Data *)malloc(sizeof(struct Func_Data));
    //只要不主动释放永远都有,返回值为地址
    p->func = func;
    p->func_name = strdup(str);
    
    p->next = NULL;
    tail->next = p;//赋值为P的地址
    tail = p;//p的地址赋值给p
    //指针用间接引用，如果是结构体用直接引用
}
