/*************************************************************************
	> File Name: OJ125.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月17日 星期日 17时51分00秒
 ************************************************************************/

#include <stdio.h>
int main() { 
    int h, m, s, t;
    scanf("%d %d %d %d", &h, &m, &s, &t);
    s += t;
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
    h %= 24;
    if(h >= 12 ) {
        h != 12 && (h %= 12);
        printf("%d:%d:%dpm\n", h, m, s);
    }
    else{
        !h && (h += 12);
        printf("%d:%d:%dam\n", h, m, s);
    } 
    printf("%.2f%c", t * 1.0 / 864, '%');
    return 0;
}

