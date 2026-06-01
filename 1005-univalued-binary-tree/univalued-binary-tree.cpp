class Solution {
public:
    int val;

    bool f(TreeNode* root) {
        if (!root) return true;

        return root->val == val &&
               f(root->left) &&
               f(root->right);
    }

    bool isUnivalTree(TreeNode* root) {
        val = root->val;
        return f(root);
    }
};