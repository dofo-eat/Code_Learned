/*************************************************************************
	> File Name: OJ398.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月01日 星期三 18时48分14秒
 ************************************************************************/

#include<iostream>
#include <queue>
using namespace std;

int n, m;
int mmap[405][405];
int x, y;

struct node {
    int x1, y1,step;
};

int dir[8][2] = {
    1,2,
    1, -2,
    2, 1,
    2, -1,
    1, -2,
    -1, -2,
    -2, 1, 
    -2, -1
};


int main () {
    cin >> n >> m >> x >> y;
    queue<node>que;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
                   
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
    }
    return 0;
}
