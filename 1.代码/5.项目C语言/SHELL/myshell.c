/*************************************************************************
	> File Name: myshell.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月14日 星期二 08时39分51秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/utsname.h>

const int max_name_len = 256;
const int max_path_len = 1024;

/*void type_prompt(char *prompt)
{
    struct passwd *pwd;
    char hostname[max_name_len];
    char pathname[max_path_len];
    int length;
    pwd = getpwuid(getuid());
    getcwd(pathname,max_path_len);
    length = strlen(prompt);
}*/

 char *argv[8];
 int argc = 0;
 void do_shell()
 {
     pid_t pid;
     if((pid = fork())  < 0 ){
         perror("fork");
        exit(1);
     }
     if(pid == 0){
         execvp(argv[0],argv);
         perror("execvp");
     }else {
         int st;
         while(wait(&st) != pid);
     }
 }
 void do_parse(char *buf)
 {
     int start = 0;
     int i=0;
    argc = 0;
     while(buf[i])
     {
         if(!isspace(buf[i]) && start == 0){
            argv[argc++] = buf+i;
            start = 1;
        }
        else if(isspace(buf[i]) && start == 1){
            start = 0;
            buf[i] = '\0';
        }

        i++;
    }
    argv[argc++] = NULL;

}
int main()
{
    char buf[1024];
    while(1){
        printf("[suxinxin@myshell> ]:");
        scanf("%[^\n]%*c",buf);
       // type_prompt(buf);
        do_parse(buf);
        do_shell();
         
    }

}

