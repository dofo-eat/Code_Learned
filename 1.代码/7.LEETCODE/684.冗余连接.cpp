/*************************************************************************
	> File Name: 684.冗余连接.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月23日 星期六 14时09分03秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Solution {
public:
    struct UnionSet {
        int *fa;
        UnionSet(int n) {
            fa = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                fa[i] = i;
            }
            return ;
        }
        int get(int x) {
            return (fa[x] = (x - fa[x] ? get(fa[x]) : x));
        }
        int merge(int a, int b) {
            if (get(a) == get(b)) return 0;
            fa[get(a)] = get(b);
            return 1;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionSet u(edges.size());
        vector<int> ret;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            if (u.merge(a, b)) continue;
            ret.push_back(a);
            ret.push_back(b);
            break;
        }
        return ret;
    }
};
