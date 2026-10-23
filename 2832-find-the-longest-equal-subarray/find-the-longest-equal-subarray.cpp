class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int maxFreq = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            freq[nums[r]]++;

            maxFreq = max(maxFreq, freq[nums[r]]);

            if (r - l + 1 - maxFreq > k){
                freq[nums[l]]--;
                l++;
            }
        }
    return maxFreq;}
};