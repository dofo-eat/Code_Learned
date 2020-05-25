/*************************************************************************
	> File Name: 24.两个链表的交点.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月24日 星期日 15时25分28秒
 ************************************************************************/

#include<iostream>
using namespace std;

ListNode *findIntersectionListNode(ListNode *head1, ListNode *head2) {
    ListNode *p1 = head1, *p2 = head2;
    while(p1!= p2) {
        if(p1 == NULL) p1 = head2;
        if(p2 == NULL) p2 = head1;
        p1 =p1->next;
        p2 = p2->next;
    }
    return p1;
}
