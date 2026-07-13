class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        //BFS - 
        if(root == NULL) return {};
        vector<int> ans;
        queue<TreeNode *> q;
        int levelLastValue = 0;
        q.push(root);
        while(q.size() > 0){
            int size = q.size();
            for(int i = 1 ; i<=size ; i++){
                TreeNode * node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                levelLastValue = node->val;
            }
            ans.push_back(levelLastValue);
        }
        return ans;
    }
};
