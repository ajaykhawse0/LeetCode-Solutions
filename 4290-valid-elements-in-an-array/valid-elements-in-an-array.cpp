class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums;
        vector<int>ans;

        for(int i=0;i<n;i++){
        bool leftGreater=true;
        bool rightGreater=true;

        for(int j=0;j<i;j++){
            if(nums[i]<=nums[j]){
                leftGreater=false;
                break;
            }
        }
        for(int j=n-1;j>i;j--){
                   if(nums[i]<=nums[j]){
                rightGreater=false;
                break;
            }
        }
        if(rightGreater || leftGreater){
            ans.push_back(nums[i]);
        }
        }

    return ans;}
};