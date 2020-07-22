/*************************************************************************
	> File Name: 5.map.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月21日 星期二 20时10分02秒
 ************************************************************************/

#include<iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<double, string> arr;
    arr[1.2] = "hello";
    arr[4.3] = "world";
    arr[-4.5] = "haizi";
    arr[89.1] = "me";
    double n;
    while(cin >> n) {
        /*if(arr[n] != "") {
            cout << " find:" << arr[n] << endl;
        } else {
            cout << "not found" << n << endl;
        }*/
        //没有会新增节点
        if(arr.find(n) != arr.end()) {
            cout << "find:" << arr[n] << endl;
        } else {
            cout << "not found" << n << endl;
        }
    }
    for(auto iter = arr.begin(); iter != arr.end(); iter++) {

        cout << iter->first << " " << iter->second << endl;
    }
    cout << arr[1.2] << endl;
    cout << arr[4.3] << endl;
    return 0;
}
