/*************************************************************************
	> File Name: p2865.严格最短路-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月01日 星期三 20时08分44秒
 ************************************************************************/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int to, val, next;
};

edge edg[200005];
int n, m, edg_cnt, head[5005], ans[5005], ans2[5005],mark[5005];

void make_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(ans, 0x3F, sizeof(ans));
    memset(ans2, 0x3F, sizeof(ans2));
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b , c;
        cin >> a >> b >> c;
        if (a == 1 || b == 1) {
            ans2[1] = min(ans2[1], c * 2);
        }
        make_edge(a, b, c);
        make_edge(b, a, c);
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    mark[1] = 1;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        mark[t] = 0;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            if (ans[edg[i].to] > ans[t] + edg[i].val) {
                ans2[edg[i].to] = ans[edg[i].to];
                ans[edg[i].to] = ans[t] + edg[i].val;
                if (mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                }
            }
            if (ans[edg[i].to] < ans[t] + edg[i].val && ans2[edg[i].to] > ans[t] + edg[i].val) {
                ans2[edg[i].to] = ans[t] + edg[i].val;
                if (mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                }  
            }
            if (ans2[edg[i].to] > ans2[t] + edg[i].val) {
                ans2[edg[i].to] = ans2[t] + edg[i].val;
                if (mark[edg[i].to] == 0) {
                    mark[edg[i].to] = 1;
                    que.push(edg[i].to);
                } 
            }
        }
    }
    cout << ans2[n] << endl;
    return 0;
}
