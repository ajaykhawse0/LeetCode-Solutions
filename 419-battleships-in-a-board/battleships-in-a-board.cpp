class Solution {
public: 
    vector<vector<int>>dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
              if(board[i][j]=='X'){
                dfs(i,j,m,n,board);
                ans++;
              }
            }
        }
  return ans;  }

  void dfs(int r,int c,int m,int n,vector<vector<char>>& board){
    board[r][c] = ' ';

       for(auto dir:dirs){
        int nr = r + dir[0]; 
        int nc = c + dir[1];

        if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='X'){
            dfs(nr,nc,m,n,board);
        } 
       }

  }
};