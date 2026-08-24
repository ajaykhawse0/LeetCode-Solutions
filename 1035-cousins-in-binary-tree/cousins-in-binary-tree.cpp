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
public: int parX,parY,depX,depY;
    void solve(int x,int y,TreeNode*root,int depth,int parent){
        if(!root)return ;

        if(root->val==x){
            parX = parent;
            depX = depth;
        }
        if(root->val==y){
            parY = parent;
            depY = depth;
        }
        solve(x,y,root->left,depth+1,root->val);
        solve(x,y,root->right,depth+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(x==root->val || y==root->val)return false;

        solve(x,y,root,0,0);

        if(parX!=parY && depX==depY)return true;

        return false;
    }
};