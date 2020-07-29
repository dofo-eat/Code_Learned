/*************************************************************************
	> File Name: OJ65.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月29日 星期三 12时25分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int sum = 0;
    for(int i = 1; i <= 10000; i++) {
        if(i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
