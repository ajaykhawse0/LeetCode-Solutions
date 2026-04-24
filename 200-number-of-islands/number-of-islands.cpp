class Solution {
public:
    
    vector<vector<int>>dirs = {{-1,0},{0,1},{1,0},{0,-1}};

    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid,int m,int n){
        vis[row][col]=1;
        for(vector<int>&dir:dirs){
           int nrow = row+dir[0];
           int ncol = col+dir[1];

           if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
            vis[nrow][ncol]=1;
            dfs(nrow,ncol,vis,grid,m,n);
           }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        int cnt=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    if(!vis[i][j]){
                        cnt++;
                        dfs(i,j,vis,grid,m,n);
                    }
                }
            }
        }
return cnt;
    }
};