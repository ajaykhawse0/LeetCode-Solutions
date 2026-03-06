class Solution {
public:
    bool check(vector<int>& nums) {
        //Rev
         int decreasing=0;
         int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1])decreasing++;
        }
        //last check 
        if(nums[n-1]>nums[0])decreasing++;
        return decreasing<=1;
        
    }
};