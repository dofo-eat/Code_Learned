/*************************************************************************
	> File Name: 5.特殊回文数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年04月23日 星期四 17时18分03秒
 ************************************************************************/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i = 10000;i < 100000; i++) {
        int a = i / 10000;
        int b = (i / 1000) % 10;
        int c = (i / 100) % 10;
        int d = (i / 10) % 10;
        int e = i % 10; 
        
        if(a ==e && b == d){
            if(a + b + c + d + e == n) cout<< i <<endl;
        }
    }
    
    for(int i = 100000;i < 1000000;i++) {
        int a = i / 100000;
        int b = (i / 10000) % 10;
        int c = (i / 1000) % 10;
        int d = (i / 100) % 10;
        int e = (i / 10) % 10;
        int f = i % 10;
        
        if(a == f && b == e && c == d) {
            if(a + b + c + d + e + f == n) cout<< i <<endl;
        }
    }
    
    return 0;
}
