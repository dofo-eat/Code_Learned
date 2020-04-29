/*************************************************************************
	> File Name: OJ559.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月29日 星期三 18时23分39秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct node {
    double val, cost, num;
};

bool cmp(node a, node b) {
    return a.num > b.num;
}

double m, n,ans;
node s[1005];

int main () {
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i].val >> s[i].cost;
        s[i].num = s[i].val / s[i].cost;
    }
    sort(s, s + (int)n, cmp);
    for(int i = 0; i < n; i++) {
        if(m <= s[i].cost){
            ans += s[i].num * m;
            break;
        }
        ans += s[i].val;
        m -= s[i].cost;
    }
    printf("%.3f\n", ans);
    return 0;
}
