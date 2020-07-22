/*************************************************************************
	> File Name: 6.sort.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月21日 星期二 20时53分34秒
 ************************************************************************/

#include<iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

struct CMP_FUNC {
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int arr[1000], n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    nth_element(arr, arr + 1, arr + n);
    cout << arr[1] << endl;
    //bool 类型
    sort(arr, arr + n, cmp);
    //sort(arr, arr + n, CMP_FUNC);
   //lamber表达式
    sort(arr, arr + n, [](int a, int b) ->bool {
        return a > b;
    });
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
