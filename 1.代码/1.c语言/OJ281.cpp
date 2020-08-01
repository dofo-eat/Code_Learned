/*************************************************************************
	> File Name: OJ281.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月20日 星期三 21时12分35秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000

struct Node {
    int flag;
    int next[26];
} tree[MAX_N + 5];
int root = 1, cnt = 1;
char str[MAX_N + 5];

int getNode() { return ++cnt; }
void insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNode();
        p = tree[p].next[ind];
    }
    tree[p].flag += 1;
    return ;
}

int query(const char *str) {
    int p = root, cnt = 0;
    for (int i = 0; str[i] && p; i++) {
        p = tree[p].next[str[i] - 'a'];
        cnt += tree[p].flag;
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    while (n--) cin >> str, insert(str);
    while (m--) cin >> str, cout << query(str) << endl;
    return 0;
}
