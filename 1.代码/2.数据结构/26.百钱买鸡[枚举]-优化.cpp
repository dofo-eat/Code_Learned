/*************************************************************************
	> File Name: 26.百钱买鸡[枚举]-优化.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月17日 星期五 16时33分38秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    for(int i = 0; i <= 33; i++) {
        for(int j = 0; j <= 20; j++) {
            int z;
            z = 100 - i - j;
            if(3 * i + 5 * j + z / 3 == 100 && z % 3 == 0) {
                cout << i << " " << j << " " << z << endl;
            }
        }
    }
    return 0;
}
