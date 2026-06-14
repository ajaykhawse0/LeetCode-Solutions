class Solution {
public:
vector<vector<int>>memo;
    int MOD=1e9+7;

    int solve(int n,int k,int target,vector<vector<int>>&memo){
        if(n==0 && target==0)return 1;//one way;

        if(n<=0 || target<=0)return 0;//no way possible;

        if(memo[n][target]!=-1)return memo[n][target];//already visited

        int res=0;//no. of ways

        for(int i=1;i<=k;i++){
            res = (res+solve(n-1,k,target-i,memo))%MOD;
        }

        return memo[n][target]  = res % MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        //changing states are no. of dices and the target
        memo.assign(n+1,vector<int>(target+1,-1));

        return solve(n,k,target,memo);

    }
};