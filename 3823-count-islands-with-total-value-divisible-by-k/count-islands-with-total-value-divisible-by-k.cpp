class Solution {
public:
    int m, n;
    long long dfs(int i, int j, vector<vector<int>>& grid, int k) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return 0;

        long long sum = grid[i][j];
        grid[i][j] = 0;

        sum += dfs(i - 1, j, grid, k);
        sum += dfs(i, j - 1, grid, k);
        sum += dfs(i + 1, j, grid, k);
        sum += dfs(i, j + 1, grid, k);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int islands = 0;

        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid, k);
                    if(sum%k==0)islands++;
                }
            }
        }
    return islands;}
};