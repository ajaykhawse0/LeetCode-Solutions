class Solution {
public:typedef long long ll;
int n,maxTrans;
 ll solve(int i,int trans,int state,vector<vector<vector<ll>>>&dp,vector<int>&prices){
    if(i==n){
        return state==0?0:-1e9;
    }

    if(dp[i][trans][state]!=-1)return dp[i][trans][state];
    ll ans = solve(i+1,trans,state,dp,prices);


    if(state==0){
        //trying both
        ans = max(ans,solve(i+1,trans,1,dp,prices)-prices[i]);//longhand
        ans = max(ans,solve(i+1,trans,2,dp,prices)+prices[i]);//shorthand
    }
    else if(state==1 && trans<maxTrans){
        //selling holded stock
        ans = max(ans,solve(i+1,trans+1,0,dp,prices)+prices[i]);
    }
    else if(state==2 && trans<maxTrans){
        //selling holded stock
        ans = max(ans,solve(i+1,trans+1,0,dp,prices)-prices[i]);
    }

    return dp[i][trans][state] = ans;
 }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(k+1,vector<ll>(3,-1)));
        maxTrans=k;

       return solve(0,0,0,dp,prices);
    }
};