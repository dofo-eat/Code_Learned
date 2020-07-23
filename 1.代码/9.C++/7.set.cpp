/*************************************************************************
	> File Name: 7.set.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月23日 星期四 18时13分41秒
 ************************************************************************/

#include<iostream>
#include<set>
using namespace std;
//底层结构是红黑树
int main() {
    set<int> s;
    s.insert(234);
    s.insert(252);
    s.insert(563);
    s.insert(213);
    cout << s.size() << endl;
    s.insert(252);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;
    //遍历返回最小值
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << *s.begin() << endl;
    return 0;
}
