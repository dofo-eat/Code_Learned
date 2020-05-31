/*************************************************************************
	> File Name: 26.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月30日 星期六 16时45分50秒
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 200000

struct Data {
    int s, e, d;
}arr[MAX_N + 5];


int main(){
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int b[MAX_N + 5] = {0};
        for(int i = 1; i <= n; i++) {
            cin >> arr[i].s >> arr[i].e >> arr[i].d;
            for(int j = arr[i].s; j <= arr[i].e; j++) {
                b[j] += 1;
            }
        }
    }
    return 0;
}
