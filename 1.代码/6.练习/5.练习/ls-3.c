/*************************************************************************
	> File Name: ls-3.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月17日 星期二 11时42分27秒
 ************************************************************************/
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>


void do_ls(char[]);


int main(int argc, char **argv) {
    if(argc == 1) {
        do_ls(".");
        //printf("No\n");
    } else {
        while(--argc) {
            printf("%s:\n", *++argv);
            do_ls(*argv);
        }
    }
    return 0;
}

void do_ls(char dirname[]) {
    DIR *dirp;
    struct dirent *direntp;

    if((dirp = (opendir(dirname))) == NULL) {
        perror("opendir");
        return ;
    }
    while((direntp = readdir(dirp)) != NULL) {
        printf("%s ", direntp->d_name);
    }
    closedir(dirp);
    printf("\n");
}

