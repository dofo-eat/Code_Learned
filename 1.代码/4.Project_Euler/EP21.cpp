/*************************************************************************
	> File Name: EP21.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月29日 星期日 18时32分00秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define N 10000

int f[N + 5] = {0};

/*void init() {
    for(int i = 2; i <= N; j++) {
        for(int j = 1; j < i; j++) {
            if(i % j == 0) {
                f[i] += j;
            }
        }
    }
    return ;
}
*/
void init() {
    for(int i = 2; i <= N; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j) continue;
            f[i] += j;
            f[i] += i / j;
        }
        f[i] -= i;
    }
    return ;
}
int main () {
    init();
    long long sum = 0;
    for(int i = 2; i < N; i++) {
        if(f[i] != i && f[i]< N &&  i  == f[f[i]]) sum += i;
    }
    cout << sum << endl;
    return 0;
}
