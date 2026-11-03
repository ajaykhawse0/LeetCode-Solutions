class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max = *max_element(nums.begin(),nums.end());
        int ans=0;
        for(int&n:nums){
            ans+= max-n;
        }
    return ans;}
};