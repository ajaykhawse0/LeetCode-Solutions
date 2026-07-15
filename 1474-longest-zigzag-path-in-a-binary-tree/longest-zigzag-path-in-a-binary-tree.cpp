/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
/*
class Solution {
public:

  //Brute force
   int zigZag(TreeNode* node, int dir, int cnt) {
       if (!node)
           return cnt ;
       cnt++;
       if (dir == 0) { // last move was left
           return zigZag(node->right, 1, cnt);
       } else { // last move was right
           return zigZag(node->left, 0, cnt);
       }
   }
   int longestZigZag(TreeNode* root) {
       if (!root)
           return 0;
       stack<TreeNode*> st;
       int ans = 0;
       st.push(root);

       while (!st.empty()) {
           auto node = st.top();
           st.pop();

           ans =
               max({ans, zigZag(node->left, 0, 0), zigZag(node->right, 1, 0)});

           if (node->left) {
               st.push(node->left);
           }
           if (node->right) {
               st.push(node->right);
           }
       }
       return ans;
   }
};*/

class Solution {
public:
    int ans = 0;
    // optimized
    void zigZag(TreeNode* node, int left, int right) {
        if (!node)
            return;

        ans = max({ans, left, right});

        zigZag(node->left,  right + 1, 0);//last move was left
        zigZag(node->right, 0, left + 1);//last move was right
    }
    int longestZigZag(TreeNode* root) {
        if (!root)
            return 0;
        zigZag(root, 0, 0);
        return ans;
    }
};