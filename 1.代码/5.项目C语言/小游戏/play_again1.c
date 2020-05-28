/*************************************************************************
	> File Name: play_again1.c
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月28日 星期四 19时59分50秒
 ************************************************************************/

 #include<stdio.h>
 #define Q "Do you want another try?"

int getresponse();

 int main() {
     int response;
     response = getresponse();
    
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
