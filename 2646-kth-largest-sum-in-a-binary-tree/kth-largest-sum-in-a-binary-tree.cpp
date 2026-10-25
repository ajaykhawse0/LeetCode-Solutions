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
public:using ll = long long;
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<ll>pq;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int sz =  q.size();
            ll sum = 0;
            while(sz--){
                auto node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }

                sum += node->val;
            }
            pq.push(sum);
        }
        k-=1;
        while(k-- && !pq.empty()){
            pq.pop();
        }

        return pq.empty()?-1:pq.top();
    }
};