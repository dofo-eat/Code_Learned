/*************************************************************************
	> File Name: OJ235.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月11日 星期三 18时58分51秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[15], cnt;

void p() {
    for(int i = 0; i < cnt; i++) {
        if(i)  cout << " ";
        cout << num[i];    
    }
    cout << endl;
}

void func(int s) {
    for(int i = s; i <= n; i++) {
        num[cnt] = i;//本层选的数是i
        cnt++;
        p();//输出
        func(i + 1);
        cnt--;
    }
}

int main (){
    cin >> n;
    func(1);
    return 0;
}
