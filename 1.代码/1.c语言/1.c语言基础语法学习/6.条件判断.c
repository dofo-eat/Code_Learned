/*************************************************************************
	> File Name: 6.条件判断.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月03日 星期二 20时09分16秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a - b) {
        printf("not equal\n");
    }else{
        printf("equal\n");
    }
    if((a++) && (b++)) {//同理如下
        printf("true\n");
    }else{
        printf("flase\n");
    }
    if((a++) || (b++)) {//a++为真时不再先后进行判断因为或（||）
        printf("true");
    }else{
        printf("flase");
    }
    printf("a = %d, b = %d\n", a, b);
    for(int i = 0; i < 10; i++) {
        i && printf(" ");
        printf("%d", i);
    }
    printf("\n");
    int cnt = 0;
    for(int i = 0; i < 10; i++) {
        int val = rand() % 100;
        cnt += !(val & 1);
        i == 0 || printf(" ");
        printf("%d",val);
    }
    printf("\n");
    printf("even numbers : %d\n", cnt);
    return 0;
}
