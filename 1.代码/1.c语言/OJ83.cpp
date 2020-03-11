/*************************************************************************
	> File Name: OJ83.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月11日 星期三 20时12分22秒
 ************************************************************************/

#include<iostream>
using namespace std;

int func(int s, int left_num, int left_cnt) {//传入的参数， 选择的数， 剩下的个数
    if(left_cnt == 0) {
        if(left_num == 0) return 1;
        return 0;
    }
    int ans = 0;
    for(int i = s; i <= left_num; i++) {
        ans += func(i, left_num - i, left_cnt - 1);
    }
    return ans;
}

int main () {
    int n, m;
    cin >> n >> m;
    cout << func(1, n, m) << endl;
    return 0;
}
