/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月23日 星期四 17时35分07秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

long long n, a[400005], b[400005], ans[400005];

int main() {
    priority_queue<int> que;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int sum = a[i] + b[j];
            if(sum < que.top()) {
                que.pop();
                que.push(sum);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        ans[i] = que.top();
        que.pop();
    }
    for(int i = n - 1; i >= 0; i--) {
        cout << ans[i] << endl;   
    }
    return 0;
}
