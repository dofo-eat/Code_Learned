/*************************************************************************
	> File Name: 101.对称二叉树.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月29日 星期六 14时51分05秒
 ************************************************************************/

bool is_check(struct TreeNode *p, *q) {
    if(p == NULL && q ==NULL) return true;
    if(p == NULL || q == NULL) return false;//有一个是空树
    if(p->val - q->val) return false;
    return is_check(p->left, q->right) && is_check(p->right, q->left);
    //p的左子树q的右子树进行比较
}

 bool isSymmetric(struct TreeNode *root) {
     if(root == NULL) return true;
     return is_check(root->left, root->right) ;
 }
