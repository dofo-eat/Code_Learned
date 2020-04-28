/*************************************************************************
	> File Name: OJ490.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月28日 星期二 19时10分53秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 32767

int f[MAX_N + 5];

int main () {
    int n;
    cin >> n;
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = (f[i - 1] + 2 - 1) % i + 1;//公式是f[n] = (f[n -1] + k -1) % n + 1
    }
    int x = n;
    while (f[x] -x) x = f[x];//当前的所剩的人数和当前的最后剩余不等
    //知道剩下的人的编号就是到下一轮剩下的人数
    cout << n + x << endl;
    return 0;
}
