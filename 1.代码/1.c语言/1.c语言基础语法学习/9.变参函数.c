/*************************************************************************
	> File Name: 9.变参函数.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月07日 星期六 16时26分51秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<inttypes.h>
#include<stdarg.h>

int max_int(int n, ...) {//...参数列表
    va_list arg;
    va_start(arg, n);
    int ans = INT32_MIN;
    while(n--) {
        int temp = va_arg(arg, int);
        temp > ans && (ans = temp);
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_int(3, 3, 5, 16));
    printf("%d\n", max_int(3, 3, 5, 16, 21));
    printf("%d\n", max_int(3, 3, 5, 21, -32));
    return 0;
}
