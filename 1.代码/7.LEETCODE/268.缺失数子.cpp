/*************************************************************************
	> File Name: 268.缺失数子.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年07月23日 星期四 13时47分49秒
 ************************************************************************/

#include<iostream>
using namespace std;

int missingNumber(int* nums, int numsSize){
    int ans = numsSize, i;
    for(i = 0; i < numsSize; i++){
        ans ^= i ^ nums[i];    
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << missingNumber(nums, n);
}
