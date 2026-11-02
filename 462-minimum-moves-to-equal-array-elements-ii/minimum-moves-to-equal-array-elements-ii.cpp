class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        auto mid = nums.begin()+nums.size()/2;
        nth_element(nums.begin(),mid,nums.end());


        int moves = 0;
        int val = *mid;
        for(int x:nums){
            moves += abs(x-val);
        } 
    return moves;}
};