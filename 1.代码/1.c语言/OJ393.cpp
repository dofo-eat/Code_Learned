/*************************************************************************
	> File Name: OJ393.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 19时23分45秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iomanip>
#include<cstdio>
using namespace std;

int n , k;
double num[10005] , mmax;

int check(double len) {
    int cnt = 0;
    for (int i = 0; i < n;i++) {
        cnt += num[i] / len;
    }
    return cnt;
}
double func() {
    double l = 0 , r = mmax;
    while (fabs(l - r) > 0.00005) {
        double mid = (l + r) / 2;
        int temp = check(mid);
        if(temp >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

int main(){
    cin >>n >> k;
    for (int i = 0; i < n;i++) {
        cin >> num[i];
        mmax = max(mmax , num[i]);
    }
    double ans = func();
    printf("%d.%d%d\n", (int)ans, (int)(ans * 10) % 10, (int)(ans * 100) % 10);
    return 0;
}
