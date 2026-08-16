class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for(int i=0;i<nums.size();i++){
            xr ^= i;
            xr ^= nums[i];
        }

        return xr ^ nums.size();
    }
};