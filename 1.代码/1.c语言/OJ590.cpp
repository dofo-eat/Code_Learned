/*************************************************************************
	> File Name: OJ590.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月29日 星期三 20时27分44秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int n, m, num[1005][1005], dowm[1005][1005], up[1005][1005];
int mmax[1005], mmax_ind[1005], mmax2[1005];

int main () {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i ; j++) {
            cin >> num[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            dowm[i][j] = max(dowm[ i - 1 ][j - 1], dowm[i - 1][j]) + num[i][j];
        }
    }
    for(int i = n; i > 0; i--) {
        for(int j = 1; j <= i; j++) {
            up[i][j] = max(up[i + 1][j+ 1], up[i+ 1][j]) + num[i][j];
        }
    } 
    for(int i = 2; i <= n; i++) {
        int ind1 = 0, ind1_max = 0,ind2_max = 0;
        for(int j = 1; j <= i; j++) {
            int t = dowm[i][j] + up[i][j] - num[i][j];
            if(t > ind1_max) {
                ind1_max = t;
                ind1 = j;
            }
        }
        for(int j = 1; j <= i; j++) {
            int t = dowm[i][j] + up[i][j] - num[i][j];
            if(t > ind2_max && j != ind1) {
                ind2_max = t;
            }
        }
        mmax[i] = ind1_max;
        mmax_ind[i] = ind1;
        mmax2[i] = ind2_max;
    }
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1 && b == 1) {
            cout << -1 << endl;
            continue;
        }
        if(mmax_ind[a] == b) {
            cout << mmax2[a] << endl;
        } else {
            cout << mmax[a] << endl;
        }
    }
    return 0;
}
