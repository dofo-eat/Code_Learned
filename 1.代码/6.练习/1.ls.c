/*************************************************************************
	> File Name: 1.ls.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月21日 星期六 15时31分08秒
 ************************************************************************/
/*************************************************************************
    > File Name: ls.c
    > Author: 
    > Mail: 
    > Created Time: 2020年03月19日 星期四 18时49分06秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#define FILEMAX 1024
#define NAMEMAX 256

int flag_a = 0;
int flag_l = 0;
int dir_num = 0;

void size_window(char filename[][NAMEMAX], int cnt, int* row, int* col){
    struct winsize size;
    int len[cnt], max = 0, total = 0;//len[cnt]每个文件名字长度
    memset(len, 0, sizeof(int) * cnt);
    if (isatty(STDOUT_FILENO) == 0) {//isatty判断是否是终端
        exit(1);
    }

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {//ioctal获得屏幕宽度
        perror("ioctl");
        exit(1);
    }
    printf("window size row = %d, col = %d\n", size.ws_row, size.ws_col);

    for (int i= 0; i < cnt; i++) {//让数组存每个文件名字长度
        len[i] = strlen(filename[i]);
        if (max < len[i]) max = len[i];//求得最大文件名字
        total += len[i] + 1;//total总长度
    }
    if (max + 1 >= size.ws_col) {
        //如果最长的文件名加一个空格已经大于了终端宽度，意为只能有一列
        *row = cnt;
        *col = 1;
        return ;
    }
    if (total <= size.ws_col) {
        //如果所有文件名加起来还没到终端宽度，意为只有一行
        *row = 1;
        *col = cnt;
        return ;
    }
    //寻找最多放几列
    int try_begin = 0;
    for (int i = 0, tmp = 0; i < cnt; i++) {
        tmp += (len[i] + 1);//这一行的长度
        if (tmp >= size.ws_col) {
            try_begin = i;
            break;
        }
    }

    for (int i = try_begin; ;i--) {
        int *wide = (int *)malloc(sizeof(int) * i);//wide每一列的宽度
        memset(wide, 0, sizeof(int) * i);
        *row = (int)ceil(cnt / i);//上取整
        int try_sum = 0;
        for (int x = 0; x < i; x++) {
            for (int y = x * *row; y < (x + 1) * *row && y < cnt; y++) {
                //求每一列初始位置，第一个*是乘，第二个*是对row取值
                if (wide[x] < len[y]) wide[x] = len[y];
                //wide[x]第i列第x行的宽度，len[y]文件名字长度
            }
            try_sum += (wide[x] + 1);
        }

        if (try_sum > size.ws_col) continue;//大于终端宽度
        if (try_sum <= size.ws_col) {
            *col = i;
            break;
        }
    }
}


void show_files(char filename[][NAMEMAX], int cnt, int row, int col) {
    int wide_file[cnt];// 
    memset(wide_file, 0, sizeof(int) * cnt);
    for(int i = 0; i < col; i++) {//wide_file[i]用来记录每一列宽度
        for (int j = (i * row); j < (i + 1) * row && j < cnt; j++) {
            if (wide_file[i] < strlen(filename[j])) wide_file[i] = strlen(filename[j]);//最大宽度

        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = i; j < i + (row * col) && j < cnt; j = j + row) {
            int tmp = j / row;
            printf("%-*s", wide_file[tmp] + 1, filename[j]);
        }
            printf("\n");
        }
}

void mode_to_str(mode_t mode, char *str) {
    if (S_ISREG(mode)) str[0] = '-';
    if (S_ISDIR(mode)) str[0] = 'd';
    if (S_ISCHR(mode)) str[0] = 'c';
    if (S_ISBLK(mode)) str[0] = 's';
    if (S_ISSOCK(mode)) str[0] = 'l';
    if (S_ISLNK(mode)) str[0] = 'b';
    if (S_ISFIFO(mode)) str[0] = 'p';

    if (mode & S_IRUSR) str[1] = 'r';
    if (mode & S_IWUSR) str[2] = 'w';
    if (mode & S_IXUSR) str[3] = 'x';

    if (mode & S_IRGRP) str[4] = 'r';
    if (mode & S_IWGRP) str[5] = 'w';
    if (mode & S_IXGRP) str[6] = 'x';

    if (mode & S_IROTH) str[7] = 'r';
    if (mode & S_IWOTH) str[8] = 'w';
    if (mode & S_IXOTH) str[9] = 'x';

    if ((mode & S_IXUSR) && (mode & S_ISUID)) str[3] = 's';
}

char *uid_to_name(uid_t uid) {
    struct passwd *pw_ptr;
    static char tmpstr[10] = {0};
    if ((pw_ptr = getpwuid(uid)) == NULL) {
        sprintf(tmpstr, "%d", uid);
        return tmpstr;
    } else {
        return pw_ptr->pw_name;
    }
}

char *gid_to_name(gid_t gid) {
    struct group *gr_ptr;
    //static 全局静态变量
    static char tmpstr[10] = {0};
    if ((gr_ptr = getgrgid(gid)) == NULL) {
        sprintf(tmpstr, "%d", gid);
        return tmpstr;
    } else {
        return gr_ptr->gr_name;
    }

}

void show_info(char *filename, struct stat *info) {
    //printf("%s\n", filename);
    char modestr[11] = "----------";
    mode_to_str(info->st_mode, modestr);
    printf("%s ", modestr);
    printf("%4d ", info->st_nlink);
    printf("%10s ", uid_to_name(info->st_uid));
    printf("%10s ", gid_to_name(info->st_gid));
    printf("%10lld ", info->st_size);
    //字符串首地址，从第四个开始输出，为了不输出周几,周几的英文占3位
    printf("%.15s ", 4 + ctime(&info->st_mtime));
    printf("%s\n", filename);
}

void do_stat(char *filename) {
    struct stat st;
    if (stat(filename, &st) < 0) {
        perror(filename);
    } else {
        show_info(filename, &st);
    }
    //printf("Doing with %s status.\n", filename);
}

int cmp_name(const void* _a, const void* _b) {
    char *a = (char *)_a;
    char *b = (char *)_b;
    return strcmp(a, b);
}

void do_ls(char *dirname) {
    DIR *dirp = NULL;
    struct dirent *direntp;
    char names[FILEMAX][NAMEMAX] = {0};//存文件的名字
    if ((dirp = opendir(dirname)) == NULL) {//为空，代表不是一个目录而是一个文件
        if (access(dirname, R_OK) == 0) {//可读
            if (flag_l == 0) {
                dir_num--;
                printf("\033[0;31m%s\033[0m\n", dirname);//无l直接输出名字
                return;
            } else {
                do_stat(dirname);//有l用stat输出详细信息
                return;
            }
        } else {
            perror(dirname);
            return ;
        }
    } else {
        printf("%s:\n", dirname);
        chdir(dirname);
        int cnt = 0;
        while((direntp = readdir(dirp)) != NULL) {//一直读到目录流末尾
            //判断文件名中如果有叫'.'的文件
            //如果有选项a就可以输出该隐藏文件，没有a就不用输出直接cintinue
            if (direntp->d_name[0] == '.' && (flag_a == 0)) continue;
            strcpy(names[cnt++], direntp->d_name);//将文件名字放进数组中
        }
        qsort(names, cnt, NAMEMAX, cmp_name);//qsort直接返回按字母序排好的结构

        if (flag_l == 1) {//有l选项
            for (int i = 0; i < cnt; i++) {
                do_stat(names[i]);//查看全部信息
            }
        } else {
            printf("Print all file\n");
            int row, col;
            size_window(names, cnt, &row, &col);
            printf("row = %d, col = %d\n", row, col);
            show_files(names, cnt, row, col);
        }

    }

    printf("Doing with dir %s.\n", dirname);
}


int main(int argc, char **argv) {
    int opt;
    while((opt = getopt(argc, argv, "al")) != -1) {
        //照着al如果是a就flag_a=1，bflag_b=1，都不是就报错
        switch (opt) {
            case 'a':
            flag_a = 1;
                break;
            case 'l':
                flag_l = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s [-al] [filename]\n", argv[0]);
                exit(1);
        }
    }

    printf("flag_a = %d, flag_l = %d\n", flag_a, flag_l);

    printf("optind = %d \n", optind);

    argc -= (optind - 1);
    argv += (optind - 1);//optind是处理完选项，也就是减去了选项个数后的参数

    //printf("argc = %d \nargv=%s\n",argc,  *(argv + 1));

    if (argc == 1) {//没有参数
        do_ls(".");//输出当前目录下的文件
    } else {
        while(--argc) {
            do_ls(*(++argv));//argv先加1，指的就是选项后的第一个参数
        }
    }

    return 0;
}
 
