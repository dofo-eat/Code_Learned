/*************************************************************************
	> File Name: thread_pool.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月13日 星期四 16时09分02秒
 ************************************************************************/

#include<iostream>
#include<functional>
#include <thread>
using namespace std;

class Task {
public :
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, forward<ARGS>(args)...);
        //this->func = std::bind(func, args...);
    }
    void operator()() {
        this->func();
        return ;
    }
private:
    function<void()> func;
};

void thread_func1(int a, int b) {
    cout << a << " + " << b << " = " << a + b << endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}

class ThreadPool {
public:
    //以某一个成员方法作为入口
    ThreadPool(int n = 5) {
        //判断线程池是否启动
        is_running(false), max_threads_num(n) {}
        for(int i = 0; i < n; i++) {
            if(is_running) return ;
            is_running = true;
            threads.push_back(new thread(&ThreadPool::worker, this));
        }
    }
    void start() {
        is(is_running) return ;
        is_running = true;
        for(int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&ThreadPool)::worker)
        }
    }
    //this指针参数
    //死循环等带线程池的任务
    //取任务
    //执行任务
    void worker() {
       cout << " I am a worker" << endl; 
    }
    void stop() {
       if(is_running == false) return;
        is_running = false;
        for(int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
        }
    }
private:
    vector<thread *> threads;
    bool is_running;
    int max_threads_num;
};

int main() {
    Task t(thread_func1, 3, 4);
    t();
    int n = 0;
    Task t1(thread_func2, ref(n));
    t1(), t1(), t1();
    cout << n;
    
    ThreadPool tp(6);
    tp.start();
    tp.stop();
    return 0;
}
