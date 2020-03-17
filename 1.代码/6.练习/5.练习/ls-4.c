/*************************************************************************
	> File Name: ls-4.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月17日 星期二 17时23分13秒
 ************************************************************************/

#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


void do_ls(char *dirname);//目录
void dostat(char *filename);//文件
void show_file_info(char *filename, struct stat *info_p);
void mode_to_letters(int mode, char * str);
char *uid_to_name(uid_t uid);
char *gid_to_name(gid_t gid);

int main(int argc , char *argv[]) {
    if (argc == 1) {
        do_ls(".");
    }else {
        while (--argc) {
            printf("%s:\n", *++argv);
            chdir(*argv);
            do_ls(*argv);
            chdir("");
        }
    }
    return 0;
}


void do_ls (char dirname[]) { 
    DIR *dirp;
    struct dirent *direntp;
    if ((dirp = opendir(dirname)) == NULL) {
    fprintf(stderr,"ls: cannot open %s, not a directory. treat as a file shown below:\n", dirname);
        dostat( dirname );
    }else {
        while ( (direntp = readdir (dirp )) != NULL) {
            dostat (direntp->d_name);
        }
        closedir (dirp);
    }
}

void dostat (char *filename) {
    struct stat info;
    if (stat (filename, &info) == -1) {
        perror (filename);
    }else{
        show_file_info(filename, &info);
    }
}

void show_file_info(char *filename, struct stat *info_p) {
    char modestr[12];
    mode_to_letters (info_p->st_mode, modestr);
    printf ("%s", modestr);
    printf("%4d "  , (int) info_p->st_nlink);
    printf("%-8s " , uid_to_name(info_p->st_uid));
    printf("%-8s " , gid_to_name(info_p->st_gid));
    printf("%8ld " , (long)info_p->st_size);
    printf("%.12s ", 4+ctime(&info_p->st_mtime));
    printf("%s\n" , filename);
}

void mode_to_letters (int mode, char * str) {
    strcpy(str, "----------");           
    if (S_ISDIR(mode))
    str[0] = 'd';    
    if (S_ISCHR(mode))
    str[0] = 'c';    
    if (S_ISBLK(mode))
    str[0] = 'b';    
    if (mode & S_IRUSR)
    str[1] = 'r';    
    if (mode & S_IWUSR)
    str[2] = 'w';
    if (mode & S_IXUSR)
    str[3] = 'x';
    if (mode & S_IRGRP)
    str[4] = 'r';    
    if (mode & S_IWGRP)
    str[5] = 'w';
    if (mode & S_IXGRP)
    str[6] = 'x';
    if (mode & S_IROTH)
    str[7] = 'r';    
    if (mode & S_IWOTH)
    str[8] = 'w';
    if (mode & S_IXOTH)
   str[9] = 'x';
}

char *uid_to_name (uid_t uid) {
    struct passwd *pw_str;
    static  char numstr[12];
    if ((pw_str = getpwuid(uid)) == NULL) {
        sprintf (numstr, "%d", uid);
        return numstr;
    }else {
        return pw_str->pw_name ;
    }
}

char *gid_to_name (gid_t gid) {
    struct group *grp_ptr;
    static char numstr[12];
    if ((grp_ptr = getgrgid(gid)) == NULL) {
        sprintf(numstr, "%d", gid);
        return numstr;
    } else {
        return grp_ptr->gr_name;
    }
}


