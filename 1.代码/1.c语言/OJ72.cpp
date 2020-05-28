/*************************************************************************
	> File Name: OJ72.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月28日 星期四 15时52分38秒
 ************************************************************************/
#include <iostream>
using namespace std;
#define MAX_N 10000

struct UnionSet {
    int fa[MAX_N + 5], val[MAX_N + 5];
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int get(int x) {
        if (x == fa[x]) return x;
        int root = get(fa[x]);
        val[x] += val[fa[x]];
        val[x] %= 3;
        return fa[x] = root;
    }
    /*void merge(int a, int b, int t) {
        int aa = get(a), bb = get(b);
        if (aa == bb) return ;
        fa[aa] = bb;
        val[aa] = (t + val[b] - val[a] + 3) % 3;
        return ;
    } */
    void merge(int a, int b, int t) {
        if(get(a) == get(b)) return ;
        val[get(a)] = (t + val[b] - val[a] + 3) % 3;
        fa[get(a)] = get(b);
        return;
    }
};

UnionSet u;

int main() {
    int n, m;
    cin >> n >> m;
    u.init(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            u.merge(b, c, 2);
        } else {
            if (u.get(b) != u.get(c)) {
                cout << "Unknown" << endl;
            } else {
                if((u.val[b] - u.val[c] + 3) % 3 == 0) {
                    cout << "Tie" << endl;
                }
                if((u.val[b] - u.val[c] + 3) % 3 == 1) {
                    cout << "Loss" << endl;
                }
                if((u.val[b] - u.val[c] + 3) % 3 == 2) {
                    cout << "Win" << endl;
                }
            }
        }
    }
    return 0;
}

