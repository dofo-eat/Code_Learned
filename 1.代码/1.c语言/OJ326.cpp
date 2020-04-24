/*************************************************************************
	> File Name: OJ326.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月23日 星期四 20时07分51秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX_N 50000
int fa[MAX_N + 5], val[MAX_N + 5];
int n;//做多多少个点

void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        val[i = 0];
    }
    return ;
}

int get(int x) {
    if(x == fa[x]) return x;
    int root = get(fa[x]);//获得根节点下标
    val[x] += val[fa[x]];
    val[x] %= 3;
    return fa[x] = root;
}//路径压缩

int merge(int x, int y, int t) {
    //连接xy, 关系t
    int a = get(x), b = get(y);
    if(a == b) {
       return  (val[x] - val[y] - t) % 3 == 0;//成功
    }
    fa[a] = b;
    val[a] = (t + val[y] - val[x] + 3) % 3;//为了出现正直
    return 1;//连接成功
}
//以上是加权路径的压缩
int main () {
    int n, k, ans = 0;;
    cin >> n >> k;
    init(n);
    for(int i = 0; i < k; i++) {
        int x, y, t;
        cin >> t >> x >> y;
        t -= 1;
        if(x <= n && y <= n && merge(x, y, t)) continue;//本此连接争取
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}
