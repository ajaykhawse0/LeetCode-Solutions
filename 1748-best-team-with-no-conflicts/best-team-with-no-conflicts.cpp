class Solution {
public:
    int n;
    vector<vector<int>>dp;
    vector<pair<int,int>>arr;

    int solve(int idx,int prev){
        if(idx==n)return 0;

        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        
        int skip = solve(idx+1,prev);

        int take = 0;

        if(prev==-1 || arr[idx].second>=arr[prev].second){
            take  += arr[idx].second + solve(idx+1,idx);
        }
       return dp[idx][prev+1] = max(take,skip);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        n = scores.size();

        for(int i=0;i<n;i++){
            arr.push_back({ages[i],scores[i]});
        }
        dp.assign(n,vector<int>(n+1,-1));

        sort(arr.begin(),arr.end());

        return solve(0,-1);
    }
};