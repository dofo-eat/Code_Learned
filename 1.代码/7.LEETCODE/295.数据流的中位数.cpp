/*************************************************************************
	> File Name: 295.数据流的中位数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月16日 星期六 18时31分56秒
 ************************************************************************/
class MedianFinder {
public:
    typedef pair<int, int> PII;
    set<PII> s1, s2;
    int t;
    /** initialize your data structure here. */
    MedianFinder() {
        t = 0;
    }
    
    void addNum(int num) {
        if (s1.size() == 0 || num <= -(s1.begin()->first)) {
            s1.insert(PII(-num, t++));
        } else {
            s2.insert(PII(num, t++));
        }
        if (s1.size() + 2 == s2.size()) {
            PII temp = *s2.begin();
            temp.first = -(temp.first);
            s1.insert(temp);
            s2.erase(s2.begin());
        }
        if (s2.size() + 2 == s1.size()) {
            PII temp = *s1.begin();
            temp.first = -(temp.first);
            s2.insert(temp);
            s1.erase(s1.begin());
        }
        return ;
    }
    
    double findMedian() {
        double val1 = s1.size() == 0 ? 0 : -(s1.begin()->first);
        double val2 = s2.size() == 0 ? 0 : s2.begin()->first;
        if (s1.size() == s2.size()) return (val1 + val2) / 2.0;
        return s1.size() > s2.size() ? val1 : val2;
    }
};
