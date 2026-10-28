class Solution {
public:vector<vector<vector<int>>>memo;
    int m,n;
     
    int solve(int i,int j,int xr,vector<vector<int>>& grid){
        if(i>=m || j>=n)return INT_MAX;
        
        xr ^= grid[i][j];

        if(i==m-1 && j==n-1)return xr;

        if(memo[i][j][xr]!=INT_MAX)return memo[i][j][xr];

        int right = solve(i,j+1,xr,grid);
        int down =  solve(i+1,j,xr,grid);

        return memo[i][j][xr] = min(right,down);

    } 
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        memo.assign(m,vector<vector<int>>(n,vector<int>(1024,INT_MAX)));


        return solve(0,0,0,grid);
    }
};