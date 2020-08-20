/*************************************************************************
	> File Name: haizei_test.h
	> Author: 
	> Mail: 
	> Created Time: 2020年01月12日 星期日 18时26分47秒
 ************************************************************************/

#ifndef _HAIZEI_TEST_H
#define _HAIZEI_TEST_H

#define MAX_N 1000

typedef void (*Func_T)();

struct Func_Data {
    Func_Data func;
    char *func_name;
    struct Func_Data *next;
};

extern Func_Data func_arr[MAX_N];
extern int func_cnt;//变量也会出现重定义的情况
//TEST为宏，定义为一个用于测试的函数，因为一个程序中的函数函数名不可以重复，故写为

extern struct Func_Data head, *tail;
extern int func_cnt;

#define TEST(a, b)\
    void a##b();\
    __attribute__((constructor))\
    void add_##a##b() {\
        add_function(a##b, #a "." #b);
    }\
    void a##b()
#define EXPECT_EQ(a, b) {\
    if (a == b) {\
        printf("YES\n");\
    } else {\
        printf("NO\n");\
    }\
}

int RUN_ALL_TESTS();
void add_function(Func_T, const char *);

#endif
