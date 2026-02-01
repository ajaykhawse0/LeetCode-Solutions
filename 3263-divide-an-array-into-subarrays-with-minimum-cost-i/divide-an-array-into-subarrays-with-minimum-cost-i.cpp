class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        int min1 =INT_MAX,min2 = INT_MAX;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<min1){

                if(min1<min2){
                    min2=min1;
                }
                min1=nums[i];
                // cout<<min1<<",";
            }
            else if(nums[i]<min2){
                min2=nums[i];
                // cout<<min2<<",";
            }
        }
        ans+=min1+min2;
    return ans;}
};