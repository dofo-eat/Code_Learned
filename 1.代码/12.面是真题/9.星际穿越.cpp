/*************************************************************************
	> File Name: 9.星际穿越.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月26日 星期三 16时35分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[10][10][10], ans, mark[10][10][10], sx, sy, sz;

int dir[6][3] = {
    1, 0, 0, -1, 0, 0,
    0, 1, 0, 0, -1, 0,
    0, 0, 1, 0, 0, -1,
};

int funx(int x, int y, int z) {
    int t = 0;
    for(int i = 0; i < 6; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        int zz = z + dir[i][2];
        if(xx << 0 || yy < 0 || zz < 0 || xx == n || yy == n || zz == n) continue;
        if(num[x][y][z] > num[xx][yy][zz] && mark[xx][yy][zz] == 0) {
            mark[xx][yy][zz] = 1;
            t = max(t, funx(xx, yy, zz));
            mark[xx][yy][zz] = 0;
        }
    }
    return t + num[x][y][z];
}

int main() {
    cin >> n;
    for(int i =0; i < n * n * n; i++) {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        num[x][y][z] = t;
        if(num[sx][sy][sz] < t) {
            sx = x, sy = y, sz = z;
        }
    }
    ans = funx(sx, sy, sz);
    cout << ans << endl;
    return 0;
}
