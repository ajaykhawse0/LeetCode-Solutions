class Solution {
public:
    vector<vector<int>>dirs={{-1,0},{0,1},{1,0},{0,-1}};

    void dfs(int r,int c, int m,int n,vector<vector<int>>&vis,vector<vector<int>>& grid){
        vis[r][c]=1;
        
        for(auto&dir:dirs){
            int nr = r+dir[0];
            int nc = c+dir[1];

            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,m,n,vis,grid);
            }
        }
        
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        //Boundary Check 
        
        //First Row

        for(int j=0;j<n;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,m,n,vis,grid);
            }
        }

        //Last Row 
        
        for(int j=0;j<n;j++){
            if(grid[m-1][j]==1 && !vis[m-1][j]){
                dfs(m-1,j,m,n,vis,grid);
            }
        }
        
        //First Col

        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i,0,m,n,vis,grid);
            }
        }

        //Last Row 

        for(int i=0;i<m;i++){
            if(grid[i][n-1]==1 && !vis[i][n-1]){
                dfs(i,n-1,m,n,vis,grid);
            }
        }

        int Enclaves = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    Enclaves++;
                    
                }
            }
        }
    return Enclaves;}
};