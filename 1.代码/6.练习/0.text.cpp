/*************************************************************************
	> File Name: 0.text.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年06月28日 星期日 14时57分45秒
 ************************************************************************/
#include <stdio.h>
int main()
{
    const int N=10;
    const int M=2;
    int* a=new int[N];
    for(int i=0;i<N;++i)
        a[i]=(0==i%2)?(i+2):(i+0);
    int (*b)[N/M]=(int (*)[N/M])a;
    for(int i=0;i<M;++i)
        for(int j=0;j<N/M;++j)
            printf("%d",b[i][j]);
    return 0;
} 
