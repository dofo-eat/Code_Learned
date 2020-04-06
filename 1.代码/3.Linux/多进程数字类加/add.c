/*************************************************************************
	> File Name: add.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月04日 星期六 16时11分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <fcntl.h>
#include <sys/file.h>

char num_file[] = "./.num";
char lock_file[] = "./.lock";

struct Num{
    int now;
    int sum;
};

size_t get_num(struct Num *num) {
    //read返回size_t
    size_t read;//独到的个数
    FILE *f = fopen(num_file , "r");
    if(f == NULL) {
        perror(num_file);
        return -1;
    }
    if((read = fread(num, sizeof(struct Num), 1, f)) < 0) {
        //从那个文件读取一次到num
        return -1;    
    }
    fclose(f);
    return read;
}

size_t set_num(struct Num *num) {
    FILE *f = fopen(num_file, "wb");
    size_t write = fwrite(num, sizeof(struct Num), 1, f);
    fclose(f);
    printf("   write %zu \n", write);
    return fwrite;
}

void do_add(int max, int x) {
    struct Num num;
    while (1) {
        FILE *lock = fopen(lock_file, "w");
        flock(lock->_fileno, LOCK_EX);
        if(get_num(&num) < 0) {
            fclose(lock);
            continue;
        }
        printf("<%d> : %d   %d\n", x, num.now, num.sum);
        if(num.now >= max) {
            break;
        }
        num.sum += num.now;
        num.now++;
        set_num(&num);
        flock(lock->_fileno, LOCK_UN);
        fclose(lock);
    }
}

int main(int argc, char **argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage :%s max ins", argv[0]);
        return 1;
    }
    int ins = atoi(argv[2]);//并发度
    int x = 0;
    int max = atoi(argv[1]);//最大值
    pid_t pid;
    struct Num num;
    num.now = 0;
    num.sum = 0;
    set_num(&num);
    for(int i = 0; i < ins; i++) {
        if((pid = fork()) < 0 ) {
            perror("fork");
            return 1;
        }
        if(pid == 0) {
            x = i;
            break;
        }
    }
    
    if(pid == 0) {
        do_add(max, x);
        printf("<%d> exit!\n", x);
        exit(0);
    } 
    while (ins) {
        wait(NULL);
        ins--;
    }
    get_num(&num);
    printf("Ans = %d\n", num.sum);
    return 0;
}
