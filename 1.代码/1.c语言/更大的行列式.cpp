/*************************************************************************
	> File Name: 更大的行列式.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 13时19分35秒
 ************************************************************************/
#include <iostream>
using namespace std;
 
int main() {
    int A[3][3], B[2][2];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> B[i][j];
        }
    }
    int a_value = 0, b_value = 0;
    for (int i = 0; i < 3; i++) {
        int x = 0, y = i, ans1 = 1, ans2 = 1;
        for (int j = 0; j < 3; j++) {
            ans1 *= A[x + j][(y + j) % 3];
            ans2 *= A[x + j][(y - j + 3) % 3];
        }
        a_value = a_value + ans1 - ans2;
    }
    b_value = B[0][0] * B[1][1] - B[0][1] * B[1][0];
    cout << (a_value > b_value ? a_value : b_value) << endl;
    return 0;
}

