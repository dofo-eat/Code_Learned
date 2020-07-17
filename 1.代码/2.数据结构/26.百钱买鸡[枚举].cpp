/*************************************************************************
	> File Name: 26.百钱买鸡[枚举].cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月17日 星期五 16时07分17秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            for(int k = 0; k <= 100; k++) {
                if(i + j + k == 100 && 3 * i + 5 * j + k / 3 == 100 && k % 3 == 0) {
                    cout <<  i << " " << j << " " << k << " " << endl;
                }
            }
        }
    }
    return 0;
}
