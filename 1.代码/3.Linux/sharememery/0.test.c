/*************************************************************************
	> File Name: 0.test.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月09日 星期四 20时27分52秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

void seconds_sleep(unsigned seconds){
        struct timeval tv;
        tv.tv_sec=seconds;
        tv.tv_usec=0;
        int err;
        err=select(0,NULL,NULL,NULL,&tv);

}

int main(void){
    fd_set rfds;
    struct timeval tv;
    int retval;

           /* Watch stdin (fd 0) to see when it has input. */
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);

           /* Wait up to five seconds. */
    tv.tv_sec = 5;
    tv.tv_usec = 0;
            
    retval = select(1, &rfds, NULL, NULL, &tv);
           /* Don't rely on the value of tv now! */

    if (retval == -1)
        perror("select()");
    else if (retval){
        char buf[512] = {0};
        printf("Data is available now.\n");
        scanf("%s", &buf);
    }//内核只是可以感知到可以读， 但是还没写入
               /* FD_ISSET(0, &rfds) will be true. */
   else
        printf("No data within five seconds.\n");
    exit(EXIT_SUCCESS);
}


