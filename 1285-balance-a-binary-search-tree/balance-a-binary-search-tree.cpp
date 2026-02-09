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
void inorderTraversal(TreeNode* root ,vector<int>&inorder){
    if(!root)return;
    inorderTraversal(root->left,inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right,inorder);
}
TreeNode * constructBST(int start,int end ,vector<int>&inorder){
    if(start>end)return nullptr;

    int mid = start + (end-start)/2;
    TreeNode*root = new TreeNode(inorder[mid]);
    root->left = constructBST(start,mid-1,inorder);
    root->right = constructBST(mid+1,end,inorder);

    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root,inorder);
        int start = 0;
        int end = inorder.size()-1;
        return constructBST(start,end,inorder);

    }
};