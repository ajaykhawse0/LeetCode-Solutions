class Solution {
public:
vector<vector<int>>dp;
int n;
int solve(int idx,int amount,vector<int>&coins){
    if(amount==0)return 1;

    if(idx==n)return 0;

    if(dp[idx][amount]!=-1)return dp[idx][amount];

    int take  = 0;
    int skip = solve(idx+1,amount,coins);
    if(amount>=coins[idx]){
        take = solve(idx,amount-coins[idx],coins);
    }

    return dp[idx][amount]=take+skip;
}
    int change(int amount, vector<int>& coins) {
    n=coins.size();
    dp.assign(n,vector<int>(amount+1,-1));        
    // dp.resize(n,vector<int>(amount+1,-1));

    return solve(0,amount,coins);        
    }
};