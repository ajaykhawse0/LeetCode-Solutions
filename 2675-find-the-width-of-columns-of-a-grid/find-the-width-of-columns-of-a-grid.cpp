class Solution {
public:
    int len(int x) {
        int l = x <= 0 ? 1 : 0;
        x = abs(x);

        while (x > 0) {
            x /= 10;
            l++;
        }
        return l;
    }

    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans(n, 0);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                ans[j] = max(ans[j], len(grid[i][j]));
            }
        }

        return ans;
    }
};