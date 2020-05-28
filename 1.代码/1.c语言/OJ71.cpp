/*************************************************************************
	> File Name: OJ71.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月28日 星期四 14时48分59秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5];
    void init(int n) {
        for(int i = 1; i <= n; i++) fa[i] = i;
    }
    int get(int x) {
        return (fa[x] = (x == fa[x] ? x : get(fa[x])));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for(int i = 0; i < m;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            u.merge(b, c);
        } else {
            if(u.get(b) == u.get(c)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
