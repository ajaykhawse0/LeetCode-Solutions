class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> memo;
    bool dfs(int r, int c, int open, vector<vector<char>>& grid) {
        if (r >= m || c >= n)
            return false;

        if (grid[r][c] == '(')
            open++;
        else if (grid[r][c] == ')')
            open--;

        if (open < 0)
            return false;

        if (memo[r][c][open] != -1)
            return memo[r][c][open];

        if (r == m - 1 && c == n - 1) {
            return memo[r][c][open] = (open == 0);
        }

        bool down = dfs(r + 1, c, open, grid);
        bool right = dfs(r, c + 1, open, grid);

        return memo[r][c][open] = (down || right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int len = m + n - 1;

        if (len & 1 || grid[0][0] != '(' || grid[m - 1][n - 1] != ')')
            return false;
        memo.assign(m + 1,
                    vector<vector<int>>(n + 1, vector<int>(len + 1, -1)));

        return dfs(0, 0, 0, grid);
    }
};