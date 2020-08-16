/*************************************************************************
	> File Name: 19.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 22时01分28秒
 ************************************************************************/
#include <iostream>
using namespace std;

int a;

int main() {
    auto int = [&a]() {
        a++;
    }
    inc();
    inc();
    cout << a << endl;
    return 0;
}
