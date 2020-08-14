/*************************************************************************
	> File Name: OJ398.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月03日 星期五 21时09分01秒
 ************************************************************************/
#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int dir[8][2] = {
    1, 2,
    1, -2,
    2, 1,
    2, -1,
    -1, 2,
    -1, -2,
    -2, 1,
    -2, -1
};
int n, m, sx, sy, mmap[405][405];

int main() {
    cin >> n >> m >> sx >> sy;
    queue<node> que;
    que.push({sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (x <= 0 || y <= 0 || x > n || y > m) continue;
            if (mmap[x][y] == 0) {
                mmap[x][y] = temp.step + 1;
                que.push({x, y, temp.step + 1});
            }
        }
    }
    mmap[sx][sy] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j != 1) cout << " ";
            if (i == sx && j == sy) {
                cout << 0;
            } else if (mmap[i][j] == 0) {
                cout << -1;
            } else {
                cout << mmap[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
 

 

