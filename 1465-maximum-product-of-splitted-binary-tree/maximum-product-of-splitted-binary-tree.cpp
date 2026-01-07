class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long totalSum = 0;
    long long maxProd = 0;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long currSum = root->val + leftSum + rightSum;

       
        long long product = currSum * (totalSum - currSum);
        maxProd = max(maxProd, product);

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfsTotal(root);   
        dfs(root);                   
        return maxProd % MOD;        
    }

    long long dfsTotal(TreeNode* root) {
        if (!root) return 0;
        return root->val + dfsTotal(root->left) + dfsTotal(root->right);
    }
};
