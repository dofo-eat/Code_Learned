/*************************************************************************
	> File Name: 9.查找整数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 15时19分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    int arr[1005];
    int a;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    cin >> a;
    for(int i = 1; i <= n; i++) {
        if(a == arr[i]) {
            cout << i << endl;
            break;
        } else {
            cout << "-1" << endl;
        }
    }  
    return 0;
}
