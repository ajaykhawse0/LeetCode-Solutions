class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n<=2)return n;

        int i=0;
        int j=1;
        
        int len = 2;
        int maxLen = 2;

        while(j+1<n){
           if(nums[i]+nums[j]==nums[j+1]){
            len++;
           }
           else{
            maxLen = max(len,maxLen);
            len = 2;
           }
           i++;
           j++;
        }
            maxLen = max(len,maxLen);

   return maxLen; }
};