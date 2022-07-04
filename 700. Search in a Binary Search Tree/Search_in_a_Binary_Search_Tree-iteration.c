struct TreeNode* searchBST(struct TreeNode* root, int val){
    while(root!= NULL && root->val != val){
        if(root->val > val) root = root->left;
        else root = root->right;
    }
    return root;
}