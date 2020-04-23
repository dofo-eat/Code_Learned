/*************************************************************************
	> File Name: OJ392.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 18时51分29秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

int n, m, num[100005],mmax; 

int check(int mid) {
    int cnt = 1, now = 0;
    for(int i = 0; i < n; i++) {
        if(num[i] - num[now] >= mid) {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func(){
    int l = 1, r = mmax;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        int cnt = check(mid);
        if(cnt >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
//11110000
int main () {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    mmax = num[n-1] - num[0];
    cout << func () << endl;
    return 0;
}
