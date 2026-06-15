class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> arr(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i < m - k + 1; i++) {

            for (int j = 0; j < n - k + 1; j++) {
                vector<int> sub;
                for (int row = i; row < i + k; row++) {
                    for (int col = j; col < j + k; col++) {
                        sub.push_back(grid[row][col]);
                    }
                }
                sort(begin(sub), end(sub));
                sub.erase(unique(begin(sub), end(sub)), end(sub));
                if (sub.size() <= 1)
                    arr[i][j] = 0;
                else {
                    int ans = INT_MAX;
                    for (int p = 0; p < sub.size() - 1; p++) {
                        ans = min(ans, sub[p + 1] - sub[p]);
                    }

                    arr[i][j] = ans;
                }
            }
        }
        return arr;
    }
};