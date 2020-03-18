/*************************************************************************
	> File Name: OJ397.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月18日 星期三 18时34分04秒
 ************************************************************************/
#include<iostream>
using namespace std;

int n, m, mmap[105][105];
int sum = 0;

int dir[4][2] = {
     0,1,
     1,0,
     0,-1,
     -1,0 
};

void func(int x0, int y0) {
    for(int i = 0; i < 4; i++) {
        int x = x0 + dir[i][0];
        int y = y0 + dir[i][1];
        if(mmap[x][y] != 0) {
            mmap[x][y] = 0;
            func(x, y);
        }
    } 
}

int main () {
    cin >> n>> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mmap[i][j] != 0) {
                sum++;
                mmap[i][j] = 0;
                func(i, j);
            }
        }
    }
    cout << sum << endl;
    return 0;
}
