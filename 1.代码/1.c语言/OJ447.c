/*************************************************************************
	> File Name: OJ447.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月05日 星期四 20时03分09秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int a[1001] = {0};

void luck() {
    for(int j = 4; j < 1000; j++) {
        int flag = 0;
        int i = j;
        while(i) {
            if(i % 10 != 4 && i % 10 != 7) {
                flag = 1;
                break;
            }
            i /= 10;
        }
        if(!flag) {
            a[++a[0]] = j; 
        }
    }
}

int main() {
    luck();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= a[0];i++) {
        if(n % a[i] == 0){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
