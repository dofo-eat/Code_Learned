/*************************************************************************
	> File Name: OJ80.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月11日 星期三 20时39分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m, sx, sy;
char mmap[505][505];
int dir[4][2] = {1,0,0,1,-1,0,0,-1};
int func(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(mmap[tx][ty] == '.') {
            mmap[tx][ty] = 0;
            if(func(tx, ty)) {
                return 1;
            }
        }
    }
    return 0;
}

int main () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if(mmap[i][j]== 's') {
                sx = i; 
                sy = j;
            }
        }
    }
    if(func(sx, sy)) {
        cout << 
    }
    return 0;
}
