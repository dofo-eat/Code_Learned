/*************************************************************************
	> File Name: 21.min最小栈.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月12日 星期二 09时56分34秒
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

typedef pair<int, int> PII;

struct NewStack :stack<PII> {
public :
    //NewStack;
    NewStack() {this->t = 0;}
    void push(int val) {
        PII data(val, t++);
        this->stack<PII>::push(data);
        if(m_stack.empty() || val < m_stack.top().first) {
            m_stack.push(data);
        }
        return ;
    }
    void pop() {
        if(this->empty()) return ;
        if(this->top().second == m_stack.top().second) {
            m_stack.pop();
        }
        this->stack<PII>::pop();
        return ;
    }
    int min() {
        if(this->empty()) return 0;
        return m_stack.top().first;
    }
private :
    int t;
    stack<PII> m_stack;
};

int main() {
    NewStack s;
    int op, val;
    while(cin >> op >> val) {
        switch(op) {
            case 0:s.push(val);break;
            case 1:s.pop();break;
            case 2:cout << s.min() << endl; break;
        }
    }
    return 0;
}
