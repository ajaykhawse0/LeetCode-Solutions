/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        unordered_map<long long,long long>sum;
        unordered_map<long long,long long>cnt;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long maxl=0;
        while(!q.empty()){
            auto[node,level]=q.front();
            maxl = max(maxl,level);
            q.pop();
            sum[level] += node->val;
            cnt[level]++;

            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }


        }
        vector<double>ans(maxl+1);
        for(auto&[lev,count]:cnt){
            ans[lev] = (double)sum[lev]/count;
        }

return ans;
    }
};