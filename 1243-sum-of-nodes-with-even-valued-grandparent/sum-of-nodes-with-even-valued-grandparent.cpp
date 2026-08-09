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
    int solve(TreeNode*node,int parent,int grandParent){
        if(!node)return 0;
        int ans = 0;
        if(!(grandParent&1)){
          ans = node->val;
        }
        if(node->left){
            ans = ans+solve(node->left,node->val,parent);
        }
        if(node->right){
            ans = ans+solve(node->right,node->val,parent);
        }

        return ans;
    }
    int sumEvenGrandparent(TreeNode* root) {
        //try recursion

        return solve(root,-1,-1);//parent,grandaparent
    }
};