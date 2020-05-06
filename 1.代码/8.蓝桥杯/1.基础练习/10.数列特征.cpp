/*************************************************************************
	> File Name: 10.数列特征.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 15时34分44秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    int min = 0, max = 0, sum = 0;
    cin >> n;
    int arr[10005];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }   
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    cout << max << endl;
    cout << min << endl;
    cout << sum << endl;
    return 0;
}
