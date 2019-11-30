/*************************************************************************
	> File Name: OJ217二.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2019年11月30日 星期六 18时12分14秒
 ************************************************************************/


 #include<iostream>
 #include<algorithm>
 using namespace std;

 bool cmp(int a, int b) {
         return a > b;

 }
 int main () {
         int n;
         cin >> n;
         int a[100001];
     for(int i = 0; i < n; i++) {
                 cin >> a[i];
             
     }
         sort(a, a + n, cmp);
         int sum = 0;
     for(int i = 0; i < n; i++) {
        if(n % 2 == 0){
            if(a[i] >= a[n / 2 - 1]) sum++;
        }else{
            if(a[i] >= a[n / 2]) sum++;                 
        }     
    }
    if(n % 2 == 0) cout << a[n / 2 - 1] << " " <<  sum << endl;
    else cout << a[n / 2] << " " << sum << endl;
    return 0;
 }


