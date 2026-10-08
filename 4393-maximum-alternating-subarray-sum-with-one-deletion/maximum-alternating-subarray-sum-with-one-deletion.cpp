class Solution {
public:using ll = long long;
int n;

ll solve(int i,int parity,int del,vector<int>&nums){
    if(i==n)return 0;

    if(dp[i][parity][del]!=LLONG_MIN)return dp[i][parity][del];

    ll ans = 0;

    ll val = nums[i];

    if(parity==1){
        val = -1LL*nums[i];
    }


    ll take = val + solve(i+1,1-parity,del,nums);
    ans = max(ans,take);

    if(del == 0){
        ll skip = solve(i+1,parity,1,nums);
        
        ans = max(ans,skip);    }



        return dp[i][parity][del] = ans; 
}

    vector<vector<vector<ll>>>dp;
    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1,vector<vector<ll>>(2,vector<ll>(2,LLONG_MIN)));

        int i = 0;
        ll ans = LLONG_MIN;
        
        while(i<n){
            //always start with negative parity
            ll curr = nums[i] + solve(i+1,1,0,nums);

            ans = max(ans,curr);
            
            i++;

        }
    return ans;}
};