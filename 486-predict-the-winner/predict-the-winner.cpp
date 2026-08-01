class Solution {
public:
int n ;
vector<vector<int>>memo;

int solve(vector<int>&nums,int i,int j){
    if(i==j)return nums[i];

    if(memo[i][j]!=-1)return memo[i][j];

    int leftPick = nums[i] - solve(nums,i+1,j);
    int rightPick = nums[j] - solve(nums,i,j-1);

    return memo[i][j] = max(leftPick,rightPick);
} 


    
    bool predictTheWinner(vector<int>& nums) {
        n = nums.size();
        memo.assign(n,vector<int>(n,-1));
        return solve(nums,0,n-1) >= 0;//if net diff is greater p1 will win
    }
};