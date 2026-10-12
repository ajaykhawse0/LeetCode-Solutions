class Solution {
public:
    int maxSubArraySum(vector<int>& nums) {
        // min sub array len => 2;
        int sum = nums[0] + nums[1];
        int maxSum = sum;

        for (int i = 2; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i - 1] + nums[i]);
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MIN;
        // first calculate it for all rows

        for (auto& arr : grid) {
            ans = max(ans, maxSubArraySum(arr));
        }

        //check for all cols
        for (int i = 0; i < n; i++) {
            vector<int> arr;
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[j][i]);
            }
            ans = max(ans, maxSubArraySum(arr));
        }

        //check for all internal cells

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                ans = max(ans,grid[i][j]);
            }
        }
    return ans;}
};