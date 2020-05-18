/*************************************************************************
	> File Name: 374.猜数字太小.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月17日 星期日 15时15分30秒
 ************************************************************************/

class Solution {
public:
    int bs(int l, int r) {
        int mid, ret;
        while (l <= r) {
            mid = ((l ^ r) >> 1) + (l & r);
            if ((ret = guess(mid)) == 0) return mid;
            if (ret == -1) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    int guessNumber(int n) {
        return bs(1, n);
    }
};
