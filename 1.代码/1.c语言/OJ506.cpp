/*************************************************************************
	> File Name: OJ506.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月13日 星期三 18时25分19秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct node {
    int num, time;
};

bool cmp(node a, node b) {
    return a.time < b.time;
};

int n;
node s[35];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i].time;
        s[i].num = i + 1;
    }
    sort(s, s + n, cmp);
    int ans = 0, now = 0;
    for(int i = 0; i < n; i++) {
        if(i) cout << " ";
        cout << s[i].num;
        ans += now;
        now += s[i].time;
    }
    printf("\n%.2f\n", (double) ans / n);
    return 0;
}
