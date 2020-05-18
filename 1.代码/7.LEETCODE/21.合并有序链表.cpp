/*************************************************************************
	> File Name: 21.合并有序链表.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月17日 星期日 14时19分06秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode ret, *p = &ret;
        ret.next = NULL;
        while (l1 || l2) {
            if (l2 == NULL || (l1 && l1->val < l2->val)) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
            p->next = NULL;
        }
        return ret.next;
    }
};
