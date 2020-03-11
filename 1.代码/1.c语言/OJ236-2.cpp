/*************************************************************************
	> File Name: OJ236-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月11日 星期三 19时43分16秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, m,num[15], cnt;

void func(int s, int left) {
    if(left == 0) {
        for(int i = 0; i < cnt; i++) {
            if(i) cout << " ";
            cout << num[i];
        }
        cout << endl;
        return ;
    }
    for(int i = s; i <= n - left + 1; i++) {
        num[cnt] = i;
        cnt++;
        func(i + 1, left - 1);
        cnt--;
    }
}

int main () {
    cin >> n >> m;
    func(1, 1);
    return 0;
}
