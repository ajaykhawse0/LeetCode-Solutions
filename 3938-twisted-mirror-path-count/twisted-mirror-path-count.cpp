
class Solution {
    using ll = long long;

    int m, n;
    ll MOD = 1e9 + 7;

    vector<vector<vector<ll>>> memo;

public:

    ll solve(int i, int j, int dir, vector<vector<int>>& grid) {

        if (i >= m || j >= n)
            return 0;

        // Process mirror before checking destination.
        if (grid[i][j] == 1) {

            if (memo[i][j][dir] != -1)
                return memo[i][j][dir];

            if (dir == 0) {
                // Entered from left -> reflected down
                return memo[i][j][dir] =
                    solve(i + 1, j, 1, grid) % MOD;
            }
            else {
                // Entered from above -> reflected right
                return memo[i][j][dir] =
                    solve(i, j + 1, 0, grid) % MOD;
            }
        }

        // Reached destination (non-mirror)
        if (i == m - 1 && j == n - 1)
            return 1;

        if (memo[i][j][dir] != -1)
            return memo[i][j][dir];

        // Empty cell: choose right or down
        ll down = solve(i + 1, j, 1, grid);
        ll right = solve(i, j + 1, 0, grid);

        return memo[i][j][dir] = (down + right) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<vector<ll>>(
            n, vector<ll>(2, -1)
        ));

        if (m == 1 && n == 1)
            return 1;

        // Starting cell is already occupied.
        // It does not trigger a reflection.
        ll ans = 0;

        ans = (ans + solve(1, 0, 1, grid)) % MOD;
        ans = (ans + solve(0, 1, 0, grid)) % MOD;

        return ans;
    }
};
