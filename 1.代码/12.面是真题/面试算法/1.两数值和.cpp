/*************************************************************************
	> File Name: 1.两数值和.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年09月01日 星期二 21时08分28秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> get_two_sum(vector<int>& numbers, int target) {
   unordered_map<int,int> m;
        for(int i=0;i<numbers.size();++i)
        {
            m[numbers[i]]=i;
        }
               vector<int> result;
        for(int i=0;i<numbers.size();++i)
        {
            if(m.find(target-numbers[i])!=m.end())
            {
       result.push_back(i);
              result.push_back(m[target-numbers[i]]);
              break;
            }
        }
        return result; 
}
int main() {
    int n;
    vector<int> v;
    cin >> n;
    int tp;
    for (int i = 0; i < n; ++i) {
        cin >> tp;
        v.push_back(tp);
    }
    int x;
    cin >> x;
    vector<int> ans = get_two_sum(v, x);
    if (ans.size() == 2) {
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

