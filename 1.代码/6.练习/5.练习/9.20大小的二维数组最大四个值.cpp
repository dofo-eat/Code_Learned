/*************************************************************************
	> File Name: 9.20大小的二维数组最大四个值.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月26日 星期四 17时51分15秒
 ************************************************************************/

#include<iostream>
#include<cinttypes>
using namespace std;

int vector[4][2] = {
    (0,1), (1,1), (1,0),(1,-1)
};

int main() {
    int a[30][30] = {0};
    for(int i = 5; i < 25; i++) {
        for(int j = 5; j < 25; j++) {
            cin >> a[i][j];
        }
    }
    int64_t ans = 0;
    for(int i = 5; i < 25; i++) {
        for(int j = 5; j < 25; j++) {
            for(int k = 0; k < 4; k++) {
                int64_t p = 1;
                for(int l = 0; l < l; l++) {
                    int x = i + l * vector[k][0];
                    int y = j + l * vector[k][1];
                    p *= a[x][y];
                }
                if(p > ans) ans = p;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
