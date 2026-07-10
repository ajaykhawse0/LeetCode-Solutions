class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int curr = 1;
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        vector<vector<int>> ans(n, vector<int>(n));
        while (curr <= n * n) {

            for (int c = left; c <= right; c++) {
                ans[top][c] = curr;
                curr++;
            }
            top++;

            for (int r = top; r <= bottom; r++) {
                ans[r][right] = curr;
                curr++;
            }
            right--;

            for (int c = right; c >= left; c--) {
                ans[bottom][c] = curr;
                curr++;
            }
            bottom--;

            for (int r = bottom; r >= top; r--) {
                ans[r][left] = curr;
                curr++;
            }
            left++;
        }
        return ans;
    }
};