class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int minSum = nums[k-1]-nums[0];       
        
        for(int i=1;i+k<=n;i++){
          minSum = min(minSum,nums[i+k-1]-nums[i]);
        }
    return minSum;}
};/*1,4,7,9 ,k=2 => minsum = nums[2-1]-nums[0] = 3
             minsum = nums[2]-nums[1]=3
             minSum = nums[3]-nums[2] = 2*/
/*1,4,7,9 ,k=3 => minsum = nums[3-1]-nums[0] = 6
             minsum = nums[3]-nums[1]=5
             */