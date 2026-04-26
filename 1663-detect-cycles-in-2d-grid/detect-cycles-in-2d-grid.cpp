class Solution {
public:
int m,n;
vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
bool dfs(int r,int c,int parR,int parC,vector<vector<int>>&visited,vector<vector<char>>&grid){
          
          visited[r][c]=1;

          for(vector<int>&dir:dirs){
            int nr = r+dir[0];
            int nc = c+dir[1];

            if(nr>=0 && nr<m && nc>=0 && nc<n && grid[r][c]==grid[nr][nc]){
                if(visited[nr][nc] && (nr!=parR && nc!=parC )){
                    return true;
                }
                else if(!visited[nr][nc]){
                     if(dfs(nr,nc,r,c,visited,grid))return true;
                }
                
            }
          }
return false;}
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>>visited(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]){
                    if(dfs(i,j,-1,-1,visited,grid)){
                        return true;
                    }
                }
            }
        }
  return false;  }
};