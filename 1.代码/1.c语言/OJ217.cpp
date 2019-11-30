/*************************************************************************
	> File Name: OJ217.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月30日 星期六 16时33分57秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}
int main () {
    int n;
    cin >> n;
    int a[100001];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    int sum = 0;
    int m = n / 2;
    for(int i = 0; i < n; i++) {
        if(a[i] >= a[m]) sum++;
    }
    cout << a[m] << " " << sum << endl;
    return 0;
}
