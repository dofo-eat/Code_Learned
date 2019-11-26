/*************************************************************************
	> File Name: OJ174.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月16日 星期六 16时53分32秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char a[10001] = {0};
    char bstr[10001] = {0};
    char change[] = "%20";
    char sear[] = " ";
    scanf("%[^\n]s",a);
    for(int i = 0; i < strlen(a); i++) {
        if(!strncmp(a + i,sear,strlen(sear))) {
            strcat(bstr,change);
            i += strlen(sear) - 1;
        }else{
            strncat(bstr,a + i, 1);
        }
    }
    strcpy(a,bstr);
    printf("%s",a);
    return 0;
}
