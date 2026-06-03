class Solution {
public:
vector<int>dp;
int solve(int idx,vector<int>&nums){
    if(idx==0)return nums[0];
    if(idx<0)return 0;
    if(dp[idx]!=-1)return dp[idx];

    int take = nums[idx] + solve(idx-2,nums);
    int skip =  solve(idx-1,nums);

    return dp[idx] = max(skip,take);

}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        dp.assign(n,-1);

        return solve(n-1,nums);
        
    }
};
//BOTTOM UP => TABULATION
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1)return nums[0];

//         vector<int>dp(n);
//         dp[0]=nums[0];
//         dp[1]=max(nums[0],nums[1]);//because robber can rob only one of adjacent house

//         for(int i=2;i<n;i++){
//             dp[i]=max(dp[i-1],nums[i]+dp[i-2]);//rob the current house or the adjacent one which one gives more profit
//         }
// return dp[n-1];
//     }
// };