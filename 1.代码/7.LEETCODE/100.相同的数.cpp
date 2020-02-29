/*************************************************************************
	> File Name: 100.相同的数.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月29日 星期六 14时34分27秒
 ************************************************************************/
 bool isSameTree(struct TreeNode *p, struct TreeNode *q) {
     if(p == NULL && q == NULL) return true;
     if(p == NULL || q == NULL) return false;//p为空或者q为空, 那么不符合逻辑, 错误
     if(p->val - p->val) return false;
     return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
 }
