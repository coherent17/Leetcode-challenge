struct TreeNode *createNode(int val){
    struct TreeNode *newnode = malloc(sizeof(struct TreeNode));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if(!root){
        root = createNode(val);
        return root;
    }
    
    struct TreeNode *temp = root;
    struct TreeNode *prev = root;
    while(temp){
        prev = temp;
        if(temp->val > val){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    
    if(val > prev->val){
        prev->right = createNode(val);
    }
    else{
        prev->left = createNode(val);
    }

    return root;
}