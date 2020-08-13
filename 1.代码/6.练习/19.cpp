/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 13时04分37秒
 ************************************************************************/
#include <iostream>
using namespace std;
void upper_case_count(char arr[31]) {
    // 请在下面实现统计并输出大写字母个数的功能
    int sum = 0;
    for(int i = 0; i < 31; i++) {
        if(arr[i] >= 'A' && arr[i] <= 'Z') {
            sum++;
        }
    }
    cout << sum << endl;
}
void lower_case_count(char arr[31]) {
    // 请在下面实现统计并输出小写字母个数的功能
    int sum = 0;
    for(int i = 0; i < 31; i++) {
        if(arr[i] >= 'a' && arr[i] <= 'z') {
            sum++;
        }
    }
    cout << sum << endl;
}
void digit_count(char arr[31]) {
    // 请在下面实现统计并输出数字个数的功能
    int sum = 0;
    for(int i = 0; i < 31; i++) {
        if(arr[i] >= '0' && arr[i] <= '9') {
            sum++;
        }
    }
    cout << sum << endl;
}
void space_count(char arr[31]) {
    // 请在下面实现统计并输出空格个数的功能
    int sum = 0;
    for(int i = 0; i < 31; i++) {
        if(arr[i] == ' ') {
            sum++;
        }
    }
    cout << sum << endl;
}

int main() {
    char string[31];
    int i;
    for(int i = 0; i < 31; i++) {
        cin >> string[i];
    }
    
    upper_case_count(string);
    lower_case_count(string);
    digit_count(string);
    space_count(string);
    return 0;
    
}

