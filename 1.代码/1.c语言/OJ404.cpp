/*************************************************************************
	> File Name: OJ404.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月18日 星期三 19时29分04秒
 ************************************************************************/
#include<iostream>
using namespace std;

int n, m, start_x, start_y;
char mmap[3005][3005];
char check[3005][3005];
int sum = 1;

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
        if(x < 1 || y < 1 || x > n || y > m) continue;
        if(mmap[x0][y0] != mmap[x][y] && check[x][y] == 0) {
            check[x][y] = 1;
            sum++;
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
    cin >>start_x >> start_y;
    check[start_x][start_y] = 1;
    func(start_x,start_y);
    cout << sum << endl;
    return 0;
} 
