/*************************************************************************
	> File Name: 9.expre_cale.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月18日 星期二 14时28分01秒
 ************************************************************************/
#include<stdio.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>
#define max_n 100


int calc(const char *str, int l, int r) {
    int prior = 0x3f3f3f3f - 1, temp = 0, pos = -1;// 当前优先级定义一个最大的量, pos最低优先符号位置
    for(int i = l; i <= r; i++ ) {
        int current_prior =  0x3f3f3f3f;
        switch(str[i]) {
            case '(' : temp += 100; break;
            case ')' : temp -= 100; break;//temp +-优先级等级
            case '+' :
            case '-' : current_prior = temp + 1;break;
            case '*' :
            case '/' : current_prior = temp + 2;break;
            case '^':current_prior = temp + 3;break;
        }
        if(current_prior <= prior) {
            prior = current_prior;
            pos = i;
        }
    }
    if(pos ==  -1) {
        int num = 0;
        for(int i = l; i <= r; i++) {
            if(str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    }
    int a = calc(str, l, pos - 1);
    int b = calc(str, pos + 1, r);
    switch(str[pos]) {
        case '+':return a + b;
        case'-':return a - b;
        case '*':return a * b;
        case '/':return a / b;
        case '^':return (int)pow(a, b);
    }
    return 0;
}

int main () {
    char str[max_n + 5] = {0};
    while(scanf("%[^\n]s", str) != EOF) {
        getchar();
        printf("%d\n", calc(str, 0, strlen(str) - 1));
    }
}
