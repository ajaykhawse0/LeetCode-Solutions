class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        //observation is simple if no single element is encountered on left side nums[mid]==nums[mid+1](mid should be even) in that scenario move left to mid+2;
        //else shrink from left
        while(low<high){
            mid = low + (high-low)/2;//overflow handling
            if(mid&1)mid--;//even
            if(nums[mid]==nums[mid+1]){
                low = mid+2;
            }

            else{
                high = mid;
            }

        }
   return nums[low]; }
};