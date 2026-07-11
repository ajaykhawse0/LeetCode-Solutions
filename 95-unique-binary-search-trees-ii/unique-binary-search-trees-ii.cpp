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
    unordered_map<string,vector<TreeNode*>>dp;
    vector<TreeNode*>solve(int start,int end){
        if(start>end){
            return {nullptr};
        }

        string key = to_string(start) + "#$" + to_string(end);
        if(dp.count(key)){
            return dp[key];
        }

        vector<TreeNode*>ans;

        for(int root=start ; root<=end ; root++){
            vector<TreeNode*>LeftTree = solve(start,root-1);
            vector<TreeNode*>RightTree = solve(root+1,end);

            for(auto&L:LeftTree){
                for(auto&R:RightTree){
                    TreeNode*node = new TreeNode(root);
                    node->left = L;
                    node->right = R;
                    ans.push_back(node);
                }
            }
        }
        return dp[key] = ans;
    }
    vector<TreeNode*> generateTrees(int n) {
              return solve(1,n);
    }
};