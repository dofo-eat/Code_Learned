/*************************************************************************
	> File Name: 1.thread_pool.h
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月14日 星期五 22时25分46秒
 ************************************************************************/

#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <thread>
#include <queue>
#include <condition_variable>
using namespace std;

namespace haizei {
class Task {
public:
    template<typename Func_T, typename ...ARGS>
    Task(Func_T f, ARGS ...args) {
        //为了保证变参函数能够按传输的样是进行传递， 需要加上forward
        func = bind(f, std::forward<ARGS>(args)...);   
    }
    void run() {
        func();
    }
private:
    std::function<void()> func;
};


class thread_pool {
public:
    //初始化线程池让他的大小为5同时也要将is_started初始化为false, 条件锁绑定互斥锁， 他俩 搭配使用
    thread_pool(int thread_size = 5)
    :thread_size(thread_size),
    is_started(false),
    m_mutex(),
    m_cond(){}
    //开始线程池
    void start();
    void stop();
    template<typename Func_T, typename ...ARGS>
    void add_one_task(Func_T f, ARGS...args) {
        __add_one_task(new Task(f, std::forward<ARGS>(args)...));
    }
    ~thread_pool() {
        stop();
    }
private:
    //无限循环进等待的入口函数
    //为什么要设置成员方法， 因为有可能访问线程池的私有变量
    void thread_loop();
    Task *get_one_task();
    void __add_one_task(Task *);//添加任务地址

    int thread_size;//限制个数
    std::queue<Task *> Tasks;//存储任务
    std::vector<std::thread *>  Threads;//制定一个线程数组
    bool is_started;//它最起码要是一个成员属性, 判断当前是不是在运行状态

    std::mutex m_mutex;
    std::condition_variable m_cond;//解决队列中没有任务的时候thread_pool进行判断它时不是空转的解决
};
//初始化线程池对像
void thread_pool::start() {
    //添加锁时为了进行线程修改的同步
    std::unique_lock<std::mutex> lock(m_mutex);
    is_started = true;
    for(int i = 0; i < thread_size; i++) {
        //添加一个线程对象
        Threads.push_back(new std::thread(&thread_pool::thread_loop, this));
    }

}
//等待线程执行结束
void thread_pool::stop() {
    std::unique_lock<std::mutex> lock(m_mutex);
    is_started = false;
    m_cond.notify_all();
    for(int i = 0; i < Threads.size(); i++) {
        Threads[i]->join();
        delete Threads[i];
    }
    //销毁之后进行清空
    Threads.clear();
    return ;
}
//让thread_loop进行无限循环
void thread_pool::thread_loop () {
    //is_started != 0的时候意味着还没有进行调用stop， 所以让线程进行无限循环等待对象输入和线程池的任务获取
    while(is_started) {
        //获取任务地址
        Task *t = get_one_task();
        if(t != nullptr) {
            std::cout << "thread_loop tid :: " << std::this_thread::get_id() << std::endl; 
            t->run();
        }
    }
    return ;
    //cout << "hello world" << endl;
}

//获取任务
Task* thread_pool::get_one_task() {
   //先获取锁
    std::unique_lock<std::mutex> lock(m_mutex);
    //同时满足才结束阻塞的状态
    while (Tasks.empty() && is_started) {
        m_cond.wait(lock);
    }
    Task *t = nullptr;
    if(!Tasks.empty() && is_started) {
        t = Tasks.front();
        Tasks.pop();
    }
    return t;
}

//添加任务
void thread_pool::__add_one_task(Task *t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    Tasks.push(t);
    //通知所有等待的任务已经进行添加了
    m_cond.notify_one();
    return ;
}

}

#endif
