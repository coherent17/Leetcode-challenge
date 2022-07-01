void postorder(struct TreeNode *root, int *res, int *index){
    if(!root) return NULL;
    postorder(root->left, res, index);
    postorder(root->right, res, index);
    res[(*index)++] = root->val;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){
    if(!root){
        *returnSize = 0;
        return NULL;
    }
    int *res = malloc(sizeof(int) * 100);
    int index = 0;
    postorder(root, res, &index);
    *returnSize = index;
    return res;
}