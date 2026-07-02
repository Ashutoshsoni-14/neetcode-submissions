class Solution {
public:
    bool helper(TreeNode* &root , long minval , long maxval){
        if(root == NULL){
            return true;
        }
        if(root->val <= minval || root->val >= maxval) return false;

        return helper(root->left , minval , root->val) && helper(root->right , root->val , maxval);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root , INT_MIN , INT_MAX);
    }
};
