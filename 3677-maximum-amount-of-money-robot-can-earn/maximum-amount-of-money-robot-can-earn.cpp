class Solution {
public:
    int m, n;

    int solve(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {

        if (i >= m || j >= n) return INT_MIN;

        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] >= 0) return coins[i][j];
            if (k > 0) return 0;
            return coins[i][j];
        }

        if (dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int val = coins[i][j];
        int ans = INT_MIN;

        // Move right or down
        if (val >= 0) {
            ans = val + max(solve(i + 1, j, k, coins, dp),
                            solve(i, j + 1, k, coins, dp));
        } else {
            // Option 1: take negative
            int take = val + max(solve(i + 1, j, k, coins, dp),
                                 solve(i, j + 1, k, coins, dp));

            // Option 2: skip negative (if k > 0)
            int skip = INT_MIN;
            if (k > 0) {
                skip = max(solve(i + 1, j, k - 1, coins, dp),
                           solve(i, j + 1, k - 1, coins, dp));
            }

            ans = max(take, skip);
        }

        return dp[i][j][k] = ans;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        vector<vector<vector<int>>> dp(m,
            vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        return solve(0, 0, 2, coins, dp);
    }
};