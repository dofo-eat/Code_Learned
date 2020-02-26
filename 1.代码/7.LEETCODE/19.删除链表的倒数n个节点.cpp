/*************************************************************************
	> File Name: 19.删除链表的倒数n个节点.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月25日 星期二 14时28分26秒
 ************************************************************************/

struct listNode *removeNthFromEnd(struct listNode *head, int n) {
    struct listNode ret, *p, *q;
    ret.next = head;
    p = q = &ret;//虚拟头结点
    while(n--) q = q->next;
    q = q->next;//判断当前n+1个节点
    while(q) {
        p = p->next;
        q = q->next;
    }
    return ret.next;
}
