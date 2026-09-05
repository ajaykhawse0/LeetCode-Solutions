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
    using P = pair<bool,int>;
    priority_queue<int>pq;
    P dfs(TreeNode* root){
            if(!root)return{true,0};

            P left = dfs(root->left);
            P right = dfs(root->right);

            if(left.first && right.first && left.second==right.second){
                int sz = left.second+right.second+1;//(1)for the curr node
                pq.push(sz);
                return {true,sz};
            }

            return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(!root)return -1;
        dfs(root);
        
        k-=1;//0 based indexing
        while(!pq.empty() && k--){
            pq.pop();
        }
        return pq.empty()?-1:pq.top();
    }
};