class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            int diff = target-nums[i];
            if(mpp.count(diff)){
                return {mpp[diff],i};
            }
            mpp[nums[i]] = i;
        }
       return {-1,-1}; 
    }
};