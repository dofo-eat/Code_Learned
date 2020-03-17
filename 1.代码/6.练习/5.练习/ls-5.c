/*************************************************************************
	> File Name: ls-5.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月17日 星期二 17时37分27秒
 ************************************************************************/

#include <stdio.h> 
#include <sys/types.h> 
#include <dirent.h> 
#include <sys/stat.h> 
#include <string.h> 
  
void do_ls(char[]); 
void dostat(char *); 
void show_file_info( char *, struct stat *); 
void mode_to_letters( int , char[] ); 
char * uid_to_name( uid_t ); 
char * gid_to_name( gid_t ); 
  
  
main(int ac, char *av[]) 
{ 
    if( ac == 1 ) 
    do_ls( "." );          /*显示当前目录*/ 
    else 
    while( --ac ){ 
        printf("%s:\n", *++av);   /*显示参数指定的目录*/ 
        do_ls( *av ); 
    } 
} 
  
  
void do_ls( char dirname[] ) 
{ 
    DIR *dir_ptr; 
    struct dirent *direntp; 
  
    if( (dir_ptr = opendir( dirname )) == NULL)            /*打开目录,成功则返回 DIR 结构指针*/ 
    fprintf(stderr, "ls1: cannot open %s\n", dirname); 
      
    else 
    { 
    while( ( direntp = readdir( dir_ptr ) ) != NULL ) 
         dostat( direntp->d_name ); 
  
    closedir( dir_ptr ); 
    } 
} 
  
void dostat( char *filename ) 
{ 
    struct stat info; 
  
    if( stat( filename, &info ) == -1 ) 
    perror( filename ); 
    else 
    show_file_info( filename, &info ); 
} 
  
void show_file_info( char *filename, struct stat *info_p ) 
{ 
 
   if(filename[0]!='.')
   {
    char *uid_to_name(), *ctime(), *gid_to_name(), *filemode(); 
    void mode_to_letters(); 
  
    char modestr[11]; 
  
    mode_to_letters( info_p->st_mode, modestr );      /*模式到字符的转换*/ 
  
    printf("%s", modestr );                           /*输出模式标识符*/ 
  
    printf("%4d", (int)info_p->st_nlink); 
  
    printf(" %-8s", uid_to_name(info_p->st_uid)); 
  
    printf("%-8s", gid_to_name(info_p->st_gid)); 
  
    printf("%8ld  ", (long)info_p->st_size); 
  
    printf("%.12s ", 4 + ctime(&info_p->st_mtime)); 
  
    printf("%s\n",filename);   
   }    
  
} 
  
  
void mode_to_letters( int mode, char str[] ) 
{ 
    strcpy(str,"----------"); 
  
    if( S_ISDIR(mode) ) str[0] = 'd';                 /*目录*/ 
    if( S_ISCHR(mode) ) str[0] = 'c';                 /*字符文件*/ 
    if( S_ISBLK(mode) ) str[0] = 'b';                 /*块文件*/ 
  
    if(mode & S_IRUSR)  str[1] = 'r'; 
    if(mode & S_IWUSR)  str[2] = 'w'; 
    if(mode & S_IXUSR)  str[3] = 'x'; 
      
    if(mode & S_IRGRP)  str[4] = 'r'; 
    if(mode & S_IWGRP)  str[5] = 'w'; 
    if(mode & S_IXGRP)  str[6] = 'x'; 
  
    if(mode & S_IXOTH)  str[7] = 'r'; 
    if(mode & S_IXOTH)  str[8] = 'w'; 
    if(mode & S_IXOTH)  str[9] = 'x'; 
} 
  
#include <pwd.h> 
  
    char *uid_to_name( uid_t uid ) 
/* 
*返回和 uid 相应的用户名的指针 
*/ 
    { 
    struct passwd *getpwuid(), *pw_ptr; 
    static char numstr[10]; 
  
    if( ( pw_ptr = getpwuid( uid ) ) == NULL ) { 
        sprintf(numstr, "%d", uid);      /*没有对应的用户名则 uid 存入 numstr,返回后以字符串的形式打印 uid*/ 
        return numstr; 
    } 
    else 
        return pw_ptr->pw_name;          /*打印用户名*/ 
    } 
  
  
#include <grp.h> 
  
    char *gid_to_name( gid_t gid ) 
    { 
    struct group *getgrgid(), *grp_ptr; 
    static char numstr[10]; 
  
    if( ( grp_ptr = getgrgid(gid) ) == NULL ){ 
  
        sprintf(numstr, "%d", gid); 
        return numstr; 
    } 
    else 
        return grp_ptr->gr_name; 
    } 
