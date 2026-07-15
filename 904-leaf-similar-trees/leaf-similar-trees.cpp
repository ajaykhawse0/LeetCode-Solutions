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
    void solve(TreeNode* root,vector<int>&arr){
        if(!root)return;
        if(!root->left && !root->right){
            arr.push_back(root->val);
            return;
        }
        solve(root->left,arr);
        solve(root->right,arr);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>seq1;
        solve(root1,seq1);
        vector<int>seq2;
        solve(root2,seq2);
        
        return seq1==seq2;
    }
};