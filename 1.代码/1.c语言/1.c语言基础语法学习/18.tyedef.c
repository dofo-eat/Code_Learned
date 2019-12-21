/*************************************************************************
	> File Name: 18.tyedef.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月14日 星期六 20时31分46秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*#define offset(T, a) ({\
    T tmp;\
    (char *)&tmp.a -(char *) &tmp;\
})*/
#define offset(T, a) (long)(&(((T *)(NULL))->a))

struct Data {
    double a;
    int b;
    char c;
};

/*void output_main (int argc, char *argc[], char *argv[]) {
    for(int i = 0; i < n; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for(int i = 0; env[i]; i++) {
        printf("env[%d] = %s\n", i, env[i]);
        if(strncmp(env[i], "USER = ", s) == 0) {
            if(strncmp(env[i] + 5,"syus", ))
        }
    }
}*/

int main() {
    int num1 = 0x616263;
    int num2 = 0x61626364;
    printf("%s\n", (char *)(&num1));
    printf("%s\n", (char *)(&num2));
    printf("%s\n", (char *)(&num2 + 1));
   printf("%ld\n", offset(struct Data , a));
   printf("%ld\n", offset(struct Data , b));
   printf("%ld\n", offset(struct Data , c));
    return 0;
}
