class Solution {
public:
    vector<vector<int>> memo;
    int NEG = -1e9;
    int n;
    vector<vector<int>> dirs = {{1, 0}, {1, 1}, {1, -1}};
    int solve(int r, int c, vector<vector<int>>& matrix) {
        if (r == n - 1)
            return matrix[r][c];

        if (memo[r][c] != NEG)
            return memo[r][c];
        int ans = 1e9;
        for (auto dir : dirs) {
            int nr = r + dir[0];
            int nc = c + dir[1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                ans = min(ans, matrix[r][c] + solve(nr, nc, matrix));
            }
        }
        return memo[r][c]  = ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        memo.assign(n, vector<int>(n, NEG));
        int ans = 1e9;

        for (int i = 0; i < n; i++) {
            ans = min(ans, solve(0, i, matrix));
        }
        return ans;
    }
};