class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size();
        int cols = mat[0].size();
        int l = 0,r=cols-1;
        while(l<rows && r>=0){
            int curr = mat[l][r];
            if(curr==target)return true;
            if(curr>target)r--;
            else l++;
        }
  return false;  }
};