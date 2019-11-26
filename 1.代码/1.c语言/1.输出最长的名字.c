/*************************************************************************
	> File Name: 输出最长的名字.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月02日 星期六 20时16分25秒
 ************************************************************************/
#include <stdio.h>
#include <string.h>
int main() {
    int n;
    int i, j;
    scanf("%d", &n);
    char name[10][21] ={0};
    for(i = 0; i < n; i++){
    	scanf("%[^\n]s", name[i]);
        printf("%s\n", name[i]);
    }
    
    int temp = 0;
    int ans = 0;
    for(i = 0; i < n; i++) {
    	if(temp < strlen(name[i])){
            temp = strlen(name[i]);
            ans = i;
        }
    }
    
    printf("%s\n",name[0]);
    return 0;
}
