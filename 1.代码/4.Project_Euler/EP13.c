/*************************************************************************
	> File Name: EP13.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月21日 星期六 15时58分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N 52

char str[N + 5] = {0};
int ans[N + 5] = {0};

int main() {
    while(~scanf("%s", str)) {
        int len = strlen(str);
        if(len > ans[0]) ans[0] = len;
        for(int i = 0; i < len; i++) {
            ans[len - i] += str[i] - '0';
        }
        for(int i = 1; i <= ans[0]; i++) {
            if(ans[i] < 10) continue;
            ans[i + 1] += ans[i]/ 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
            /*if(i == ans[0]) {
                ans[0] +=  1;
            }*/
        }
    }
    for(int i = ans[0]; i > ans[0] - 10; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
