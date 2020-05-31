/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 12时17分33秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 200000

int arr[MAX_N + 5];
int c[MAX_N + 5];

inline int lowbit(int x) {
    return x & (-x);
}

void add (int ind, int val, int n) {
    while(ind <= n) {
        c[ind] += val;
        ind += lowbit(ind);
    }
}

int query(int x) {
    if(x) {
        return c[x] + query(x - lowbit(x));
    }
    return 0;
}

int main(){
    int n;
    long long ans = 0;//^
    long long sum = 0;//v
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) {
        long long lnum = query(arr[i]);
        ans += (arr[i] - lnum - 1) * lnum;
        sum += (i - 1 - lnum) * (n - arr[i] - i + 1 + lnum);
        add(arr[i], 1, n);
    }
    cout << sum <<  " " << ans << endl;
    return 0;
}
