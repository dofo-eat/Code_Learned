/*************************************************************************
	> File Name: OJ240.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月11日 星期三 18时14分24秒
 ************************************************************************/

#include<iostream>
using namespace std;

char ans[2200][2200];
int num[10] = {0, 1, 3, 9, 27, 81, 243, 729, 2187};//图形边长

void func(int x, int y, int n) {//n是图形大小
    if(n == 1) {
        ans[x][y] = 'X';
        return ;
    }
    func(x, y, n - 1);//左上角
    func(x, y + num[n] / 3 * 2, n - 1);//右上角
    func(x + num[n] / 3 * 2, y, n - 1);//左下
    func(x + num[n] / 3 * 2, y + num[n] / 3 * 2, n - 1);//右下
    func(x + num[n] / 3, y + num[n] / 3, n - 1);//中间
}

int main () {
    func(1, 1, 7);
    int n;
    while(cin >> n) {
        if(n == -1) break;
        for(int i = 1; i <= num[n]; i++) {
            for(int j = 1; j <= num[n]; j++) {
                if(ans[i][j] == 'X') cout << 'X';
                else cout << ' ';
            }
            cout << endl;
        }
        cout << '-' << endl;
    }
    return 0;
}

