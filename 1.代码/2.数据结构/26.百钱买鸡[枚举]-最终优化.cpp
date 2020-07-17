/*************************************************************************
	> File Name: 26.百钱买鸡[枚举]-最终优化.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月17日 星期五 16时46分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int x, y, z;
    for(int i = 0; i <= 3; i++) {
        x = 4 * i;
        y = 25 + 7 * i;
        z = 75 + 3 * i;
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}
