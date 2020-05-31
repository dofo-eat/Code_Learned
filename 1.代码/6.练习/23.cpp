/*************************************************************************
	> File Name: 23.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 15时05分21秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 20000
#define MAX_M 100000

struct UnionSet{
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
        return ;
    }
    int get(int x) {
        if(x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 2;
        return fa[x] = root;
    }
    int merge(int a, int b, int temp) {
        int x = get(a);
        int y = get(b);
        if(x == y) {
            return (val[a] - val[b] - temp) % 2 == 0;
        }
        fa[x] = y;
        val[x] = (temp + val[b] - val[a] + 2) % 2;
        return 1;
    }
};

UnionSet u;

struct Data {
    int a, b, c;
} arr[MAX_N + 5];

bool cmp(const Data &a, const Data &b) {
    return a.c > b.c;
}

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for(int i = 0; i < m; i++) {
        cin >> arr[i].a >> arr[i].b >>  arr[i].c;
    }
    sort(arr, arr + m, cmp);
    arr[m].a = arr[m].b = 1;
    arr[m].c = 0;
    for(int i = 0; i < m; i++) {
        if(u.merge(arr[i].a, arr[i].b, 1)) continue;
        cout << arr[i].c << endl;
        return 0;
    }
    return 0;
}
