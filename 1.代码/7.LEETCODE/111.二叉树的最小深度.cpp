/*************************************************************************
	> File Name: 111.二叉树的最小深度.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月29日 星期六 18时21分44秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(root == NULL) return 0;
   if(root->left == NULL && root ->right == NULL) return 1;
    if (root->left == NULL || root->right == NULL)
        return minDepth(root->right ? root->right : root->left) + 1;
    int l = minDepth(root->left), r = minDepth(root -> right);
    return (l < r ? l : r) + 1;
}


