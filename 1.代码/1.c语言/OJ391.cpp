/*************************************************************************
	> File Name: OJ391.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月22日 星期三 18时07分35秒
 ************************************************************************/

#include<iostream>
using namespace std;

long long int n, m, num[100000];
long long int mmax, x;//x最小值

long long check(long long mid) {
    int now = 0, cnt = 0;//当前端树以及数 的数量
    //根据和来求段数如果大于要求移动做指针
    for(int i = 0; i < n; i++) {
        if(now + num[i] == mid) {
            cnt++;
            now = 0;
        } else if(now + num[i] > mid) {
            cnt++;
            now = num[i];
        } else {
            now += num[i];
        }
    }
    if(now > 0) cnt++;
    return cnt;
}

long long func() {
    long long l= x, r = mmax;
    while(l != r) {
        long long mid = (l + r) / 2;
        long long cnt = check(mid);//能分成几段
        if(cnt > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main () {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        mmax +=  num[i];//极大值
        x = max(x, num[i]);
    }
    cout << func() << endl;
    return 0;
}
