
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int zeros = 0;
        int ones = 0;
        int mx = -1;

        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i <= n; i++) {
            int score = zeros + totalOnes - ones;

            mpp[score].push_back(i);
            mx = max(mx, score);

            if (i < n) {
                if (nums[i] == 0)
                    zeros++;
                else
                    ones++;
            }
        }

        return mpp[mx];
    }
};
