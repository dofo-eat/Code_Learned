/*************************************************************************
	> File Name: OJ572.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月25日 星期一 18时03分50秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
#define MAX_N 400000

long long a[MAX_N + 5],b[MAX_N + 5], ans[MAX_N + 5];

int main() {
    priority_queue<int> que;
    long long int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        que.push(a[1] + b[i]);
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int sum = a[i] + b[j];
            if(sum < que.top()) {
                que.pop();
                que.push(sum);
            } else {
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        ans[i] = que.top();
        que.pop();
    }
    for(int i = n; i>= 1; i--) {
        cout << ans[i] << endl;
    }
    return 0;
}
