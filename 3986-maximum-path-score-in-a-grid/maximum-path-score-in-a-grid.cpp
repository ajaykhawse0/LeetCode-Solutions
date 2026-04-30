
class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int cost, int k){

        if(i >= m || j >= n) return -1;

        int newCost = cost + (grid[i][j] == 0 ? 0 : 1);

        if(newCost > k) return -1;

        if(i == m-1 && j == n-1) return grid[i][j];

        if(dp[i][j][newCost] != INT_MIN) return dp[i][j][newCost];

        int right = solve(grid, i, j+1, newCost, k);
        int down  = solve(grid, i+1, j, newCost, k);

        int maxVal = max(right, down);

        if(maxVal == -1) 
            return dp[i][j][newCost] = -1;

        return dp[i][j][newCost] = grid[i][j] + maxVal;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(k+1, INT_MIN)));

        return solve(grid, 0, 0, 0, k);
    }
};