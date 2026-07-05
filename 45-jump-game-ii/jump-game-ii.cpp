class Solution {
public:
    vector<int>memo;
    int n;
    int INF = 1e9;

    int solve(int idx,vector<int>&nums){
        if(idx>=n-1)return 0;
        if(memo[idx]!=INF)return memo[idx];

        int mini = INF;

        for(int i=1;i<=nums[idx];i++){
            mini = min(mini,1+solve(i+idx,nums)); 
        }

        return memo[idx] = mini;
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        if(nums[0]==0)return-1;
        n = nums.size();
        memo.assign(n,INF);
        int val = solve(0,nums);
        return (val==INF)?-1:val;
    }
};