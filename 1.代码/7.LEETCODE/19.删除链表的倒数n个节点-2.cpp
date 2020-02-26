/*************************************************************************
	> File Name: 19.删除链表的倒数n个节点-2.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月17日 星期一 17时18分28秒
 ************************************************************************/
 struct ListNode *remove(struct ListNode *head, int n) {
     struct ListNode ret, *p, *q;
     ret.next = head;
     p = q = &ret;
     while(n--) {
         q = q->next;
     }
     q = q->next;
     while(q) {
         p = p->next;
         q = q->next;
     }
     q = p->next;
     p->next = q->next;
     free(q);
     return ret.next;
 }
