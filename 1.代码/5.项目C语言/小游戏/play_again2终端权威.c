/*************************************************************************
	> File Name: play_again1.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月28日 星期四 19时59分50秒
 ************************************************************************/

 #include<stdio.h>
 #include<termios.h>
 #define Q "Do you want another try?"

int getresponse();

void tty_mode(); 
 
 int main() {
     int response;
     tty_mode(0);
     setcrmode();
     response = getresponse();
     tty_mode(1);
    printf("return val = %d\n", response);
     return response;
 }

 int getresponse() {
     printf("%s", Q);
     printf("YES or NO : ");
     switch (getchar()) {
         case 'y':
         case 'Y': return 1;
         case 'N' :
         case 'n' : return 0;
         default : return 0;
     }
 }

void setcrmode() {
    struct termios ttystate;
    tcgetattr(0,&ttystate);//取输入中端的
    ttystate.c_lflag &= ~ICANON;//将取道的改掉
    ttystate.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &ttystate);
}

void tty_mode (int how) {
    //how = 1还原 how = 0 保存
    static struct termios orignal_mode;
    if(how == 0) {
        tcgetattr(0, &orignal_mode);
    } else {
        tcgsetattr(0, TCSANOW, &orignal_mode);
    }
}
