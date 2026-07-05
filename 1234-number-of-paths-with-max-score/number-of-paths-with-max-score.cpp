class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{0,-1},{-1,-1}};
    int MOD = 1e9+7;
    vector<vector<bool>> vis;
    vector<vector<pair<int,int>>>memo;
    vector<int>dpWays;

    pair<int,int> dfs(int i,int j,vector<string>& board){

        if(i==0 && j==0) return {0,1};

        if(i<0 || j<0 || board[i][j]=='X')
            return {-1,0};
        
        if(vis[i][j])return memo[i][j];
        vis[i][j]=true;

        int best=-1;
        int ways=0;

        for(auto &dir:dirs){
            int nr=i+dir[0];
            int nc=j+dir[1];

            // Boundary check first
            if(nr<0 || nc<0) continue;

            auto [score,cnt]=dfs(nr,nc,board);

            if(score==-1) continue;

            if(board[i][j]>='0' && board[i][j]<='9')
                score += board[i][j]-'0';

            if(score>best){
                best=score;
                ways=cnt;
            }
            else if(score==best){
                ways=(ways+cnt)%MOD;
            }
        }

        return memo[i][j]={best,ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m=board.size();
        int n=board[0].size();

        vis.assign(m,vector<bool>(n,false));
        memo.assign(m,vector<pair<int,int>>(n));


        auto [score,ways]=dfs(m-1,n-1,board);

        if(score==-1)
            return {0,0};

        return {score,ways};
    }
};