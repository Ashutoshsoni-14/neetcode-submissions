class Solution {
public:
    int ans = 0;
    int diameter(TreeNode * root){
        if(root == NULL) return 0;
        
        int ld = diameter(root->left);
        int rd = diameter(root->right);

        ans = max(ans , ld+rd);

        return max(ld , rd )+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return ans;
    }
};
