/*************************************************************************
	> File Name: 17.IP转整数.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月14日 星期六 19时07分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

union IP{
    unsigned int num;
    struct {
        unsigned char a1;
        unsigned char a2;
        unsigned char a3;
        unsigned char a4;
    }ip;
};

int main() {
    union IP p;
    char str[25];
    unsigned int arr[4];
    while(~scanf("%s", str)) {
        sscanf(str, "%d. %d. %d. %d",arr, arr + 1, arr + 2, arr + 3);   
        p.ip.a1 = arr[0];
        p.ip.a2 = arr[1];
        p.ip.a3 = arr[2];
        p.ip.a4 = arr[3];//大端机使用这种输入形式
        //小端机器使用p.ip.a1 = arr[0][1][2][3] 这种形式
        printf("%u\n", p.num);
    }
    return 0;
}
