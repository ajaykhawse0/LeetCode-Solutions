class Solution {
public:
int n,K;
typedef long long ll;
long long solve(int idx,int trans,int state,vector<int>&prices,vector<vector<vector<ll>>>&dp){
   if (idx == n) {
            if (state == 0) return 0;
            return -1e9;
        }

    if(dp[idx][trans][state]!=-1){
        return dp[idx][trans][state];
    }

    ll ans = solve(idx+1,trans,state,prices,dp);//no position

    if(state == 0){
        //try both longHand(i.e.holding)and shorthand (shortselling)
         
         ans = max(ans,solve(idx+1,trans,1,prices,dp)-prices[idx]);//longhand
         ans = max(ans,solve(idx+1,trans,2,prices,dp)+prices[idx]);//shorthand

    }
    else if(state==1 && trans<K){
        //longHand state
        //selling the holded stock
        ans = max(ans,solve(idx+1,trans+1,0,prices,dp)+prices[idx]);
    }
    else if(state==2 && trans<K){
        //shortHand state
        //buying  the shortselled stock
        ans = max(ans,solve(idx+1,trans+1,0,prices,dp)-prices[idx]);
    }
 return   dp[idx][trans][state]=ans;

}

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        K=k;
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(K+1,vector<ll>(3,-1)));
        return solve(0,0,0,prices,dp);
    }
};