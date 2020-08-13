/*************************************************************************
	> File Name: 23.thread.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 11时49分22秒
 ************************************************************************/

#include<iostream>
#include<thread>
using namespace std;

void func() {
    cout << " hello world" << endl;
}

void func2(int x) {
    cout << x << "hello world" << endl;
}

void func3(int &x) {
    x += 1;
    cout << x << "hello world" << endl;
}

int main() {
    thread t1(func);
    //等待子线程结束
    t1.join();
    thread t2(func2, 2);
    t2.join();
    int n;
    thread t3(func3, ref(n));
    t3.join();
    cout << n << endl;
    return 0;
}
