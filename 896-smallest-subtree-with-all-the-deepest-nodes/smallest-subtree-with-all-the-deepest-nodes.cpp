/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth;

    int findDepth(TreeNode* root) {
        if (root == NULL) return 0;

        int ldepth = findDepth(root->left);
        int rdepth = findDepth(root->right);

        return 1 + max(ldepth, rdepth);
    }

    TreeNode* lca(TreeNode* root, int depth) {
        if (root == NULL) return NULL;

        if (depth == maxDepth)
            return root;

        TreeNode* left = lca(root->left, depth + 1);
        TreeNode* right = lca(root->right, depth + 1);

        if (left && right) return root;
        if (left) return left;
        return right;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        maxDepth=findDepth(root)-1;
        return lca(root,0);
    }
};