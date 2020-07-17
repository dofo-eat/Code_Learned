/*************************************************************************
	> File Name: OJ515.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月17日 星期五 17时30分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b, l, A, B;
    cin >> a >> b >> l;
    double raw, radio = 9999999;
    raw = (double) a / b;
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= l; j++) {
            double t = (double)i / j;
            if(t >= raw && t - raw < radio - raw) {
                radio = t;
                A = i;
                B = j;
            }
        }
    }
    cout << A << " " <<B << endl;
    return 0;
}
