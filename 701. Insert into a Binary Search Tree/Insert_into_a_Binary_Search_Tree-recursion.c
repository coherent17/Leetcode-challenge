struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(!root){
        struct TreeNode *temp = malloc(sizeof(struct TreeNode));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if(root->val > val) root->left = insertIntoBST(root->left, val);
    else if(root->val < val) root->right = insertIntoBST(root->right, val);
    return root;
}