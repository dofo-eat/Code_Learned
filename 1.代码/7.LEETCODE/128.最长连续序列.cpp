/*************************************************************************
	> File Name: 128.最长连续序列.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月21日 星期四 19时52分54秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    struct UnionSet {
        int *fa, *cnt;
        UnionSet(int n) {
            fa = new int[n + 1];
            cnt = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                fa[i] = i;
                cnt[i] = 1;
            }
        }
        bool isroot(int x) {
            return x == fa[x];
        }
        int get(int x) {
            return (fa[x] = (x == fa[x] ? x : get(fa[x])));
        }
        void merge(int a, int b) { 
            int aa = get(a), bb = get(b);
            if (aa == bb) return ;
            fa[aa] = bb;
            cnt[bb] += cnt[aa];
            return ;
        }
        ~UnionSet() {
            delete[] fa;
            delete[] cnt;
        }
    };

    int longestConsecutive(vector<int>& nums) {
        UnionSet u(nums.size());
        unordered_map<int, int> h;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(nums[i]) != h.end()) continue;
            if (h.find(nums[i] - 1) != h.end()) {
                u.merge(i, h[nums[i] - 1]);
            }
            if (h.find(nums[i] + 1) != h.end()) {
                u.merge(i, h[nums[i] + 1]);
            }
            h[nums[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!u.isroot(i)) continue;
            ans = max(ans, u.cnt[i]);
        }
        return ans;
    }
};
