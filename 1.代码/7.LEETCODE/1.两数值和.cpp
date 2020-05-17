/*************************************************************************
	> File Name: 1.两数值和.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月16日 星期六 19时44分52秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
    public:
        unordered_map<int, int> h;
    vector<int> twoSum(vector<int>& nums, int target) {
                vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(target - nums[i]) == h.end()) {
                                h[nums[i]] = i;
                                continue;
                            
            }
                        ret.push_back(h[target - nums[i]]);
                        ret.push_back(i);
                        break;
                    
        }
                return ret;
            
    }

};
