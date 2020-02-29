/*************************************************************************
	> File Name: 102.二叉树的层次遍历.cpp
	> Author: dofo-eat
	> Mail:2354787023@qq.com 
	> Created Time: 2020年02月29日 星期六 15时11分55秒
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int getDepth(struct TreeNode *root) {
    if(root == NULL) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

void getCnt(struct TreeNode *root, int k, int *cnt) {
    if(root == NULL) return;
    cnt[k] += 1;
    getCnt(root->left, k + 1, cnt);
    getCnt(root->right, k + 1, cnt);
    //判断每一个纬度开多大
}

void getRuselt(struct TreeNode *root, int k, int *cnt, int **ret) {
    if(root == NULL) return;
    ret[k][cnt[k]++] = root->val;
    getRuselt(root->left, k + 1, cnt, ret);
    getRuselt(root->right, k + 1, cnt, ret);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
//int *returnSize传出参数 改变后在将这数据返回
    int depth = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) *depth);
    int *cnt = (int *)calloc(sizeof(int), depth);//每一个数组的首地址
    //int *cnt = (int *) calloc(depth, sizeof(int));前面写开多大, 后面写地址的大小 清零声明出来的空间都是0
    getCnt(root, 0, cnt);
    //cnt[0] = 1, cnt[1] = 2, cnt[2] = 2;为了判断每层存储的元素个数
    for(int i = 0; i < depth; i++) {
        ret[i] = (int *) malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getRuselt(root, 0, cnt, ret);//从第0层开始放入, 向RET放入数值;
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;
}
 
