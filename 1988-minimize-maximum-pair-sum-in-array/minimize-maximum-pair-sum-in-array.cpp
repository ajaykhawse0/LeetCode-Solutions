class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minimizedMax = INT_MIN;
        int i=0,j=nums.size()-1;
        while(i<j){
            int sum = nums[i]+nums[j];
            minimizedMax = max(minimizedMax,sum);
            i++;j--;
        }
    return minimizedMax;}
};