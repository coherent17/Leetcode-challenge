int max(int a, int b){
    return a > b ? a : b;
}

int maxDepth(struct TreeNode* root){
    if(!root) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth) + 1;
}