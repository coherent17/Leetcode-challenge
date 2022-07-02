bool check(struct TreeNode *left, struct TreeNode *right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL) return false;
    if(right == NULL) return false;
    if(left->val == right->val) return check(left->left, right->right) && check(left->right, right->left);
    return false;
}

bool isSymmetric(struct TreeNode* root){
    return check(root->left, root->right);
}