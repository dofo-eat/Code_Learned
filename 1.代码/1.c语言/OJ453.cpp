/*************************************************************************
	> File Name: OJ453.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月06日 星期五 19时47分43秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int b[10005];
int main() {
    int n, m;
    int temp;
    cin >> n >> m;
    int a[10000] = {0};
    for(int i = 0; i < n;i++) {
        cin >> temp;
        if(b[temp] == 0) a[++a[0]] = temp, b[temp] = 1;
    }
    sort(a + 1, a + a[0] + 1);
    cout << a[m] << endl;
    return 0;
}
