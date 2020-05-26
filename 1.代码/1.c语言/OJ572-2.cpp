/*************************************************************************
	> File Name: OJ572-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月25日 星期一 18时42分57秒
 ************************************************************************/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

long long n, num1[400005], num2[400005], ans[400005];

int main() {
    priority_queue<int> que;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num1[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &num2[i]);
        que.push(num1[0] + num2[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = num1[i] + num2[j];
            if (sum < que.top()) {
                que.pop();
                que.push(sum);
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans[i] = que.top();
        que.pop();
    }
    for (int i = n - 1; i >= 0; i--) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
 


