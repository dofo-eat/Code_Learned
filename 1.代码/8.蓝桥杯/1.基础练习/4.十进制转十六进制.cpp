/*************************************************************************
	> File Name: 4.十进制转十六进制.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月23日 星期四 16时09分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main () {
    int n;
    cin >> n;
    if(n == 0) {
        cout << 0;
    }
    int a[100005] = {0};
    int sum = 0;
    while (n > 0) {
        sum = n % 16;
        a[++a[0]] = sum;
        n = n / 16;
    }
    for(int i = a[0]; i > 0; i--) {
        int temp = 0;
        temp = a[i];
        cout << arr[temp];
    }
    cout << endl;
    return 0;
}
