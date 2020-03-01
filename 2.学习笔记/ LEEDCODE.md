#  LEEDCODE

##  一.顺序表和链表

###  1.LEEDCODE 19. 删除链表的倒数第N个节点

* 给定一个链表，删除链表的倒数第 *n *个节点，并且返回链表的头结点。

* 示例

* ```c
  给定一个链表: 1->2->3->4->5, 和 n = 2.
  当删除了倒数第二个节点后，链表变为 1->2->3->5.
  ```

~~~ c

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode ret, *p, *q;
    ret.next = head;//增加虚拟头结点
    p = q = &ret;//从虚拟头结点处开始遍历
    while (n--) { q = q->next; }//快慢指针先走n步
    q = q->next;
    while (q) {
        p = p->next;
        q = q->next;
    }//q到达尾节点时, p正好到达要删除的前一个节点
    q = p->next;
    p->next = q->next;
    free(q);
    return ret.next;//为什么不返回头结点是因为头结点可能被删掉了
}
~~~

###  2.LEEDCODE 24. 两两交换链表中的节点

* 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

* 示例

* ```
  给定 1->2->3->4, 你应该返回 2->1->4->3.
  ```

~~~ c
//本题利用头插法
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *p, *q, ret;
    ret.next = head;
    p = &ret;//将p取地址ret
    q = head;
    while (q != NULL && q->next != NULL) {//如果q和q->next为空时不进行查询
        p->next = q->next;
        q->next = p->next->next;
        p->next->next = q;
        p = q;
        q = q->next; 
      //这的大概意思时a, b两个顺序指针, a指向b的下一个, b指向a
    }
    return ret.next;
}
~~~

###   3.LEEDCODE 83. 删除排序链表中的重复元素

* 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

* 示例

* ```
  输入: 1->1->2
  输出: 1->2
  ```

~~~ c

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *current = head, *q;
    while (current  != NULL && current->next != NULL) {
        if (current->val -  current->next->val) {//if判断返回值为不为0
            current = current->next;
        } else {
            q = current->next;
            current->next = q->next;
            free(q);
          //找到并释放节点
        }
    }
    return head;
}
~~~

###   4.LEEDCODE 141. 环形链表

* 给定一个链表，判断链表中是否有环。

  为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

* 示例

* **输入：**head = [3,2,0,-4], pos = 1
  **输出：**true
  **解释：**链表中有一个环，其尾部连接到第二个节点。

~~~ c
//快慢指针
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow , *fast;
        slow = fast = head;
        if(head == NULL || head->next == NULL) return false;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast ==slow) return true;
        }
        return false;
}
~~~

###  5.LEEDCODE  160. 相交链表

* 如下面的两个链表:

* [![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)

  在节点 c1 开始相交。

  输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
  输出：Reference of the node with value = 8
  输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

  ~~~ c

  struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
      struct ListNode *p, *q;
      p = headA, q = headB;
      while(p != q) {
          p = p?p->next:headB;
          q = q?q->next:headA;
      }
    //让两条链表加上对方的长度使他们相等, 返回值
      return p;
  }
  ~~~

* ​

###  6.LEEDCODE 202. 快乐数

* 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

* 示例

* ```从
  输入: 19
  输出: true
  解释: 
  12 + 92 = 82
  82 + 22 = 68
  62 + 82 = 100
  12 + 02 + 02 = 1
  ```

~~~ c
int get_next(int n) {
    int temp = 0;
    while(n) {
        temp += (n % 10) * (n % 10);
        n /= 10;
      //个位数的平方
    }
    return temp;
}

 bool isHappy(int n) {
     int p = n, q = n;
     while(q != 1) {
         p = get_next(p);
         q = get_next(get_next(q));
         if(p == q) break;
     }
     return q == 1;//判断有环无环
 }
~~~

###  7.LEEDCODE 203. 移除链表元素

* 删除链表中等于给定值 **val **的所有节点。

* 示例

* ```
  输入: 1->2->6->3->4->5->6, val = 6
  输出: 1->2->3->4->5
  ```

~~~ c

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p, *q;
    ret.next = head;
    p = &ret;
    while(p && p->next) {
      //判断是否为所删除的值
        if(p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        }else{
            p = p->next;
        }
    }
    return ret.next;
}
~~~

###  8.LEEDCODE  206. 反转链表

* 反转链表

* 示例

* ```
  输入: 1->2->3->4->5->NULL
  输出: 5->4->3->2->1->NULL
  ```

~~~ c

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode ret, *p, *q;
    ret.next = NULL;//虚拟头结点的下一个节点为空
    p = head;
    while(p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
//头插法
~~~

###   9.LEEDCODE 234. 回文链表

* 请判断一个链表是否为回文链表。

* 示例

* ```c
  输入: 1->2->2->1
  输出: true
  ```

  ~~~ c
  int get_length(struct ListNode *head) {
      int n = 0;
      while(head)  n+= 1, head = head->next;
      return n;
    //求出传入链表的长度
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
    //反转链表
      while(q) {
          if(p->val - q->val) return false;//不是
          p = p->next;
          q =q->next;
      }
      return true;
  }
  ~~~

### 10.LEEDCODE 237. 删除链表中的节点

- 请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。

- 示例

- 输入: head = [4,5,1,9], node = 5
  输出: [4,1,9]
  解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

  ![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/01/19/237_example.png)

~~~ c
void deleteNode(struct ListNode* node) {
    struct ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
    free(p);
    return ;
}
~~~



