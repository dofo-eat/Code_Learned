/*************************************************************************
	> File Name: 378.有序矩阵中第k小的元素.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月17日 星期日 15时37分49秒
 ************************************************************************/
class Solution {
public:
    int check(vector<vector<int>>& matrix, int x, int n, int m) {
        int cnt = 0, j = n;
        for (int i = 0; i < m; i++) {
            while (j && matrix[j - 1][i] > x) --j;
            cnt += j;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int l = matrix[0][0], r = matrix[n - 1][m - 1];
        int mid, ret;
        while (l < r) {
            mid = (l + r) >> 1;
            ret = check(matrix, mid, n, m);
            if (ret < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
