/*************************************************************************
	> File Name: 257.二叉树所有的路径.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月29日 星期六 20时05分08秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int getPathCnt(struct TreeNode *root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return getPathCnt(root->left) + getPathCnt(root->right);
}

int getResult(struct TreeNode *root, int len, int k, char **ret, char *buffer) {
    if(root == NULL) return 0;
    len += sprintf(buffer + len, "%d", root->val);//下一个buffer从len开始
    buffer[len] = 0;//为了循环使用
    if(root->left == NULL && root->right == NULL) {
        ret[k] = strdup(buffer);//走到ret[k]位置时将buffer拷贝过去
        return 1;
    }
    len += sprintf(buffer + len, "->");
    int cnt = getResult(root->left, len, k, ret, buffer);//len是字符偏移量
    cnt += getResult(root->right, len, k + cnt, ret, buffer);//节点放在那一个位置上
    return cnt;//总共增加节点值的个数
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getPathCnt(root);//判断有多少路径
    char **ret = (char **)malloc (sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buffer = (char *)malloc(sizeof(char) * max_len);//申请一个每个链表长度
    getResult(root, 0, 0, ret, buffer);
    *returnSize = pathCnt;//代表总的路径的个数
    return ret;
}
