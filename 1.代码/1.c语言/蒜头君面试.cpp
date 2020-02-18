/*************************************************************************
	> File Name: 蒜头君面试.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月06日 星期四 19时38分00秒
 ************************************************************************/

#include<iostream>
#include<map>
using namespace std;

int main () {
    int n;
    int a, sum = 0, temp = 0;
    cin >> n;
    map<int, int> num;
    for(int i = 0; i < n; i++) {
        cin >> a;
        if(num.count(a)) num[a]++;
        else num.insert(pair<int, int>(a, 1));
        if(num[a] > sum) {
            temp = a;
            sum = num[a];
        }
        if(num[a] == sum && a > temp) {
            temp = a;
        }
    }
    cout << temp << " " << sum << endl;
    return 0;
}
