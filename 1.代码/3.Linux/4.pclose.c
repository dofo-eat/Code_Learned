/*************************************************************************
	> File Name: 4.pclose.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月09日 星期四 17时01分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main() {
    int pclose(FILE *fp) {
        int fd, stat;
        pid_t pid;
        fd = fileno(fp);
        if(fclose(fp) == EOF) {
            return -1;
        }
    }    
    return 0;
}
