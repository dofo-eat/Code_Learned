/*************************************************************************
	> File Name: 2.more.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月21日 星期六 18时59分40秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define PAGLINE 10//定义每次输入10行
#define LENLINE 512//一行有多长

int get_cmd() {
    printf("more :");
    char c;
    while((c = getchar()) != EOF) {
        if(c == 'q') return 0;
        if(c == ' ') return 1;
        if(c == '\n') return 2;
    }
}

void do_more(FILE *fp) {
    char line[LENLINE] = {0};
    int num_line = 0, reply;//有多少行, 接受键盘输入
    while (fgets(line, LENLINE, fp)) {
        if(num_line == PAGLINE) {
            reply = get_cmd();
            if(reply == 0) break;
        }
        if(fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    if(argc == 1) {
        printf("Usage: %s [filename | stdin]", argv[0]);//标准输入
    } else {
        while(--argc) {
            if((fp == fopen(*++argv, "r")) != NULL) {
                do_more(fp);
            }
        }
    }
    return 0;
}
