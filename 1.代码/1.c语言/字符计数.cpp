/*************************************************************************
	> File Name: 字符计数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月10日 星期二 21时13分10秒
 ************************************************************************/
#include <stdio.h>
void upper_case_count(char arr[31]) {
    // 请在下面实现统计并输出大写字母个数的功能
    int i, sum = 0;
    for(i = 0; i < 31; i++){
        if(arr[i] >= 'A' && arr[i] <= 'Z') {
            sum++;
        }
    }
    printf("%d\n",sum);
}
void lower_case_count(char arr[31]) {
    // 请在下面实现统计并输出小写字母个数的功能
    int i, sum = 0;
    for(i = 0; i < 31; i++){
      if(arr[i] >= 'a' && arr[i] <= 'z'){
          sum++;
      }    
    }
    printf("%d\n",sum);
}
void digit_count(char arr[31]) {
    // 请在下面实现统计并输出数字个数的功能
    int i, sum = 0;
    for(i = 0; i < 31; i++){
        if(arr[i] >= '0' && arr[i] <= '9') {
            sum++;
        }
    }
    printf("%d\n",sum);
}
void space_count(char arr[31]) {
    // 请在下面实现统计并输出空格个数的功能
    int i, sum = 0;
    for(i = 0; i < 31; i++) {
        if(arr[i] == ' ') {
            sum++;
        }
    }
    printf("%d\n",sum);
}

int main() {
    char string[31];
    int i;
    for(i = 0; i < 30; i++){
        scanf("%c",&string[i]);
    }
    upper_case_count(string);
    lower_case_count(string);
    digit_count(string);
    space_count(string);
    return 0;
    
}
 
