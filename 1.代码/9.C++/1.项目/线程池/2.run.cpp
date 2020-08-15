/*************************************************************************
	> File Name: 2.run.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月14日 星期五 22时30分49秒
 ************************************************************************/

#include<iostream>
#include "thread_pool.h"
using namespace std;

//如果我们这里传的是引用， 下面的n的传递就是引用传递ref
void func(int x, int &n) {
    n += 2;
    cout << "func :" << x << " " << n << endl;
}

int main() {
    int n = 123;
    
    haizei::Task t(func, 23, ref(n));
    t.run();
    cout << n << endl;
    haizei::thread_pool tp(2);
    tp.start();
    for(int i = 0; i < 10; i++) {
        tp.add_one_task(func, i, ref(n));
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    cout << "add task done" << endl;
    tp.stop();
    return 0;
}
