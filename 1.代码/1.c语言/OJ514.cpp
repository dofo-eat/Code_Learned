/*************************************************************************
	> File Name: OJ514.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月23日 星期六 13时23分03秒
 ************************************************************************/
#include<iostream> 
using namespace std;

int n, ans;
int num[15] = {6, 2, 5, 5, 4, 5, 6,3, 7, 6,
};

int check(int x, int y) {
    int z = x + y;
    int xn = 0, yn = 0, zn = 0;
    if(x == 0) {
        xn = num[0];
    } else {
        while(x) {
            xn += num[x % 10];
            x /= 10;
        }
    }
    if(y == 0) {
        yn = num[0];
    } else {
        while(y) {
            yn += num[y % 10];
            y /= 10;
        }
    }
    if(z == 0) {
        zn = num[0];
    }
    else {
        while(z) {
            zn += num[z % 10];
            z /= 10;
        }
    }
    if(xn + yn + zn + 4 == n) return 1;
    return 0;
}

int main() {
    cin >> n;
    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if(check(i, j)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
//514
