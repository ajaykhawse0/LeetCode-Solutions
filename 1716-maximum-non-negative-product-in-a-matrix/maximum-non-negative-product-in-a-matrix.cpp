class Solution {
public:
typedef long long ll;
typedef pair<ll,ll> P;
int n,m;
int M = 1e9+7;
vector<vector<int>>dirs={{0,1},{1,0}};
vector<vector<P>>dp;
    P solve(int r,int c,vector<vector<int>>& grid){

        if(r==n-1 && c==m-1){
            return make_pair(grid[r][c],grid[r][c]);
        }

        if(dp[r][c]!=make_pair(-1e9,-1e9))return dp[r][c];

        ll maxi = -1e9 , mini = 1e9;
        ll currVal = grid[r][c];

        for(auto&dir:dirs){
            int newr = r+dir[0];
            int newc = c+dir[1];

            if(newr>=0 && newr<n && newc>=0 && newc<m){
                P nextVal = solve(newr,newc,grid);

                maxi = max({maxi,currVal*nextVal.first,nextVal.second*currVal});
                mini = min({mini,currVal*nextVal.first,nextVal.second*currVal});
            }
        }
    return dp[r][c] = {maxi,mini};}
    int maxProductPath(vector<vector<int>>& grid) {
        //recursion + memoization;
        n = grid.size(),m=grid[0].size();
        dp.assign(n,vector<P>(m,{-1e9,-1e9}));
        
        P result = solve(0,0,grid);

        if(result.first<0)return -1;

        return result.first%M;
    }
};