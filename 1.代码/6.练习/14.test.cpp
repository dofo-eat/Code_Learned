/*************************************************************************
	> File Name: 14.test.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月25日 星期一 17时33分45秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

struct node {
    int now, step;
};

int num[105][105], check[105];

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }
    queue<node> que;
    que.push({x, 0});
    check[x] = 1;
    while(!que.empty()) {
        node temp = que.front();
        que.pop();
        if(temp.now == y) {
            cout << temp.step - 1 << endl;
            return 0;
        }
        for(int i = 1; i <= n; i++) {
            if(check[i] == 0 && num[temp.now][i] == 1) {
                check[i] = 1;
                que.push({i, temp.step + 1});
            }
        }
    }
    return 0;
}
