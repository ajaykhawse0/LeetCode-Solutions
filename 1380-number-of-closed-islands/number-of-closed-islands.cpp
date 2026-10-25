class Solution {
public:int m,n;
    bool dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        if(i<0 || i>=m || j<0 || j>=n)return false;

        if(vis[i][j])return true;
        vis[i][j] = true;

        if(grid[i][j]==1)return true;

        bool up = dfs(i-1,j,grid,vis);
        bool down = dfs(i+1,j,grid,vis);
        bool left = dfs(i,j-1,grid,vis);
        bool right = dfs(i,j+1,grid,vis);

        return left && right && up && down; // if it is covered from all sides by 1's only then it is considered as closed island
    }
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int islands  = 0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    if(dfs(i,j,grid,vis)){
                        islands++;
                    }
                }
            }
        }
 return islands;   }
};