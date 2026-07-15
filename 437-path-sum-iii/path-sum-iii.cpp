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
public: int cnt = 0;
    
    void dfs(TreeNode*node,long long targetSum,long long currSum){
        if(!node)return;

        currSum += node->val;

        if(currSum == targetSum)cnt++;

        dfs(node->left,targetSum,currSum); 
        dfs(node->right,targetSum,currSum); 
    }
    int pathSum(TreeNode* root, int targetSum) {
        //try for all the the nodes just use a stack
        if(!root)return 0;
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            auto node = st.top();
            st.pop();

            dfs(node,targetSum,0);

            if(node->left){
                st.push(node->left);
            }

            if(node->right){
                st.push(node->right);
            }


        }


 return cnt;   }
};