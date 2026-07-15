class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum=0;
        int rightsum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            if(i==0){
                leftsum=0;
                rightsum-=nums[i];
            }
            else{
                leftsum+=nums[i-1];
                rightsum-=nums[i];
            }
            if(leftsum==rightsum)return i;
        }

        return -1;

    }
};