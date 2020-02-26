/*************************************************************************
	> File Name: 实现ls-2.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年01月30日 星期四 17时47分58秒
 ************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(char *dir, int depth)
{
        DIR *dp;
        struct dirent *entry;
        struct stat statbuf;

        if((dp = opendir(dir)) == NULL)
    {
                fprintf(stderr, "cannot open directory: %s\n", dir);
                return;
            
    }
        chdir(dir);
        while((entry = readdir(dp)) != NULL)
    {
                lstat(entry->d_name, &statbuf);
                if(S_ISDIR(statbuf.st_mode))
        {
                        if(strcmp(".", entry->d_name) == 0 ||
                                          strcmp("..", entry->d_name) == 0)
                            continue;
                        printf("%*s%s/\n", depth, "", entry->d_name);
                        printdir(entry->d_name, depth+4);
                    
        }
                else printf("%*s%s\n", depth, "", entry->d_name);
            
    }
        chdir("..");
        closedir(dp);

}

int main(int argc, char* argv[])
{
        char *topdir = ".";
        if (argc >= 2)
            topdir = argv[1];
        printdir(topdir, 0);
        exit(0);
    //
}
