class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>ans(n,0);

        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                ans[j] =max(ans[j],(int)to_string(grid[i][j]).size());
            }
        }
 return ans;   }
};