class Solution {
public:vector<vector<int>>memo;//brute dp
int n,m;
    int solve(int l,int idx,vector<int>& nums, vector<int>& multipliers){
        if(idx==m)return 0;

        if(memo[l][idx]!=-1)return memo[l][idx];

        //pickleft
        int left = nums[l]*multipliers[idx] + solve(l+1,idx+1,nums,multipliers);
        //pickright
        //r = n-idx+l-1
        int right = nums[n-(idx-l)-1]*multipliers[idx] + solve(l,idx+1,nums,multipliers);         

        return memo[l][idx] = max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        m = multipliers.size();
        n = nums.size();
        memo.assign(1000,vector<int>(1000,-1));
        
        return solve(0,0,nums,multipliers);
    }
};