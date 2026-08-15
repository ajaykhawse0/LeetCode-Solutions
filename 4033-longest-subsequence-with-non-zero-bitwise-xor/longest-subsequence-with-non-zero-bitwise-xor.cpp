class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool allZero = true;
        int xorAns = 0;
        for (int i = 0; i < nums.size(); i++) {
            xorAns ^= nums[i];
            if (nums[i] != 0)
                allZero = false;
        }
        if (allZero)
            return 0;

        return xorAns == 0 ? nums.size() - 1 : nums.size();
    }
};