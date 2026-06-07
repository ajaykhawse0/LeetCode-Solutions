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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // hash table and set approach

        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>childern;

        for(auto&d:descriptions){
            int parent = d[0];
            int child = d[1];
            bool isLeft = d[2]==1;

            if(!mpp.count(parent)){
                mpp[parent] = new TreeNode(parent);
            }
            if(!mpp.count(child)){
                mpp[child] = new TreeNode(child);
            }

            if(isLeft){
                mpp[parent]->left = mpp[child];
            }
            else{
                mpp[parent]->right=mpp[child];
            }

            childern.insert(child);

        }

      for(auto&[val,node]:mpp){
        if(!childern.count(val)){
            return node;
        }
      }
   return nullptr; }
};