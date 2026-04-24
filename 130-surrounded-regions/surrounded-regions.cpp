class Solution {
public:
   vector<vector<int>>dirs = {{-1,0},{0,1},{1,0},{0,-1}};
   void dfs(vector<vector<char>>& board,int r,int c,vector<vector<int>>&vis,int m,int n){
    vis[r][c] = 1;

    for(auto&dir:dirs){
        int nr = r+dir[0];
        int nc = c+dir[1];

        if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
            dfs(board,nr,nc,vis,m,n);

        }
    }
   }

    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        //first row
        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O'){
            dfs(board,0,j,vis,m,n);}
        }
        //last row
        for(int j=0;j<n;j++){
            if(!vis[m-1][j] && board[m-1][j]=='O'){
            dfs(board,m-1,j,vis,m,n);}
        }
        //first col
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
            dfs(board,i,0,vis,m,n);}
        }
        //last col
        for(int i=0;i<m;i++){
            if(!vis[i][n-1] && board[i][n-1]=='O'){
            dfs(board,i,n-1,vis,m,n);}
        }
 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};