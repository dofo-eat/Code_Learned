/*************************************************************************
	> File Name: OJ457.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月18日 星期三 19时11分37秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
int main() {
    int n;
    cin >> n;
    int a[1001]= {0};
    int b[1001] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll temp = 0, flag = 0;
    for(int i = 0; i < n - 1; i++) {
        temp = fabs(a[i] -a[i + 1]);
        if(temp < 1 || temp > n - 1) {
            flag = 1;
            break;
        }
        else {
            if (b[temp] == 1) {
                flag = 1;
                break;
            }
            b[temp] = 1;
        } 
    }
    if (flag == 1) {
        cout << "Not jolly" << endl;
    } else {
        cout << "Jolly" << endl;
    }
    return 0;
}
