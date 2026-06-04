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
// public:priority_queue<int,vector<int>,greater<int>>pq;
vector<int>arr;
    void traverse(TreeNode*root){
        if(!root)return;
        // pq.push(root->val);
        traverse(root->left);
        arr.push_back(root->val);
        traverse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        traverse(root);
        // for(int i=0;i<k-1;i++){
        //     pq.pop();
        // }
        return arr[k-1];
    }
};