void inorder(struct TreeNode *root, int *res, int *index){
    if(!root) return;
    inorder(root->left, res, index);
    res[(*index)++] = root->val;
    inorder(root->right, res, index);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    int *res = malloc(sizeof(int) * 100);
    int index = 0;
    inorder(root, res, &index);
    *returnSize = index;
    return res;
}