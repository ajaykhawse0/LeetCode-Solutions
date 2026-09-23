class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
      int total = accumulate(nums.begin(),nums.end(),0);
      int n = nums.size();
      int target = total-x;

      if(target<0)return -1;
      if(target==0)return n;

      int sum = 0;
      int left = 0;
      int longest = -1;

      for(int right=0;right<n;right++){
        sum += nums[right];
        while(left<right && sum>target){
            sum -= nums[left];
            left++;
        }
        if(target==sum){
            longest = max(longest,right-left+1);
        }
      } 
    return longest==-1?-1:n-longest;}
};