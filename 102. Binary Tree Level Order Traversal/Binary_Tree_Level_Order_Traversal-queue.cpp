class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            int qsize = q.size();
            vector<int> curr;
            while(qsize--){
                TreeNode *temp = q.front();
                q.pop();
                curr.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ret.push_back(curr);
        }
        return ret;
    }
};