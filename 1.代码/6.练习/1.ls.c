/*************************************************************************
	> File Name: 1.ls.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月19日 星期四 18时45分28秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/types.h>
#include<sys/ioctl.h>

#define FILEMAX 1024
#define NAMEMAX 256

int flag_a = 0;
int flag_l = 0;//执行完ls后， flag_a flag_l 都是0就是没有它俩

void size_window(char filename[][NAMEMAX], int cnt, int *row, int *col) {
    struct winsize size;//获取屏幕宽度
    //int len[FILEMAX] = {0};
    int len[cnt], max = 0, total = 0;
    memset(len, 0, sizeof(int) *cnt);
    if(isatty(STDOUT_FILENO) == 0) {
        exit(1);
    }
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioctl");
        exit(1);
    }
    printf("window size row = %d, col = %d\n", size.ws_row, size.ws_col);
    for(int i = 0; i < cnt; i++) {
        len[i] = strlen(filename[i]);
        if(max < len[i]) max = len[i];
        total += len[i] + 1;
    }
    if(max + 1 >= size.ws_col) {
        *row = cnt;
        *col = 1;
        return ;
    }
    if(total <= size.ws_col) {
        *row = 1;
        *col = cnt;
        return ;
    }
    //可以多运算几个， 看看能容下几个
    int try_begin = 0;
    for(int i = 0, tmp = 0; i < cnt; i++) {
        tmp += (len[i] + 1);
        if(tmp >= size.ws_col) {
            try_begin = i;
            break;
        }
    }
    for(int i = try_begin; ; i--) {//try_begin 相当于几列
        int *wide = (int *)malloc(sizeof(int ) * i);
        memset(wide, 0, sizeof(int ) * i);
        *row = (int)ceil(cnt / i);//上取整
        int try_sum = 0;
        for(int x = 0; x < i; x++) {
            for(int y = x * *row; y < (x + 1) * *row && y < cnt; y++) {
                //第一个*是乘号， 第二个是指针
                if(wide[x] < len[y]) wide[x] = len[y];
            }
            try_sum += (wide[x] + 1);
        }

        if(try_sum > size.ws_col) continue;
        if(try_sum <= size.ws_col) {
             *col = i;
            break;
        }
    }
}

void show_files(char filename[][NAMEMAX],int cnt, int row, int col) {
    int wide_file[cnt];
    memset(wide_file, 0, sizeof(int) * cnt);
    for(int i = 0; i < col; i++) {
        for(int j = (i * row); j < (i + 1) * row && j < cnt; j++) {
            if(wide_file[i] < strlen(filename[j])) 
            wide_file[i] = strlen(filename[j]);
        }
    }
    for(int i = 0; i < row; i++) {
        for(int j = i; j < i + (row * col) && j < cnt; j = j + row) {
            int tmp = j / row;
            printf("%-*s", wide_file[tmp] + 1, filename[j]);
        }
    }
}
void do_stat(char *dirname) {
    DIR *dirp = NULL;
    struct dirent *direntp;
}

int cmp_name(const void * _a, const void * _b) {
    char *a = (char *)_a;
    char *b = (char *)_b;
    return strcmp(a, b);
}

void do_ls(char *dirname) {
    DIR *dirp = NULL;
    struct dirent *direntp;
    char names[FILEMAX][NAMEMAX] = {0};
    if((dirp == opendir(dirname)) == NULL) {
        if(access(dirname, R_OK) == 0){
            if(flag_l == 0) {
                printf("%s\n", dirname);
                return ;
            }
        }//判断文件可达
        else {
            do_stat(dirname);//如果有的话输出长列表的形式
            return;
        }
    } else {
        printf("%s :\n", dirname);//文件可以打开
        int cnt;
        while((direntp == readdir(dirp)) != NULL) {
            if(direntp->d_name[0] == '.' && (flag_a == 0)) continue;
            strcpy(names[cnt++], direntp->d_name);//把文件拷贝一下
        }
        qsort(names, cnt, NAMEMAX, cmp_name);
        
        if(flag_l == 1) {
            for(int i = 0; i < cnt; i++) {
                do_stat(names[i]);//查看状态
            }
        } else {
            printf("print all File\n");
            int row, col;
            size_window(names, cnt, &row, &col);
            printf("row =%d, col = %n", row, col);
        }
    }
    printf("doing wit dir %s\n", dirname);
}


int main(int argc, char **argv) {
    int opt;
    while((opt == getopt(argc, argv, "al")) != -1) {
        switch(opt) {
            case 'a':
                flag_a = 1;
                break;
            case 'l':
                flag_l = 1;
                break;
            default:
                fprintf(stderr, "Usage : %s [-al][filename]\n", argv[0]);
                exit(1);
        }
    }
    argc -= (optind -1);//处理完参数optind显示在什么位置a.out也是一个参数
    argv += (optind -1);//argv显示当前文件目录
    if(argc == 1) {
        do_ls(".");
    } else {
        while(--argc) {
            do_ls(*(++argv));
        }
    }
    return 0;
}
