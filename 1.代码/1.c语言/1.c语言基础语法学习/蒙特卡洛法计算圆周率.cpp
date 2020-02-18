/*************************************************************************
	> File Name: 蒙特卡洛法计算圆周率.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年01月07日 星期二 18时56分10秒
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define MAX_OP 1000000

int main () {
    int n = 0, m = 0;
    for(int i = 0; i < MAX_OP; i++) {
        double x = rand() * 1.0 /RAND_MAX * (rand() % 2 ? 1 : -1);
        double y = rand() * 1.0/ RAND_MAX * (rand() % 2 ? 1 : -1);
        if(x * x + y * y <= 1.0) m += 1;
        n += 1;
    }
    printf("%lf\n", m * 1.0 / n * 4.0);
    return 0;
}
