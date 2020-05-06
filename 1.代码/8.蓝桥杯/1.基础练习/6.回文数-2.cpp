/*************************************************************************
	> File Name: 6.回文数-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月06日 星期三 11时10分37秒
 ************************************************************************/

#include <cstdio>
int is_palindrome(int n){
    int a[5],num=0;
    do{
        a[num++]=n%10;
        n/=10;
    }while(n);
    for(int i=0;i<num/2;i++) if(a[i]!=a[num-1-i]) return 0;
    return 1;
}
 
int main(){
    for(int i=1000;i<=9999;i++)
        if(is_palindrome(i)) printf("%d\n",i);
    return 0;
}
