class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<long long>dp(k,1e18);
        dp[0] = 0;
        for(int i=0;i<nums.size();i++){
             sum += nums[i];
             long long rem = sum%k;
             sum = min(sum,dp[rem]);

             dp[rem] = sum;
        }
    return sum;}
};