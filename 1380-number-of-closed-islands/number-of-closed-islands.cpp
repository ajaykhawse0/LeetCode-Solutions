class Solution {
public:
    int m, n;
    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){

        if(i<0 || i>=m || j<0 || j>=n)return false;

        if(vis[i][j])return true;

        vis[i][j]=1;

        if(grid[i][j]==1)return true;

        bool up = dfs(i-1,j,grid,vis);
        bool down = dfs(i+1,j,grid,vis);
        bool left = dfs(i,j-1,grid,vis);
        bool right = dfs(i,j+1,grid,vis);

        return up && down && left && right;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0 && !vis[i][j]) {
                    if (dfs(i, j, grid, vis)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};