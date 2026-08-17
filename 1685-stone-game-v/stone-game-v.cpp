class Solution {
public:vector<vector<int>>dp;
vector<int>prefixSum;
    
    int solve(int l,int r,vector<int>&stones){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];

        int leftSum = 0;
        int rightSum = prefixSum[r+1]-prefixSum[l];
        
        int ans = 0;

        for(int p=l;p<r;p++){
            leftSum += stones[p];
            rightSum -= stones[p];
             
             if(leftSum<rightSum){
                ans = max(ans,leftSum+solve(l,p,stones));
             }
             else if(rightSum<leftSum){
                ans = max(ans,rightSum+solve(p+1,r,stones));
             }
             else{
                ans = max({ans,leftSum+solve(l,p,stones),rightSum+solve(p+1,r,stones)});

             }
        }
            return dp[l][r]=ans;}

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefixSum.resize(n+1,0);
        for(int i=0;i<n;i++){
         prefixSum[i+1] = prefixSum[i]+stoneValue[i];
        }
        dp.assign(n+1,vector<int>(n+1,-1));
        
        return solve(0,n-1,stoneValue);
    }
};