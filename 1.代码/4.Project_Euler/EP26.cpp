/*************************************************************************
	> File Name: EP26.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月28日 星期六 20时36分06秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 1000

int r_len[N + 5];

int get_len(int d) {
    memset(r_len, 0, sizeof(r_len));
    int r = 1, t = 1;
    r_len[r]= 1;
    while(d) {
        r *= 10;
        r %= d;
        t += 1;
        if(r_len[r]) return t - r_len[r];
        r_len[r] = t;
    }
    return 0;
}

int main () {
    int d = 0, len = -1;
    for(int i = 2; i < N; i++) {
        int tmp = get_len(i);
        if(len < get_len(i)) {
            len = tmp;
            d = i;
        }
    }
    cout << d << endl;
    cout << len << endl;
}
