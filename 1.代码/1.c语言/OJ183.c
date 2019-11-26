/*************************************************************************
	> File Name: OJ183.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 14时29分53秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int f(int x) {
    if(x == 0) {
        return 0;
    }else if(x == 1) {
        return 1;
    }else if(x > 1 && x % 2 == 0) {
        return 3 * f(x / 2) - 1;
    }else if(x > 1 && x % 2 == 1) {
        return 3 * f((x + 1) / 2) - 1;
    }

}
int main() {
    int x;
    scanf("%d", &x);
    int sum = f(x);
    printf("%d", sum);
    return 0;
}
