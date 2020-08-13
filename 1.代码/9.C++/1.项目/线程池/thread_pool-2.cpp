/*************************************************************************
	> File Name: thread_pool-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 16时52分49秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <thread>
using namespace std;

class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
        return ;
    }

private:
    function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : is_running(false), max_threads_num(n) {}
    void start() {
        if (is_running) return ;
        is_running = true;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
        return ;
    }
    void worker() {
        cout << "worker : hello, I'm worker" << endl;
    }
    void stop() {
        if (is_running == false) return ;
        is_running = false;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return ;
    }

private:
    bool is_running;
    int max_threads_num;
    vector<thread *> threads;
};

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}

int main() {
    Task t1(thread_func1, 3, 4);
    Task t2(thread_func1, 5, 6);
    Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();
    int n = 0;
    
    Task t4(thread_func2, ref(n));
    t4(), t4(), t4();
    cout << n << endl;

    ThreadPool tp(6);
    tp.start();
    tp.stop();
    return 0;
}

