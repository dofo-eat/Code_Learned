/*************************************************************************
	> File Name: EP45-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年12月24日 星期二 20时29分21秒
 ************************************************************************/
 #include <algorithm>
 #include <cmath>
 #include <cstdio>
 #include <iomanip>
 #include <iostream>
 #include <string>
 using namespace std;

 typedef long long LL;

 LL Triangle(LL n) { return n * (n + 1) >> 1;  }
 LL Pentagonal(LL n) { return n * (3 * n - 1) >> 1;  }
 LL Hexoagonal(LL n) { return n * (2 * n - 1);  }

 LL binary_search(LL (*num)(LL), LL n, LL x) {
         int head = 1, tail = n - 1, mid;
     while (head <= tail) {
                 mid = (head + tail) >> 1;
                 if (num(mid) == x) return mid;
                 if (num(mid) < x)
                     head = mid + 1;
                 else
                     tail = mid - 1;
             
     }
             return -1;

 }

         int main() {
                 int n = 144;
             while (binary_search(Pentagonal, 2 * n, Hexoagonal(n)) == -1) {
                         n++;
                     
             }
                 cout << Hexoagonal(n) << endl;
                 return 0;

         }
