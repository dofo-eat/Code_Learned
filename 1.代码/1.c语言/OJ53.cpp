/*************************************************************************
	> File Name: OJ53.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月28日 星期二 17时24分40秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int sum[1000005];
int t = 0;

int factor(int n) {
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            sum[t] += i;
        }
    }
    t++;
}

/*bool cmp(int a, int b) {
    return a > b;
}
*/
int main() {
    int n;
    cin >> n;
    int a[1000005];
    for(int i = 0; i < n; i++) {
        factor(i);
    }
    sort(sum, sum + n);
    cout << sum[n - 1];
    return 0;
}
