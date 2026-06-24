class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // sum method

        unordered_map<int, int> mpp;

        mpp[0] = -1;
        int prefix = 0;
        int ans = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            prefix += ((nums[i] == 1) ? 1 : -1);

            if (mpp.count(prefix)) {
                ans = max(ans, i - mpp[prefix]);
            } else {
                mpp[prefix] = i;
            }
        }

        return ans;
    }
};