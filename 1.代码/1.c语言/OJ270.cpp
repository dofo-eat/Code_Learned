/*************************************************************************
	> File Name: OJ270.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月24日 星期日 21时09分47秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 300000

long long arr[MAX_N + 5];
int q[MAX_N + 5], head = 0, tail = 0;

int main () {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    q[tail++] = 0;
    long long ans = arr[1];
    for(int i = 1; i <= n;i ++) {
        ans = max(ans, arr[i] - arr[q[head]]);
        while(tail - head && arr[i] <= arr[q[tail - 1]]) tail--;
        q[tail++] = i;
        if(i - q[head] >= m) head++;
    }
    cout << ans << endl;
    return 0;
}
