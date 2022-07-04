struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(!root) return root;
    else if(root->val == val) return root;
    else if(root->val > val) return searchBST(root->left, val);
    else return searchBST(root->right, val);
    return root;
}