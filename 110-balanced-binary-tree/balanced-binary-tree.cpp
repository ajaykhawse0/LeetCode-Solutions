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
int calHeight(TreeNode*node){
    if(!node)return 0;

    return 1+max(calHeight(node->left),calHeight(node->right));
}
    bool isBalanced(TreeNode* root) {
        if(!root)return true;

        int lheight = calHeight(root->left);
        int rheight = calHeight(root->right);

        if(abs(rheight-lheight)>1)return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right)return false;

        return true;
    }
};