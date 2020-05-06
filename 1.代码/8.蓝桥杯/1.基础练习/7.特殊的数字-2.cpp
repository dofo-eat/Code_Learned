/*************************************************************************
	> File Name: 7.特殊的数字-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 11时20分06秒
 ************************************************************************/
#include <iostream>
using namespace std;
 
int isSpecial(int x) {
    int sum = 0;
    while(x) {
        int t = x % 10;
        sum += t * t * t;
        x /= 10;
    }
 
    return sum;
}
 
int main() {
    for(int i = 100; i <= 999; i ++) {
        if(isSpecial(i) == i)
        cout << i << endl;
    }
    return 0;
}
