class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        while(r<n){
            mpp[nums[r]]++;

            while(mpp[nums[r]] > k && l <= r){
                mpp[nums[l]]--;
                l++;
            }
            maxLen = max(maxLen,r-l+1);
            r++;
        }
    return maxLen;}
};