class Solution {
private :

vector<vector<int>>dirs={{-1,0},{0,1},{1,0},{0,-1}};
int bfs(queue<pair<pair<int,int>,int>>&q,vector<vector<int>>&vis,vector<vector<int>>& grid,int rows,int cols,int freshOranges){

        int ans = 0;      
        int cnt = 0;
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
         
        ans = max(ans,time);
        q.pop();
        for(auto&dir:dirs){
            int nrow = row+dir[0];
            int ncol = col+dir[1];

            if(nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                cnt++;
                vis[nrow][ncol]=2;

                q.push({{nrow,ncol},time+1});
            }
        }
    }
if(freshOranges != cnt)return -1;
return ans;}

public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows =  grid.size();
        int cols =  grid[0].size();
        
        vector<vector<int>>vis(rows,vector<int>(cols,0));

        queue<pair<pair<int,int>,int>>q;
        int fresh=0;//fresh orange count;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});//row,col,time
                    vis[i][j]=2;//rotten
                }
                else if(grid[i][j]==1)fresh++;
            }
        }

        return bfs(q,vis,grid,rows,cols,fresh);
    }
};