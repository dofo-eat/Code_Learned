/*************************************************************************
	> File Name: OJ122.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月07日 星期四 17时41分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    int h, m, s;
    if(t > 3600) {
        h = t / 3600;
        m = (t - (h * 3600)) / 60;
        s = t % 60;   
    }else{
        m = t / 60;
        s = t % 60;
    }
    if(h > 24) {
        if(h % 24 == 0) {
            printf("%02d:%02d:%02d am", h % 12, m, s);
        }else if((h % 24) >=  12 && (h % 24) < 13){
            printf("%02d:%02d:%02d midnoon", h, m, s);
        }else{
            printf("%02d:%02d:%02d pm", h - 12, m, s);
        }
    }else{
        if(h >= 0 && h < 12) {
            printf("%02d:%02d:%02d am", h, m, s);
        }else if(h >= 12 && h < 13){
            printf("%02d:%02d:%02d midnoon", h, m, s);
        }else{
            printf("%02d:%02d:%02d pm", h - 12, m, s);
        }
    }
    return 0;   
}
