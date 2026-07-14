class Solution {
public:
    void dfs(TreeNode *root , vector<int> &v){
        if(root == NULL) return ;

        dfs(root->left , v);
        v.push_back(root->val);
        dfs(root->right , v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        dfs(root,v);
        return v[k-1];
    }
};
