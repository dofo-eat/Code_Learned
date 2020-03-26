/*************************************************************************
	> File Name: OJ542.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月25日 星期三 19时31分33秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int t, n, h, r, qiu[1005][3];//三维的球
int low[1005], low_num;//下表面 计数器
int up[1005], arr[1005][1005], check[1005];

int func(int now) {
    if(up[now] == 1) return 1;//判断是否是终点
    for(int i = 1; i <= n; i++) {
        if(arr[now][i] && check[i] == 0) {
            check[i] = 1;
            if(func(i)) return 1; 
        }
    }
    return 0;
}

int main () {
    cin >> t;
    while(t--) {
        memset(low, 0, sizeof(low));
        memset(up, 0, sizeof(up));
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));//数组清零
        low_num = 0;
        cin >> n>> h >> r;
        for(int i = 1; i <= n;i++) {
            cin >> qiu[i][0] >> qiu[i][1] >> qiu[i][2];
            if(qiu[i][2] <= r) {
                low[low_num] = i;
                low_num++;
            }//起点
            if(qiu[i][2] + r >= h) {//大于下表面就是
                up[i] = 1;
            }//终点
            for(int j = 1; j < i; j++) {
                int t0 = qiu[i][0] - qiu[j][0];
                int t1 = qiu[i][1] - qiu[j][1];
                int t2 = qiu[i][2] - qiu[j][2];
                if(sqrt(t0 * t0 + t1 * t1 + t2 * t2) <= 2 * r) {
                    arr[i][j] = arr[j][i] = 1;//是否可以连通 
                }
            }
        }
        int flag = 0;
        for(int i = 0; i <= low_num; i++) {
            if(check[i] == 0) {
                check[i] = 1;
                if(func(i)) {
                    cout << "Yes" << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0) {
            cout << "No" << endl;
        }
    }
    return 0;
}
