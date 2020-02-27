/*************************************************************************
	> File Name: 234.回文链表.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月27日 星期四 15时44分09秒
 ************************************************************************/

int get_length(struct ListNode *head) {
    int n = 0;
    while(head)  n+= 1, head = head->next;
    return n;
}

struct ListNode *reverse(struct ListNode *head, int n) {
    struct ListNode ret, *p = head, *q;
    while(n--) p = p->next;
    ret.next = NULL;
    while(p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret. next;
}

bool isPalindrome(struct ListNode* head){
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(head, (len + 1) / 2);
    while(q) {
        if(p->val - q->val) return false;
        p = p->next;
        q =q->next;
    }
    return true;
}
 
