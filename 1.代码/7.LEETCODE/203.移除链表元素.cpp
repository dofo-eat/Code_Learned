/*************************************************************************
	> File Name: 203.移除链表元素.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月27日 星期四 15时00分52秒
 ************************************************************************/

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = &ret;
    while(p && p->next) {
        if(p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        }else{
            p = p->next;
        }
    }
    return ret.next;
}:
