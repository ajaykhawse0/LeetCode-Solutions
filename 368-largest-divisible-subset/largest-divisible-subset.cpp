class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        vector<int>dp(n+1,1);
        vector<int>prev(n+1,-1);
        int maxi = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){

                if((nums[i]%nums[j])==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i] = j;
                }

            }
                if(dp[maxi]<dp[i]){
                    maxi=i;
                }
        }

        vector<int>res;

        for(int i=maxi;i>=0;i=prev[i]){
            res.push_back(nums[i]);
        }
    return res;}
};