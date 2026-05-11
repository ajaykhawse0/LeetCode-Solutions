class Solution {
public:
    int solve(vector<int>&nums,int target,int n,vector<int>&dp,int idx){
        if(idx==n-1)return 0;
        
        if(dp[idx]!=INT_MIN)return dp[idx];
        int ans = -1;

        for(int j=idx+1;j<n;j++){
            if(abs(nums[j]-nums[idx])<=target){
            int temp = solve(nums,target,n,dp,j);
            if(temp!=-1){
                ans = max(ans,temp+1);
            }
            }
        }
    return dp[idx]=ans;}
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n,INT_MIN);

        return solve(nums,target,n,dp,0);
    }
};