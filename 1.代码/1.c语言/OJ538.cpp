/*************************************************************************
	> File Name: OJ538.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月25日 星期三 18时13分12秒
 ************************************************************************/

#include<iostream>
using namespace std;

int n, num[25][25];
int check[25], flag;

void func(int x) {
    if(flag == 1) {
        cout << '-';
    }
    flag = 1;
    cout << x;//输出第一个数
    for(int i = 1; i <= n; i++) {
        if(num[x][i] == 1 && check[i] == 0) {//num[x][i] 矩阵的第几层来进行判断
            check[i] = 1;
            func(i);//递归
        }
    }
}

int main () {
    cin >> n;
    for(int i = 1;i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> num[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(check[i] == 0) {
            check[i] = 1;//标记走过
            func(i);
        }    
    }
    return 0;
}
