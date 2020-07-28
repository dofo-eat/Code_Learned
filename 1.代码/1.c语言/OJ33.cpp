/*************************************************************************
	> File Name: OJ33.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月27日 星期一 17时31分44秒
 ************************************************************************/

#include<iostream>
#include <cstdio>
using namespace std;

int main() {
    double n, m, p;
    cin >> n >> m >> p;
    if(p == 1) {
        printf("%.2f\n", (n + m) * 1.087 / 2.0);
    }else {
        printf("%.2f\n", (n * 0.973 + m) / 2.0);
    }
    return 0;
}
