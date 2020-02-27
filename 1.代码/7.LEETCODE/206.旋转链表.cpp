/*************************************************************************
	> File Name: 206.旋转链表.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月27日 星期四 15时21分45秒
 ************************************************************************/

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode ret, *p, *q;
    ret.next = NULL;
    p = head;
    while(p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
