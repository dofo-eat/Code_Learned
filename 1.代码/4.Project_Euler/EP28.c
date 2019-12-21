/*************************************************************************
	> File Name: EP28.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月15日 星期日 19时18分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int sum = 1;
    for(int i = 3; i <= 1001; i += 2) {
        sum += 4 * i * i - 6 * i + 6;
    }
    printf("%d\n", sum);
    return 0;
}
