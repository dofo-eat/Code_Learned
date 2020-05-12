/*************************************************************************
	> File Name: 20.同余法求非顺序输出1-100.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月12日 星期二 08时47分14秒
 ************************************************************************/

#include<iostream>
using namespace std;

int my_rang() {
    static int seed = 1;
    seed = seed * 3 % 101;
    return seed;
}

int main() {
    for(int i = 1; i <= 100; i++) 
    cout << my_rang() << endl;
    return 0;
}

