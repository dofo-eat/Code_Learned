/*************************************************************************
	> File Name: 随即产生1-100.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年03月23日 星期一 18时25分09秒
 ************************************************************************/
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;



int main()
{
    int a[100], b[100];
    srand((unsigned)time(NULL));  
    for (int i = 0; i < 100; i++)
        a[i] = i + 1;
    int range = 100;
    for (int i = 0; i < 100; i++) {
        int r = rand() % range;//产生0到99的随机数
        b[i] = a[r];
        a[r] = a[range - 1];  //把最后一个值填充到当前值
        range--;
    }
    for (int i = 0; i < 100; i++) {  //输出随机数组b
        cout << b[i] << " ";
        if ((i+1) % 10 == 0)
            cout << endl;
    }
        
    
    return 0;
}
