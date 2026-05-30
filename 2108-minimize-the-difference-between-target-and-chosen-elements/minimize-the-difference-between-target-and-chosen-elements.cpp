class Solution {
public:int m ,n;
    int solve(vector<vector<int>>&dp,int row,int sum,vector<vector<int>>&mat,int target){
        if(row>=m){
            return abs(sum-target);
        }

        if(dp[sum][row]!=-1)return dp[sum][row];
        int ans  = INT_MAX;
        for(int i=0;i<n;i++){
           ans = min(ans,solve(dp,row+1,sum+mat[row][i],mat,target));

           if(ans==0){
            break;
           }
        }
   return  dp[sum][row]=ans;}
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        //we have to move to all 
        m = mat.size();
        n = mat[0].size();

        vector<vector<int>>dp(4900,vector<int>(m,-1));

        return solve(dp,0,0,mat,target);
    }
};