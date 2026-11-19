class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int prev = -1;
        int moves = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<=prev){
                moves += (prev-nums[i]+1);
                nums[i] = prev+1;
            }
            prev = nums[i];
        }
 return moves;   }
};