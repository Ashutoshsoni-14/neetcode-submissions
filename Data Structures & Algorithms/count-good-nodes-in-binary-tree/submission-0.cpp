class Solution {
public:
    int helper(TreeNode *node , int maxVal){
        if(node == NULL){
            return 0;
        }
        int count = 0;
        if(node->val >= maxVal) count = 1;
        maxVal = max(maxVal , node->val);
        count += helper(node->left , maxVal);
        count += helper(node->right , maxVal);
        return count;
    }
    int goodNodes(TreeNode* root) {
        return helper(root,root->val);
    }
};
