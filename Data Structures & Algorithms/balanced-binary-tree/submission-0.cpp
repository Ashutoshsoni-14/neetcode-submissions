class Solution {
public:
    int depth(TreeNode * root){
        if(root == NULL) return 0;

        int ld = depth(root->left);
        int rd = depth(root->right);

        return max(ld , rd) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int l = depth(root->left);
        int r = depth(root->right);

        if(abs(l-r) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
