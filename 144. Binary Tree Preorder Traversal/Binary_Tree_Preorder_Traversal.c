void preorder(struct TreeNode *root, int *res, int *index){
    if(!root) return;
    res[(*index)++] = root->val;
    preorder(root->left, res, index);
    preorder(root->right, res, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    
    int *res = malloc(sizeof(int) * 100);
    int index = 0;
    preorder(root, res, &index);
    *returnSize = index;
    return res;
}