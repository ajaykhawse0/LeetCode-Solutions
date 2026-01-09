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

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        maxDepth = findDepth(root) - 1; // fix depth alignment
        return lca(root, 0);
    }
};
