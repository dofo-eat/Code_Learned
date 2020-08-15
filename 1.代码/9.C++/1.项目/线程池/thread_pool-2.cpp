/*************************************************************************
	> File Name: thread_pool-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年08月15日 星期六 16时25分31秒
 ************************************************************************/
#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <map>
#include <condition_variable>

namespace haizei {
class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, std::forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
        return ;
    }
    ~Task() {}

private:
    std::function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : max_threads_num(n),
    m_mutex(),
    m_cond() {}
    void start() {
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new std::thread(&ThreadPool::worker, this));
        }
        return ;
    }
    void worker() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = true;
        while (is_running[id]) {
            Task *t = this->getOneTask();
            (*t)();
            delete t;
        }
        return ;
    }
    void stop() {
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return ;
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args) {
        std::unique_lock<std::mutex> lock(m_mutex);
        //std::cout << std::this_thread::get_id() << " add one task" << std::endl;
        this->task_queue.push(new Task(func, std::forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

private:
    void stop_task() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = false;
        return ;
    }
    Task *getOneTask() {
        std::unique_lock<std::mutex> lock(m_mutex); // 抢碗
        while (task_queue.empty()) {
            //std::cout << std::this_thread::get_id() << " wait one task" << std::endl;
            m_cond.wait(lock);
        }// 等待，直到队列中存在任务
        //std::cout << std::this_thread::get_id() << " take one task" << std::endl;
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    std::vector<std::thread *> threads;
    std::queue<Task *> task_queue;
    std::map<std::thread::id, bool> is_running;
    
    std::mutex m_mutex;
    std::condition_variable m_cond;
};
} // end of namespace haizei

void thread_func1(int a, int b) {
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}

void (*func)();

void task_func(int x) {
    std::cout << "thread task func" << std::endl;
    return ;
}

int cnt = 0;

int is_prime(int x) {
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void count_prime(int l, int r) {
    for (int i = l ; i <= r; i++) {
        if (is_prime(i)) __sync_fetch_and_add(&cnt, 1);
    }
    return ;
}

int main() {
    haizei::Task t1(thread_func1, 3, 4);
    haizei::Task t2(thread_func1, 5, 6);
    haizei::Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();
    int n = 0;
    
    haizei::Task t4(thread_func2, std::ref(n));
    t4(), t4(), t4();
    std::cout << n << std::endl;

    haizei::ThreadPool tp(6);
    tp.start();
    for (int i = 0, j = 1; i < 5; i++, j += 200000) {
        tp.addOneTask(count_prime, j, j + 200000 - 1);
    }
    tp.stop();
    std::cout << cnt << std::endl;
    std::cout << "hello world" << std::endl;
    return 0;
}
