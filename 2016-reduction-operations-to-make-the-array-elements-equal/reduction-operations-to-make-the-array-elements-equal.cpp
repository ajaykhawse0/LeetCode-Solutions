class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int n = nums.size();

        int operations = 0;

        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                operations += i+1;
            }
        }  
return operations;

    }
};