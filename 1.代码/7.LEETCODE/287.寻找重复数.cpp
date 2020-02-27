/*************************************************************************
	> File Name: 287.寻找重复数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月27日 星期四 18时21分31秒
 ************************************************************************/
int findDuplicate(int* nums, int numsSize){
     int p = nums[0], q = nums[0];
     do {
         p = nums[p];
         q = nums[nums[q]];//快慢指针走两部
     }while(p != q) ;
     q = nums[0];
     while(p != q) {
         p = nums[p];
         q = nums[q];
     }//p q 差出了一个环的距离:
     return p;
 } 
