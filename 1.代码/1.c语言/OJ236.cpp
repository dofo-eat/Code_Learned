/*************************************************************************
	> File Name: OJ236.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月11日 星期三 19时28分28秒
 ************************************************************************/#include<iostream>
using namespace std;

int n, m, num[15], cnt;

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
        if(cnt == m) {
            p();
        }//输出
        func(i + 1);
        cnt--;
    }
}

int main (){
    cin >> n >> m;
    func(1);
    return 0;
}


