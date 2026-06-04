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
public:priority_queue<int,vector<int>,greater<int>>pq;
    void traverse(TreeNode*root){
        if(!root)return;
        pq.push(root->val);
        traverse(root->left);
        traverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        traverse(root);
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};