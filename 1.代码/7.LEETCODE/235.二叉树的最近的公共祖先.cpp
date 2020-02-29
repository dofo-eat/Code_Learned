/*************************************************************************
	> File Name: 235.二叉树的最近的公共祖先.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月29日 星期六 19时03分11秒
 ************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *__lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if(root->val == p->val) return p;
    if(root->val == q->val) return q;
    if(root->val > p->val && root->val < q->val) return root;//p是最小的
    if(p->val > root->val) return return __lowestCommonAncestor(root->right, p, q);
    return __lowestCommonAncestor(root->left, p, q);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL) return NULL;
    if(p->val == q->val) return p;
    if(p->val > q->val) {
        struct TreeNode *temp = p;
        p = q; 
        q = temp;
    }
    return __lowestCommonAncestor(root, q, p);
}
