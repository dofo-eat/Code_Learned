/*************************************************************************
	> File Name: OJ327-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月29日 星期五 11时45分34秒
 ************************************************************************/
#include <iostream>
#include<algorithm>
using namespace std;
#define MAX_N 20000
#define MAX_M 100000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
        return ;
    }
    int get(int x) {
        if (fa[x] == x) return x;
        int ret = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = ret;
    }
    int merge(int a, int b, int c) {
        int aa = get(a), bb = get(b);
        if (aa == bb) {
            return (val[a] - val[b] - c) % 2 == 0;
        }
        fa[aa] = bb;
        val[aa] = (c + val[b] - val[a] + 2) % 2;
        return 1;
    }
} u;

struct Data {
    int a, b, c;
} arr[MAX_M + 5];

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].a >> arr[i].b >> arr[i].c;
    }
    sort(arr, arr + m, cmp);
    u.init(n);
    for (int i = 0; i < m; i++) {
        if (u.merge(arr[i].a, arr[i].b, 1)) continue;
        cout << arr[i].c << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}

