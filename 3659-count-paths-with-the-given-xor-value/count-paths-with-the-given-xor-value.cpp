class Solution {
public:
int m,n;
int MOD=1e9+7;
vector<vector<vector<int>>>memo;

    int solve(vector<vector<int>>& grid,int k,int xr,int i,int j){
        if(i == m-1 && j == n-1)
    return xr == k;
        
        if(i>m-1 || j>n-1){
            return 0;
        }
        if(memo[i][j][xr]!=-1)return memo[i][j][xr];
        int ans = 0;
        //bottom
        if(i+1<m){
        ans = (ans + solve(grid,k,xr^grid[i+1][j],i+1,j)) %MOD;}
        //right
        if(j+1<n){
        ans = (ans+solve(grid,k,xr^grid[i][j+1],i,j+1)) % MOD;}
return memo[i][j][xr] = ans;
    }
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
         m = grid.size();
         n = grid[0].size();
         memo.assign(m,vector<vector<int>>(n,vector<int>(16,-1)));
        return solve(grid,k,grid[0][0],0,0);
    }
};