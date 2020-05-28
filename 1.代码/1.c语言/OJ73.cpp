/*************************************************************************
	> File Name: OJ73.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月28日 星期四 16时05分24秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 1000

char g[MAX_N + 5][MAX_N + 5];
int n, m;

struct UnionSet {
    int fa[MAX_N * MAX_N + 5];
    void init(int n) {
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

inline int ind(int i, int j) {
    return i * m + j + 1;
}

int main() {
    cin >> n >> m;
    u.init(n * m);
    for (int i = 0; i < n ;i++) cin >> g[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            if (j - 1 >= 0 && g[i][j - 1] == 'O') u.merge(ind(i, j), ind(i, j - 1));
            if (i - 1 >= 0 && g[i - 1][j] == 'O') u.merge(ind(i, j), ind(i - 1, j));
            if (i == 0 || i == n - 1) u.merge(ind(i, j), 0);
            if (j == 0 || j == m - 1) u.merge(ind(i, j), 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'X') continue;
            ans += (u.get(ind(i, j)) != u.get(0));
        }
    }
    cout << ans << endl;
    return 0;
}
