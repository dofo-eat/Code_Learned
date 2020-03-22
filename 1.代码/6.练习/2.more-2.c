/*************************************************************************
	> File Name: 2.more-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月21日 星期六 20时10分26秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#define LENLINE 512
//一页多少行
//#define PAGELINE 10
//一行有多长

int PAGELINE;
void do_more(FILE *fp); 

int main(int argc, char **argv) {
    struct winsize size;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
    PAGELINE = size.ws_row;
    FILE *fp;//文件指针
    //没有选项
    if (argc == 1) 
        do_more(stdin);   
    // printf("Usage: %s [filename | stdin]\n", argv[0]);
    else {
        while (--argc) {
            if ((fp = fopen(*++argv, "r")) != NULL) {
                do_more(fp);
            }
        }
    }
    return 0;
}

void do_more(FILE *fp) {//流文件
    char line[LENLINE] = {0};
    FILE *cmd = fopen("/dev/tty","r");
    int num_line = 0, reply, get_cmd(FILE *);
    while (fgets(line, LENLINE, fp)) {
        if (num_line == PAGELINE) {
            reply = get_cmd(cmd);
            if (reply == 0) break;
            num_line -= reply;
        }
        if (fputs(line, stdout) == EOF) {
            perror("fputs");
            exit(1);
        }
        num_line++;
    }

}

int get_cmd(FILE *fp) {
    printf("more:");
    int c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == 'q') return 0;
        if (c == ' ') return PAGELINE;
        if (c == '\n') return 1;
    }
    return -1;
}
