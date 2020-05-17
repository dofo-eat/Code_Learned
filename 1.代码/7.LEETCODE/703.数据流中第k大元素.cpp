/*************************************************************************
	> File Name: 703.数据流中第k大元素.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月16日 星期六 18时29分02秒
 ************************************************************************/
class KthLargest {
public:
    typedef pair<int, int> PII;
    set<PII> s;
    int k, t;
    KthLargest(int k, vector<int>& nums) {
        this->t = 0;
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
        return ;
    }
    
    int add(int val) {
        if (s.size() < k) {
            s.insert(PII(val, t++));
        } else if (val > s.begin()->first){
            s.erase(s.begin());
            s.insert(PII(val, t++));
        }
        return s.begin()->first;
    }
};

