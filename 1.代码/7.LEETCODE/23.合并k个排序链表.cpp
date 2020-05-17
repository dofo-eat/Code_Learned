/*************************************************************************
	> File Name: 23.合并k个排序链表.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年05月16日 星期六 18时46分38秒
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
    typedef pair<int, ListNode *> PIL;
    typedef pair<int, PIL> PIP;
    set<PIP> s;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));
            lists[i] = lists[i]->next;
        }
        ListNode ret, *p = &ret;
        ret.next = NULL;
        while (s.size()) {
            PIP temp = *s.begin();
            s.erase(s.begin());
            p->next = temp.second.second;
            p = p->next;
            int i = temp.second.first;
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));
            lists[i] = lists[i]->next;
        }
        return ret.next;
    }
};
