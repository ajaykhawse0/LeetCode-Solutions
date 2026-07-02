/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> memo;
    int robberyHelper(TreeNode* root) {
        if (!root)
            return 0;
        if (memo.count(root))
            return memo[root];
        int ans = 0;

        if (root->left) {
            ans += robberyHelper(root->left->left) +
                   robberyHelper(root->left->right);
        }
        if (root->right) {
            ans += robberyHelper(root->right->left) +
                   robberyHelper(root->right->right);
        }

        return memo[root] =
                   max({ans + root->val, robberyHelper(root->left) +
                                             robberyHelper(root->right)});
    }
    int rob(TreeNode* root) { return robberyHelper(root); }
};