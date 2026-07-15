class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0,curr=0;
        int ans=0;
        int n = nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==0){
            ans=max(ans,prev+curr);
            prev=curr;
            curr=0;
        }
        else{
            curr++;
        }
    }
     ans=max(ans,prev+curr);
     if(ans==n)return n-1;
    return ans;}
};