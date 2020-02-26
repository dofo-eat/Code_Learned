/*************************************************************************
	> File Name: 24.两两交换相邻节点.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月25日 星期二 15时19分44秒
 ************************************************************************/
/**
*  * Definition for singly-linked list.
*   * struct ListNode {
*    *     int val;
*     *     struct ListNode *next;
*      * };
*       */


struct ListNode* swapPairs(struct ListNode* head) {
        struct ListNode *p, *q, ret;
        ret.next = head;
        p = &ret;
        q = head;
    while (q != NULL && q->next != NULL) {
                p->next = q->next;
                q->next = p->next->next;
                p->next->next = q;
                p = q;
                q = q->next; 
            
    }
        return ret.next;

}   }
