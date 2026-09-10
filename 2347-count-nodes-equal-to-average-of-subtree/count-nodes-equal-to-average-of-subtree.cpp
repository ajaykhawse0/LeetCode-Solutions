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
void solve(TreeNode*node,int&sum,int&cnt){
    if(!node)return;
    cnt++;
    sum += node->val;

    solve(node->left,sum,cnt);
    solve(node->right,sum,cnt);
}
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int cnt = 0;
            int sum = 0;

            solve(node,sum,cnt);
            if(cnt > 0 && sum/cnt == node->val)ans++;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);

        }


    return ans;
    }
};